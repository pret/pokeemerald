	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8158B30
sub_8158B30: @ 8158B30
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r6, r0, 2
	adds r6, r0
	lsls r6, 3
	adds r6, r1
	ldr r1, =gUnknown_0203841E
	ldrh r0, [r1]
	strh r0, [r6, 0x8]
	ldrh r0, [r1, 0x2]
	strh r0, [r6, 0xA]
	movs r0, 0x40
	negs r0, r0
	bl sub_80A5178
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x3F
	bl sub_80A5178
	adds r5, r0, 0
	lsls r4, 24
	asrs r4, 24
	lsls r5, 24
	asrs r5, 24
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x2
	bl sub_80A5314
	strh r4, [r6, 0xC]
	strh r5, [r6, 0xE]
	lsls r0, 24
	asrs r0, 24
	strh r0, [r6, 0x10]
	movs r0, 0xA
	strh r0, [r6, 0x1C]
	ldr r0, =sub_8158B98
	str r0, [r6]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8158B30

	thumb_func_start sub_8158B98
sub_8158B98: @ 8158B98
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r5, [r4, 0xC]
	ldrb r6, [r4, 0x10]
	ldrh r0, [r4, 0x1E]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r4, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6F
	bne _08158BD0
	movs r0, 0x5
	strh r0, [r4, 0x1C]
	strh r1, [r4, 0x1E]
	ldr r0, =sub_8158C04
	str r0, [r4]
	b _08158BFE
	.pool
_08158BD0:
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	strh r0, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	bne _08158BEA
	strh r1, [r4, 0x1C]
	ldrh r0, [r4, 0x8]
	lsls r1, r5, 24
	asrs r1, 24
	bl audio_play_and_stuff
_08158BEA:
	lsls r1, r6, 24
	asrs r1, 24
	lsls r0, r5, 16
	asrs r0, 16
	adds r0, r1
	lsls r0, 16
	asrs r0, 16
	bl sub_80A52EC
	strh r0, [r4, 0xC]
_08158BFE:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8158B98

	thumb_func_start sub_8158C04
sub_8158C04: @ 8158C04
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	strh r0, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	bne _08158C4C
	movs r0, 0
	strh r0, [r4, 0x1C]
	movs r0, 0x3F
	bl sub_80A5178
	adds r1, r0, 0
	ldrh r0, [r4, 0xA]
	lsls r1, 24
	asrs r1, 24
	bl audio_play_and_stuff
	ldrh r0, [r4, 0x1E]
	adds r0, 0x1
	strh r0, [r4, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	bne _08158C4C
	adds r0, r5, 0
	bl move_anim_related_task_del
_08158C4C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8158C04

	thumb_func_start mas_80DCF38
mas_80DCF38: @ 8158C58
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r8, r0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =gUnknown_0203841E
	ldrh r1, [r0]
	str r1, [sp]
	ldrb r5, [r0, 0x4]
	ldrb r6, [r0, 0x6]
	ldrb r3, [r0, 0x8]
	mov r10, r3
	ldrb r7, [r0, 0xA]
	ldrb r1, [r0, 0xC]
	mov r9, r1
	ldrb r0, [r0, 0x2]
	lsls r0, 24
	asrs r0, 24
	bl sub_80A5178
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	asrs r5, 24
	adds r0, r5, 0
	bl sub_80A5178
	adds r5, r0, 0
	lsls r4, 24
	asrs r4, 24
	lsls r5, 24
	asrs r5, 24
	lsls r6, 24
	asrs r6, 24
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_80A5314
	ldr r2, =gTasks
	mov r3, r8
	lsls r1, r3, 2
	add r1, r8
	lsls r1, 3
	adds r1, r2
	movs r2, 0
	mov r6, sp
	ldrh r6, [r6]
	strh r6, [r1, 0x8]
	strh r4, [r1, 0xA]
	strh r5, [r1, 0xC]
	lsls r0, 24
	asrs r0, 24
	strh r0, [r1, 0xE]
	mov r0, r10
	strh r0, [r1, 0x10]
	strh r7, [r1, 0x12]
	mov r3, r9
	strh r3, [r1, 0x14]
	strh r2, [r1, 0x1C]
	strh r4, [r1, 0x1E]
	strh r3, [r1, 0x20]
	ldr r2, =sub_8158D08
	str r2, [r1]
	mov r0, r8
	bl _call_via_r2
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end mas_80DCF38

	thumb_func_start sub_8158D08
sub_8158D08: @ 8158D08
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x20]
	adds r1, r0, 0x1
	strh r1, [r4, 0x20]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x14
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bne _08158D50
	movs r0, 0
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x8]
	movs r1, 0x1E
	ldrsb r1, [r4, r1]
	bl audio_play_and_stuff
	ldrh r0, [r4, 0x10]
	subs r0, 0x1
	strh r0, [r4, 0x10]
	lsls r0, 16
	cmp r0, 0
	bne _08158D50
	adds r0, r5, 0
	bl move_anim_related_task_del
	b _08158D82
	.pool
_08158D50:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x1C]
	adds r1, r0, 0x1
	strh r1, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bne _08158D82
	movs r0, 0
	strh r0, [r4, 0x1C]
	ldrh r0, [r4, 0xE]
	ldrh r1, [r4, 0x1E]
	adds r0, r1
	strh r0, [r4, 0x1E]
	movs r2, 0x1E
	ldrsh r0, [r4, r2]
	bl sub_80A52EC
	strh r0, [r4, 0x1E]
_08158D82:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8158D08

	thumb_func_start sub_8158D8C
sub_8158D8C: @ 8158D8C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	movs r0, 0x40
	negs r0, r0
	bl sub_80A5178
	lsls r0, 24
	lsrs r6, r0, 24
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	beq _08158DD0
	ldr r0, =gUnknown_0203841E
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08158DC8
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldrh r4, [r0]
	b _08158E76
	.pool
_08158DC8:
	adds r0, r5, 0
	bl move_anim_task_del
	b _08158E76
_08158DD0:
	ldr r0, =gUnknown_0203841E
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r2, r0, 0
	cmp r1, 0
	bne _08158DEC
	ldr r0, =gUnknown_02038436
	ldrb r4, [r0]
	b _08158E12
	.pool
_08158DEC:
	cmp r1, 0x1
	bne _08158DFC
	ldr r0, =gUnknown_02038437
	ldrb r4, [r0]
	b _08158E12
	.pool
_08158DFC:
	cmp r1, 0x2
	bne _08158E08
	ldr r0, =gUnknown_02038436
	b _08158E0A
	.pool
_08158E08:
	ldr r0, =gUnknown_02038437
_08158E0A:
	ldrb r1, [r0]
	movs r0, 0x2
	adds r4, r0, 0
	eors r4, r1
_08158E12:
	movs r1, 0
	ldrsh r0, [r2, r1]
	cmp r0, 0x1
	beq _08158E1E
	cmp r0, 0x3
	bne _08158E38
_08158E1E:
	adds r0, r4, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	bne _08158E38
	adds r0, r5, 0
	bl move_anim_task_del
	b _08158E8C
	.pool
_08158E38:
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08158E5C
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	b _08158E6A
	.pool
_08158E5C:
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
_08158E6A:
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
_08158E76:
	cmp r4, 0
	beq _08158E86
	lsls r1, r6, 24
	asrs r1, 24
	adds r0, r4, 0
	movs r2, 0x3
	bl sub_80A32E4
_08158E86:
	adds r0, r5, 0
	bl move_anim_task_del
_08158E8C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8158D8C

	thumb_func_start sub_8158E9C
sub_8158E9C: @ 8158E9C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r4, 0
	movs r0, 0x40
	negs r0, r0
	bl sub_80A5178
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	beq _08158EE0
	ldr r0, =gUnknown_0203841E
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08158ED8
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldrh r4, [r0]
	b _08158F86
	.pool
_08158ED8:
	adds r0, r6, 0
	bl move_anim_task_del
	b _08158F86
_08158EE0:
	ldr r0, =gUnknown_0203841E
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r2, r0, 0
	cmp r1, 0
	bne _08158EFC
	ldr r0, =gUnknown_02038436
	ldrb r4, [r0]
	b _08158F22
	.pool
_08158EFC:
	cmp r1, 0x1
	bne _08158F0C
	ldr r0, =gUnknown_02038437
	ldrb r4, [r0]
	b _08158F22
	.pool
_08158F0C:
	cmp r1, 0x2
	bne _08158F18
	ldr r0, =gUnknown_02038436
	b _08158F1A
	.pool
_08158F18:
	ldr r0, =gUnknown_02038437
_08158F1A:
	ldrb r1, [r0]
	movs r0, 0x2
	adds r4, r0, 0
	eors r4, r1
_08158F22:
	movs r1, 0
	ldrsh r0, [r2, r1]
	cmp r0, 0x1
	beq _08158F2E
	cmp r0, 0x3
	bne _08158F48
_08158F2E:
	adds r0, r4, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	bne _08158F48
	adds r0, r6, 0
	bl move_anim_task_del
	b _08158FEE
	.pool
_08158F48:
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08158F6C
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	b _08158F7A
	.pool
_08158F6C:
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
_08158F7A:
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
_08158F86:
	ldr r1, =gTasks
	lsls r2, r6, 2
	adds r0, r2, r6
	lsls r0, 3
	adds r0, r1
	ldr r3, =gUnknown_0203841E
	ldrh r1, [r3, 0x2]
	strh r1, [r0, 0x8]
	strh r4, [r0, 0xA]
	lsls r1, r5, 24
	asrs r1, 24
	strh r1, [r0, 0xC]
	adds r5, r2, 0
	cmp r4, 0
	beq _08158FE8
	movs r2, 0x2
	ldrsh r0, [r3, r2]
	cmp r0, 0xFF
	bne _08158FC8
	adds r0, r4, 0
	movs r2, 0x9
	bl sub_80A32E4
	b _08158FD0
	.pool
_08158FC8:
	adds r0, r4, 0
	movs r2, 0x7
	bl sub_80A32E4
_08158FD0:
	ldr r0, =gTasks
	adds r1, r5, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8158FF4
	str r0, [r1]
	b _08158FEE
	.pool
_08158FE8:
	adds r0, r6, 0
	bl move_anim_task_del
_08158FEE:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8158E9C

	thumb_func_start sub_8158FF4
sub_8158FF4: @ 8158FF4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r4, r0, 24
	mov r9, r4
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r1
	ldrh r6, [r1, 0xA]
	mov r8, r6
	ldrb r5, [r1, 0xC]
	adds r7, r5, 0
	ldrh r2, [r1, 0x1A]
	movs r3, 0x1A
	ldrsh r0, [r1, r3]
	cmp r0, 0x1
	bgt _08159028
	adds r0, r2, 0x1
	strh r0, [r1, 0x1A]
	b _0815906A
	.pool
_08159028:
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0xFF
	bne _0815904E
	bl sub_80A36EC
	lsls r0, 24
	cmp r0, 0
	bne _0815906A
	lsls r1, r5, 24
	asrs r1, 24
	adds r0, r6, 0
	movs r2, 0xA
	bl sub_80A32E4
	adds r0, r4, 0
	bl move_anim_task_del
	b _0815906A
_0815904E:
	bl sub_80A36EC
	lsls r0, 24
	cmp r0, 0
	bne _0815906A
	lsls r1, r7, 24
	asrs r1, 24
	mov r0, r8
	movs r2, 0x8
	bl sub_80A32E4
	mov r0, r9
	bl move_anim_task_del
_0815906A:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8158FF4

	thumb_func_start sub_8159078
sub_8159078: @ 8159078
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r1
	ldrh r2, [r1, 0x1A]
	movs r3, 0x1A
	ldrsh r0, [r1, r3]
	cmp r0, 0x1
	bgt _081590A0
	adds r0, r2, 0x1
	strh r0, [r1, 0x1A]
	b _081590B0
	.pool
_081590A0:
	bl sub_80A36EC
	lsls r0, 24
	cmp r0, 0
	bne _081590B0
	adds r0, r4, 0
	bl move_anim_task_del
_081590B0:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8159078

	thumb_func_start sub_81590B8
sub_81590B8: @ 81590B8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =gUnknown_0203841E
	ldrh r1, [r1]
	strh r1, [r0, 0x1C]
	movs r0, 0x40
	negs r0, r0
	bl sub_80A5178
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	beq _081590F8
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	b _08159102
	.pool
_081590F8:
	ldr r1, =gUnknown_02038438
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
_08159102:
	ldrh r2, [r0]
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	strh r2, [r1, 0xA]
	lsls r0, r5, 24
	asrs r0, 24
	strh r0, [r1, 0xC]
	cmp r2, 0
	beq _08159130
	ldr r0, =sub_815913C
	str r0, [r1]
	b _08159136
	.pool
_08159130:
	adds r0, r4, 0
	bl move_anim_task_del
_08159136:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81590B8

	thumb_func_start sub_815913C
sub_815913C: @ 815913C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrh r6, [r0, 0xA]
	mov r8, r6
	ldrb r3, [r0, 0xC]
	adds r5, r3, 0
	movs r7, 0x1A
	ldrsh r2, [r0, r7]
	mov r12, r1
	cmp r2, 0x5
	bhi _081591DC
	lsls r0, r2, 2
	ldr r1, =_08159174
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08159174:
	.4byte _081591C2
	.4byte _081591A8
	.4byte _0815918C
	.4byte _081591A8
	.4byte _081591A8
	.4byte _081591B8
_0815918C:
	lsls r1, r5, 24
	asrs r1, 24
	mov r0, r8
	movs r2, 0x4
	bl play_cry_maybe
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	b _081591B0
	.pool
_081591A8:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	add r0, r12
_081591B0:
	ldrh r1, [r0, 0x1A]
	adds r1, 0x1
	strh r1, [r0, 0x1A]
	b _08159204
_081591B8:
	bl sub_80A36EC
	lsls r0, 24
	cmp r0, 0
	bne _08159204
_081591C2:
	bl sub_80A369C
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x1A]
	adds r0, 0x1
	strh r0, [r1, 0x1A]
	b _08159204
	.pool
_081591DC:
	movs r1, 0x1C
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _081591F2
	lsls r1, r3, 24
	asrs r1, 24
	adds r0, r6, 0
	movs r2, 0x6
	bl play_cry_maybe
	b _081591FE
_081591F2:
	lsls r1, r5, 24
	asrs r1, 24
	mov r0, r8
	movs r2, 0x6
	bl sub_80A32E4
_081591FE:
	adds r0, r4, 0
	bl move_anim_task_del
_08159204:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_815913C

	thumb_func_start sub_8159210
sub_8159210: @ 8159210
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203841E
	ldrh r5, [r0]
	ldrb r0, [r0, 0x2]
	lsls r0, 24
	asrs r0, 24
	bl sub_80A5178
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	adds r0, r5, 0
	bl sub_80A3808
	adds r0, r4, 0
	bl move_anim_task_del
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159210

	thumb_func_start sub_8159244
sub_8159244: @ 8159244
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203841E
	ldrh r5, [r0]
	ldrb r0, [r0, 0x2]
	lsls r0, 24
	asrs r0, 24
	bl sub_80A5178
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	adds r0, r5, 0
	bl sub_80A383C
	adds r0, r4, 0
	bl move_anim_task_del
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159244

	thumb_func_start sub_8159278
sub_8159278: @ 8159278
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	mov r8, r0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =gUnknown_0203841E
	ldrb r5, [r0, 0x2]
	ldrb r6, [r0, 0x4]
	ldrh r1, [r0, 0x6]
	mov r9, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	bl sub_80A5178
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	asrs r5, 24
	adds r0, r5, 0
	bl sub_80A5178
	adds r5, r0, 0
	lsls r4, 24
	asrs r4, 24
	lsls r5, 24
	asrs r5, 24
	lsls r6, 24
	asrs r6, 24
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_80A5314
	ldr r2, =gTasks
	mov r3, r8
	lsls r1, r3, 2
	add r1, r8
	lsls r1, 3
	adds r1, r2
	movs r2, 0
	strh r4, [r1, 0xA]
	strh r5, [r1, 0xC]
	lsls r0, 24
	asrs r0, 24
	strh r0, [r1, 0xE]
	mov r0, r9
	strh r0, [r1, 0x12]
	strh r2, [r1, 0x1C]
	strh r4, [r1, 0x1E]
	ldr r2, =sub_8159308
	str r2, [r1]
	mov r0, r8
	bl _call_via_r2
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159278

	thumb_func_start sub_8159308
sub_8159308: @ 8159308
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r2, [r4, 0xE]
	ldrh r0, [r4, 0x1C]
	adds r1, r0, 0x1
	strh r1, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x12
	ldrsh r1, [r4, r3]
	cmp r0, r1
	bne _08159342
	movs r0, 0
	strh r0, [r4, 0x1C]
	ldrh r1, [r4, 0x1E]
	adds r0, r2, r1
	strh r0, [r4, 0x1E]
	movs r2, 0x1E
	ldrsh r0, [r4, r2]
	bl sub_80A52EC
	strh r0, [r4, 0x1E]
_08159342:
	ldr r1, =gUnknown_02038440
	ldrh r0, [r4, 0x1E]
	strb r0, [r1]
	movs r3, 0x1E
	ldrsh r1, [r4, r3]
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _0815935A
	adds r0, r5, 0
	bl move_anim_task_del
_0815935A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159308

	thumb_func_start nullsub_114
nullsub_114: @ 8159368
	bx lr
	thumb_func_end nullsub_114

	thumb_func_start sub_815936C
sub_815936C: @ 815936C
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_exec_buffer_A_ch0_tbl6
	str r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_815936C

	thumb_func_start bx_exec_buffer_A_ch0_tbl6
bx_exec_buffer_A_ch0_tbl6: @ 8159388
	push {lr}
	ldr r2, =gBattleExecBuffer
	ldr r1, =gBitTable
	ldr r0, =gActiveBank
	ldrb r3, [r0]
	lsls r0, r3, 2
	adds r0, r1
	ldr r1, [r2]
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _081593D4
	ldr r0, =gBattleBufferA
	lsls r1, r3, 9
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x38
	bhi _081593D0
	ldr r0, =gUnknown_085CDF20
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	bl _call_via_r0
	b _081593D4
	.pool
_081593D0:
	bl dp01_tbl6_exec_completed
_081593D4:
	pop {r0}
	bx r0
	thumb_func_end bx_exec_buffer_A_ch0_tbl6

	thumb_func_start bx_battle_menu_t6_2
bx_battle_menu_t6_2: @ 81593D8
	push {r4,r5,lr}
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _08159446
	movs r0, 0x5
	bl audio_play
	ldr r1, =gUnknown_020244AC
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08159424
	cmp r0, 0x1
	bgt _08159414
	cmp r0, 0
	beq _0815941E
	b _08159440
	.pool
_08159414:
	cmp r0, 0x2
	beq _0815942A
	cmp r0, 0x3
	beq _08159436
	b _08159440
_0815941E:
	movs r0, 0x1
	movs r1, 0x5
	b _0815942E
_08159424:
	movs r0, 0x1
	movs r1, 0x6
	b _0815942E
_0815942A:
	movs r0, 0x1
	movs r1, 0x7
_0815942E:
	movs r2, 0
	bl dp01_build_cmdbuf_x21_a_bb
	b _08159440
_08159436:
	movs r0, 0x1
	movs r1, 0x8
	movs r2, 0
	bl dp01_build_cmdbuf_x21_a_bb
_08159440:
	bl dp01_tbl6_exec_completed
	b _0815954E
_08159446:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08159484
	ldr r5, =gUnknown_020244AC
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _0815954E
	movs r0, 0x5
	bl audio_play
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	bl sub_8059CF8
	ldrb r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	movs r2, 0x1
	b _081594F2
	.pool
_08159484:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081594C0
	ldr r5, =gUnknown_020244AC
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _0815954E
	movs r0, 0x5
	bl audio_play
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	bl sub_8059CF8
	ldrb r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	movs r2, 0x1
	b _081594F2
	.pool
_081594C0:
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0815950C
	ldr r5, =gUnknown_020244AC
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0815954E
	movs r0, 0x5
	bl audio_play
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	bl sub_8059CF8
	ldrb r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	movs r2, 0x2
_081594F2:
	eors r0, r2
	strb r0, [r1]
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8059CB4
	b _0815954E
	.pool
_0815950C:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0815954E
	ldr r5, =gUnknown_020244AC
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0815954E
	movs r0, 0x5
	bl audio_play
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	bl sub_8059CF8
	ldrb r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	movs r2, 0x2
	eors r0, r2
	strb r0, [r1]
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8059CB4
_0815954E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_battle_menu_t6_2

	thumb_func_start sub_815955C
sub_815955C: @ 815955C
	push {lr}
	ldr r2, =gSprites
	ldr r1, =gBankSpriteIds
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _08159580
	bl dp01_tbl6_exec_completed
_08159580:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815955C

	thumb_func_start bx_t6_button_a
bx_t6_button_a: @ 8159594
	push {lr}
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _081595A6
	bl dp01_tbl6_exec_completed
_081595A6:
	pop {r0}
	bx r0
	thumb_func_end bx_t6_button_a

	thumb_func_start sub_81595AC
sub_81595AC: @ 81595AC
	push {lr}
	ldr r2, =gSprites
	ldr r1, =gUnknown_03005D70
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _081595D0
	bl dp01_tbl6_exec_completed
_081595D0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81595AC

	thumb_func_start sub_81595E4
sub_81595E4: @ 81595E4
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0815960E
	ldr r2, =gMain
	ldr r0, =0x00000439
	adds r3, r2, r0
	ldrb r1, [r3]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
	ldr r0, =gUnknown_03005D00
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, [r2, 0x8]
	bl SetMainCallback2
_0815960E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81595E4

	thumb_func_start bx_wait_t6
bx_wait_t6: @ 8159624
	push {lr}
	ldr r0, =gDoingBattleAnim
	ldrb r0, [r0]
	cmp r0, 0
	beq _0815964A
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0815964E
_0815964A:
	bl dp01_tbl6_exec_completed
_0815964E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_wait_t6

	thumb_func_start sub_8159660
sub_8159660: @ 8159660
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08159684
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8159698
	str r1, [r0]
	bl FreeAllWindowBuffers
	bl sub_81358F4
_08159684:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159660

	thumb_func_start sub_8159698
sub_8159698: @ 8159698
	push {lr}
	ldr r0, =gMain
	ldr r1, [r0, 0x4]
	ldr r0, =sub_8038420
	cmp r1, r0
	bne _081596BE
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081596BE
	ldr r0, =gUnknown_0203CE7C
	ldrh r1, [r0]
	movs r0, 0x1
	bl dp01_build_cmdbuf_x23_aa_0
	bl dp01_tbl6_exec_completed
_081596BE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159698

	thumb_func_start sub_81596D4
sub_81596D4: @ 81596D4
	push {lr}
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _081596F6
	bl dp01_tbl6_exec_completed
_081596F6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81596D4

	thumb_func_start dp01_tbl6_exec_completed
dp01_tbl6_exec_completed: @ 8159704
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gBattleBankFunc
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_exec_buffer_A_ch0_tbl6
	str r1, [r0]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08159758
	bl link_get_multiplayer_id
	mov r1, sp
	strb r0, [r1]
	movs r0, 0x2
	movs r1, 0x4
	mov r2, sp
	bl PrepareBufferDataTransferLink
	ldr r1, =gBattleBufferA
	ldrb r0, [r4]
	lsls r0, 9
	adds r0, r1
	movs r1, 0x38
	strb r1, [r0]
	b _0815976A
	.pool
_08159758:
	ldr r2, =gBattleExecBuffer
	ldr r1, =gBitTable
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
_0815976A:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_tbl6_exec_completed

	thumb_func_start bx_80364D0
bx_80364D0: @ 815977C
	push {lr}
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _0815979E
	bl dp01_tbl6_exec_completed
_0815979E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_80364D0

	thumb_func_start sub_81597AC
sub_81597AC: @ 81597AC
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81597AC

	thumb_func_start sub_81597B8
sub_81597B8: @ 81597B8
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81597B8

	thumb_func_start sub_81597C4
sub_81597C4: @ 81597C4
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81597C4

	thumb_func_start sub_81597D0
sub_81597D0: @ 81597D0
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81597D0

	thumb_func_start sub_81597DC
sub_81597DC: @ 81597DC
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81597DC

	thumb_func_start sub_81597E8
sub_81597E8: @ 81597E8
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81597E8

	thumb_func_start sub_81597F4
sub_81597F4: @ 81597F4
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81597F4

	thumb_func_start sub_8159800
sub_8159800: @ 8159800
	push {r4-r6,lr}
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	ldr r5, =gActiveBank
	ldrb r1, [r5]
	bl sub_805DF84
	ldr r0, [r4]
	ldrb r6, [r0, 0x8]
	ldrb r0, [r5]
	bl GetBankIdentity
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl template_build_for_pokemon_or_trainer
	ldr r0, =gUnknown_0202499C
	ldr r2, =gUnknown_08305D2C
	ldr r1, [r4]
	ldrb r1, [r1, 0x8]
	lsls r1, 2
	adds r1, r2
	ldrb r1, [r1]
	movs r2, 0x8
	subs r2, r1
	lsls r2, 18
	movs r1, 0xA0
	lsls r1, 15
	adds r2, r1
	asrs r2, 16
	movs r1, 0x50
	movs r3, 0x1E
	bl CreateSprite
	ldr r6, =gBankSpriteIds
	ldrb r1, [r5]
	adds r1, r6
	strb r0, [r1]
	ldr r4, =gSprites
	ldrb r3, [r5]
	adds r0, r3, r6
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	lsls r3, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0xF0
	strh r1, [r0, 0x24]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =0x0000fffe
	strh r1, [r0, 0x2E]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, 0x1C
	adds r0, r4
	ldr r1, =sub_805D7AC
	str r1, [r0]
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_815955C
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159800

	thumb_func_start sub_81598E0
sub_81598E0: @ 81598E0
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81598E0

	thumb_func_start sub_81598EC
sub_81598EC: @ 81598EC
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81598EC

	thumb_func_start sub_81598F8
sub_81598F8: @ 81598F8
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81598F8

	thumb_func_start sub_8159904
sub_8159904: @ 8159904
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159904

	thumb_func_start sub_8159910
sub_8159910: @ 8159910
	push {r4,r5,lr}
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0, 0x8]
	movs r0, 0x4
	strb r0, [r1, 0x8]
	ldr r1, =gDoingBattleAnim
	movs r0, 0x1
	strb r0, [r1]
	ldr r5, =gActiveBank
	ldrb r4, [r5]
	movs r0, 0x1
	bl GetBankByPlayerAI
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r4, 0
	movs r3, 0x4
	bl move_anim_start_t4
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_wait_t6
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159910

	thumb_func_start sub_8159964
sub_8159964: @ 8159964
	push {r4,r5,lr}
	ldr r1, =gBattleBufferA
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r1, [r0]
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	strb r1, [r0, 0x8]
	ldr r1, =gDoingBattleAnim
	movs r0, 0x1
	strb r0, [r1]
	ldrb r4, [r5]
	movs r0, 0x1
	bl GetBankByPlayerAI
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r4, 0
	movs r3, 0x4
	bl move_anim_start_t4
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_wait_t6
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159964

	thumb_func_start sub_81599C4
sub_81599C4: @ 81599C4
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81599C4

	thumb_func_start sub_81599D0
sub_81599D0: @ 81599D0
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_81599D0

	thumb_func_start dp01t_10_6_message
dp01t_10_6_message: @ 81599DC
	push {r4,lr}
	ldr r0, =gUnknown_02022E14
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E16
	strh r1, [r0]
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 9
	ldr r1, =gUnknown_02023066
	adds r0, r1
	ldrh r0, [r0]
	bl battle_pick_message
	ldr r0, =gUnknown_02022E2C
	movs r1, 0
	bl battle_show_message_maybe
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_t6_button_a
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_10_6_message

	thumb_func_start dp01t_11_6_message_for_player_only
dp01t_11_6_message_for_player_only: @ 8159A30
	push {lr}
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08159A4C
	bl dp01t_10_6_message
	b _08159A50
	.pool
_08159A4C:
	bl dp01_tbl6_exec_completed
_08159A50:
	pop {r0}
	bx r0
	thumb_func_end dp01t_11_6_message_for_player_only

	thumb_func_start sub_8159A54
sub_8159A54: @ 8159A54
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _08159A7A
	ldr r0, =gUnknown_02022E14
	strh r1, [r0]
	ldr r1, =gUnknown_02022E16
	movs r0, 0xA0
	strh r0, [r1]
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_battle_menu_t6_2
	str r1, [r0]
_08159A7A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159A54

	thumb_func_start sub_8159A94
sub_8159A94: @ 8159A94
	push {r4,lr}
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8159A54
	str r1, [r0]
	ldr r0, =gUnknown_085CCA54
	movs r1, 0x2
	bl battle_show_message_maybe
	movs r4, 0
_08159AAE:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8059CF8
	adds r4, 0x1
	cmp r4, 0x3
	ble _08159AAE
	ldr r1, =gUnknown_020244AC
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8059CB4
	ldr r0, =gUnknown_085CCA04
	bl get_battle_strings_
	ldr r0, =gUnknown_02022E2C
	movs r1, 0x1
	bl battle_show_message_maybe
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159A94

	thumb_func_start sub_8159AFC
sub_8159AFC: @ 8159AFC
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159AFC

	thumb_func_start sub_8159B08
sub_8159B08: @ 8159B08
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159B08

	thumb_func_start sub_8159B14
sub_8159B14: @ 8159B14
	push {lr}
	sub sp, 0x4
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gBattleBankFunc
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8159660
	str r1, [r0]
	ldr r1, =gUnknown_020244B8
	ldrb r0, [r2]
	strb r0, [r1]
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159B14

	thumb_func_start sub_8159B54
sub_8159B54: @ 8159B54
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159B54

	thumb_func_start sub_8159B60
sub_8159B60: @ 8159B60
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159B60

	thumb_func_start sub_8159B6C
sub_8159B6C: @ 8159B6C
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159B6C

	thumb_func_start sub_8159B78
sub_8159B78: @ 8159B78
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159B78

	thumb_func_start sub_8159B84
sub_8159B84: @ 8159B84
	push {lr}
	ldr r0, =gUnknown_03005D70
	ldr r1, =gActiveBank
	ldrb r1, [r1]
	adds r0, r1, r0
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gPlayerParty
	adds r1, r2
	movs r2, 0xB
	bl healthbar_draw_field_maybe
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159B84

	thumb_func_start sub_8159BC0
sub_8159BC0: @ 8159BC0
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159BC0

	thumb_func_start sub_8159BCC
sub_8159BCC: @ 8159BCC
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159BCC

	thumb_func_start sub_8159BD8
sub_8159BD8: @ 8159BD8
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159BD8

	thumb_func_start sub_8159BE4
sub_8159BE4: @ 8159BE4
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159BE4

	thumb_func_start sub_8159BF0
sub_8159BF0: @ 8159BF0
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159BF0

	thumb_func_start sub_8159BFC
sub_8159BFC: @ 8159BFC
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159BFC

	thumb_func_start sub_8159C08
sub_8159C08: @ 8159C08
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159C08

	thumb_func_start sub_8159C14
sub_8159C14: @ 8159C14
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159C14

	thumb_func_start sub_8159C20
sub_8159C20: @ 8159C20
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159C20

	thumb_func_start sub_8159C2C
sub_8159C2C: @ 8159C2C
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159C2C

	thumb_func_start sub_8159C38
sub_8159C38: @ 8159C38
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159C38

	thumb_func_start sub_8159C44
sub_8159C44: @ 8159C44
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159C44

	thumb_func_start sub_8159C50
sub_8159C50: @ 8159C50
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159C50

	thumb_func_start sub_8159C5C
sub_8159C5C: @ 8159C5C
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159C5C

	thumb_func_start sub_8159C68
sub_8159C68: @ 8159C68
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159C68

	thumb_func_start sub_8159C74
sub_8159C74: @ 8159C74
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159C74

	thumb_func_start sub_8159C80
sub_8159C80: @ 8159C80
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	movs r3, 0x3F
	cmp r0, 0
	bne _08159C94
	movs r3, 0xC0
_08159C94:
	ldr r2, =gBattleBufferA
	ldrb r1, [r4]
	lsls r1, 9
	adds r0, r2, 0x1
	adds r0, r1, r0
	ldrb r0, [r0]
	adds r2, 0x2
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	lsls r1, r3, 24
	asrs r1, 24
	bl audio_play_and_stuff
	bl dp01_tbl6_exec_completed
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159C80

	thumb_func_start dp01t_34_6_move_anim_start_t3
dp01t_34_6_move_anim_start_t3: @ 8159CC4
	push {r4,r5,lr}
	ldr r4, =gBattleBufferA
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r3, r0, 9
	adds r0, r4, 0x3
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, 0
	beq _08159D00
	bl sub_805EA60
	ldrb r1, [r5]
	lsls r1, 9
	adds r0, r4, 0x1
	adds r0, r1, r0
	ldrb r0, [r0]
	adds r2, r4, 0x2
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	bl song_play_for_text
	b _08159D14
	.pool
_08159D00:
	adds r0, r4, 0x1
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r1, r4, 0x2
	adds r1, r3, r1
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	bl fanfare_play
_08159D14:
	bl dp01_tbl6_exec_completed
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end dp01t_34_6_move_anim_start_t3

	thumb_func_start sub_8159D20
sub_8159D20: @ 8159D20
	push {lr}
	ldr r1, =gBattlePartyID
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x19
	bl cry_related
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159D20

	thumb_func_start dp01t_2E_6_battle_intro
dp01t_2E_6_battle_intro: @ 8159D5C
	push {lr}
	ldr r1, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	bl battle_intro_launch
	ldr r2, =gUnknown_020243FC
	ldrh r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r2]
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_2E_6_battle_intro

	thumb_func_start sub_8159D90
sub_8159D90: @ 8159D90
	push {r4,r5,lr}
	ldr r5, =gUnknown_03005D70
	ldr r4, =gActiveBank
	ldrb r1, [r4]
	adds r0, r1, r5
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gPlayerParty
	adds r1, r2
	movs r2, 0xA
	bl healthbar_draw_field_maybe
	ldrb r0, [r4]
	bl sub_8076918
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	bl sub_80729D0
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_81595AC
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159D90

	thumb_func_start sub_8159DEC
sub_8159DEC: @ 8159DEC
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159DEC

	thumb_func_start sub_8159DF8
sub_8159DF8: @ 8159DF8
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159DF8

	thumb_func_start sub_8159E04
sub_8159E04: @ 8159E04
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159E04

	thumb_func_start sub_8159E10
sub_8159E10: @ 8159E10
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159E10

	thumb_func_start sub_8159E1C
sub_8159E1C: @ 8159E1C
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r5, =gBattleBufferA
	ldr r6, =gActiveBank
	ldrb r2, [r6]
	lsls r1, r2, 9
	adds r0, r5, 0x1
	adds r0, r1, r0
	ldrb r3, [r0]
	adds r0, r5, 0x2
	adds r0, r1, r0
	ldrb r4, [r0]
	adds r5, 0x3
	adds r1, r5
	ldrb r0, [r1]
	lsls r0, 8
	orrs r4, r0
	str r4, [sp]
	adds r0, r2, 0
	adds r1, r2, 0
	bl move_anim_start_t3
	lsls r0, 24
	cmp r0, 0
	beq _08159E5C
	bl dp01_tbl6_exec_completed
	b _08159E68
	.pool
_08159E5C:
	ldr r0, =gBattleBankFunc
	ldrb r1, [r6]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_81596D4
	str r0, [r1]
_08159E68:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159E1C

	thumb_func_start sub_8159E78
sub_8159E78: @ 8159E78
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159E78

	thumb_func_start sub_8159E84
sub_8159E84: @ 8159E84
	push {lr}
	bl dp01_tbl6_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8159E84

	thumb_func_start sub_8159E90
sub_8159E90: @ 8159E90
	push {r4,lr}
	ldr r2, =gBattleOutcome
	ldr r1, =gBattleBufferA
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	movs r0, 0x5
	bl sub_80A2F50
	movs r0, 0x3
	bl BeginFastPaletteFade
	bl dp01_tbl6_exec_completed
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x6
	ands r0, r1
	cmp r0, 0x2
	bne _08159ECC
	ldr r0, =gBattleBankFunc
	ldrb r1, [r4]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_81595E4
	str r0, [r1]
_08159ECC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159E90

	thumb_func_start nullsub_115
nullsub_115: @ 8159EEC
	bx lr
	thumb_func_end nullsub_115

	thumb_func_start sub_8159EF0
sub_8159EF0: @ 8159EF0
	ldr r1, =gUnknown_03005DB0
	ldr r0, =hm_add_c3_launch_phase_2
	str r0, [r1]
	ldr r1, =gUnknown_0203CEEC
	ldr r0, =hm2_sweet_scent
	str r0, [r1]
	movs r0, 0x1
	bx lr
	.pool
	thumb_func_end sub_8159EF0

	thumb_func_start hm2_sweet_scent
hm2_sweet_scent: @ 8159F10
	push {lr}
	movs r0, 0x33
	bl FieldEffectStart
	bl brm_get_pokemon_selection
	ldr r1, =gUnknown_02038C08
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end hm2_sweet_scent

	thumb_func_start sub_8159F2C
sub_8159F2C: @ 8159F2C
	push {lr}
	bl sub_80AC3D0
	bl oei_task_add
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r2, =sub_8159F5C
	lsrs r0, r2, 16
	strh r0, [r1, 0x18]
	strh r2, [r1, 0x1A]
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8159F2C

	thumb_func_start sub_8159F5C
sub_8159F5C: @ 8159F5C
	push {r4,r5,lr}
	sub sp, 0x4
	movs r0, 0xEC
	bl audio_play
	ldr r5, =gPlttBufferUnfaded
	ldr r1, =sPaletteDecompressionBuffer
	movs r4, 0x80
	lsls r4, 1
	adds r0, r5, 0
	adds r2, r4, 0
	bl CpuFastSet
	ldr r0, =gPlttBufferFaded
	adds r1, r5, 0
	adds r2, r4, 0
	bl CpuFastSet
	bl GetPlayerAvatarObjectId
	ldr r2, =gSprites
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r1, [r1, 0x5]
	lsrs r1, 4
	adds r1, 0x10
	movs r0, 0x1
	lsls r0, r1
	mvns r0, r0
	movs r1, 0x1F
	str r1, [sp]
	movs r1, 0x4
	movs r2, 0
	movs r3, 0x8
	bl BeginNormalPaletteFade
	ldr r0, =sub_8159FEC
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0
	strh r0, [r1, 0x8]
	movs r0, 0x33
	bl FieldEffectActiveListRemove
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159F5C

	thumb_func_start sub_8159FEC
sub_8159FEC: @ 8159FEC
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _0815A088
	bl sub_81BE72C
	movs r0, 0x40
	movs r1, 0x8
	movs r2, 0x1F
	bl BlendPalettes
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r4, r1, r0
	ldrh r1, [r4, 0x8]
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	cmp r0, 0x40
	bne _0815A084
	strh r6, [r4, 0x8]
	bl sub_80B5578
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815A044
	adds r0, r5, 0
	bl DestroyTask
	b _0815A088
	.pool
_0815A044:
	ldr r0, =sub_815A090
	str r0, [r4]
	bl GetPlayerAvatarObjectId
	ldr r2, =gSprites
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r1, [r1, 0x5]
	lsrs r1, 4
	adds r1, 0x10
	movs r0, 0x1
	lsls r0, r1
	mvns r0, r0
	movs r1, 0x1F
	str r1, [sp]
	movs r1, 0x4
	movs r2, 0x8
	movs r3, 0
	bl BeginNormalPaletteFade
	bl sub_81BE6B8
	b _0815A088
	.pool
_0815A084:
	adds r0, r1, 0x1
	strh r0, [r4, 0x8]
_0815A088:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8159FEC

	thumb_func_start sub_815A090
sub_815A090: @ 815A090
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0815A0BE
	ldr r0, =sPaletteDecompressionBuffer
	ldr r1, =gPlttBufferUnfaded
	movs r2, 0x80
	lsls r2, 1
	bl CpuFastSet
	bl sub_80AC3E4
	ldr r0, =gUnknown_08290CAE
	bl script_env_1_execute_new_script
	adds r0, r4, 0
	bl DestroyTask
_0815A0BE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A090

	thumb_func_start sub_815A0D4
sub_815A0D4: @ 815A0D4
	push {lr}
	adds r2, r0, 0
	ldr r1, =gUnknown_0203841E
	ldrh r0, [r1]
	ldrh r3, [r2, 0x20]
	adds r0, r3
	strh r0, [r2, 0x20]
	ldrh r0, [r1, 0x2]
	ldrh r3, [r2, 0x22]
	adds r0, r3
	strh r0, [r2, 0x22]
	movs r3, 0x6
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bne _0815A0FC
	ldrh r0, [r1, 0x4]
	b _0815A100
	.pool
_0815A0FC:
	ldrh r0, [r1, 0x4]
	negs r0, r0
_0815A100:
	strh r0, [r2, 0x2E]
	ldrh r0, [r1, 0x8]
	strh r0, [r2, 0x30]
	ldr r0, =sub_815A114
	str r0, [r2, 0x1C]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A0D4

	thumb_func_start sub_815A114
sub_815A114: @ 815A114
	push {lr}
	adds r3, r0, 0
	movs r1, 0x30
	ldrsh r0, [r3, r1]
	cmp r0, 0
	ble _0815A154
	ldrh r1, [r3, 0x32]
	lsls r0, r1, 16
	asrs r0, 24
	strh r0, [r3, 0x24]
	ldrh r0, [r3, 0x2E]
	adds r1, r0
	strh r1, [r3, 0x32]
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	ldrb r2, [r0]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	ldrh r0, [r3, 0x30]
	subs r0, 0x1
	strh r0, [r3, 0x30]
	b _0815A15A
_0815A154:
	adds r0, r3, 0
	bl move_anim_8072740
_0815A15A:
	pop {r0}
	bx r0
	thumb_func_end sub_815A114

	thumb_func_start sub_815A160
sub_815A160: @ 815A160
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r6, =gUnknown_02038437
	ldrb r0, [r6]
	movs r1, 0x2
	bl sub_80A5C6C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 8
	movs r0, 0x80
	lsls r0, 12
	adds r4, r0
	asrs r4, 16
	ldrb r0, [r6]
	movs r1, 0x3
	bl sub_80A5C6C
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 8
	movs r0, 0x80
	lsls r0, 12
	adds r1, r0
	asrs r1, 16
	adds r0, r4, 0
	movs r2, 0
	bl sub_807521C
	adds r0, r5, 0
	bl move_anim_task_del
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A160

	thumb_func_start sub_815A1B0
sub_815A1B0: @ 815A1B0
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x5A
	strh r0, [r4, 0x2E]
	ldr r0, =sub_80A64B0
	str r0, [r4, 0x1C]
	movs r0, 0x7
	strh r0, [r4, 0x30]
	ldr r1, =sub_815A1F4
	adds r0, r4, 0
	bl oamt_set_x3A_32
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	ldrh r0, [r4, 0x30]
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A1B0

	thumb_func_start sub_815A1F4
sub_815A1F4: @ 815A1F4
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	ldrh r0, [r4, 0x30]
	subs r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	cmp r0, 0
	bge _0815A228
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_815A234
	str r0, [r4, 0x1C]
_0815A228:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A1F4

	thumb_func_start sub_815A234
sub_815A234: @ 815A234
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl move_anim_8072740
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_815A234

	thumb_func_start sub_815A254
sub_815A254: @ 815A254
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	ldr r4, =gUnknown_02038437
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r7, r0, 0
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A6980
	ldrh r0, [r5, 0x20]
	subs r0, r7
	lsls r0, 16
	asrs r0, 16
	ldrh r1, [r5, 0x22]
	subs r1, r6
	lsls r1, 16
	asrs r1, 16
	bl sub_80A74F4
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 23
	adds r0, r1
	lsrs r4, r0, 16
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	beq _0815A2B2
	movs r1, 0x80
	lsls r1, 7
	adds r0, r4, r1
	lsls r0, 16
	lsrs r4, r0, 16
_0815A2B2:
	movs r3, 0x80
	lsls r3, 1
	str r4, [sp]
	adds r0, r5, 0
	movs r1, 0
	adds r2, r3, 0
	bl sub_80A73E0
	ldr r0, =gUnknown_0203841E
	ldrh r0, [r0, 0x4]
	strh r0, [r5, 0x2E]
	strh r7, [r5, 0x32]
	strh r6, [r5, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r5, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r5, 0
	bl oamt_set_x3A_32
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A254

	thumb_func_start sub_815A2F0
sub_815A2F0: @ 815A2F0
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x4
	strh r0, [r4, 0x2E]
	ldr r0, =sub_815A31C
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A2F0

	thumb_func_start sub_815A31C
sub_815A31C: @ 815A31C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0815A342
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	b _0815A346
_0815A342:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
_0815A346:
	strh r0, [r4, 0x2E]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0xF
	beq _0815A354
	cmp r0, 0x4
	bne _0815A35C
_0815A354:
	ldrh r0, [r4, 0x30]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r4, 0x30]
_0815A35C:
	ldrh r0, [r4, 0x32]
	adds r1, r0, 0x1
	strh r1, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x46
	ble _0815A3A0
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r4, 0
	movs r1, 0x1
	bl StartObjectRotScalAnim
	movs r0, 0
	strh r0, [r4, 0x32]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	subs r2, 0x12
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_815A3AC
	str r0, [r4, 0x1C]
_0815A3A0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A31C

	thumb_func_start sub_815A3AC
sub_815A3AC: @ 815A3AC
	push {lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x32]
	adds r1, r0, 0x1
	strh r1, [r3, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x9
	ble _0815A3E8
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	subs r2, 0x12
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	adds r0, r3, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0815A3E8
	ldr r0, =sub_815A3F0
	str r0, [r3, 0x1C]
_0815A3E8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A3AC

	thumb_func_start sub_815A3F0
sub_815A3F0: @ 815A3F0
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, 0x6
	bhi _0815A448
	lsls r0, 2
	ldr r1, =_0815A40C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815A40C:
	.4byte _0815A428
	.4byte _0815A428
	.4byte _0815A432
	.4byte _0815A432
	.4byte _0815A440
	.4byte _0815A440
	.4byte _0815A448
_0815A428:
	movs r1, 0
	movs r0, 0x1
	strh r0, [r4, 0x24]
	strh r1, [r4, 0x26]
	b _0815A450
_0815A432:
	ldr r0, =0x0000ffff
	strh r0, [r4, 0x24]
	movs r0, 0
	b _0815A44E
	.pool
_0815A440:
	movs r0, 0
	strh r0, [r4, 0x24]
	movs r0, 0x1
	b _0815A44E
_0815A448:
	movs r0, 0
	strh r0, [r4, 0x24]
	ldr r0, =0x0000ffff
_0815A44E:
	strh r0, [r4, 0x26]
_0815A450:
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	movs r2, 0
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _0815A462
	strh r2, [r4, 0x34]
_0815A462:
	ldrh r0, [r4, 0x36]
	adds r1, r0, 0x1
	strh r1, [r4, 0x36]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF
	ble _0815A48C
	movs r0, 0x10
	strh r0, [r4, 0x2E]
	strh r2, [r4, 0x30]
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	ldrh r1, [r4, 0x2E]
	movs r0, 0x52
	bl SetGpuReg
	ldr r0, =sub_815A49C
	str r0, [r4, 0x1C]
_0815A48C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A3F0

	thumb_func_start sub_815A49C
sub_815A49C: @ 815A49C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	ldrh r0, [r4, 0x30]
	adds r1, r0, 0x1
	strh r1, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0815A4CC
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	movs r1, 0
	strh r0, [r4, 0x2E]
	strh r1, [r4, 0x30]
_0815A4CC:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815A4E0
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_0815A4E0:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bge _0815A4FE
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl move_anim_8072740
_0815A4FE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_815A49C

	thumb_func_start sub_815A504
sub_815A504: @ 815A504
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =sub_815A52C
	str r0, [r1]
	ldr r1, =gUnknown_020383FE
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_815A504

	thumb_func_start sub_815A52C
sub_815A52C: @ 815A52C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_80A6D94
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r7, =gTasks
	lsls r5, r4, 2
	adds r1, r5, r4
	lsls r1, 3
	adds r1, r7
	ldrh r0, [r1, 0x12]
	adds r0, 0x1
	strh r0, [r1, 0x12]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _0815A59C
	ldr r0, =gPlttBufferFaded
	lsls r2, r6, 4
	adds r1, r2, 0
	adds r1, 0xB
	lsls r1, 1
	adds r1, r0
	ldrh r3, [r1]
	mov r8, r3
	movs r3, 0xA
	mov r9, r7
	adds r7, r5, 0
	mov r12, r0
	adds r5, r2, 0
	lsls r0, r6, 5
	add r0, r12
	adds r2, r0, 0
	adds r2, 0x14
_0815A57A:
	ldrh r0, [r2]
	strh r0, [r1]
	subs r2, 0x2
	subs r1, 0x2
	subs r3, 0x1
	cmp r3, 0
	bgt _0815A57A
	adds r0, r5, 0x1
	lsls r0, 1
	add r0, r12
	movs r1, 0
	mov r2, r8
	strh r2, [r0]
	adds r0, r7, r4
	lsls r0, 3
	add r0, r9
	strh r1, [r0, 0x12]
_0815A59C:
	ldr r0, =gUnknown_0203841E
	ldrh r1, [r0, 0xE]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _0815A5AC
	adds r0, r4, 0
	bl DestroyTask
_0815A5AC:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A52C

	thumb_func_start c3_80DE6F0
c3_80DE6F0: @ 815A5C8
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =sub_815A5F0
	str r0, [r1]
	ldr r1, =gUnknown_020383FE
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end c3_80DE6F0

	thumb_func_start sub_815A5F0
sub_815A5F0: @ 815A5F0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	bl sub_80A6D94
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r5, =gTasks
	mov r0, r8
	lsls r3, r0, 2
	adds r1, r3, r0
	lsls r1, 3
	adds r1, r5
	ldrh r0, [r1, 0x12]
	adds r0, 0x1
	strh r0, [r1, 0x12]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _0815A692
	ldr r0, =gPlttBufferFaded
	lsls r2, r7, 4
	adds r1, r2, 0
	adds r1, 0xB
	lsls r1, 1
	adds r1, r0
	ldrh r6, [r1]
	movs r4, 0xA
	mov r10, r3
	mov r9, r0
	adds r5, r2, 0
	ldr r2, =gPlttBufferUnfaded
	mov r12, r2
	lsls r0, r7, 5
	add r0, r9
	adds r3, r0, 0
	adds r3, 0x14
_0815A644:
	ldrh r0, [r3]
	strh r0, [r1]
	subs r3, 0x2
	subs r1, 0x2
	subs r4, 0x1
	cmp r4, 0
	bgt _0815A644
	adds r0, r5, 0x1
	lsls r0, 1
	add r0, r9
	strh r6, [r0]
	adds r1, r5, 0
	adds r1, 0xB
	lsls r1, 1
	add r1, r12
	ldrh r6, [r1]
	movs r4, 0xA
	lsls r0, r7, 5
	add r0, r12
	adds r2, r0, 0
	adds r2, 0x14
_0815A66E:
	ldrh r0, [r2]
	strh r0, [r1]
	subs r2, 0x2
	subs r1, 0x2
	subs r4, 0x1
	cmp r4, 0
	bgt _0815A66E
	adds r0, r5, 0x1
	lsls r0, 1
	add r0, r12
	movs r1, 0
	strh r6, [r0]
	mov r0, r10
	add r0, r8
	lsls r0, 3
	ldr r2, =gTasks
	adds r0, r2
	strh r1, [r0, 0x12]
_0815A692:
	ldr r0, =gUnknown_0203841E
	ldrh r1, [r0, 0xE]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _0815A6A2
	mov r0, r8
	bl DestroyTask
_0815A6A2:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A5F0

	thumb_func_start sub_815A6C4
sub_815A6C4: @ 815A6C4
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r0, =gUnknown_02038437
	ldrb r0, [r0]
	mov r5, sp
	adds r5, 0x2
	movs r1, 0
	mov r2, sp
	adds r3, r5, 0
	bl sub_80A8924
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0815A6F8
	ldr r1, =gUnknown_0203841E
	ldrh r0, [r1, 0x4]
	negs r0, r0
	strh r0, [r1, 0x4]
_0815A6F8:
	ldr r1, =gUnknown_0203841E
	ldrh r0, [r1, 0x8]
	strh r0, [r4, 0x2E]
	mov r2, sp
	ldrh r0, [r1, 0x4]
	ldrh r2, [r2]
	adds r0, r2
	strh r0, [r4, 0x32]
	ldrh r0, [r1, 0x6]
	ldrh r5, [r5]
	adds r0, r5
	strh r0, [r4, 0x36]
	ldr r0, =0x0000ffce
	strh r0, [r4, 0x38]
	adds r0, r4, 0
	bl sub_80A68D4
	ldr r0, =sub_815A73C
	str r0, [r4, 0x1C]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A6C4

	thumb_func_start sub_815A73C
sub_815A73C: @ 815A73C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _0815A75E
	movs r1, 0
	movs r0, 0x1E
	strh r0, [r4, 0x2E]
	strh r1, [r4, 0x30]
	ldr r0, =sub_80A64B0
	str r0, [r4, 0x1C]
	ldr r1, =sub_815A76C
	adds r0, r4, 0
	bl oamt_set_x3A_32
_0815A75E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A73C

	thumb_func_start sub_815A76C
sub_815A76C: @ 815A76C
	push {lr}
	adds r3, r0, 0
	ldrh r1, [r3, 0x30]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0815A798
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	ldrb r2, [r0]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
_0815A798:
	ldrh r0, [r3, 0x30]
	adds r0, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	bne _0815A7AC
	adds r0, r3, 0
	bl move_anim_8072740
_0815A7AC:
	pop {r0}
	bx r0
	thumb_func_end sub_815A76C

	thumb_func_start sub_815A7B0
sub_815A7B0: @ 815A7B0
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_80A6838
	ldr r5, =gUnknown_0203841E
	movs r0, 0
	ldrsh r1, [r5, r0]
	adds r0, r4, 0
	bl sub_80A6864
	ldrh r0, [r5, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldr r0, =sub_80A67D8
	str r0, [r4, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl oamt_set_x3A_32
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A7B0

	thumb_func_start sub_815A7EC
sub_815A7EC: @ 815A7EC
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815A84C
	adds r0, r4, 0
	bl sub_80A6838
	ldr r5, =gUnknown_0203841E
	movs r2, 0
	ldrsh r1, [r5, r2]
	adds r0, r4, 0
	bl sub_80A6864
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	bne _0815A840
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0815A830
	ldrh r0, [r5, 0x4]
	b _0815A846
	.pool
_0815A830:
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	negs r0, r0
	strh r0, [r4, 0x30]
	movs r2, 0x6
	ldrsh r0, [r5, r2]
	negs r0, r0
	b _0815A84A
_0815A840:
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	negs r0, r0
_0815A846:
	strh r0, [r4, 0x30]
	ldrh r0, [r5, 0x6]
_0815A84A:
	strh r0, [r4, 0x32]
_0815A84C:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r1, [r4, r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	movs r3, 0xFF
	ldrh r1, [r4, 0x30]
	ldrh r2, [r4, 0x34]
	adds r1, r2
	strh r1, [r4, 0x34]
	ldrh r1, [r4, 0x32]
	ldrh r2, [r4, 0x36]
	adds r1, r2
	strh r1, [r4, 0x36]
	movs r2, 0x34
	ldrsh r1, [r4, r2]
	lsrs r2, r1, 31
	adds r1, r2
	asrs r1, 1
	strh r1, [r4, 0x24]
	ands r0, r3
	movs r1, 0x5
	bl Sin
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	lsrs r2, r1, 31
	adds r1, r2
	asrs r1, 1
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xF0
	bls _0815A8A4
	adds r0, r4, 0
	bl move_anim_8072740
_0815A8A4:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815A7EC

	thumb_func_start sub_815A8AC
sub_815A8AC: @ 815A8AC
	push {lr}
	adds r2, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0815A8C2
	adds r0, r2, 0
	bl move_anim_8072740
_0815A8C2:
	pop {r0}
	bx r0
	thumb_func_end sub_815A8AC

	thumb_func_start sub_815A8C8
sub_815A8C8: @ 815A8C8
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_02038437
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815A8EC
	ldr r1, =gUnknown_0203841E
	movs r0, 0
	b _0815A8F0
	.pool
_0815A8EC:
	ldr r1, =gUnknown_0203841E
	movs r0, 0x1
_0815A8F0:
	strh r0, [r1, 0xE]
	adds r0, r4, 0
	bl move_anim_task_del
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A8C8

	thumb_func_start sub_815A904
sub_815A904: @ 815A904
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_02038404
	ldr r0, [r0]
	cmp r0, 0
	ble _0815A920
	ldr r1, =gUnknown_0203841E
	movs r0, 0
	b _0815A924
	.pool
_0815A920:
	ldr r1, =gUnknown_0203841E
	movs r0, 0x1
_0815A924:
	strh r0, [r1, 0xE]
	adds r0, r2, 0
	bl move_anim_task_del
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A904

	thumb_func_start sub_815A934
sub_815A934: @ 815A934
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r1, =0x00001f3f
	movs r0, 0x4A
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 8
	movs r0, 0
	bl SetGpuRegBits
	ldr r0, =gUnknown_02022E24
	movs r1, 0
	strh r1, [r0]
	ldr r4, =gUnknown_02022E26
	strh r1, [r4]
	movs r0, 0x40
	movs r1, 0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0x44
	bl SetGpuReg
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A6980
	ldrb r1, [r5, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r5, 0x1]
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_815A9A0
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A934

	thumb_func_start sub_815A9A0
sub_815A9A0: @ 815A9A0
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x5
	bhi _0815AA60
	lsls r0, 2
	ldr r1, =_0815A9BC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815A9BC:
	.4byte _0815A9D4
	.4byte _0815A9F2
	.4byte _0815AA12
	.4byte _0815A9F2
	.4byte _0815AA32
	.4byte _0815AA42
_0815A9D4:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0815AA60
	b _0815AA3A
_0815A9F2:
	ldrh r0, [r4, 0x30]
	adds r0, 0x75
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x15
	bne _0815AA60
	movs r0, 0
	strh r0, [r4, 0x32]
	b _0815AA3A
_0815AA12:
	ldrh r0, [r4, 0x30]
	subs r0, 0x75
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x29
	bne _0815AA60
	movs r0, 0
	strh r0, [r4, 0x32]
	b _0815AA3A
_0815AA32:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80082B8
_0815AA3A:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0815AA60
_0815AA42:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0815AA60
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_815AA6C
	str r0, [r4, 0x1C]
_0815AA60:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A9A0

	thumb_func_start sub_815AA6C
sub_815AA6C: @ 815AA6C
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, =0x00003f3f
	movs r0, 0x4A
	bl SetGpuReg
	movs r0, 0
	bl GetGpuReg
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 8
	adds r0, r2, 0
	eors r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl move_anim_8072740
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815AA6C

	thumb_func_start sub_815AAA4
sub_815AAA4: @ 815AAA4
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gUnknown_0203841E
	movs r1, 0x6
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0815AAD0
	ldr r4, =gUnknown_02038436
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
_0815AAD0:
	ldrh r0, [r6]
	ldrh r2, [r5, 0x20]
	adds r0, r2
	movs r3, 0
	strh r0, [r5, 0x20]
	ldrh r0, [r6, 0x2]
	ldrh r4, [r5, 0x22]
	adds r0, r4
	strh r0, [r5, 0x22]
	ldrh r2, [r5, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x10
	ldr r4, =0x000003ff
	adds r0, r4, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x4]
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0815AB2C
	ldrb r1, [r5, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r5, 0x3]
	ldr r0, =0x0000fff4
	strh r0, [r5, 0x24]
	movs r0, 0x2
	b _0815AB32
	.pool
_0815AB2C:
	movs r0, 0xC
	strh r0, [r5, 0x24]
	ldr r0, =0x0000fffe
_0815AB32:
	strh r0, [r5, 0x30]
	ldr r1, =gUnknown_0203841E
	ldrh r0, [r1, 0x8]
	strh r0, [r5, 0x2E]
	movs r2, 0x34
	ldrsh r0, [r5, r2]
	cmp r0, 0xFF
	beq _0815AB46
	ldrh r0, [r1, 0x4]
	strh r0, [r5, 0x34]
_0815AB46:
	ldr r0, =sub_815AB5C
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815AAA4

	thumb_func_start sub_815AB5C
sub_815AB5C: @ 815AB5C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r2, [r4, 0x32]
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815AB9A
	ldrh r0, [r4, 0x30]
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	lsls r0, 16
	cmp r0, 0
	bne _0815ABBA
	adds r0, r2, 0x1
	strh r0, [r4, 0x32]
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815ABBA
	movs r0, 0x40
	negs r0, r0
	bl sub_80A5178
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xDE
	bl sub_80A3808
	b _0815ABBA
_0815AB9A:
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x30]
	subs r0, r1
	strh r0, [r4, 0x24]
	movs r1, 0x24
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bge _0815ABAC
	negs r0, r0
_0815ABAC:
	cmp r0, 0xC
	bne _0815ABBA
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	strh r0, [r4, 0x2E]
	subs r0, r2, 0x1
	strh r0, [r4, 0x32]
_0815ABBA:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815ABC8
	adds r0, r4, 0
	bl move_anim_8072740
_0815ABC8:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_815AB5C

	thumb_func_start sub_815ABD0
sub_815ABD0: @ 815ABD0
	push {lr}
	ldrb r2, [r0, 0x1]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0, 0x1]
	movs r1, 0xFF
	strh r1, [r0, 0x34]
	bl sub_815AAA4
	pop {r0}
	bx r0
	thumb_func_end sub_815ABD0

	thumb_func_start sub_815ABEC
sub_815ABEC: @ 815ABEC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	beq _0815AC40
	ldr r1, =0x00001f3f
	movs r0, 0x48
	bl SetGpuReg
	ldr r1, =gUnknown_02022E28
	ldr r2, =0x000098f0
	adds r0, r2, 0
	strh r0, [r1]
	ldr r1, =gUnknown_02022E2A
	movs r0, 0xA0
	strh r0, [r1]
	ldr r0, =gUnknown_02022E24
	ldrh r1, [r0]
	movs r0, 0x42
	bl SetGpuReg
	ldr r0, =gUnknown_02022E26
	ldrh r1, [r0]
	movs r0, 0x46
	bl SetGpuReg
	b _0815AC70
	.pool
_0815AC40:
	ldr r1, =0x00001f3f
	movs r0, 0x48
	bl SetGpuReg
	ldr r1, =gUnknown_02022E28
	movs r0, 0xF0
	strh r0, [r1]
	ldr r4, =gUnknown_02022E2A
	ldr r1, =0x000078a0
	adds r0, r1, 0
	strh r0, [r4]
	movs r0, 0x42
	movs r1, 0xF0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0x46
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 7
	movs r0, 0
	bl SetGpuRegBits
_0815AC70:
	adds r0, r5, 0
	bl move_anim_task_del
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815ABEC

	thumb_func_start sub_815AC8C
sub_815AC8C: @ 815AC8C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	ldr r0, =gUnknown_02022E28
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E2A
	strh r1, [r0]
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	bne _0815ACB8
	movs r1, 0x80
	lsls r1, 7
	movs r0, 0
	bl ClearGpuRegBits
_0815ACB8:
	adds r0, r4, 0
	bl move_anim_task_del
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815AC8C

	thumb_func_start sub_815ACD0
sub_815ACD0: @ 815ACD0
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gUnknown_0203841E
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0815ACEC
	ldr r4, =gUnknown_02038436
	b _0815ACEE
	.pool
_0815ACEC:
	ldr r4, =gUnknown_02038437
_0815ACEE:
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r6, [r6, 0x2]
	adds r0, r6
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldr r2, =gUnknown_0203841E
	ldrh r0, [r2, 0x4]
	strh r0, [r5, 0x26]
	movs r3, 0
	lsls r0, 16
	asrs r0, 16
	ldrh r4, [r2, 0x6]
	movs r6, 0x6
	ldrsh r1, [r2, r6]
	cmp r0, r1
	ble _0815AD26
	movs r3, 0x1
_0815AD26:
	strh r3, [r5, 0x2E]
	movs r0, 0
	strh r0, [r5, 0x30]
	ldrh r0, [r2, 0x8]
	strh r0, [r5, 0x32]
	ldrh r0, [r2, 0xA]
	strh r0, [r5, 0x34]
	strh r4, [r5, 0x36]
	ldr r0, =sub_815AD4C
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815ACD0

	thumb_func_start sub_815AD4C
sub_815AD4C: @ 815AD4C
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x32]
	ldrh r1, [r2, 0x30]
	adds r0, r1
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r2, 0x30]
	ldr r1, =gSineTable
	movs r3, 0x30
	ldrsh r0, [r2, r3]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r2, 0x24]
	ldrh r0, [r2, 0x34]
	ldrh r3, [r2, 0x26]
	adds r1, r0, r3
	strh r1, [r2, 0x26]
	movs r3, 0x2E
	ldrsh r0, [r2, r3]
	cmp r0, 0
	beq _0815AD98
	lsls r0, r1, 16
	asrs r0, 16
	movs r3, 0x36
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bge _0815ADAA
	adds r0, r2, 0
	bl move_anim_8072740
	b _0815ADAA
	.pool
_0815AD98:
	lsls r0, r1, 16
	asrs r0, 16
	movs r3, 0x36
	ldrsh r1, [r2, r3]
	cmp r0, r1
	ble _0815ADAA
	adds r0, r2, 0
	bl move_anim_8072740
_0815ADAA:
	pop {r0}
	bx r0
	thumb_func_end sub_815AD4C

	thumb_func_start sub_815ADB0
sub_815ADB0: @ 815ADB0
	push {r4-r7,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r5, r1, r0
	ldr r0, =gUnknown_0203841E
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0815ADDC
	ldr r4, =gUnknown_02038436
	b _0815ADDE
	.pool
_0815ADDC:
	ldr r4, =gUnknown_02038437
_0815ADDE:
	ldrb r0, [r4]
	bl sub_80A6190
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r0, [r4]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r6, 0
	adds r1, r0, 0
	adds r1, 0x24
	movs r2, 0
	strh r1, [r5, 0x8]
	strh r1, [r5, 0xA]
	subs r0, 0x21
	strh r0, [r5, 0xC]
	cmp r0, 0
	bge _0815AE08
	strh r2, [r5, 0xC]
_0815AE08:
	ldrh r0, [r5, 0x8]
	strh r0, [r5, 0xE]
	movs r0, 0x8
	strh r0, [r5, 0x10]
	ldr r1, =gUnknown_0203841E
	ldrh r0, [r1, 0x2]
	strh r0, [r5, 0x12]
	strh r2, [r5, 0x14]
	strh r2, [r5, 0x16]
	cmp r7, 0x1
	bne _0815AE30
	ldr r0, =gUnknown_02022E18
	b _0815AE32
	.pool
_0815AE30:
	ldr r0, =gUnknown_02022E1C
_0815AE32:
	ldrh r2, [r0]
	strh r2, [r5, 0x18]
	adds r3, r2, 0
	adds r3, 0xF0
	strh r3, [r5, 0x1A]
	ldrh r0, [r1, 0x4]
	strh r0, [r5, 0x1C]
	movs r4, 0x4
	ldrsh r0, [r1, r4]
	cmp r0, 0
	bne _0815AE54
	strh r3, [r5, 0x1E]
	ldrh r3, [r5, 0x18]
	b _0815AE58
	.pool
_0815AE54:
	strh r2, [r5, 0x1E]
	ldrh r3, [r5, 0x1A]
_0815AE58:
	movs r0, 0
	strh r0, [r5, 0x26]
	ldrh r1, [r5, 0xC]
	lsls r2, r1, 16
	asrs r1, r2, 16
	movs r6, 0xE
	ldrsh r0, [r5, r6]
	cmp r1, r0
	bgt _0815AE8E
	ldr r4, =gUnknown_02038C28
	movs r0, 0xF0
	lsls r0, 3
	adds r0, r4
	mov r12, r0
_0815AE74:
	asrs r2, 16
	lsls r1, r2, 1
	adds r0, r1, r4
	strh r3, [r0]
	add r1, r12
	strh r3, [r1]
	adds r2, 0x1
	lsls r2, 16
	asrs r1, r2, 16
	movs r6, 0xE
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _0815AE74
_0815AE8E:
	cmp r7, 0x1
	bne _0815AEA0
	ldr r0, =0x04000014
	b _0815AEA2
	.pool
_0815AEA0:
	ldr r0, =0x04000018
_0815AEA2:
	str r0, [sp]
	ldr r0, =0xa2600001
	str r0, [sp, 0x4]
	mov r1, sp
	movs r2, 0
	movs r0, 0x1
	strb r0, [r1, 0x8]
	mov r0, sp
	strb r2, [r0, 0x9]
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	bl sub_80BA038
	ldr r0, =sub_815AED8
	str r0, [r5]
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815ADB0

	thumb_func_start sub_815AED8
sub_815AED8: @ 815AED8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	ldrh r0, [r4, 0x8]
	ldrh r1, [r4, 0x12]
	subs r0, r1
	strh r0, [r4, 0x8]
	lsls r0, 16
	asrs r0, 16
	ldrh r2, [r4, 0xC]
	movs r3, 0xC
	ldrsh r1, [r4, r3]
	cmp r0, r1
	bge _0815AF00
	strh r2, [r4, 0x8]
_0815AF00:
	ldrh r1, [r4, 0x10]
	movs r2, 0x10
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _0815AF2C
	ldrh r0, [r4, 0xA]
	ldrh r1, [r4, 0x12]
	subs r0, r1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	ldrh r2, [r4, 0xC]
	movs r3, 0xC
	ldrsh r1, [r4, r3]
	cmp r0, r1
	bge _0815AF30
	strh r2, [r4, 0xA]
	movs r0, 0x1
	strh r0, [r4, 0x26]
	b _0815AF30
	.pool
_0815AF2C:
	subs r0, r1, 0x1
	strh r0, [r4, 0x10]
_0815AF30:
	ldrh r0, [r4, 0x14]
	adds r0, 0x1
	strh r0, [r4, 0x14]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0815AF5C
	movs r0, 0
	strh r0, [r4, 0x14]
	movs r1, 0
	movs r2, 0x16
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _0815AF4E
	movs r1, 0x1
_0815AF4E:
	strh r1, [r4, 0x16]
	cmp r1, 0
	beq _0815AF58
	ldrh r0, [r4, 0x18]
	b _0815AF5A
_0815AF58:
	ldrh r0, [r4, 0x1A]
_0815AF5A:
	strh r0, [r4, 0x20]
_0815AF5C:
	ldrh r1, [r4, 0x8]
	lsls r3, r1, 16
	asrs r1, r3, 16
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bge _0815AF90
	ldr r5, =gUnknown_02038C28
	movs r0, 0xF0
	lsls r0, 3
	adds r6, r5, r0
_0815AF72:
	asrs r3, 16
	lsls r1, r3, 1
	adds r2, r1, r5
	ldrh r0, [r4, 0x20]
	strh r0, [r2]
	adds r1, r6
	ldrh r0, [r4, 0x20]
	strh r0, [r1]
	adds r3, 0x1
	lsls r3, 16
	asrs r1, r3, 16
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r1, r0
	blt _0815AF72
_0815AF90:
	ldrh r1, [r4, 0xA]
	lsls r3, r1, 16
	asrs r1, r3, 16
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bgt _0815AFC4
	ldr r5, =gUnknown_02038C28
	movs r0, 0xF0
	lsls r0, 3
	adds r6, r5, r0
_0815AFA6:
	asrs r3, 16
	lsls r1, r3, 1
	adds r2, r1, r5
	ldrh r0, [r4, 0x1E]
	strh r0, [r2]
	adds r1, r6
	ldrh r0, [r4, 0x1E]
	strh r0, [r1]
	adds r3, 0x1
	lsls r3, 16
	asrs r1, r3, 16
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r1, r0
	ble _0815AFA6
_0815AFC4:
	movs r3, 0x26
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _0815AFE0
	movs r1, 0x1C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0815AFDA
	ldr r1, =gUnknown_02039B28
	movs r0, 0x3
	strb r0, [r1, 0x15]
_0815AFDA:
	adds r0, r7, 0
	bl move_anim_task_del
_0815AFE0:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815AED8

	thumb_func_start sub_815AFF0
sub_815AFF0: @ 815AFF0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	movs r5, 0
	strh r5, [r4, 0x8]
	strh r5, [r4, 0xA]
	ldr r6, =gUnknown_02038436
	ldrb r0, [r6]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0xC]
	ldrb r0, [r6]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0xE]
	movs r0, 0x20
	strh r0, [r4, 0x10]
	ldr r0, =0x0000ffec
	strh r0, [r4, 0x12]
	strh r5, [r4, 0x14]
	movs r0, 0
	bl obj_id_for_side_relative_to_move
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x26]
	ldr r0, =sub_815B054
	str r0, [r4]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815AFF0

	thumb_func_start sub_815B054
sub_815B054: @ 815B054
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r6, r0, r1
	movs r1, 0x8
	ldrsh r0, [r6, r1]
	cmp r0, 0x5
	bls _0815B074
	b _0815B22E
_0815B074:
	lsls r0, 2
	ldr r1, =_0815B088
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815B088:
	.4byte _0815B0A0
	.4byte _0815B160
	.4byte _0815B18E
	.4byte _0815B1A2
	.4byte _0815B1B8
	.4byte _0815B220
_0815B0A0:
	movs r0, 0xC
	ldrsh r2, [r6, r0]
	ldrh r1, [r6, 0xA]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0815B0B6
	movs r1, 0x10
	ldrsh r0, [r6, r1]
	subs r0, r2, r0
	b _0815B0BC
_0815B0B6:
	movs r1, 0x10
	ldrsh r0, [r6, r1]
	adds r0, r2, r0
_0815B0BC:
	lsls r0, 16
	lsrs r1, r0, 16
	ldrh r2, [r6, 0x12]
	ldrh r0, [r6, 0xE]
	adds r2, r0
	ldr r0, =gUnknown_08593114
	lsls r1, 16
	asrs r1, 16
	lsls r2, 16
	asrs r2, 16
	ldrb r4, [r6, 0xA]
	movs r3, 0x6
	subs r3, r4
	lsls r3, 24
	lsrs r3, 24
	bl CreateSprite
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x40
	negs r0, r0
	bl sub_80A5178
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xBA
	bl audio_play_and_stuff
	cmp r4, 0x40
	beq _0815B120
	ldr r5, =gSprites
	lsls r1, r4, 4
	adds r1, r4
	lsls r1, 2
	adds r3, r1, r5
	ldrh r0, [r6, 0xA]
	movs r2, 0x1
	ands r2, r0
	adds r3, 0x3F
	ldrb r4, [r3]
	movs r0, 0x2
	negs r0, r0
	ands r0, r4
	orrs r0, r2
	strb r0, [r3]
	adds r5, 0x1C
	adds r1, r5
	ldr r0, =DummyObjectCallback
	str r0, [r1]
_0815B120:
	ldrh r1, [r6, 0xA]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0815B138
	ldrh r0, [r6, 0x10]
	subs r0, 0x6
	strh r0, [r6, 0x10]
	ldrh r0, [r6, 0x12]
	subs r0, 0x6
	strh r0, [r6, 0x12]
_0815B138:
	ldrh r1, [r6, 0x26]
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_085CE2A0
	adds r0, r6, 0
	bl sub_80A7CFC
	ldrh r0, [r6, 0xA]
	adds r0, 0x1
	strh r0, [r6, 0xA]
	strh r4, [r6, 0x8]
	b _0815B22E
	.pool
_0815B160:
	adds r0, r6, 0
	bl sub_80A7D34
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0815B22E
	movs r2, 0xA
	ldrsh r1, [r6, r2]
	cmp r1, 0x6
	bne _0815B180
	movs r0, 0x8
	strh r0, [r6, 0x14]
	movs r0, 0x3
	strh r0, [r6, 0x8]
	b _0815B22E
_0815B180:
	cmp r1, 0x2
	bgt _0815B186
	movs r0, 0xA
_0815B186:
	strh r0, [r6, 0x14]
	movs r0, 0x2
	strh r0, [r6, 0x8]
	b _0815B22E
_0815B18E:
	ldrh r0, [r6, 0x14]
	movs r2, 0x14
	ldrsh r1, [r6, r2]
	cmp r1, 0
	beq _0815B19E
	subs r0, 0x1
	strh r0, [r6, 0x14]
	b _0815B22E
_0815B19E:
	strh r1, [r6, 0x8]
	b _0815B22E
_0815B1A2:
	ldrh r1, [r6, 0x14]
	movs r2, 0x14
	ldrsh r0, [r6, r2]
	cmp r0, 0
	beq _0815B1B2
	subs r0, r1, 0x1
	strh r0, [r6, 0x14]
	b _0815B22E
_0815B1B2:
	movs r0, 0x4
	strh r0, [r6, 0x8]
	b _0815B22E
_0815B1B8:
	movs r5, 0
	movs r7, 0
	ldr r3, =gSprites
	movs r0, 0x1C
	adds r0, r3
	mov r8, r0
_0815B1C4:
	lsls r0, r5, 4
	adds r0, r5
	lsls r4, r0, 2
	adds r0, r3, 0
	adds r0, 0x14
	adds r0, r4, r0
	ldr r1, [r0]
	ldr r0, =gUnknown_08593114
	cmp r1, r0
	bne _0815B200
	adds r0, r4, r3
	strh r2, [r0, 0x2E]
	movs r1, 0x6
	strh r1, [r0, 0x30]
	movs r1, 0x2
	str r2, [sp]
	str r3, [sp, 0x4]
	bl StartObjectImageAnim
	mov r0, r8
	adds r1, r4, r0
	ldr r0, =sub_815B23C
	str r0, [r1]
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	ldr r2, [sp]
	ldr r3, [sp, 0x4]
	cmp r7, 0x6
	beq _0815B20A
_0815B200:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x3F
	bls _0815B1C4
_0815B20A:
	strh r7, [r6, 0x14]
	movs r0, 0x5
	strh r0, [r6, 0x8]
	b _0815B22E
	.pool
_0815B220:
	movs r1, 0x14
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0815B22E
	adds r0, r2, 0
	bl move_anim_task_del
_0815B22E:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_815B054

	thumb_func_start sub_815B23C
sub_815B23C: @ 815B23C
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0815B270
	ldr r3, =gTasks
	movs r0, 0x30
	ldrsh r1, [r4, r0]
	lsls r1, 1
	movs r0, 0x2E
	ldrsh r2, [r4, r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r3, 0x8
	adds r1, r3
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	adds r0, r4, 0
	bl DestroySprite
_0815B270:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815B23C

	thumb_func_start sub_815B27C
sub_815B27C: @ 815B27C
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0815B290
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A69CC
_0815B290:
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x27
	bgt _0815B2C2
	ldrh r0, [r5, 0x2E]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0815B2B4
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	b _0815B2C0
_0815B2B4:
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
_0815B2C0:
	strb r0, [r2]
_0815B2C2:
	movs r2, 0x2E
	ldrsh r0, [r5, r2]
	cmp r0, 0x1E
	ble _0815B2D8
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_0815B2D8:
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0x3D
	bne _0815B324
	ldr r1, =move_anim_8072740
	adds r0, r5, 0
	bl oamt_set_x3A_32
	ldrh r0, [r5, 0x24]
	ldrh r2, [r5, 0x20]
	adds r0, r2
	movs r1, 0
	strh r0, [r5, 0x20]
	ldrh r0, [r5, 0x26]
	ldrh r2, [r5, 0x22]
	adds r0, r2
	strh r0, [r5, 0x22]
	strh r1, [r5, 0x24]
	strh r1, [r5, 0x26]
	movs r0, 0x14
	strh r0, [r5, 0x2E]
	ldr r4, =gUnknown_02038437
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r5, 0x1C]
_0815B324:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815B27C

	thumb_func_start sub_815B338
sub_815B338: @ 815B338
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
	beq _0815B35C
	cmp r0, 0x1
	beq _0815B37C
	b _0815B38E
	.pool
_0815B35C:
	movs r0, 0
	bl obj_id_for_side_relative_to_move
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_085CE350
	adds r0, r4, 0
	bl sub_80A7CFC
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815B38E
	.pool
_0815B37C:
	adds r0, r4, 0
	bl sub_80A7D34
	lsls r0, 24
	cmp r0, 0
	bne _0815B38E
	adds r0, r5, 0
	bl move_anim_task_del
_0815B38E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815B338

	thumb_func_start sub_815B394
sub_815B394: @ 815B394
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0
	bl obj_id_for_side_relative_to_move
	lsls r0, 24
	lsrs r6, r0, 24
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _0815B3F4
	cmp r0, 0x1
	bgt _0815B3B4
	cmp r0, 0
	beq _0815B3BE
	b _0815B496
_0815B3B4:
	cmp r0, 0x2
	beq _0815B424
	cmp r0, 0x3
	beq _0815B478
	b _0815B496
_0815B3BE:
	ldr r4, =gUnknown_02038436
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	adds r0, r6, 0
	movs r1, 0
	bl sub_80A7270
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r5, 0x30]
	strh r0, [r5, 0x32]
	b _0815B46C
	.pool
_0815B3F4:
	ldrh r0, [r5, 0x30]
	adds r0, 0x60
	strh r0, [r5, 0x30]
	ldrh r0, [r5, 0x32]
	subs r0, 0x1A
	strh r0, [r5, 0x32]
	movs r2, 0x30
	ldrsh r1, [r5, r2]
	movs r0, 0x32
	ldrsh r2, [r5, r0]
	adds r0, r6, 0
	movs r3, 0
	bl obj_id_set_rotscale
	ldrh r0, [r5, 0x34]
	adds r0, 0x1
	strh r0, [r5, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	bne _0815B424
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
_0815B424:
	ldrh r0, [r5, 0x30]
	adds r0, 0x60
	strh r0, [r5, 0x30]
	ldrh r0, [r5, 0x32]
	adds r0, 0x30
	strh r0, [r5, 0x32]
	movs r2, 0x30
	ldrsh r1, [r5, r2]
	movs r0, 0x32
	ldrsh r2, [r5, r0]
	adds r0, r6, 0
	movs r3, 0
	bl obj_id_set_rotscale
	ldrh r0, [r5, 0x34]
	adds r0, 0x1
	strh r0, [r5, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x9
	bne _0815B496
	movs r0, 0
	strh r0, [r5, 0x34]
	ldr r1, =gSprites
	lsls r0, r6, 4
	adds r0, r6
	lsls r0, 2
	adds r0, r1
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	adds r0, r6, 0
	bl sub_80A7344
_0815B46C:
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	b _0815B496
	.pool
_0815B478:
	ldrh r0, [r5, 0x26]
	subs r0, 0x6
	strh r0, [r5, 0x26]
	movs r1, 0x22
	ldrsh r0, [r5, r1]
	movs r2, 0x26
	ldrsh r1, [r5, r2]
	adds r0, r1
	movs r1, 0x20
	negs r1, r1
	cmp r0, r1
	bge _0815B496
	adds r0, r5, 0
	bl move_anim_8072740
_0815B496:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_815B394

	thumb_func_start sub_815B49C
sub_815B49C: @ 815B49C
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0815B4BC
	ldr r0, =0x0000fff0
	b _0815B4C0
	.pool
_0815B4BC:
	movs r0, 0x80
	lsls r0, 1
_0815B4C0:
	strh r0, [r4, 0x20]
	movs r0, 0
	strh r0, [r4, 0x22]
	ldr r0, =sub_815B4D4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815B49C

	thumb_func_start sub_815B4D4
sub_815B4D4: @ 815B4D4
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x48
	strh r0, [r4, 0x2E]
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0815B4F8
	ldrh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 20
	b _0815B500
	.pool
_0815B4F8:
	ldrh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 20
	negs r0, r0
_0815B500:
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x30]
	adds r0, 0x10
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 24
	ldrh r1, [r4, 0x26]
	adds r5, r0, r1
	strh r5, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x3
	bl __modsi3
	lsls r0, 16
	cmp r0, 0
	bne _0815B54C
	ldr r0, =gUnknown_085CE3A0
	ldrh r1, [r4, 0x24]
	ldrh r2, [r4, 0x20]
	adds r1, r2
	lsls r1, 16
	asrs r1, 16
	ldrh r2, [r4, 0x22]
	adds r2, r5
	lsls r2, 16
	asrs r2, 16
	adds r3, r4, 0
	adds r3, 0x43
	ldrb r3, [r3]
	adds r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	bl CreateSpriteAndAnimate
_0815B54C:
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	movs r2, 0x24
	ldrsh r1, [r4, r2]
	adds r0, r1
	adds r0, 0x20
	movs r1, 0x98
	lsls r1, 1
	cmp r0, r1
	bls _0815B566
	adds r0, r4, 0
	bl move_anim_8072740
_0815B566:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815B4D4

	thumb_func_start sub_815B570
sub_815B570: @ 815B570
	push {r4,lr}
	adds r4, r0, 0
	bl Random2
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _0815B58A
	ldrh r2, [r4, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x4
	b _0815B592
_0815B58A:
	ldrh r2, [r4, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x5
_0815B592:
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x4]
	bl Random2
	movs r1, 0x7
	ands r0, r1
	adds r1, r0, 0
	cmp r1, 0x3
	ble _0815B5B4
	negs r0, r1
	lsls r0, 24
	lsrs r0, 24
_0815B5B4:
	lsls r0, 24
	asrs r0, 24
	strh r0, [r4, 0x26]
	ldr r0, =sub_815B5D0
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815B570

	thumb_func_start sub_815B5D0
sub_815B5D0: @ 815B5D0
	push {lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1D
	bgt _0815B612
	ldrh r0, [r3, 0x30]
	adds r0, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	bne _0815B646
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	ldrb r2, [r0]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	movs r0, 0
	b _0815B644
_0815B612:
	movs r1, 0x30
	ldrsh r0, [r3, r1]
	cmp r0, 0x2
	bne _0815B628
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_0815B628:
	movs r1, 0x30
	ldrsh r0, [r3, r1]
	cmp r0, 0x3
	bne _0815B640
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =0x0000ffff
	strh r0, [r3, 0x30]
_0815B640:
	ldrh r0, [r3, 0x30]
	adds r0, 0x1
_0815B644:
	strh r0, [r3, 0x30]
_0815B646:
	movs r1, 0x2E
	ldrsh r0, [r3, r1]
	cmp r0, 0x3C
	ble _0815B654
	adds r0, r3, 0
	bl DestroySprite
_0815B654:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815B5D0

	thumb_func_start sub_815B65C
sub_815B65C: @ 815B65C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815B69C
	movs r0, 0
	bl obj_id_for_side_relative_to_move
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_085CE3B8
	adds r0, r4, 0
	bl sub_80A7CFC
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815B6AE
	.pool
_0815B69C:
	adds r0, r4, 0
	bl sub_80A7D34
	lsls r0, 24
	cmp r0, 0
	bne _0815B6AE
	adds r0, r5, 0
	bl move_anim_task_del
_0815B6AE:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815B65C

	thumb_func_start sub_815B6B4
sub_815B6B4: @ 815B6B4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815B6F4
	movs r0, 0
	bl obj_id_for_side_relative_to_move
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_085CE3E0
	adds r0, r4, 0
	bl sub_80A7CFC
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815B706
	.pool
_0815B6F4:
	adds r0, r4, 0
	bl sub_80A7D34
	lsls r0, 24
	cmp r0, 0
	bne _0815B706
	adds r0, r5, 0
	bl move_anim_task_del
_0815B706:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815B6B4

	thumb_func_start sub_815B70C
sub_815B70C: @ 815B70C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0815B71E
	cmp r0, 0x1
	beq _0815B748
	b _0815B770
_0815B71E:
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A69CC
	movs r0, 0x90
	lsls r0, 4
	strh r0, [r4, 0x30]
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0815B770
	.pool
_0815B748:
	ldrh r2, [r4, 0x30]
	lsls r1, r2, 16
	asrs r1, 24
	ldrh r0, [r4, 0x26]
	subs r0, r1
	strh r0, [r4, 0x26]
	subs r2, 0x60
	strh r2, [r4, 0x30]
	movs r2, 0x22
	ldrsh r0, [r4, r2]
	movs r2, 0x26
	ldrsh r1, [r4, r2]
	adds r0, r1
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	cmp r0, r1
	ble _0815B770
	adds r0, r4, 0
	bl move_anim_8072740
_0815B770:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_815B70C

	thumb_func_start sub_815B778
sub_815B778: @ 815B778
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815B7B8
	movs r0, 0
	bl obj_id_for_side_relative_to_move
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_085CE430
	adds r0, r4, 0
	bl sub_80A7CFC
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815B7CA
	.pool
_0815B7B8:
	adds r0, r4, 0
	bl sub_80A7D34
	lsls r0, 24
	cmp r0, 0
	bne _0815B7CA
	adds r0, r5, 0
	bl move_anim_task_del
_0815B7CA:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815B778

	thumb_func_start sub_815B7D0
sub_815B7D0: @ 815B7D0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r3, r1, 0
	cmp r0, 0x4
	bls _0815B7F6
	b _0815BAFC
_0815B7F6:
	lsls r0, 2
	ldr r1, =_0815B808
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815B808:
	.4byte _0815B81C
	.4byte _0815B86C
	.4byte _0815B8A8
	.4byte _0815BA44
	.4byte _0815BA82
_0815B81C:
	movs r0, 0x4C
	movs r1, 0
	bl SetGpuReg
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815B844
	movs r0, 0x1
	movs r1, 0x2
	movs r2, 0x1
	bl lcd_bg_operations
	b _0815B84E
	.pool
_0815B844:
	movs r0, 0x2
	movs r1, 0x2
	movs r2, 0x1
	bl lcd_bg_operations
_0815B84E:
	ldr r0, =gTasks
	mov r6, r8
	lsls r1, r6, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	ldr r0, =gUnknown_0203841E
	ldrh r0, [r0]
	strh r0, [r1, 0x1C]
	b _0815BA26
	.pool
_0815B86C:
	mov r1, r8
	lsls r0, r1, 2
	add r0, r8
	lsls r0, 3
	adds r4, r0, r3
	ldrh r0, [r4, 0xC]
	adds r1, r0, 0x1
	strh r1, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bgt _0815B886
	b _0815BAFC
_0815B886:
	movs r0, 0
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	ldrh r5, [r4, 0xA]
	lsls r1, r5, 4
	orrs r1, r5
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x4C
	bl SetGpuReg
	cmp r5, 0xF
	beq _0815B8A6
	b _0815BAFC
_0815B8A6:
	b _0815BA7A
_0815B8A8:
	ldr r5, =gUnknown_02038436
	ldrb r0, [r5]
	ldr r1, =gUnknown_02038437
	ldrb r1, [r1]
	mov r2, r8
	lsls r4, r2, 2
	adds r2, r4, r2
	lsls r2, 3
	adds r2, r3
	ldrb r2, [r2, 0x1C]
	bl sub_805E448
	ldrb r1, [r5]
	mov r0, sp
	bl sub_80A6BFC
	bl sub_80A4DF0
	lsls r0, 24
	mov r9, r4
	cmp r0, 0
	beq _0815B8E0
	movs r1, 0
	b _0815B8EA
	.pool
_0815B8E0:
	ldrb r0, [r5]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r1, r0, 24
_0815B8EA:
	ldr r0, =gUnknown_020244D4
	ldr r2, [r0]
	lsls r0, r1, 2
	adds r2, 0x4
	adds r2, r0
	ldr r1, =gUnknown_020244E4
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r1, 11
	ldr r0, [r2]
	adds r0, r1
	ldr r1, [sp]
	ldr r2, =0x04000200
	bl CpuSet
	ldr r1, [sp]
	movs r2, 0x80
	lsls r2, 4
	mov r0, sp
	ldrh r3, [r0, 0xA]
	movs r0, 0x1
	bl LoadBgTiles
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	beq _0815BA1C
	ldr r5, =gUnknown_02039F34
	ldr r0, [r5]
	ldr r0, [r0, 0x18]
	ldrh r0, [r0]
	bl sub_80DB2A8
	adds r4, r0, 0
	ldr r0, [r5]
	ldr r0, [r0, 0x18]
	ldrh r0, [r0, 0x2]
	bl sub_80DB2A8
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	beq _0815B99C
	ldr r6, [sp, 0x4]
	movs r5, 0
	movs r0, 0x7
	mov r12, r0
	movs r7, 0
_0815B950:
	movs r4, 0
	adds r3, r7, r6
	mov r1, r12
	lsls r0, r1, 1
	adds r2, r0, r6
_0815B95A:
	ldrh r1, [r3]
	ldrh r0, [r2]
	strh r0, [r3]
	strh r1, [r2]
	adds r3, 0x2
	subs r2, 0x2
	adds r4, 0x1
	cmp r4, 0x3
	ble _0815B95A
	movs r2, 0x20
	add r12, r2
	adds r7, 0x40
	adds r5, 0x1
	cmp r5, 0x7
	ble _0815B950
	movs r5, 0
	movs r0, 0x80
	lsls r0, 3
	adds r3, r0, 0
_0815B980:
	adds r2, r5, 0x1
	lsls r0, r5, 6
	adds r1, r0, r6
	movs r4, 0x7
_0815B988:
	ldrh r0, [r1]
	eors r0, r3
	strh r0, [r1]
	adds r1, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _0815B988
	adds r5, r2, 0
	cmp r5, 0x7
	ble _0815B980
_0815B99C:
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldrh r0, [r0, 0x2]
	bl sub_80DB2A8
	lsls r0, 24
	cmp r0, 0
	beq _0815B9EC
	ldr r3, =gSprites
	ldr r4, =gBankSpriteIds
	ldr r2, =gUnknown_02038436
	ldrb r0, [r2]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r3, 0
	adds r1, 0x10
	adds r0, r1
	ldr r1, =gUnknown_082FF6C0
	b _0815BA06
	.pool
_0815B9EC:
	ldr r3, =gSprites
	ldr r4, =gBankSpriteIds
	ldr r2, =gUnknown_02038436
	ldrb r0, [r2]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r3, 0
	adds r1, 0x10
	adds r0, r1
	ldr r1, =gUnknown_082FF694
_0815BA06:
	str r1, [r0]
	ldrb r0, [r2]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0
	bl StartObjectRotScalAnim
_0815BA1C:
	ldr r0, =gTasks
	mov r1, r9
	add r1, r8
	lsls r1, 3
	adds r1, r0
_0815BA26:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0815BAFC
	.pool
_0815BA44:
	mov r1, r8
	lsls r0, r1, 2
	add r0, r8
	lsls r0, 3
	adds r4, r0, r3
	ldrh r0, [r4, 0xC]
	adds r1, r0, 0x1
	strh r1, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0815BAFC
	movs r0, 0
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
	strh r0, [r4, 0xA]
	ldrh r5, [r4, 0xA]
	lsls r1, r5, 4
	orrs r1, r5
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x4C
	bl SetGpuReg
	cmp r5, 0
	bne _0815BAFC
_0815BA7A:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815BAFC
_0815BA82:
	movs r0, 0x4C
	movs r1, 0
	bl SetGpuReg
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815BAAC
	movs r0, 0x1
	movs r1, 0x2
	movs r2, 0
	bl lcd_bg_operations
	b _0815BAB6
	.pool
_0815BAAC:
	movs r0, 0x2
	movs r1, 0x2
	movs r2, 0
	bl lcd_bg_operations
_0815BAB6:
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	bne _0815BAF6
	ldr r4, =gUnknown_02038436
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815BAF6
	ldr r0, =gTasks
	mov r2, r8
	lsls r1, r2, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r6, 0x1C
	ldrsh r0, [r1, r6]
	cmp r0, 0
	bne _0815BAF6
	ldrb r0, [r4]
	ldr r1, =gUnknown_020244D0
	ldr r1, [r1]
	ldr r2, [r1]
	lsls r1, r0, 2
	adds r1, r2
	ldrh r1, [r1, 0x2]
	bl sub_805EE54
_0815BAF6:
	mov r0, r8
	bl move_anim_task_del
_0815BAFC:
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815B7D0

	thumb_func_start c3_80DFBE4
c3_80DFBE4: @ 815BB18
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gUnknown_0203841E
	ldr r3, =gSprites
	ldr r2, =gBankSpriteIds
	ldr r1, =gUnknown_02038436
	ldrb r1, [r1]
	adds r1, r2
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r3
	adds r1, 0x3E
	ldrb r1, [r1]
	lsls r1, 29
	lsrs r1, 31
	strh r1, [r4, 0xE]
	bl move_anim_task_del
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c3_80DFBE4

	thumb_func_start sub_815BB58
sub_815BB58: @ 815BB58
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	ldr r1, =gUnknown_02038437
	ldrb r1, [r1]
	movs r2, 0x1
	bl sub_805E448
	adds r0, r4, 0
	bl move_anim_task_del
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815BB58

	thumb_func_start sub_815BB84
sub_815BB84: @ 815BB84
	push {r4,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r2, r1, 0
	cmp r0, 0x4
	bls _0815BBA2
	b _0815BDF2
_0815BBA2:
	lsls r0, 2
	ldr r1, =_0815BBB4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815BBB4:
	.4byte _0815BBC8
	.4byte _0815BCB8
	.4byte _0815BD08
	.4byte _0815BD72
	.4byte _0815BDA6
_0815BBC8:
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl lcd_bg_operations
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	bne _0815BC02
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0x1
	bl lcd_bg_operations
_0815BC02:
	mov r0, sp
	bl sub_80A6B30
	ldr r1, =gUnknown_08C2A6EC
	mov r0, sp
	movs r2, 0
	bl sub_80A6D60
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	beq _0815BC34
	ldr r1, =gUnknown_02022E18
	ldr r3, =0x0000ffc8
	b _0815BC5C
	.pool
_0815BC34:
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0815BC58
	ldr r1, =gUnknown_02022E18
	ldr r2, =0x0000ff79
	adds r0, r2, 0
	b _0815BC5E
	.pool
_0815BC58:
	ldr r1, =gUnknown_02022E18
	ldr r3, =0x0000fff6
_0815BC5C:
	adds r0, r3, 0
_0815BC5E:
	strh r0, [r1]
	ldr r1, =gUnknown_02022E1A
	movs r0, 0
	strh r0, [r1]
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_08C2A634
	mov r2, sp
	ldrh r2, [r2, 0xA]
	bl sub_80A6CC0
	ldr r0, =gUnknown_08C2A6D4
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 4
	movs r2, 0x20
	bl LoadCompressedPalette
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =gUnknown_02022E18
	ldrh r0, [r0]
	strh r0, [r1, 0x1C]
	ldr r0, =gUnknown_02022E1A
	ldrh r0, [r0]
	strh r0, [r1, 0x1E]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	b _0815BD8E
	.pool
_0815BCB8:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r4, r0, r2
	ldrh r0, [r4, 0x10]
	adds r1, r0, 0x1
	strh r1, [r4, 0x10]
	lsls r0, 16
	cmp r0, 0
	bgt _0815BCCE
	b _0815BDF2
_0815BCCE:
	movs r0, 0
	strh r0, [r4, 0x10]
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	ble _0815BCE4
	movs r0, 0xC
	strh r0, [r4, 0xA]
_0815BCE4:
	ldrh r0, [r4, 0xA]
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0xC
	bne _0815BDF2
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815BDF2
_0815BD08:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r4, r0, r2
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	cmp r0, 0
	bge _0815BD20
	movs r0, 0
	strh r0, [r4, 0xA]
_0815BD20:
	ldrh r0, [r4, 0xA]
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _0815BDF2
	ldr r2, =gUnknown_02022E18
	ldr r1, =gUnknown_085CE460
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrh r1, [r4, 0x1C]
	adds r0, r1
	strh r0, [r2]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _0815BD6C
	strh r0, [r4, 0x8]
	b _0815BDF2
	.pool
_0815BD6C:
	movs r0, 0x3
	strh r0, [r4, 0x8]
	b _0815BDF2
_0815BD72:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r2
	ldrh r0, [r1, 0xE]
	adds r0, 0x1
	strh r0, [r1, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _0815BDF2
	movs r0, 0
	strh r0, [r1, 0xE]
	movs r0, 0x1
_0815BD8E:
	strh r0, [r1, 0x8]
	movs r0, 0x40
	negs r0, r0
	bl sub_80A5178
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xE4
	bl audio_play_and_stuff
	b _0815BDF2
_0815BDA6:
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldrb r0, [r0, 0x9]
	bl sub_80A6C68
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	bne _0815BDC8
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	bl lcd_bg_operations
_0815BDC8:
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
	ldr r0, =gUnknown_02022E18
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1A
	strh r1, [r0]
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl move_anim_task_del
_0815BDF2:
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815BB84

	thumb_func_start sub_815BE04
sub_815BE04: @ 815BE04
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r7, r0, 0
	bl Random2
	lsls r0, 16
	movs r1, 0xFC
	lsls r1, 14
	ands r1, r0
	lsrs r5, r1, 16
	adds r1, r5, 0
	cmp r1, 0x1F
	ble _0815BE2E
	movs r0, 0x20
	subs r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
_0815BE2E:
	ldr r4, =gUnknown_02038436
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, r5
	strh r0, [r7, 0x20]
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x20
	strh r0, [r7, 0x22]
	ldr r1, =gUnknown_0203841E
	ldrh r0, [r1]
	strh r0, [r7, 0x30]
	ldrh r0, [r1, 0x2]
	strh r0, [r7, 0x32]
	ldr r4, =gUnknown_085CE48C
	movs r0, 0x20
	ldrsh r1, [r7, r0]
	movs r0, 0x22
	ldrsh r2, [r7, r0]
	adds r5, r7, 0
	adds r5, 0x43
	ldrb r3, [r5]
	adds r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	adds r0, r4, 0
	bl CreateSprite
	mov r9, r0
	mov r1, r9
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	movs r0, 0x20
	ldrsh r1, [r7, r0]
	movs r0, 0x22
	ldrsh r2, [r7, r0]
	ldrb r3, [r5]
	adds r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	adds r0, r4, 0
	bl CreateSprite
	mov r8, r0
	mov r1, r8
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	mov r0, r9
	lsls r2, r0, 4
	add r2, r9
	lsls r2, 2
	ldr r1, =gSprites
	mov r10, r1
	adds r5, r2, r1
	adds r0, r5, 0
	movs r1, 0x1
	str r2, [sp]
	bl StartObjectImageAnim
	mov r0, r8
	lsls r6, r0, 4
	add r6, r8
	lsls r6, 2
	mov r1, r10
	adds r4, r6, r1
	adds r0, r4, 0
	movs r1, 0x2
	bl StartObjectImageAnim
	ldr r1, =gUnknown_0203841E
	ldrh r0, [r1]
	strh r0, [r5, 0x30]
	ldrh r0, [r1, 0x2]
	strh r0, [r5, 0x32]
	ldrh r0, [r1]
	strh r0, [r4, 0x30]
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0x32]
	ldr r0, =0x0000ffff
	strh r0, [r5, 0x3C]
	movs r0, 0x1
	negs r0, r0
	strh r0, [r4, 0x3C]
	adds r5, 0x3E
	ldrb r0, [r5]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r5]
	adds r4, 0x3E
	ldrb r0, [r4]
	orrs r0, r1
	strb r0, [r4]
	movs r0, 0x1C
	add r10, r0
	ldr r2, [sp]
	add r2, r10
	ldr r0, =sub_815C050
	str r0, [r2]
	add r6, r10
	str r0, [r6]
	mov r1, r9
	strh r1, [r7, 0x3A]
	mov r0, r8
	strh r0, [r7, 0x3C]
	ldr r0, =sub_815BF44
	str r0, [r7, 0x1C]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815BE04

	thumb_func_start sub_815BF44
sub_815BF44: @ 815BF44
	push {lr}
	adds r3, r0, 0
	ldrh r2, [r3, 0x32]
	ldrh r0, [r3, 0x34]
	adds r2, r0
	lsls r0, r2, 16
	asrs r0, 24
	ldrh r1, [r3, 0x26]
	subs r1, r0
	strh r1, [r3, 0x26]
	movs r0, 0xFF
	ands r2, r0
	strh r2, [r3, 0x34]
	movs r2, 0x36
	ldrsh r0, [r3, r2]
	cmp r0, 0
	bne _0815BF92
	lsls r0, r1, 16
	asrs r0, 16
	movs r1, 0x8
	negs r1, r1
	cmp r0, r1
	bge _0815BF92
	ldr r2, =gSprites
	movs r0, 0x3A
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	ldrh r0, [r3, 0x36]
	adds r0, 0x1
	strh r0, [r3, 0x36]
_0815BF92:
	movs r1, 0x36
	ldrsh r0, [r3, r1]
	cmp r0, 0x1
	bne _0815BFC6
	movs r2, 0x26
	ldrsh r1, [r3, r2]
	movs r0, 0x10
	negs r0, r0
	cmp r1, r0
	bge _0815BFC6
	ldr r2, =gSprites
	movs r0, 0x3C
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	ldrh r0, [r3, 0x36]
	adds r0, 0x1
	strh r0, [r3, 0x36]
_0815BFC6:
	ldrh r0, [r3, 0x30]
	subs r0, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0815BFE8
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_815BFF4
	str r0, [r3, 0x1C]
_0815BFE8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815BF44

	thumb_func_start sub_815BFF4
sub_815BFF4: @ 815BFF4
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r5, =gSprites
	movs r0, 0x3A
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r3, r0, 2
	adds r6, r5, 0
	adds r6, 0x1C
	adds r0, r3, r6
	ldr r2, [r0]
	ldr r0, =DummyObjectCallback
	cmp r2, r0
	bne _0815C040
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldr r0, [r1]
	cmp r0, r2
	bne _0815C040
	adds r0, r3, r5
	bl DestroySprite
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	bl DestroySprite
	adds r0, r4, 0
	bl move_anim_8072740
_0815C040:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815BFF4

	thumb_func_start sub_815C050
sub_815C050: @ 815C050
	push {lr}
	adds r3, r0, 0
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _0815C09C
	ldrh r2, [r3, 0x32]
	ldrh r1, [r3, 0x34]
	adds r2, r1
	lsls r1, r2, 16
	asrs r1, 24
	ldrh r0, [r3, 0x26]
	subs r0, r1
	strh r0, [r3, 0x26]
	movs r0, 0xFF
	ands r2, r0
	strh r2, [r3, 0x34]
	ldrh r0, [r3, 0x30]
	subs r0, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0815C09C
	mov r1, r12
	ldrb r0, [r1]
	movs r1, 0x4
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	ldr r0, =DummyObjectCallback
	str r0, [r3, 0x1C]
_0815C09C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815C050

	thumb_func_start sub_815C0A4
sub_815C0A4: @ 815C0A4
	push {r4-r6,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r4, r1, 0
	cmp r0, 0x5
	bls _0815C0C2
	b _0815C396
_0815C0C2:
	lsls r0, 2
	ldr r1, =_0815C0D4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815C0D4:
	.4byte _0815C0EC
	.4byte _0815C224
	.4byte _0815C2AC
	.4byte _0815C2E2
	.4byte _0815C310
	.4byte _0815C34A
_0815C0EC:
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x00000d03
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl lcd_bg_operations
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	bne _0815C124
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0x1
	bl lcd_bg_operations
_0815C124:
	mov r0, sp
	bl sub_80A6B30
	ldr r1, =gUnknown_08C2A6EC
	mov r0, sp
	movs r2, 0
	bl sub_80A6D60
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	beq _0815C15C
	ldr r1, =gUnknown_02022E18
	ldr r3, =0x0000ffc8
	adds r0, r3, 0
	b _0815C1CA
	.pool
_0815C15C:
	ldr r0, =gUnknown_02038437
	ldrb r0, [r0]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r4, r0, 24
	bl battle_type_is_double
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815C1B4
	cmp r4, 0x1
	bne _0815C180
	ldr r1, =gUnknown_02022E18
	ldr r2, =0x0000ff65
	adds r0, r2, 0
	strh r0, [r1]
_0815C180:
	cmp r4, 0x3
	bne _0815C18C
	ldr r1, =gUnknown_02022E18
	ldr r3, =0x0000ff8d
	adds r0, r3, 0
	strh r0, [r1]
_0815C18C:
	cmp r4, 0
	bne _0815C196
	ldr r1, =gUnknown_02022E18
	movs r0, 0xE
	strh r0, [r1]
_0815C196:
	cmp r4, 0x2
	bne _0815C1CC
	ldr r1, =gUnknown_02022E18
	ldr r2, =0x0000ffec
	b _0815C1C8
	.pool
_0815C1B4:
	cmp r4, 0x1
	bne _0815C1C0
	ldr r1, =gUnknown_02022E18
	ldr r3, =0x0000ff79
	adds r0, r3, 0
	strh r0, [r1]
_0815C1C0:
	cmp r4, 0
	bne _0815C1CC
	ldr r1, =gUnknown_02022E18
	ldr r2, =0x0000fff6
_0815C1C8:
	adds r0, r2, 0
_0815C1CA:
	strh r0, [r1]
_0815C1CC:
	ldr r1, =gUnknown_02022E1A
	movs r0, 0
	strh r0, [r1]
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_08C2A634
	mov r2, sp
	ldrh r2, [r2, 0xA]
	bl sub_80A6CC0
	ldr r0, =gUnknown_08C2A6D4
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 4
	movs r2, 0x20
	bl LoadCompressedPalette
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =gUnknown_02022E18
	ldrh r0, [r0]
	strh r0, [r1, 0x1C]
	ldr r0, =gUnknown_02022E1A
	ldrh r0, [r0]
	strh r0, [r1, 0x1E]
	b _0815C2A4
	.pool
_0815C224:
	ldr r1, =gTasks
	lsls r4, r6, 2
	adds r0, r4, r6
	lsls r0, 3
	adds r5, r0, r1
	movs r0, 0
	strh r0, [r5, 0xE]
	ldr r0, =gUnknown_02038437
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815C268
	ldr r2, =gUnknown_02022E18
	ldr r1, =gUnknown_085CE4A4
	movs r3, 0xC
	ldrsh r0, [r5, r3]
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrh r5, [r5, 0x1C]
	adds r0, r5
	b _0815C27A
	.pool
_0815C268:
	ldr r2, =gUnknown_02022E18
	ldr r1, =gUnknown_085CE4A4
	movs r3, 0xC
	ldrsh r0, [r5, r3]
	adds r0, r1
	movs r1, 0
	ldrsb r1, [r0, r1]
	ldrh r0, [r5, 0x1C]
	subs r0, r1
_0815C27A:
	strh r0, [r2]
	ldr r0, =gTasks
	adds r1, r4, r6
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0xC]
	adds r0, 0x1
	strh r0, [r1, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	bne _0815C2A4
	strh r0, [r1, 0x8]
	b _0815C396
	.pool
_0815C2A4:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0815C396
_0815C2AC:
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r4, r0, r4
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bgt _0815C2C6
	movs r0, 0x5
	strh r0, [r4, 0xA]
_0815C2C6:
	ldrh r1, [r4, 0xA]
	lsls r1, 8
	movs r0, 0x3
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0x5
	bne _0815C396
	b _0815C302
_0815C2E2:
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r4, r0, r4
	ldrh r1, [r4, 0xE]
	adds r1, 0x1
	strh r1, [r4, 0xE]
	lsls r1, 16
	asrs r1, 16
	ldr r2, =gUnknown_085CE4A8
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	adds r0, r2
	ldrb r0, [r0]
	cmp r1, r0
	ble _0815C396
_0815C302:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815C396
	.pool
_0815C310:
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r4, r0, r4
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	ble _0815C32A
	movs r0, 0xD
	strh r0, [r4, 0xA]
_0815C32A:
	ldrh r1, [r4, 0xA]
	lsls r1, 8
	movs r0, 0x3
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0xD
	bne _0815C396
	movs r0, 0x1
	strh r0, [r4, 0x8]
	b _0815C396
_0815C34A:
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldrb r0, [r0, 0x9]
	bl sub_80A6C68
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	bne _0815C36C
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	bl lcd_bg_operations
_0815C36C:
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
	ldr r0, =gUnknown_02022E18
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1A
	strh r1, [r0]
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r6, 0
	bl move_anim_task_del
_0815C396:
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815C0A4

	thumb_func_start sub_815C3A8
sub_815C3A8: @ 815C3A8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815C3E8
	movs r0, 0
	bl obj_id_for_side_relative_to_move
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_085CE4B0
	adds r0, r4, 0
	bl sub_80A7CFC
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815C3FA
	.pool
_0815C3E8:
	adds r0, r4, 0
	bl sub_80A7D34
	lsls r0, 24
	cmp r0, 0
	bne _0815C3FA
	adds r0, r5, 0
	bl move_anim_task_del
_0815C3FA:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815C3A8

	thumb_func_start sub_815C400
sub_815C400: @ 815C400
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r1, [r4, r2]
	cmp r1, 0
	bne _0815C41E
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A69CC
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0815C472
_0815C41E:
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	cmp r1, 0x14
	ble _0815C472
	ldrh r0, [r4, 0x30]
	adds r0, 0xA0
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x32]
	adds r0, 0x80
	strh r0, [r4, 0x32]
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0815C450
	ldrh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 24
	negs r0, r0
	b _0815C456
	.pool
_0815C450:
	ldrh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 24
_0815C456:
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 24
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x40
	ble _0815C472
	adds r0, r4, 0
	bl move_anim_8072740
_0815C472:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_815C400

	thumb_func_start sub_815C478
sub_815C478: @ 815C478
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	ldr r5, =gUnknown_0203841E
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0815C4A4
	adds r0, r2, 0
	bl move_anim_task_del
	b _0815C538
	.pool
_0815C4A4:
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bge _0815C4B0
	movs r0, 0
	strh r0, [r5, 0x4]
_0815C4B0:
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	cmp r0, 0x2
	ble _0815C4BC
	movs r0, 0x2
	strh r0, [r5, 0x4]
_0815C4BC:
	movs r0, 0
	strh r0, [r4, 0x8]
	strh r0, [r4, 0xA]
	strh r0, [r4, 0xC]
	movs r0, 0x4
	ldrsh r1, [r5, r0]
	lsls r1, 1
	movs r0, 0x8
	subs r0, r1
	strh r0, [r4, 0xE]
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	lsls r0, 7
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	strh r0, [r4, 0x10]
	ldrh r0, [r5, 0x4]
	adds r0, 0x2
	strh r0, [r4, 0x12]
	ldrh r0, [r5, 0x2]
	subs r0, 0x1
	strh r0, [r4, 0x14]
	ldrb r0, [r5]
	bl obj_id_for_side_relative_to_move
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x26]
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0815C508
	ldr r0, =gUnknown_02038436
	b _0815C50A
	.pool
_0815C508:
	ldr r0, =gUnknown_02038437
_0815C50A:
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815C528
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	negs r0, r0
	strh r0, [r4, 0x10]
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	negs r0, r0
	strh r0, [r4, 0x12]
_0815C528:
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_80A7270
	ldr r0, =sub_815C548
	str r0, [r4]
_0815C538:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815C478

	thumb_func_start sub_815C548
sub_815C548: @ 815C548
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r6, [r4, r0]
	cmp r6, 0x1
	beq _0815C5D0
	cmp r6, 0x1
	bgt _0815C570
	cmp r6, 0
	beq _0815C57C
	b _0815C6A8
	.pool
_0815C570:
	cmp r6, 0x2
	beq _0815C628
	cmp r6, 0x3
	bne _0815C57A
	b _0815C698
_0815C57A:
	b _0815C6A8
_0815C57C:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r4, 0x12]
	ldrh r2, [r0, 0x24]
	adds r1, r2
	strh r1, [r0, 0x24]
	ldrh r0, [r4, 0xC]
	ldrh r1, [r4, 0x10]
	subs r0, r1
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0xC]
	adds r1, r2, 0
	bl obj_id_set_rotscale
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A73A0
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0xE
	ldrsh r1, [r4, r2]
	cmp r0, r1
	blt _0815C6A8
	strh r6, [r4, 0xA]
	b _0815C690
	.pool
_0815C5D0:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x24]
	ldrh r2, [r4, 0x12]
	subs r1, r2
	strh r1, [r0, 0x24]
	ldrh r0, [r4, 0x10]
	ldrh r1, [r4, 0xC]
	adds r0, r1
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0xC]
	adds r1, r2, 0
	bl obj_id_set_rotscale
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A73A0
	ldrh r1, [r4, 0xA]
	adds r1, 0x1
	strh r1, [r4, 0xA]
	lsls r1, 16
	asrs r1, 16
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	lsls r0, 1
	cmp r1, r0
	blt _0815C6A8
	movs r0, 0
	strh r0, [r4, 0xA]
	b _0815C690
	.pool
_0815C628:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r4, 0x12]
	ldrh r2, [r0, 0x24]
	adds r1, r2
	movs r5, 0
	strh r1, [r0, 0x24]
	ldrh r0, [r4, 0xC]
	ldrh r1, [r4, 0x10]
	subs r0, r1
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0xC]
	adds r1, r2, 0
	bl obj_id_set_rotscale
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A73A0
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0xE
	ldrsh r1, [r4, r2]
	cmp r0, r1
	blt _0815C6A8
	ldrh r1, [r4, 0x14]
	movs r2, 0x14
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _0815C690
	subs r0, r1, 0x1
	strh r0, [r4, 0x14]
	strh r5, [r4, 0xA]
	strh r5, [r4, 0x8]
	b _0815C6A8
	.pool
_0815C690:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815C6A8
_0815C698:
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A7344
	adds r0, r5, 0
	bl move_anim_task_del
_0815C6A8:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_815C548

	thumb_func_start sub_815C6B0
sub_815C6B0: @ 815C6B0
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0815C6D4
	strh r0, [r4, 0x20]
	ldr r1, =gUnknown_0203841E
	ldrh r0, [r1]
	b _0815C6DE
	.pool
_0815C6D4:
	movs r0, 0xF0
	strh r0, [r4, 0x20]
	ldr r1, =gUnknown_0203841E
	ldrh r0, [r1]
	subs r0, 0x1E
_0815C6DE:
	strh r0, [r4, 0x22]
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x32]
	ldrb r1, [r1, 0x2]
	adds r0, r4, 0
	bl StartObjectImageAnim
	ldr r0, =sub_815C700
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815C6B0

	thumb_func_start sub_815C700
sub_815C700: @ 815C700
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x3
	strh r0, [r4, 0x2E]
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0815C744
	ldrh r1, [r4, 0x20]
	adds r1, 0x5
	strh r1, [r4, 0x20]
	ldrh r0, [r4, 0x22]
	subs r0, 0x1
	strh r0, [r4, 0x22]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0xF0
	ble _0815C732
	adds r0, r4, 0
	bl move_anim_8072740
_0815C732:
	ldrh r1, [r4, 0x2E]
	movs r0, 0xFF
	ands r0, r1
	movs r1, 0x10
	bl Sin
	b _0815C768
	.pool
_0815C744:
	ldrh r1, [r4, 0x20]
	subs r1, 0x5
	strh r1, [r4, 0x20]
	ldrh r0, [r4, 0x22]
	adds r0, 0x1
	strh r0, [r4, 0x22]
	lsls r1, 16
	cmp r1, 0
	bge _0815C75C
	adds r0, r4, 0
	bl move_anim_8072740
_0815C75C:
	ldrh r1, [r4, 0x2E]
	movs r0, 0xFF
	ands r0, r1
	movs r1, 0x10
	bl Cos
_0815C768:
	strh r0, [r4, 0x26]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_815C700

	thumb_func_start sub_815C770
sub_815C770: @ 815C770
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	movs r0, 0
	strh r0, [r4, 0x8]
	strh r0, [r4, 0xA]
	strh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
	movs r0, 0x20
	strh r0, [r4, 0x20]
	movs r0, 0x40
	strh r0, [r4, 0x22]
	movs r0, 0x80
	lsls r0, 4
	strh r0, [r4, 0x24]
	ldr r0, =gUnknown_0203841E
	ldrb r0, [r0]
	bl obj_id_for_side_relative_to_move
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x26]
	movs r1, 0
	bl sub_80A7270
	ldr r0, =sub_815C7C4
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815C770

	thumb_func_start sub_815C7C4
sub_815C7C4: @ 815C7C4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r7, r0, r1
	movs r1, 0x8
	ldrsh r0, [r7, r1]
	mov r8, r0
	cmp r0, 0x1
	beq _0815C860
	cmp r0, 0x1
	bgt _0815C7F4
	cmp r0, 0
	beq _0815C7FC
	b _0815C8DA
	.pool
_0815C7F4:
	mov r2, r8
	cmp r2, 0x2
	beq _0815C8C8
	b _0815C8DA
_0815C7FC:
	movs r3, 0x80
	lsls r3, 2
	adds r0, r3, 0
	ldrh r1, [r7, 0xC]
	adds r2, r0, r1
	strh r2, [r7, 0xC]
	lsls r0, r2, 16
	asrs r0, 16
	ldrh r3, [r7, 0x24]
	mov r8, r3
	movs r3, 0x24
	ldrsh r1, [r7, r3]
	cmp r0, r1
	blt _0815C8DA
	mov r0, r8
	subs r5, r0, r2
	lsls r5, 16
	asrs r5, 16
	adds r6, r1, 0
	lsls r6, 1
	adds r0, r5, 0
	adds r1, r6, 0
	bl __divsi3
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	adds r1, r6, 0
	bl __modsi3
	lsls r0, 16
	lsrs r0, 16
	lsls r4, 16
	asrs r4, 16
	movs r1, 0x1
	ands r4, r1
	cmp r4, 0
	bne _0815C854
	lsls r0, 16
	asrs r0, 16
	mov r2, r8
	subs r0, r2, r0
	b _0815C8B2
_0815C854:
	lsls r0, 16
	asrs r0, 16
	mov r3, r8
	subs r0, r3
	strh r0, [r7, 0xC]
	b _0815C8DA
_0815C860:
	ldr r1, =0xfffffe00
	adds r0, r1, 0
	ldrh r2, [r7, 0xC]
	adds r1, r0, r2
	strh r1, [r7, 0xC]
	movs r3, 0xC
	ldrsh r0, [r7, r3]
	movs r2, 0x24
	ldrsh r6, [r7, r2]
	cmn r0, r6
	bgt _0815C8DA
	ldrh r3, [r7, 0x24]
	mov r9, r3
	mov r0, r9
	subs r4, r0, r1
	lsls r4, 16
	asrs r4, 16
	lsls r6, 1
	adds r0, r4, 0
	adds r1, r6, 0
	bl __divsi3
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	adds r0, r4, 0
	adds r1, r6, 0
	bl __modsi3
	lsls r0, 16
	lsrs r2, r0, 16
	mov r1, r8
	ands r1, r5
	lsls r0, r1, 16
	asrs r1, r0, 16
	cmp r1, 0
	bne _0815C8BC
	lsls r0, r2, 16
	asrs r0, 16
	mov r2, r9
	subs r0, r2
_0815C8B2:
	strh r0, [r7, 0xC]
	strh r1, [r7, 0x8]
	b _0815C8DA
	.pool
_0815C8BC:
	lsls r0, r2, 16
	asrs r0, 16
	mov r3, r9
	subs r0, r3, r0
	strh r0, [r7, 0xC]
	b _0815C8DA
_0815C8C8:
	ldrh r0, [r7, 0x26]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A7344
	adds r0, r4, 0
	bl move_anim_task_del
	b _0815C950
_0815C8DA:
	ldrh r0, [r7, 0x26]
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r7, 0xC]
	adds r1, r2, 0
	bl obj_id_set_rotscale
	ldrh r0, [r7, 0x26]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A73A0
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r7, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	movs r2, 0xC
	ldrsh r0, [r7, r2]
	cmp r0, 0
	bge _0815C90E
	adds r0, 0x3F
_0815C90E:
	asrs r0, 6
	negs r0, r0
	strh r0, [r1, 0x24]
	ldrh r0, [r7, 0xA]
	adds r0, 0x1
	strh r0, [r7, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _0815C950
	ldrh r1, [r7, 0x20]
	movs r3, 0x20
	ldrsh r0, [r7, r3]
	cmp r0, 0
	beq _0815C94C
	subs r0, r1, 0x1
	strh r0, [r7, 0x20]
	ldrh r0, [r7, 0x24]
	ldrh r1, [r7, 0x22]
	subs r0, r1
	strh r0, [r7, 0x24]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF
	bgt _0815C950
	movs r0, 0x10
	strh r0, [r7, 0x24]
	b _0815C950
	.pool
_0815C94C:
	movs r0, 0x2
	strh r0, [r7, 0x8]
_0815C950:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_815C7C4

	thumb_func_start sub_815C95C
sub_815C95C: @ 815C95C
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0815C9BC
	ldr r6, =gUnknown_0203841E
	movs r2, 0x4
	ldrsh r0, [r6, r2]
	cmp r0, 0
	bne _0815C990
	ldr r4, =gUnknown_02038436
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
_0815C990:
	ldrh r0, [r6]
	ldrh r1, [r5, 0x20]
	adds r0, r1
	strh r0, [r5, 0x20]
	ldrh r1, [r6, 0x2]
	ldrh r2, [r5, 0x22]
	adds r0, r1, r2
	strh r0, [r5, 0x22]
	movs r0, 0x80
	strh r0, [r5, 0x30]
	movs r0, 0xC0
	lsls r0, 2
	strh r0, [r5, 0x32]
	strh r1, [r5, 0x34]
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	b _0815CA1A
	.pool
_0815C9BC:
	ldrh r1, [r5, 0x30]
	lsls r0, r1, 16
	asrs r0, 24
	strh r0, [r5, 0x24]
	ldrh r0, [r5, 0x32]
	lsls r0, 16
	asrs r0, 24
	ldrh r2, [r5, 0x26]
	adds r0, r2
	strh r0, [r5, 0x26]
	movs r2, 0x36
	ldrsh r0, [r5, r2]
	adds r4, r1, 0
	cmp r0, 0
	bne _0815C9FA
	movs r0, 0x26
	ldrsh r1, [r5, r0]
	movs r2, 0x34
	ldrsh r0, [r5, r2]
	cmn r1, r0
	ble _0815C9FA
	movs r0, 0x1
	strh r0, [r5, 0x36]
	movs r1, 0x32
	ldrsh r0, [r5, r1]
	negs r0, r0
	movs r1, 0x3
	bl __divsi3
	lsls r0, 1
	strh r0, [r5, 0x32]
_0815C9FA:
	adds r0, r4, 0
	adds r0, 0xC0
	strh r0, [r5, 0x30]
	ldrh r0, [r5, 0x32]
	adds r0, 0x80
	strh r0, [r5, 0x32]
	adds r0, r5, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0815CA1A
	adds r0, r5, 0
	bl move_anim_8072740
_0815CA1A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_815C95C

	thumb_func_start sub_815CA20
sub_815CA20: @ 815CA20
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	adds r7, r0, 0
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r2, r0, r1
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	cmp r0, 0
	bne _0815CB2C
	ldr r0, =gUnknown_0203841E
	movs r3, 0
	ldrsh r1, [r0, r3]
	mov r8, r0
	cmp r1, 0
	bne _0815CA5C
	ldr r0, =gUnknown_02038436
	b _0815CA5E
	.pool
_0815CA5C:
	ldr r0, =gUnknown_02038437
_0815CA5E:
	ldrb r0, [r0]
	strh r0, [r2, 0x1E]
	mov r1, r8
	ldrb r0, [r1]
	bl obj_id_for_side_relative_to_move
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r4, r7, 2
	adds r0, r4, r7
	lsls r0, 3
	adds r6, r0, r1
	strh r5, [r6, 0x1C]
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A7270
	mov r2, r8
	movs r3, 0x2
	ldrsh r0, [r2, r3]
	cmp r0, 0x1
	beq _0815CAC0
	cmp r0, 0x1
	bgt _0815CAA0
	cmp r0, 0
	beq _0815CAA8
	lsls r2, r5, 4
	b _0815CB08
	.pool
_0815CAA0:
	cmp r0, 0x2
	beq _0815CACA
	lsls r2, r5, 4
	b _0815CB08
_0815CAA8:
	movs r2, 0xA0
	lsls r2, 1
	adds r0, r5, 0
	movs r1, 0xE0
	movs r3, 0
	bl obj_id_set_rotscale
	adds r0, r5, 0
	bl sub_80A7E6C
	lsls r2, r5, 4
	b _0815CB08
_0815CAC0:
	movs r2, 0x98
	lsls r2, 1
	movs r3, 0xF0
	lsls r3, 4
	b _0815CAD2
_0815CACA:
	movs r2, 0x98
	lsls r2, 1
	movs r3, 0xF1
	lsls r3, 8
_0815CAD2:
	adds r0, r5, 0
	movs r1, 0xD0
	bl obj_id_set_rotscale
	adds r0, r5, 0
	bl sub_80A7E6C
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	bne _0815CAF8
	ldrb r0, [r6, 0x1E]
	bl GetBankSide
	lsls r0, 24
	lsls r2, r5, 4
	cmp r0, 0
	bne _0815CB08
_0815CAF8:
	ldr r0, =gSprites
	lsls r2, r5, 4
	adds r1, r2, r5
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x26]
	adds r0, 0x10
	strh r0, [r1, 0x26]
_0815CB08:
	ldr r1, =gSprites
	adds r0, r2, r5
	lsls r0, 2
	adds r0, r1
	movs r1, 0x2
	strh r1, [r0, 0x24]
	ldr r0, =gTasks
	adds r1, r4, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0815CB78
	.pool
_0815CB2C:
	ldrb r5, [r2, 0x1C]
	ldrh r0, [r2, 0xC]
	adds r0, 0x1
	movs r4, 0
	strh r0, [r2, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	bne _0815CB50
	strh r4, [r2, 0xC]
	ldr r0, =gSprites
	lsls r1, r5, 4
	adds r1, r5
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x24]
	negs r0, r0
	strh r0, [r1, 0x24]
_0815CB50:
	ldrh r0, [r2, 0xA]
	adds r0, 0x1
	strh r0, [r2, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	bne _0815CB78
	adds r0, r5, 0
	bl sub_80A7344
	ldr r1, =gSprites
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	strh r4, [r0, 0x24]
	strh r4, [r0, 0x26]
	adds r0, r7, 0
	bl move_anim_task_del
_0815CB78:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815CA20

	thumb_func_start sub_815CB88
sub_815CB88: @ 815CB88
	push {r4,r5,lr}
	adds r4, r0, 0
	bl Random2
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xC
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	ldrh r2, [r4, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, r0
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x4]
	bl Random2
	ldr r5, =0x000001ff
	ands r5, r0
	bl Random2
	movs r1, 0xFF
	ands r1, r0
	movs r0, 0x1
	ands r0, r5
	cmp r0, 0
	beq _0815CBE0
	movs r2, 0xBC
	lsls r2, 3
	adds r0, r5, r2
	b _0815CBE8
	.pool
_0815CBE0:
	movs r3, 0xBC
	lsls r3, 3
	adds r0, r3, 0
	subs r0, r5
_0815CBE8:
	strh r0, [r4, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0815CBFA
	movs r2, 0x90
	lsls r2, 3
	adds r0, r1, r2
	b _0815CC02
_0815CBFA:
	movs r3, 0x90
	lsls r3, 3
	adds r0, r3, 0
	subs r0, r1
_0815CC02:
	strh r0, [r4, 0x30]
	ldr r0, =gUnknown_0203841E
	ldrh r0, [r0]
	strh r0, [r4, 0x32]
	lsls r0, 16
	cmp r0, 0
	bne _0815CC1C
	ldr r0, =0x0000fff8
	b _0815CC1E
	.pool
_0815CC1C:
	movs r0, 0xF8
_0815CC1E:
	strh r0, [r4, 0x20]
	movs r0, 0x68
	strh r0, [r4, 0x22]
	ldr r0, =sub_815CC34
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815CB88

	thumb_func_start sub_815CC34
sub_815CC34: @ 815CC34
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815CC4C
	ldrh r3, [r4, 0x2E]
	lsls r0, r3, 16
	asrs r0, 24
	ldrh r1, [r4, 0x24]
	adds r0, r1
	b _0815CC56
_0815CC4C:
	ldrh r3, [r4, 0x2E]
	lsls r1, r3, 16
	asrs r1, 24
	ldrh r0, [r4, 0x24]
	subs r0, r1
_0815CC56:
	strh r0, [r4, 0x24]
	ldrh r2, [r4, 0x30]
	lsls r1, r2, 16
	asrs r1, 24
	ldrh r0, [r4, 0x26]
	subs r0, r1
	strh r0, [r4, 0x26]
	adds r0, r3, 0
	subs r0, 0x16
	strh r0, [r4, 0x2E]
	adds r1, r2, 0
	subs r1, 0x30
	strh r1, [r4, 0x30]
	lsls r0, 16
	cmp r0, 0
	bge _0815CC7A
	movs r0, 0
	strh r0, [r4, 0x2E]
_0815CC7A:
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1F
	bne _0815CC8E
	adds r0, r4, 0
	bl move_anim_8072740
_0815CC8E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_815CC34

	thumb_func_start sub_815CC94
sub_815CC94: @ 815CC94
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r1, =0x00001f3f
	movs r0, 0x4A
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 8
	movs r0, 0
	bl SetGpuRegBits
	ldr r0, =gUnknown_02022E24
	movs r1, 0
	strh r1, [r0]
	ldr r4, =gUnknown_02022E26
	strh r1, [r4]
	movs r0, 0x40
	movs r1, 0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0x44
	bl SetGpuReg
	ldr r0, =gUnknown_0203841E
	ldrh r0, [r0, 0x4]
	strh r0, [r5, 0x2E]
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A6980
	ldrb r1, [r5, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r5, 0x1]
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_815CD0C
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815CC94

	thumb_func_start sub_815CD0C
sub_815CD0C: @ 815CD0C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0815CD4A
	cmp r0, 0x1
	bgt _0815CD22
	cmp r0, 0
	beq _0815CD2C
	b _0815CDAA
_0815CD22:
	cmp r0, 0x2
	beq _0815CD60
	cmp r0, 0x3
	beq _0815CD82
	b _0815CDAA
_0815CD2C:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0815CDAA
	b _0815CD7A
_0815CD4A:
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	cmp r0, 0
	bne _0815CDAA
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80082B8
	b _0815CD7A
_0815CD60:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0815CDAA
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_0815CD7A:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	b _0815CDAA
_0815CD82:
	ldr r1, =0x00003f3f
	movs r0, 0x4A
	bl SetGpuReg
	movs r0, 0
	bl GetGpuReg
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 8
	adds r0, r2, 0
	eors r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl move_anim_8072740
_0815CDAA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815CD0C

	thumb_func_start sub_815CDB4
sub_815CDB4: @ 815CDB4
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gUnknown_02038436
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x20]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x22]
	ldr r1, =gUnknown_0203841E
	ldrh r0, [r1]
	strh r0, [r4, 0x2E]
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0x30]
	ldr r1, =sub_815CDFC
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815CDB4

	thumb_func_start sub_815CDFC
sub_815CDFC: @ 815CDFC
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, 0x32]
	lsls r1, 16
	asrs r1, 24
	bl Sin
	strh r0, [r4, 0x24]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	ldrh r1, [r4, 0x34]
	lsls r1, 16
	asrs r1, 24
	bl Cos
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	adds r0, 0x9
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x30]
	lsls r1, r0, 16
	cmp r0, 0x3F
	bls _0815CE36
	asrs r0, r1, 16
	cmp r0, 0xC3
	ble _0815CE48
_0815CE36:
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl sub_80A82E4
	subs r0, 0x1
	b _0815CE52
	.pool
_0815CE48:
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl sub_80A82E4
	adds r0, 0x1
_0815CE52:
	adds r1, r4, 0
	adds r1, 0x43
	strb r0, [r1]
	movs r3, 0x38
	ldrsh r2, [r4, r3]
	cmp r2, 0
	bne _0815CE98
	movs r1, 0x80
	lsls r1, 3
	adds r0, r1, 0
	ldrh r3, [r4, 0x32]
	adds r0, r3
	strh r0, [r4, 0x32]
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	ldrh r3, [r4, 0x34]
	adds r0, r3
	strh r0, [r4, 0x34]
	ldrh r0, [r4, 0x36]
	adds r0, 0x1
	strh r0, [r4, 0x36]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	cmp r0, r1
	bne _0815CEC8
	strh r2, [r4, 0x36]
	movs r0, 0x1
	strh r0, [r4, 0x38]
	b _0815CEC8
	.pool
_0815CE98:
	cmp r2, 0x1
	bne _0815CEC8
	ldr r1, =0xfffffc00
	adds r0, r1, 0
	ldrh r2, [r4, 0x32]
	adds r0, r2
	strh r0, [r4, 0x32]
	ldr r3, =0xffffff00
	adds r0, r3, 0
	ldrh r1, [r4, 0x34]
	adds r0, r1
	strh r0, [r4, 0x34]
	ldrh r0, [r4, 0x36]
	adds r0, 0x1
	strh r0, [r4, 0x36]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x2E
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bne _0815CEC8
	adds r0, r4, 0
	bl move_anim_8072740
_0815CEC8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815CDFC

	thumb_func_start sub_815CED8
sub_815CED8: @ 815CED8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x18]
	movs r0, 0
	bl obj_id_for_side_relative_to_move
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	beq _0815CF18
	movs r0, 0x1
	str r0, [sp, 0x1C]
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldr r1, [r0, 0x10]
	mov r9, r1
	ldr r2, [r0, 0xC]
	mov r8, r2
	ldrh r6, [r0, 0x2]
	movs r3, 0x14
	b _0815D058
	.pool
_0815CF18:
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0815CFC4
	movs r0, 0
	str r0, [sp, 0x1C]
	ldr r6, =gBattlePartyID
	ldr r4, =gUnknown_02038437
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	movs r5, 0x64
	muls r0, r5
	ldr r7, =gPlayerParty
	adds r0, r7
	movs r1, 0
	bl GetMonData
	mov r9, r0
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	muls r0, r5
	adds r0, r7
	movs r1, 0x1
	bl GetMonData
	mov r8, r0
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldrb r2, [r4]
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r1, r0, r1
	ldrh r0, [r1, 0x2]
	cmp r0, 0
	bne _0815CFBC
	adds r0, r2, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0815CF9C
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	muls r0, r5
	adds r0, r7
	b _0815CFAA
	.pool
_0815CF9C:
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
_0815CFAA:
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r6, r0, 16
	b _0815CFBE
	.pool
_0815CFBC:
	ldrh r6, [r1, 0x2]
_0815CFBE:
	movs r1, 0x14
	mov r10, r1
	b _0815D05A
_0815CFC4:
	movs r2, 0x1
	str r2, [sp, 0x1C]
	ldr r6, =gBattlePartyID
	ldr r4, =gUnknown_02038437
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	movs r5, 0x64
	muls r0, r5
	ldr r7, =gEnemyParty
	adds r0, r7
	movs r1, 0
	bl GetMonData
	mov r9, r0
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	muls r0, r5
	adds r0, r7
	movs r1, 0x1
	bl GetMonData
	mov r8, r0
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldrb r2, [r4]
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r1, r0, r1
	ldrh r0, [r1, 0x2]
	cmp r0, 0
	bne _0815D054
	adds r0, r2, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0815D03C
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	b _0815D048
	.pool
_0815D03C:
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	muls r0, r5
	adds r0, r7
_0815D048:
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r6, r0, 16
	b _0815D056
_0815D054:
	ldrh r6, [r1, 0x2]
_0815D056:
	ldr r3, =0x0000ffec
_0815D058:
	mov r10, r3
_0815D05A:
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl sub_80A8328
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r5, =gUnknown_02038436
	ldrb r0, [r5]
	movs r1, 0
	bl sub_80A5C6C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r5]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	mov r2, r10
	lsls r1, r2, 16
	asrs r1, 16
	adds r4, r1
	lsls r4, 16
	asrs r4, 16
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0x5
	str r0, [sp, 0x4]
	mov r3, r9
	str r3, [sp, 0x8]
	mov r0, r8
	str r0, [sp, 0xC]
	ldr r0, =gUnknown_02038437
	ldrb r0, [r0]
	str r0, [sp, 0x10]
	movs r0, 0x1
	str r0, [sp, 0x14]
	adds r0, r6, 0
	ldr r1, [sp, 0x1C]
	movs r2, 0
	adds r3, r4, 0
	bl sub_80A8394
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	ldr r0, =gSprites
	lsls r5, r6, 4
	adds r5, r6
	lsls r5, 2
	adds r5, r0
	movs r0, 0x3
	ands r7, r0
	lsls r7, 2
	mov r8, r7
	ldrb r0, [r5, 0x5]
	movs r4, 0xD
	negs r4, r4
	adds r1, r4, 0
	ands r1, r0
	mov r2, r8
	orrs r1, r2
	strb r1, [r5, 0x5]
	ldrb r2, [r5, 0x1]
	adds r0, r4, 0
	ands r0, r2
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r5, 0x1]
	ldr r0, =0x00007fff
	lsrs r1, 4
	lsls r1, 4
	movs r3, 0x80
	lsls r3, 1
	adds r2, r3, 0
	orrs r1, r2
	movs r2, 0x20
	bl FillPalette
	ldrb r0, [r5, 0x5]
	ands r4, r0
	mov r0, r8
	orrs r4, r0
	strb r4, [r5, 0x5]
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	ldr r0, =gTasks
	ldr r1, [sp, 0x18]
	lsls r4, r1, 2
	adds r4, r1
	lsls r4, 3
	adds r4, r0
	ldrh r0, [r4, 0xA]
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	strh r6, [r4, 0x8]
	ldr r0, =sub_815D160
	str r0, [r4]
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815CED8

	thumb_func_start sub_815D160
sub_815D160: @ 815D160
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r0, [r4, 0x1C]
	adds r1, r0, 0x1
	strh r1, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0815D1AE
	movs r0, 0
	strh r0, [r4, 0x1C]
	ldrh r1, [r4, 0xA]
	adds r1, 0x1
	strh r1, [r4, 0xA]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0xA
	bne _0815D1AE
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r4, 0x1C]
	strh r0, [r4, 0x1E]
	ldr r0, =sub_815D1BC
	str r0, [r4]
_0815D1AE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815D160

	thumb_func_start sub_815D1BC
sub_815D1BC: @ 815D1BC
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r5, r1, r2
	ldrb r2, [r5, 0x8]
	ldrh r0, [r5, 0x1C]
	subs r0, 0x10
	movs r4, 0
	strh r0, [r5, 0x1C]
	ldrh r0, [r5, 0x1E]
	adds r0, 0x80
	strh r0, [r5, 0x1E]
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r6, r0, r1
	ldrb r2, [r6, 0x1]
	lsls r1, r2, 30
	lsrs r1, 30
	movs r0, 0x2
	orrs r1, r0
	subs r0, 0x6
	ands r0, r2
	orrs r0, r1
	strb r0, [r6, 0x1]
	movs r0, 0x1C
	ldrsh r2, [r5, r0]
	movs r0, 0x1E
	ldrsh r3, [r5, r0]
	str r4, [sp]
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_80A73E0
	ldrh r0, [r5, 0x20]
	adds r0, 0x1
	strh r0, [r5, 0x20]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x9
	bne _0815D22A
	adds r0, r6, 0
	bl sub_80A749C
	adds r0, r6, 0
	bl sub_80A8610
	ldr r0, =sub_80A6814
	str r0, [r5]
_0815D22A:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815D1BC

	thumb_func_start sub_815D240
sub_815D240: @ 815D240
	push {r4-r7,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	ldr r0, =gUnknown_0203841E
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0815D26C
	ldr r0, =gUnknown_02038436
	b _0815D26E
	.pool
_0815D26C:
	ldr r0, =gUnknown_02038437
_0815D26E:
	ldrb r5, [r0]
	movs r6, 0
	strh r6, [r4, 0x8]
	strh r6, [r4, 0xA]
	strh r6, [r4, 0xC]
	movs r0, 0x10
	strh r0, [r4, 0xE]
	strh r6, [r4, 0x10]
	strh r5, [r4, 0x12]
	movs r0, 0x20
	strh r0, [r4, 0x14]
	strh r6, [r4, 0x16]
	movs r0, 0x18
	strh r0, [r4, 0x18]
	adds r0, r5, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815D2A0
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	negs r0, r0
	strh r0, [r4, 0x18]
_0815D2A0:
	adds r0, r5, 0
	bl sub_80A6190
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x22
	strh r0, [r4, 0x22]
	cmp r0, 0
	bge _0815D2B4
	strh r6, [r4, 0x22]
_0815D2B4:
	ldrh r0, [r4, 0x22]
	adds r0, 0x42
	strh r0, [r4, 0x24]
	ldr r0, =gUnknown_0203841E
	ldrb r0, [r0]
	bl obj_id_for_side_relative_to_move
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x26]
	adds r0, r5, 0
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815D304
	ldr r0, =0x04000014
	str r0, [sp]
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	ldr r0, =gUnknown_02022E18
	ldrh r5, [r0]
	ldr r0, =gUnknown_02022E1A
	b _0815D316
	.pool
_0815D304:
	ldr r0, =0x04000018
	str r0, [sp]
	ldr r1, =0x00003f44
	movs r0, 0x50
	bl SetGpuReg
	ldr r0, =gUnknown_02022E1C
	ldrh r5, [r0]
	ldr r0, =gUnknown_02022E1E
_0815D316:
	ldrh r3, [r0]
	movs r7, 0
	movs r2, 0
	ldr r6, =gUnknown_02038C28
	movs r0, 0xF0
	lsls r0, 3
	adds r0, r6
	mov r12, r0
_0815D326:
	lsls r2, 16
	asrs r2, 16
	lsls r1, r2, 1
	adds r0, r1, r6
	strh r5, [r0]
	add r1, r12
	strh r5, [r1]
	adds r0, r2, 0x1
	lsls r0, 1
	adds r1, r0, r6
	strh r3, [r1]
	add r0, r12
	strh r3, [r0]
	lsls r0, r7, 16
	movs r1, 0x80
	lsls r1, 9
	adds r0, r1
	adds r2, 0x2
	lsls r2, 16
	lsrs r2, 16
	lsrs r7, r0, 16
	asrs r0, 16
	cmp r0, 0x9F
	ble _0815D326
	ldr r0, =0xa6600001
	str r0, [sp, 0x4]
	mov r1, sp
	movs r2, 0
	movs r0, 0x1
	strb r0, [r1, 0x8]
	mov r0, sp
	strb r2, [r0, 0x9]
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	bl sub_80BA038
	ldr r0, =sub_815D398
	str r0, [r4]
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815D240

	thumb_func_start sub_815D398
sub_815D398: @ 815D398
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r6, r0, r1
	ldrb r0, [r6, 0x12]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815D3D8
	ldr r0, =gUnknown_02022E18
	ldrh r0, [r0]
	str r0, [sp, 0x4]
	ldr r0, =gUnknown_02022E1A
	b _0815D3E0
	.pool
_0815D3D8:
	ldr r0, =gUnknown_02022E1C
	ldrh r0, [r0]
	str r0, [sp, 0x4]
	ldr r0, =gUnknown_02022E1E
_0815D3E0:
	ldrh r0, [r0]
	str r0, [sp, 0x8]
	movs r1, 0x8
	ldrsh r0, [r6, r1]
	cmp r0, 0x1
	bne _0815D3EE
	b _0815D5CC
_0815D3EE:
	cmp r0, 0x1
	bgt _0815D400
	cmp r0, 0
	beq _0815D40E
	b _0815D63C
	.pool
_0815D400:
	cmp r0, 0x2
	bne _0815D406
	b _0815D5EC
_0815D406:
	cmp r0, 0x3
	bne _0815D40C
	b _0815D636
_0815D40C:
	b _0815D63C
_0815D40E:
	movs r2, 0x24
	ldrsh r0, [r6, r2]
	lsls r0, 17
	lsrs r5, r0, 16
	movs r3, 0
	str r3, [sp]
	mov r9, r3
	movs r4, 0
	ldrh r0, [r6, 0xA]
	adds r0, 0x2
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r6, 0xA]
	ldrh r7, [r6, 0xA]
	mov r8, r7
	movs r0, 0x14
	ldrsh r1, [r6, r0]
	movs r0, 0xFC
	lsls r0, 3
	bl __divsi3
	strh r0, [r6, 0x1A]
	movs r1, 0x16
	ldrsh r0, [r6, r1]
	lsls r0, 1
	movs r2, 0x1A
	ldrsh r1, [r6, r2]
	bl __divsi3
	negs r0, r0
	strh r0, [r6, 0x1C]
	ldrh r0, [r6, 0x16]
	strh r0, [r6, 0x1E]
	lsls r0, 16
	asrs r0, 21
	lsls r0, 16
	lsrs r7, r0, 16
	strh r7, [r6, 0x20]
	ldrh r2, [r6, 0x24]
	lsls r3, r2, 16
	mov r12, r3
	asrs r1, r3, 16
	movs r3, 0x22
	ldrsh r0, [r6, r3]
	cmp r1, r0
	ble _0815D52E
	ldr r0, =gUnknown_02039B28
	mov r10, r0
	ldr r1, [sp, 0x4]
	lsls r0, r1, 16
	asrs r0, 16
	str r0, [sp, 0x10]
	ldr r2, [sp, 0x8]
	lsls r0, r2, 16
	asrs r0, 16
	str r0, [sp, 0xC]
_0815D47E:
	lsls r5, 16
	asrs r5, 16
	adds r2, r5, 0x1
	lsls r2, 1
	mov r3, r10
	ldrb r1, [r3, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	ldr r0, =gUnknown_02038C28
	adds r2, r0
	lsls r4, 16
	asrs r4, 16
	mov r1, r9
	lsls r0, r1, 16
	asrs r0, 16
	subs r0, r4, r0
	ldr r3, [sp, 0xC]
	adds r0, r3, r0
	strh r0, [r2]
	lsls r3, r5, 1
	mov r0, r10
	ldrb r1, [r0, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r3, r0
	ldr r1, =gUnknown_02038C28
	adds r3, r1
	lsls r1, r7, 16
	asrs r1, 16
	ldr r2, [sp, 0x10]
	adds r1, r2, r1
	mov r7, r8
	lsls r2, r7, 16
	asrs r2, 16
	lsls r0, r2, 1
	ldr r7, =gSineTable
	adds r0, r7
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 21
	adds r1, r0
	strh r1, [r3]
	adds r2, 0xA
	mov r8, r2
	movs r0, 0xFF
	mov r1, r8
	ands r1, r0
	mov r8, r1
	ldrh r0, [r6, 0x1C]
	ldrh r2, [r6, 0x1E]
	adds r0, r2
	strh r0, [r6, 0x1E]
	lsls r0, 16
	asrs r0, 21
	lsls r0, 16
	lsrs r7, r0, 16
	strh r7, [r6, 0x20]
	adds r4, 0x1
	lsls r4, 16
	lsrs r4, 16
	subs r5, 0x2
	lsls r5, 16
	lsrs r5, 16
	ldr r3, [sp]
	lsls r0, r3, 16
	asrs r0, 16
	ldrh r1, [r6, 0x14]
	adds r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	str r2, [sp]
	asrs r0, 21
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	ldr r0, =0xffff0000
	add r0, r12
	lsrs r2, r0, 16
	lsls r3, r2, 16
	mov r12, r3
	asrs r1, r3, 16
	movs r3, 0x22
	ldrsh r0, [r6, r3]
	cmp r1, r0
	bgt _0815D47E
_0815D52E:
	lsls r1, r2, 17
	cmp r1, 0
	blt _0815D55A
	ldr r4, =gUnknown_02038C28
	ldr r7, [sp, 0x4]
	lsls r0, r7, 16
	asrs r0, 16
	adds r3, r0, 0
	adds r3, 0xF0
	movs r0, 0xF0
	lsls r0, 3
	adds r5, r4, r0
_0815D546:
	asrs r2, r1, 16
	lsls r1, r2, 1
	adds r0, r1, r4
	strh r3, [r0]
	adds r1, r5
	strh r3, [r1]
	subs r2, 0x2
	lsls r1, r2, 16
	cmp r1, 0
	bge _0815D546
_0815D55A:
	ldrh r0, [r6, 0x14]
	adds r0, 0x1
	strh r0, [r6, 0x14]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3F
	ble _0815D5C2
	movs r0, 0x40
	strh r0, [r6, 0x14]
	ldrh r0, [r6, 0xC]
	adds r0, 0x1
	strh r0, [r6, 0xC]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0815D594
	ldrh r0, [r6, 0xE]
	subs r0, 0x1
	strh r0, [r6, 0xE]
	b _0815D59A
	.pool
_0815D594:
	ldrh r0, [r6, 0x10]
	adds r0, 0x1
	strh r0, [r6, 0x10]
_0815D59A:
	ldrh r1, [r6, 0x10]
	lsls r1, 8
	ldrh r0, [r6, 0xE]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r2, 0xE
	ldrsh r1, [r6, r2]
	cmp r1, 0
	bne _0815D63C
	movs r3, 0x10
	ldrsh r0, [r6, r3]
	cmp r0, 0x10
	bne _0815D63C
	strh r1, [r6, 0xC]
	strh r1, [r6, 0xE]
	b _0815D62E
_0815D5C2:
	ldrh r0, [r6, 0x18]
	ldrh r7, [r6, 0x16]
	adds r0, r7
	strh r0, [r6, 0x16]
	b _0815D63C
_0815D5CC:
	ldrh r0, [r6, 0xC]
	adds r0, 0x1
	strh r0, [r6, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	ble _0815D63C
	ldr r1, =gUnknown_02039B28
	movs r0, 0x3
	strb r0, [r1, 0x15]
	movs r0, 0
	strh r0, [r6, 0xC]
	b _0815D62E
	.pool
_0815D5EC:
	ldrh r0, [r6, 0xC]
	adds r0, 0x1
	strh r0, [r6, 0xC]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0815D602
	ldrh r0, [r6, 0xE]
	adds r0, 0x1
	strh r0, [r6, 0xE]
	b _0815D608
_0815D602:
	ldrh r0, [r6, 0x10]
	subs r0, 0x1
	strh r0, [r6, 0x10]
_0815D608:
	ldrh r1, [r6, 0x10]
	lsls r1, 8
	ldrh r0, [r6, 0xE]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0xE
	ldrsh r0, [r6, r1]
	cmp r0, 0x10
	bne _0815D63C
	movs r2, 0x10
	ldrsh r0, [r6, r2]
	cmp r0, 0
	bne _0815D63C
	strh r0, [r6, 0xC]
	strh r0, [r6, 0xE]
_0815D62E:
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
	b _0815D63C
_0815D636:
	adds r0, r4, 0
	bl move_anim_task_del
_0815D63C:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_815D398

	thumb_func_start sub_815D64C
sub_815D64C: @ 815D64C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	movs r0, 0
	strh r0, [r4, 0x8]
	ldr r0, =gUnknown_0203841E
	ldrb r0, [r0]
	bl obj_id_for_side_relative_to_move
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	strh r1, [r4, 0x26]
	ldr r2, =gUnknown_085CE5F0
	adds r0, r4, 0
	bl sub_80A7CFC
	ldr r0, =sub_815D694
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815D64C

	thumb_func_start sub_815D694
sub_815D694: @ 815D694
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r2, =gTasks
	adds r3, r0, r2
	ldrh r0, [r3, 0x8]
	adds r1, r0, 0x1
	movs r5, 0
	strh r1, [r3, 0x8]
	subs r0, 0x14
	lsls r0, 16
	lsrs r0, 16
	adds r6, r2, 0
	cmp r0, 0x16
	bhi _0815D6F8
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0815D708
	strh r5, [r3, 0xA]
	ldrh r0, [r3, 0xC]
	adds r0, 0x1
	strh r0, [r3, 0xC]
	movs r5, 0x1
	ands r0, r5
	cmp r0, 0
	bne _0815D6F8
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x24]
	b _0815D708
	.pool
_0815D6F8:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r5, [r0, 0x24]
_0815D708:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r6
	bl sub_80A7D34
	lsls r0, 24
	cmp r0, 0
	bne _0815D720
	adds r0, r4, 0
	bl move_anim_task_del
_0815D720:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815D694

	thumb_func_start sub_815D72C
sub_815D72C: @ 815D72C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	adds r5, r2, 0
	adds r0, r3, 0
	ldr r4, [sp, 0x14]
	ldr r6, [sp, 0x18]
	lsls r1, 16
	lsrs r1, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r4, 16
	lsrs r4, 16
	lsls r6, 16
	lsrs r6, 16
	mov r2, r8
	strh r1, [r2, 0x20]
	strh r5, [r2, 0x22]
	lsls r1, 16
	asrs r1, 16
	lsls r2, r1, 4
	mov r3, r8
	strh r2, [r3, 0x36]
	lsls r5, 16
	asrs r5, 16
	lsls r2, r5, 4
	strh r2, [r3, 0x38]
	lsls r0, 16
	asrs r0, 16
	subs r0, r1
	lsls r0, 4
	adds r1, r6, 0
	bl __divsi3
	mov r1, r8
	strh r0, [r1, 0x3A]
	lsls r4, 16
	asrs r4, 16
	subs r4, r5
	lsls r4, 4
	adds r0, r4, 0
	adds r1, r6, 0
	bl __divsi3
	mov r2, r8
	strh r0, [r2, 0x3C]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_815D72C

	thumb_func_start sub_815D794
sub_815D794: @ 815D794
	ldrh r1, [r0, 0x3A]
	ldrh r2, [r0, 0x36]
	adds r1, r2
	strh r1, [r0, 0x36]
	ldrh r2, [r0, 0x3C]
	ldrh r3, [r0, 0x38]
	adds r2, r3
	strh r2, [r0, 0x38]
	lsls r1, 16
	asrs r1, 20
	strh r1, [r0, 0x20]
	lsls r2, 16
	asrs r2, 20
	strh r2, [r0, 0x22]
	bx lr
	thumb_func_end sub_815D794

	thumb_func_start sub_815D7B4
sub_815D7B4: @ 815D7B4
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	ldrh r6, [r4, 0x20]
	ldrh r5, [r4, 0x22]
	bl sub_80A6838
	ldr r0, =gUnknown_0203841E
	ldrb r1, [r0]
	adds r0, r4, 0
	bl StartObjectRotScalAnim
	movs r0, 0x20
	ldrsh r1, [r4, r0]
	movs r0, 0x22
	ldrsh r2, [r4, r0]
	lsls r6, 16
	asrs r6, 16
	lsls r5, 16
	asrs r5, 16
	str r5, [sp]
	movs r0, 0x40
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r3, r6, 0
	bl sub_815D72C
	movs r0, 0
	strh r0, [r4, 0x2E]
	ldr r0, =sub_815D804
	str r0, [r4, 0x1C]
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815D7B4

	thumb_func_start sub_815D804
sub_815D804: @ 815D804
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	movs r0, 0x2E
	ldrsh r4, [r5, r0]
	lsls r4, 3
	movs r0, 0xFF
	ands r4, r0
	adds r0, r5, 0
	bl sub_815D794
	adds r0, r4, 0
	movs r1, 0x8
	bl Sin
	strh r0, [r5, 0x26]
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0x3A
	ble _0815D86A
	ldrh r0, [r5, 0x30]
	adds r0, 0x1
	strh r0, [r5, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0815D86A
	movs r0, 0
	strh r0, [r5, 0x30]
	ldrh r1, [r5, 0x32]
	adds r1, 0x1
	strh r1, [r5, 0x32]
	movs r0, 0x1
	ands r1, r0
	adds r3, r5, 0
	adds r3, 0x3E
	lsls r1, 2
	ldrb r2, [r3]
	subs r0, 0x6
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r1, 0x32
	ldrsh r0, [r5, r1]
	cmp r0, 0x3
	ble _0815D86A
	adds r0, r5, 0
	bl move_anim_8074EE0
_0815D86A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815D804

	thumb_func_start sub_815D870
sub_815D870: @ 815D870
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gUnknown_0203841E
	ldrh r0, [r6, 0x6]
	strh r0, [r5, 0x2E]
	ldrb r1, [r6]
	adds r0, r5, 0
	bl StartObjectRotScalAnim
	ldr r0, =gUnknown_02038437
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0815D896
	ldrh r0, [r6, 0x2]
	negs r0, r0
	strh r0, [r6, 0x2]
_0815D896:
	ldr r4, =gUnknown_02038436
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r6, 0x2]
	adds r0, r1
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r6, [r6, 0x4]
	adds r0, r6
	strh r0, [r5, 0x22]
	ldr r0, =sub_810E2C8
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815D870

	thumb_func_start sub_815D8D8
sub_815D8D8: @ 815D8D8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r7, 0
	ldr r2, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r3, r0, r2
	ldrh r0, [r3, 0x8]
	subs r0, 0x1
	strh r0, [r3, 0x8]
	movs r1, 0x14
	ldrsh r0, [r3, r1]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	mov r8, r2
	cmp r0, 0
	beq _0815D95A
	ldrh r0, [r3, 0xA]
	subs r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0815D95A
	movs r2, 0x1A
	ldrsh r0, [r3, r2]
	cmp r0, 0
	bne _0815D92C
	ldrh r0, [r3, 0x10]
	strh r0, [r3, 0x1A]
	negs r0, r0
	strh r0, [r3, 0x10]
	b _0815D92E
	.pool
_0815D92C:
	strh r7, [r3, 0x1A]
_0815D92E:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	mov r2, r8
	adds r1, r0, r2
	movs r2, 0x1C
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0815D94A
	ldrh r0, [r1, 0x12]
	strh r0, [r1, 0x1C]
	negs r0, r0
	strh r0, [r1, 0x12]
	b _0815D94E
_0815D94A:
	movs r0, 0
	strh r0, [r1, 0x1C]
_0815D94E:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	add r0, r8
	ldrh r1, [r0, 0x22]
	strh r1, [r0, 0xA]
_0815D95A:
	lsls r2, r5, 2
	adds r0, r2, r5
	lsls r0, 3
	mov r1, r8
	adds r4, r0, r1
	ldrh r6, [r4, 0x16]
	ldrh r7, [r4, 0x18]
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	mov r12, r2
	cmp r0, 0
	beq _0815D998
	ldr r3, =gSprites
	movs r2, 0x26
	ldrsh r0, [r4, r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	lsrs r2, r6, 8
	ldrh r0, [r4, 0x1A]
	subs r0, r2
	strh r0, [r1, 0x24]
	adds r2, r3, 0
	b _0815D9AE
	.pool
_0815D998:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	lsrs r1, r6, 8
	ldrh r4, [r4, 0x1A]
	adds r1, r4
	strh r1, [r0, 0x24]
_0815D9AE:
	mov r1, r12
	adds r0, r1, r5
	lsls r0, 3
	mov r1, r8
	adds r4, r0, r1
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0815D9E0
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	lsrs r2, r7, 8
	ldrh r0, [r4, 0x1C]
	subs r0, r2
	b _0815D9F2
	.pool
_0815D9E0:
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	lsrs r0, r7, 8
	ldrh r4, [r4, 0x1C]
	adds r0, r4
_0815D9F2:
	strh r0, [r1, 0x26]
	mov r2, r12
	adds r0, r2, r5
	lsls r0, 3
	add r0, r8
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bgt _0815DA12
	adds r0, r5, 0
	bl DestroyTask
	ldr r1, =gUnknown_020383FE
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
_0815DA12:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815D8D8

	thumb_func_start sub_815DA20
sub_815DA20: @ 815DA20
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r7, 0
	ldr r2, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r3, r0, r2
	ldrh r0, [r3, 0x8]
	subs r0, 0x1
	strh r0, [r3, 0x8]
	movs r1, 0x14
	ldrsh r0, [r3, r1]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	mov r8, r2
	cmp r0, 0
	beq _0815DAA6
	ldrh r0, [r3, 0xA]
	subs r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0815DAA6
	movs r2, 0x1A
	ldrsh r0, [r3, r2]
	cmp r0, 0
	bne _0815DA78
	ldrh r0, [r3, 0x10]
	strh r0, [r3, 0x1A]
	negs r0, r0
	strh r0, [r3, 0x10]
	b _0815DA7A
	.pool
_0815DA78:
	strh r7, [r3, 0x1A]
_0815DA7A:
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	mov r2, r8
	adds r1, r0, r2
	movs r2, 0x1C
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0815DA96
	ldrh r0, [r1, 0x12]
	strh r0, [r1, 0x1C]
	negs r0, r0
	strh r0, [r1, 0x12]
	b _0815DA9A
_0815DA96:
	movs r0, 0
	strh r0, [r1, 0x1C]
_0815DA9A:
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	add r0, r8
	ldrh r1, [r0, 0x22]
	strh r1, [r0, 0xA]
_0815DAA6:
	lsls r3, r6, 2
	adds r0, r3, r6
	lsls r0, 3
	mov r1, r8
	adds r4, r0, r1
	ldrh r2, [r4, 0xC]
	ldr r1, =0x00007fff
	adds r0, r1, 0
	ands r0, r2
	ldrh r2, [r4, 0x16]
	adds r0, r2
	lsls r5, r0, 16
	lsrs r0, r5, 16
	mov r9, r0
	ldrh r0, [r4, 0xE]
	ands r1, r0
	ldrh r2, [r4, 0x18]
	adds r1, r2
	lsls r1, 16
	lsrs r7, r1, 16
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	mov r12, r3
	cmp r0, 0
	beq _0815DB00
	ldr r3, =gSprites
	movs r2, 0x26
	ldrsh r0, [r4, r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	lsrs r2, r5, 24
	ldrh r0, [r4, 0x1A]
	subs r0, r2
	strh r0, [r1, 0x24]
	adds r2, r3, 0
	b _0815DB16
	.pool
_0815DB00:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	lsrs r1, r5, 24
	ldrh r4, [r4, 0x1A]
	adds r1, r4
	strh r1, [r0, 0x24]
_0815DB16:
	mov r1, r12
	adds r0, r1, r6
	lsls r0, 3
	mov r1, r8
	adds r4, r0, r1
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0815DB48
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	lsrs r2, r7, 8
	ldrh r0, [r4, 0x1C]
	subs r0, r2
	b _0815DB5A
	.pool
_0815DB48:
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	lsrs r0, r7, 8
	ldrh r4, [r4, 0x1C]
	adds r0, r4
_0815DB5A:
	strh r0, [r1, 0x26]
	mov r2, r12
	adds r0, r2, r6
	lsls r0, 3
	mov r1, r8
	adds r2, r0, r1
	mov r0, r9
	strh r0, [r2, 0x16]
	strh r7, [r2, 0x18]
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	cmp r0, 0
	bgt _0815DB80
	movs r0, 0x1E
	strh r0, [r2, 0x8]
	movs r0, 0
	strh r0, [r2, 0x22]
	ldr r0, =sub_815D8D8
	str r0, [r2]
_0815DB80:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815DA20

	thumb_func_start sub_815DB90
sub_815DB90: @ 815DB90
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gTasks
	mov r8, r0
	lsls r7, r6, 2
	adds r0, r7, r6
	lsls r0, 3
	mov r1, r8
	adds r4, r0, r1
	ldr r1, =gBankSpriteIds
	ldr r2, =gUnknown_02038436
	ldrb r0, [r2]
	adds r0, r1
	ldrb r0, [r0]
	strh r0, [r4, 0x26]
	ldr r5, =gUnknown_0203841E
	ldrh r0, [r5]
	strh r0, [r4, 0x24]
	ldrh r0, [r5]
	strh r0, [r4, 0x8]
	ldrh r0, [r5, 0xC]
	strh r0, [r4, 0x22]
	movs r3, 0x6
	ldrsh r0, [r5, r3]
	cmp r0, 0
	beq _0815DBD4
	ldrh r0, [r4, 0x14]
	ldr r3, =0xffff8000
	adds r1, r3, 0
	orrs r0, r1
	strh r0, [r4, 0x14]
_0815DBD4:
	ldrb r0, [r2]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0815DC04
	ldrh r0, [r5, 0x2]
	strh r0, [r4, 0xC]
	ldrh r0, [r5, 0x4]
	strh r0, [r4, 0xE]
	mov r3, r8
	adds r4, r7, 0
	b _0815DC74
	.pool
_0815DC04:
	movs r7, 0x2
	ldrsh r0, [r5, r7]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0815DC20
	ldrh r1, [r5, 0x2]
	ldr r0, =0x00007fff
	ands r0, r1
	b _0815DC28
	.pool
_0815DC20:
	ldrh r0, [r5, 0x2]
	ldr r2, =0xffff8000
	adds r1, r2, 0
	orrs r0, r1
_0815DC28:
	strh r0, [r4, 0xC]
	ldr r0, =gUnknown_0203841E
	movs r3, 0x4
	ldrsh r1, [r0, r3]
	movs r2, 0x80
	lsls r2, 8
	ands r1, r2
	adds r5, r0, 0
	cmp r1, 0
	beq _0815DC60
	ldr r3, =gTasks
	lsls r4, r6, 2
	adds r1, r4, r6
	lsls r1, 3
	adds r1, r3
	ldrh r2, [r5, 0x4]
	ldr r0, =0x00007fff
	ands r0, r2
	b _0815DC72
	.pool
_0815DC60:
	ldr r3, =gTasks
	lsls r4, r6, 2
	adds r1, r4, r6
	lsls r1, 3
	adds r1, r3
	ldrh r2, [r5, 0x4]
	ldr r7, =0xffff8000
	adds r0, r7, 0
	orrs r0, r2
_0815DC72:
	strh r0, [r1, 0xE]
_0815DC74:
	adds r0, r4, r6
	lsls r0, 3
	adds r0, r3
	movs r1, 0
	strh r1, [r0, 0x18]
	strh r1, [r0, 0x16]
	ldrh r1, [r5, 0x8]
	strh r1, [r0, 0x10]
	ldrh r1, [r5, 0xA]
	strh r1, [r0, 0x12]
	ldr r1, =sub_815DA20
	str r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815DB90

	thumb_func_start sub_815DCA4
sub_815DCA4: @ 815DCA4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	ldr r4, =gUnknown_0203841E
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815DCC4
	adds r0, r2, 0
	bl move_anim_task_del
_0815DCC4:
	movs r0, 0
	strh r0, [r5, 0x8]
	strh r0, [r5, 0xA]
	strh r0, [r5, 0xC]
	ldrh r0, [r4, 0x2]
	strh r0, [r5, 0xE]
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815DCE8
	ldr r0, =gUnknown_02038436
	b _0815DCEA
	.pool
_0815DCE8:
	ldr r0, =gUnknown_02038437
_0815DCEA:
	ldrb r4, [r0]
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x10]
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x12]
	adds r0, r4, 0
	bl sub_80A82E4
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x14]
	ldr r0, =gUnknown_0203841E
	ldrb r0, [r0]
	bl obj_id_for_side_relative_to_move
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	strh r1, [r5, 0x26]
	ldr r2, =gUnknown_085CE74C
	adds r0, r5, 0
	bl sub_80A7CFC
	ldr r0, =sub_815DD48
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815DCA4

	thumb_func_start sub_815DD48
sub_815DD48: @ 815DD48
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
	cmp r0, 0
	beq _0815DD6C
	cmp r0, 0x1
	beq _0815DDCC
	b _0815DDDA
	.pool
_0815DD6C:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	bne _0815DD82
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_815DDE0
_0815DD82:
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0x12
	bne _0815DD92
	adds r0, r5, 0
	movs r1, 0
	bl sub_815DDE0
_0815DD92:
	adds r0, r4, 0
	bl sub_80A7D34
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0815DDDA
	ldrh r0, [r4, 0xE]
	subs r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 16
	cmp r0, 0
	bne _0815DDB4
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815DDDA
_0815DDB4:
	strh r1, [r4, 0xA]
	ldrh r1, [r4, 0x26]
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_085CE74C
	adds r0, r4, 0
	bl sub_80A7CFC
	b _0815DDDA
	.pool
_0815DDCC:
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815DDDA
	adds r0, r5, 0
	bl move_anim_task_del
_0815DDDA:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815DD48

	thumb_func_start sub_815DDE0
sub_815DDE0: @ 815DDE0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r2, =gTasks
	adds r4, r0, r2
	cmp r1, 0
	bne _0815DE08
	movs r1, 0x12
	movs r3, 0xEC
	b _0815DE0C
	.pool
_0815DE08:
	movs r1, 0x1E
	movs r3, 0x14
_0815DE0C:
	mov r2, sp
	ldrh r0, [r4, 0x10]
	subs r0, r1
	strh r0, [r2]
	ldrh r0, [r4, 0x10]
	subs r0, r1
	subs r0, 0x4
	strh r0, [r2, 0x2]
	ldrh r0, [r4, 0x10]
	adds r0, r1
	strh r0, [r2, 0x4]
	ldrh r0, [r4, 0x10]
	adds r0, r1
	adds r0, 0x4
	strh r0, [r2, 0x6]
	add r2, sp, 0x8
	lsls r1, r3, 24
	asrs r1, 24
	ldrh r0, [r4, 0x12]
	adds r0, r1
	strh r0, [r2]
	ldrh r0, [r4, 0x12]
	adds r0, r1
	adds r0, 0x6
	strh r0, [r2, 0x2]
	movs r5, 0
	mov r8, r2
	ldr r7, =gSprites
_0815DE44:
	lsls r0, r5, 1
	add r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x1
	ands r0, r5
	lsls r0, 1
	add r0, r8
	movs r3, 0
	ldrsh r2, [r0, r3]
	ldrb r3, [r4, 0x14]
	subs r3, 0x5
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gUnknown_085CE76C
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _0815DE98
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r7
	movs r0, 0
	strh r0, [r1, 0x2E]
	movs r0, 0x2
	cmp r5, 0x1
	bhi _0815DE86
	movs r2, 0x2
	negs r2, r2
	adds r0, r2, 0
_0815DE86:
	strh r0, [r1, 0x30]
	ldr r0, =0x0000ffff
	strh r0, [r1, 0x32]
	strh r6, [r1, 0x34]
	movs r0, 0x2
	strh r0, [r1, 0x36]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
_0815DE98:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _0815DE44
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815DDE0

	thumb_func_start sub_815DEBC
sub_815DEBC: @ 815DEBC
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x32]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	ble _0815DF02
	ldr r3, =gTasks
	movs r0, 0x36
	ldrsh r1, [r4, r0]
	lsls r1, 1
	movs r0, 0x34
	ldrsh r2, [r4, r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r3, 0x8
	adds r1, r3
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	adds r0, r4, 0
	bl DestroySprite
_0815DF02:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815DEBC

	thumb_func_start sub_815DF0C
sub_815DF0C: @ 815DF0C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	movs r0, 0
	strh r0, [r4, 0x8]
	ldr r1, =gUnknown_0203841E
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0xA]
	ldrb r0, [r1]
	bl obj_id_for_side_relative_to_move
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	adds r0, r1
	strh r0, [r4, 0xC]
	ldr r0, =sub_815DF64
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815DF0C

	thumb_func_start sub_815DF64
sub_815DF64: @ 815DF64
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0815DFB4
	ldrh r0, [r4, 0xC]
	ldr r2, =gUnknown_085CE784
	movs r3, 0x8
	ldrsh r1, [r4, r3]
	lsls r1, 1
	adds r1, r2
	ldrh r3, [r1]
	movs r1, 0x10
	movs r2, 0x8
	bl BlendPalette
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x17
	ble _0815DFA4
	movs r0, 0
	strh r0, [r4, 0x8]
_0815DFA4:
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
	strh r0, [r4, 0xA]
	b _0815DFC6
	.pool
_0815DFB4:
	ldrh r0, [r4, 0xC]
	movs r1, 0x10
	movs r2, 0
	movs r3, 0
	bl BlendPalette
	adds r0, r5, 0
	bl move_anim_task_del
_0815DFC6:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815DF64

	thumb_func_start sub_815DFCC
sub_815DFCC: @ 815DFCC
	push {lr}
	sub sp, 0x1C
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0xD0
	lsls r2, 1
	ldr r1, =gUnknown_02038436
	ldrb r3, [r1]
	ldr r1, =gUnknown_0203841E
	ldrb r1, [r1]
	str r1, [sp]
	movs r1, 0xA
	str r1, [sp, 0x4]
	movs r1, 0x2
	str r1, [sp, 0x8]
	movs r1, 0x1E
	str r1, [sp, 0xC]
	ldr r1, =gUnknown_08C2DC68
	str r1, [sp, 0x10]
	ldr r1, =gUnknown_08C2DDC4
	str r1, [sp, 0x14]
	ldr r1, =gUnknown_08C2DDA4
	str r1, [sp, 0x18]
	movs r1, 0
	bl sub_8117854
	add sp, 0x1C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815DFCC

	thumb_func_start sub_815E01C
sub_815E01C: @ 815E01C
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gUnknown_02038436
	ldrb r0, [r6]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815E038
	ldr r1, =gUnknown_0203841E
	ldrh r0, [r1]
	negs r0, r0
	strh r0, [r1]
_0815E038:
	ldrb r0, [r6]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	ldr r4, =gUnknown_0203841E
	lsrs r0, 24
	ldrh r1, [r4]
	adds r0, r1
	strh r0, [r5, 0x20]
	ldrb r0, [r6]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x2]
	adds r0, r1
	strh r0, [r5, 0x22]
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815E080
	movs r0, 0xA0
	lsls r0, 2
	strh r0, [r5, 0x2E]
	ldr r0, =0x0000fd80
	strh r0, [r5, 0x30]
	b _0815E0A8
	.pool
_0815E080:
	cmp r0, 0x1
	bne _0815E09A
	adds r2, r5, 0
	adds r2, 0x3F
	ldrb r0, [r2]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0xA0
	lsls r0, 2
	strh r0, [r5, 0x2E]
	strh r0, [r5, 0x30]
	b _0815E0A8
_0815E09A:
	adds r0, r5, 0
	movs r1, 0x1
	bl StartObjectImageAnim
	movs r0, 0xA0
	lsls r0, 2
	strh r0, [r5, 0x2E]
_0815E0A8:
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0815E0C8
	ldrh r0, [r5, 0x2E]
	negs r0, r0
	strh r0, [r5, 0x2E]
	adds r2, r5, 0
	adds r2, 0x3F
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
_0815E0C8:
	ldr r0, =sub_815E0DC
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815E01C

	thumb_func_start sub_815E0DC
sub_815E0DC: @ 815E0DC
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	ldrh r1, [r2, 0x3A]
	adds r0, r1
	strh r0, [r2, 0x3A]
	ldrh r1, [r2, 0x30]
	ldrh r3, [r2, 0x3C]
	adds r1, r3
	strh r1, [r2, 0x3C]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r2, 0x24]
	lsls r1, 16
	asrs r1, 24
	strh r1, [r2, 0x26]
	ldrh r0, [r2, 0x38]
	adds r0, 0x1
	strh r0, [r2, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xE
	bne _0815E110
	adds r0, r2, 0
	bl move_anim_8072740
_0815E110:
	pop {r0}
	bx r0
	thumb_func_end sub_815E0DC

	thumb_func_start sub_815E114
sub_815E114: @ 815E114
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r6, r1, r0
	bl sub_80A4DF0
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _0815E144
	movs r0, 0x8
	strh r0, [r6, 0x12]
	movs r0, 0x3
	strh r0, [r6, 0x14]
	movs r0, 0x1
	strh r0, [r6, 0x16]
	b _0815E14E
	.pool
_0815E144:
	movs r0, 0xC
	strh r0, [r6, 0x12]
	movs r0, 0x3
	strh r0, [r6, 0x14]
	strh r1, [r6, 0x16]
_0815E14E:
	ldr r5, =gUnknown_02038436
	ldrb r0, [r5]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0815E188
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	adds r4, r0, 0
	ldrb r0, [r5]
	movs r1, 0
	bl sub_80A861C
	lsls r4, 24
	lsrs r4, 24
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _0815E17C
	adds r0, 0x3
_0815E17C:
	asrs r0, 2
	adds r0, r4, r0
	b _0815E1AC
	.pool
_0815E188:
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	adds r4, r0, 0
	ldrb r0, [r5]
	movs r1, 0
	bl sub_80A861C
	lsls r4, 24
	lsrs r4, 24
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _0815E1A8
	adds r0, 0x3
_0815E1A8:
	asrs r0, 2
	subs r0, r4, r0
_0815E1AC:
	strh r0, [r6, 0x1E]
	ldr r5, =gUnknown_02038436
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	adds r4, r0, 0
	ldrb r0, [r5]
	movs r1, 0
	bl sub_80A861C
	lsls r4, 24
	lsrs r4, 24
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _0815E1D0
	adds r0, 0x3
_0815E1D0:
	asrs r0, 2
	subs r0, r4, r0
	strh r0, [r6, 0x20]
	ldr r4, =gUnknown_02038437
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x22]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x24]
	ldr r0, =sub_815E20C
	str r0, [r6]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815E114

	thumb_func_start sub_815E20C
sub_815E20C: @ 815E20C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	cmp r1, 0
	beq _0815E238
	cmp r1, 0x1
	bne _0815E230
	b _0815E330
_0815E230:
	b _0815E33E
	.pool
_0815E238:
	ldrh r0, [r5, 0xA]
	adds r0, 0x1
	strh r0, [r5, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _0815E33E
	strh r1, [r5, 0xA]
	movs r1, 0x1E
	ldrsh r0, [r5, r1]
	movs r2, 0x20
	ldrsh r1, [r5, r2]
	movs r3, 0x22
	ldrsh r2, [r5, r3]
	movs r4, 0x24
	ldrsh r3, [r5, r4]
	ldrb r4, [r5, 0x12]
	str r4, [sp]
	ldrb r4, [r5, 0xC]
	str r4, [sp, 0x4]
	add r4, sp, 0x10
	str r4, [sp, 0x8]
	adds r4, 0x2
	str r4, [sp, 0xC]
	bl sub_815E34C
	movs r6, 0
	mov r8, r4
	ldr r4, =gSprites
_0815E272:
	add r0, sp, 0x10
	movs r2, 0
	ldrsh r1, [r0, r2]
	mov r3, r8
	movs r0, 0
	ldrsh r2, [r3, r0]
	ldr r0, =gUnknown_085CE7EC
	movs r3, 0x23
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x40
	beq _0815E306
	movs r1, 0x16
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0815E2C6
	cmp r6, 0
	bne _0815E2B4
	lsls r2, r3, 4
	adds r1, r2, r3
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r5, 0x14]
	negs r0, r0
	strh r0, [r1, 0x26]
	strh r0, [r1, 0x24]
	b _0815E2EE
	.pool
_0815E2B4:
	lsls r2, r3, 4
	adds r1, r2, r3
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r5, 0x14]
	strh r0, [r1, 0x26]
	ldrh r0, [r5, 0x14]
	strh r0, [r1, 0x24]
	b _0815E2EE
_0815E2C6:
	cmp r6, 0
	bne _0815E2DC
	lsls r2, r3, 4
	adds r1, r2, r3
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r5, 0x14]
	negs r0, r0
	strh r0, [r1, 0x24]
	ldrh r0, [r5, 0x14]
	b _0815E2EC
_0815E2DC:
	lsls r2, r3, 4
	adds r1, r2, r3
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r5, 0x14]
	strh r0, [r1, 0x24]
	ldrh r0, [r5, 0x14]
	negs r0, r0
_0815E2EC:
	strh r0, [r1, 0x26]
_0815E2EE:
	ldr r1, =gSprites
	adds r0, r2, r3
	lsls r0, 2
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x2E]
	strh r7, [r0, 0x30]
	movs r1, 0xA
	strh r1, [r0, 0x32]
	ldrh r0, [r5, 0x1C]
	adds r0, 0x1
	strh r0, [r5, 0x1C]
_0815E306:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x1
	bls _0815E272
	ldrh r2, [r5, 0xC]
	movs r3, 0xC
	ldrsh r1, [r5, r3]
	movs r4, 0x12
	ldrsh r0, [r5, r4]
	cmp r1, r0
	bne _0815E324
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
_0815E324:
	adds r0, r2, 0x1
	strh r0, [r5, 0xC]
	b _0815E33E
	.pool
_0815E330:
	movs r1, 0x1C
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0815E33E
	adds r0, r7, 0
	bl move_anim_task_del
_0815E33E:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_815E20C

	thumb_func_start sub_815E34C
sub_815E34C: @ 815E34C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r4, [sp, 0x28]
	ldr r5, [sp, 0x2C]
	ldr r6, [sp, 0x30]
	mov r9, r6
	ldr r6, [sp, 0x34]
	mov r10, r6
	lsls r0, 16
	lsrs r0, 16
	mov r12, r0
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp]
	lsls r2, 16
	lsrs r2, 16
	adds r7, r2, 0
	lsls r3, 16
	lsrs r3, 16
	str r3, [sp, 0x4]
	lsls r4, 24
	lsrs r6, r4, 24
	lsls r5, 24
	lsrs r5, 24
	mov r8, r5
	cmp r5, 0
	bne _0815E394
	mov r2, r9
	strh r0, [r2]
	mov r6, r10
	strh r1, [r6]
	b _0815E3F2
_0815E394:
	cmp r5, r6
	bcc _0815E3A2
	mov r0, r9
	strh r2, [r0]
	mov r1, r10
	strh r3, [r1]
	b _0815E3F2
_0815E3A2:
	subs r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	mov r2, r12
	lsls r1, r2, 16
	asrs r1, 16
	lsls r5, r1, 8
	lsls r0, r7, 16
	asrs r0, 16
	subs r0, r1
	lsls r0, 8
	adds r1, r6, 0
	bl __divsi3
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	adds r5, r0
	ldr r2, [sp]
	lsls r1, r2, 16
	asrs r1, 16
	lsls r4, r1, 8
	ldr r2, [sp, 0x4]
	lsls r0, r2, 16
	asrs r0, 16
	subs r0, r1
	lsls r0, 8
	adds r1, r6, 0
	bl __divsi3
	mov r6, r8
	muls r6, r0
	adds r0, r6, 0
	adds r4, r0
	asrs r5, 8
	mov r0, r9
	strh r5, [r0]
	asrs r4, 8
	mov r1, r10
	strh r4, [r1]
_0815E3F2:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_815E34C

	thumb_func_start sub_815E404
sub_815E404: @ 815E404
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x24
	ble _0815E43A
	ldr r3, =gTasks
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	lsls r1, 1
	movs r0, 0x30
	ldrsh r2, [r4, r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r3, 0x8
	adds r1, r3
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	adds r0, r4, 0
	bl DestroySprite
_0815E43A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815E404

	thumb_func_start sub_815E444
sub_815E444: @ 815E444
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, =gUnknown_0203841E
	ldrh r0, [r1]
	strh r0, [r4, 0x20]
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0x22]
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x32]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x36]
	ldrh r0, [r1, 0x8]
	strh r0, [r4, 0x2E]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl oamt_set_x3A_32
	ldr r0, =sub_80A70C0
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815E444

	thumb_func_start sub_815E47C
sub_815E47C: @ 815E47C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r0, 2
	add r0, r9
	lsls r0, 3
	ldr r1, =gTasks
	adds r7, r0, r1
	ldr r0, =gUnknown_02038436
	mov r10, r0
	ldrb r0, [r0]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7, 0x1E]
	mov r1, r10
	ldrb r0, [r1]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7, 0x20]
	ldr r0, =gUnknown_02038437
	mov r8, r0
	ldrb r0, [r0]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7, 0x22]
	mov r1, r8
	ldrb r0, [r1]
	movs r1, 0x3
	bl sub_80A5C6C
	adds r4, r0, 0
	mov r1, r8
	ldrb r0, [r1]
	movs r1, 0
	bl sub_80A861C
	lsls r4, 24
	lsrs r4, 24
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _0815E4EE
	adds r0, 0x3
_0815E4EE:
	asrs r0, 2
	adds r0, r4, r0
	strh r0, [r7, 0x24]
	ldr r4, =gUnknown_085CE84C
	movs r0, 0x1E
	ldrsh r5, [r7, r0]
	movs r1, 0x20
	ldrsh r6, [r7, r1]
	mov r1, r8
	ldrb r0, [r1]
	bl sub_80A82E4
	adds r3, r0, 0
	subs r3, 0x5
	lsls r3, 24
	lsrs r3, 24
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7, 0x26]
	cmp r0, 0x40
	beq _0815E5B8
	ldr r4, =gSprites
	movs r0, 0x26
	ldrsh r1, [r7, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x10
	strh r1, [r0, 0x2E]
	movs r0, 0x26
	ldrsh r1, [r7, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r7, 0x22]
	strh r1, [r0, 0x32]
	movs r0, 0x26
	ldrsh r1, [r7, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r7, 0x24]
	strh r1, [r0, 0x36]
	movs r0, 0x26
	ldrsh r1, [r7, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =0x0000ffe0
	strh r1, [r0, 0x38]
	movs r0, 0x26
	ldrsh r1, [r7, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl sub_80A68D4
	mov r1, r10
	ldrb r0, [r1]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815E596
	movs r0, 0x26
	ldrsh r1, [r7, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x1
	bl StartObjectRotScalAnim
_0815E596:
	ldr r0, =sub_815E5CC
	str r0, [r7]
	b _0815E5BE
	.pool
_0815E5B8:
	mov r0, r9
	bl move_anim_task_del
_0815E5BE:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_815E47C

	thumb_func_start sub_815E5CC
sub_815E5CC: @ 815E5CC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	cmp r1, 0x1
	beq _0815E634
	cmp r1, 0x1
	bgt _0815E5F4
	cmp r1, 0
	beq _0815E5FE
	b _0815E6D2
	.pool
_0815E5F4:
	cmp r1, 0x2
	beq _0815E658
	cmp r1, 0x3
	beq _0815E6CC
	b _0815E6D2
_0815E5FE:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0815E6D2
	strh r1, [r4, 0xA]
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl sub_80A6900
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _0815E6D2
	b _0815E6BE
	.pool
_0815E634:
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _0815E6D2
	movs r0, 0
	strh r0, [r4, 0xA]
	strh r0, [r4, 0xC]
	b _0815E6BE
	.pool
_0815E658:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0815E6D2
	movs r0, 0
	strh r0, [r4, 0xA]
	ldrh r2, [r4, 0xC]
	adds r2, 0x1
	strh r2, [r4, 0xC]
	ldr r5, =gSprites
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	movs r0, 0x1
	ands r2, r0
	adds r1, 0x3E
	lsls r2, 2
	ldrb r3, [r1]
	subs r0, 0x6
	ands r0, r3
	orrs r0, r2
	strb r0, [r1]
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0x10
	bne _0815E6D2
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r0, [r0, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl rotscale_free_entry
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	bl DestroySprite
_0815E6BE:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815E6D2
	.pool
_0815E6CC:
	adds r0, r2, 0
	bl move_anim_task_del
_0815E6D2:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815E5CC

	thumb_func_start sub_815E6D8
sub_815E6D8: @ 815E6D8
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_0203841E
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r6, r0, 0
	cmp r1, 0
	bne _0815E6F4
	ldr r0, =gUnknown_02038436
	b _0815E6F6
	.pool
_0815E6F4:
	ldr r0, =gUnknown_02038437
_0815E6F6:
	ldrb r5, [r0]
	ldrh r2, [r4, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x10
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x4]
	adds r1, r6, 0
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x3A]
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	movs r1, 0x1
	cmp r0, 0
	bne _0815E724
	movs r3, 0x1
	negs r3, r3
	adds r1, r3, 0
_0815E724:
	strh r1, [r4, 0x3C]
	adds r0, r5, 0
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x22]
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0815E768
	ldrb r2, [r4, 0x3]
	lsls r1, r2, 26
	lsrs r1, 27
	movs r0, 0x8
	orrs r1, r0
	lsls r1, 1
	subs r0, 0x47
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x3]
	adds r0, r5, 0
	movs r1, 0x4
	bl sub_80A861C
	subs r0, 0x8
	b _0815E772
	.pool
_0815E768:
	adds r0, r5, 0
	movs r1, 0x5
	bl sub_80A861C
	adds r0, 0x8
_0815E772:
	strh r0, [r4, 0x20]
	ldr r0, =sub_815E784
	str r0, [r4, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815E6D8

	thumb_func_start sub_815E784
sub_815E784: @ 815E784
	push {lr}
	adds r2, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r2, r0]
	cmp r1, 0x1
	beq _0815E7CC
	cmp r1, 0x1
	bgt _0815E79A
	cmp r1, 0
	beq _0815E7A4
	b _0815E83C
_0815E79A:
	cmp r1, 0x2
	beq _0815E7DC
	cmp r1, 0x3
	beq _0815E802
	b _0815E83C
_0815E7A4:
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0815E83C
	strh r1, [r2, 0x30]
	ldrh r0, [r2, 0x3C]
	ldrh r1, [r2, 0x24]
	adds r0, r1
	strh r0, [r2, 0x24]
	ldrh r0, [r2, 0x32]
	adds r0, 0x1
	strh r0, [r2, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	bne _0815E83C
	b _0815E7FA
_0815E7CC:
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	bne _0815E83C
	b _0815E7F6
_0815E7DC:
	movs r0, 0x3C
	ldrsh r1, [r2, r0]
	lsls r1, 2
	ldrh r0, [r2, 0x24]
	subs r0, r1
	strh r0, [r2, 0x24]
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	bne _0815E83C
_0815E7F6:
	movs r0, 0
	strh r0, [r2, 0x30]
_0815E7FA:
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	b _0815E83C
_0815E802:
	movs r0, 0x3C
	ldrsh r1, [r2, r0]
	lsls r0, r1, 1
	adds r0, r1
	ldrh r1, [r2, 0x24]
	adds r0, r1
	strh r0, [r2, 0x24]
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	bne _0815E83C
	ldrh r0, [r2, 0x3A]
	subs r0, 0x1
	strh r0, [r2, 0x3A]
	lsls r0, 16
	cmp r0, 0
	beq _0815E836
	movs r0, 0
	strh r0, [r2, 0x30]
	ldrh r0, [r2, 0x2E]
	subs r0, 0x1
	strh r0, [r2, 0x2E]
	b _0815E83C
_0815E836:
	adds r0, r2, 0
	bl move_anim_8072740
_0815E83C:
	pop {r0}
	bx r0
	thumb_func_end sub_815E784

	thumb_func_start sub_815E840
sub_815E840: @ 815E840
	push {r4,lr}
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r2, =gUnknown_0203841E
	movs r3, 0
	ldrsh r0, [r2, r3]
	cmp r0, 0
	bne _0815E85C
	adds r0, r1, 0
	bl move_anim_task_del
	b _0815E884
	.pool
_0815E85C:
	ldr r0, =gTasks
	lsls r4, r1, 2
	adds r4, r1
	lsls r4, 3
	adds r4, r0
	ldrh r0, [r2, 0x2]
	strh r0, [r4, 0x8]
	ldrb r0, [r2]
	bl obj_id_for_side_relative_to_move
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	strh r1, [r4, 0x26]
	ldr r2, =gUnknown_085CE87C
	adds r0, r4, 0
	bl sub_80A7CFC
	ldr r0, =sub_815E898
	str r0, [r4]
_0815E884:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815E840

	thumb_func_start sub_815E898
sub_815E898: @ 815E898
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0815E8F2
	movs r0, 0
	strh r0, [r4, 0xA]
	ldrh r1, [r4, 0xC]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0815E8E0
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x2
	b _0815E8F0
	.pool
_0815E8E0:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000fffe
_0815E8F0:
	strh r1, [r0, 0x24]
_0815E8F2:
	adds r0, r4, 0
	bl sub_80A7D34
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _0815E94E
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r5, [r0, 0x24]
	ldrh r0, [r4, 0x8]
	subs r0, 0x1
	strh r0, [r4, 0x8]
	lsls r0, 16
	cmp r0, 0
	beq _0815E948
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks
	adds r0, r1
	ldrh r1, [r0, 0x26]
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_085CE87C
	bl sub_80A7CFC
	strh r5, [r4, 0xA]
	strh r5, [r4, 0xC]
	b _0815E94E
	.pool
_0815E948:
	adds r0, r6, 0
	bl move_anim_task_del
_0815E94E:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_815E898

	thumb_func_start sub_815E954
sub_815E954: @ 815E954
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gUnknown_0203841E
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0815E970
	ldr r4, =gUnknown_02038436
	b _0815E972
	.pool
_0815E970:
	ldr r4, =gUnknown_02038437
_0815E972:
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A861C
	strh r0, [r5, 0x22]
	movs r1, 0x22
	ldrsh r0, [r5, r1]
	cmp r0, 0x7
	bgt _0815E996
	movs r0, 0x8
	strh r0, [r5, 0x22]
_0815E996:
	movs r2, 0
	strh r2, [r5, 0x2E]
	ldr r1, =gUnknown_0203841E
	ldrh r0, [r1, 0x2]
	strh r0, [r5, 0x30]
	strh r2, [r5, 0x32]
	ldrh r0, [r1, 0x4]
	strh r0, [r5, 0x34]
	ldr r0, =sub_815E9BC
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815E954

	thumb_func_start sub_815E9BC
sub_815E9BC: @ 815E9BC
	push {lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x30
	ldrsh r1, [r3, r2]
	cmp r0, r1
	blt _0815EA10
	movs r0, 0
	strh r0, [r3, 0x2E]
	ldrh r1, [r3, 0x32]
	adds r1, 0x1
	movs r0, 0x1
	ands r1, r0
	strh r1, [r3, 0x32]
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	lsls r1, 2
	ldrb r2, [r0]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	movs r2, 0x32
	ldrsh r0, [r3, r2]
	cmp r0, 0
	beq _0815EA10
	ldrh r0, [r3, 0x34]
	subs r0, 0x1
	strh r0, [r3, 0x34]
	lsls r0, 16
	cmp r0, 0
	bne _0815EA10
	adds r0, r3, 0
	bl move_anim_8072740
_0815EA10:
	pop {r0}
	bx r0
	thumb_func_end sub_815E9BC

	thumb_func_start sub_815EA14
sub_815EA14: @ 815EA14
	push {lr}
	adds r3, r0, 0
	ldr r0, =gUnknown_0203841E
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0815EA44
	ldrb r2, [r3, 0x3]
	lsls r1, r2, 26
	lsrs r1, 27
	movs r0, 0x8
	orrs r1, r0
	lsls r1, 1
	subs r0, 0x47
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x3]
	movs r0, 0x64
	strh r0, [r3, 0x20]
	movs r0, 0x1
	b _0815EA4A
	.pool
_0815EA44:
	movs r0, 0x8C
	strh r0, [r3, 0x20]
	ldr r0, =0x0000ffff
_0815EA4A:
	strh r0, [r3, 0x3C]
	movs r0, 0x38
	strh r0, [r3, 0x22]
	ldr r0, =sub_815EA60
	str r0, [r3, 0x1C]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815EA14

	thumb_func_start sub_815EA60
sub_815EA60: @ 815EA60
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x8
	bls _0815EA6E
	b _0815EC40
_0815EA6E:
	lsls r0, 2
	ldr r1, =_0815EA7C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815EA7C:
	.4byte _0815EAA0
	.4byte _0815EAD2
	.4byte _0815EAE4
	.4byte _0815EB24
	.4byte _0815EB36
	.4byte _0815EB74
	.4byte _0815EBD8
	.4byte _0815EBF8
	.4byte _0815EC1E
_0815EAA0:
	movs r3, 0x3C
	ldrsh r0, [r4, r3]
	lsls r0, 1
	ldrh r1, [r4, 0x22]
	subs r1, r0
	strh r1, [r4, 0x22]
	ldrh r2, [r4, 0x30]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _0815EAC2
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	lsls r1, 1
	ldrh r0, [r4, 0x20]
	subs r0, r1
	strh r0, [r4, 0x20]
_0815EAC2:
	adds r0, r2, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x9
	beq _0815EAD0
	b _0815EC40
_0815EAD0:
	b _0815EC12
_0815EAD2:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	beq _0815EAE2
	b _0815EC40
_0815EAE2:
	b _0815EC12
_0815EAE4:
	ldrh r2, [r4, 0x30]
	adds r2, 0x1
	strh r2, [r4, 0x30]
	movs r3, 0x3C
	ldrsh r1, [r4, r3]
	lsls r0, r1, 1
	adds r0, r1
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldr r3, =gSineTable
	movs r0, 0x30
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 19
	ldrh r1, [r4, 0x3C]
	muls r0, r1
	strh r0, [r4, 0x24]
	lsls r2, 16
	asrs r2, 16
	cmp r2, 0xC
	beq _0815EB1C
	b _0815EC40
_0815EB1C:
	b _0815EC12
	.pool
_0815EB24:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	beq _0815EB34
	b _0815EC40
_0815EB34:
	b _0815EC12
_0815EB36:
	ldrh r2, [r4, 0x30]
	adds r2, 0x1
	strh r2, [r4, 0x30]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	lsls r1, r0, 1
	adds r1, r0
	ldrh r0, [r4, 0x22]
	subs r0, r1
	strh r0, [r4, 0x22]
	ldr r3, =gSineTable
	movs r0, 0x30
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 19
	ldrh r1, [r4, 0x3C]
	muls r0, r1
	strh r0, [r4, 0x24]
	lsls r2, 16
	asrs r2, 16
	cmp r2, 0xC
	bne _0815EC40
	b _0815EC16
	.pool
_0815EB74:
	ldrh r2, [r4, 0x30]
	adds r2, 0x1
	strh r2, [r4, 0x30]
	movs r3, 0x3C
	ldrsh r1, [r4, r3]
	lsls r0, r1, 1
	adds r0, r1
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldr r3, =gSineTable
	movs r0, 0x30
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 19
	ldrh r1, [r4, 0x3C]
	muls r0, r1
	strh r0, [r4, 0x24]
	lsls r2, 16
	asrs r2, 16
	cmp r2, 0xF
	bne _0815EBC0
	ldrh r2, [r4, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x10
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x4]
_0815EBC0:
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	cmp r0, 0x12
	bne _0815EC40
	b _0815EC12
	.pool
_0815EBD8:
	movs r3, 0x3C
	ldrsh r0, [r4, r3]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 1
	ldrh r0, [r4, 0x20]
	adds r1, r0
	strh r1, [r4, 0x20]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x9
	bne _0815EC40
	b _0815EC12
_0815EBF8:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	lsls r0, 1
	ldrh r3, [r4, 0x20]
	adds r0, r3
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _0815EC40
_0815EC12:
	movs r0, 0
	strh r0, [r4, 0x30]
_0815EC16:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0815EC40
_0815EC1E:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	lsls r1, r0, 1
	adds r1, r0
	ldrh r0, [r4, 0x20]
	subs r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	bne _0815EC40
	adds r0, r4, 0
	bl move_anim_8072740
_0815EC40:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_815EA60

	thumb_func_start sub_815EC48
sub_815EC48: @ 815EC48
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r6, r1, r0
	movs r0, 0
	bl obj_id_for_side_relative_to_move
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x26]
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	bne _0815ECD0
	bl battle_type_is_double
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x1
	bne _0815ECB4
	ldr r5, =gUnknown_02038436
	ldrb r0, [r5]
	movs r1, 0
	bl sub_80A5C6C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldrb r1, [r5]
	movs r0, 0x2
	eors r0, r1
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	ble _0815ECAC
	strh r7, [r6, 0x24]
	b _0815ECD4
	.pool
_0815ECAC:
	ldr r0, =0x0000ffff
	b _0815ECD2
	.pool
_0815ECB4:
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0815ECD0
	ldr r0, =0x0000ffff
	b _0815ECD2
	.pool
_0815ECD0:
	movs r0, 0x1
_0815ECD2:
	strh r0, [r6, 0x24]
_0815ECD4:
	ldr r0, =sub_815ECE4
	str r0, [r6]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815EC48

	thumb_func_start sub_815ECE4
sub_815ECE4: @ 815ECE4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r3, r0, r1
	movs r1, 0x8
	ldrsh r0, [r3, r1]
	cmp r0, 0x8
	bls _0815ECFE
	b _0815EE78
_0815ECFE:
	lsls r0, 2
	ldr r1, =_0815ED10
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815ED10:
	.4byte _0815ED34
	.4byte _0815ED46
	.4byte _0815ED78
	.4byte _0815EDA8
	.4byte _0815EDCE
	.4byte _0815EDF8
	.4byte _0815EE08
	.4byte _0815EE28
	.4byte _0815EE60
_0815ED34:
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	beq _0815ED44
	b _0815EE78
_0815ED44:
	b _0815EE50
_0815ED46:
	ldr r2, =gSprites
	movs r1, 0x26
	ldrsh r0, [r3, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r2, 0x24
	ldrsh r0, [r3, r2]
	lsls r2, r0, 1
	adds r2, r0
	ldrh r0, [r1, 0x24]
	subs r0, r2
	strh r0, [r1, 0x24]
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	beq _0815ED72
	b _0815EE78
_0815ED72:
	b _0815EE50
	.pool
_0815ED78:
	ldr r2, =gSprites
	movs r1, 0x26
	ldrsh r0, [r3, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x24
	ldrsh r2, [r3, r0]
	lsls r0, r2, 1
	adds r0, r2
	ldrh r2, [r1, 0x24]
	adds r0, r2
	strh r0, [r1, 0x24]
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	bne _0815EE78
	b _0815EE50
	.pool
_0815EDA8:
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	bne _0815EE78
	movs r0, 0
	strh r0, [r3, 0xA]
	ldrh r1, [r3, 0xC]
	movs r2, 0xC
	ldrsh r0, [r3, r2]
	cmp r0, 0
	bne _0815EE54
	adds r0, r1, 0x1
	strh r0, [r3, 0xC]
	movs r0, 0x1
	strh r0, [r3, 0x8]
	b _0815EE78
_0815EDCE:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r3, 0x24]
	ldrh r2, [r0, 0x24]
	adds r1, r2
	strh r1, [r0, 0x24]
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	bne _0815EE78
	b _0815EE50
	.pool
_0815EDF8:
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	bne _0815EE78
	b _0815EE50
_0815EE08:
	ldr r2, =gSprites
	movs r1, 0x26
	ldrsh r0, [r3, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x24
	ldrsh r2, [r3, r0]
	lsls r2, 2
	ldrh r0, [r1, 0x24]
	subs r0, r2
	b _0815EE40
	.pool
_0815EE28:
	ldr r2, =gSprites
	movs r1, 0x26
	ldrsh r0, [r3, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r2, 0x24
	ldrsh r0, [r3, r2]
	lsls r0, 2
	ldrh r2, [r1, 0x24]
	adds r0, r2
_0815EE40:
	strh r0, [r1, 0x24]
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	bne _0815EE78
_0815EE50:
	movs r0, 0
	strh r0, [r3, 0xA]
_0815EE54:
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
	b _0815EE78
	.pool
_0815EE60:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strh r1, [r0, 0x24]
	adds r0, r4, 0
	bl move_anim_task_del
_0815EE78:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815ECE4

	thumb_func_start sub_815EE84
sub_815EE84: @ 815EE84
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_0203841E
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0815EEA8
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r0, =gUnknown_02038436
	b _0815EEAA
	.pool
_0815EEA8:
	ldr r0, =gUnknown_02038437
_0815EEAA:
	ldrb r0, [r0]
	strh r0, [r4, 0x3C]
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815EECE
	ldrb r0, [r4, 0x3]
	movs r1, 0x3F
	negs r1, r1
	ands r1, r0
	movs r0, 0x10
	orrs r1, r0
	strb r1, [r4, 0x3]
_0815EECE:
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A8328
	movs r2, 0x3
	ands r2, r0
	lsls r2, 2
	ldrb r3, [r4, 0x5]
	movs r1, 0xD
	negs r1, r1
	adds r0, r1, 0
	ands r0, r3
	orrs r0, r2
	strb r0, [r4, 0x5]
	ldrb r0, [r4, 0x1]
	ands r1, r0
	movs r0, 0x4
	orrs r1, r0
	strb r1, [r4, 0x1]
	ldr r0, =sub_815EF08
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815EE84

	thumb_func_start sub_815EF08
sub_815EF08: @ 815EF08
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bls _0815EF16
	b _0815F106
_0815EF16:
	lsls r0, 2
	ldr r1, =_0815EF24
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815EF24:
	.4byte _0815EF38
	.4byte _0815F038
	.4byte _0815F0A0
	.4byte _0815F0B4
	.4byte _0815F100
_0815EF38:
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	cmp r0, 0x5
	bhi _0815EF68
	lsls r0, 2
	ldr r1, =_0815EF50
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815EF50:
	.4byte _0815EF6C
	.4byte _0815EF88
	.4byte _0815EFAA
	.4byte _0815EFC6
	.4byte _0815EF6C
	.4byte _0815EFEC
_0815EF68:
	movs r0, 0
	strh r0, [r4, 0x3A]
_0815EF6C:
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x5
	bl sub_80A861C
	subs r0, 0x4
	lsls r0, 16
	lsrs r5, r0, 16
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x3
	b _0815EFE0
_0815EF88:
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x5
	bl sub_80A861C
	subs r0, 0x4
	lsls r0, 16
	lsrs r5, r0, 16
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl sub_80A861C
	adds r0, 0x4
	b _0815EFE6
_0815EFAA:
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x4
	bl sub_80A861C
	adds r0, 0x4
	lsls r0, 16
	lsrs r5, r0, 16
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x3
	b _0815EFE0
_0815EFC6:
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x4
	bl sub_80A861C
	adds r0, 0x4
	lsls r0, 16
	lsrs r5, r0, 16
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
_0815EFE0:
	bl sub_80A861C
	subs r0, 0x4
_0815EFE6:
	lsls r0, 16
	lsrs r1, r0, 16
	b _0815F00C
_0815EFEC:
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r5, r0, 24
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r1, r0, 24
_0815F00C:
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	cmp r0, 0x4
	bne _0815F018
	movs r0, 0x18
	b _0815F022
_0815F018:
	cmp r0, 0x5
	bne _0815F020
	movs r0, 0x6
	b _0815F022
_0815F020:
	movs r0, 0xC
_0815F022:
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x20]
	strh r0, [r4, 0x30]
	strh r5, [r4, 0x32]
	ldrh r0, [r4, 0x22]
	strh r0, [r4, 0x34]
	strh r1, [r4, 0x36]
	adds r0, r4, 0
	bl obj_translate_based_on_private_1_2_3_4
	b _0815F0F8
_0815F038:
	adds r0, r4, 0
	bl sub_80A6F3C
	lsls r0, 24
	cmp r0, 0
	beq _0815F106
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	beq _0815F070
	cmp r0, 0x5
	beq _0815F090
	ldrh r0, [r4, 0x24]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	movs r1, 0
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x26]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	strh r1, [r4, 0x26]
	strh r1, [r4, 0x24]
	strh r1, [r4, 0x2E]
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	b _0815F088
_0815F070:
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	movs r1, 0
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x26]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	strh r1, [r4, 0x26]
	strh r1, [r4, 0x24]
	strh r1, [r4, 0x38]
_0815F088:
	ldrh r0, [r4, 0x3A]
	adds r0, 0x1
	strh r0, [r4, 0x3A]
	b _0815F106
_0815F090:
	movs r0, 0
	strh r0, [r4, 0x2E]
	movs r1, 0x10
	strh r1, [r4, 0x30]
	strh r0, [r4, 0x32]
	movs r0, 0x3
	strh r0, [r4, 0x38]
	b _0815F106
_0815F0A0:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _0815F106
	movs r0, 0
	strh r0, [r4, 0x38]
	b _0815F106
_0815F0B4:
	ldrh r1, [r4, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0815F0C6
	ldrh r0, [r4, 0x30]
	subs r0, 0x1
	strh r0, [r4, 0x30]
	b _0815F0CC
_0815F0C6:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
_0815F0CC:
	ldrh r1, [r4, 0x32]
	lsls r1, 8
	ldrh r0, [r4, 0x30]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x20
	bne _0815F106
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_0815F0F8:
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	b _0815F106
_0815F100:
	adds r0, r4, 0
	bl move_anim_8072740
_0815F106:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815EF08

	thumb_func_start sub_815F10C
sub_815F10C: @ 815F10C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	movs r2, 0x2E
	ldrsh r1, [r4, r2]
	subs r0, r1
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	muls r0, r1
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	bl __divsi3
	adds r5, r0, 0
	strh r5, [r4, 0x24]
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	movs r2, 0x30
	ldrsh r1, [r4, r2]
	subs r0, r1
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	muls r0, r1
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	bl __divsi3
	adds r3, r0, 0
	strh r3, [r4, 0x26]
	ldrh r1, [r4, 0x38]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0815F16A
	ldr r0, =gUnknown_085CE3A0
	ldrh r1, [r4, 0x20]
	adds r1, r5
	lsls r1, 16
	asrs r1, 16
	ldrh r2, [r4, 0x22]
	adds r2, r3
	lsls r2, 16
	asrs r2, 16
	movs r3, 0x5
	bl CreateSprite
_0815F16A:
	movs r0, 0x38
	ldrsh r1, [r4, r0]
	movs r2, 0x36
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _0815F17C
	adds r0, r4, 0
	bl move_anim_8072740
_0815F17C:
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815F10C

	thumb_func_start sub_815F18C
sub_815F18C: @ 815F18C
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gUnknown_02038437
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0815F1B8
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	beq _0815F1D0
_0815F1B8:
	ldr r2, =gUnknown_0203841E
	ldrh r1, [r5, 0x20]
	ldrh r0, [r2]
	subs r0, r1, r0
	strh r0, [r5, 0x2E]
	ldrh r0, [r2, 0x4]
	subs r1, r0
	b _0815F1DE
	.pool
_0815F1D0:
	ldr r2, =gUnknown_0203841E
	ldrh r1, [r5, 0x20]
	ldrh r0, [r2]
	adds r0, r1, r0
	strh r0, [r5, 0x2E]
	ldrh r0, [r2, 0x4]
	adds r1, r0
_0815F1DE:
	strh r1, [r5, 0x32]
	adds r3, r2, 0
	ldrh r1, [r5, 0x22]
	ldrh r2, [r3, 0x2]
	adds r2, r1, r2
	strh r2, [r5, 0x30]
	ldrh r0, [r3, 0x6]
	adds r1, r0
	strh r1, [r5, 0x34]
	ldrh r0, [r3, 0x8]
	strh r0, [r5, 0x36]
	ldrh r0, [r5, 0x2E]
	strh r0, [r5, 0x20]
	strh r2, [r5, 0x22]
	ldr r0, =sub_815F10C
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815F18C

	thumb_func_start sub_815F20C
sub_815F20C: @ 815F20C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0
	bl obj_id_for_side_relative_to_move
	lsls r0, 24
	lsrs r5, r0, 24
	adds r2, r5, 0
	ldr r0, =gTasks
	mov r9, r0
	lsls r7, r6, 2
	adds r0, r7, r6
	lsls r0, 3
	mov r8, r0
	mov r4, r8
	add r4, r9
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815F254
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A7270
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r4, 0xA]
	strh r0, [r4, 0xC]
	b _0815F2A0
	.pool
_0815F254:
	cmp r0, 0x1
	bne _0815F2AC
	ldrh r0, [r4, 0xA]
	adds r0, 0x60
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xC]
	subs r0, 0xD
	strh r0, [r4, 0xC]
	movs r2, 0xA
	ldrsh r1, [r4, r2]
	movs r0, 0xC
	ldrsh r2, [r4, r0]
	adds r0, r5, 0
	movs r3, 0
	bl obj_id_set_rotscale
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x9
	bne _0815F310
	movs r0, 0
	strh r0, [r4, 0xE]
	adds r0, r5, 0
	bl sub_80A7344
	ldr r1, =gSprites
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_0815F2A0:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815F310
	.pool
_0815F2AC:
	ldr r4, =gUnknown_02038436
	ldrb r0, [r4]
	movs r1, 0
	bl refresh_graphics_maybe
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	beq _0815F2EE
	ldr r3, =gSprites
	ldr r2, =gBankSpriteIds
	ldrb r0, [r4]
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r3, 0
	adds r1, 0x10
	adds r0, r1
	ldr r1, =gUnknown_082FF6C0
	str r1, [r0]
	ldrb r0, [r4]
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0
	bl StartObjectRotScalAnim
_0815F2EE:
	mov r4, r9
	adds r3, r7, 0
	ldr r5, =sub_815F330
	movs r1, 0xF
	mov r2, r8
	adds r0, r4, r2
	adds r0, 0x26
	movs r2, 0
_0815F2FE:
	strh r2, [r0]
	subs r0, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _0815F2FE
	adds r0, r3, r6
	lsls r0, 3
	adds r0, r4
	str r5, [r0]
_0815F310:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815F20C

	thumb_func_start sub_815F330
sub_815F330: @ 815F330
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0
	bl obj_id_for_side_relative_to_move
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r5, [r4, r0]
	cmp r5, 0x1
	beq _0815F394
	cmp r5, 0x1
	bgt _0815F360
	cmp r5, 0
	beq _0815F36A
	b _0815F482
	.pool
_0815F360:
	cmp r5, 0x2
	beq _0815F400
	cmp r5, 0x3
	beq _0815F43C
	b _0815F482
_0815F36A:
	ldr r0, =gSprites
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	adds r1, r0
	ldr r0, =0x0000ff38
	strh r0, [r1, 0x26]
	movs r0, 0xC8
	strh r0, [r1, 0x24]
	adds r1, 0x3E
	ldrb r2, [r1]
	subs r0, 0xCD
	ands r0, r2
	strb r0, [r1]
	strh r5, [r4, 0x1C]
	b _0815F42E
	.pool
_0815F394:
	ldrh r1, [r4, 0x1C]
	adds r1, 0x70
	movs r5, 0
	strh r1, [r4, 0x1C]
	ldr r2, =gSprites
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 2
	adds r2, r0, r2
	lsls r1, 16
	asrs r1, 24
	ldrh r3, [r2, 0x26]
	adds r1, r3
	strh r1, [r2, 0x26]
	movs r1, 0x22
	ldrsh r0, [r2, r1]
	movs r3, 0x26
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r1, 0x20
	negs r1, r1
	cmp r0, r1
	blt _0815F3C4
	strh r5, [r2, 0x24]
_0815F3C4:
	movs r1, 0x26
	ldrsh r0, [r2, r1]
	cmp r0, 0
	ble _0815F3CE
	strh r5, [r2, 0x26]
_0815F3CE:
	movs r3, 0x26
	ldrsh r0, [r2, r3]
	cmp r0, 0
	bne _0815F482
	movs r0, 0x40
	negs r0, r0
	bl sub_80A5178
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x7D
	bl audio_play_and_stuff
	ldr r1, =0xfffff800
	adds r0, r1, 0
	ldrh r2, [r4, 0x1C]
	adds r0, r2
	strh r0, [r4, 0x1C]
	b _0815F42E
	.pool
_0815F400:
	ldrh r0, [r4, 0x1C]
	subs r0, 0x70
	strh r0, [r4, 0x1C]
	lsls r0, 16
	cmp r0, 0
	bge _0815F410
	movs r0, 0
	strh r0, [r4, 0x1C]
_0815F410:
	ldr r0, =gSprites
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	adds r1, r0
	ldrh r2, [r4, 0x1C]
	lsls r2, 16
	asrs r2, 24
	ldrh r0, [r1, 0x26]
	subs r0, r2
	strh r0, [r1, 0x26]
	movs r3, 0x1C
	ldrsh r0, [r4, r3]
	cmp r0, 0
	bne _0815F482
_0815F42E:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815F482
	.pool
_0815F43C:
	ldrh r0, [r4, 0x1C]
	adds r0, 0x70
	strh r0, [r4, 0x1C]
	ldr r2, =gSprites
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	adds r1, r2
	lsls r0, 16
	asrs r0, 24
	ldrh r2, [r1, 0x26]
	adds r0, r2
	strh r0, [r1, 0x26]
	lsls r0, 16
	cmp r0, 0
	ble _0815F460
	movs r0, 0
	strh r0, [r1, 0x26]
_0815F460:
	movs r3, 0x26
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bne _0815F482
	movs r0, 0x40
	negs r0, r0
	bl sub_80A5178
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x7D
	bl audio_play_and_stuff
	adds r0, r6, 0
	bl move_anim_task_del
_0815F482:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815F330

	thumb_func_start sub_815F48C
sub_815F48C: @ 815F48C
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gUnknown_02038437
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0815F4B8
	ldrb r0, [r4]
	bl sub_80A82E4
	subs r0, 0x2
	adds r1, r5, 0
	adds r1, 0x43
	strb r0, [r1]
	ldr r4, =0x0000ff70
	b _0815F4C8
	.pool
_0815F4B8:
	ldrb r0, [r4]
	bl sub_80A82E4
	adds r0, 0x2
	adds r1, r5, 0
	adds r1, 0x43
	strb r0, [r1]
	ldr r4, =0x0000ffa0
_0815F4C8:
	ldr r0, =gUnknown_02038437
	ldrb r0, [r0]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	strh r4, [r5, 0x26]
	ldr r0, =sub_815F4F0
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815F48C

	thumb_func_start sub_815F4F0
sub_815F4F0: @ 815F4F0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bls _0815F4FE
	b _0815F61A
_0815F4FE:
	lsls r0, 2
	ldr r1, =_0815F50C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815F50C:
	.4byte _0815F520
	.4byte _0815F544
	.4byte _0815F584
	.4byte _0815F5B4
	.4byte _0815F5E0
_0815F520:
	ldrh r0, [r4, 0x26]
	adds r0, 0xA
	strh r0, [r4, 0x26]
	lsls r0, 16
	cmp r0, 0
	blt _0815F61A
	movs r0, 0x3F
	bl sub_80A5178
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xCD
	bl audio_play_and_stuff
	movs r0, 0
	strh r0, [r4, 0x26]
	b _0815F5D8
_0815F544:
	ldrh r1, [r4, 0x30]
	adds r1, 0x4
	movs r5, 0
	strh r1, [r4, 0x30]
	ldr r2, =gSineTable
	movs r3, 0x30
	ldrsh r0, [r4, r3]
	lsls r0, 1
	adds r0, r2
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 19
	negs r0, r0
	strh r0, [r4, 0x26]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x7F
	ble _0815F61A
	movs r0, 0x3F
	bl sub_80A5178
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xCD
	bl audio_play_and_stuff
	strh r5, [r4, 0x30]
	strh r5, [r4, 0x26]
	b _0815F5D8
	.pool
_0815F584:
	ldrh r1, [r4, 0x30]
	adds r1, 0x6
	movs r3, 0
	strh r1, [r4, 0x30]
	ldr r2, =gSineTable
	movs r5, 0x30
	ldrsh r0, [r4, r5]
	lsls r0, 1
	adds r0, r2
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 20
	negs r0, r0
	strh r0, [r4, 0x26]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x7F
	ble _0815F61A
	strh r3, [r4, 0x30]
	strh r3, [r4, 0x26]
	b _0815F5D8
	.pool
_0815F5B4:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _0815F61A
	movs r0, 0x3F
	bl sub_80A5178
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xC0
	bl audio_play_and_stuff
	movs r0, 0
	strh r0, [r4, 0x30]
_0815F5D8:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0815F61A
_0815F5E0:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _0815F61A
	movs r0, 0
	strh r0, [r4, 0x30]
	ldrh r1, [r4, 0x32]
	adds r1, 0x1
	strh r1, [r4, 0x32]
	movs r0, 0x1
	ands r1, r0
	adds r3, r4, 0
	adds r3, 0x3E
	lsls r1, 2
	ldrb r2, [r3]
	subs r0, 0x6
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x7
	bne _0815F61A
	adds r0, r4, 0
	bl move_anim_8072740
_0815F61A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815F4F0

	thumb_func_start sub_815F620
sub_815F620: @ 815F620
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	bl sub_80A4DF0
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0
	bne _0815F66E
	movs r0, 0x1
	bl duplicate_obj_of_side_rel2move_in_transparent_mode
	lsls r0, 16
	lsrs r1, r0, 16
	mov r10, r1
	asrs r6, r0, 16
	cmp r6, 0
	blt _0815F66E
	movs r0, 0x1
	bl duplicate_obj_of_side_rel2move_in_transparent_mode
	lsls r0, 16
	lsrs r1, r0, 16
	mov r9, r1
	asrs r1, r0, 16
	cmp r1, 0
	bge _0815F67C
	lsls r0, r6, 4
	adds r0, r6
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl obj_delete_but_dont_free_vram
_0815F66E:
	mov r0, r8
	bl move_anim_task_del
	b _0815F780
	.pool
_0815F67C:
	ldr r4, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r5, r0, r4
	ldrh r0, [r5, 0x24]
	adds r0, 0x18
	strh r0, [r5, 0x24]
	lsls r0, r6, 4
	adds r0, r6
	lsls r0, 2
	adds r6, r0, r4
	ldrh r0, [r6, 0x24]
	subs r0, 0x18
	strh r0, [r6, 0x24]
	strh r7, [r5, 0x2E]
	strh r7, [r6, 0x2E]
	strh r7, [r5, 0x30]
	strh r7, [r6, 0x30]
	strh r7, [r5, 0x32]
	strh r7, [r6, 0x32]
	movs r0, 0x10
	strh r0, [r5, 0x34]
	ldr r0, =0x0000fff0
	strh r0, [r6, 0x34]
	strh r7, [r5, 0x36]
	movs r0, 0x80
	strh r0, [r6, 0x36]
	movs r0, 0x18
	strh r0, [r5, 0x38]
	strh r0, [r6, 0x38]
	mov r0, r8
	strh r0, [r5, 0x3A]
	strh r0, [r6, 0x3A]
	strh r7, [r5, 0x3C]
	strh r7, [r6, 0x3C]
	ldr r2, =gTasks
	mov r1, r8
	lsls r3, r1, 2
	adds r0, r3, r1
	lsls r0, 3
	adds r0, r2
	movs r1, 0x2
	strh r1, [r0, 0x8]
	ldr r0, =gUnknown_020244D0
	ldr r1, [r0]
	ldr r0, =gUnknown_02038437
	ldrb r0, [r0]
	ldr r1, [r1]
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	adds r7, r4, 0
	mov r12, r3
	cmp r0, 0
	bne _0815F720
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r2, r6, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	b _0815F736
	.pool
_0815F720:
	adds r1, r5, 0
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	adds r1, r6, 0
	adds r1, 0x3E
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
_0815F736:
	mov r1, r9
	lsls r0, r1, 16
	asrs r0, 16
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r4, r2, r7
	ldrb r1, [r4, 0x1]
	movs r3, 0xD
	negs r3, r3
	adds r0, r3, 0
	ands r0, r1
	strb r0, [r4, 0x1]
	mov r1, r10
	lsls r0, r1, 16
	asrs r0, 16
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r4, r1, r7
	ldrb r0, [r4, 0x1]
	ands r3, r0
	strb r3, [r4, 0x1]
	adds r3, r7, 0
	adds r3, 0x1C
	adds r2, r3
	ldr r0, =sub_815F7C4
	str r0, [r2]
	adds r1, r3
	str r0, [r1]
	mov r0, r12
	add r0, r8
	lsls r0, 3
	ldr r1, =gTasks
	adds r0, r1
	ldr r1, =sub_815F79C
	str r1, [r0]
_0815F780:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815F620

	thumb_func_start sub_815F79C
sub_815F79C: @ 815F79C
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0815F7BA
	adds r0, r2, 0
	bl move_anim_task_del
_0815F7BA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815F79C

	thumb_func_start sub_815F7C4
sub_815F7C4: @ 815F7C4
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0815F80E
	movs r0, 0
	strh r0, [r4, 0x30]
	ldr r0, =gUnknown_020244D0
	ldr r1, [r0]
	ldr r0, =gUnknown_02038437
	ldrb r0, [r0]
	ldr r1, [r1]
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0815F80E
	adds r3, r4, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsls r1, r2, 29
	lsrs r1, 31
	movs r0, 0x1
	eors r1, r0
	ands r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0815F80E:
	ldrh r0, [r4, 0x34]
	ldrh r1, [r4, 0x36]
	adds r0, r1
	movs r5, 0
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x36]
	movs r2, 0x36
	ldrsh r0, [r4, r2]
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl Cos
	strh r0, [r4, 0x24]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0815F840
	cmp r0, 0x1
	beq _0815F858
	b _0815F896
	.pool
_0815F840:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3C
	bne _0815F896
	strh r5, [r4, 0x32]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0815F896
_0815F858:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	cmp r0, 0
	ble _0815F896
	strh r5, [r4, 0x32]
	ldrh r0, [r4, 0x38]
	subs r0, 0x2
	strh r0, [r4, 0x38]
	lsls r0, 16
	cmp r0, 0
	bge _0815F896
	ldr r3, =gTasks
	movs r2, 0x3C
	ldrsh r1, [r4, r2]
	lsls r1, 1
	movs r0, 0x3A
	ldrsh r2, [r4, r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r3, 0x8
	adds r1, r3
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	adds r0, r4, 0
	bl obj_delete_but_dont_free_vram
_0815F896:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815F7C4

	thumb_func_start sub_815F8A0
sub_815F8A0: @ 815F8A0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r3, =gUnknown_0203841E
	movs r2, 0
	strh r2, [r3, 0xE]
	ldr r1, =gUnknown_0203841A
	ldrb r0, [r1]
	ldrb r1, [r1]
	adds r0, r1, 0
	subs r0, 0x3D
	lsls r0, 24
	lsrs r0, 24
	adds r2, r1, 0
	cmp r0, 0x1E
	bhi _0815F8C4
	movs r0, 0x1
	strh r0, [r3, 0xE]
_0815F8C4:
	adds r0, r2, 0
	subs r0, 0x5C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6C
	bhi _0815F8D4
	movs r0, 0x2
	strh r0, [r3, 0xE]
_0815F8D4:
	lsls r0, r1, 24
	lsrs r0, 24
	cmp r0, 0xC8
	bls _0815F8E0
	movs r0, 0x3
	strh r0, [r3, 0xE]
_0815F8E0:
	adds r0, r4, 0
	bl move_anim_task_del
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815F8A0

	thumb_func_start sub_815F8F4
sub_815F8F4: @ 815F8F4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0x4
	bls _0815F91A
	b _0815FE68
_0815F91A:
	lsls r0, 2
	ldr r1, =_0815F92C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815F92C:
	.4byte _0815F940
	.4byte _0815F9F4
	.4byte _0815FBE8
	.4byte _0815FD08
	.4byte _0815FD8C
_0815F940:
	movs r0, 0
	bl obj_id_for_side_relative_to_move
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	mov r2, r8
	lsls r4, r2, 2
	adds r0, r4, r2
	lsls r0, 3
	adds r6, r0, r1
	movs r3, 0x80
	lsls r3, 4
	adds r0, r3, 0
	ldrh r1, [r6, 0xA]
	adds r0, r1
	strh r0, [r6, 0xA]
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	mov r9, r4
	cmp r0, 0
	bne _0815F998
	ldr r2, =gSprites
	lsls r3, r7, 4
	adds r1, r3, r7
	lsls r1, 2
	adds r1, r2
	ldrh r0, [r6, 0xA]
	lsls r0, 16
	asrs r0, 24
	ldrh r4, [r1, 0x24]
	adds r0, r4
	strh r0, [r1, 0x24]
	b _0815F9B2
	.pool
_0815F998:
	ldr r3, =gSprites
	lsls r4, r7, 4
	adds r2, r4, r7
	lsls r2, 2
	adds r2, r3
	ldrh r1, [r6, 0xA]
	lsls r1, 16
	asrs r1, 24
	ldrh r0, [r2, 0x24]
	subs r0, r1
	strh r0, [r2, 0x24]
	adds r2, r3, 0
	adds r3, r4, 0
_0815F9B2:
	ldr r1, =gTasks
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r4, r0, r1
	ldrb r0, [r4, 0xA]
	strh r0, [r4, 0xA]
	adds r1, r3, r7
	lsls r1, 2
	adds r1, r2
	ldrh r0, [r1, 0x24]
	ldrh r1, [r1, 0x20]
	adds r0, r1
	lsls r0, 16
	movs r1, 0x80
	lsls r1, 14
	adds r0, r1
	movs r1, 0x98
	lsls r1, 17
	cmp r0, r1
	bhi _0815F9DE
	b _0815FE68
_0815F9DE:
	movs r0, 0
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815FE68
	.pool
_0815F9F4:
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	beq _0815FA28
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldr r2, [r0, 0x8]
	mov r10, r2
	ldr r3, [r0, 0xC]
	mov r9, r3
	ldrh r6, [r0]
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl sub_80A82E4
	lsls r0, 24
	lsrs r4, r0, 24
	movs r7, 0
	b _0815FB4E
	.pool
_0815FA28:
	ldr r4, =gUnknown_02038436
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0815FAC8
	ldr r7, =gBattlePartyID
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r7
	ldrh r0, [r0]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	movs r1, 0
	bl GetMonData
	mov r10, r0
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r7
	ldrh r0, [r0]
	muls r0, r6
	adds r0, r5
	movs r1, 0x1
	bl GetMonData
	mov r9, r0
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldrb r2, [r4]
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r1, r0, r1
	ldrh r0, [r1, 0x2]
	cmp r0, 0
	bne _0815FA9C
	lsls r0, r2, 1
	adds r0, r7
	ldrh r0, [r0]
	muls r0, r6
	adds r0, r5
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r6, r0, 16
	b _0815FA9E
	.pool
_0815FA9C:
	ldrh r6, [r1, 0x2]
_0815FA9E:
	movs r0, 0x1
	bl obj_id_for_side_relative_to_move
	ldr r2, =gSprites
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x43
	ldrb r0, [r1]
	adds r0, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	movs r7, 0
	movs r5, 0x88
	lsls r5, 1
	b _0815FB50
	.pool
_0815FAC8:
	ldr r7, =gBattlePartyID
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r7
	ldrh r0, [r0]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gEnemyParty
	adds r0, r5
	movs r1, 0
	bl GetMonData
	mov r10, r0
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r7
	ldrh r0, [r0]
	muls r0, r6
	adds r0, r5
	movs r1, 0x1
	bl GetMonData
	mov r9, r0
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldrb r2, [r4]
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r1, r0, r1
	ldrh r0, [r1, 0x2]
	cmp r0, 0
	bne _0815FB2C
	lsls r0, r2, 1
	adds r0, r7
	ldrh r0, [r0]
	muls r0, r6
	adds r0, r5
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r6, r0, 16
	b _0815FB2E
	.pool
_0815FB2C:
	ldrh r6, [r1, 0x2]
_0815FB2E:
	movs r0, 0x1
	bl obj_id_for_side_relative_to_move
	ldr r2, =gSprites
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x43
	ldrb r0, [r1]
	subs r0, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	movs r7, 0x1
_0815FB4E:
	ldr r5, =0x0000ffe0
_0815FB50:
	ldr r0, =gUnknown_02038437
	ldrb r0, [r0]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	lsls r3, r5, 16
	asrs r3, 16
	str r0, [sp]
	str r4, [sp, 0x4]
	mov r4, r10
	str r4, [sp, 0x8]
	mov r0, r9
	str r0, [sp, 0xC]
	ldr r4, =gUnknown_02038436
	ldrb r0, [r4]
	str r0, [sp, 0x10]
	movs r0, 0
	str r0, [sp, 0x14]
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0
	bl sub_80A8394
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_020244D0
	ldr r1, [r0]
	ldrb r0, [r4]
	ldr r1, [r1]
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0, 0x2]
	cmp r0, 0
	beq _0815FBBA
	ldr r1, =gSprites
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	orrs r0, r1
	ldr r3, =0x00007fff
	movs r1, 0x10
	movs r2, 0x6
	bl BlendPalette
_0815FBBA:
	ldr r0, =gTasks
	mov r3, r8
	lsls r1, r3, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	strh r5, [r1, 0x26]
	b _0815FD7E
	.pool
_0815FBE8:
	ldr r1, =gTasks
	mov r0, r8
	lsls r4, r0, 2
	adds r0, r4, r0
	lsls r0, 3
	adds r6, r0, r1
	ldrh r0, [r6, 0x26]
	lsls r0, 24
	lsrs r5, r0, 24
	movs r1, 0x80
	lsls r1, 4
	adds r0, r1, 0
	ldrh r2, [r6, 0xA]
	adds r0, r2
	strh r0, [r6, 0xA]
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	mov r9, r4
	cmp r0, 0
	bne _0815FC40
	ldr r3, =gSprites
	lsls r4, r5, 4
	adds r2, r4, r5
	lsls r2, 2
	adds r2, r3
	ldrh r1, [r6, 0xA]
	lsls r1, 16
	asrs r1, 24
	ldrh r0, [r2, 0x24]
	subs r0, r1
	strh r0, [r2, 0x24]
	adds r2, r3, 0
	adds r3, r4, 0
	b _0815FC56
	.pool
_0815FC40:
	ldr r2, =gSprites
	lsls r3, r5, 4
	adds r1, r3, r5
	lsls r1, 2
	adds r1, r2
	ldrh r0, [r6, 0xA]
	lsls r0, 16
	asrs r0, 24
	ldrh r4, [r1, 0x24]
	adds r0, r4
	strh r0, [r1, 0x24]
_0815FC56:
	ldr r1, =gTasks
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r6, r0, r1
	ldrb r0, [r6, 0xA]
	strh r0, [r6, 0xA]
	adds r1, r3, r5
	lsls r1, 2
	adds r1, r2
	ldrh r0, [r1, 0x24]
	ldrh r1, [r1, 0x20]
	adds r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
	movs r1, 0x24
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0815FCD6
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0815FCB4
	lsls r4, r5, 16
	asrs r4, 16
	ldr r0, =gUnknown_02038437
	ldrb r0, [r0]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bge _0815FCD6
	b _0815FCCA
	.pool
_0815FCB4:
	lsls r4, r5, 16
	asrs r4, 16
	ldr r0, =gUnknown_02038437
	ldrb r0, [r0]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	ble _0815FCD6
_0815FCCA:
	ldrh r0, [r6, 0x24]
	adds r0, 0x1
	strh r0, [r6, 0x24]
	ldr r1, =gUnknown_0203841E
	ldr r0, =0x0000ffff
	strh r0, [r1, 0xE]
_0815FCD6:
	lsls r0, r5, 16
	movs r2, 0x80
	lsls r2, 14
	adds r0, r2
	movs r1, 0x98
	lsls r1, 17
	cmp r0, r1
	bhi _0815FCE8
	b _0815FE68
_0815FCE8:
	ldr r0, =gTasks
	mov r1, r9
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r0, 0
	strh r0, [r1, 0xA]
	b _0815FD7E
	.pool
_0815FD08:
	movs r0, 0
	bl obj_id_for_side_relative_to_move
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	mov r3, r8
	lsls r4, r3, 2
	adds r0, r4, r3
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x26]
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	ldr r5, =gSprites
	adds r0, r5
	bl sub_80A8610
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	mov r9, r4
	cmp r0, 0
	bne _0815FD60
	lsls r1, r7, 4
	adds r1, r7
	lsls r1, 2
	adds r1, r5
	ldrh r0, [r1, 0x20]
	negs r0, r0
	subs r0, 0x20
	strh r0, [r1, 0x24]
	b _0815FD74
	.pool
_0815FD60:
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	adds r0, r5
	ldrh r2, [r0, 0x20]
	movs r4, 0x88
	lsls r4, 1
	adds r1, r4, 0
	subs r1, r2
	strh r1, [r0, 0x24]
_0815FD74:
	ldr r0, =gTasks
	mov r1, r9
	add r1, r8
	lsls r1, 3
	adds r1, r0
_0815FD7E:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0815FE68
	.pool
_0815FD8C:
	movs r0, 0
	bl obj_id_for_side_relative_to_move
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	mov r0, r8
	lsls r4, r0, 2
	adds r0, r4, r0
	lsls r0, 3
	adds r2, r0, r1
	movs r1, 0x80
	lsls r1, 4
	adds r0, r1, 0
	ldrh r3, [r2, 0xA]
	adds r0, r3
	strh r0, [r2, 0xA]
	ldr r0, =gUnknown_02038436
	mov r10, r0
	ldrb r0, [r0]
	str r2, [sp, 0x18]
	bl GetBankSide
	lsls r0, 24
	mov r9, r4
	ldr r2, [sp, 0x18]
	cmp r0, 0
	bne _0815FE0C
	ldr r1, =gSprites
	lsls r5, r7, 4
	adds r0, r5, r7
	lsls r0, 2
	adds r6, r0, r1
	ldrh r0, [r2, 0xA]
	lsls r0, 16
	asrs r0, 24
	ldrh r1, [r6, 0x24]
	adds r0, r1
	strh r0, [r6, 0x24]
	movs r2, 0x24
	ldrsh r4, [r6, r2]
	movs r3, 0x20
	ldrsh r0, [r6, r3]
	adds r4, r0
	mov r1, r10
	ldrb r0, [r1]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r3, r5, 0
	cmp r4, r0
	blt _0815FE44
	movs r2, 0
	strh r2, [r6, 0x24]
	b _0815FE44
	.pool
_0815FE0C:
	ldr r1, =gSprites
	lsls r5, r7, 4
	adds r0, r5, r7
	lsls r0, 2
	adds r6, r0, r1
	ldrh r1, [r2, 0xA]
	lsls r1, 16
	asrs r1, 24
	ldrh r0, [r6, 0x24]
	subs r0, r1
	strh r0, [r6, 0x24]
	movs r3, 0x24
	ldrsh r4, [r6, r3]
	movs r1, 0x20
	ldrsh r0, [r6, r1]
	adds r4, r0
	mov r2, r10
	ldrb r0, [r2]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r3, r5, 0
	cmp r4, r0
	bgt _0815FE44
	movs r4, 0
	strh r4, [r6, 0x24]
_0815FE44:
	ldr r1, =gTasks
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0, 0xA]
	strh r1, [r0, 0xA]
	ldr r1, =gSprites
	adds r0, r3, r7
	lsls r0, 2
	adds r0, r1
	movs r1, 0x24
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0815FE68
	mov r0, r8
	bl move_anim_task_del
_0815FE68:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815F8F4

	thumb_func_start sub_815FE80
sub_815FE80: @ 815FE80
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0815FE92
	cmp r0, 0x1
	beq _0815FF3A
	b _0815FFBC
_0815FE92:
	ldr r0, =gUnknown_0203841E
	movs r2, 0xE
	ldrsh r1, [r0, r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0815FF2C
	movs r0, 0x3F
	bl sub_80A5178
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x7A
	bl audio_play_and_stuff
	ldr r0, =gUnknown_02038437
	ldrb r0, [r0]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x10
	strh r0, [r4, 0x22]
	ldr r0, =0x0000ffe0
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815FFBC
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	bne _0815FFBC
	movs r0, 0x1
	bl obj_id_for_side_relative_to_move
	ldr r2, =gSprites
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x43
	ldrb r0, [r1]
	subs r0, 0x1
	adds r1, r4, 0
	adds r1, 0x43
	strb r0, [r1]
	b _0815FFBC
	.pool
_0815FF2C:
	adds r0, r4, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	b _0815FFBC
_0815FF3A:
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r2, 0x2E
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r2, [r4, 0x30]
	adds r0, r2, 0x5
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7F
	ble _0815FF6E
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	adds r0, r2, 0
	subs r0, 0x7A
	strh r0, [r4, 0x30]
_0815FF6E:
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	ldrh r1, [r4, 0x32]
	adds r0, r1
	strh r0, [r4, 0x32]
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0815FF9C
	ldrh r2, [r4, 0x32]
	lsls r1, r2, 16
	asrs r1, 24
	ldrh r0, [r4, 0x24]
	subs r0, r1
	strh r0, [r4, 0x24]
	adds r1, r2, 0
	b _0815FFA8
	.pool
_0815FF9C:
	ldrh r1, [r4, 0x32]
	lsls r0, r1, 16
	asrs r0, 24
	ldrh r2, [r4, 0x24]
	adds r0, r2
	strh r0, [r4, 0x24]
_0815FFA8:
	movs r0, 0xFF
	ands r0, r1
	strh r0, [r4, 0x32]
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, 0x2
	bne _0815FFBC
	adds r0, r4, 0
	bl move_anim_8072740
_0815FFBC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_815FE80

	thumb_func_start sub_815FFC4
sub_815FFC4: @ 815FFC4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r2, 0x26
	ldrsh r0, [r0, r2]
	adds r3, r1, 0
	cmp r0, 0x4
	bls _0815FFE0
	b _08160132
_0815FFE0:
	lsls r0, 2
	ldr r1, =_0815FFF4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815FFF4:
	.4byte _08160008
	.4byte _08160058
	.4byte _081600B4
	.4byte _081600CC
	.4byte _08160132
_08160008:
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r0, =gUnknown_02038437
	ldrb r0, [r0]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r2, r0, 0
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r1
	movs r0, 0x6
	strh r0, [r1, 0x8]
	cmp r5, r2
	ble _0816003E
	negs r0, r0
	strh r0, [r1, 0x8]
_0816003E:
	strh r5, [r1, 0xA]
	strh r2, [r1, 0xC]
	ldrh r0, [r1, 0x26]
	adds r0, 0x1
	strh r0, [r1, 0x26]
	b _08160150
	.pool
_08160058:
	ldr r1, =gBankSpriteIds
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	adds r0, r1
	ldrb r2, [r0]
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r1, r0, r1
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r2, r0, r3
	ldrh r0, [r2, 0x8]
	ldrh r3, [r1, 0x24]
	adds r0, r3
	strh r0, [r1, 0x24]
	movs r3, 0x8
	ldrsh r0, [r2, r3]
	cmp r0, 0
	ble _081600A0
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	movs r3, 0x24
	ldrsh r1, [r1, r3]
	adds r0, r1
	movs r3, 0xC
	ldrsh r1, [r2, r3]
	b _08160126
	.pool
_081600A0:
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	movs r3, 0x24
	ldrsh r1, [r1, r3]
	adds r0, r1
	movs r3, 0xC
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bgt _08160150
	b _0816012A
_081600B4:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r3
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	negs r1, r1
	strh r1, [r0, 0x8]
	ldrh r1, [r0, 0x26]
	adds r1, 0x1
	strh r1, [r0, 0x26]
	b _08160150
_081600CC:
	ldr r1, =gBankSpriteIds
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	adds r0, r1
	ldrb r2, [r0]
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r1, r0, r1
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r2, r0, r3
	ldrh r0, [r2, 0x8]
	ldrh r3, [r1, 0x24]
	adds r0, r3
	strh r0, [r1, 0x24]
	movs r3, 0x8
	ldrsh r0, [r2, r3]
	cmp r0, 0
	bge _08160118
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	movs r3, 0x24
	ldrsh r1, [r1, r3]
	adds r0, r1
	movs r3, 0xA
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bgt _08160150
	b _0816012A
	.pool
_08160118:
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	movs r3, 0x24
	ldrsh r1, [r1, r3]
	adds r0, r1
	movs r3, 0xA
	ldrsh r1, [r2, r3]
_08160126:
	cmp r0, r1
	blt _08160150
_0816012A:
	ldrh r0, [r2, 0x26]
	adds r0, 0x1
	strh r0, [r2, 0x26]
	b _08160150
_08160132:
	ldr r1, =gBankSpriteIds
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	adds r0, r1
	ldrb r2, [r0]
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x24]
	adds r0, r4, 0
	bl move_anim_task_del
_08160150:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815FFC4

	thumb_func_start sub_8160164
sub_8160164: @ 8160164
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	movs r0, 0
	bl obj_id_for_side_relative_to_move
	lsls r0, 24
	lsrs r0, 24
	movs r5, 0
	strh r0, [r4, 0xE]
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	movs r2, 0x1
	negs r2, r2
	adds r1, r2, 0
	cmp r0, 0
	bne _08160198
	movs r1, 0x1
_08160198:
	strh r1, [r4, 0x10]
	ldr r2, =gSprites
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x22]
	strh r0, [r4, 0x14]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x20]
	strh r0, [r4, 0x12]
	strh r5, [r4, 0x1A]
	strh r5, [r4, 0x1E]
	movs r0, 0x1
	strh r0, [r4, 0x1C]
	strh r5, [r4, 0x20]
	ldr r0, =sub_81601DC
	str r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8160164

	thumb_func_start sub_81601DC
sub_81601DC: @ 81601DC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _08160284
	cmp r0, 0x1
	bgt _08160204
	cmp r0, 0
	beq _0816020A
	b _081602DA
	.pool
_08160204:
	cmp r0, 0x2
	beq _081602D4
	b _081602DA
_0816020A:
	ldrh r0, [r4, 0x1E]
	adds r0, 0x8
	movs r2, 0xFF
	ands r0, r2
	strh r0, [r4, 0x1E]
	ldr r5, =gSprites
	movs r6, 0xE
	ldrsh r0, [r4, r6]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldr r3, =gSineTable
	movs r6, 0x1E
	ldrsh r0, [r4, r6]
	lsls r0, 1
	adds r0, r3
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 21
	strh r0, [r1, 0x24]
	ldrh r0, [r4, 0x1A]
	adds r0, 0x2
	ands r0, r2
	strh r0, [r4, 0x1A]
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r5
	movs r6, 0x1A
	ldrsh r0, [r4, r6]
	lsls r0, 1
	adds r0, r3
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 19
	ldrh r1, [r4, 0x10]
	muls r0, r1
	ldrh r1, [r4, 0x12]
	adds r0, r1
	strh r0, [r2, 0x20]
	movs r6, 0x1A
	ldrsh r0, [r4, r6]
	cmp r0, 0
	bne _081602DA
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrh r1, [r4, 0x12]
	strh r1, [r0, 0x20]
	b _081602C4
	.pool
_08160284:
	ldrh r0, [r4, 0x1E]
	adds r0, 0x8
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x1E]
	ldr r3, =gSprites
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldr r2, =gSineTable
	movs r5, 0x1E
	ldrsh r0, [r4, r5]
	lsls r0, 1
	adds r0, r2
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 21
	strh r0, [r1, 0x24]
	movs r6, 0x1E
	ldrsh r2, [r4, r6]
	cmp r2, 0
	bne _081602DA
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	strh r2, [r1, 0x24]
_081602C4:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _081602DA
	.pool
_081602D4:
	adds r0, r2, 0
	bl move_anim_task_del
_081602DA:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81601DC

	thumb_func_start sub_81602E0
sub_81602E0: @ 81602E0
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_02038437
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	ldrh r0, [r4, 0x2E]
	ldrh r1, [r4, 0x30]
	adds r0, r1
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x30]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x14
	bl Cos
	strh r0, [r4, 0x24]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x14
	bl Sin
	strh r0, [r4, 0x26]
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08160326
	adds r0, r4, 0
	bl move_anim_8072740
_08160326:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81602E0

	thumb_func_start sub_8160338
sub_8160338: @ 8160338
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_02038437
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0816037C
	ldr r2, =gUnknown_0203841E
	ldrh r0, [r4, 0x20]
	ldrh r1, [r2]
	subs r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r2, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldr r0, =0x0000fff5
	strh r0, [r4, 0x2E]
	movs r0, 0xC0
	strh r0, [r4, 0x30]
	adds r0, r4, 0
	movs r1, 0x1
	bl StartObjectRotScalAnim
	b _08160396
	.pool
_0816037C:
	movs r0, 0xB
	strh r0, [r4, 0x2E]
	movs r0, 0xC0
	strh r0, [r4, 0x30]
	ldr r1, =gUnknown_0203841E
	ldrh r0, [r1]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	ldrh r0, [r1, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
_08160396:
	ldr r0, =sub_81602E0
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8160338

	thumb_func_start sub_81603A8
sub_81603A8: @ 81603A8
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gUnknown_02038436
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A861C
	strh r0, [r5, 0x22]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF
	bgt _081603D2
	movs r0, 0x10
	strh r0, [r5, 0x22]
_081603D2:
	movs r0, 0
	strh r0, [r5, 0x3A]
	movs r1, 0x10
	strh r1, [r5, 0x3C]
	ldr r0, =sub_81603F4
	str r0, [r5, 0x1C]
	lsls r1, 8
	movs r0, 0x52
	bl SetGpuReg
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81603A8

	thumb_func_start sub_81603F4
sub_81603F4: @ 81603F4
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	cmp r1, 0x1
	beq _0816046C
	cmp r1, 0x1
	bgt _0816040A
	cmp r1, 0
	beq _08160414
	b _081604E8
_0816040A:
	cmp r1, 0x2
	beq _08160482
	cmp r1, 0x3
	beq _081604E2
	b _081604E8
_08160414:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _081604E8
	strh r1, [r4, 0x2E]
	ldrh r1, [r4, 0x30]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0816043E
	ldrh r2, [r4, 0x3A]
	movs r3, 0x3A
	ldrsh r0, [r4, r3]
	cmp r0, 0xF
	bgt _0816044C
	adds r0, r2, 0x1
	strh r0, [r4, 0x3A]
	b _0816044C
_0816043E:
	ldrh r2, [r4, 0x3C]
	movs r3, 0x3C
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _0816044C
	subs r0, r2, 0x1
	strh r0, [r4, 0x3C]
_0816044C:
	adds r0, r1, 0x1
	strh r0, [r4, 0x30]
	ldrh r1, [r4, 0x3C]
	lsls r1, 8
	ldrh r0, [r4, 0x3A]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081604E8
	b _081604DA
_0816046C:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bne _081604E8
	strh r1, [r4, 0x2E]
	strh r1, [r4, 0x30]
	b _081604DA
_08160482:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _081604E8
	movs r0, 0
	strh r0, [r4, 0x2E]
	ldrh r1, [r4, 0x30]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _081604AE
	ldrh r2, [r4, 0x3A]
	movs r3, 0x3A
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _081604BC
	subs r0, r2, 0x1
	strh r0, [r4, 0x3A]
	b _081604BC
_081604AE:
	ldrh r2, [r4, 0x3C]
	movs r3, 0x3C
	ldrsh r0, [r4, r3]
	cmp r0, 0xF
	bgt _081604BC
	adds r0, r2, 0x1
	strh r0, [r4, 0x3C]
_081604BC:
	adds r0, r1, 0x1
	strh r0, [r4, 0x30]
	ldrh r1, [r4, 0x3C]
	lsls r1, 8
	ldrh r0, [r4, 0x3A]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0x10
	bne _081604E8
_081604DA:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	b _081604E8
_081604E2:
	adds r0, r4, 0
	bl move_anim_8074EE0
_081604E8:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81603F4

	thumb_func_start sub_81604F0
sub_81604F0: @ 81604F0
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r2, =gUnknown_0203841E
	movs r0, 0
	strh r0, [r2, 0xE]
	ldr r0, =gUnknown_0203841C
	ldrh r1, [r0]
	movs r0, 0x60
	ands r0, r1
	cmp r0, 0
	beq _08160514
	movs r0, 0x1
	b _08160536
	.pool
_08160514:
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	beq _08160520
	movs r0, 0x2
	b _08160536
_08160520:
	movs r0, 0x18
	ands r0, r1
	cmp r0, 0
	beq _0816052C
	movs r0, 0x3
	b _08160536
_0816052C:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08160538
	movs r0, 0x4
_08160536:
	strh r0, [r2, 0xE]
_08160538:
	adds r0, r3, 0
	bl move_anim_task_del
	pop {r0}
	bx r0
	thumb_func_end sub_81604F0

	thumb_func_start sub_8160544
sub_8160544: @ 8160544
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	movs r0, 0
	strh r0, [r4, 0x8]
	ldr r0, =gUnknown_0203841E
	ldrb r0, [r0]
	bl obj_id_for_side_relative_to_move
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	strh r1, [r4, 0x26]
	ldr r2, =gUnknown_085CE9C8
	adds r0, r4, 0
	bl sub_80A7CFC
	ldr r0, =sub_816058C
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8160544

	thumb_func_start sub_816058C
sub_816058C: @ 816058C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r2, =gTasks
	adds r3, r0, r2
	ldrh r0, [r3, 0x8]
	adds r1, r0, 0x1
	movs r5, 0
	strh r1, [r3, 0x8]
	subs r0, 0x10
	lsls r0, 16
	lsrs r0, 16
	adds r6, r2, 0
	cmp r0, 0x16
	bhi _081605F0
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _08160600
	strh r5, [r3, 0xA]
	ldrh r0, [r3, 0xC]
	adds r0, 0x1
	strh r0, [r3, 0xC]
	movs r5, 0x1
	ands r0, r5
	cmp r0, 0
	bne _081605F0
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x24]
	b _08160600
	.pool
_081605F0:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r5, [r0, 0x24]
_08160600:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r6
	bl sub_80A7D34
	lsls r0, 24
	cmp r0, 0
	bne _08160618
	adds r0, r4, 0
	bl move_anim_task_del
_08160618:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816058C

	thumb_func_start sub_8160624
sub_8160624: @ 8160624
	push {lr}
	bl LoadOamFromSprites
	bl ProcessObjectCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_8160624

	thumb_func_start sub_8160638
sub_8160638: @ 8160638
	push {lr}
	sub sp, 0x4
	bl script_env_2_enable
	ldr r0, =sub_8160664
	movs r1, 0xA
	bl CreateTask
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8160638

	thumb_func_start sub_8160664
sub_8160664: @ 8160664
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08160688
	ldr r0, =sub_81606A0
	bl SetMainCallback2
	ldr r1, =gUnknown_03005DAC
	ldr r0, =sub_80AF168
	str r0, [r1]
	adds r0, r4, 0
	bl DestroyTask
_08160688:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8160664

	thumb_func_start sub_81606A0
sub_81606A0: @ 81606A0
	push {r4-r6,lr}
	bl ResetAllObjectData
	bl ResetObjectPaletteAllocator
	bl ResetTasks
	bl clear_scheduled_bg_copies_to_vram
	ldr r6, =gUnknown_0203BC34
	movs r0, 0x8C
	lsls r0, 1
	bl AllocZeroed
	str r0, [r6]
	ldr r1, =gUnknown_020375E0
	ldrh r1, [r1]
	adds r0, 0x44
	movs r5, 0
	strb r1, [r0]
	ldr r0, =sub_8160624
	bl SetVBlankCallback
	bl sub_81607EC
	movs r0, 0
	bl sub_81D2824
	ldr r4, =gUnknown_0203BC38
	movs r0, 0
	strh r5, [r4]
	strh r5, [r4, 0x2]
	strb r0, [r4, 0x4]
	bl sub_8161280
	ldr r0, =gUnknown_085CEBB0
	bl LoadObjectPic
	ldr r0, =gUnknown_085CEBB8
	bl LoadTaggedObjectPalette
	bl sub_81610B8
	ldr r0, =gUnknown_03006310
	ldrh r1, [r4]
	ldrh r2, [r4, 0x2]
	bl ListMenuInit
	ldr r1, [r6]
	movs r2, 0x89
	lsls r2, 1
	adds r1, r2
	strb r0, [r1]
	movs r0, 0
	movs r1, 0
	movs r2, 0x2
	bl FillPalette
	ldr r0, =sub_816082C
	bl SetMainCallback2
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81606A0

	thumb_func_start sub_8160740
sub_8160740: @ 8160740
	push {r4,r5,lr}
	bl ResetAllObjectData
	bl ResetObjectPaletteAllocator
	bl ResetTasks
	bl clear_scheduled_bg_copies_to_vram
	ldr r5, =gUnknown_0203BC34
	movs r0, 0x8C
	lsls r0, 1
	bl AllocZeroed
	str r0, [r5]
	movs r1, 0x1C
	strb r1, [r0]
	ldr r0, [r5]
	ldr r1, =gUnknown_020375E0
	ldrh r1, [r1]
	adds r0, 0x44
	strb r1, [r0]
	ldr r0, [r5]
	ldr r1, =gUnknown_020375E2
	ldrh r1, [r1]
	adds r0, 0x45
	strb r1, [r0]
	ldr r0, =sub_8160624
	bl SetVBlankCallback
	bl sub_81607EC
	ldr r4, =gUnknown_0203BC38
	ldrb r0, [r4, 0x4]
	bl sub_81D2824
	bl sub_8161280
	ldr r0, =gUnknown_085CEBB0
	bl LoadObjectPic
	ldr r0, =gUnknown_085CEBB8
	bl LoadTaggedObjectPalette
	bl sub_81610B8
	ldr r0, =gUnknown_03006310
	ldrh r1, [r4]
	ldrh r2, [r4, 0x2]
	bl ListMenuInit
	ldr r1, [r5]
	movs r2, 0x89
	lsls r2, 1
	adds r1, r2
	strb r0, [r1]
	movs r0, 0
	movs r1, 0
	movs r2, 0x2
	bl FillPalette
	ldr r0, =sub_816082C
	bl SetMainCallback2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8160740

	thumb_func_start sub_81607EC
sub_81607EC: @ 81607EC
	push {lr}
	bl sub_8121DA0
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085CEC28
	movs r0, 0
	movs r2, 0x2
	bl InitBgsFromTemplates
	bl sub_8121E10
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81607EC

	thumb_func_start sub_816082C
sub_816082C: @ 816082C
	push {lr}
	bl sub_8160868
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl do_scheduled_bg_tilemap_copies_to_vram
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_816082C

	thumb_func_start sub_816084C
sub_816084C: @ 816084C
	push {r4,lr}
	adds r1, r0, 0
	ldr r4, =gStringVar4
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	bl sub_81D2BF4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816084C

	thumb_func_start sub_8160868
sub_8160868: @ 8160868
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	ldr r1, =gUnknown_0203BC34
	ldr r0, [r1]
	ldrb r0, [r0]
	adds r7, r1, 0
	cmp r0, 0x21
	bls _0816087E
	b _08160E8A
_0816087E:
	lsls r0, 2
	ldr r1, =_08160890
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08160890:
	.4byte _08160918
	.4byte _08160932
	.4byte _0816094C
	.4byte _08160954
	.4byte _0816095C
	.4byte _08160964
	.4byte _08160980
	.4byte _08160E8A
	.4byte _08160988
	.4byte _081609A8
	.4byte _08160E8A
	.4byte _08160E8A
	.4byte _08160A44
	.4byte _08160A64
	.4byte _08160CB8
	.4byte _08160CD8
	.4byte _08160AB8
	.4byte _08160AD0
	.4byte _08160AEC
	.4byte _08160C1C
	.4byte _08160C48
	.4byte _08160C98
	.4byte _08160CA6
	.4byte _08160E8A
	.4byte _08160B2C
	.4byte _08160B60
	.4byte _08160B80
	.4byte _08160BDC
	.4byte _08160CFC
	.4byte _08160D48
	.4byte _08160E0C
	.4byte _08160E38
	.4byte _08160E58
	.4byte _08160E70
_08160918:
	ldr r1, [r7]
	ldrb r0, [r1]
	adds r0, 0x1
	movs r4, 0
	strb r0, [r1]
	movs r0, 0
	bl render_previous_quest_text
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0
	b _08160CAE
_08160932:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08160940
	b _08160E8A
_08160940:
	ldr r1, [r7]
	movs r0, 0x4
	b _08160E88
	.pool
_0816094C:
	ldr r1, [r7]
	ldrb r0, [r1]
	adds r0, 0x1
	b _08160E88
_08160954:
	movs r0, 0
	bl render_previous_quest_text
	b _0816096A
_0816095C:
	movs r0, 0
	bl sub_8160F50
	b _08160E8A
_08160964:
	movs r0, 0
	bl sub_8161074
_0816096A:
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	bl sub_81611AC
	b _08160E8A
	.pool
_08160980:
	movs r0, 0x1
	bl sub_8160F50
	b _08160E8A
_08160988:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	beq _08160994
	b _08160E8A
_08160994:
	bl sub_81D2C50
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	b _08160E88
	.pool
_081609A8:
	bl sub_8198C58
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	bne _08160A0A
	ldr r5, =gUnknown_0203BC34
	ldr r0, [r5]
	adds r0, 0x44
	ldrb r1, [r0]
	movs r0, 0x64
	adds r4, r1, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	bl sub_8161054
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl pokemon_moveset_pad_
	lsls r0, 16
	ldr r1, =0xffff0000
	cmp r0, r1
	beq _08160A04
	ldr r0, =gUnknown_085EF8E4
	bl sub_816084C
	ldr r1, =gUnknown_020375E0
	movs r0, 0x1
	strh r0, [r1]
	ldr r1, [r5]
	movs r0, 0x1F
	b _08160E88
	.pool
_08160A04:
	ldr r1, [r5]
	movs r0, 0x10
	b _08160E88
_08160A0A:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08160A18
	cmp r1, 0x1
	beq _08160A18
	b _08160E8A
_08160A18:
	ldr r0, =gUnknown_0203BC38
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _08160A30
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x3
	b _08160E88
	.pool
_08160A30:
	cmp r0, 0x1
	beq _08160A36
	b _08160E8A
_08160A36:
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x5
	b _08160E88
	.pool
_08160A44:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	beq _08160A50
	b _08160E8A
_08160A50:
	bl sub_81D2C50
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	b _08160E88
	.pool
_08160A64:
	bl sub_8198C58
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	bne _08160A7C
	ldr r0, =gUnknown_020375E0
	strh r1, [r0]
	b _08160E82
	.pool
_08160A7C:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08160A8A
	cmp r1, 0x1
	beq _08160A8A
	b _08160E8A
_08160A8A:
	ldr r0, =gUnknown_0203BC38
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _08160AA4
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x3
	b _08160E88
	.pool
_08160AA4:
	cmp r0, 0x1
	beq _08160AAA
	b _08160E8A
_08160AAA:
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x5
	b _08160E88
	.pool
_08160AB8:
	ldr r0, =gUnknown_085EF8F3
	bl sub_816084C
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	b _08160E88
	.pool
_08160AD0:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	beq _08160ADC
	b _08160E8A
_08160ADC:
	bl sub_81D2C50
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x12
	b _08160E88
	.pool
_08160AEC:
	bl sub_8198C58
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	bne _08160B10
	ldr r0, =gUnknown_085EFA10
	bl sub_816084C
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x13
	b _08160E88
	.pool
_08160B10:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08160B1E
	cmp r1, 0x1
	beq _08160B1E
	b _08160E8A
_08160B1E:
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x18
	b _08160E88
	.pool
_08160B2C:
	ldr r4, =gStringVar2
	bl sub_8161054
	movs r1, 0xD
	muls r1, r0
	ldr r0, =gMoveNames
	adds r1, r0
	adds r0, r4, 0
	bl StringCopy
	ldr r0, =gUnknown_085EF960
	bl sub_816084C
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	b _08160E88
	.pool
_08160B60:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	beq _08160B6C
	b _08160E8A
_08160B6C:
	bl sub_81D2C50
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	b _08160E88
	.pool
_08160B80:
	bl sub_8198C58
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	bne _08160B98
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x1B
	b _08160E88
	.pool
_08160B98:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08160BA6
	cmp r1, 0x1
	beq _08160BA6
	b _08160E8A
_08160BA6:
	ldr r0, =gUnknown_0203BC38
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _08160BC4
	ldr r2, =gUnknown_0203BC34
	ldr r1, [r2]
	movs r0, 0x3
	strb r0, [r1]
	adds r7, r2, 0
	b _08160BD0
	.pool
_08160BC4:
	ldr r7, =gUnknown_0203BC34
	cmp r0, 0x1
	bne _08160BD0
	ldr r1, [r7]
	movs r0, 0x5
	strb r0, [r1]
_08160BD0:
	ldr r1, [r7]
	movs r0, 0x10
	b _08160E88
	.pool
_08160BDC:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	beq _08160BE8
	b _08160E8A
_08160BE8:
	movs r0, 0x3
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, =gUnknown_0203BC38
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _08160C08
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x3
	b _08160E88
	.pool
_08160C08:
	cmp r0, 0x1
	beq _08160C0E
	b _08160E8A
_08160C0E:
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x5
	b _08160E88
	.pool
_08160C1C:
	bl sub_81D2C3C
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _08160C2A
	b _08160E8A
_08160C2A:
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x14
	strb r0, [r1]
	subs r0, 0x15
	str r2, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _08160E8A
	.pool
_08160C48:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08160C56
	b _08160E8A
_08160C56:
	bl sub_8161054
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gPlayerParty
	ldr r1, =gUnknown_0203BC34
	ldr r1, [r1]
	adds r1, 0x44
	ldrb r1, [r1]
	ldr r2, =gUnknown_020244E9
	ldrb r2, [r2]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldr r3, =sub_8160740
	str r0, [sp]
	adds r0, r4, 0
	bl sub_81BFA38
	bl sub_8160EA0
	b _08160E8A
	.pool
_08160C98:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	beq _08160CA4
	b _08160E8A
_08160CA4:
	b _08160E82
_08160CA6:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
_08160CAE:
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	b _08160E8A
_08160CB8:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	b _08160E88
	.pool
_08160CD8:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08160CE6
	b _08160E8A
_08160CE6:
	bl sub_8160EA0
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
	b _08160E8A
	.pool
_08160CFC:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, =gUnknown_0203BC38
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _08160D30
	movs r0, 0x1
	bl render_previous_quest_text
	b _08160D3A
	.pool
_08160D30:
	cmp r0, 0x1
	bne _08160D3A
	movs r0, 0x1
	bl sub_8161074
_08160D3A:
	bl sub_8161234
	movs r0, 0x3
	movs r1, 0x2
	bl CopyWindowToVram
	b _08160E8A
_08160D48:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08160D56
	b _08160E8A
_08160D56:
	ldr r1, [r7]
	adds r2, r1, 0
	adds r2, 0x45
	ldrb r0, [r2]
	cmp r0, 0x4
	bne _08160D6C
	movs r0, 0x18
	b _08160E88
	.pool
_08160D6C:
	adds r0, r1, 0
	adds r0, 0x44
	ldrb r0, [r0]
	movs r4, 0x64
	muls r0, r4
	ldr r5, =gPlayerParty
	adds r0, r5
	ldrb r1, [r2]
	adds r1, 0xD
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	ldr r2, =gStringVar3
	movs r1, 0xD
	mov r8, r1
	mov r1, r8
	muls r1, r0
	ldr r6, =gMoveNames
	adds r1, r6
	adds r0, r2, 0
	bl StringCopy
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0x44
	ldrb r0, [r0]
	muls r0, r4
	adds r0, r5
	adds r1, 0x45
	ldrb r1, [r1]
	bl sub_806B9A8
	ldr r0, [r7]
	adds r0, 0x44
	ldrb r0, [r0]
	muls r4, r0
	adds r4, r5
	bl sub_8161054
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldr r0, [r7]
	adds r0, 0x45
	ldrb r2, [r0]
	adds r0, r4, 0
	bl sub_80691F4
	ldr r4, =gStringVar2
	bl sub_8161054
	mov r1, r8
	muls r1, r0
	adds r1, r6
	adds r0, r4, 0
	bl StringCopy
	ldr r0, =gUnknown_085EF979
	bl sub_816084C
	ldr r1, [r7]
	movs r0, 0x1E
	strb r0, [r1]
	ldr r1, =gUnknown_020375E0
	movs r0, 0x1
	strh r0, [r1]
	b _08160E8A
	.pool
_08160E0C:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	bne _08160E8A
	ldr r0, =gUnknown_085EF9A6
	bl sub_816084C
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x1F
	strb r0, [r1]
	ldr r0, =0x0000016f
	bl fanfare_play
	b _08160E8A
	.pool
_08160E38:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	bne _08160E8A
	ldr r0, =0x0000016f
	bl fanfare_play
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x20
	b _08160E88
	.pool
_08160E58:
	bl task_is_not_running_overworld_fanfare
	lsls r0, 24
	cmp r0, 0
	beq _08160E8A
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x21
	b _08160E88
	.pool
_08160E70:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08160E8A
	movs r0, 0x5
	bl audio_play
_08160E82:
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0xE
_08160E88:
	strb r0, [r1]
_08160E8A:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8160868

	thumb_func_start sub_8160EA0
sub_8160EA0: @ 8160EA0
	push {r4,lr}
	bl sub_8161234
	ldr r4, =gUnknown_0203BC34
	ldr r0, [r4]
	movs r1, 0x89
	lsls r1, 1
	adds r0, r1
	ldrb r0, [r0]
	ldr r1, =gUnknown_0203BC38
	adds r2, r1, 0x2
	bl sub_81AE6C8
	bl FreeAllWindowBuffers
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
	bl ResetAllObjectData
	bl ResetObjectPaletteAllocator
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8160EA0

	thumb_func_start render_previous_quest_text
render_previous_quest_text: @ 8160EE0
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	movs r2, 0
	ldr r6, =gSprites
	ldr r4, =gUnknown_0203BC34
	movs r3, 0x4
_08160EF0:
	ldr r0, [r4]
	adds r0, 0x1
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0xF
	ble _08160EF0
	cmp r5, 0
	bne _08160F38
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085EF8C2
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x3
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x1
	str r0, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0
	bl Print
_08160F38:
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end render_previous_quest_text

	thumb_func_start sub_8160F50
sub_8160F50: @ 8160F50
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r6, =gUnknown_0203BC34
	ldr r0, [r6]
	movs r4, 0x89
	lsls r4, 1
	adds r0, r4
	ldrb r0, [r0]
	bl ListMenuHandleInput
	adds r5, r0, 0
	ldr r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	ldr r4, =gUnknown_0203BC38
	adds r2, r4, 0x2
	adds r1, r4, 0
	bl get_coro_args_x18_x1A
	movs r0, 0x2
	negs r0, r0
	cmp r5, r0
	beq _08160FE4
	adds r0, 0x1
	cmp r5, r0
	bne _08161010
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x30
	ands r0, r1
	cmp r0, 0
	bne _08160F9C
	bl GetLRKeysState
	lsls r0, 24
	cmp r0, 0
	beq _0816103E
_08160F9C:
	movs r0, 0x5
	bl audio_play
	cmp r7, 0
	bne _08160FC4
	movs r0, 0x1
	bl PutWindowTilemap
	ldr r0, [r6]
	movs r1, 0x5
	strb r1, [r0]
	movs r0, 0x1
	strb r0, [r4, 0x4]
	b _08160FD4
	.pool
_08160FC4:
	movs r0, 0
	bl PutWindowTilemap
	ldr r0, [r6]
	movs r2, 0
	movs r1, 0x3
	strb r1, [r0]
	strb r2, [r4, 0x4]
_08160FD4:
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	bl sub_8161054
	bl sub_816137C
	b _0816103E
_08160FE4:
	movs r0, 0x5
	bl audio_play
	bl sub_8161234
	ldr r1, [r6]
	movs r0, 0xC
	strb r0, [r1]
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085EF9E6
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	bl sub_81D2BF4
	b _0816103E
	.pool
_08161010:
	movs r0, 0x5
	bl audio_play
	bl sub_8161234
	ldr r1, [r6]
	movs r0, 0x8
	strb r0, [r1]
	ldr r0, =gStringVar2
	movs r1, 0xD
	muls r1, r5
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085EF8DA
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	bl sub_81D2BF4
_0816103E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8160F50

	thumb_func_start sub_8161054
sub_8161054: @ 8161054
	ldr r0, =gUnknown_0203BC34
	ldr r2, [r0]
	ldr r1, =gUnknown_0203BC38
	ldrh r0, [r1, 0x2]
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 3
	adds r2, 0x4C
	adds r2, r0
	ldr r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_8161054

	thumb_func_start sub_8161074
sub_8161074: @ 8161074
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _081610A6
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085EF8C2
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x3
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x1
	str r0, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0
	bl Print
_081610A6:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161074

	thumb_func_start sub_81610B8
sub_81610B8: @ 81610B8
	push {r4-r7,lr}
	ldr r2, =gUnknown_0203BC34
	ldr r0, [r2]
	movs r1, 0x8A
	lsls r1, 1
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	ldr r0, [r2]
	ldr r2, =0x00000113
	adds r1, r0, r2
	movs r0, 0x1
	negs r0, r0
	strb r0, [r1]
	bl sub_81611AC
	movs r4, 0
	ldr r5, =gUnknown_085CEC10
_081610DC:
	adds r2, r4, 0
	cmp r4, 0
	bge _081610E4
	adds r2, r4, 0x3
_081610E4:
	asrs r2, 2
	lsls r1, r2, 2
	subs r1, r4, r1
	lsls r1, 19
	movs r0, 0xD0
	lsls r0, 15
	adds r1, r0
	asrs r1, 16
	lsls r2, 19
	movs r0, 0x90
	lsls r0, 14
	adds r2, r0
	asrs r2, 16
	adds r0, r5, 0
	movs r3, 0
	bl CreateSprite
	ldr r2, =gUnknown_0203BC34
	ldr r1, [r2]
	adds r1, 0x1
	adds r1, r4
	strb r0, [r1]
	adds r4, 0x1
	cmp r4, 0x7
	ble _081610DC
	movs r4, 0
	ldr r7, =gUnknown_085CEC10
	adds r6, r2, 0
_0816111C:
	adds r2, r4, 0
	cmp r4, 0
	bge _08161124
	adds r2, r4, 0x3
_08161124:
	asrs r2, 2
	lsls r1, r2, 2
	subs r1, r4, r1
	lsls r1, 19
	movs r0, 0xD0
	lsls r0, 15
	adds r1, r0
	asrs r1, 16
	lsls r2, 19
	movs r0, 0xD0
	lsls r0, 14
	adds r2, r0
	asrs r2, 16
	adds r0, r7, 0
	movs r3, 0
	bl CreateSprite
	ldr r1, [r6]
	adds r2, r4, 0
	adds r2, 0x8
	adds r1, 0x1
	adds r1, r2
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, 0x1
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r5, =gSprites
	adds r0, r5
	movs r1, 0x2
	bl StartObjectImageAnim
	adds r4, 0x1
	cmp r4, 0x7
	ble _0816111C
	movs r4, 0
	ldr r3, =gUnknown_0203BC34
	movs r2, 0x4
_08161176:
	ldr r0, [r3]
	adds r0, 0x1
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	adds r4, 0x1
	cmp r4, 0xF
	ble _08161176
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81610B8

	thumb_func_start sub_81611AC
sub_81611AC: @ 81611AC
	push {r4-r6,lr}
	ldr r4, =gUnknown_0203BC34
	ldr r1, [r4]
	movs r2, 0x8A
	lsls r2, 1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _081611D4
	ldr r0, =gUnknown_085CEBC0
	movs r3, 0x8B
	lsls r3, 1
	adds r1, r3
	bl AddScrollIndicatorArrowPair
	ldr r1, [r4]
	movs r5, 0x8A
	lsls r5, 1
	adds r1, r5
	strb r0, [r1]
_081611D4:
	ldr r0, [r4]
	ldr r6, =0x00000113
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _08161210
	ldr r0, =gUnknown_0203CE8C
	adds r2, r0, 0
	ldr r1, =gUnknown_085CEBD0
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldr r1, [r1]
	str r1, [r2]
	ldr r2, [r4]
	movs r3, 0x88
	lsls r3, 1
	adds r1, r2, r3
	ldrb r1, [r1]
	ldr r5, =0x00000111
	adds r2, r5
	ldrb r2, [r2]
	subs r1, r2
	strh r1, [r0, 0x8]
	ldr r1, =gUnknown_0203BC38
	bl AddScrollIndicatorArrowPair
	ldr r1, [r4]
	ldr r6, =0x00000113
	adds r1, r6
	strb r0, [r1]
_08161210:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81611AC

	thumb_func_start sub_8161234
sub_8161234: @ 8161234
	push {r4,lr}
	ldr r4, =gUnknown_0203BC34
	ldr r0, [r4]
	movs r2, 0x8A
	lsls r2, 1
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _08161256
	bl RemoveScrollIndicatorArrowPair
	ldr r0, [r4]
	movs r1, 0x8A
	lsls r1, 1
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
_08161256:
	ldr r0, [r4]
	ldr r2, =0x00000113
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _08161270
	bl RemoveScrollIndicatorArrowPair
	ldr r0, [r4]
	ldr r2, =0x00000113
	adds r1, r0, r2
	movs r0, 0xFF
	strb r0, [r1]
_08161270:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161234

	thumb_func_start sub_8161280
sub_8161280: @ 8161280
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xC
	ldr r4, =gUnknown_0203BC34
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x44
	ldrb r2, [r0]
	movs r0, 0x64
	muls r0, r2
	ldr r2, =gPlayerParty
	adds r0, r2
	adds r1, 0x12
	bl sub_806E0B4
	ldr r1, [r4]
	movs r6, 0x88
	lsls r6, 1
	adds r1, r6
	strb r0, [r1]
	movs r5, 0
	ldr r0, [r4]
	adds r0, r6
	ldrb r0, [r0]
	cmp r5, r0
	bge _081612F6
	mov r8, r4
	movs r0, 0xD
	mov r12, r0
	ldr r2, =gMoveNames
	mov r9, r2
_081612C2:
	mov r7, r8
	ldr r4, [r7]
	lsls r3, r5, 3
	adds r2, r4, 0
	adds r2, 0x48
	adds r2, r3
	lsls r0, r5, 1
	adds r1, r4, 0
	adds r1, 0x12
	adds r1, r0
	ldrh r0, [r1]
	mov r7, r12
	muls r7, r0
	adds r0, r7, 0
	add r0, r9
	str r0, [r2]
	adds r0, r4, 0
	adds r0, 0x4C
	adds r0, r3
	ldrh r1, [r1]
	str r1, [r0]
	adds r5, 0x1
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r5, r0
	blt _081612C2
_081612F6:
	ldr r4, =gUnknown_0203BC34
	ldr r0, [r4]
	adds r0, 0x44
	ldrb r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	ldr r0, =gStringVar1
	mov r1, sp
	bl StringCopy10
	ldr r2, [r4]
	movs r5, 0x88
	lsls r5, 1
	adds r3, r2, r5
	ldrb r0, [r3]
	lsls r0, 3
	adds r1, r2, 0
	adds r1, 0x48
	adds r1, r0
	ldr r0, =gUnknown_085E8CF0
	str r0, [r1]
	ldrb r0, [r3]
	lsls r0, 3
	adds r2, 0x4C
	adds r2, r0
	movs r0, 0x2
	negs r0, r0
	str r0, [r2]
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x48
	adds r1, r5
	ldrb r1, [r1]
	bl sub_81D28C8
	ldr r1, [r4]
	ldr r2, =0x00000111
	adds r1, r2
	strb r0, [r1]
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161280

	thumb_func_start sub_816137C
sub_816137C: @ 816137C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	ldr r0, =gUnknown_0203BC38
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08161394
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	bne _081613CC
_08161394:
	movs r5, 0
	ldr r4, =gSprites
	ldr r3, =gUnknown_0203BC34
	movs r2, 0x4
_0816139C:
	ldr r0, [r3]
	adds r0, 0x1
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0xF
	bls _0816139C
	b _081614FE
	.pool
_081613CC:
	ldr r1, =gContestEffects
	ldr r0, =gContestMoves
	lsls r4, 3
	adds r0, r4, r0
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x1]
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 24
	lsrs r6, r0, 24
	mov r8, r4
	cmp r6, 0xFF
	bne _081613EE
	movs r6, 0
_081613EE:
	movs r5, 0
	ldr r7, =gUnknown_0203BC34
	ldr r4, =gSprites
_081613F4:
	cmp r5, r6
	bcs _08161420
	ldr r0, [r7]
	adds r0, 0x1
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x1
	bl StartObjectImageAnim
	b _08161436
	.pool
_08161420:
	ldr r0, [r7]
	adds r0, 0x1
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0
	bl StartObjectImageAnim
_08161436:
	ldr r0, [r7]
	adds r0, 0x1
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r3, 0x5
	negs r3, r3
	adds r2, r3, 0
	ands r1, r2
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x7
	bls _081613F4
	ldr r1, =gContestEffects
	ldr r0, =gContestMoves
	add r0, r8
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x2]
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0xFF
	bne _0816147C
	movs r6, 0
_0816147C:
	movs r5, 0
	ldr r0, =gUnknown_0203BC34
	mov r8, r0
	ldr r7, =gSprites
_08161484:
	cmp r5, r6
	bcs _081614B8
	mov r1, r8
	ldr r0, [r1]
	adds r4, r5, 0
	adds r4, 0x8
	adds r0, 0x1
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	movs r1, 0x3
	bl StartObjectImageAnim
	b _081614D4
	.pool
_081614B8:
	mov r3, r8
	ldr r0, [r3]
	adds r4, r5, 0
	adds r4, 0x8
	adds r0, 0x1
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	movs r1, 0x2
	bl StartObjectImageAnim
_081614D4:
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x1
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r3, 0x5
	negs r3, r3
	adds r2, r3, 0
	ands r1, r2
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x7
	bls _08161484
_081614FE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_816137C

	thumb_func_start hm_prepare_dive_probably
hm_prepare_dive_probably: @ 8161508
	push {r4-r6,lr}
	bl brm_get_pokemon_selection
	lsls r0, 24
	lsrs r0, 24
	movs r6, 0x64
	muls r0, r6
	ldr r4, =gPlayerParty
	adds r0, r4
	movs r1, 0x3A
	bl GetMonData
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	bl brm_get_pokemon_selection
	lsls r0, 24
	lsrs r0, 24
	muls r0, r6
	adds r0, r4
	movs r1, 0x39
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x5
	bl __udivsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r4, r0
	bhi _08161558
	movs r0, 0
	b _0816155A
	.pool
_08161558:
	movs r0, 0x1
_0816155A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end hm_prepare_dive_probably

	thumb_func_start sub_8161560
sub_8161560: @ 8161560
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203CEC8
	movs r1, 0xA
	strb r1, [r0, 0xB]
	ldrb r1, [r0, 0x9]
	strb r1, [r0, 0xA]
	bl brm_get_pokemon_selection
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl sub_81B0FCC
	movs r0, 0x5
	bl display_pokemon_menu_message
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B1370
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161560

	thumb_func_start sub_81615A8
sub_81615A8: @ 81615A8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	str r4, [sp, 0x4]
	ldr r1, =gUnknown_0203CEC8
	ldrb r7, [r1, 0x9]
	mov r8, r7
	ldrb r0, [r1, 0xA]
	adds r5, r0, 0
	cmp r5, 0x6
	bls _081615EC
	movs r0, 0
	strb r0, [r1, 0xB]
	bl display_pokemon_menu_message
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B1370
	str r1, [r0]
	b _08161658
	.pool
_081615EC:
	movs r0, 0x64
	mov r10, r0
	mov r0, r10
	muls r0, r5
	ldr r1, =gPlayerParty
	mov r9, r1
	adds r6, r0, r1
	adds r0, r6, 0
	movs r1, 0x39
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	beq _0816161A
	cmp r7, r5
	beq _0816161A
	adds r0, r6, 0
	movs r1, 0x3A
	bl GetMonData
	cmp r0, r4
	bne _08161628
_0816161A:
	ldr r0, [sp, 0x4]
	bl sub_81617B8
	b _08161658
	.pool
_08161628:
	movs r0, 0x1
	bl audio_play
	mov r1, r10
	mov r0, r8
	muls r0, r1
	add r0, r9
	movs r1, 0x3A
	bl GetMonData
	movs r1, 0x5
	bl __udivsi3
	adds r3, r0, 0
	lsls r3, 16
	asrs r3, 16
	movs r2, 0x1
	negs r2, r2
	ldr r0, =sub_816166C
	str r0, [sp]
	ldr r0, [sp, 0x4]
	mov r1, r8
	bl sub_81B1F18
_08161658:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81615A8

	thumb_func_start sub_816166C
sub_816166C: @ 816166C
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	bl audio_play
	ldr r5, =gUnknown_0203CEC8
	movs r1, 0x9
	ldrsb r1, [r5, r1]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3A
	bl GetMonData
	movs r1, 0x5
	bl __udivsi3
	adds r3, r0, 0
	lsls r3, 16
	asrs r3, 16
	ldrb r1, [r5, 0xA]
	ldr r0, =sub_81616C0
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_81B1F18
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816166C

	thumb_func_start sub_81616C0
sub_81616C0: @ 81616C0
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gUnknown_0203CEC8
	movs r1, 0xA
	ldrsb r1, [r0, r1]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gStringVar1
	bl GetMonNickname
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085E9C17
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0
	bl sub_81B1B5C
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_8161724
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81616C0

	thumb_func_start sub_8161724
sub_8161724: @ 8161724
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_81B1BD4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08161772
	ldr r4, =gUnknown_0203CEC8
	movs r0, 0
	strb r0, [r4, 0xB]
	ldrb r0, [r4, 0x9]
	movs r1, 0
	bl sub_81B0FCC
	ldrb r0, [r4, 0xA]
	strb r0, [r4, 0x9]
	ldrb r0, [r4, 0xA]
	movs r1, 0x1
	bl sub_81B0FCC
	movs r0, 0x6
	movs r1, 0
	bl sub_8198070
	movs r0, 0x6
	bl ClearWindowTilemap
	movs r0, 0
	bl display_pokemon_menu_message
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B1370
	str r1, [r0]
_08161772:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161724

	thumb_func_start sub_8161784
sub_8161784: @ 8161784
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_81B1BD4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081617AA
	movs r0, 0x5
	bl display_pokemon_menu_message
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81B1370
	str r0, [r1]
_081617AA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161784

	thumb_func_start sub_81617B8
sub_81617B8: @ 81617B8
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x5
	bl audio_play
	ldr r0, =gUnknown_085E9712
	movs r1, 0
	bl sub_81B1B5C
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_8161784
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81617B8

	thumb_func_start sub_81617F4
sub_81617F4: @ 81617F4
	push {r4,lr}
	ldr r0, =gUnknown_0203BC40
	mov r12, r0
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r2, =0x00002734
	adds r0, r1, r2
	mov r4, r12
	str r0, [r4]
	movs r3, 0xA
	strb r3, [r4, 0x4]
	adds r2, 0xA
	adds r0, r1, r2
	str r0, [r4, 0x8]
	strb r3, [r4, 0xC]
	ldr r4, =0x00002748
	adds r0, r1, r4
	mov r2, r12
	str r0, [r2, 0x10]
	strb r3, [r2, 0x14]
	adds r4, 0xA
	adds r0, r1, r4
	str r0, [r2, 0x18]
	movs r2, 0x1E
	mov r0, r12
	strb r2, [r0, 0x1C]
	adds r4, 0x1E
	adds r0, r1, r4
	mov r4, r12
	str r0, [r4, 0x20]
	mov r0, r12
	adds r0, 0x24
	strb r2, [r0]
	ldr r2, =0x0000278e
	adds r0, r1, r2
	str r0, [r4, 0x28]
	mov r0, r12
	adds r0, 0x2C
	strb r3, [r0]
	ldr r4, =0x00002798
	adds r0, r1, r4
	mov r2, r12
	str r0, [r2, 0x30]
	adds r2, 0x34
	movs r0, 0x28
	strb r0, [r2]
	adds r4, 0x28
	adds r1, r4
	mov r0, r12
	str r1, [r0, 0x38]
	adds r0, 0x3C
	strb r3, [r0]
	bl sub_8126968
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81617F4

	thumb_func_start sub_8161880
sub_8161880: @ 8161880
	push {r4,r5,lr}
	lsls r0, 24
	movs r3, 0
	ldr r1, =gUnknown_0203BC40
	lsrs r2, r0, 21
	adds r0, r2, r1
	ldrb r0, [r0, 0x4]
	cmp r3, r0
	bcs _081618AA
	adds r5, r1, 0
	movs r4, 0
_08161896:
	adds r0, r2, r5
	ldr r1, [r0]
	adds r1, r3
	strb r4, [r1]
	adds r1, r3, 0x1
	lsls r1, 24
	lsrs r3, r1, 24
	ldrb r0, [r0, 0x4]
	cmp r3, r0
	bcc _08161896
_081618AA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161880

	thumb_func_start sub_81618B4
sub_81618B4: @ 81618B4
	push {r4,lr}
	movs r4, 0
_081618B8:
	adds r0, r4, 0
	bl sub_8161880
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x7
	bls _081618B8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81618B4

	thumb_func_start sub_81618D0
sub_81618D0: @ 81618D0
	push {r4,lr}
	lsls r0, 24
	movs r2, 0
	ldr r1, =gUnknown_0203BC40
	lsrs r0, 21
	adds r0, r1
	movs r1, 0x4
	ldrsb r1, [r0, r1]
	cmp r2, r1
	bge _0816190C
	adds r4, r0, 0
	adds r3, r1, 0
_081618E8:
	lsls r0, r2, 24
	asrs r1, r0, 24
	ldr r0, [r4]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08161900
	adds r0, r1, 0
	b _08161910
	.pool
_08161900:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	asrs r0, 24
	cmp r0, r3
	blt _081618E8
_0816190C:
	movs r0, 0x1
	negs r0, r0
_08161910:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81618D0

	thumb_func_start sub_8161918
sub_8161918: @ 8161918
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r1, =gUnknown_085A5C08
	lsls r0, r3, 5
	adds r0, r1
	ldrb r0, [r0, 0x13]
	movs r2, 0
	ldr r1, =gUnknown_0203BC40
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0, 0x4]
	cmp r2, r1
	bcs _08161956
	ldr r4, [r0]
_08161936:
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, r3
	bne _0816194C
	movs r0, 0x1
	b _08161958
	.pool
_0816194C:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, r1
	bcc _08161936
_08161956:
	movs r0, 0
_08161958:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8161918

	thumb_func_start IsThereStorageSpaceForDecoration
IsThereStorageSpaceForDecoration: @ 8161960
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	cmp r4, 0
	beq _081619A0
	ldr r1, =gUnknown_085A5C08
	lsls r0, r4, 5
	adds r0, r1
	ldrb r5, [r0, 0x13]
	adds r0, r5, 0
	bl sub_81618D0
	lsls r0, 24
	asrs r2, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _081619A0
	ldr r0, =gUnknown_0203BC40
	lsls r1, r5, 3
	adds r1, r0
	ldr r0, [r1]
	adds r0, r2
	strb r4, [r0]
	movs r0, 0x1
	b _081619A2
	.pool
_081619A0:
	movs r0, 0
_081619A2:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end IsThereStorageSpaceForDecoration

	thumb_func_start sub_81619A8
sub_81619A8: @ 81619A8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _081619D4
	ldr r1, =gUnknown_085A5C08
	lsls r0, 5
	adds r0, r1
	ldrb r0, [r0, 0x13]
	bl sub_81618D0
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _081619D4
	movs r0, 0x1
	b _081619D6
	.pool
_081619D4:
	movs r0, 0
_081619D6:
	pop {r1}
	bx r1
	thumb_func_end sub_81619A8

	thumb_func_start sub_81619DC
sub_81619DC: @ 81619DC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r3, 0
	cmp r5, 0
	bne _081619F8
	b _08161A26
_081619EA:
	movs r0, 0
	strb r0, [r1]
	adds r0, r6, 0
	bl sub_8161A38
	movs r0, 0x1
	b _08161A28
_081619F8:
	ldr r2, =gUnknown_0203BC40
	ldr r1, =gUnknown_085A5C08
	lsls r0, r5, 5
	adds r0, r1
	ldrb r4, [r0, 0x13]
	lsls r0, r4, 3
	adds r0, r2
	ldrb r1, [r0, 0x4]
	cmp r3, r1
	bcs _08161A26
	adds r6, r4, 0
	adds r4, r0, 0
	adds r2, r1, 0
_08161A12:
	ldr r0, [r4]
	adds r1, r0, r3
	ldrb r0, [r1]
	cmp r0, r5
	beq _081619EA
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, r2
	bcc _08161A12
_08161A26:
	movs r0, 0
_08161A28:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81619DC

	thumb_func_start sub_8161A38
sub_8161A38: @ 8161A38
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	movs r6, 0
	ldr r2, =gUnknown_0203BC40
	lsrs r0, 21
	adds r1, r0, r2
	ldrb r3, [r1, 0x4]
	cmp r6, r3
	bcs _08161ABC
	adds r7, r0, 0
	mov r10, r1
	mov r0, r10
	str r0, [sp]
_08161A5C:
	adds r1, r6, 0x1
	lsls r0, r1, 24
	lsrs r3, r0, 24
	adds r2, r7, 0
	mov r12, r1
	mov r1, r10
	ldrb r1, [r1, 0x4]
	cmp r3, r1
	bcs _08161AAE
	ldr r0, =gUnknown_0203BC40
	mov r9, r0
	adds r1, r0, 0
	mov r8, r1
_08161A76:
	mov r0, r9
	adds r5, r2, r0
	ldr r1, [r5]
	adds r0, r1, r3
	ldrb r4, [r0]
	adds r2, r4, 0
	cmp r2, 0
	beq _08161A9C
	adds r0, r1, r6
	ldrb r1, [r0]
	cmp r1, 0
	beq _08161A92
	cmp r1, r2
	bls _08161A9C
_08161A92:
	ldrb r1, [r0]
	strb r4, [r0]
	ldr r0, [r5]
	adds r0, r3
	strb r1, [r0]
_08161A9C:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	adds r2, r7, 0
	mov r1, r8
	adds r0, r2, r1
	ldrb r0, [r0, 0x4]
	cmp r3, r0
	bcc _08161A76
_08161AAE:
	mov r3, r12
	lsls r0, r3, 24
	lsrs r6, r0, 24
	ldr r0, [sp]
	ldrb r0, [r0, 0x4]
	cmp r6, r0
	bcc _08161A5C
_08161ABC:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161A38

	thumb_func_start sub_8161AD0
sub_8161AD0: @ 8161AD0
	push {r4,r5,lr}
	lsls r0, 24
	movs r4, 0
	movs r3, 0
	ldr r2, =gUnknown_0203BC40
	lsrs r1, r0, 21
	adds r0, r1, r2
	ldrb r0, [r0, 0x4]
	cmp r4, r0
	bcs _08161B04
	adds r5, r2, 0
_08161AE6:
	adds r2, r1, r5
	ldr r0, [r2]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _08161AF8
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_08161AF8:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	ldrb r2, [r2, 0x4]
	cmp r3, r2
	bcc _08161AE6
_08161B04:
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8161AD0

	thumb_func_start sub_8161B10
sub_8161B10: @ 8161B10
	push {r4,r5,lr}
	movs r5, 0
	movs r4, 0
_08161B16:
	adds r0, r4, 0
	bl sub_8161AD0
	adds r0, r5, r0
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x7
	bls _08161B16
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8161B10

	thumb_func_start sub_8161B34
sub_8161B34: @ 8161B34
	push {r4,r5,lr}
	ldr r5, =gSaveBlock1Ptr
	ldr r0, [r5]
	ldr r4, =0x000031dc
	adds r0, r4
	movs r1, 0
	movs r2, 0x1C
	bl memset
	ldr r0, [r5]
	adds r0, r4
	ldr r1, =0x00000197
	strh r1, [r0, 0x8]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161B34

	thumb_func_start sub_8161B60
sub_8161B60: @ 8161B60
	push {r4-r6,lr}
	movs r2, 0
	ldr r6, =gUnknown_0203BC86
	ldr r4, =gUnknown_0203BC80
	movs r3, 0
	adds r5, r4, 0x1
_08161B6C:
	lsls r1, r2, 1
	adds r0, r1, r4
	strb r3, [r0]
	adds r1, r5
	strb r3, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x2
	bls _08161B6C
	movs r0, 0
	strb r0, [r6]
	strb r0, [r6, 0x1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161B60

	thumb_func_start sub_8161B94
sub_8161B94: @ 8161B94
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	lsls r0, 16
	cmp r0, 0
	bne _08161BBC
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r2, =0x000031dc
	adds r1, r2
	ldr r2, =0x00000197
	b _08161BC8
	.pool
_08161BBC:
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r2, =0x000031dc
	adds r1, r2
	movs r2, 0xCC
	lsls r2, 1
_08161BC8:
	strh r2, [r1, 0x8]
	adds r7, r0, 0
	ldr r6, =gEnemyParty
	ldr r0, [r7]
	ldr r5, =0x000031dc
	adds r0, r5
	ldrh r1, [r0, 0x8]
	movs r4, 0
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
	adds r0, r6, 0
	movs r2, 0x28
	movs r3, 0x20
	bl create_pokemon_set_level
	ldr r0, [r7]
	adds r0, r5
	movs r1, 0x28
	strb r1, [r0, 0xC]
	ldr r0, [r7]
	adds r0, r5
	strb r4, [r0, 0xD]
	ldr r0, [r7]
	adds r0, r5
	movs r1, 0x1
	strb r1, [r0, 0x13]
	adds r0, r6, 0
	movs r1, 0x42
	bl GetMonData
	ldr r1, [r7]
	adds r1, r5
	str r0, [r1]
	adds r0, r6, 0
	movs r1, 0
	bl GetMonData
	ldr r1, [r7]
	adds r1, r5
	str r0, [r1, 0x4]
	adds r0, r6, 0
	movs r1, 0x3A
	bl GetMonData
	ldr r1, [r7]
	adds r1, r5
	movs r2, 0
	mov r8, r2
	strh r0, [r1, 0xA]
	adds r0, r6, 0
	movs r1, 0x16
	bl GetMonData
	ldr r1, [r7]
	adds r1, r5
	strb r0, [r1, 0xE]
	adds r0, r6, 0
	movs r1, 0x17
	bl GetMonData
	ldr r1, [r7]
	adds r1, r5
	strb r0, [r1, 0xF]
	adds r0, r6, 0
	movs r1, 0x18
	bl GetMonData
	ldr r1, [r7]
	adds r1, r5
	strb r0, [r1, 0x10]
	adds r0, r6, 0
	movs r1, 0x21
	bl GetMonData
	ldr r1, [r7]
	adds r1, r5
	strb r0, [r1, 0x11]
	adds r0, r6, 0
	movs r1, 0x2F
	bl GetMonData
	ldr r1, [r7]
	adds r1, r5
	strb r0, [r1, 0x12]
	ldr r4, =gUnknown_0203BC86
	mov r0, r8
	strb r0, [r4]
	bl Random
	ldr r5, =gUnknown_085CEC30
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x14
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 1
	adds r1, r5
	ldrb r0, [r1]
	strb r0, [r4, 0x1]
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161B94

	thumb_func_start sub_8161CBC
sub_8161CBC: @ 8161CBC
	push {lr}
	bl sub_8161B34
	bl sub_8161B60
	ldr r0, =gUnknown_020375E0
	ldrh r0, [r0]
	bl sub_8161B94
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161CBC

	thumb_func_start mapnumbers_history_shift_sav1_0_2_4_out
mapnumbers_history_shift_sav1_0_2_4_out: @ 8161CD8
	ldr r0, =gUnknown_0203BC80
	ldrb r1, [r0, 0x2]
	strb r1, [r0, 0x4]
	ldrb r1, [r0, 0x3]
	strb r1, [r0, 0x5]
	ldrb r1, [r0]
	strb r1, [r0, 0x2]
	ldrb r1, [r0, 0x1]
	strb r1, [r0, 0x3]
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x4]
	strb r1, [r0]
	ldrb r1, [r2, 0x5]
	strb r1, [r0, 0x1]
	bx lr
	.pool
	thumb_func_end mapnumbers_history_shift_sav1_0_2_4_out

	thumb_func_start sub_8161D00
sub_8161D00: @ 8161D00
	push {r4,r5,lr}
	movs r1, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x000031dc
	adds r0, r2
	ldrb r0, [r0, 0x13]
	cmp r0, 0
	beq _08161D3E
	ldr r0, =gUnknown_0203BC86
	strb r1, [r0]
	ldr r5, =gUnknown_085CEC30
	adds r4, r0, 0
_08161D1A:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x14
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 1
	adds r1, r5
	ldrb r1, [r1]
	ldrb r0, [r4, 0x1]
	cmp r0, r1
	beq _08161D1A
	strb r1, [r4, 0x1]
_08161D3E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161D00

	thumb_func_start sub_8161D54
sub_8161D54: @ 8161D54
	push {r4-r7,lr}
	movs r4, 0
	bl Random
	lsls r0, 16
	movs r1, 0xF0
	lsls r1, 12
	ands r1, r0
	cmp r1, 0
	bne _08161D6E
	bl sub_8161D00
	b _08161DE2
_08161D6E:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000031dc
	adds r0, r1
	ldrb r0, [r0, 0x13]
	cmp r0, 0
	beq _08161DE2
	ldr r7, =gUnknown_0203BC86
	ldr r3, =gUnknown_085CEC30
_08161D80:
	lsls r0, r4, 1
	adds r0, r4
	lsls r2, r0, 1
	adds r1, r2, r3
	ldrb r0, [r7, 0x1]
	ldrb r1, [r1]
	cmp r0, r1
	bne _08161DD8
	ldr r6, =gUnknown_085CEC30
	adds r5, r2, 0x1
	ldr r4, =gUnknown_0203BC80
_08161D96:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x5
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	adds r0, r5
	adds r0, r6
	ldrb r1, [r0]
	ldrb r0, [r4, 0x4]
	cmp r0, 0
	bne _08161DBA
	ldrb r0, [r4, 0x5]
	cmp r0, r1
	beq _08161D96
_08161DBA:
	cmp r1, 0xFF
	beq _08161D96
	strb r1, [r7, 0x1]
	b _08161DE2
	.pool
_08161DD8:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x13
	bls _08161D80
_08161DE2:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8161D54

	thumb_func_start sub_8161DE8
sub_8161DE8: @ 8161DE8
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r3, =0x000031dc
	adds r0, r3
	ldrb r0, [r0, 0x13]
	cmp r0, 0
	beq _08161E20
	ldr r0, =gUnknown_0203BC86
	ldrb r3, [r0]
	cmp r2, r3
	bne _08161E20
	ldrb r0, [r0, 0x1]
	cmp r1, r0
	bne _08161E20
	movs r0, 0x1
	b _08161E22
	.pool
_08161E20:
	movs r0, 0
_08161E22:
	pop {r1}
	bx r1
	thumb_func_end sub_8161DE8

	thumb_func_start sub_8161E28
sub_8161E28: @ 8161E28
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, =gEnemyParty
	bl zero_enemy_party_data
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r1, =0x000031dc
	adds r0, r1
	ldrh r1, [r0, 0x8]
	ldrb r2, [r0, 0xC]
	ldr r3, [r0]
	ldr r0, [r0, 0x4]
	str r0, [sp]
	adds r0, r5, 0
	bl sub_8068060
	ldr r2, [r4]
	ldr r0, =0x000031e9
	adds r2, r0
	adds r0, r5, 0
	movs r1, 0x37
	bl SetMonData
	ldr r2, [r4]
	ldr r1, =0x000031e6
	adds r2, r1
	adds r0, r5, 0
	movs r1, 0x39
	bl SetMonData
	ldr r2, [r4]
	ldr r0, =0x000031ea
	adds r2, r0
	adds r0, r5, 0
	movs r1, 0x16
	bl SetMonData
	ldr r2, [r4]
	ldr r1, =0x000031eb
	adds r2, r1
	adds r0, r5, 0
	movs r1, 0x17
	bl SetMonData
	ldr r2, [r4]
	ldr r0, =0x000031ec
	adds r2, r0
	adds r0, r5, 0
	movs r1, 0x18
	bl SetMonData
	ldr r2, [r4]
	ldr r1, =0x000031ed
	adds r2, r1
	adds r0, r5, 0
	movs r1, 0x21
	bl SetMonData
	ldr r2, [r4]
	ldr r0, =0x000031ee
	adds r2, r0
	adds r0, r5, 0
	movs r1, 0x2F
	bl SetMonData
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161E28

	thumb_func_start sub_8161EDC
sub_8161EDC: @ 8161EDC
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldrb r0, [r1, 0x4]
	ldrb r1, [r1, 0x5]
	bl sub_8161DE8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08161F10
	bl Random
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	cmp r1, 0
	bne _08161F10
	bl sub_8161E28
	movs r0, 0x1
	b _08161F12
	.pool
_08161F10:
	movs r0, 0
_08161F12:
	pop {r1}
	bx r1
	thumb_func_end sub_8161EDC

	thumb_func_start sub_8161F18
sub_8161F18: @ 8161F18
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r1, 0x39
	bl GetMonData
	ldr r5, =gSaveBlock1Ptr
	ldr r1, [r5]
	ldr r4, =0x000031dc
	adds r1, r4
	strh r0, [r1, 0xA]
	adds r0, r6, 0
	movs r1, 0x37
	bl GetMonData
	ldr r1, [r5]
	adds r1, r4
	strb r0, [r1, 0xD]
	bl sub_8161D00
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161F18

	thumb_func_start sub_8161F4C
sub_8161F4C: @ 8161F4C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000031dc
	adds r0, r1
	movs r1, 0
	strb r1, [r0, 0x13]
	bx lr
	.pool
	thumb_func_end sub_8161F4C

	thumb_func_start sub_8161F64
sub_8161F64: @ 8161F64
	ldr r3, =gUnknown_0203BC86
	ldrb r2, [r3]
	strb r2, [r0]
	ldrb r0, [r3, 0x1]
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8161F64

	thumb_func_start sub_8161F74
sub_8161F74: @ 8161F74
	push {lr}
	ldr r1, =gUnknown_085DF96C
	ldr r0, =gUnknown_020375E0
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161F74

	thumb_func_start sub_8161F94
sub_8161F94: @ 8161F94
	push {r4-r7,lr}
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r5, r0, 30
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, [r4]
	ldr r2, =0x00000ca8
	adds r0, r2
	movs r7, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r1, [r4]
	adds r2, 0xA
	adds r0, r1, r2
	strh r7, [r0]
	ldr r0, =0x00000ca9
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r1, [r4]
	ldr r2, =0x00000ca9
	adds r1, r2
	ldrb r2, [r1]
	movs r0, 0x9
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	bl sub_81A3ACC
	ldr r4, [r4]
	ldr r0, =0x00000cdc
	adds r3, r4, r0
	ldr r2, =gUnknown_085DF9AC
	lsls r1, r5, 2
	lsls r0, r6, 3
	adds r1, r0
	adds r1, r2
	ldr r0, [r3]
	ldr r1, [r1]
	ands r0, r1
	cmp r0, 0
	bne _0816200E
	lsls r0, r5, 1
	lsls r1, r6, 2
	adds r0, r1
	movs r2, 0xCE
	lsls r2, 4
	adds r1, r4, r2
	adds r1, r0
	strh r7, [r1]
_0816200E:
	bl sub_8164ED8
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x4
	ldrsb r1, [r0, r1]
	movs r2, 0x5
	ldrsb r2, [r0, r2]
	movs r3, 0x1
	negs r3, r3
	movs r0, 0
	bl saved_warp2_set
	ldr r0, =gUnknown_02038BCA
	strh r7, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161F94

	thumb_func_start sub_8162054
sub_8162054: @ 8162054
	push {r4-r6,lr}
	ldr r5, =gSaveBlock2Ptr
	ldr r0, [r5]
	ldr r4, =0x00000ca9
	adds r0, r4
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r6, r0, 30
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =gUnknown_020375E2
	ldrh r0, [r0]
	cmp r0, 0x1
	beq _08162094
	cmp r0, 0x1
	ble _081620E8
	cmp r0, 0x2
	beq _081620A8
	cmp r0, 0x3
	beq _081620D8
	b _081620E8
	.pool
_08162094:
	adds r0, r6, 0
	lsls r1, 24
	lsrs r1, 24
	bl sub_8164FCC
	ldr r1, =gUnknown_020375F0
	strh r0, [r1]
	b _081620E8
	.pool
_081620A8:
	ldr r4, =gUnknown_020375F0
	ldr r2, [r5]
	ldr r0, =0x00000cdc
	adds r2, r0
	ldr r3, =gUnknown_085DF9AC
	lsls r0, r6, 2
	lsls r1, 3
	adds r0, r1
	adds r0, r3
	ldr r1, [r2]
	ldr r0, [r0]
	ands r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	strh r0, [r4]
	b _081620E8
	.pool
_081620D8:
	ldr r1, [r5]
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r0, 30
	ldr r2, =0x00000d07
	adds r1, r2
	strb r0, [r1]
_081620E8:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8162054

	thumb_func_start sub_81620F4
sub_81620F4: @ 81620F4
	push {r4-r7,lr}
	ldr r6, =gSaveBlock2Ptr
	ldr r0, [r6]
	ldr r7, =0x00000ca9
	adds r0, r7
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r5, r0, 30
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =gUnknown_020375E2
	ldrh r0, [r0]
	cmp r0, 0x1
	beq _08162134
	cmp r0, 0x1
	ble _081621B4
	cmp r0, 0x2
	beq _08162150
	cmp r0, 0x3
	beq _081621A4
	b _081621B4
	.pool
_08162134:
	ldr r2, [r6]
	lsls r0, r5, 1
	lsls r1, r4, 2
	adds r0, r1
	movs r1, 0xCE
	lsls r1, 4
	adds r2, r1
	adds r2, r0
	ldr r0, =gUnknown_020375E4
	ldrh r0, [r0]
	strh r0, [r2]
	b _081621B4
	.pool
_08162150:
	ldr r0, =gUnknown_020375E4
	ldrh r0, [r0]
	cmp r0, 0
	beq _08162180
	ldr r2, [r6]
	ldr r0, =0x00000cdc
	adds r2, r0
	ldr r3, =gUnknown_085DF9AC
	lsls r1, r5, 2
	lsls r0, r4, 3
	adds r1, r0
	adds r1, r3
	ldr r0, [r2]
	ldr r1, [r1]
	orrs r0, r1
	str r0, [r2]
	b _081621B4
	.pool
_08162180:
	ldr r2, [r6]
	ldr r1, =0x00000cdc
	adds r2, r1
	ldr r3, =gUnknown_085DF9CC
	lsls r1, r5, 2
	lsls r0, r4, 3
	adds r1, r0
	adds r1, r3
	ldr r0, [r2]
	ldr r1, [r1]
	ands r0, r1
	str r0, [r2]
	b _081621B4
	.pool
_081621A4:
	ldr r1, [r6]
	adds r0, r1, r7
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r0, 30
	ldr r2, =0x00000d07
	adds r1, r2
	strb r0, [r1]
_081621B4:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81620F4

	thumb_func_start sub_81621C0
sub_81621C0: @ 81621C0
	push {r4,r5,lr}
	ldr r0, =gUnknown_02038BCA
	ldrh r1, [r0]
	movs r0, 0xFA
	lsls r0, 1
	cmp r1, r0
	bne _081621DA
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000bec
	adds r0, r1
	bl sub_816534C
_081621DA:
	ldr r5, =gSaveBlock2Ptr
	ldr r0, [r5]
	ldr r1, =0x00000d04
	adds r2, r0, r1
	ldrh r1, [r2]
	ldr r0, =0x0000270e
	cmp r1, r0
	bhi _081621EE
	adds r0, r1, 0x1
	strh r0, [r2]
_081621EE:
	ldr r1, [r5]
	ldr r4, =0x00000cb2
	adds r1, r4
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	bl sub_8163E90
	ldr r1, =gUnknown_020375F0
	ldr r0, [r5]
	adds r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81621C0

	thumb_func_start sub_816222C
sub_816222C: @ 816222C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x3C
	movs r0, 0
	str r0, [sp, 0x24]
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r0, 30
	mov r10, r0
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x2C]
	ldr r0, =0x000040cf
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _08162266
	b _0816239C
_08162266:
	mov r0, r10
	ldr r1, [sp, 0x2C]
	bl sub_8164FCC
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x28]
	movs r7, 0
	mov r2, sp
	str r2, [sp, 0x34]
_0816227A:
	movs r3, 0xEC
	adds r0, r7, 0
	muls r0, r3
	movs r4, 0xE7
	lsls r4, 3
	adds r0, r4
	ldr r5, =gSaveBlock2Ptr
	ldr r1, [r5]
	movs r2, 0
	mov r8, r2
	mov r9, r2
	movs r5, 0
	adds r3, r7, 0x1
	str r3, [sp, 0x30]
	adds r1, r0
_08162298:
	ldm r1!, {r0}
	mov r4, r8
	orrs r4, r0
	mov r8, r4
	add r9, r0
	adds r5, 0x1
	cmp r5, 0x39
	bls _08162298
	movs r6, 0
	movs r5, 0
	movs r0, 0xEC
	adds r2, r7, 0
	muls r2, r0
_081622B2:
	ldr r3, =gSaveBlock2Ptr
	ldr r1, [r3]
	movs r0, 0x2C
	muls r0, r5
	adds r0, r2
	adds r1, r0
	ldr r4, =0x0000076c
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, 0
	beq _081622E4
	movs r0, 0xEF
	lsls r0, 3
	adds r4, r1, r0
	mov r0, r10
	str r2, [sp, 0x38]
	bl sub_8165C90
	ldrb r1, [r4]
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [sp, 0x38]
	cmp r1, r0
	bhi _081622E4
	adds r6, 0x1
_081622E4:
	adds r5, 0x1
	cmp r5, 0x3
	ble _081622B2
	ldr r0, =gUnknown_085DF9F6
	ldr r1, [sp, 0x2C]
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r6, r0
	blt _0816233E
	ldr r3, =gSaveBlock2Ptr
	ldr r2, [r3]
	movs r4, 0xEC
	adds r3, r7, 0
	muls r3, r4
	adds r1, r2, r3
	ldr r5, =0x0000073a
	adds r0, r1, r5
	ldrh r0, [r0]
	ldr r4, [sp, 0x28]
	cmp r0, r4
	bne _0816233E
	subs r5, 0x2
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, r10
	bne _0816233E
	mov r0, r8
	cmp r0, 0
	beq _0816233E
	movs r1, 0x82
	lsls r1, 4
	adds r0, r2, r1
	adds r0, r3
	ldr r0, [r0]
	cmp r0, r9
	bne _0816233E
	movs r2, 0x96
	lsls r2, 1
	adds r0, r7, r2
	ldr r3, [sp, 0x34]
	stm r3!, {r0}
	str r3, [sp, 0x34]
	ldr r4, [sp, 0x24]
	adds r4, 0x1
	str r4, [sp, 0x24]
_0816233E:
	ldr r7, [sp, 0x30]
	cmp r7, 0x4
	ble _0816227A
	ldr r5, [sp, 0x2C]
	cmp r5, 0
	bne _08162396
	bl sub_8165B20
	movs r7, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r4, =gUnknown_085DF9EC
	adds r2, r0, 0
	adds r2, 0xDC
	ldr r1, [sp, 0x24]
	lsls r0, r1, 2
	mov r5, sp
	adds r3, r0, r5
_08162362:
	ldrb r0, [r2]
	lsls r1, r0, 25
	lsrs r0, r1, 30
	cmp r0, 0
	beq _0816238E
	ldrb r0, [r2, 0x1]
	adds r0, r4
	ldrb r0, [r0]
	ldr r5, [sp, 0x28]
	cmp r0, r5
	bne _0816238E
	lsrs r0, r1, 30
	subs r0, 0x1
	cmp r0, r10
	bne _0816238E
	movs r1, 0xC8
	lsls r1, 1
	adds r0, r7, r1
	stm r3!, {r0}
	ldr r5, [sp, 0x24]
	adds r5, 0x1
	str r5, [sp, 0x24]
_0816238E:
	adds r2, 0x44
	adds r7, 0x1
	cmp r7, 0x3
	ble _08162362
_08162396:
	ldr r0, [sp, 0x24]
	cmp r0, 0
	bne _081623C0
_0816239C:
	movs r0, 0
	b _081623DA
	.pool
_081623C0:
	ldr r4, =gUnknown_02038BCA
	bl Random
	lsls r0, 16
	lsrs r0, 16
	ldr r1, [sp, 0x24]
	bl __modsi3
	lsls r0, 2
	add r0, sp
	ldr r0, [r0]
	strh r0, [r4]
	movs r0, 0x1
_081623DA:
	add sp, 0x3C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_816222C

	thumb_func_start sub_81623F0
sub_81623F0: @ 81623F0
	push {r4-r7,lr}
	ldr r6, =gSaveBlock2Ptr
	ldr r0, [r6]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r0, 30
	cmp r0, 0x2
	bne _08162414
	bl sub_8165E18
	b _08162530
	.pool
_08162414:
	ldr r0, =0x000040ce
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_81A39C4
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x7
	bl __udivsi3
	lsls r0, 16
	lsrs r5, r0, 16
	bl sub_8165C40
	subs r4, 0x2
	cmp r4, 0x1
	bhi _08162488
	ldr r1, [r6]
	ldr r2, =0x00000cb2
	adds r0, r1, r2
	ldrh r3, [r0]
	ldr r2, =gUnknown_02038BCA
	lsls r0, r3, 2
	ldr r4, =0x00000cb4
	adds r1, r4
	adds r0, r1, r0
	ldrh r0, [r0]
	strh r0, [r2]
	ldr r4, =gUnknown_02038BCC
	lsls r0, r3, 1
	adds r0, 0x1
	lsls r0, 1
	adds r1, r0
	ldrh r0, [r1]
	strh r0, [r4]
	ldrh r0, [r2]
	movs r1, 0
	bl sub_8162614
	ldrh r0, [r4]
	movs r1, 0x1
	bl sub_8162614
	b _08162530
	.pool
_08162488:
	bl sub_816222C
	lsls r0, 24
	cmp r0, 0
	beq _081624B4
	ldr r4, =gUnknown_02038BCA
	ldrh r0, [r4]
	movs r1, 0
	bl sub_8162614
	ldr r1, [r6]
	ldr r2, =0x00000cb2
	adds r0, r1, r2
	ldrh r0, [r0]
	lsls r0, 1
	adds r2, 0x2
	b _08162528
	.pool
_081624B4:
	lsls r7, r5, 24
	adds r5, r6, 0
	ldr r6, =0x00000cb2
_081624BA:
	ldr r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsrs r0, r7, 24
	bl sub_8162548
	lsls r0, 16
	lsrs r3, r0, 16
	movs r4, 0
	ldr r1, [r5]
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r4, r0
	bge _081624FC
	ldr r2, =0x00000cb4
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, r3
	beq _081624FC
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	subs r2, 0x2
	adds r0, r1, r2
	ldrh r2, [r0]
	ldr r0, =0x00000cb4
	adds r1, r0
_081624EE:
	adds r1, 0x2
	adds r4, 0x1
	cmp r4, r2
	bge _081624FC
	ldrh r0, [r1]
	cmp r0, r3
	bne _081624EE
_081624FC:
	ldr r0, [r5]
	ldr r1, =0x00000cb2
	adds r0, r1
	ldrh r0, [r0]
	cmp r4, r0
	bne _081624BA
	ldr r4, =gUnknown_02038BCA
	strh r3, [r4]
	ldrh r0, [r4]
	movs r1, 0
	bl sub_8162614
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r2, =0x00000cb2
	adds r0, r1, r2
	ldrh r2, [r0]
	adds r0, r2, 0x1
	cmp r0, 0x6
	bgt _08162530
	lsls r0, r2, 1
	ldr r2, =0x00000cb4
_08162528:
	adds r1, r2
	adds r1, r0
	ldrh r0, [r4]
	strh r0, [r1]
_08162530:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81623F0

	thumb_func_start sub_8162548
sub_8162548: @ 8162548
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r3, r0, 0
	lsls r1, 24
	lsrs r1, 24
	cmp r0, 0x7
	bhi _08162584
	cmp r1, 0x6
	bne _08162570
	ldr r2, =gUnknown_085DFA1A
	lsls r1, r0, 2
	adds r0, r2, 0x2
	adds r0, r1, r0
	adds r1, r2
	ldrh r0, [r0]
	ldrh r4, [r1]
	b _0816258A
	.pool
_08162570:
	ldr r2, =gUnknown_085DF9FA
	lsls r1, r3, 2
	adds r0, r2, 0x2
	adds r0, r1, r0
	adds r1, r2
	ldrh r0, [r0]
	ldrh r4, [r1]
	b _0816258A
	.pool
_08162584:
	ldr r1, =gUnknown_085DF9FA
	ldrh r0, [r1, 0x1E]
	ldrh r4, [r1, 0x1C]
_0816258A:
	subs r0, r4
	adds r0, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r5, 0
	bl __umodsi3
	adds r4, r0
	lsls r4, 16
	lsrs r5, r4, 16
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8162548

	thumb_func_start sub_81625B4
sub_81625B4: @ 81625B4
	push {r4,lr}
	adds r4, r2, 0
	lsls r0, 24
	lsrs r0, 24
	adds r2, r0, 0
	lsls r1, 24
	lsrs r1, 24
	cmp r0, 0x7
	bhi _081625F4
	cmp r1, 0x6
	bne _081625D4
	ldr r1, =gUnknown_085DFA1A
	lsls r2, r0, 2
	b _081625D8
	.pool
_081625D4:
	ldr r1, =gUnknown_085DF9FA
	lsls r2, 2
_081625D8:
	adds r0, r1, 0x2
	adds r0, r2, r0
	adds r2, r1
	ldrh r0, [r0]
	ldrh r1, [r2]
	subs r0, r1
	adds r0, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	ldrh r0, [r2]
	b _08162604
	.pool
_081625F4:
	ldr r0, =gUnknown_085DF9FA
	ldrh r1, [r0, 0x1E]
	ldrh r2, [r0, 0x1C]
	subs r1, r2
	adds r1, 0x1
	lsls r1, 16
	lsrs r1, 16
	ldrh r0, [r0, 0x1C]
_08162604:
	strh r0, [r4]
	strb r1, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81625B4

	thumb_func_start sub_8162614
sub_8162614: @ 8162614
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r6, r4, 0
	lsls r1, 24
	lsrs r5, r1, 24
	bl sub_8165C40
	movs r0, 0xFA
	lsls r0, 1
	cmp r4, r0
	bne _08162640
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000bed
	adds r0, r1
	b _081626BA
	.pool
_08162640:
	ldr r0, =0x000003fe
	cmp r4, r0
	bne _08162650
	bl sub_81A4DD8
	b _08162788
	.pool
_08162650:
	ldr r0, =0x0000012b
	cmp r4, r0
	bhi _0816266C
	ldr r0, =gUnknown_0203BC88
	ldr r1, [r0]
	movs r0, 0x34
	muls r0, r4
	adds r0, r1
	b _081626BA
	.pool
_0816266C:
	ldr r0, =0x0000018f
	cmp r4, r0
	bhi _08162698
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0xfffffed4
	adds r2, r4, r1
	movs r1, 0xEC
	muls r1, r2
	adds r0, r1
	ldr r1, =0x00000739
	adds r0, r1
	b _081626BA
	.pool
_08162698:
	ldr r3, =gUnknown_08610970
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r0, =0xfffffe70
	adds r2, r6, r0
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r1, r0
	adds r1, 0xDC
	ldrb r0, [r1]
	lsls r0, 27
	lsrs r0, 27
	movs r1, 0x58
	muls r0, r1
	adds r0, r3
	adds r0, 0x32
_081626BA:
	ldrb r2, [r0]
	movs r1, 0
	ldr r3, =gUnknown_085DCEDC
	ldrb r0, [r3]
	cmp r0, r2
	beq _081626D4
_081626C6:
	adds r1, 0x1
	cmp r1, 0x1D
	bhi _081626D4
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	bne _081626C6
_081626D4:
	cmp r1, 0x1E
	beq _08162700
	ldr r0, =gUnknown_085DCF0E
	adds r0, r1, r0
	ldrb r1, [r0]
	cmp r5, 0x1
	beq _08162744
	cmp r5, 0x1
	ble _0816272E
	cmp r5, 0xF
	bne _0816272E
	b _08162750
	.pool
_08162700:
	movs r1, 0
	ldr r3, =gUnknown_085DCEFA
	ldrb r0, [r3]
	cmp r0, r2
	beq _08162718
_0816270A:
	adds r1, 0x1
	cmp r1, 0x13
	bhi _08162718
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	bne _0816270A
_08162718:
	cmp r1, 0x14
	beq _0816275C
	ldr r0, =gUnknown_085DCF2C
	adds r0, r1, r0
	ldrb r1, [r0]
	cmp r5, 0x1
	beq _08162744
	cmp r5, 0x1
	ble _0816272E
	cmp r5, 0xF
	beq _08162750
_0816272E:
	ldr r0, =0x00004010
	bl VarSet
	b _08162788
	.pool
_08162744:
	ldr r0, =0x00004011
	bl VarSet
	b _08162788
	.pool
_08162750:
	ldr r0, =0x0000401e
	bl VarSet
	b _08162788
	.pool
_0816275C:
	cmp r5, 0x1
	beq _08162770
	cmp r5, 0x1
	ble _08162768
	cmp r5, 0xF
	beq _08162780
_08162768:
	ldr r0, =0x00004010
	b _08162772
	.pool
_08162770:
	ldr r0, =0x00004011
_08162772:
	movs r1, 0x7
	bl VarSet
	b _08162788
	.pool
_08162780:
	ldr r0, =0x0000401e
	movs r1, 0x7
	bl VarSet
_08162788:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8162614

	thumb_func_start sub_8162794
sub_8162794: @ 8162794
	push {lr}
	movs r0, 0xFA
	lsls r0, 1
	movs r1, 0
	bl sub_8162614
	pop {r0}
	bx r0
	thumb_func_end sub_8162794

	thumb_func_start sub_81627A4
sub_81627A4: @ 81627A4
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r5, r4, 0
	bl sub_8165C40
	movs r0, 0xFA
	lsls r0, 1
	cmp r4, r0
	bne _081627CC
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000bed
	adds r0, r1
	b _08162836
	.pool
_081627CC:
	ldr r0, =0x0000012b
	cmp r4, r0
	bhi _081627E8
	ldr r0, =gUnknown_0203BC88
	ldr r1, [r0]
	movs r0, 0x34
	muls r0, r4
	adds r0, r1
	b _08162836
	.pool
_081627E8:
	ldr r0, =0x0000018f
	cmp r4, r0
	bhi _08162814
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0xfffffed4
	adds r2, r4, r1
	movs r1, 0xEC
	muls r1, r2
	adds r0, r1
	ldr r1, =0x00000739
	adds r0, r1
	b _08162836
	.pool
_08162814:
	ldr r3, =gUnknown_08610970
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r0, =0xfffffe70
	adds r2, r5, r0
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r1, r0
	adds r1, 0xDC
	ldrb r0, [r1]
	lsls r0, 27
	lsrs r0, 27
	movs r1, 0x58
	muls r0, r1
	adds r0, r3
	adds r0, 0x32
_08162836:
	ldrb r2, [r0]
	movs r1, 0
	ldr r3, =gUnknown_085DCEDC
	ldrb r0, [r3]
	cmp r0, r2
	beq _08162850
_08162842:
	adds r1, 0x1
	cmp r1, 0x1D
	bhi _08162850
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	bne _08162842
_08162850:
	cmp r1, 0x1E
	beq _0816286C
	ldr r0, =gUnknown_085DCF0E
	b _08162892
	.pool
_0816286C:
	movs r1, 0
	ldr r3, =gUnknown_085DCEFA
	ldrb r0, [r3]
	cmp r0, r2
	beq _08162884
_08162876:
	adds r1, 0x1
	cmp r1, 0x13
	bhi _08162884
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	bne _08162876
_08162884:
	cmp r1, 0x14
	bne _08162890
	movs r0, 0x7
	b _08162896
	.pool
_08162890:
	ldr r0, =gUnknown_085DCF2C
_08162892:
	adds r0, r1, r0
	ldrb r0, [r0]
_08162896:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81627A4

	thumb_func_start sub_81628A0
sub_81628A0: @ 81628A0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	movs r1, 0
	mov r8, r1
	mov r10, r0
	movs r5, 0
	ldr r2, =gSaveBlock2Ptr
	ldr r0, [r2]
	mov r4, r10
	ldrb r4, [r4, 0xC]
	str r4, [sp, 0x18]
	mov r9, r5
	movs r7, 0x4
	str r7, [sp, 0x1C]
	ldr r1, =0x00000744
	adds r1, r0
	mov r12, r1
_081628CA:
	movs r6, 0
	movs r3, 0
	mov r2, r12
	ldrb r0, [r2]
	ldr r4, [sp, 0x18]
	cmp r0, r4
	bne _081628FA
	mov r4, r9
	mov r2, r10
	adds r2, 0xC
_081628DE:
	adds r3, 0x1
	cmp r3, 0x3
	bgt _081628FA
	ldr r7, =gSaveBlock2Ptr
	ldr r0, [r7]
	adds r1, r3, r4
	ldr r7, =0x00000744
	adds r0, r7
	adds r0, r1
	adds r1, r2, r3
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _081628DE
_081628FA:
	cmp r3, 0x4
	bne _08162944
	movs r6, 0
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	ldr r3, =0x0000073c
	adds r0, r3
	ldr r2, [sp, 0x1C]
	adds r0, r2
	ldrb r0, [r0]
	mov r4, r10
	ldrb r4, [r4, 0x8]
	cmp r0, r4
	bne _08162944
	adds r1, r0, 0
	mov r2, r9
	adds r2, 0x4
_0816291C:
	cmp r1, 0xFF
	bne _08162930
	movs r6, 0x7
	b _08162944
	.pool
_08162930:
	adds r6, 0x1
	cmp r6, 0x6
	bgt _08162944
	ldr r7, =gSaveBlock2Ptr
	ldr r0, [r7]
	adds r0, r3
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, r1
	beq _0816291C
_08162944:
	cmp r6, 0x7
	beq _0816295A
	movs r0, 0xEC
	add r9, r0
	ldr r1, [sp, 0x1C]
	adds r1, 0xEC
	str r1, [sp, 0x1C]
	add r12, r0
	adds r5, 0x1
	cmp r5, 0x4
	ble _081628CA
_0816295A:
	cmp r5, 0x4
	bgt _08162974
	ldr r2, =gSaveBlock2Ptr
	ldr r0, [r2]
	movs r1, 0xEC
	muls r1, r5
	adds r0, r1
	movs r4, 0xE7
	lsls r4, 3
	adds r0, r4
	b _081629B2
	.pool
_08162974:
	movs r5, 0
	ldr r7, =gSaveBlock2Ptr
	ldr r0, [r7]
	ldr r1, =0x0000073a
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _0816299E
	adds r3, r7, 0
	adds r2, r1, 0
	movs r1, 0
_0816298A:
	adds r1, 0xEC
	adds r5, 0x1
	cmp r5, 0x4
	bgt _081629C4
	ldr r0, [r3]
	adds r0, r1
	adds r0, r2
	ldrh r0, [r0]
	cmp r0, 0
	bne _0816298A
_0816299E:
	cmp r5, 0x4
	bgt _081629C4
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	movs r1, 0xEC
	muls r1, r5
	adds r0, r1
	movs r2, 0xE7
	lsls r2, 3
	adds r0, r2
_081629B2:
	mov r1, r10
	movs r2, 0xEC
	bl memcpy
	b _08162A8A
	.pool
_081629C4:
	mov r2, sp
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r3, =0x0000073a
	adds r0, r3
	ldrh r0, [r0]
	movs r1, 0
	strh r0, [r2]
	add r0, sp, 0xC
	strh r1, [r0]
	movs r7, 0x1
	add r8, r7
	movs r5, 0x1
	add r0, sp, 0xC
	mov r9, r0
	mov r12, r3
_081629E4:
	movs r3, 0
	adds r7, r5, 0x1
	cmp r3, r8
	bge _08162A2E
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	movs r2, 0xEC
	adds r1, r5, 0
	muls r1, r2
	adds r0, r1
	mov r1, r12
	adds r4, r0, r1
	mov r6, sp
_081629FE:
	lsls r0, r3, 1
	add r0, sp
	ldrh r2, [r4]
	adds r1, r2, 0
	ldrh r0, [r0]
	cmp r1, r0
	bcs _08162A24
	movs r3, 0
	movs r4, 0x1
	mov r8, r4
	strh r2, [r6]
	mov r0, r9
	strh r5, [r0]
	b _08162A2E
	.pool
_08162A24:
	cmp r1, r0
	bhi _08162A2E
	adds r3, 0x1
	cmp r3, r8
	blt _081629FE
_08162A2E:
	cmp r3, r8
	bne _08162A54
	mov r1, r8
	lsls r2, r1, 1
	mov r4, sp
	adds r3, r4, r2
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	movs r4, 0xEC
	adds r1, r5, 0
	muls r1, r4
	adds r0, r1
	add r0, r12
	ldrh r0, [r0]
	strh r0, [r3]
	add r2, r9
	strh r5, [r2]
	movs r0, 0x1
	add r8, r0
_08162A54:
	adds r5, r7, 0
	cmp r5, 0x4
	ble _081629E4
	bl Random
	lsls r0, 16
	lsrs r0, 16
	mov r1, r8
	bl __modsi3
	adds r5, r0, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	lsls r1, r5, 1
	add r1, sp
	adds r1, 0xC
	ldrh r2, [r1]
	movs r1, 0xEC
	muls r1, r2
	adds r0, r1
	movs r1, 0xE7
	lsls r1, 3
	adds r0, r1
	mov r1, r10
	movs r2, 0xEC
	bl memcpy
_08162A8A:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81628A0

	thumb_func_start sub_8162AA0
sub_8162AA0: @ 8162AA0
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r5, r4, 0
	bl sub_8165C40
	movs r0, 0xFA
	lsls r0, 1
	cmp r4, r0
	bne _08162AD0
	ldr r1, =gTrainerPicIndices
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000bed
	adds r0, r2
	ldrb r0, [r0]
	adds r0, r1
	b _08162BC8
	.pool
_08162AD0:
	ldr r0, =0x000003fe
	cmp r4, r0
	bne _08162AE4
	bl sub_81A4CB0
	lsls r0, 24
	lsrs r0, 24
	b _08162BCA
	.pool
_08162AE4:
	ldr r0, =0x0000012b
	cmp r4, r0
	bhi _08162B08
	ldr r2, =gTrainerPicIndices
	ldr r0, =gUnknown_0203BC88
	ldr r1, [r0]
	movs r0, 0x34
	muls r0, r4
	adds r0, r1
	ldrb r0, [r0]
	adds r0, r2
	b _08162BC8
	.pool
_08162B08:
	ldr r0, =0x0000018f
	cmp r4, r0
	bhi _08162B64
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	beq _08162B38
	ldr r4, =gTrainerPicIndices
	bl sub_818649C
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	b _08162BC8
	.pool
_08162B38:
	ldr r3, =gTrainerPicIndices
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0xfffffed4
	adds r2, r4, r1
	movs r1, 0xEC
	muls r1, r2
	adds r0, r1
	ldr r2, =0x00000739
	adds r0, r2
	ldrb r0, [r0]
	adds r0, r3
	b _08162BC8
	.pool
_08162B64:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	bne _08162BB0
	ldr r4, =gTrainerPicIndices
	ldr r3, =gUnknown_08610970
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r0, =0xfffffe70
	adds r2, r5, r0
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r1, r0
	adds r1, 0xDC
	ldrb r0, [r1]
	lsls r0, 27
	lsrs r0, 27
	movs r1, 0x58
	muls r0, r1
	adds r0, r3
	adds r0, 0x32
	ldrb r0, [r0]
	adds r0, r4
	b _08162BC8
	.pool
_08162BB0:
	ldr r5, =gTrainerPicIndices
	ldr r4, =gUnknown_08610970
	bl sub_81864A8
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x58
	muls r0, r1
	adds r0, r4
	adds r0, 0x32
	ldrb r0, [r0]
	adds r0, r5
_08162BC8:
	ldrb r0, [r0]
_08162BCA:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8162AA0

	thumb_func_start sub_8162BD8
sub_8162BD8: @ 8162BD8
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r5, r4, 0
	bl sub_8165C40
	movs r0, 0xFA
	lsls r0, 1
	cmp r4, r0
	bne _08162C08
	ldr r1, =gTrainerClassNameIndices
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000bed
	adds r0, r2
	ldrb r0, [r0]
	b _08162C26
	.pool
_08162C08:
	ldr r0, =0x000003fe
	cmp r4, r0
	bne _08162C1C
	bl sub_81A4D00
	lsls r0, 24
	lsrs r0, 24
	b _08162D1E
	.pool
_08162C1C:
	ldr r0, =0x00000c03
	cmp r4, r0
	bne _08162C38
	ldr r0, =gTrainers
	ldr r1, =0x00007da1
_08162C26:
	adds r0, r1
	ldrb r0, [r0]
	b _08162D1E
	.pool
_08162C38:
	ldr r0, =0x0000012b
	cmp r4, r0
	bhi _08162C60
	ldr r2, =gTrainerClassNameIndices
	ldr r0, =gUnknown_0203BC88
	ldr r1, [r0]
	movs r0, 0x34
	muls r0, r4
	adds r0, r1
	ldrb r0, [r0]
	adds r0, r2
	ldrb r0, [r0]
	b _08162D1E
	.pool
_08162C60:
	ldr r0, =0x0000018f
	cmp r4, r0
	bhi _08162CBC
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	beq _08162C90
	ldr r4, =gTrainerClassNameIndices
	bl sub_818649C
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	ldrb r0, [r0]
	b _08162D1E
	.pool
_08162C90:
	ldr r3, =gTrainerClassNameIndices
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0xfffffed4
	adds r2, r4, r1
	movs r1, 0xEC
	muls r1, r2
	adds r0, r1
	ldr r2, =0x00000739
	adds r0, r2
	ldrb r0, [r0]
	adds r0, r3
	ldrb r0, [r0]
	b _08162D1E
	.pool
_08162CBC:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	beq _08162CF4
	ldr r5, =gTrainerClassNameIndices
	ldr r4, =gUnknown_08610970
	bl sub_81864A8
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x58
	muls r0, r1
	adds r0, r4
	adds r0, 0x32
	ldrb r0, [r0]
	adds r0, r5
	ldrb r0, [r0]
	b _08162D1E
	.pool
_08162CF4:
	ldr r4, =gTrainerClassNameIndices
	ldr r3, =gUnknown_08610970
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r0, =0xfffffe70
	adds r2, r5, r0
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r1, r0
	adds r1, 0xDC
	ldrb r0, [r1]
	lsls r0, 27
	lsrs r0, 27
	movs r1, 0x58
	muls r0, r1
	adds r0, r3
	adds r0, 0x32
	ldrb r0, [r0]
	adds r0, r4
	ldrb r0, [r0]
_08162D1E:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8162BD8

	thumb_func_start sub_8162D34
sub_8162D34: @ 8162D34
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r5, r4, 0
	bl sub_8165C40
	movs r0, 0xFA
	lsls r0, 1
	cmp r4, r0
	bne _08162D5C
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000bed
	adds r0, r1
	b _08162E0A
	.pool
_08162D5C:
	ldr r0, =0x0000012b
	cmp r4, r0
	bhi _08162D78
	ldr r0, =gUnknown_0203BC88
	ldr r1, [r0]
	movs r0, 0x34
	muls r0, r4
	adds r0, r1
	b _08162E0A
	.pool
_08162D78:
	ldr r0, =0x0000018f
	cmp r4, r0
	bhi _08162DC0
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	beq _08162DA0
	bl sub_818649C
	lsls r0, 24
	lsrs r0, 24
	b _08162E0C
	.pool
_08162DA0:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0xfffffed4
	adds r2, r4, r1
	movs r1, 0xEC
	muls r1, r2
	adds r0, r1
	ldr r1, =0x00000739
	adds r0, r1
	b _08162E0A
	.pool
_08162DC0:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	beq _08162DE8
	ldr r4, =gUnknown_08610970
	bl sub_81864A8
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x58
	muls r0, r1
	adds r0, r4
	b _08162E08
	.pool
_08162DE8:
	ldr r3, =gUnknown_08610970
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r0, =0xfffffe70
	adds r2, r5, r0
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r1, r0
	adds r1, 0xDC
	ldrb r0, [r1]
	lsls r0, 27
	lsrs r0, 27
	movs r1, 0x58
	muls r0, r1
	adds r0, r3
_08162E08:
	adds r0, 0x32
_08162E0A:
	ldrb r0, [r0]
_08162E0C:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8162D34

	thumb_func_start sub_8162E20
sub_8162E20: @ 8162E20
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r1, 16
	lsrs r5, r1, 16
	movs r4, 0
	bl sub_8165C40
	movs r0, 0xFA
	lsls r0, 1
	cmp r5, r0
	bne _08162E54
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xBF
	lsls r1, 4
	adds r2, r0, r1
_08162E40:
	adds r0, r6, r4
	adds r1, r2, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r4, 0x1
	cmp r4, 0x6
	ble _08162E40
	b _08162F5C
	.pool
_08162E54:
	ldr r0, =0x000003fe
	cmp r5, r0
	bne _08162E68
	adds r0, r6, 0
	bl sub_81A4D50
	b _08162F62
	.pool
_08162E68:
	ldr r0, =0x00000c03
	cmp r5, r0
	bne _08162E88
	ldr r2, =gTrainers + TRAINER_STEVEN * 0x28 + 0x4 @ Steven's name
_08162E70:
	adds r0, r6, r4
	adds r1, r4, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r4, 0x1
	cmp r4, 0x6
	ble _08162E70
	b _08162F5C
	.pool
_08162E88:
	ldr r0, =0x0000012b
	cmp r5, r0
	bhi _08162EB4
	ldr r0, =gUnknown_0203BC88
	ldr r1, [r0]
	movs r0, 0x34
	muls r0, r5
	adds r0, r1
	adds r2, r0, 0x4
_08162E9A:
	adds r0, r6, r4
	adds r1, r2, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r4, 0x1
	cmp r4, 0x6
	ble _08162E9A
	b _08162F5C
	.pool
_08162EB4:
	ldr r0, =0x0000018f
	cmp r5, r0
	bhi _08162F00
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	beq _08162ED8
	adds r0, r6, 0
	bl sub_8186468
	b _08162F62
	.pool
_08162ED8:
	ldr r2, =gSaveBlock2Ptr
	movs r0, 0xEC
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =0xfffef2a8
	adds r1, r0
	ldr r0, [r2]
	adds r0, r1
	adds r1, r0, 0x4
	adds r0, 0xE4
	ldrb r2, [r0]
	adds r0, r6, 0
	bl sub_81DB5E8
	b _08162F62
	.pool
_08162F00:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	beq _08162F24
	bl sub_81864A8
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_81864C0
	lsls r0, 24
	lsrs r4, r0, 24
	b _08162F3E
	.pool
_08162F24:
	ldr r1, =gSaveBlock2Ptr
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	ldr r2, =0xffff969c
	adds r0, r2
	ldr r1, [r1]
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 27
	lsrs r5, r0, 27
	adds r1, 0x3F
	ldrb r4, [r1]
_08162F3E:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_81A1650
	adds r1, r0, 0
	adds r0, r6, 0
	adds r2, r4, 0
	bl sub_81DB5E8
	b _08162F62
	.pool
_08162F5C:
	adds r1, r6, r4
	movs r0, 0xFF
	strb r0, [r1]
_08162F62:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8162E20

	thumb_func_start sub_8162F68
sub_8162F68: @ 8162F68
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r5, r4, 0
	bl sub_8165C40
	movs r0, 0xFA
	lsls r0, 1
	cmp r4, r0
	bne _08162F90
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000bed
	adds r0, r1
	b _0816300E
	.pool
_08162F90:
	ldr r0, =0x000003fe
	cmp r4, r0
	bne _08162FA4
	bl sub_81A4DB8
	lsls r0, 24
	lsrs r0, 24
	b _08163042
	.pool
_08162FA4:
	ldr r0, =0x0000012b
	cmp r4, r0
	bhi _08162FC0
	ldr r0, =gUnknown_0203BC88
	ldr r1, [r0]
	movs r0, 0x34
	muls r0, r4
	adds r0, r1
	b _0816300E
	.pool
_08162FC0:
	ldr r0, =0x0000018f
	cmp r4, r0
	bhi _08162FEC
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0xfffffed4
	adds r2, r4, r1
	movs r1, 0xEC
	muls r1, r2
	adds r0, r1
	ldr r1, =0x00000739
	adds r0, r1
	b _0816300E
	.pool
_08162FEC:
	ldr r3, =gUnknown_08610970
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r0, =0xfffffe70
	adds r2, r5, r0
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r1, r0
	adds r1, 0xDC
	ldrb r0, [r1]
	lsls r0, 27
	lsrs r0, 27
	movs r1, 0x58
	muls r0, r1
	adds r0, r3
	adds r0, 0x32
_0816300E:
	ldrb r2, [r0]
	movs r1, 0
	ldr r3, =gUnknown_085DCEFA
	ldrb r0, [r3]
	cmp r0, r2
	beq _08163028
_0816301A:
	adds r1, 0x1
	cmp r1, 0x13
	bhi _08163028
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	bne _0816301A
_08163028:
	cmp r1, 0x14
	bne _08163040
	movs r0, 0
	b _08163042
	.pool
_08163040:
	movs r0, 0x1
_08163042:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8162F68

	thumb_func_start sub_8163048
sub_8163048: @ 8163048
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl zero_enemy_party_data
	ldr r0, =gUnknown_02038BCA
	ldrh r0, [r0]
	movs r1, 0
	adds r2, r4, 0
	bl sub_81630C4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8163048

	thumb_func_start sub_816306C
sub_816306C: @ 816306C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl zero_enemy_party_data
	ldr r0, =gUnknown_02038BCA
	ldrh r0, [r0]
	movs r1, 0
	adds r2, r4, 0
	bl sub_81630C4
	ldr r0, =gUnknown_02038BCC
	ldrh r0, [r0]
	movs r1, 0x3
	adds r2, r4, 0
	bl sub_81630C4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816306C

	thumb_func_start sub_81630A0
sub_81630A0: @ 81630A0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl zero_enemy_party_data
	ldr r0, =gUnknown_02038BCA
	ldrh r0, [r0]
	movs r1, 0
	adds r2, r4, 0
	bl sub_8165EA4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81630A0

	thumb_func_start sub_81630C4
sub_81630C4: @ 81630C4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x40
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x18]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x1C]
	add r4, sp, 0x14
	movs r0, 0xFF
	strb r0, [r4]
	bl sub_8165C40
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x20]
	ldr r0, =0x0000012b
	cmp r5, r0
	bhi _08163138
	adds r0, r5, 0
	bl sub_8165D08
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x24]
	ldr r0, =gUnknown_02038BCA
	ldrh r2, [r0]
	ldr r0, =gUnknown_0203BC88
	ldr r1, [r0]
	movs r0, 0x34
	muls r0, r2
	adds r0, r1
	ldr r0, [r0, 0x30]
	str r0, [sp, 0x2C]
	movs r0, 0
	str r0, [sp, 0x28]
	ldr r2, [sp, 0x2C]
	ldrh r1, [r2]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _08163124
	b _08163278
_08163124:
	b _08163260
	.pool
_08163138:
	movs r0, 0xFA
	lsls r0, 1
	cmp r5, r0
	bne _08163180
	ldr r7, [sp, 0x18]
	adds r0, r7, 0x3
	cmp r7, r0
	blt _0816314A
	b _08163426
_0816314A:
	ldr r4, =gSaveBlock2Ptr
_0816314C:
	movs r0, 0x64
	muls r0, r7
	ldr r1, =gEnemyParty
	adds r0, r1
	ldr r5, [sp, 0x18]
	subs r2, r7, r5
	movs r1, 0x2C
	muls r2, r1
	movs r6, 0xC2
	lsls r6, 4
	adds r2, r6
	ldr r1, [r4]
	adds r1, r2
	bl sub_806819C
	adds r7, 0x1
	adds r0, r5, 0
	adds r0, 0x3
	cmp r7, r0
	blt _0816314C
	b _08163426
	.pool
_08163180:
	ldr r0, =0x000003fe
	cmp r5, r0
	bne _08163190
	bl sub_81A4E04
	b _08163426
	.pool
_08163190:
	ldr r0, =0x0000018f
	cmp r5, r0
	bhi _08163218
	movs r6, 0
	ldr r7, [sp, 0x18]
	ldr r1, [sp, 0x1C]
	adds r0, r7, r1
	cmp r7, r0
	blt _081631A4
	b _08163426
_081631A4:
	ldr r2, =0xfffffed4
	adds r1, r5, r2
	movs r0, 0xEC
	adds r2, r1, 0
	muls r2, r0
	mov r8, r2
	muls r0, r5
	ldr r5, =0xfffef2a8
	adds r4, r0, r5
_081631B6:
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	movs r0, 0x2C
	adds r2, r6, 0
	muls r2, r0
	mov r1, r8
	adds r0, r2, r1
	adds r1, r3, r0
	ldr r5, =0x0000076c
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, 0
	beq _081631F0
	adds r5, 0xC
	adds r0, r1, r5
	ldrb r0, [r0]
	ldr r1, [sp, 0x20]
	cmp r0, r1
	bhi _081631F0
	movs r0, 0x64
	muls r0, r7
	ldr r1, =gEnemyParty
	adds r0, r1
	adds r1, r3, r4
	adds r2, 0x34
	adds r1, r2
	movs r2, 0
	bl sub_8068338
_081631F0:
	adds r6, 0x1
	adds r7, 0x1
	ldr r2, [sp, 0x18]
	ldr r5, [sp, 0x1C]
	adds r0, r2, r5
	cmp r7, r0
	blt _081631B6
	b _08163426
	.pool
_08163218:
	ldr r7, [sp, 0x18]
	adds r0, r7, 0x3
	cmp r7, r0
	blt _08163222
	b _08163426
_08163222:
	ldr r6, =gSaveBlock2Ptr
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	ldr r1, =0xffff969c
	adds r5, r0, r1
	movs r4, 0
_08163230:
	movs r0, 0x64
	muls r0, r7
	ldr r1, =gEnemyParty
	adds r0, r1
	ldr r1, [r6]
	adds r1, r5
	lsrs r2, r4, 24
	bl sub_8068528
	movs r2, 0x80
	lsls r2, 17
	adds r4, r2
	adds r7, 0x1
	ldr r0, [sp, 0x18]
	adds r0, 0x3
	cmp r7, r0
	blt _08163230
	b _08163426
	.pool
_08163260:
	ldr r0, [sp, 0x28]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x28]
	lsls r0, 1
	ldr r5, [sp, 0x2C]
	adds r0, r5
	ldrh r1, [r0]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _08163260
_08163278:
	movs r7, 0
	bl Random
	adds r4, r0, 0
	bl Random
	lsls r4, 16
	lsrs r4, 16
	lsls r0, 16
	orrs r4, r0
	str r4, [sp, 0x30]
	ldr r6, [sp, 0x1C]
	cmp r7, r6
	bne _08163296
	b _08163426
_08163296:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	ldr r1, [sp, 0x28]
	bl __modsi3
	lsls r0, 1
	ldr r1, [sp, 0x2C]
	adds r0, r1
	ldrh r4, [r0]
	ldr r2, [sp, 0x20]
	cmp r2, 0x32
	beq _081632B6
	cmp r2, 0x14
	bne _081632BE
_081632B6:
	ldr r0, =0x00000351
	cmp r4, r0
	bls _081632BE
	b _0816341E
_081632BE:
	movs r6, 0
	ldr r5, [sp, 0x18]
	adds r5, r7
	mov r8, r5
	b _081632D2
	.pool
_081632D0:
	adds r6, 0x1
_081632D2:
	cmp r6, r8
	bge _081632F6
	movs r1, 0x64
	adds r0, r6, 0
	muls r0, r1
	ldr r2, =gEnemyParty
	adds r0, r2
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	ldr r1, =gUnknown_0203BC8C
	ldr r2, [r1]
	lsls r1, r4, 4
	adds r1, r2
	ldrh r1, [r1]
	cmp r0, r1
	bne _081632D0
_081632F6:
	cmp r6, r8
	beq _081632FC
	b _0816341E
_081632FC:
	movs r6, 0
	cmp r6, r8
	bge _08163346
	ldr r5, =gBattleFrontierHeldItems
	mov r9, r5
	movs r3, 0
_08163308:
	ldr r0, =gEnemyParty
	adds r5, r3, r0
	adds r0, r5, 0
	movs r1, 0xC
	movs r2, 0
	str r3, [sp, 0x38]
	bl GetMonData
	ldr r3, [sp, 0x38]
	cmp r0, 0
	beq _0816333E
	adds r0, r5, 0
	movs r1, 0xC
	movs r2, 0
	bl GetMonData
	ldr r1, =gUnknown_0203BC8C
	ldr r2, [r1]
	lsls r1, r4, 4
	adds r1, r2
	ldrb r1, [r1, 0xA]
	lsls r1, 1
	add r1, r9
	ldr r3, [sp, 0x38]
	ldrh r1, [r1]
	cmp r0, r1
	beq _08163346
_0816333E:
	adds r3, 0x64
	adds r6, 0x1
	cmp r6, r8
	blt _08163308
_08163346:
	cmp r6, r8
	bne _0816341E
	movs r6, 0
	cmp r6, r7
	bge _08163368
	add r0, sp, 0xC
	ldrh r0, [r0]
	cmp r0, r4
	beq _08163368
	add r1, sp, 0xC
_0816335A:
	adds r1, 0x2
	adds r6, 0x1
	cmp r6, r7
	bge _08163368
	ldrh r0, [r1]
	cmp r0, r4
	bne _0816335A
_08163368:
	cmp r6, r7
	bne _0816341E
	lsls r0, r7, 1
	add r0, sp
	adds r0, 0xC
	strh r4, [r0]
	movs r1, 0x64
	mov r0, r8
	muls r0, r1
	ldr r2, =gEnemyParty
	adds r0, r2
	ldr r5, =gUnknown_0203BC8C
	ldr r2, [r5]
	lsls r4, 4
	adds r2, r4, r2
	ldrh r1, [r2]
	ldrb r3, [r2, 0xC]
	ldr r6, [sp, 0x24]
	str r6, [sp]
	ldrb r2, [r2, 0xB]
	str r2, [sp, 0x4]
	ldr r2, [sp, 0x30]
	str r2, [sp, 0x8]
	ldr r2, [sp, 0x20]
	bl sub_8068634
	movs r0, 0xFF
	mov r6, sp
	strb r0, [r6, 0x14]
	movs r6, 0
	adds r0, r7, 0x1
	str r0, [sp, 0x34]
	mov r9, r4
	movs r0, 0x64
	mov r3, r8
	muls r3, r0
	mov r1, r9
	str r1, [sp, 0x3C]
	ldr r2, =gEnemyParty
	mov r10, r2
_081633B8:
	ldr r0, [r5]
	ldr r7, [sp, 0x3C]
	adds r0, r7, r0
	lsls r4, r6, 1
	adds r0, 0x2
	adds r0, r4
	ldrh r1, [r0]
	lsls r2, r6, 24
	lsrs r2, 24
	mov r7, r10
	adds r0, r3, r7
	str r3, [sp, 0x38]
	bl sub_80691F4
	ldr r0, [r5]
	ldr r1, [sp, 0x3C]
	adds r0, r1, r0
	adds r0, 0x2
	adds r0, r4
	ldrh r0, [r0]
	ldr r3, [sp, 0x38]
	cmp r0, 0xDA
	bne _081633EC
	movs r0, 0
	mov r2, sp
	strb r0, [r2, 0x14]
_081633EC:
	adds r6, 0x1
	cmp r6, 0x3
	ble _081633B8
	movs r5, 0x64
	mov r4, r8
	muls r4, r5
	ldr r6, =gEnemyParty
	adds r4, r6
	adds r0, r4, 0
	movs r1, 0x20
	add r2, sp, 0x14
	bl SetMonData
	ldr r0, =gUnknown_0203BC8C
	ldr r0, [r0]
	add r0, r9
	ldrb r2, [r0, 0xA]
	lsls r2, 1
	ldr r0, =gBattleFrontierHeldItems
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0xC
	bl SetMonData
	ldr r7, [sp, 0x34]
_0816341E:
	ldr r0, [sp, 0x1C]
	cmp r7, r0
	beq _08163426
	b _08163296
_08163426:
	add sp, 0x40
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81630C4

	thumb_func_start sub_8163444
sub_8163444: @ 8163444
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x8]
	movs r1, 0xFF
	add r0, sp, 0x4
	strb r1, [r0]
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	movs r0, 0xDC
	adds r0, r2
	mov r10, r0
	ldrb r0, [r0, 0x1]
	movs r1, 0x9
	str r1, [sp, 0x10]
	cmp r0, 0x4
	bhi _08163474
	movs r0, 0x6
	str r0, [sp, 0x10]
_08163474:
	ldr r1, =0x00000ca9
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, 0x3
	ands r0, r1
	movs r1, 0x32
	str r1, [sp, 0xC]
	cmp r0, 0
	beq _0816348A
	movs r0, 0x64
	str r0, [sp, 0xC]
_0816348A:
	movs r7, 0
	adds r2, 0xE2
	str r2, [sp, 0x14]
	add r1, sp, 0x4
	mov r9, r1
_08163494:
	ldr r2, [sp, 0x8]
	adds r6, r2, r7
	movs r0, 0x64
	muls r0, r6
	ldr r1, =gEnemyParty
	adds r0, r1
	lsls r5, r7, 1
	adds r4, r5, r7
	lsls r4, 2
	mov r2, r10
	adds r1, r2, r4
	ldrh r1, [r1, 0x4]
	movs r2, 0x8
	str r2, [sp]
	ldr r2, [sp, 0xC]
	ldr r3, [sp, 0x10]
	bl pokemon_make_ev_something
	movs r0, 0xFF
	mov r1, r9
	strb r0, [r1]
	adds r2, r7, 0x1
	mov r8, r2
	movs r1, 0x3
_081634C4:
	ldr r2, [sp, 0x14]
	adds r0, r2, r4
	ldrh r0, [r0]
	cmp r0, 0xDA
	bne _081634D4
	movs r2, 0
	mov r0, r9
	strb r2, [r0]
_081634D4:
	adds r4, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _081634C4
	movs r0, 0x64
	adds r4, r6, 0
	muls r4, r0
	ldr r0, =gEnemyParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x20
	add r2, sp, 0x4
	bl SetMonData
	adds r2, r5, r7
	lsls r2, 2
	add r2, r10
	adds r2, 0xE
	adds r0, r4, 0
	movs r1, 0xC
	bl SetMonData
	mov r7, r8
	cmp r7, 0x3
	bne _08163494
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8163444

	thumb_func_start sub_8163524
sub_8163524: @ 8163524
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_8165C40
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gUnknown_0203BC88
	ldr r1, [r0]
	movs r0, 0x34
	muls r0, r4
	adds r0, r1
	ldr r5, [r0, 0x30]
	movs r4, 0
	ldrh r1, [r5]
	b _08163558
	.pool
_0816354C:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 1
	adds r0, r5
	ldrh r1, [r0]
_08163558:
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _0816354C
_0816355E:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r4, 0
	bl __modsi3
	lsls r0, 1
	adds r0, r5
	ldrh r1, [r0]
	cmp r6, 0x32
	beq _0816357A
	cmp r6, 0x14
	bne _08163580
_0816357A:
	ldr r0, =0x00000351
	cmp r1, r0
	bhi _0816355E
_08163580:
	adds r0, r1, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8163524

	thumb_func_start sub_8163590
sub_8163590: @ 8163590
	push {lr}
	bl zero_enemy_party_data
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	beq _081635C0
	ldr r0, =gUnknown_02038BCA
	ldrh r0, [r0]
	movs r1, 0
	bl sub_81635D4
	b _081635CA
	.pool
_081635C0:
	ldr r0, =gUnknown_02038BCA
	ldrh r0, [r0]
	movs r1, 0
	bl sub_816379C
_081635CA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8163590

	thumb_func_start sub_81635D4
sub_81635D4: @ 81635D4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	lsls r0, 16
	lsrs r2, r0, 16
	adds r3, r2, 0
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x10]
	ldr r0, =0x0000012b
	cmp r2, r0
	bhi _0816364A
	ldr r4, =gSaveBlock2Ptr
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 24
	ldr r4, [r4]
	lsrs r0, 22
	movs r2, 0xCE
	lsls r2, 4
	adds r1, r4, r2
	adds r1, r0
	ldrh r0, [r1]
	movs r1, 0x7
	bl __udivsi3
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r3, =0x00000cb2
	adds r4, r3
	ldrh r0, [r4]
	cmp r0, 0x5
	bhi _0816363C
	adds r0, r1, 0
	movs r1, 0
	bl sub_81A6CA8
	lsls r0, 24
	lsrs r0, 24
	b _081636A6
	.pool
_0816363C:
	adds r0, r1, 0
	movs r1, 0x1
	bl sub_81A6CA8
	lsls r0, 24
	lsrs r0, 24
	b _081636A6
_0816364A:
	movs r0, 0xFA
	lsls r0, 1
	cmp r2, r0
	bne _08163694
	ldr r7, [sp, 0x10]
	adds r0, r7, 0x3
	cmp r7, r0
	blt _0816365C
	b _08163776
_0816365C:
	ldr r4, =gSaveBlock2Ptr
_0816365E:
	movs r0, 0x64
	muls r0, r7
	ldr r1, =gEnemyParty
	adds r0, r1
	ldr r1, [sp, 0x10]
	subs r2, r7, r1
	movs r1, 0x2C
	muls r2, r1
	movs r3, 0xC2
	lsls r3, 4
	adds r2, r3
	ldr r1, [r4]
	adds r1, r2
	bl sub_806819C
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, [sp, 0x10]
	adds r0, 0x3
	cmp r7, r0
	blt _0816365E
	b _08163776
	.pool
_08163694:
	ldr r0, =0x000003fe
	cmp r3, r0
	bne _081636A4
	bl sub_81A6CD0
	b _08163776
	.pool
_081636A4:
	movs r0, 0x1F
_081636A6:
	str r0, [sp, 0x18]
	bl sub_8165C40
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x14]
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldrb r2, [r1, 0xA]
	ldrb r0, [r1, 0xB]
	lsls r0, 8
	orrs r2, r0
	ldrb r0, [r1, 0xC]
	lsls r0, 16
	orrs r2, r0
	ldrb r0, [r1, 0xD]
	lsls r0, 24
	orrs r2, r0
	mov r8, r2
	movs r7, 0
_081636CE:
	ldr r1, =gUnknown_03006298
	lsls r0, r7, 1
	adds r0, r1
	ldrh r0, [r0]
	mov r9, r0
	ldr r3, [sp, 0x10]
	adds r5, r3, r7
	movs r0, 0x64
	adds r6, r5, 0
	muls r6, r0
	ldr r1, =gEnemyParty
	adds r0, r6, r1
	ldr r3, =gUnknown_0203BC8C
	ldr r2, [r3]
	mov r1, r9
	lsls r4, r1, 4
	adds r2, r4, r2
	ldrh r1, [r2]
	ldrb r3, [r2, 0xC]
	mov r10, r3
	ldr r3, [sp, 0x18]
	str r3, [sp]
	ldrb r2, [r2, 0xB]
	str r2, [sp, 0x4]
	mov r2, r8
	str r2, [sp, 0x8]
	ldr r2, [sp, 0x14]
	mov r3, r10
	bl sub_8068634
	movs r1, 0
	add r0, sp, 0xC
	strb r1, [r0]
	movs r3, 0
	adds r7, 0x1
	mov r10, r7
	adds r7, r4, 0
_08163718:
	ldr r0, =gUnknown_0203BC8C
	ldr r1, [r0]
	mov r2, r9
	lsls r0, r2, 4
	adds r0, r1
	lsls r1, r3, 1
	adds r0, 0x2
	adds r0, r1
	ldrh r1, [r0]
	ldr r2, =gEnemyParty
	adds r0, r6, r2
	adds r2, r3, 0
	str r3, [sp, 0x1C]
	bl sub_81A7024
	ldr r3, [sp, 0x1C]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x3
	bls _08163718
	movs r3, 0x64
	adds r4, r5, 0
	muls r4, r3
	ldr r0, =gEnemyParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x20
	add r2, sp, 0xC
	bl SetMonData
	ldr r1, =gUnknown_0203BC8C
	ldr r0, [r1]
	adds r0, r7, r0
	ldrb r2, [r0, 0xA]
	lsls r2, 1
	ldr r0, =gBattleFrontierHeldItems
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0xC
	bl SetMonData
	mov r2, r10
	lsls r0, r2, 24
	lsrs r7, r0, 24
	cmp r7, 0x2
	bls _081636CE
_08163776:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81635D4

	thumb_func_start sub_816379C
sub_816379C: @ 816379C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x10]
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldrb r0, [r1, 0xA]
	mov r9, r0
	ldrb r0, [r1, 0xB]
	lsls r0, 8
	mov r2, r9
	orrs r2, r0
	ldrb r0, [r1, 0xC]
	lsls r0, 16
	orrs r2, r0
	ldrb r0, [r1, 0xD]
	lsls r0, 24
	orrs r2, r0
	mov r9, r2
	movs r7, 0
	mov r8, r7
_081637D0:
	ldr r1, =gUnknown_03006298
	mov r2, r8
	lsls r0, r2, 1
	adds r0, r1
	ldrh r4, [r0]
	ldr r5, [sp, 0x10]
	add r5, r8
	movs r7, 0x64
	adds r6, r5, 0
	muls r6, r7
	ldr r1, =gEnemyParty
	adds r0, r6, r1
	ldr r7, =gUnknown_0203BC8C
	ldr r2, [r7]
	lsls r4, 4
	adds r2, r4, r2
	ldrh r1, [r2]
	ldrb r3, [r2, 0xC]
	movs r7, 0
	str r7, [sp]
	ldrb r2, [r2, 0xB]
	str r2, [sp, 0x4]
	mov r2, r9
	str r2, [sp, 0x8]
	movs r2, 0x1E
	bl sub_8068634
	movs r1, 0
	add r0, sp, 0xC
	strb r1, [r0]
	mov r10, r5
	mov r0, r8
	adds r0, 0x1
	str r0, [sp, 0x14]
	mov r8, r4
	mov r5, r8
_08163818:
	ldr r1, =gUnknown_0203BC8C
	ldr r0, [r1]
	adds r0, r5, r0
	lsls r4, r7, 1
	adds r0, 0x2
	adds r0, r4
	ldrh r1, [r0]
	ldr r2, =gEnemyParty
	adds r0, r6, r2
	adds r2, r7, 0
	bl sub_81A7024
	ldr r1, =gUnknown_0203BC8C
	ldr r0, [r1]
	adds r0, r5, r0
	adds r0, 0x2
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, 0xDA
	bne _08163846
	movs r1, 0
	add r0, sp, 0xC
	strb r1, [r0]
_08163846:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x3
	bls _08163818
	movs r2, 0x64
	mov r4, r10
	muls r4, r2
	ldr r7, =gEnemyParty
	adds r4, r7
	adds r0, r4, 0
	movs r1, 0x20
	add r2, sp, 0xC
	bl SetMonData
	ldr r1, =gUnknown_0203BC8C
	ldr r0, [r1]
	add r0, r8
	ldrb r2, [r0, 0xA]
	lsls r2, 1
	ldr r0, =gBattleFrontierHeldItems
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0xC
	bl SetMonData
	ldr r2, [sp, 0x14]
	lsls r0, r2, 24
	lsrs r0, 24
	mov r8, r0
	cmp r0, 0x2
	bls _081637D0
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816379C

	thumb_func_start ConvertBattleFrontierTrainerSpeechToString
ConvertBattleFrontierTrainerSpeechToString: @ 81638AC
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gStringVar4
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x3
	movs r3, 0x2
	bl ConvertEasyChatWordsToString
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x1
	adds r1, r4, 0
	bl GetStringWidth
	cmp r0, 0xCC
	bls _0816390A
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x2
	movs r3, 0x3
	bl ConvertEasyChatWordsToString
	ldrb r0, [r4]
	movs r1, 0x1
	cmp r0, 0xFE
	beq _081638EE
	adds r2, r4, 0
_081638E4:
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r1, 0x1
	cmp r0, 0xFE
	bne _081638E4
_081638EE:
	ldr r2, =gStringVar4
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r3, r2, 0
	cmp r0, 0xFE
	beq _08163904
_081638FA:
	adds r1, 0x1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0xFE
	bne _081638FA
_08163904:
	adds r1, r3
	movs r0, 0xFA
	strb r0, [r1]
_0816390A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ConvertBattleFrontierTrainerSpeechToString

	thumb_func_start sub_8163914
sub_8163914: @ 8163914
	push {lr}
	bl sub_8165C40
	ldr r0, =gUnknown_020375E2
	ldrh r0, [r0]
	cmp r0, 0
	beq _08163930
	ldr r0, =gUnknown_02038BCC
	b _08163932
	.pool
_08163930:
	ldr r0, =gUnknown_02038BCA
_08163932:
	ldrh r3, [r0]
	movs r0, 0xFA
	lsls r0, 1
	cmp r3, r0
	bne _08163950
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000bfc
	b _08163986
	.pool
_08163950:
	ldr r0, =0x0000012b
	cmp r3, r0
	bhi _08163974
	ldr r2, =gUnknown_0203BC88
	movs r0, 0x34
	adds r1, r3, 0
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	adds r0, 0xC
	bl ConvertBattleFrontierTrainerSpeechToString
	b _081639A8
	.pool
_08163974:
	ldr r0, =0x0000018f
	cmp r3, r0
	bhi _0816399C
	ldr r1, =gSaveBlock2Ptr
	movs r0, 0xEC
	muls r0, r3
	ldr r1, [r1]
	adds r0, r1
	ldr r1, =0xfffef2b8
_08163986:
	adds r0, r1
	bl ConvertBattleFrontierTrainerSpeechToString
	b _081639A8
	.pool
_0816399C:
	adds r0, r3, 0
	adds r0, 0x70
	lsls r0, 24
	lsrs r0, 24
	bl sub_819F99C
_081639A8:
	pop {r0}
	bx r0
	thumb_func_end sub_8163914

	thumb_func_start sub_81639AC
sub_81639AC: @ 81639AC
	push {r4-r6,lr}
	sub sp, 0x4
	bl sub_81864CC
	ldr r0, =gBattleScripting
	adds r0, 0x26
	ldrb r0, [r0]
	cmp r0, 0xA
	bhi _08163A78
	lsls r0, 2
	ldr r1, =_081639D0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081639D0:
	.4byte _081639FC
	.4byte _08163A38
	.4byte _08163A74
	.4byte _081639FC
	.4byte _081639FC
	.4byte _081639FC
	.4byte _081639FC
	.4byte _081639FC
	.4byte _08163A78
	.4byte _081639FC
	.4byte _081639FC
_081639FC:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000ebc
	adds r1, r0, r2
	ldr r2, [r1]
	ldr r0, =0x00fffffe
	cmp r2, r0
	bhi _08163A2C
	adds r0, r2, 0x1
	str r0, [r1]
	movs r1, 0x14
	bl __umodsi3
	cmp r0, 0
	bne _08163A78
	bl sub_81DA57C
	b _08163A78
	.pool
_08163A2C:
	ldr r0, =0x00ffffff
	str r0, [r1]
	b _08163A78
	.pool
_08163A38:
	movs r5, 0
	ldr r6, =gSaveBlock1Ptr
_08163A3C:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	movs r0, 0x8E
	lsls r0, 2
	adds r1, r4, r0
	ldr r0, [r6]
	adds r0, r1
	movs r1, 0xC
	bl GetMonData
	mov r1, sp
	strh r0, [r1]
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xC
	mov r2, sp
	bl SetMonData
	adds r5, 0x1
	cmp r5, 0x5
	ble _08163A3C
	b _08163A78
	.pool
_08163A74:
	bl sub_816537C
_08163A78:
	ldr r0, =c2_exit_to_overworld_1_continue_scripts_restart_music
	bl SetMainCallback2
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81639AC

	thumb_func_start sub_8163A8C
sub_8163A8C: @ 8163A8C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_8145F20
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08163AB0
	ldr r0, =gMain
	ldr r1, =sub_81639AC
	str r1, [r0, 0x8]
	ldr r0, =sub_8036760
	bl SetMainCallback2
	adds r0, r4, 0
	bl DestroyTask
_08163AB0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8163A8C

	thumb_func_start sub_8163AC4
sub_8163AC4: @ 8163AC4
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r0, =gBattleScripting
	ldr r2, =gUnknown_020375E0
	ldrh r1, [r2]
	adds r0, 0x26
	strb r1, [r0]
	ldrh r0, [r2]
	cmp r0, 0xA
	bls _08163ADA
	b _08163E68
_08163ADA:
	lsls r0, 2
	ldr r1, =_08163AF0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08163AF0:
	.4byte _08163B1C
	.4byte _08163BC0
	.4byte _08163C10
	.4byte _08163C70
	.4byte _08163CC4
	.4byte _08163D28
	.4byte _08163D74
	.4byte _08163DB4
	.4byte _08163E2C
	.4byte _08163DF4
	.4byte _08163DC8
_08163B1C:
	ldr r5, =gBattleTypeFlags
	movs r0, 0x84
	lsls r0, 1
	str r0, [r5]
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x1
	beq _08163B56
	cmp r4, 0x1
	bgt _08163B44
	cmp r4, 0
	beq _08163B4E
	b _08163BA6
	.pool
_08163B44:
	cmp r4, 0x2
	beq _08163B64
	cmp r4, 0x3
	beq _08163B98
	b _08163BA6
_08163B4E:
	movs r0, 0x3
	bl sub_8163048
	b _08163BA6
_08163B56:
	movs r0, 0x4
	bl sub_8163048
	ldr r0, [r5]
	orrs r0, r4
	str r0, [r5]
	b _08163BA6
_08163B64:
	movs r0, 0x2
	bl sub_816306C
	ldr r1, =gUnknown_02038BCE
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000cd6
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldrh r0, [r1]
	bl sub_8165404
	ldr r0, [r5]
	ldr r1, =0x00408041
	orrs r0, r1
	str r0, [r5]
	b _08163BA6
	.pool
_08163B98:
	ldr r0, [r5]
	ldr r1, =0x00800043
	orrs r0, r1
	str r0, [r5]
	movs r0, 0x2
	bl sub_816306C
_08163BA6:
	ldr r0, =sub_8163A8C
	movs r1, 0x1
	bl CreateTask
	movs r0, 0
	bl current_map_music_set__default_for_battle
	movs r0, 0
	b _08163E10
	.pool
_08163BC0:
	movs r5, 0
	ldr r6, =gSaveBlock1Ptr
_08163BC4:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r0, r4, r0
	movs r1, 0xC
	bl GetMonData
	mov r1, sp
	strh r0, [r1]
	movs r0, 0x8E
	lsls r0, 2
	adds r4, r0
	ldr r0, [r6]
	adds r0, r4
	movs r1, 0xC
	mov r2, sp
	bl SetMonData
	adds r5, 0x1
	cmp r5, 0x5
	ble _08163BC4
	ldr r0, =sub_8163A8C
	movs r1, 0x1
	bl CreateTask
	movs r0, 0
	bl current_map_music_set__default_for_battle
	movs r0, 0xC
	b _08163E10
	.pool
_08163C10:
	bl zero_enemy_party_data
	movs r5, 0
	ldr r4, =gSaveBlock2Ptr
_08163C18:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2C
	adds r2, r5, 0
	muls r2, r1
	movs r1, 0xC2
	lsls r1, 4
	adds r2, r1
	ldr r1, [r4]
	adds r1, r2
	bl sub_806819C
	adds r5, 0x1
	cmp r5, 0x2
	ble _08163C18
	ldr r1, =gBattleTypeFlags
	ldr r0, =0x00000808
	str r0, [r1]
	ldr r1, =gUnknown_02038BCA
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sub_8163A8C
	movs r1, 0x1
	bl CreateTask
	movs r0, 0
	bl current_map_music_set__default_for_battle
	movs r0, 0xD
	b _08163E10
	.pool
_08163C70:
	ldr r4, =gBattleTypeFlags
	ldr r0, =0x00010008
	str r0, [r4]
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x1
	bne _08163C8A
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_08163C8A:
	ldr r0, =gUnknown_02038BCA
	ldrh r1, [r0]
	ldr r0, =0x000003fe
	cmp r1, r0
	bne _08163C9A
	movs r0, 0x2
	bl sub_8163048
_08163C9A:
	ldr r0, =sub_8163A8C
	movs r1, 0x1
	bl CreateTask
	movs r0, 0
	bl sub_806E694
	movs r0, 0x3
	b _08163E10
	.pool
_08163CC4:
	ldr r4, =gBattleTypeFlags
	ldr r0, =0x00020008
	str r0, [r4]
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x1
	bne _08163CDE
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_08163CDE:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000ca9
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	beq _08163D0C
	movs r0, 0x3
	bl sub_8163048
	b _08163D12
	.pool
_08163D0C:
	movs r0, 0x3
	bl sub_81630A0
_08163D12:
	ldr r0, =sub_8163A8C
	movs r1, 0x1
	bl CreateTask
	movs r0, 0
	bl current_map_music_set__default_for_battle
	movs r0, 0x4
	b _08163E10
	.pool
_08163D28:
	ldr r1, =gBattleTypeFlags
	ldr r0, =0x00040008
	str r0, [r1]
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	beq _08163D58
	movs r0, 0x3
	bl sub_8163048
	b _08163D5E
	.pool
_08163D58:
	movs r0, 0x3
	bl sub_81630A0
_08163D5E:
	ldr r0, =sub_8163A8C
	movs r1, 0x1
	bl CreateTask
	movs r0, 0
	bl current_map_music_set__default_for_battle
	movs r0, 0x5
	b _08163E10
	.pool
_08163D74:
	ldr r4, =gBattleTypeFlags
	ldr r0, =0x00080008
	str r0, [r4]
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x1
	bne _08163D8E
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_08163D8E:
	bl sub_8163590
	ldr r0, =sub_8163A8C
	movs r1, 0x1
	bl CreateTask
	movs r0, 0
	bl current_map_music_set__default_for_battle
	movs r0, 0x6
	b _08163E10
	.pool
_08163DB4:
	ldr r1, =gBattleTypeFlags
	movs r0, 0x84
	lsls r0, 1
	str r0, [r1]
	movs r0, 0x3
	bl sub_8163048
	b _08163E00
	.pool
_08163DC8:
	ldr r1, =gBattleTypeFlags
	ldr r0, =0x00200008
	str r0, [r1]
	movs r0, 0x3
	bl sub_8163048
	ldr r0, =sub_8163A8C
	movs r1, 0x1
	bl CreateTask
	movs r0, 0
	bl current_map_music_set__default_for_battle
	movs r0, 0xA
	b _08163E10
	.pool
_08163DF4:
	ldr r1, =gBattleTypeFlags
	ldr r0, =0x00008109
	str r0, [r1]
	movs r0, 0x1
	bl sub_816306C
_08163E00:
	ldr r0, =sub_8163A8C
	movs r1, 0x1
	bl CreateTask
	movs r0, 0
	bl current_map_music_set__default_for_battle
	movs r0, 0x7
_08163E10:
	bl sub_80B100C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8145EF4
	b _08163E68
	.pool
_08163E2C:
	ldr r1, =gBattleTypeFlags
	ldr r0, =0x00408049
	str r0, [r1]
	ldr r5, =0x00000c03
	adds r0, r5, 0
	bl sub_8165404
	ldr r4, =gUnknown_02038BFC
	movs r0, 0
	strb r0, [r4]
	ldr r0, =gUnknown_08224158
	bl TrainerBattleConfigure
	movs r0, 0x1
	strb r0, [r4]
	ldr r0, =gUnknown_08224167
	bl TrainerBattleConfigure
	ldr r0, =gUnknown_02038BCE
	strh r5, [r0]
	ldr r0, =sub_8163A8C
	movs r1, 0x1
	bl CreateTask
	movs r0, 0
	bl current_map_music_set__default_for_battle
	movs r0, 0x12
	bl sub_8145EF4
_08163E68:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8163AC4

	thumb_func_start sub_8163E90
sub_8163E90: @ 8163E90
	push {r4-r6,lr}
	ldr r6, =gSaveBlock2Ptr
	ldr r0, [r6]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r5, [r0]
	lsls r5, 30
	lsrs r5, 30
	ldr r0, =0x000040ce
	bl VarGet
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8164FCC
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, [r6]
	lsls r5, 1
	lsls r4, 2
	adds r5, r4
	movs r1, 0xCE
	lsls r1, 4
	adds r0, r1
	adds r1, r0, r5
	ldrh r0, [r1]
	cmp r0, r2
	bcs _08163ED0
	strh r2, [r1]
_08163ED0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8163E90

	thumb_func_start sub_8163EE4
sub_8163EE4: @ 8163EE4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r1, =0x0000064c
	adds r5, r0, r1
	adds r0, r5, 0
	bl sub_8164FB8
	ldr r0, [r4]
	ldr r2, =0x00000ca9
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r6, r0, 30
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r2, [r4]
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	beq _08163F40
	ldr r4, =gUnknown_085DCEFA
	ldrb r0, [r2, 0xA]
	ldrb r1, [r2, 0xB]
	adds r0, r1
	ldrb r1, [r2, 0xC]
	adds r0, r1
	ldrb r1, [r2, 0xD]
	adds r0, r1
	movs r1, 0x14
	b _08163F52
	.pool
_08163F40:
	ldr r4, =gUnknown_085DCEDC
	ldrb r0, [r2, 0xA]
	ldrb r1, [r2, 0xB]
	adds r0, r1
	ldrb r1, [r2, 0xC]
	adds r0, r1
	ldrb r1, [r2, 0xD]
	adds r0, r1
	movs r1, 0x1E
_08163F52:
	bl __umodsi3
	adds r0, r4
	ldrb r0, [r0]
	strb r6, [r5]
	strb r0, [r5, 0x1]
	adds r0, r5, 0
	adds r0, 0xC
	ldr r4, =gSaveBlock2Ptr
	ldr r1, [r4]
	adds r1, 0xA
	bl sub_80842F4
	adds r0, r5, 0x4
	ldr r1, [r4]
	bl StringCopy7
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_8164FCC
	strh r0, [r5, 0x2]
	movs r4, 0
	movs r2, 0x10
	adds r2, r5
	mov r12, r2
	movs r7, 0x1C
	adds r7, r5
	mov r9, r7
	adds r6, r5, 0
	adds r6, 0x28
	movs r0, 0xE4
	adds r0, r5
	mov r8, r0
_08163F96:
	lsls r2, r4, 1
	mov r1, r12
	adds r3, r1, r2
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r7, =0x00002bbc
	adds r0, r1, r7
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r3]
	mov r0, r9
	adds r3, r0, r2
	adds r7, 0xC
	adds r0, r1, r7
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r3]
	adds r3, r6, r2
	ldr r0, =0x00002bd4
	adds r1, r0
	adds r1, r2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r4, 0x1
	cmp r4, 0x5
	ble _08163F96
	movs r4, 0
_08163FCC:
	ldr r6, =gSaveBlock2Ptr
	ldr r0, [r6]
	lsls r1, r4, 1
	ldr r2, =0x00000caa
	adds r0, r2
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, 0
	beq _08163FF4
	adds r1, r0, 0
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gUnknown_02024488
	adds r0, r1
	movs r1, 0x2C
	muls r1, r4
	adds r1, 0x34
	adds r1, r5, r1
	bl sub_80686FC
_08163FF4:
	adds r4, 0x1
	cmp r4, 0x3
	ble _08163FCC
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	mov r7, r8
	strb r0, [r7]
	ldr r0, [r6]
	ldr r1, =0x0000064c
	adds r0, r1
	bl sub_8164F70
	bl sub_8163E90
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8163EE4

	thumb_func_start sub_8164040
sub_8164040: @ 8164040
	push {r4,r5,lr}
	ldr r5, =gSaveBlock2Ptr
	ldr r0, [r5]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r4, [r0]
	lsls r4, 30
	lsrs r4, 30
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	ldr r5, [r5]
	lsls r4, 1
	lsrs r0, 14
	adds r4, r0
	movs r2, 0xCE
	lsls r2, 4
	adds r0, r5, r2
	adds r0, r4
	ldrh r0, [r0]
	movs r1, 0x7
	bl __udivsi3
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =gUnknown_020375E2
	ldrh r0, [r0]
	cmp r0, 0
	bne _0816408E
	cmp r1, 0x1
	bgt _0816408A
	ldr r1, =0x00000cb2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _0816408E
_0816408A:
	bl sub_8163EE4
_0816408E:
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r1, =gUnknown_020375E2
	ldrh r1, [r1]
	ldr r2, =0x00000ca8
	adds r0, r2
	strb r1, [r0]
	movs r0, 0x80
	lsls r0, 7
	movs r1, 0
	bl VarSet
	ldr r1, [r4]
	ldr r0, =0x00000ca9
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	bl sub_81A4C30
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8164040

	thumb_func_start nullsub_61
nullsub_61: @ 81640D8
	bx lr
	thumb_func_end nullsub_61

	thumb_func_start nullsub_116
nullsub_116: @ 81640DC
	bx lr
	thumb_func_end nullsub_116

	thumb_func_start sub_81640E0
sub_81640E0: @ 81640E0
	push {r4-r7,lr}
	sub sp, 0xC
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	ldr r4, =gPlayerParty
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	lsls r0, 16
	lsrs r7, r0, 16
	adds r4, 0x64
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
	movs r6, 0
	movs r2, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r0, =0xfffffe70
	adds r5, r0
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	adds r1, 0xE0
	adds r0, r1
	mov r3, sp
_08164122:
	ldrh r1, [r0]
	cmp r1, r7
	beq _08164130
	cmp r1, r4
	beq _08164130
	stm r3!, {r2}
	adds r6, 0x1
_08164130:
	adds r0, 0xC
	adds r2, 0x1
	cmp r2, 0x2
	ble _08164122
	bl Random
	ldr r4, =gUnknown_03006298
	lsls r0, 16
	lsrs r0, 16
	adds r1, r6, 0
	bl __modsi3
	lsls r0, 2
	add r0, sp
	ldr r0, [r0]
	strh r0, [r4]
_08164150:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r6, 0
	bl __modsi3
	lsls r0, 2
	add r0, sp
	ldr r0, [r0]
	strh r0, [r4, 0x2]
	ldrh r1, [r4]
	lsls r0, 16
	lsrs r0, 16
	cmp r1, r0
	beq _08164150
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81640E0

	thumb_func_start sub_8164188
sub_8164188: @ 8164188
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	ldr r6, =gSaveBlock2Ptr
	ldr r0, [r6]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r0, 30
	str r0, [sp, 0xC]
	ldr r4, =gPlayerParty
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x10]
	adds r4, 0x64
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x14]
	movs r3, 0
	mov r8, r3
	movs r7, 0
	adds r2, r6, 0
	ldr r0, =0xfffffed4
	adds r5, r0
	ldr r6, =0x0000076c
	mov r10, sp
	movs r0, 0xEC
	adds r1, r5, 0
	muls r1, r0
	mov r9, r1
_081641E6:
	ldr r1, [r2]
	movs r0, 0x2C
	muls r0, r7
	mov r3, r9
	adds r5, r0, r3
	adds r1, r5
	adds r0, r1, r6
	ldrh r0, [r0]
	ldr r3, [sp, 0x10]
	cmp r0, r3
	beq _0816423A
	ldr r3, [sp, 0x14]
	cmp r0, r3
	beq _0816423A
	movs r0, 0xEF
	lsls r0, 3
	adds r4, r1, r0
	ldr r1, [sp, 0xC]
	lsls r0, r1, 24
	lsrs r0, 24
	str r2, [sp, 0x18]
	bl sub_8165C90
	ldrb r1, [r4]
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [sp, 0x18]
	cmp r1, r0
	bhi _0816423A
	ldr r0, [r2]
	adds r0, r5
	adds r0, r6
	ldrh r0, [r0]
	cmp r0, 0
	beq _0816423A
	mov r3, r10
	adds r3, 0x4
	mov r10, r3
	subs r3, 0x4
	stm r3!, {r7}
	movs r0, 0x1
	add r8, r0
_0816423A:
	adds r7, 0x1
	cmp r7, 0x3
	ble _081641E6
	bl Random
	ldr r4, =gUnknown_03006298
	lsls r0, 16
	lsrs r0, 16
	mov r1, r8
	bl __modsi3
	lsls r0, 2
	add r0, sp
	ldr r0, [r0]
	strh r0, [r4, 0x4]
_08164258:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	mov r1, r8
	bl __modsi3
	lsls r0, 2
	add r0, sp
	ldr r0, [r0]
	strh r0, [r4, 0x6]
	ldrh r1, [r4, 0x4]
	lsls r0, 16
	lsrs r0, 16
	cmp r1, r0
	beq _08164258
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8164188

	thumb_func_start sub_81642A0
sub_81642A0: @ 81642A0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0xC7
	lsls r1, 4
	adds r1, r0, r1
	str r1, [sp, 0x24]
	ldr r5, =gSaveBlock2Ptr
	ldr r0, [r5]
	ldr r2, =0x00000ca9
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r0, 30
	str r0, [sp, 0x14]
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	ldr r1, [r5]
	ldr r3, [sp, 0x14]
	lsls r2, r3, 1
	lsrs r0, 14
	adds r2, r0
	movs r4, 0xCE
	lsls r4, 4
	adds r1, r4
	adds r1, r2
	ldrh r0, [r1]
	movs r1, 0x7
	bl __udivsi3
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x18]
	ldr r4, =gPlayerParty
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	str r0, [sp, 0x1C]
	adds r4, 0x64
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	str r0, [sp, 0x20]
	bl sub_8165C40
	movs r7, 0
	ldr r0, [sp, 0x18]
	lsls r0, 24
	mov r10, r0
_08164318:
	lsls r6, r7, 1
_0816431A:
	mov r1, r10
	lsrs r0, r1, 24
	movs r1, 0
	bl sub_8162548
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	movs r2, 0
	mov r9, r2
	cmp r9, r7
	bge _08164368
	ldr r0, [r5]
	ldr r3, =0x00000cb4
	adds r1, r0, r3
	ldrh r0, [r1]
	cmp r0, r8
	beq _08164368
	ldr r0, =gUnknown_0203BC88
	ldr r2, [r0]
	movs r4, 0x34
	mov r0, r8
	muls r0, r4
	adds r0, r2
	ldrb r3, [r0]
_0816434C:
	ldrh r0, [r1]
	muls r0, r4
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, r3
	beq _08164368
	adds r1, 0x2
	movs r0, 0x1
	add r9, r0
	cmp r9, r7
	bge _08164368
	ldrh r0, [r1]
	cmp r0, r8
	bne _0816434C
_08164368:
	cmp r9, r7
	bne _0816431A
	ldr r0, [r5]
	ldr r1, =0x00000cb4
	adds r0, r1
	adds r0, r6
	mov r2, r8
	strh r2, [r0]
	mov r7, r9
	adds r7, 0x1
	cmp r7, 0x5
	ble _08164318
	movs r3, 0x8
	mov r10, r3
	movs r4, 0
	mov r9, r4
	ldr r0, [sp, 0x24]
	str r0, [sp, 0x40]
_0816438C:
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	mov r2, r9
	lsls r1, r2, 1
	ldr r3, =0x00000cb4
	adds r0, r3
	adds r0, r1
	ldrh r0, [r0]
	mov r8, r0
	bl sub_81627A4
	ldr r4, [sp, 0x40]
	strb r0, [r4, 0x19]
	movs r7, 0
_081643A8:
	adds r0, r7, 0x1
	str r0, [sp, 0x30]
	mov r1, r10
	lsls r1, 1
	str r1, [sp, 0x38]
	mov r2, r10
	adds r2, 0x1
	str r2, [sp, 0x34]
	mov r0, r10
	subs r0, 0x1
	lsls r0, 1
	str r0, [sp, 0x28]
_081643C0:
	mov r0, r8
	bl sub_8163524
	lsls r0, 16
	lsrs r6, r0, 16
	movs r0, 0x1
	ands r0, r7
	cmp r0, 0
	beq _081643F4
	ldr r3, =gSaveBlock2Ptr
	ldr r0, [r3]
	ldr r4, =0x00000cb4
	adds r0, r4
	ldr r1, [sp, 0x28]
	adds r0, r1
	ldrh r2, [r0]
	ldr r0, =gUnknown_0203BC8C
	ldr r0, [r0]
	lsls r2, 4
	adds r2, r0
	lsls r1, r6, 4
	adds r1, r0
	ldrb r0, [r2, 0xA]
	ldrb r1, [r1, 0xA]
	cmp r0, r1
	beq _081643C0
_081643F4:
	movs r5, 0x8
	cmp r5, r10
	bge _08164430
	ldr r2, =gSaveBlock2Ptr
	ldr r0, [r2]
	ldr r1, =gUnknown_0203BC8C
	ldr r3, [r1]
	lsls r1, r6, 4
	adds r1, r3
	ldr r4, =0x00000cc4
	adds r2, r0, r4
	ldrh r0, [r1]
	mov r12, r0
_0816440E:
	ldrh r0, [r2]
	lsls r0, 4
	adds r0, r3
	ldrh r0, [r0]
	cmp r0, r12
	beq _08164430
	ldrh r0, [r1]
	ldr r4, [sp, 0x1C]
	cmp r4, r0
	beq _08164430
	ldr r4, [sp, 0x20]
	cmp r4, r0
	beq _08164430
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r10
	blt _0816440E
_08164430:
	cmp r5, r10
	bne _081643C0
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	ldr r2, =0x00000cb4
	adds r0, r2
	ldr r3, [sp, 0x38]
	adds r0, r3
	strh r6, [r0]
	ldr r4, [sp, 0x34]
	mov r10, r4
	ldr r7, [sp, 0x30]
	cmp r7, 0x1
	ble _081643A8
	ldr r0, [sp, 0x40]
	adds r0, 0x18
	str r0, [sp, 0x40]
	movs r1, 0x1
	add r9, r1
	mov r2, r9
	cmp r2, 0x5
	ble _0816438C
	movs r3, 0
	mov r10, r3
	bl sub_8165B20
	movs r4, 0
	mov r9, r4
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r2, 0
	adds r6, r0, 0
	adds r6, 0xDC
	mov r8, sp
_08164474:
	ldrb r0, [r6]
	lsls r4, r0, 25
	lsrs r0, r4, 30
	cmp r0, 0
	beq _081644E0
	ldr r1, =gUnknown_085DF9EC
	ldrb r0, [r6, 0x1]
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x7
	str r2, [sp, 0x44]
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [sp, 0x44]
	ldr r1, [sp, 0x18]
	cmp r0, r1
	bgt _081644E0
	lsrs r0, r4, 30
	subs r0, 0x1
	ldr r3, [sp, 0x14]
	cmp r0, r3
	bne _081644E0
	movs r5, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	adds r0, 0xE0
	adds r1, r2, r0
	movs r7, 0x2
_081644B0:
	ldrh r0, [r1]
	ldr r4, [sp, 0x1C]
	cmp r4, r0
	beq _081644C0
	ldr r3, [sp, 0x20]
	cmp r3, r0
	beq _081644C0
	adds r5, 0x1
_081644C0:
	adds r1, 0xC
	subs r7, 0x1
	cmp r7, 0
	bge _081644B0
	cmp r5, 0x2
	ble _081644E0
	movs r0, 0xC8
	lsls r0, 1
	add r0, r9
	mov r4, r8
	adds r4, 0x4
	mov r8, r4
	subs r4, 0x4
	stm r4!, {r0}
	movs r0, 0x1
	add r10, r0
_081644E0:
	adds r2, 0x44
	adds r6, 0x44
	movs r1, 0x1
	add r9, r1
	mov r3, r9
	cmp r3, 0x3
	ble _08164474
	mov r4, r10
	cmp r4, 0
	beq _08164532
	bl Random
	ldr r6, =gSaveBlock2Ptr
	ldr r4, [r6]
	lsls r0, 16
	lsrs r0, 16
	mov r1, r10
	bl __modsi3
	lsls r0, 2
	add r0, sp
	ldr r0, [r0]
	movs r5, 0xCC
	lsls r5, 4
	adds r4, r5
	strh r0, [r4]
	ldrh r0, [r4]
	bl sub_81627A4
	ldr r1, [sp, 0x24]
	adds r1, 0xA8
	strb r0, [r1, 0x1]
	movs r0, 0xD8
	lsls r0, 2
	bl FlagReset
	ldr r0, [r6]
	adds r0, r5
	ldrh r0, [r0]
	bl sub_81640E0
_08164532:
	movs r0, 0
	mov r10, r0
	mov r9, r0
	mov r1, sp
	str r1, [sp, 0x3C]
_0816453C:
	ldr r0, =gSaveBlock2Ptr
	movs r2, 0xEC
	mov r1, r9
	muls r1, r2
	movs r3, 0xE7
	lsls r3, 3
	adds r1, r3
	ldr r0, [r0]
	movs r2, 0
	movs r3, 0
	movs r7, 0
	mov r4, r9
	adds r4, 0x1
	str r4, [sp, 0x2C]
	adds r1, r0, r1
_0816455A:
	ldm r1!, {r0}
	orrs r2, r0
	adds r3, r0
	adds r7, 0x1
	cmp r7, 0x39
	bls _0816455A
	ldr r0, =gSaveBlock2Ptr
	ldr r5, [r0]
	movs r1, 0xEC
	mov r6, r9
	muls r6, r1
	adds r4, r5, r6
	ldr r1, =0x0000073a
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, 0x7
	str r2, [sp, 0x44]
	str r3, [sp, 0x48]
	bl __udivsi3
	lsls r0, 16
	lsrs r0, 16
	ldr r2, [sp, 0x44]
	ldr r3, [sp, 0x48]
	ldr r1, [sp, 0x18]
	cmp r0, r1
	bgt _08164656
	movs r1, 0xE7
	lsls r1, 3
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r4, [sp, 0x14]
	cmp r0, r4
	bne _08164656
	cmp r2, 0
	beq _08164656
	adds r1, 0xE8
	adds r0, r5, r1
	adds r0, r6
	ldr r0, [r0]
	cmp r0, r3
	bne _08164656
	movs r5, 0
	movs r7, 0
	ldr r2, =gSaveBlock2Ptr
	mov r8, r2
	ldr r3, =0x0000076c
_081645B8:
	mov r4, r8
	ldr r2, [r4]
	movs r0, 0x2C
	adds r1, r7, 0
	muls r1, r0
	movs r4, 0xEC
	mov r0, r9
	muls r0, r4
	adds r6, r1, r0
	adds r2, r6
	adds r0, r2, r3
	ldrh r0, [r0]
	ldr r1, [sp, 0x1C]
	cmp r1, r0
	beq _0816463C
	ldr r4, [sp, 0x20]
	cmp r4, r0
	beq _0816463C
	movs r0, 0xEF
	lsls r0, 3
	adds r4, r2, r0
	ldr r1, [sp, 0x14]
	lsls r0, r1, 24
	lsrs r0, 24
	str r3, [sp, 0x48]
	bl sub_8165C90
	ldrb r1, [r4]
	lsls r0, 24
	lsrs r0, 24
	ldr r3, [sp, 0x48]
	cmp r1, r0
	bhi _0816463C
	mov r2, r8
	ldr r0, [r2]
	adds r0, r6
	adds r0, r3
	ldrh r0, [r0]
	cmp r0, 0
	b _08164638
	.pool
_08164638:
	beq _0816463C
	adds r5, 0x1
_0816463C:
	adds r7, 0x1
	cmp r7, 0x3
	ble _081645B8
	cmp r5, 0x1
	ble _08164656
	movs r0, 0x96
	lsls r0, 1
	add r0, r9
	ldr r3, [sp, 0x3C]
	stm r3!, {r0}
	str r3, [sp, 0x3C]
	movs r4, 0x1
	add r10, r4
_08164656:
	ldr r0, [sp, 0x2C]
	mov r9, r0
	cmp r0, 0x4
	bgt _08164660
	b _0816453C
_08164660:
	mov r1, r10
	cmp r1, 0
	beq _081646A0
	bl Random
	ldr r6, =gSaveBlock2Ptr
	ldr r4, [r6]
	lsls r0, 16
	lsrs r0, 16
	mov r1, r10
	bl __modsi3
	lsls r0, 2
	add r0, sp
	ldr r0, [r0]
	ldr r5, =0x00000cc2
	adds r4, r5
	strh r0, [r4]
	ldrh r0, [r4]
	bl sub_81627A4
	ldr r1, [sp, 0x24]
	adds r1, 0xC0
	strb r0, [r1, 0x1]
	ldr r0, =0x00000361
	bl FlagReset
	ldr r0, [r6]
	adds r0, r5
	ldrh r0, [r0]
	bl sub_8164188
_081646A0:
	add sp, 0x4C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81642A0

	thumb_func_start sub_81646BC
sub_81646BC: @ 81646BC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r1, 16
	lsrs r4, r1, 16
	movs r0, 0
	mov r9, r0
	mov r10, r0
	bl sub_8165C40
	movs r0, 0xFA
	lsls r0, 1
	cmp r5, r0
	beq _081647CE
	subs r0, 0xC9
	cmp r5, r0
	bhi _081646FC
	ldr r0, =gUnknown_0203BC8C
	ldr r1, [r0]
	lsls r0, r4, 4
	adds r0, r1
	ldrh r1, [r0, 0x2]
	mov r9, r1
	ldrh r0, [r0]
	mov r10, r0
	b _081647CE
	.pool
_081646FC:
	ldr r0, =0x0000018f
	cmp r5, r0
	bhi _08164750
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r1, =gUnknown_03006298
	ldr r0, =gUnknown_020375E2
	ldrh r0, [r0]
	adds r0, 0x1
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x2C
	muls r1, r0
	ldr r0, =0xfffffed4
	adds r2, r5, r0
	movs r0, 0xEC
	muls r0, r2
	adds r1, r0
	adds r3, r1
	movs r1, 0xEE
	lsls r1, 3
	adds r0, r3, r1
	ldrh r0, [r0]
	mov r9, r0
	ldr r2, =0x0000076c
	adds r3, r2
	ldrh r3, [r3]
	mov r10, r3
	b _081647CE
	.pool
_08164750:
	ldr r4, =gSaveBlock2Ptr
	ldr r3, [r4]
	ldr r1, =gUnknown_03006298
	ldr r0, =gUnknown_020375E2
	ldrh r0, [r0]
	subs r0, 0x1
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r2, =0xfffffe70
	adds r1, r5, r2
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	adds r0, r2
	adds r3, r0
	adds r0, r3, 0
	adds r0, 0xE2
	ldrh r0, [r0]
	mov r9, r0
	adds r3, 0xE0
	ldrh r3, [r3]
	mov r10, r3
	movs r3, 0
	ldr r7, =gStringVar3
	mov r8, r7
	adds r0, r4, 0
	mov r12, r0
	adds r4, r2, 0
	movs r6, 0x8A
	lsls r6, 1
_08164794:
	mov r1, r8
	adds r2, r3, r1
	mov r1, r12
	ldr r0, [r1]
	adds r1, r3, r4
	adds r0, r6
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	adds r3, 0x1
	cmp r3, 0x6
	ble _08164794
	adds r1, r3, r7
	movs r0, 0xFF
	strb r0, [r1]
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r0, =0xfffffe70
	adds r1, r5, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, r0
	ldr r1, =0x0000011b
	adds r0, r2, r1
	ldrb r1, [r0]
	adds r0, r7, 0
	bl ConvertInternationalString
_081647CE:
	ldr r0, =gStringVar1
	movs r1, 0xD
	mov r2, r9
	muls r2, r1
	adds r1, r2, 0
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar2
	movs r1, 0xB
	mov r2, r10
	muls r2, r1
	adds r1, r2, 0
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81646BC

	thumb_func_start sub_8164828
sub_8164828: @ 8164828
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	bl sub_8165C40
	bl sub_81A39C4
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x7
	bl __udivsi3
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	ldr r0, =gUnknown_020375F2
	ldrh r0, [r0]
	subs r5, r0, 0x2
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	lsls r1, r5, 1
	ldr r2, =0x00000cb4
	adds r0, r2
	adds r0, r1
	ldrh r7, [r0]
	movs r3, 0
	str r3, [sp]
	ldr r4, =gUnknown_085DD500
	lsls r6, r7, 16
	b _08164884
	.pool
_0816487C:
	adds r4, 0x8
	ldr r0, [sp]
	adds r0, 0x1
	str r0, [sp]
_08164884:
	ldr r1, [sp]
	cmp r1, 0x31
	bhi _0816489A
	lsrs r0, r6, 16
	bl sub_8162D34
	lsls r0, 24
	lsrs r0, 24
	ldr r1, [r4]
	cmp r1, r0
	bne _0816487C
_0816489A:
	ldr r0, =gUnknown_020375E2
	ldrh r0, [r0]
	cmp r0, 0x4
	bls _081648A4
	b _08164AC2
_081648A4:
	lsls r0, 2
	ldr r1, =_081648B8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081648B8:
	.4byte _081648CC
	.4byte _08164984
	.4byte _0816499C
	.4byte _081649BC
	.4byte _08164AC2
_081648CC:
	movs r0, 0xFA
	lsls r0, 1
	cmp r7, r0
	bne _081648D6
	b _08164B54
_081648D6:
	subs r0, 0xC9
	cmp r7, r0
	ble _081648E2
	ldr r0, =0x0000018f
	cmp r7, r0
	bgt _081648F4
_081648E2:
	ldr r0, =gStringVar1
	adds r1, r7, 0
	bl sub_8162E20
	b _08164AC2
	.pool
_081648F4:
	movs r3, 0
	lsls r2, r7, 16
	mov r10, r2
	ldr r6, =gStringVar1
	mov r9, r6
	ldr r4, =gSaveBlock2Ptr
	mov r8, r4
	ldr r5, =0xfffffe70
	adds r1, r7, r5
	lsls r0, r1, 4
	adds r0, r1
	lsls r4, r0, 2
	movs r5, 0x8A
	lsls r5, 1
_08164910:
	mov r0, r9
	adds r2, r3, r0
	mov r1, r8
	ldr r0, [r1]
	adds r1, r3, r4
	adds r0, r5
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	adds r3, 0x1
	cmp r3, 0x6
	ble _08164910
	adds r1, r3, r6
	movs r0, 0xFF
	strb r0, [r1]
	ldr r2, =gSaveBlock2Ptr
	ldr r1, [r2]
	ldr r3, =0xfffffe70
	adds r0, r7, r3
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	adds r1, r4
	ldr r5, =0x0000011b
	adds r0, r1, r5
	ldrb r1, [r0]
	adds r0, r6, 0
	bl ConvertInternationalString
	ldr r0, =gStringVar2
	ldr r2, =gSaveBlock2Ptr
	ldr r1, [r2]
	adds r1, r4
	adds r1, 0xDE
	ldrb r1, [r1]
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r0, =gStringVar3
	mov r3, r10
	lsrs r1, r3, 16
	bl sub_8162E20
	b _08164AC2
	.pool
_08164984:
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	lsls r0, r5, 2
	adds r1, r0
	ldr r4, =0x00000cc4
	adds r1, r4
	b _081649A8
	.pool
_0816499C:
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	lsls r0, r5, 2
	adds r1, r0
	ldr r5, =0x00000cc6
	adds r1, r5
_081649A8:
	adds r0, r7, 0
	ldrh r1, [r1]
	bl sub_81646BC
	b _08164AC2
	.pool
_081649BC:
	ldr r0, =gUnknown_02038BCE
	strh r7, [r0]
	ldr r0, =0x0000012b
	cmp r7, r0
	bgt _08164A08
	ldr r0, =gSaveBlock2Ptr
	ldr r4, [r0]
	lsls r1, r5, 1
	adds r0, r1, 0
	adds r0, 0x8
	lsls r0, 1
	ldr r3, =0x00000cb4
	adds r2, r4, r3
	adds r0, r2, r0
	ldrh r3, [r0]
	ldr r5, =0x00000cd8
	adds r0, r4, r5
	strh r3, [r0]
	adds r1, 0x9
	lsls r1, 1
	adds r2, r1
	ldrh r0, [r2]
	ldr r1, =0x00000cda
	adds r4, r1
	strh r0, [r4]
	b _08164A46
	.pool
_08164A08:
	ldr r0, =0x0000018f
	cmp r7, r0
	bgt _08164A30
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r3, =gUnknown_03006298
	ldrh r2, [r3, 0x4]
	ldr r4, =0x00000cd8
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r0, [r3, 0x6]
	b _08164A40
	.pool
_08164A30:
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r3, =gUnknown_03006298
	ldrh r2, [r3]
	ldr r4, =0x00000cd8
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r0, [r3, 0x2]
_08164A40:
	ldr r5, =0x00000cda
	adds r1, r5
	strh r0, [r1]
_08164A46:
	movs r5, 0
	mov r0, r8
	lsls r0, 24
	str r0, [sp, 0x4]
_08164A4E:
	lsls r1, r5, 1
	mov r10, r1
	adds r2, r5, 0x1
	mov r9, r2
	lsrs r0, r5, 31
	adds r0, r5, r0
	asrs r0, 1
	lsls r0, 24
	mov r8, r0
_08164A60:
	ldr r3, [sp, 0x4]
	lsrs r0, r3, 24
	mov r4, r8
	lsrs r1, r4, 24
	bl sub_8162548
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r0, =gUnknown_02038BCE
	ldrh r0, [r0]
	cmp r0, r3
	beq _08164A60
	movs r2, 0
	cmp r2, r5
	bge _08164AA2
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	ldr r4, =0x00000cb4
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, r3
	beq _08164AA2
	adds r6, r1, 0
_08164A8E:
	adds r2, 0x1
	cmp r2, r5
	bge _08164AA2
	ldr r0, [r6]
	lsls r1, r2, 1
	adds r0, r4
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, r3
	bne _08164A8E
_08164AA2:
	cmp r2, r5
	bne _08164A60
	ldr r5, =gSaveBlock2Ptr
	ldr r0, [r5]
	ldr r1, =0x00000cb4
	adds r0, r1
	add r0, r10
	strh r3, [r0]
	mov r5, r9
	cmp r5, 0xD
	ble _08164A4E
	ldr r2, =gSaveBlock2Ptr
	ldr r0, [r2]
	ldr r3, =0x00000cd6
	adds r0, r3
	strh r7, [r0]
_08164AC2:
	movs r0, 0xFA
	lsls r0, 1
	cmp r7, r0
	beq _08164B54
	subs r0, 0xC9
	cmp r7, r0
	bgt _08164AF8
	ldr r0, =gUnknown_085DD500
	ldr r4, [sp]
	lsls r1, r4, 3
	b _08164B04
	.pool
_08164AF8:
	ldr r0, =0x0000018f
	cmp r7, r0
	bgt _08164B28
	ldr r0, =gUnknown_085DD500
	ldr r5, [sp]
	lsls r1, r5, 3
_08164B04:
	adds r0, 0x4
	adds r1, r0
	ldr r0, =gUnknown_020375E2
	ldrh r0, [r0]
	ldr r1, [r1]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl box_related_two__2
	b _08164B54
	.pool
_08164B28:
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r0, =0xfffffe70
	adds r2, r7, r0
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r1, r0
	adds r1, 0xDC
	ldrb r0, [r1]
	lsls r0, 27
	ldr r1, =gUnknown_085DD690
	lsrs r0, 25
	adds r0, r1
	ldr r1, =gUnknown_020375E2
	ldrh r1, [r1]
	ldr r0, [r0]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	bl box_related_two__2
_08164B54:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8164828

	thumb_func_start sub_8164B74
sub_8164B74: @ 8164B74
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r7, r0, 30
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, [r4]
	ldr r2, =0x00000cb2
	adds r0, r2
	ldrh r6, [r0]
	bl link_get_multiplayer_id
	ldr r0, =gUnknown_020375F0
	ldrh r0, [r0]
	cmp r0, 0x6
	bls _08164BAC
	b _08164DB6
_08164BAC:
	lsls r0, 2
	ldr r1, =_08164BD0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08164BD0:
	.4byte _08164BEC
	.4byte _08164C3C
	.4byte _08164CE0
	.4byte _08164D14
	.4byte _08164D98
	.4byte _08164DA8
	.4byte _08164DB6
_08164BEC:
	cmp r5, 0x3
	beq _08164BF2
	b _08164DB0
_08164BF2:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	lsls r1, r7, 1
	adds r0, r1
	ldr r3, =0x00000cec
	adds r0, r3
	ldrh r0, [r0]
	movs r1, 0x7
	bl __udivsi3
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp]
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	bne _08164C18
	b _08164DB6
_08164C18:
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	movs r2, 0x4
	bl link_0800A448
	ldr r1, =gUnknown_020375F0
	movs r0, 0x1
	b _08164DB4
	.pool
_08164C3C:
	bl sub_800A550
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0x3
	beq _08164C4A
	b _08164DB6
_08164C4A:
	bl sub_800A5B4
	ldr r1, =gUnknown_020223C4
	movs r0, 0x80
	lsls r0, 1
	adds r2, r1, r0
	ldrh r0, [r1]
	ldrh r3, [r2]
	cmp r0, r3
	bhi _08164C60
	ldrh r0, [r2]
_08164C60:
	str r0, [sp]
	movs r4, 0
	ldr r0, =gSaveBlock2Ptr
	mov r9, r0
_08164C68:
	adds r1, r4, 0x1
	mov r8, r1
	lsrs r0, r4, 31
	adds r0, r4, r0
	asrs r0, 1
	lsls r7, r0, 24
_08164C74:
	ldr r0, [sp]
	lsls r0, 24
	lsrs r0, 24
	lsrs r1, r7, 24
	bl sub_8162548
	lsls r0, 16
	lsrs r3, r0, 16
	movs r2, 0
	cmp r2, r4
	bge _08164CB0
	mov r1, r9
	ldr r0, [r1]
	ldr r1, =0x00000cb4
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, r3
	beq _08164CB0
	ldr r6, =gSaveBlock2Ptr
	adds r5, r1, 0
_08164C9C:
	adds r2, 0x1
	cmp r2, r4
	bge _08164CB0
	ldr r0, [r6]
	lsls r1, r2, 1
	adds r0, r5
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, r3
	bne _08164C9C
_08164CB0:
	cmp r4, r2
	bne _08164C74
	mov r2, r9
	ldr r0, [r2]
	lsls r1, r4, 1
	ldr r2, =0x00000cb4
	adds r0, r2
	adds r0, r1
	strh r3, [r0]
	mov r4, r8
	cmp r4, 0xD
	ble _08164C68
	ldr r1, =gUnknown_020375F0
	movs r0, 0x2
	b _08164DB4
	.pool
_08164CE0:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _08164DB6
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	ldr r3, =0x00000cb4
	adds r1, r3
	movs r2, 0x28
	bl link_0800A448
	ldr r1, =gUnknown_020375F0
	movs r0, 0x3
	b _08164DB4
	.pool
_08164D14:
	bl sub_800A550
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0x3
	bne _08164DB6
	bl sub_800A5B4
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r5, =0x00000cb4
	adds r0, r5
	ldr r1, =gUnknown_020223C4
	movs r2, 0x28
	bl memcpy
	ldr r2, =gUnknown_02038BCA
	ldr r1, [r4]
	lsls r0, r6, 2
	adds r1, r5
	adds r0, r1, r0
	ldrh r0, [r0]
	strh r0, [r2]
	ldr r4, =gUnknown_02038BCC
	lsls r0, r6, 1
	adds r0, 0x1
	lsls r0, 1
	adds r1, r0
	ldrh r0, [r1]
	strh r0, [r4]
	ldrh r0, [r2]
	movs r1, 0
	bl sub_8162614
	ldrh r0, [r4]
	movs r1, 0x1
	bl sub_8162614
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0
	beq _08164DB0
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	bne _08164DB0
	ldr r1, =gUnknown_020375F0
	movs r0, 0x4
	b _08164DB4
	.pool
_08164D98:
	bl sub_800AC34
	ldr r1, =gUnknown_020375F0
	movs r0, 0x5
	b _08164DB4
	.pool
_08164DA8:
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0
	bne _08164DB6
_08164DB0:
	ldr r1, =gUnknown_020375F0
	movs r0, 0x6
_08164DB4:
	strh r0, [r1]
_08164DB6:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8164B74

	thumb_func_start sub_8164DCC
sub_8164DCC: @ 8164DCC
	push {lr}
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	beq _08164DDA
	bl sub_800AC34
_08164DDA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8164DCC

	thumb_func_start sub_8164DE4
sub_8164DE4: @ 8164DE4
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000cd6
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0xF
	bl sub_8162614
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8164DE4

	thumb_func_start sub_8164E04
sub_8164E04: @ 8164E04
	push {r4-r6,lr}
	sub sp, 0x20
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	bne _08164E9A
	ldr r5, =gUnknown_02038BCA
	ldrh r1, [r5]
	mov r0, sp
	bl sub_8162E20
	mov r0, sp
	bl StripExtCtrlCodes
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r1, =0x00000bd8
	adds r0, r1
	mov r1, sp
	bl StringCopy
	ldr r0, [r4]
	ldr r2, =0x00000beb
	adds r0, r2
	ldrh r1, [r5]
	bl sub_8165B88
	ldr r6, =gBattlePartyID
	ldrh r0, [r6, 0x2]
	movs r5, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	ldr r1, [r4]
	ldr r2, =0x00000bd6
	adds r1, r2
	strh r0, [r1]
	ldrh r0, [r6]
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	ldr r1, [r4]
	ldr r2, =0x00000bd4
	adds r1, r2
	strh r0, [r1]
	movs r2, 0
	movs r5, 0xBE
	lsls r5, 4
	ldr r3, =gUnknown_020240B4
	adds r6, r4, 0
_08164E7C:
	ldr r0, [r4]
	adds r0, r5
	adds r0, r2
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0xA
	ble _08164E7C
	ldr r0, [r6]
	ldr r1, =gBattleOutcome
	ldrb r1, [r1]
	ldr r2, =0x00000d06
	adds r0, r2
	strb r1, [r0]
_08164E9A:
	add sp, 0x20
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8164E04

	thumb_func_start sub_8164ED8
sub_8164ED8: @ 8164ED8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r3, 0
	movs r2, 0
	ldr r4, =0x0000064c
	adds r1, r0, r4
_08164EEA:
	ldm r1!, {r0}
	adds r3, r0
	adds r2, 0x1
	cmp r2, 0x39
	bls _08164EEA
	ldr r5, =gSaveBlock2Ptr
	ldr r1, [r5]
	ldr r2, =0x00000734
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, r3
	beq _08164F0A
	ldr r3, =0x0000064c
	adds r0, r1, r3
	bl sub_8164FB8
_08164F0A:
	movs r4, 0
	adds r7, r5, 0
	movs r6, 0xEC
	mov r8, r7
_08164F12:
	adds r0, r4, 0
	muls r0, r6
	movs r1, 0xE7
	lsls r1, 3
	adds r0, r1
	ldr r1, [r7]
	movs r3, 0
	movs r2, 0
	adds r5, r4, 0x1
	adds r1, r0
_08164F26:
	ldm r1!, {r0}
	adds r3, r0
	adds r2, 0x1
	cmp r2, 0x39
	bls _08164F26
	mov r0, r8
	ldr r2, [r0]
	adds r1, r4, 0
	muls r1, r6
	movs r4, 0x82
	lsls r4, 4
	adds r0, r2, r4
	adds r0, r1
	ldr r0, [r0]
	cmp r0, r3
	beq _08164F52
	movs r3, 0xE7
	lsls r3, 3
	adds r0, r1, r3
	adds r0, r2, r0
	bl sub_8164FB8
_08164F52:
	adds r4, r5, 0
	cmp r4, 0x4
	ble _08164F12
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8164ED8

	thumb_func_start sub_8164F70
sub_8164F70: @ 8164F70
	push {r4,lr}
	adds r2, r0, 0
	adds r2, 0xE8
	movs r1, 0
	str r1, [r2]
	movs r3, 0
	adds r4, r0, 0
_08164F7E:
	ldr r0, [r2]
	ldm r4!, {r1}
	adds r0, r1
	str r0, [r2]
	adds r3, 0x1
	cmp r3, 0x39
	bls _08164F7E
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8164F70

	thumb_func_start sub_8164F94
sub_8164F94: @ 8164F94
	push {r4,lr}
	adds r2, r0, 0
	adds r2, 0xA0
	movs r1, 0
	str r1, [r2]
	movs r3, 0
	adds r4, r0, 0
_08164FA2:
	ldr r0, [r2]
	ldm r4!, {r1}
	adds r0, r1
	str r0, [r2]
	adds r3, 0x1
	cmp r3, 0x27
	bls _08164FA2
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8164F94

	thumb_func_start sub_8164FB8
sub_8164FB8: @ 8164FB8
	push {lr}
	movs r1, 0
	movs r2, 0
_08164FBE:
	stm r0!, {r2}
	adds r1, 0x1
	cmp r1, 0x3A
	bls _08164FBE
	pop {r0}
	bx r0
	thumb_func_end sub_8164FB8

	thumb_func_start sub_8164FCC
sub_8164FCC: @ 8164FCC
	push {lr}
	lsls r0, 24
	lsls r1, 24
	ldr r2, =gSaveBlock2Ptr
	ldr r2, [r2]
	lsrs r0, 23
	lsrs r1, 22
	adds r0, r1
	movs r1, 0xCE
	lsls r1, 4
	adds r2, r1
	adds r2, r0
	ldrh r0, [r2]
	ldr r1, =0x0000270f
	cmp r0, r1
	bls _08164FEE
	adds r0, r1, 0
_08164FEE:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8164FCC

	thumb_func_start sub_8164FFC
sub_8164FFC: @ 8164FFC
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_085DFA42
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	cmp r4, 0x3
	bls _0816501C
	movs r0, 0x3
	b _08165022
	.pool
_0816501C:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
_08165022:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8164FFC

	thumb_func_start sub_816502C
sub_816502C: @ 816502C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r0, 30
	adds r5, r0, 0
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	bl sub_8164FFC
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r2, 0x44
	mov r10, r2
	cmp r5, 0
	beq _0816506A
	movs r0, 0x45
	mov r10, r0
_0816506A:
	ldr r1, =gUnknown_020375F0
	mov r9, r1
	movs r0, 0
	strh r0, [r1]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8164FCC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x37
	bls _081650DC
	movs r6, 0
	cmp r6, r8
	bge _081650DC
	ldr r7, =gSaveBlock1Ptr
	mov r5, sp
_0816508C:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	lsls r1, r6, 1
	ldr r2, =0x00000caa
	adds r0, r2
	adds r0, r1
	ldrh r1, [r0]
	subs r1, 0x1
	movs r0, 0
	strb r1, [r5]
	strb r0, [r5, 0x1]
	movs r0, 0x64
	muls r0, r1
	movs r1, 0x8E
	lsls r1, 2
	adds r4, r0, r1
	ldr r0, [r7]
	adds r0, r4
	mov r1, r10
	bl GetMonData
	cmp r0, 0
	bne _081650D4
	movs r0, 0x1
	mov r2, r9
	strh r0, [r2]
	ldr r0, [r7]
	adds r0, r4
	mov r1, r10
	bl SetMonData
	ldr r0, [r7]
	adds r0, r4
	bl sub_80EE5A4
	strb r0, [r5, 0x1]
_081650D4:
	adds r5, 0x4
	adds r6, 0x1
	cmp r6, r8
	blt _0816508C
_081650DC:
	ldr r0, =gUnknown_020375F0
	ldrh r0, [r0]
	cmp r0, 0
	beq _08165132
	movs r0, 0x2A
	bl sav12_xor_increment
	mov r0, r8
	cmp r0, 0x1
	ble _08165110
	mov r3, sp
	add r2, sp, 0x4
	mov r6, r8
	subs r6, 0x1
_081650F8:
	ldrb r1, [r3, 0x1]
	ldrb r0, [r2, 0x1]
	cmp r0, r1
	bls _08165108
	ldr r1, [sp]
	ldr r0, [r2]
	str r0, [sp]
	str r1, [r2]
_08165108:
	adds r2, 0x4
	subs r6, 0x1
	cmp r6, 0
	bne _081650F8
_08165110:
	mov r0, sp
	ldrb r0, [r0, 0x1]
	cmp r0, 0x4
	bls _08165132
	ldr r2, =gSaveBlock1Ptr
	mov r0, sp
	ldrb r1, [r0]
	movs r0, 0x64
	muls r1, r0
	movs r0, 0x8E
	lsls r0, 2
	adds r1, r0
	ldr r0, [r2]
	adds r0, r1
	mov r1, r10
	bl sub_80EE4DC
_08165132:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816502C

	thumb_func_start sub_816515C
sub_816515C: @ 816515C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r1, =gSaveBlock2Ptr
	ldr r2, [r1]
	ldr r0, =0x00000bec
	adds r7, r2, r0
	ldrb r0, [r2, 0x8]
	adds r5, r1, 0
	cmp r0, 0
	beq _08165194
	ldr r4, =gUnknown_085DCEFA
	ldrb r0, [r2, 0xA]
	ldrb r1, [r2, 0xB]
	adds r0, r1
	ldrb r1, [r2, 0xC]
	adds r0, r1
	ldrb r1, [r2, 0xD]
	adds r0, r1
	movs r1, 0x14
	b _081651A6
	.pool
_08165194:
	ldr r4, =gUnknown_085DCEDC
	ldrb r0, [r2, 0xA]
	ldrb r1, [r2, 0xB]
	adds r0, r1
	ldrb r1, [r2, 0xC]
	adds r0, r1
	ldrb r1, [r2, 0xD]
	adds r0, r1
	movs r1, 0x1E
_081651A6:
	bl __umodsi3
	adds r0, r4
	ldrb r0, [r0]
	strb r0, [r7, 0x1]
	adds r0, r7, 0
	adds r0, 0xC
	ldr r1, [r5]
	adds r1, 0xA
	bl sub_80842F4
	adds r0, r7, 0x4
	ldr r1, [r5]
	bl StringCopy7
	movs r0, 0x1
	strh r0, [r7, 0x2]
	movs r6, 0x7
	movs r4, 0
	ldr r0, =gSaveBlock1Ptr
	mov r8, r0
	adds r5, r7, 0
	adds r5, 0x10
	ldr r1, =0x00002bbc
	mov r12, r1
	adds r3, r7, 0
	adds r3, 0x28
	adds r2, r7, 0
	adds r2, 0x1C
_081651E0:
	lsls r0, r4, 1
	mov r9, r0
	mov r1, r8
	ldr r0, [r1]
	add r0, r12
	add r0, r9
	ldrh r0, [r0]
	strh r0, [r5]
	strh r6, [r2]
	adds r0, r6, 0x6
	strh r0, [r3]
	adds r6, 0x1
	adds r5, 0x2
	adds r3, 0x2
	adds r2, 0x2
	adds r4, 0x1
	cmp r4, 0x5
	ble _081651E0
	movs r4, 0
_08165206:
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2C
	muls r1, r4
	adds r1, 0x34
	adds r1, r7, r1
	bl sub_80686FC
	adds r4, 0x1
	cmp r4, 0x2
	ble _08165206
	adds r0, r7, 0
	bl sub_8165328
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816515C

	thumb_func_start sub_8165244
sub_8165244: @ 8165244
	ldr r1, =gTrainerPicIndices
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000bed
	adds r0, r2
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8165244

	thumb_func_start sub_8165264
sub_8165264: @ 8165264
	ldr r1, =gTrainerClassNameIndices
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000bed
	adds r0, r2
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8165264

	thumb_func_start sub_8165284
sub_8165284: @ 8165284
	push {r4,lr}
	adds r3, r0, 0
	movs r2, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xBF
	lsls r1, 4
	adds r4, r0, r1
_08165294:
	adds r0, r3, r2
	adds r1, r4, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x4
	ble _08165294
	adds r1, r3, r2
	movs r0, 0xFF
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8165284

	thumb_func_start sub_81652B4
sub_81652B4: @ 81652B4
	push {r4-r6,lr}
	ldr r2, =gUnknown_020375F0
	movs r0, 0
	strh r0, [r2]
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	ldr r3, =0x00000bec
	adds r5, r0, r3
	movs r4, 0
	movs r3, 0
	adds r6, r1, 0
	adds r1, r5, 0
_081652CC:
	ldm r1!, {r0}
	orrs r4, r0
	adds r3, 0x1
	cmp r3, 0x2D
	bls _081652CC
	cmp r4, 0
	bne _081652EC
	movs r0, 0x1
	strh r0, [r2]
	b _08165316
	.pool
_081652EC:
	movs r4, 0
	movs r3, 0
	adds r2, r5, 0
_081652F2:
	ldm r2!, {r0}
	adds r4, r0
	adds r3, 0x1
	cmp r3, 0x2D
	bls _081652F2
	ldr r1, [r6]
	ldr r2, =0x00000ca4
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, r4
	beq _08165316
	ldr r3, =0x00000bec
	adds r0, r1, r3
	bl sub_816534C
	ldr r1, =gUnknown_020375F0
	movs r0, 0x1
	strh r0, [r1]
_08165316:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81652B4

	thumb_func_start sub_8165328
sub_8165328: @ 8165328
	push {r4,lr}
	adds r2, r0, 0
	adds r2, 0xB8
	movs r1, 0
	str r1, [r2]
	movs r3, 0
	adds r4, r0, 0
_08165336:
	ldr r0, [r2]
	ldm r4!, {r1}
	adds r0, r1
	str r0, [r2]
	adds r3, 0x1
	cmp r3, 0x2D
	bls _08165336
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8165328

	thumb_func_start sub_816534C
sub_816534C: @ 816534C
	push {lr}
	movs r1, 0
	movs r2, 0
_08165352:
	stm r0!, {r2}
	adds r1, 0x1
	cmp r1, 0x2E
	bls _08165352
	pop {r0}
	bx r0
	thumb_func_end sub_816534C

	thumb_func_start sub_8165360
sub_8165360: @ 8165360
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000bfc
	adds r0, r1
	bl ConvertBattleFrontierTrainerSpeechToString
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8165360

	thumb_func_start sub_816537C
sub_816537C: @ 816537C
	push {lr}
	ldr r0, =gBattleOutcome
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _08165398
	ldr r1, =gStringVar4
	movs r0, 0xFF
	strb r0, [r1]
	b _081653C0
	.pool
_08165398:
	cmp r0, 0x1
	bne _081653B4
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000c14
	adds r0, r1
	bl ConvertBattleFrontierTrainerSpeechToString
	b _081653C0
	.pool
_081653B4:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000c08
	adds r0, r1
	bl ConvertBattleFrontierTrainerSpeechToString
_081653C0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816537C

	thumb_func_start sub_81653CC
sub_81653CC: @ 81653CC
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000ca8
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081653E0
	bl sub_80F01B8
_081653E0:
	movs r0, 0x77
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081653F8
	bl sub_80F01B8
	movs r0, 0x77
	bl FlagReset
_081653F8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81653CC

	thumb_func_start sub_8165404
sub_8165404: @ 8165404
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x70
	lsls r0, 16
	lsrs r7, r0, 16
	bl sub_8165C40
	ldr r0, =0x00000c03
	cmp r7, r0
	beq _08165420
	b _0816554C
_08165420:
	movs r0, 0
	mov r10, r0
	mov r1, sp
	adds r1, 0x44
	str r1, [sp, 0x64]
_0816542A:
	mov r2, r10
	lsls r2, 2
	mov r9, r2
	mov r3, r10
	adds r3, 0x1
	str r3, [sp, 0x60]
	mov r0, r9
	add r0, r10
	lsls r0, 2
	ldr r6, =gUnknown_085DD6D0
	adds r5, r0, r6
_08165440:
	bl Random
	adds r4, r0, 0
	bl Random
	lsls r4, 16
	lsrs r4, 16
	lsls r0, 16
	orrs r4, r0
	str r4, [sp, 0x44]
	ldr r0, =0x0000ef2a
	adds r1, r4, 0
	bl sub_806EBD0
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0
	bne _08165440
	ldr r0, [sp, 0x44]
	bl GetNatureFromPersonality
	ldrb r1, [r5, 0x4]
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	bne _08165440
	movs r0, 0x64
	mov r6, r10
	muls r6, r0
	ldr r1, =gUnknown_02024618
	mov r8, r1
	adds r0, r6, r1
	mov r5, r9
	add r5, r10
	lsls r5, 2
	ldr r2, =gUnknown_085DD6D0
	adds r3, r5, r2
	ldrh r1, [r3]
	ldrb r2, [r3, 0x3]
	ldrb r3, [r3, 0x2]
	mov r12, r3
	movs r4, 0x1
	str r4, [sp]
	mov r3, r10
	str r3, [sp, 0x4]
	str r4, [sp, 0x8]
	ldr r4, =0x0000ef2a
	str r4, [sp, 0xC]
	mov r3, r12
	bl create_pokemon_set_level
	str r7, [sp, 0x44]
	movs r3, 0
	mov r4, r8
	ldr r0, =gUnknown_085DD6D5
	adds r5, r0
_081654B0:
	adds r1, r3, 0
	adds r1, 0x1A
	adds r2, r5, r3
	adds r0, r6, r4
	bl SetMonData
	ldr r0, [sp, 0x44]
	adds r0, 0x1
	str r0, [sp, 0x44]
	adds r3, r0, 0
	cmp r3, 0x5
	ble _081654B0
	movs r0, 0
	str r0, [sp, 0x44]
	movs r1, 0
	movs r6, 0x64
	mov r4, r10
	muls r4, r6
	ldr r7, =gUnknown_085DD6DC
	ldr r6, =gUnknown_02024618
	mov r0, r9
	add r0, r10
	lsls r5, r0, 2
_081654DE:
	lsls r0, r1, 1
	adds r0, r5
	adds r0, r7
	ldrh r1, [r0]
	ldr r0, [sp, 0x64]
	ldrb r2, [r0]
	adds r0, r4, r6
	bl sub_80691F4
	ldr r0, [sp, 0x44]
	adds r0, 0x1
	str r0, [sp, 0x44]
	adds r1, r0, 0
	cmp r1, 0x3
	ble _081654DE
	movs r1, 0x64
	mov r4, r10
	muls r4, r1
	ldr r0, =gUnknown_02024618
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x7
	ldr r2, =gTrainers + TRAINER_STEVEN * 0x28 + 0x4 @ Steven's name
	bl SetMonData
	movs r0, 0
	str r0, [sp, 0x44]
	adds r0, r4, 0
	movs r1, 0x31
	ldr r2, [sp, 0x64]
	bl SetMonData
	adds r0, r4, 0
	bl pokemon_calc_effective_stats
	ldr r2, [sp, 0x60]
	mov r10, r2
	cmp r2, 0x2
	bgt _0816552E
	b _0816542A
_0816552E:
	b _0816585A
	.pool
_0816554C:
	movs r0, 0xFA
	lsls r0, 1
	cmp r7, r0
	bne _08165564
	add r0, sp, 0x10
	ldr r1, =gGameLanguage
	ldrb r1, [r1]
	strb r1, [r0]
	b _0816585A
	.pool
_08165564:
	ldr r0, =0x0000012b
	cmp r7, r0
	bls _0816556C
	b _081656E8
_0816556C:
	bl sub_8165C40
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x50]
	adds r0, r7, 0
	bl sub_8165D08
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4C]
	bl Random
	adds r4, r0, 0
	bl Random
	lsls r4, 16
	lsrs r4, 16
	lsls r0, 16
	orrs r4, r0
	str r4, [sp, 0x58]
	movs r3, 0
	mov r10, r3
	mov r6, sp
	adds r6, 0x44
	str r6, [sp, 0x64]
	mov r0, sp
	adds r0, 0x48
	str r0, [sp, 0x5C]
_081655A6:
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	mov r0, r10
	adds r0, 0x12
	lsls r0, 1
	ldr r2, =0x00000cb4
	adds r1, r2
	adds r1, r0
	ldrh r1, [r1]
	str r1, [sp, 0x54]
	movs r6, 0x64
	mov r3, r10
	muls r3, r6
	mov r8, r3
	ldr r0, =gUnknown_02024618
	mov r9, r0
	mov r0, r8
	add r0, r9
	ldr r6, =gUnknown_0203BC8C
	ldr r4, [r6]
	lsls r5, r1, 4
	adds r4, r5, r4
	ldrh r1, [r4]
	ldr r3, [sp, 0x50]
	lsls r2, r3, 24
	ldrb r3, [r4, 0xC]
	mov r12, r3
	ldr r3, [sp, 0x4C]
	str r3, [sp]
	ldrb r4, [r4, 0xB]
	str r4, [sp, 0x4]
	ldr r3, [sp, 0x58]
	str r3, [sp, 0x8]
	lsrs r2, 24
	mov r3, r12
	bl sub_8068634
	movs r0, 0xFF
	str r0, [sp, 0x48]
	movs r0, 0
	str r0, [sp, 0x44]
	movs r2, 0
	mov r0, r10
	adds r0, 0x1
	str r0, [sp, 0x60]
	mov r4, r8
	mov r3, r9
_08165604:
	ldr r0, [r6]
	adds r0, r5, r0
	lsls r1, r2, 1
	adds r0, 0x2
	adds r0, r1
	ldrh r1, [r0]
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, r3
	str r3, [sp, 0x68]
	bl sub_80691F4
	ldr r0, [r6]
	adds r0, r5, r0
	ldr r2, [sp, 0x44]
	lsls r1, r2, 1
	adds r0, 0x2
	adds r0, r1
	ldrh r0, [r0]
	ldr r3, [sp, 0x68]
	cmp r0, 0xDA
	bne _08165634
	movs r0, 0
	str r0, [sp, 0x48]
_08165634:
	adds r0, r2, 0x1
	str r0, [sp, 0x44]
	adds r2, r0, 0
	cmp r2, 0x3
	ble _08165604
	movs r1, 0x64
	mov r4, r10
	muls r4, r1
	ldr r0, =gUnknown_02024618
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x20
	ldr r2, [sp, 0x5C]
	bl SetMonData
	ldr r0, =gUnknown_0203BC8C
	ldr r1, [r0]
	ldr r2, [sp, 0x54]
	lsls r0, r2, 4
	adds r0, r1
	ldrb r2, [r0, 0xA]
	lsls r2, 1
	ldr r0, =gBattleFrontierHeldItems
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0xC
	bl SetMonData
	movs r0, 0
	str r0, [sp, 0x44]
	movs r2, 0
	ldr r0, =gUnknown_0203BC88
	ldr r1, [r0]
	movs r0, 0x34
	muls r0, r7
	adds r0, r1
	adds r3, r0, 0x4
_0816567E:
	mov r1, sp
	adds r1, r2
	adds r1, 0x10
	adds r0, r3, r2
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, [sp, 0x44]
	adds r0, 0x1
	str r0, [sp, 0x44]
	adds r2, r0, 0
	cmp r2, 0x7
	ble _0816567E
	movs r3, 0x64
	mov r4, r10
	muls r4, r3
	ldr r0, =gUnknown_02024618
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x7
	add r2, sp, 0x10
	bl SetMonData
	adds r0, r7, 0
	bl sub_8162F68
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x44]
	adds r0, r4, 0
	movs r1, 0x31
	ldr r2, [sp, 0x64]
	bl SetMonData
	ldr r6, [sp, 0x60]
	mov r10, r6
	cmp r6, 0x1
	bgt _081656CA
	b _081655A6
_081656CA:
	b _0816585A
	.pool
_081656E8:
	ldr r0, =0x0000018f
	cmp r7, r0
	bls _081656F0
	b _081657F0
_081656F0:
	ldr r1, =0xfffffed4
	adds r0, r7, r1
	lsls r0, 16
	lsrs r7, r0, 16
	movs r2, 0
	mov r10, r2
	mov r3, sp
	adds r3, 0x44
	str r3, [sp, 0x64]
	add r5, sp, 0x18
	ldr r6, =0x000015fc
	mov r9, r6
	ldr r0, =0x0000ffff
	mov r8, r0
	movs r1, 0x24
	str r1, [sp, 0x6C]
_08165710:
	ldr r1, =gSaveBlock2Ptr
	movs r0, 0xEC
	adds r4, r7, 0
	muls r4, r0
	movs r2, 0xE7
	lsls r2, 3
	adds r4, r2
	ldr r0, [r1]
	adds r4, r0, r4
	ldr r3, =0x00000cb4
	adds r0, r3
	ldr r6, [sp, 0x6C]
	adds r0, r6
	ldrh r1, [r0]
	movs r0, 0x2C
	muls r1, r0
	adds r1, r4, r1
	adds r0, r5, 0
	adds r1, 0x34
	ldm r1!, {r2,r3,r6}
	stm r0!, {r2,r3,r6}
	ldm r1!, {r2,r3,r6}
	stm r0!, {r2,r3,r6}
	ldm r1!, {r2,r3,r6}
	stm r0!, {r2,r3,r6}
	ldm r1!, {r2,r3}
	stm r0!, {r2,r3}
	adds r1, r4, 0x4
	add r0, sp, 0x10
	bl StringCopy
	adds r4, 0xE4
	ldrb r0, [r4]
	cmp r0, 0x1
	bne _0816578C
	ldrh r0, [r5, 0x20]
	mov r6, r8
	ands r0, r6
	cmp r0, r9
	beq _0816579C
	mov r1, sp
	adds r1, 0x3D
	movs r0, 0xFF
	strb r0, [r1]
	add r0, sp, 0x38
	movs r1, 0x1
	bl ConvertInternationalString
	b _0816579C
	.pool
_0816578C:
	ldrh r0, [r5, 0x20]
	mov r1, r8
	ands r0, r1
	cmp r0, r9
	bne _0816579C
	add r1, sp, 0x10
	movs r0, 0xFF
	strb r0, [r1, 0x5]
_0816579C:
	movs r0, 0x64
	mov r4, r10
	muls r4, r0
	ldr r0, =gUnknown_02024618
	adds r4, r0
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_8068338
	adds r0, r4, 0
	movs r1, 0x7
	add r2, sp, 0x10
	bl SetMonData
	movs r2, 0x96
	lsls r2, 1
	adds r0, r7, r2
	lsls r0, 16
	lsrs r0, 16
	bl sub_8162F68
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x44]
	adds r0, r4, 0
	movs r1, 0x31
	ldr r2, [sp, 0x64]
	bl SetMonData
	ldr r3, [sp, 0x6C]
	adds r3, 0x2
	str r3, [sp, 0x6C]
	movs r6, 0x1
	add r10, r6
	mov r0, r10
	cmp r0, 0x1
	ble _08165710
	b _0816585A
	.pool
_081657F0:
	ldr r1, =0xfffffe70
	adds r0, r7, r1
	lsls r0, 16
	lsrs r7, r0, 16
	movs r2, 0
	mov r10, r2
	mov r3, sp
	adds r3, 0x44
	str r3, [sp, 0x64]
	ldr r6, =gSaveBlock2Ptr
	mov r8, r6
	movs r5, 0x24
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	adds r6, r0, 0
	adds r6, 0xDC
_08165812:
	movs r0, 0x64
	mov r4, r10
	muls r4, r0
	ldr r0, =gUnknown_02024618
	adds r4, r0
	mov r1, r8
	ldr r0, [r1]
	adds r1, r0, r6
	ldr r2, =0x00000cb4
	adds r0, r2
	adds r0, r5
	ldrb r2, [r0]
	adds r0, r4, 0
	bl sub_8068528
	movs r3, 0xC8
	lsls r3, 1
	adds r0, r7, r3
	lsls r0, 16
	lsrs r0, 16
	bl sub_8162F68
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x44]
	adds r0, r4, 0
	movs r1, 0x31
	ldr r2, [sp, 0x64]
	bl SetMonData
	adds r5, 0x2
	movs r0, 0x1
	add r10, r0
	mov r1, r10
	cmp r1, 0x1
	ble _08165812
_0816585A:
	add sp, 0x70
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8165404

	thumb_func_start sub_816587C
sub_816587C: @ 816587C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	adds r6, r0, 0
	adds r5, r1, 0
	movs r2, 0
	adds r1, r6, 0
	adds r3, r6, 0
	adds r3, 0x58
_08165894:
	ldrh r0, [r1, 0x1C]
	cmp r0, 0
	beq _0816589C
	adds r2, 0x1
_0816589C:
	adds r1, 0x2C
	cmp r1, r3
	ble _08165894
	cmp r2, 0x3
	beq _081658B4
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0xEC
	bl memset
	movs r0, 0
	b _081659BE
_081658B4:
	ldrb r0, [r6]
	strb r0, [r5]
	ldrh r0, [r6, 0x2]
	strh r0, [r5, 0x2]
	movs r2, 0
	ldr r0, =gUnknown_085DCF40
	ldrb r1, [r0]
	ldrb r3, [r6, 0x1]
	mov r12, r0
	adds r4, r5, 0x4
	adds r7, r6, 0x4
	movs r0, 0xC
	adds r0, r5
	mov r9, r0
	movs r0, 0xC
	adds r0, r6
	mov r8, r0
	adds r0, r5, 0
	adds r0, 0x10
	str r0, [sp, 0x4]
	movs r0, 0x10
	adds r0, r6
	mov r10, r0
	adds r0, r5, 0
	adds r0, 0x1C
	str r0, [sp, 0x8]
	adds r0, 0xC
	str r0, [sp, 0xC]
	adds r0, 0x90
	str r0, [sp, 0x10]
	cmp r1, r3
	beq _08165904
	mov r1, r12
_081658F6:
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0x51
	bgt _08165904
	ldrb r0, [r1]
	cmp r0, r3
	bne _081658F6
_08165904:
	cmp r2, 0x52
	beq _08165918
	lsls r0, r2, 1
	mov r1, r12
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	b _0816591A
	.pool
_08165918:
	movs r0, 0x2B
_0816591A:
	strb r0, [r5, 0x1]
	movs r2, 0
	adds r3, r7, 0
_08165920:
	adds r0, r4, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x7
	ble _08165920
	movs r2, 0
	mov r4, r9
	mov r3, r8
_08165934:
	adds r0, r4, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x3
	ble _08165934
	mov r3, r10
	ldr r1, [sp, 0x4]
	movs r2, 0x5
_08165948:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, 0x2
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _08165948
	ldr r3, =gUnknown_085DFA46
	ldr r1, [sp, 0x8]
	movs r2, 0x5
_0816595C:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, 0x2
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _0816595C
	ldr r3, =gUnknown_085DFA52
	ldr r1, [sp, 0xC]
	movs r2, 0x5
_08165970:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, 0x2
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _08165970
	adds r2, r6, 0
	adds r3, r5, 0
	movs r4, 0x58
	adds r4, r2
	mov r8, r4
_08165988:
	adds r1, r3, 0
	adds r1, 0x34
	adds r0, r2, 0
	adds r0, 0x1C
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldm r0!, {r6,r7}
	stm r1!, {r6,r7}
	adds r2, 0x2C
	adds r3, 0x2C
	cmp r2, r8
	ble _08165988
	movs r0, 0
	str r0, [sp]
	ldr r2, =0x0500000b
	mov r0, sp
	ldr r1, [sp, 0x10]
	bl CpuSet
	adds r0, r5, 0
	bl sub_8164F70
	movs r0, 0x1
_081659BE:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_816587C

	thumb_func_start sub_81659DC
sub_81659DC: @ 81659DC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r6, r1, 0
	movs r2, 0
	adds r1, r4, 0
	adds r3, r4, 0
	adds r3, 0x58
_081659F4:
	ldrh r0, [r1, 0x34]
	cmp r0, 0
	beq _081659FC
	adds r2, 0x1
_081659FC:
	adds r1, 0x2C
	cmp r1, r3
	ble _081659F4
	cmp r2, 0x3
	beq _08165A14
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0xA4
	bl memset
	movs r0, 0
	b _08165AD8
_08165A14:
	ldrb r0, [r4]
	strb r0, [r6]
	ldrh r0, [r4, 0x2]
	strh r0, [r6, 0x2]
	movs r2, 0
	ldr r0, =gUnknown_085DCF40
	ldrb r1, [r0, 0x1]
	ldrb r3, [r4, 0x1]
	mov r12, r0
	adds r5, r6, 0x4
	adds r7, r4, 0x4
	movs r0, 0xC
	adds r0, r6
	mov r9, r0
	movs r0, 0xC
	adds r0, r4
	mov r8, r0
	adds r0, r6, 0
	adds r0, 0x10
	str r0, [sp]
	movs r0, 0x10
	adds r0, r4
	mov r10, r0
	cmp r1, r3
	beq _08165A58
	mov r1, r12
	adds r1, 0x1
_08165A4A:
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0x51
	bgt _08165A58
	ldrb r0, [r1]
	cmp r0, r3
	bne _08165A4A
_08165A58:
	cmp r2, 0x52
	beq _08165A68
	lsls r0, r2, 1
	add r0, r12
	ldrb r0, [r0]
	b _08165A6A
	.pool
_08165A68:
	movs r0, 0x24
_08165A6A:
	strb r0, [r6, 0x1]
	movs r2, 0
	adds r3, r7, 0
_08165A70:
	adds r0, r5, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x7
	ble _08165A70
	movs r2, 0
	mov r5, r9
	mov r3, r8
_08165A84:
	adds r0, r5, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x3
	ble _08165A84
	mov r3, r10
	ldr r1, [sp]
	movs r2, 0x5
_08165A98:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, 0x2
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _08165A98
	adds r2, r4, 0
	adds r3, r6, 0
	movs r4, 0x58
	adds r4, r2
	mov r8, r4
_08165AB0:
	adds r1, r3, 0
	adds r1, 0x1C
	adds r0, r2, 0
	adds r0, 0x34
	ldm r0!, {r4,r5,r7}
	stm r1!, {r4,r5,r7}
	ldm r0!, {r4,r5,r7}
	stm r1!, {r4,r5,r7}
	ldm r0!, {r4,r5,r7}
	stm r1!, {r4,r5,r7}
	ldm r0!, {r5,r7}
	stm r1!, {r5,r7}
	adds r2, 0x2C
	adds r3, 0x2C
	cmp r2, r8
	ble _08165AB0
	adds r0, r6, 0
	bl sub_8164F94
	movs r0, 0x1
_08165AD8:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81659DC

	thumb_func_start sub_8165AE8
sub_8165AE8: @ 8165AE8
	push {r4,lr}
	adds r2, r0, 0
	movs r0, 0
	str r0, [r2, 0x40]
	movs r3, 0
	adds r4, r2, 0
_08165AF4:
	ldr r0, [r2, 0x40]
	ldm r4!, {r1}
	adds r0, r1
	str r0, [r2, 0x40]
	adds r3, 0x1
	cmp r3, 0xF
	bls _08165AF4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8165AE8

	thumb_func_start sub_8165B08
sub_8165B08: @ 8165B08
	push {lr}
	movs r1, 0
	movs r3, 0
	adds r2, r0, 0
_08165B10:
	stm r2!, {r3}
	adds r1, 0x1
	cmp r1, 0x10
	bls _08165B10
	bl sub_819FA5C
	pop {r0}
	bx r0
	thumb_func_end sub_8165B08

	thumb_func_start sub_8165B20
sub_8165B20: @ 8165B20
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r5, 0
	ldr r0, =gSaveBlock2Ptr
	mov r8, r0
	mov r9, r8
_08165B30:
	lsls r0, r5, 4
	adds r1, r0, r5
	lsls r1, 2
	adds r1, 0xDC
	mov r3, r9
	ldr r2, [r3]
	movs r4, 0
	movs r3, 0
	adds r6, r0, 0
	adds r7, r5, 0x1
	adds r2, r1
_08165B46:
	ldm r2!, {r0}
	adds r4, r0
	adds r3, 0x1
	cmp r3, 0xF
	bls _08165B46
	mov r0, r8
	ldr r2, [r0]
	adds r0, r6, r5
	lsls r1, r0, 2
	movs r3, 0x8E
	lsls r3, 1
	adds r0, r2, r3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, r4
	beq _08165B70
	adds r0, r1, 0
	adds r0, 0xDC
	adds r0, r2, r0
	bl sub_8165B08
_08165B70:
	adds r5, r7, 0
	cmp r5, 0x3
	ble _08165B30
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8165B20

	thumb_func_start sub_8165B88
sub_8165B88: @ 8165B88
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r2, r1, 16
	adds r3, r2, 0
	movs r0, 0xFA
	lsls r0, 1
	cmp r2, r0
	bne _08165BA4
	ldr r0, =gGameLanguage
	b _08165C28
	.pool
_08165BA4:
	ldr r0, =0x0000012b
	cmp r2, r0
	bhi _08165BB8
	ldr r0, =gGameLanguage
	b _08165C28
	.pool
_08165BB8:
	ldr r0, =0x0000018f
	cmp r2, r0
	bhi _08165BFC
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	beq _08165BDC
	bl sub_81864B4
	b _08165C2A
	.pool
_08165BDC:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0xfffffed4
	adds r2, r1
	movs r1, 0xEC
	muls r1, r2
	adds r0, r1
	ldr r1, =0x0000081c
	adds r0, r1
	b _08165C28
	.pool
_08165BFC:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	beq _08165C14
	bl sub_81864C0
	b _08165C2A
	.pool
_08165C14:
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r0, =0xfffffe70
	adds r1, r3, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, r0
	ldr r1, =0x0000011b
	adds r0, r2, r1
_08165C28:
	ldrb r0, [r0]
_08165C2A:
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8165B88

	thumb_func_start sub_8165C40
sub_8165C40: @ 8165C40
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000ca9
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	beq _08165C84
	ldr r1, =gUnknown_0203BC88
	ldr r0, =gBattleFrontierTrainers
	str r0, [r1]
	ldr r1, =gUnknown_0203BC8C
	ldr r0, =gBattleFrontierMons
	str r0, [r1]
	ldrb r0, [r2]
	lsls r0, 30
	lsrs r0, 30
	bl sub_8165C90
	b _08165C88
	.pool
_08165C84:
	bl sub_8165D78
_08165C88:
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_8165C40

	thumb_func_start sub_8165C90
sub_8165C90: @ 8165C90
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _08165C9E
	cmp r0, 0x1
	beq _08165CA2
_08165C9E:
	movs r0, 0x32
	b _08165CB0
_08165CA2:
	bl sub_8165CB4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3B
	bhi _08165CB0
	movs r0, 0x3C
_08165CB0:
	pop {r1}
	bx r1
	thumb_func_end sub_8165C90

	thumb_func_start sub_8165CB4
sub_8165CB4: @ 8165CB4
	push {r4-r6,lr}
	movs r6, 0
	movs r5, 0
_08165CBA:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	cmp r0, 0
	beq _08165CF4
	adds r0, r4, 0
	movs r1, 0x41
	movs r2, 0
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	beq _08165CF4
	adds r0, r4, 0
	movs r1, 0x38
	movs r2, 0
	bl GetMonData
	cmp r0, r6
	ble _08165CF4
	adds r6, r0, 0
_08165CF4:
	adds r5, 0x1
	cmp r5, 0x5
	ble _08165CBA
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8165CB4

	thumb_func_start sub_8165D08
sub_8165D08: @ 8165D08
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	cmp r0, 0x63
	bls _08165D3A
	movs r1, 0x6
	cmp r0, 0x77
	bls _08165D3A
	movs r1, 0x9
	cmp r0, 0x8B
	bls _08165D3A
	movs r1, 0xC
	cmp r0, 0x9F
	bls _08165D3A
	movs r1, 0xF
	cmp r0, 0xB3
	bls _08165D3A
	movs r1, 0x12
	cmp r0, 0xC7
	bls _08165D3A
	movs r1, 0x1F
	cmp r0, 0xDB
	bhi _08165D3A
	movs r1, 0x15
_08165D3A:
	adds r0, r1, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8165D08

	thumb_func_start sub_8165D40
sub_8165D40: @ 8165D40
	push {lr}
	ldr r0, =0x000040cf
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	beq _08165D58
	cmp r0, 0x3
	beq _08165D58
	cmp r0, 0x4
	bne _08165D70
_08165D58:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1E
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	b _08165D72
	.pool
_08165D70:
	movs r0, 0
_08165D72:
	pop {r1}
	bx r1
	thumb_func_end sub_8165D40

	thumb_func_start sub_8165D78
sub_8165D78: @ 8165D78
	push {lr}
	ldr r0, =0x000040cf
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x4
	bne _08165DA8
	ldr r1, =gUnknown_0203BC88
	ldr r0, =gSlateportBattleTentTrainers
	str r0, [r1]
	ldr r1, =gUnknown_0203BC8C
	ldr r0, =gSlateportBattleTentMons
	b _08165DF2
	.pool
_08165DA8:
	cmp r0, 0x2
	bne _08165DC8
	ldr r1, =gUnknown_0203BC88
	ldr r0, =gVerdanturfBattleTentTrainers
	str r0, [r1]
	ldr r1, =gUnknown_0203BC8C
	ldr r0, =gVerdanturfBattleTentMons
	b _08165DF2
	.pool
_08165DC8:
	cmp r0, 0x3
	bne _08165DE8
	ldr r1, =gUnknown_0203BC88
	ldr r0, =gFallarborBattleTentTrainers
	str r0, [r1]
	ldr r1, =gUnknown_0203BC8C
	ldr r0, =gFallarborBattleTentMons
	b _08165DF2
	.pool
_08165DE8:
	ldr r1, =gUnknown_0203BC88
	ldr r0, =gBattleFrontierTrainers
	str r0, [r1]
	ldr r1, =gUnknown_0203BC8C
	ldr r0, =gBattleFrontierMons
_08165DF2:
	str r0, [r1]
	bl sub_8165CB4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1D
	bhi _08165E02
	movs r0, 0x1E
_08165E02:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8165D78

	thumb_func_start sub_8165E18
sub_8165E18: @ 8165E18
	push {r4,r5,lr}
	ldr r5, =gSaveBlock2Ptr
_08165E1C:
	bl sub_8165D40
	lsls r0, 16
	lsrs r4, r0, 16
	movs r3, 0
	ldr r1, [r5]
	ldr r2, =0x00000cb2
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r3, r0
	bge _08165E58
	adds r2, 0x2
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, r4
	beq _08165E58
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	subs r2, 0x2
	adds r0, r1, r2
	ldrh r2, [r0]
	ldr r0, =0x00000cb4
	adds r1, r0
_08165E4A:
	adds r1, 0x2
	adds r3, 0x1
	cmp r3, r2
	bge _08165E58
	ldrh r0, [r1]
	cmp r0, r4
	bne _08165E4A
_08165E58:
	ldr r0, [r5]
	ldr r1, =0x00000cb2
	adds r0, r1
	ldrh r0, [r0]
	cmp r3, r0
	bne _08165E1C
	ldr r5, =gUnknown_02038BCA
	strh r4, [r5]
	ldrh r0, [r5]
	movs r1, 0
	bl sub_8162614
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r2, =0x00000cb2
	adds r0, r1, r2
	ldrh r2, [r0]
	adds r0, r2, 0x1
	cmp r0, 0x2
	bgt _08165E8C
	lsls r0, r2, 1
	ldr r2, =0x00000cb4
	adds r1, r2
	adds r1, r0
	ldrh r0, [r5]
	strh r0, [r1]
_08165E8C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8165E18

	thumb_func_start sub_8165EA4
sub_8165EA4: @ 8165EA4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x38
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x18]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x1C]
	bl sub_8165D78
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x20]
	ldr r0, =gUnknown_02038BCA
	ldrh r2, [r0]
	ldr r0, =gUnknown_0203BC88
	ldr r1, [r0]
	movs r0, 0x34
	muls r0, r2
	adds r0, r1
	ldr r0, [r0, 0x30]
	str r0, [sp, 0x28]
	movs r0, 0
	str r0, [sp, 0x24]
	ldr r2, [sp, 0x28]
	ldrh r1, [r2]
	b _08165EFE
	.pool
_08165EEC:
	ldr r0, [sp, 0x24]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x24]
	lsls r0, 1
	ldr r6, [sp, 0x28]
	adds r0, r6
	ldrh r1, [r0]
_08165EFE:
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _08165EEC
	movs r0, 0
	mov r8, r0
	bl Random
	adds r4, r0, 0
	bl Random
	lsls r4, 16
	lsrs r4, 16
	lsls r0, 16
	orrs r4, r0
	str r4, [sp, 0x2C]
	b _08166092
	.pool
_08165F24:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	ldr r1, [sp, 0x24]
	bl __modsi3
	lsls r0, 1
	ldr r2, [sp, 0x28]
	adds r0, r2
	ldrh r4, [r0]
	movs r6, 0
	ldr r7, [sp, 0x18]
	add r7, r8
	b _08165F44
_08165F42:
	adds r6, 0x1
_08165F44:
	cmp r6, r7
	bge _08165F68
	movs r1, 0x64
	adds r0, r6, 0
	muls r0, r1
	ldr r2, =gEnemyParty
	adds r0, r2
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	ldr r1, =gUnknown_0203BC8C
	ldr r2, [r1]
	lsls r1, r4, 4
	adds r1, r2
	ldrh r1, [r1]
	cmp r0, r1
	bne _08165F42
_08165F68:
	cmp r6, r7
	beq _08165F6E
	b _08166092
_08165F6E:
	movs r6, 0
	cmp r6, r7
	bge _08165FB8
	ldr r0, =gBattleFrontierHeldItems
	mov r9, r0
	movs r3, 0
_08165F7A:
	ldr r1, =gEnemyParty
	adds r5, r3, r1
	adds r0, r5, 0
	movs r1, 0xC
	movs r2, 0
	str r3, [sp, 0x34]
	bl GetMonData
	ldr r3, [sp, 0x34]
	cmp r0, 0
	beq _08165FB0
	adds r0, r5, 0
	movs r1, 0xC
	movs r2, 0
	bl GetMonData
	ldr r1, =gUnknown_0203BC8C
	ldr r2, [r1]
	lsls r1, r4, 4
	adds r1, r2
	ldrb r1, [r1, 0xA]
	lsls r1, 1
	add r1, r9
	ldr r3, [sp, 0x34]
	ldrh r1, [r1]
	cmp r0, r1
	beq _08165FB8
_08165FB0:
	adds r3, 0x64
	adds r6, 0x1
	cmp r6, r7
	blt _08165F7A
_08165FB8:
	cmp r6, r7
	bne _08166092
	movs r6, 0
	cmp r6, r8
	bge _08165FDA
	add r0, sp, 0xC
	ldrh r0, [r0]
	cmp r0, r4
	beq _08165FDA
	add r1, sp, 0xC
_08165FCC:
	adds r1, 0x2
	adds r6, 0x1
	cmp r6, r8
	bge _08165FDA
	ldrh r0, [r1]
	cmp r0, r4
	bne _08165FCC
_08165FDA:
	cmp r6, r8
	bne _08166092
	mov r2, r8
	lsls r0, r2, 1
	add r0, sp
	adds r0, 0xC
	strh r4, [r0]
	movs r6, 0x64
	adds r0, r7, 0
	muls r0, r6
	ldr r1, =gEnemyParty
	adds r0, r1
	ldr r5, =gUnknown_0203BC8C
	ldr r2, [r5]
	lsls r4, 4
	adds r2, r4, r2
	ldrh r1, [r2]
	ldrb r3, [r2, 0xC]
	movs r6, 0
	str r6, [sp]
	ldrb r2, [r2, 0xB]
	str r2, [sp, 0x4]
	ldr r2, [sp, 0x2C]
	str r2, [sp, 0x8]
	ldr r2, [sp, 0x20]
	bl sub_8068634
	add r1, sp, 0x14
	movs r0, 0xFF
	strb r0, [r1]
	mov r9, r4
	mov r0, r8
	adds r0, 0x1
	str r0, [sp, 0x30]
	movs r0, 0x64
	adds r1, r7, 0
	muls r1, r0
	mov r8, r1
	adds r3, r5, 0
	mov r5, r9
	ldr r2, =gEnemyParty
	mov r10, r2
_0816602E:
	ldr r0, [r3]
	adds r0, r5, r0
	lsls r4, r6, 1
	adds r0, 0x2
	adds r0, r4
	ldrh r1, [r0]
	lsls r2, r6, 24
	lsrs r2, 24
	mov r0, r8
	add r0, r10
	str r3, [sp, 0x34]
	bl sub_80691F4
	ldr r3, [sp, 0x34]
	ldr r0, [r3]
	adds r0, r5, r0
	adds r0, 0x2
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, 0xDA
	bne _0816605E
	movs r0, 0
	mov r1, sp
	strb r0, [r1, 0x14]
_0816605E:
	adds r6, 0x1
	cmp r6, 0x3
	ble _0816602E
	movs r2, 0x64
	adds r4, r7, 0
	muls r4, r2
	ldr r6, =gEnemyParty
	adds r4, r6
	adds r0, r4, 0
	movs r1, 0x20
	add r2, sp, 0x14
	bl SetMonData
	ldr r0, =gUnknown_0203BC8C
	ldr r0, [r0]
	add r0, r9
	ldrb r2, [r0, 0xA]
	lsls r2, 1
	ldr r0, =gBattleFrontierHeldItems
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0xC
	bl SetMonData
	ldr r0, [sp, 0x30]
	mov r8, r0
_08166092:
	ldr r1, [sp, 0x1C]
	cmp r8, r1
	beq _0816609A
	b _08165F24
_0816609A:
	add sp, 0x38
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8165EA4

	thumb_func_start sub_81660B8
sub_81660B8: @ 81660B8
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0
	ldr r3, =gUnknown_085DCEDC
	ldrb r0, [r3]
	cmp r0, r2
	beq _081660DA
_081660C8:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1D
	bhi _081660DA
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	bne _081660C8
_081660DA:
	cmp r1, 0x1E
	beq _081660EC
	ldr r0, =gUnknown_085DCF0E
	b _08166116
	.pool
_081660EC:
	movs r1, 0
	ldr r3, =gUnknown_085DCEFA
	ldrb r0, [r3]
	cmp r0, r2
	beq _08166108
_081660F6:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x13
	bhi _08166108
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	bne _081660F6
_08166108:
	cmp r1, 0x14
	bne _08166114
	movs r0, 0x7
	b _0816611A
	.pool
_08166114:
	ldr r0, =gUnknown_085DCF2C
_08166116:
	adds r0, r1, r0
	ldrb r0, [r0]
_0816611A:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81660B8

	thumb_func_start sub_8166124
sub_8166124: @ 8166124
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r2, =gSaveBlock2Ptr
	movs r0, 0xEC
	muls r0, r6
	movs r1, 0xE7
	lsls r1, 3
	adds r0, r1
	ldr r1, [r2]
	movs r5, 0
	movs r4, 0
	movs r3, 0
	adds r1, r0
_08166140:
	ldm r1!, {r0}
	adds r5, r0
	orrs r4, r0
	adds r3, 0x1
	cmp r3, 0x39
	bls _08166140
	cmp r5, 0
	bne _08166154
	cmp r4, 0
	beq _08166180
_08166154:
	ldr r2, [r2]
	movs r0, 0xEC
	adds r1, r6, 0
	muls r1, r0
	movs r3, 0x82
	lsls r3, 4
	adds r0, r2, r3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, r5
	bne _08166174
	movs r0, 0x1
	b _08166182
	.pool
_08166174:
	movs r3, 0xE7
	lsls r3, 3
	adds r0, r1, r3
	adds r0, r2, r0
	bl sub_8164FB8
_08166180:
	movs r0, 0
_08166182:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8166124

	thumb_func_start sub_8166188
sub_8166188: @ 8166188
	push {r4-r7,lr}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x02000002
	ands r0, r1
	cmp r0, 0
	beq _081661E8
	bl sub_8165C40
	lsls r0, 24
	movs r5, 0
	ldr r7, =gBaseStats
	lsrs r0, 22
	ldr r1, =gExperienceTables
	adds r6, r0, r1
_081661A6:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	adds r1, r0, 0
	cmp r1, 0
	beq _081661E2
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r7
	ldrb r1, [r0, 0x13]
	movs r0, 0xCA
	lsls r0, 1
	adds r2, r1, 0
	muls r2, r0
	adds r2, r6
	adds r0, r4, 0
	movs r1, 0x19
	bl SetMonData
	adds r0, r4, 0
	bl pokemon_calc_effective_stats
_081661E2:
	adds r5, 0x1
	cmp r5, 0x5
	ble _081661A6
_081661E8:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8166188

	thumb_func_start sub_8166204
sub_8166204: @ 8166204
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r4, =gUnknown_0203BCAC
	ldr r0, =0x0000806c
	bl AllocZeroed
	str r0, [r4]
	ldr r1, =gUnknown_0203BC90
	ldr r2, =0x00007fd0
	adds r0, r2
	str r0, [r1]
	str r5, [r0, 0x8]
	str r6, [r0, 0x4]
	ldr r0, =sub_8166380
	bl launch_c3_walk_stairs_and_run_once
	ldr r0, =sub_816631C
	bl SetMainCallback2
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8166204

	thumb_func_start sub_816624C
sub_816624C: @ 816624C
	push {r4,r5,lr}
	ldr r4, =gUnknown_0203BCAC
	ldr r0, =0x0000806c
	bl AllocZeroed
	str r0, [r4]
	ldr r5, =gUnknown_0203BC90
	ldr r1, =0x00007fd0
	adds r0, r1
	str r0, [r5]
	ldr r1, =gUnknown_0203BC98
	ldr r1, [r1]
	str r1, [r0, 0x8]
	ldr r1, =gUnknown_0203BC94
	ldr r1, [r1]
	str r1, [r0, 0x4]
	ldr r4, =gUnknown_0203BC9C
	ldrb r0, [r4]
	bl sub_81672E4
	strb r0, [r4]
	ldr r5, [r5]
	movs r1, 0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _08166284
	movs r1, 0x1
_08166284:
	adds r0, r5, 0
	adds r0, 0x56
	strb r1, [r0]
	ldr r0, =sub_8166380
	bl launch_c3_walk_stairs_and_run_once
	ldr r0, =sub_81662C0
	bl SetMainCallback2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816624C

	thumb_func_start sub_81662C0
sub_81662C0: @ 81662C0
	push {r4,lr}
	ldr r4, =gUnknown_0203BC90
	ldr r0, [r4]
	ldr r0, [r0]
	bl _call_via_r0
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	ldr r4, [r4]
	ldr r1, [r4]
	ldr r0, =map_warp_consider_1_to_outside_or_stair_or_dive
	cmp r1, r0
	bne _081662F0
	adds r0, r4, 0
	adds r0, 0x50
	movs r1, 0
	strb r1, [r0]
	ldr r0, =sub_8166304
	bl SetMainCallback2
_081662F0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81662C0

	thumb_func_start sub_8166304
sub_8166304: @ 8166304
	push {lr}
	bl sub_81668F8
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_8166304

	thumb_func_start sub_816631C
sub_816631C: @ 816631C
	push {lr}
	ldr r0, =gUnknown_0203BC90
	ldr r0, [r0]
	ldr r0, [r0]
	bl _call_via_r0
	bl AnimateSprites
	bl BuildOamBuffer
	bl RunTextPrinters
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816631C

	thumb_func_start sub_8166340
sub_8166340: @ 8166340
	push {lr}
	bl LoadOamFromSprites
	bl ProcessObjectCopyRequests
	bl TransferPlttBuffer
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00007c58
	adds r0, r1
	bl sub_81D2108
	bl sub_80BA0A8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8166340

	thumb_func_start launch_c3_walk_stairs_and_run_once
launch_c3_walk_stairs_and_run_once: @ 816636C
	ldr r1, =gUnknown_0203BC90
	ldr r1, [r1]
	str r0, [r1]
	adds r1, 0x50
	movs r0, 0
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end launch_c3_walk_stairs_and_run_once

	thumb_func_start sub_8166380
sub_8166380: @ 8166380
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r1, =gUnknown_0203BC90
	ldr r0, [r1]
	adds r0, 0x50
	ldrb r0, [r0]
	adds r2, r1, 0
	cmp r0, 0xF
	bls _08166394
	b _08166556
_08166394:
	lsls r0, 2
	ldr r1, =_081663A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081663A8:
	.4byte _081663E8
	.4byte _0816640C
	.4byte _08166416
	.4byte _08166434
	.4byte _08166464
	.4byte _08166468
	.4byte _08166474
	.4byte _08166484
	.4byte _08166490
	.4byte _0816649C
	.4byte _081664B8
	.4byte _081664BC
	.4byte _081664E4
	.4byte _08166510
	.4byte _08166528
	.4byte _08166550
_081663E8:
	ldr r2, =gUnknown_0203BCAC
	ldr r0, [r2]
	ldr r1, =0x00007b10
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	ldr r0, [r2]
	ldr r2, =0x00007c58
	adds r0, r2
	bl sub_81D1ED4
	b _0816653C
	.pool
_0816640C:
	bl ResetAllObjectData
	bl ResetObjectPaletteAllocator
	b _0816653C
_08166416:
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	str r0, [sp]
	movs r1, 0xC0
	lsls r1, 19
	ldr r2, =0x05006000
	mov r0, sp
	bl CpuSet
	b _0816653C
	.pool
_08166434:
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085DFCCC
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	ldr r0, =gUnknown_085DFCDC
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r0, 0
	movs r1, 0x97
	movs r2, 0xE0
	bl sub_809882C
	b _0816653C
	.pool
_08166464:
	ldr r1, [r2]
	b _08166540
_08166468:
	bl sub_8168328
	lsls r0, 24
	cmp r0, 0
	bne _08166556
	b _0816653C
_08166474:
	ldr r1, =gKeyRepeatStartDelay
	movs r0, 0x14
	strh r0, [r1]
	bl sub_8167420
	b _0816653C
	.pool
_08166484:
	bl sub_8167930
	lsls r0, 24
	cmp r0, 0
	bne _08166556
	b _0816653C
_08166490:
	movs r0, 0
	bl sub_8167608
	bl sub_8167760
	b _0816653C
_0816649C:
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00007b0e
	adds r0, r1
	bl sub_81D312C
	lsls r0, 24
	cmp r0, 0
	bne _08166556
	b _0816653C
	.pool
_081664B8:
	ldr r1, [r2]
	b _08166540
_081664BC:
	ldr r5, =gUnknown_0203BCAC
	ldr r1, [r5]
	ldr r4, =0x00007c58
	adds r0, r1, r4
	ldr r2, =0x00007c6c
	adds r1, r2
	bl sub_81D2754
	ldr r0, [r5]
	adds r0, r4
	bl sub_81D20AC
	b _0816653C
	.pool
_081664E4:
	ldr r4, =gUnknown_0203BCAC
	ldr r0, [r4]
	ldr r1, =0x00007c58
	adds r0, r1
	bl sub_81D20BC
	lsls r0, 24
	cmp r0, 0
	bne _08166556
	ldr r2, [r4]
	ldr r1, =0x00007c58
	adds r0, r2, r1
	adds r1, 0x14
	adds r2, r1
	adds r1, r2, 0
	bl sub_81D1F84
	b _0816653C
	.pool
_08166510:
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r2, =0x00007c58
	adds r0, r2
	bl sub_81D2230
	b _0816653C
	.pool
_08166528:
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0x1
	bl sub_8167BA0
_0816653C:
	ldr r0, =gUnknown_0203BC90
	ldr r1, [r0]
_08166540:
	adds r1, 0x50
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08166556
	.pool
_08166550:
	ldr r0, =map_warp_consider_1_to_outside_or_stair_or_dive
	bl launch_c3_walk_stairs_and_run_once
_08166556:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8166380

	thumb_func_start map_warp_consider_1_to_outside_or_stair_or_dive
map_warp_consider_1_to_outside_or_stair_or_dive: @ 8166564
	push {r4,lr}
	sub sp, 0x4
	ldr r4, =gUnknown_0203BC90
	ldr r0, [r4]
	adds r0, 0x50
	ldrb r1, [r0]
	cmp r1, 0
	beq _08166580
	cmp r1, 0x1
	beq _081665C0
	b _08166610
	.pool
_08166580:
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =sub_8166340
	bl SetVBlankCallback
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	ldr r1, [r4]
	adds r1, 0x50
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08166610
	.pool
_081665C0:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08166610
	ldr r4, =gUnknown_0203BCAC
	ldr r0, [r4]
	ldr r1, =0x00007b1c
	adds r0, r1
	bl sub_81D3464
	ldr r4, [r4]
	ldr r2, =0x00008041
	adds r0, r4, r2
	ldrb r1, [r0]
	ldr r3, =0x00008040
	adds r0, r4, r3
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	beq _0816660A
	ldr r1, =0x00007fb3
	adds r0, r4, r1
	movs r1, 0
	ldrsb r1, [r0, r1]
	subs r2, 0x91
	adds r0, r4, r2
	adds r0, r1
	ldrb r2, [r0]
	ldr r3, =0x00007b1c
	adds r0, r4, r3
	subs r3, 0xC
	adds r1, r4, r3
	ldrb r1, [r1]
	bl sub_81D3480
_0816660A:
	ldr r0, =sub_8166634
	bl launch_c3_walk_stairs_and_run_once
_08166610:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end map_warp_consider_1_to_outside_or_stair_or_dive

	thumb_func_start sub_8166634
sub_8166634: @ 8166634
	push {lr}
	ldr r0, =gUnknown_0203BC90
	ldr r0, [r0]
	adds r0, 0x50
	ldrb r0, [r0]
	cmp r0, 0x7
	bls _08166644
	b _0816680E
_08166644:
	lsls r0, 2
	ldr r1, =_08166658
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08166658:
	.4byte _08166678
	.4byte _0816675C
	.4byte _0816680E
	.4byte _08166788
	.4byte _0816680E
	.4byte _08166794
	.4byte _081667AC
	.4byte _081667F4
_08166678:
	ldr r2, =gMain
	ldrh r1, [r2, 0x2C]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081666B8
	movs r0, 0x5
	bl audio_play
	movs r0, 0x1
	bl sub_8167CA0
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00007b1c
	adds r0, r1
	bl sub_81D3520
	ldr r0, =gUnknown_0203BC90
	ldr r0, [r0]
	adds r0, 0x50
	movs r1, 0x1
	b _0816680C
	.pool
_081666B8:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081666F0
	movs r0, 0x5
	bl audio_play
	movs r0, 0
	bl sub_8167CA0
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r2, =0x00007b1c
	adds r0, r2
	bl sub_81D3520
	ldr r0, =gUnknown_0203BC90
	ldr r0, [r0]
	adds r0, 0x50
	movs r1, 0x1
	b _0816680C
	.pool
_081666F0:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08166710
	movs r0, 0x5
	bl audio_play
	ldr r0, =gUnknown_0203BC90
	ldr r0, [r0]
	adds r0, 0x50
	movs r1, 0x3
	b _0816680C
	.pool
_08166710:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0816671A
	b _0816680E
_0816671A:
	movs r0, 0x5
	bl audio_play
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r2, =0x00008041
	adds r1, r0, r2
	ldrb r1, [r1]
	subs r2, 0x1
	adds r0, r2
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	bne _0816674C
	ldr r0, =gUnknown_0203BC90
	ldr r0, [r0]
	adds r0, 0x50
	movs r1, 0x3
	b _0816680C
	.pool
_0816674C:
	ldr r0, =gUnknown_0203BC90
	ldr r0, [r0]
	adds r0, 0x50
	movs r1, 0x5
	b _0816680C
	.pool
_0816675C:
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00008044
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0816680E
	ldr r0, =gUnknown_0203BC90
	ldr r0, [r0]
	adds r0, 0x50
	b _0816680C
	.pool
_08166788:
	ldr r0, =sub_8166BEC
	bl launch_c3_walk_stairs_and_run_once
	b _0816680E
	.pool
_08166794:
	bl sub_8166D44
	ldr r0, =gUnknown_0203BC90
	ldr r1, [r0]
	adds r1, 0x50
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0816680E
	.pool
_081667AC:
	bl sub_8166DE4
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _081667CC
	cmp r1, 0
	bgt _081667C6
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08166804
	b _0816680E
_081667C6:
	cmp r1, 0x1
	bne _0816680E
	b _08166804
_081667CC:
	bl sub_8167268
	lsls r0, 24
	cmp r0, 0
	beq _081667E8
	bl sub_8166F50
	ldr r0, =gUnknown_0203BC90
	ldr r0, [r0]
	adds r0, 0x50
	movs r1, 0x7
	b _0816680C
	.pool
_081667E8:
	ldr r0, =sub_816681C
	bl launch_c3_walk_stairs_and_run_once
	b _0816680E
	.pool
_081667F4:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0816680E
	bl sub_8166F94
_08166804:
	ldr r0, =gUnknown_0203BC90
	ldr r0, [r0]
	adds r0, 0x50
	movs r1, 0
_0816680C:
	strb r1, [r0]
_0816680E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8166634

	thumb_func_start sub_816681C
sub_816681C: @ 816681C
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, =gUnknown_0203BC90
	ldr r0, [r5]
	adds r0, 0x50
	ldrb r4, [r0]
	cmp r4, 0
	beq _08166838
	cmp r4, 0x1
	beq _08166888
	b _081668D4
	.pool
_08166838:
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00008041
	adds r0, r1
	ldrb r0, [r0]
	bl sub_81672A4
	ldr r1, =gUnknown_0203BC9C
	strb r0, [r1]
	ldr r1, =gUnknown_0203BC94
	ldr r2, [r5]
	ldr r0, [r2, 0x4]
	str r0, [r1]
	ldr r1, =gUnknown_0203BC98
	ldr r0, [r2, 0x8]
	str r0, [r1]
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, [r5]
	adds r1, 0x50
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _081668D4
	.pool
_08166888:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _081668D4
	movs r0, 0
	bl SetVBlankCallback
	ldr r4, =gUnknown_0203BCA0
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203BCA4
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203BCA8
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203BCAC
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	bl FreeAllWindowBuffers
	ldr r1, =gMain
	ldr r0, =sub_816624C
	str r0, [r1, 0x8]
	bl sub_8179D70
_081668D4:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816681C

	thumb_func_start sub_81668F8
sub_81668F8: @ 81668F8
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gUnknown_0203BC90
	ldr r0, [r1]
	adds r0, 0x50
	ldrb r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x6
	bls _0816690C
	b _08166A18
_0816690C:
	lsls r0, 2
	ldr r1, =_08166920
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08166920:
	.4byte _0816693C
	.4byte _08166972
	.4byte _08166A18
	.4byte _081669A0
	.4byte _081669AE
	.4byte _081669C8
	.4byte _081669F4
_0816693C:
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00008041
	adds r0, r1
	ldr r1, =gUnknown_0203BC9C
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _08166968
	ldr r0, [r4]
	adds r0, 0x56
	ldrb r0, [r0]
	bl sub_8167CA0
	ldr r1, [r4]
	b _081669E2
	.pool
_08166968:
	ldr r0, [r4]
	adds r0, 0x50
	movs r1, 0x3
	strb r1, [r0]
	b _08166A18
_08166972:
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00008044
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _08166A18
	ldr r0, =gUnknown_0203BC90
	ldr r0, [r0]
	adds r0, 0x50
	strb r1, [r0]
	b _08166A18
	.pool
_081669A0:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	b _081669DE
_081669AE:
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	b _081669DE
_081669C8:
	ldr r0, =sub_8166340
	bl SetVBlankCallback
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
_081669DE:
	ldr r0, =gUnknown_0203BC90
	ldr r1, [r0]
_081669E2:
	adds r1, 0x50
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08166A18
	.pool
_081669F4:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08166A18
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00007b1c
	adds r0, r1
	bl sub_81D3464
	ldr r0, =sub_8166A34
	bl launch_c3_walk_stairs_and_run_once
	ldr r0, =sub_816631C
	bl SetMainCallback2
_08166A18:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81668F8

	thumb_func_start sub_8166A34
sub_8166A34: @ 8166A34
	push {r4-r6,lr}
	ldr r1, =gUnknown_0203BC90
	ldr r0, [r1]
	adds r0, 0x50
	ldrb r0, [r0]
	adds r5, r1, 0
	cmp r0, 0x5
	bls _08166A46
	b _08166BDA
_08166A46:
	lsls r0, 2
	ldr r1, =_08166A58
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08166A58:
	.4byte _08166A70
	.4byte _08166AAC
	.4byte _08166AC0
	.4byte _08166B14
	.4byte _08166B94
	.4byte _08166BB6
_08166A70:
	ldr r4, [r5]
	ldr r3, =gPlayerParty
	str r3, [r4, 0xC]
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r2, =0x00008041
	adds r1, r0, r2
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r0, r1
	subs r2, 0x88
	adds r1, r2
	ldrb r2, [r1]
	movs r1, 0x64
	muls r1, r2
	adds r1, r3
	str r1, [r4, 0xC]
	ldr r3, =0x00007b1c
	adds r0, r3
	bl sub_81D3520
	b _08166BAA
	.pool
_08166AAC:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _08166ABA
	b _08166BDA
_08166ABA:
	b _08166BAA
	.pool
_08166AC0:
	bl sub_8167104
	ldr r6, =gUnknown_0203BC90
	ldr r0, [r6]
	adds r0, 0x5C
	ldr r4, =gUnknown_0203BCAC
	ldr r1, [r4]
	ldr r5, =0x00007ca8
	adds r1, r5
	bl sub_81D2754
	ldr r2, [r4]
	ldr r4, =0x00007c58
	adds r0, r2, r4
	ldr r3, =0x00007fb3
	adds r1, r2, r3
	movs r3, 0
	ldrsb r3, [r1, r3]
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 2
	adds r4, 0x14
	adds r1, r4
	adds r1, r2, r1
	adds r2, r5
	bl sub_81D1F84
	bl sub_8167338
	ldr r1, [r6]
	b _08166BAC
	.pool
_08166B14:
	ldr r5, =gUnknown_0203BCAC
	ldr r0, [r5]
	ldr r1, =0x00007c58
	adds r0, r1
	bl sub_81D2074
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _08166BDA
	ldr r0, [r5]
	ldr r4, =0x00008041
	adds r0, r4
	ldrb r0, [r0]
	bl sub_81672A4
	lsls r0, 24
	lsrs r0, 24
	bl sub_81681F4
	ldr r3, [r5]
	adds r4, r3, r4
	ldrb r1, [r4]
	ldr r2, =0x00008040
	adds r0, r3, r2
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	beq _08166B6C
	ldr r4, =0x00007fb3
	adds r0, r3, r4
	movs r1, 0
	ldrsb r1, [r0, r1]
	subs r2, 0x90
	adds r0, r3, r2
	adds r0, r1
	ldrb r2, [r0]
	ldr r4, =0x00007b1c
	adds r0, r3, r4
	subs r4, 0xC
	adds r1, r3, r4
	ldrb r1, [r1]
	bl sub_81D3480
_08166B6C:
	ldr r1, =gUnknown_0203BC90
	ldr r0, [r1]
	adds r0, 0x52
	strb r6, [r0]
	ldr r1, [r1]
	b _08166BAC
	.pool
_08166B94:
	ldr r1, [r5]
	adds r1, 0x52
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x10
	bls _08166BDA
	bl sub_8166E24
_08166BAA:
	ldr r1, [r5]
_08166BAC:
	adds r1, 0x50
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08166BDA
_08166BB6:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _08166BDA
	bl sub_8166EDC
	lsls r0, 24
	cmp r0, 0
	bne _08166BDA
	ldr r0, =gUnknown_0203CE7C
	ldrb r0, [r0]
	bl sub_8136F68
	ldr r0, =sub_8166BEC
	bl launch_c3_walk_stairs_and_run_once
_08166BDA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8166A34

	thumb_func_start sub_8166BEC
sub_8166BEC: @ 8166BEC
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r4, =gUnknown_0203BC90
	ldr r0, [r4]
	adds r2, r0, 0
	adds r2, 0x50
	ldrb r1, [r2]
	cmp r1, 0x1
	beq _08166C28
	cmp r1, 0x1
	bgt _08166C0C
	cmp r1, 0
	beq _08166C16
	b _08166D18
	.pool
_08166C0C:
	cmp r1, 0x2
	beq _08166C40
	cmp r1, 0x3
	beq _08166C5C
	b _08166D18
_08166C16:
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _08166C4A
_08166C28:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08166D18
	movs r0, 0x2
	strb r0, [r2]
	b _08166D18
	.pool
_08166C40:
	ldr r1, =gUnknown_02039B28
	movs r0, 0x3
	strb r0, [r1, 0x15]
	bl sub_80BA0A8
_08166C4A:
	ldr r1, [r4]
	adds r1, 0x50
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08166D18
	.pool
_08166C5C:
	ldr r0, [r0, 0x4]
	bl SetMainCallback2
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00007b1c
	adds r0, r1
	bl sub_81D354C
	movs r4, 0
_08166C70:
	ldr r5, =gUnknown_0203BCAC
	ldr r0, [r5]
	ldr r2, =0x00007b06
	adds r0, r2
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x6
	bls _08166C70
	movs r0, 0
	bl FreeObjectTilesByTag
	movs r0, 0x1
	bl FreeObjectTilesByTag
	movs r0, 0
	bl FreeObjectPaletteByTag
	movs r0, 0x1
	bl FreeObjectPaletteByTag
	movs r4, 0
_08166CAE:
	ldr r0, [r5]
	lsls r1, r4, 2
	ldr r2, =0x00007b44
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	bl DestroySprite
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bls _08166CAE
	ldr r6, =gUnknown_0203BCAC
	ldr r0, [r6]
	ldr r2, =0x00007b10
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _08166CE6
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
_08166CE6:
	movs r0, 0
	bl SetVBlankCallback
	ldr r4, =gUnknown_0203BCA0
	ldr r0, [r4]
	bl Free
	movs r5, 0
	str r5, [r4]
	ldr r4, =gUnknown_0203BCA4
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203BCA8
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r0, [r6]
	bl Free
	str r5, [r6]
	bl FreeAllWindowBuffers
_08166D18:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8166BEC

	thumb_func_start sub_8166D44
sub_8166D44: @ 8166D44
	push {r4,lr}
	sub sp, 0x4C
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00008041
	adds r0, r1
	ldrb r0, [r0]
	bl sub_81672A4
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	add r2, sp, 0xC
	bl GetMonData
	add r0, sp, 0xC
	bl StringGetEnd10
	ldr r1, =gUnknown_085EC7A0
	add r0, sp, 0xC
	bl StringAppend
	ldr r4, =gStringVar4
	adds r0, r4, 0
	add r1, sp, 0xC
	bl StringCopy
	movs r0, 0x2
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x2
	movs r1, 0x97
	movs r2, 0xE
	bl sub_8098858
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0
	bl Print
	movs r0, 0x2
	bl PutWindowTilemap
	movs r0, 0x2
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =gUnknown_085DFCFC
	movs r1, 0x97
	movs r2, 0xE
	movs r3, 0
	bl CreateYesNoMenu
	add sp, 0x4C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8166D44

	thumb_func_start sub_8166DE4
sub_8166DE4: @ 8166DE4
	push {r4,lr}
	bl sub_8198C58
	lsls r0, 24
	lsrs r4, r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _08166E18
	cmp r1, 0
	bgt _08166E02
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08166E06
	b _08166E18
_08166E02:
	cmp r1, 0x1
	bne _08166E18
_08166E06:
	movs r0, 0x5
	bl audio_play
	movs r0, 0x2
	bl rbox_fill_rectangle
	movs r0, 0x2
	bl ClearWindowTilemap
_08166E18:
	lsls r0, r4, 24
	asrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8166DE4

	thumb_func_start sub_8166E24
sub_8166E24: @ 8166E24
	push {r4,lr}
	movs r0, 0x2
	movs r1, 0x97
	movs r2, 0xE
	bl sub_8098858
	movs r0, 0x2
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r3, =gUnknown_0203BC90
	ldr r0, [r3]
	adds r0, 0x53
	movs r1, 0
	strb r1, [r0]
	ldr r2, [r3]
	adds r1, r2, 0
	adds r1, 0x53
	ldrb r0, [r1]
	cmp r0, 0x4
	bhi _08166EA8
	adds r0, r2, 0
	adds r0, 0x61
	ldrb r1, [r1]
	adds r0, r1
	ldrb r0, [r0]
	adds r4, r3, 0
	cmp r0, 0
	bne _08166E84
	adds r2, r4, 0
_08166E60:
	ldr r0, [r2]
	adds r0, 0x53
	ldrb r1, [r0]
	adds r1, 0x1
	strb r1, [r0]
	ldr r3, [r2]
	adds r1, r3, 0
	adds r1, 0x53
	ldrb r0, [r1]
	cmp r0, 0x4
	bhi _08166EA8
	adds r0, r3, 0
	adds r0, 0x61
	ldrb r1, [r1]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08166E60
_08166E84:
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0x53
	ldrb r0, [r1]
	cmp r0, 0x4
	bhi _08166EA8
	ldr r0, =gStringVar4
	ldrb r1, [r1]
	adds r2, 0x61
	adds r2, r1
	ldrb r2, [r2]
	bl sub_8166FD4
	b _08166EB8
	.pool
_08166EA8:
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_0203BC90
	ldr r1, [r1]
	adds r1, 0x53
	ldrb r1, [r1]
	movs r2, 0
	bl sub_8166FD4
_08166EB8:
	ldr r0, =gStringVar4
	bl sub_8166FB0
	movs r0, 0x2
	bl PutWindowTilemap
	movs r0, 0x2
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8166E24

	thumb_func_start sub_8166EDC
sub_8166EDC: @ 8166EDC
	push {r4,r5,lr}
	movs r0, 0x2
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r5, =gUnknown_0203BC90
	adds r3, r5, 0
	movs r4, 0x5
_08166EEC:
	ldr r0, [r3]
	adds r0, 0x53
	ldrb r1, [r0]
	adds r1, 0x1
	strb r1, [r0]
	ldr r2, [r3]
	adds r1, r2, 0
	adds r1, 0x53
	ldrb r0, [r1]
	cmp r0, 0x4
	bhi _08166F18
	adds r0, r2, 0
	adds r0, 0x61
	ldrb r1, [r1]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08166F1E
	b _08166EEC
	.pool
_08166F18:
	strb r4, [r1]
	movs r0, 0
	b _08166F44
_08166F1E:
	ldr r4, =gStringVar4
	ldr r0, [r5]
	adds r1, r0, 0
	adds r1, 0x53
	ldrb r1, [r1]
	adds r0, 0x61
	adds r0, r1
	ldrb r2, [r0]
	adds r0, r4, 0
	bl sub_8166FD4
	adds r0, r4, 0
	bl sub_8166FB0
	movs r0, 0x2
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x1
_08166F44:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8166EDC

	thumb_func_start sub_8166F50
sub_8166F50: @ 8166F50
	push {lr}
	sub sp, 0xC
	movs r0, 0x2
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x2
	movs r1, 0x97
	movs r2, 0xE
	bl sub_8098858
	ldr r2, =gUnknown_085EC800
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r3, 0
	bl Print
	movs r0, 0x2
	bl PutWindowTilemap
	movs r0, 0x2
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8166F50

	thumb_func_start sub_8166F94
sub_8166F94: @ 8166F94
	push {lr}
	movs r0, 0x2
	bl rbox_fill_rectangle
	movs r0, 0x2
	bl ClearWindowTilemap
	movs r0, 0x2
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r0}
	bx r0
	thumb_func_end sub_8166F94

	thumb_func_start sub_8166FB0
sub_8166FB0: @ 8166FB0
	push {lr}
	sub sp, 0xC
	ldr r2, =gStringVar4
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r3, 0
	bl Print
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8166FB0

	thumb_func_start sub_8166FD4
sub_8166FD4: @ 8166FD4
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r3, r1, 24
	lsls r2, 16
	lsrs r0, r2, 16
	asrs r2, 16
	cmp r2, 0
	beq _08167010
	cmp r2, 0
	ble _08166FEC
	movs r0, 0
_08166FEC:
	lsls r0, 16
	ldr r1, =gUnknown_085DFD04
	lsls r0, r3, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r4, 0
	bl StringCopy
	ldr r1, =gUnknown_085EC7E1
	adds r0, r4, 0
	bl StringAppend
	b _08167018
	.pool
_08167010:
	ldr r1, =gUnknown_085EC7EF
	adds r0, r4, 0
	bl StringCopy
_08167018:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8166FD4

	thumb_func_start sub_8167024
sub_8167024: @ 8167024
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	movs r4, 0
	ldr r7, =gUnknown_085DFCB0
_0816702E:
	lsls r0, r4, 2
	adds r0, r7
	ldr r1, [r0]
	adds r0, r6, 0
	bl GetMonData
	adds r1, r5, r4
	strb r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x4
	bls _0816702E
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8167024

	thumb_func_start sub_8167054
sub_8167054: @ 8167054
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	mov r8, r0
	adds r5, r1, 0
	adds r0, r5, 0
	movs r1, 0x30
	bl GetMonData
	cmp r0, 0xFF
	beq _081670F0
	mov r0, r8
	adds r1, r5, 0
	bl sub_8167184
	movs r4, 0
	mov r7, sp
_08167078:
	ldr r1, =gUnknown_085DFCB0
	lsls r0, r4, 2
	adds r0, r1
	ldr r6, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	bl GetMonData
	lsls r0, 24
	lsrs r0, 24
	strb r0, [r7]
	ldr r1, =gUnknown_0203BC90
	ldr r1, [r1]
	lsls r2, r4, 1
	adds r1, 0x66
	adds r1, r2
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r0, 0
	bge _081670A6
	movs r1, 0
_081670A6:
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _081670B0
	movs r1, 0xFF
_081670B0:
	strb r1, [r7]
	adds r0, r5, 0
	adds r1, r6, 0
	mov r2, sp
	bl SetMonData
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x4
	bls _08167078
	adds r0, r5, 0
	movs r1, 0x30
	bl GetMonData
	lsls r0, 24
	lsrs r0, 24
	mov r2, r8
	ldrb r2, [r2, 0x6]
	adds r1, r0, r2
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _081670E2
	movs r1, 0xFF
_081670E2:
	mov r0, sp
	strb r1, [r0]
	adds r0, r5, 0
	movs r1, 0x30
	mov r2, sp
	bl SetMonData
_081670F0:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8167054

	thumb_func_start sub_8167104
sub_8167104: @ 8167104
	push {r4,r5,lr}
	ldr r5, =gPlayerParty
	ldr r0, =gUnknown_0203BCAC
	ldr r1, [r0]
	ldr r2, =0x00008041
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 2
	adds r1, r0
	ldr r0, =0x00007fb9
	adds r1, r0
	ldrb r1, [r1]
	movs r0, 0x64
	muls r0, r1
	adds r5, r0, r5
	ldr r4, =gUnknown_0203BC90
	ldr r1, [r4]
	adds r1, 0x57
	adds r0, r5, 0
	bl sub_8167024
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	adds r1, r5, 0
	bl sub_8167054
	ldr r1, [r4]
	adds r1, 0x5C
	adds r0, r5, 0
	bl sub_8167024
	movs r3, 0
_08167144:
	ldr r0, [r4]
	adds r2, r0, 0
	adds r2, 0x61
	adds r2, r3
	adds r1, r0, 0
	adds r1, 0x5C
	adds r1, r3
	adds r0, 0x57
	adds r0, r3
	ldrb r1, [r1]
	ldrb r0, [r0]
	subs r1, r0
	strb r1, [r2]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x4
	bls _08167144
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8167104

	thumb_func_start sub_8167184
sub_8167184: @ 8167184
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r10, r1
	ldr r1, =gUnknown_0203BC90
	ldr r3, [r1]
	ldrb r1, [r0, 0x1]
	adds r2, r3, 0
	adds r2, 0x66
	strh r1, [r2]
	ldrb r2, [r0, 0x5]
	adds r1, r3, 0
	adds r1, 0x68
	strh r2, [r1]
	ldrb r1, [r0, 0x4]
	adds r2, r3, 0
	adds r2, 0x6A
	strh r1, [r2]
	ldrb r2, [r0, 0x3]
	adds r1, r3, 0
	adds r1, 0x6C
	strh r2, [r1]
	ldrb r1, [r0, 0x2]
	adds r0, r3, 0
	adds r0, 0x6E
	strh r1, [r0]
	ldr r0, =gUnknown_0203BC9E
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	ble _081671D4
	movs r0, 0x1
	b _081671DA
	.pool
_081671D4:
	cmp r0, 0
	bge _08167250
	movs r0, 0xFF
_081671DA:
	movs r2, 0
	lsls r0, 24
	mov r9, r0
	ldr r0, =gUnknown_0203BC90
	mov r8, r0
_081671E4:
	mov r0, r8
	ldr r1, [r0]
	lsls r0, r2, 24
	asrs r6, r0, 24
	lsls r7, r6, 1
	adds r1, 0x66
	adds r1, r7
	movs r2, 0
	ldrsh r4, [r1, r2]
	adds r0, r4, 0
	movs r1, 0xA
	bl __divsi3
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	movs r1, 0xA
	bl __modsi3
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _0816721C
	lsls r0, r5, 24
	movs r1, 0x80
	lsls r1, 17
	adds r0, r1
	lsrs r5, r0, 24
_0816721C:
	ldr r0, =gUnknown_085DFCC4
	adds r0, r6, r0
	ldrb r1, [r0]
	mov r0, r10
	bl sub_806E858
	lsls r0, 24
	asrs r2, r0, 24
	cmp r0, r9
	bne _08167244
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x66
	adds r0, r7
	lsls r1, r5, 24
	asrs r1, 24
	muls r1, r2
	ldrh r2, [r0]
	adds r1, r2
	strh r1, [r0]
_08167244:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	asrs r0, 24
	cmp r0, 0x4
	ble _081671E4
_08167250:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8167184

	thumb_func_start sub_8167268
sub_8167268: @ 8167268
	push {lr}
	ldr r0, =gUnknown_0203BCAC
	ldr r1, [r0]
	ldr r2, =0x00008041
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 2
	adds r1, r0
	subs r2, 0x89
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	movs r2, 0x30
	movs r3, 0
	bl sub_81D2C68
	cmp r0, 0xFF
	beq _0816729C
	movs r0, 0
	b _0816729E
	.pool
_0816729C:
	movs r0, 0x1
_0816729E:
	pop {r1}
	bx r1
	thumb_func_end sub_8167268

	thumb_func_start sub_81672A4
sub_81672A4: @ 81672A4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
_081672AC:
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _081672D2
	cmp r5, 0
	bne _081672CC
	adds r0, r4, 0
	b _081672DE
	.pool
_081672CC:
	subs r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_081672D2:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	bls _081672AC
	movs r0, 0
_081672DE:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81672A4

	thumb_func_start sub_81672E4
sub_81672E4: @ 81672E4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	movs r6, 0
	cmp r6, r5
	bcs _08167314
_081672F2:
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	beq _0816730A
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_0816730A:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _081672F2
_08167314:
	subs r0, r5, r6
	lsls r0, 24
	lsrs r0, 24
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81672E4

	thumb_func_start sub_8167324
sub_8167324: @ 8167324
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl sub_81672A4
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_8167324

	thumb_func_start sub_8167338
sub_8167338: @ 8167338
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gUnknown_085DFD18
	bl LoadObjectPic
	ldr r0, =gUnknown_085DFD20
	bl LoadTaggedObjectPalette
	ldr r2, =gUnknown_0203BC90
	ldr r0, [r2]
	adds r0, 0x54
	movs r1, 0
	strb r1, [r0]
	movs r4, 0
	adds r5, r2, 0
	ldr r6, =gUnknown_085DFD28
	adds r0, r6, 0x2
	mov r8, r0
	ldr r7, =gUnknown_0202064C
_08167360:
	ldr r0, [r5]
	adds r0, 0x61
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _081673AC
	lsls r2, r4, 2
	adds r0, r2, r6
	movs r3, 0
	ldrsh r1, [r0, r3]
	add r2, r8
	movs r0, 0
	ldrsh r2, [r2, r0]
	ldr r0, =gUnknown_085DFD5C
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _081673AC
	ldr r0, [r5]
	adds r0, 0x61
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _081673A2
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldr r1, =sub_81673DC
	str r1, [r0]
_081673A2:
	ldr r1, [r5]
	adds r1, 0x54
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_081673AC:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x4
	bls _08167360
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8167338

	thumb_func_start sub_81673DC
sub_81673DC: @ 81673DC
	push {lr}
	adds r1, r0, 0
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0x5
	bgt _081673EE
	ldrh r0, [r1, 0x26]
	subs r0, 0x2
	b _081673F6
_081673EE:
	cmp r0, 0xB
	bgt _081673F8
	ldrh r0, [r1, 0x26]
	adds r0, 0x2
_081673F6:
	strh r0, [r1, 0x26]
_081673F8:
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3C
	ble _08167418
	adds r0, r1, 0
	bl DestroySprite
	ldr r0, =gUnknown_0203BC90
	ldr r1, [r0]
	adds r1, 0x54
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
_08167418:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81673DC

	thumb_func_start sub_8167420
sub_8167420: @ 8167420
	push {r4-r6,lr}
	movs r4, 0
	movs r5, 0
	ldr r6, =gUnknown_0203BCAC
	b _08167472
	.pool
_08167430:
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2D
	bl GetMonData
	adds r3, r0, 0
	cmp r3, 0
	bne _0816746C
	ldr r1, [r6]
	lsls r2, r5, 2
	adds r1, r2
	ldr r0, =0x00007fb8
	adds r1, r0
	movs r0, 0xE
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, r2
	ldr r1, =0x00007fb9
	adds r0, r1
	strb r4, [r0]
	ldr r0, [r6]
	adds r0, r2
	ldr r2, =0x00007fba
	adds r0, r2
	strh r3, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_0816746C:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_08167472:
	bl calc_player_party_count
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bcc _08167430
	ldr r2, =gUnknown_0203BCAC
	ldr r0, [r2]
	ldr r1, =0x00008041
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	adds r1, r5, 0x1
	ldr r2, =0x00008040
	adds r0, r2
	strb r1, [r0]
	bl sub_81674BC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8167420

	thumb_func_start sub_81674BC
sub_81674BC: @ 81674BC
	push {r4,r5,lr}
	ldr r4, =gUnknown_0203BCAC
	ldr r0, [r4]
	ldr r5, =0x00008041
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0
	bl sub_816753C
	ldr r0, [r4]
	ldr r1, =0x00007fb3
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, =0x00007fb4
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, =0x00007fb5
	adds r0, r1
	movs r1, 0x2
	strb r1, [r0]
	ldr r0, [r4]
	adds r5, r0, r5
	ldrb r3, [r5]
	adds r1, r3, 0x1
	adds r2, 0x8C
	adds r0, r2
	ldrb r2, [r0]
	cmp r1, r2
	blt _08167500
	movs r1, 0
_08167500:
	subs r0, r3, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r0, 0
	bge _08167510
	subs r0, r2, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_08167510:
	adds r0, r1, 0
	movs r1, 0x1
	bl sub_816753C
	lsls r0, r4, 16
	asrs r0, 16
	movs r1, 0x2
	bl sub_816753C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81674BC

	thumb_func_start sub_816753C
sub_816753C: @ 816753C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203BCAC
	mov r9, r0
	ldr r1, [r0]
	lsls r5, 16
	asrs r0, r5, 14
	adds r0, r1, r0
	ldr r3, =0x00007fb8
	adds r2, r0, r3
	ldrb r7, [r2]
	ldr r2, =0x00007fb9
	adds r0, r2
	ldrb r0, [r0]
	mov r10, r0
	adds r3, 0x88
	adds r0, r1, r3
	ldrb r6, [r0]
	movs r0, 0
	mov r8, r0
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 3
	ldr r2, =0x00007b4d
	adds r0, r2
	adds r0, r1, r0
	lsls r2, r4, 6
	ldr r3, =0x00007b95
	adds r2, r3
	adds r1, r2
	lsrs r5, 16
	str r5, [sp]
	str r6, [sp, 0x4]
	mov r2, r8
	str r2, [sp, 0x8]
	adds r2, r7, 0
	mov r3, r10
	bl sub_81D2ED4
	mov r3, r9
	ldr r1, [r3]
	ldr r2, =0x00007c58
	adds r0, r1, r2
	ldr r3, =0x00007fb0
	adds r1, r3
	str r5, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r2, r8
	str r2, [sp, 0xC]
	adds r2, r7, 0
	mov r3, r10
	bl sub_81D2F78
	lsls r0, r4, 13
	movs r1, 0xC1
	lsls r1, 2
	adds r0, r1
	mov r3, r9
	ldr r1, [r3]
	adds r0, r1, r0
	lsls r4, 7
	adds r4, 0x4
	adds r1, r4
	str r5, [sp]
	str r6, [sp, 0x4]
	mov r2, r8
	str r2, [sp, 0x8]
	adds r2, r7, 0
	mov r3, r10
	bl sub_81D3094
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816753C

	thumb_func_start sub_8167608
sub_8167608: @ 8167608
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x28
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gUnknown_0203BCAC
	ldr r3, [r1]
	ldr r0, =0x00007b10
	mov r8, r0
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r7, r1, 0
	cmp r0, 0xFF
	bne _08167714
	add r5, sp, 0x18
	add r4, sp, 0x20
	adds r0, r5, 0
	mov r1, sp
	adds r2, r4, 0
	bl sub_81D31D0
	lsls r0, r6, 13
	movs r1, 0xC1
	lsls r1, 2
	adds r0, r1
	ldr r1, [r7]
	adds r0, r1, r0
	str r0, [sp, 0x18]
	lsls r0, r6, 7
	adds r0, 0x4
	adds r1, r0
	str r1, [sp, 0x20]
	adds r0, r4, 0
	bl LoadTaggedObjectPalette
	ldr r1, [r7]
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x00007b12
	adds r1, r2
	strh r0, [r1]
	adds r0, r5, 0
	bl LoadObjectPic
	ldr r1, [r7]
	ldr r3, =0x00007b14
	adds r1, r3
	strh r0, [r1]
	mov r0, sp
	movs r1, 0x26
	movs r2, 0x68
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r0, [r7]
	ldr r2, =0x00007b10
	adds r0, r2
	strb r1, [r0]
	cmp r1, 0x40
	bne _081676AC
	movs r0, 0x64
	bl FreeObjectTilesByTag
	movs r0, 0x64
	bl FreeObjectPaletteByTag
	ldr r0, [r7]
	add r0, r8
	movs r1, 0xFF
	strb r1, [r0]
	b _08167742
	.pool
_081676AC:
	ldr r0, [r7]
	add r0, r8
	strb r1, [r0]
	ldr r4, =gSprites
	ldr r2, [r7]
	mov r0, r8
	adds r3, r2, r0
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_8168168
	str r1, [r0]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x26]
	subs r1, 0x22
	strh r1, [r0, 0x26]
	ldr r3, =0x00007b18
	adds r1, r2, r3
	subs r3, 0x4
	adds r0, r2, r3
	ldrh r0, [r0]
	lsls r0, 5
	ldr r3, =0x06010000
	adds r0, r3
	str r0, [r1]
	ldr r0, =0x00007b12
	adds r2, r0
	ldrh r0, [r2]
	lsls r0, 4
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	strh r0, [r2]
	b _08167742
	.pool
_08167714:
	lsls r1, r6, 13
	movs r0, 0xC1
	lsls r0, 2
	adds r1, r0
	adds r1, r3, r1
	ldr r2, =0x00007b18
	adds r0, r3, r2
	ldr r2, [r0]
	ldr r0, =0x040000d4
	str r1, [r0]
	str r2, [r0, 0x4]
	ldr r1, =0x80000400
	str r1, [r0, 0x8]
	ldr r0, [r0, 0x8]
	lsls r0, r6, 7
	adds r0, 0x4
	adds r0, r3, r0
	ldr r2, =0x00007b12
	adds r1, r3, r2
	ldrh r1, [r1]
	movs r2, 0x20
	bl LoadPalette
_08167742:
	add sp, 0x28
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8167608

	thumb_func_start sub_8167760
sub_8167760: @ 8167760
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x60
	add r5, sp, 0x20
	add r4, sp, 0x38
	mov r0, sp
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_81D321C
	mov r0, sp
	bl LoadObjectPics
	adds r0, r4, 0
	bl LoadTaggedObjectPalettes
	movs r4, 0
	ldr r1, =gUnknown_0203BCAC
	ldr r0, [r1]
	ldr r2, =0x00008040
	adds r0, r2
	ldrb r0, [r0]
	subs r0, 0x1
	adds r6, r5, 0
	add r2, sp, 0x50
	mov r9, r2
	add r2, sp, 0x58
	mov r10, r2
	cmp r4, r0
	bge _0816781C
	adds r5, r1, 0
	ldr r7, =gSprites
	movs r0, 0x1C
	adds r0, r7
	mov r8, r0
_081677AC:
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 18
	movs r1, 0x80
	lsls r1, 12
	adds r2, r1
	asrs r2, 16
	adds r0, r6, 0
	movs r1, 0xE2
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x40
	beq _081677FC
	ldr r0, [r5]
	ldr r2, =0x00007b06
	adds r0, r2
	adds r0, r4
	strb r3, [r0]
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 2
	adds r1, r0, r7
	strh r4, [r1, 0x2E]
	add r0, r8
	ldr r1, =sub_8168180
	str r1, [r0]
	b _08167808
	.pool
_081677FC:
	ldr r0, [r5]
	ldr r1, =0x00007b06
	adds r0, r1
	adds r0, r4
	movs r1, 0xFF
	strb r1, [r0]
_08167808:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, [r5]
	ldr r2, =0x00008040
	adds r0, r2
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r4, r0
	blt _081677AC
_0816781C:
	movs r0, 0x67
	strh r0, [r6]
	cmp r4, 0x5
	bhi _0816788A
	ldr r5, =gUnknown_0203BCAC
	ldr r7, =gSprites
_08167828:
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 18
	movs r0, 0x80
	lsls r0, 12
	adds r2, r0
	asrs r2, 16
	adds r0, r6, 0
	movs r1, 0xE6
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x40
	beq _08167874
	ldr r0, [r5]
	ldr r1, =0x00007b06
	adds r0, r1
	adds r0, r4
	strb r3, [r0]
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r1, 0x3]
	movs r0, 0x3F
	ands r0, r2
	strb r0, [r1, 0x3]
	b _08167880
	.pool
_08167874:
	ldr r0, [r5]
	ldr r2, =0x00007b06
	adds r0, r2
	adds r0, r4
	movs r1, 0xFF
	strb r1, [r0]
_08167880:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x5
	bls _08167828
_0816788A:
	movs r0, 0x66
	strh r0, [r6]
	ldr r0, =sub_81681B4
	str r0, [r6, 0x14]
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 18
	movs r0, 0x80
	lsls r0, 12
	adds r2, r0
	asrs r2, 16
	adds r0, r6, 0
	movs r1, 0xDE
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x40
	beq _081678F4
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00007b06
	adds r0, r1
	adds r0, r4
	strb r3, [r0]
	ldr r0, =gSprites
	lsls r2, r3, 4
	adds r2, r3
	lsls r2, 2
	adds r2, r0
	ldrb r3, [r2, 0x1]
	movs r1, 0x3F
	adds r0, r1, 0
	ands r0, r3
	movs r3, 0x40
	orrs r0, r3
	strb r0, [r2, 0x1]
	ldrb r0, [r2, 0x3]
	ands r1, r0
	movs r0, 0x80
	orrs r1, r0
	strb r1, [r2, 0x3]
	b _08167902
	.pool
_081678F4:
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r2, =0x00007b06
	adds r0, r2
	adds r0, r4
	movs r1, 0xFF
	strb r1, [r0]
_08167902:
	mov r0, r9
	mov r1, r10
	bl sub_81D32B0
	mov r0, r9
	bl LoadObjectPic
	mov r0, r10
	bl LoadTaggedObjectPalette
	add sp, 0x60
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8167760

	thumb_func_start sub_8167930
sub_8167930: @ 8167930
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r2, =0x00008048
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0xB
	bls _08167944
	b _08167B78
_08167944:
	lsls r0, 2
	ldr r1, =_0816795C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0816795C:
	.4byte _0816798C
	.4byte _08167A04
	.4byte _08167A38
	.4byte _08167A48
	.4byte _08167A5C
	.4byte _08167A74
	.4byte _08167A9C
	.4byte _08167AB0
	.4byte _08167AD4
	.4byte _08167AEC
	.4byte _08167B1C
	.4byte _08167B38
_0816798C:
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
	movs r1, 0x88
	lsls r1, 6
	movs r0, 0x3
	movs r2, 0
	bl ChangeBgY
	ldr r1, =0x00007040
	movs r0, 0
	bl SetGpuReg
	movs r1, 0x91
	lsls r1, 2
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x0000040b
	movs r0, 0x52
	bl SetGpuReg
	b _08167B7E
	.pool
_08167A04:
	ldr r4, =gUnknown_0203BCA4
	movs r0, 0xD0
	lsls r0, 5
	bl Alloc
	str r0, [r4]
	ldr r5, =gUnknown_0203BCA0
	movs r4, 0xA0
	lsls r4, 3
	adds r0, r4, 0
	bl Alloc
	str r0, [r5]
	ldr r5, =gUnknown_0203BCA8
	adds r0, r4, 0
	bl Alloc
	str r0, [r5]
	b _08167B7E
	.pool
_08167A38:
	ldr r0, =gUnknown_085DFB60
	ldr r1, =gUnknown_0203BCA8
	b _08167AA0
	.pool
_08167A48:
	ldr r1, =gUnknown_085DFA80
	movs r0, 0x3
	movs r2, 0xE0
	movs r3, 0
	bl LoadBgTiles
	b _08167B7E
	.pool
_08167A5C:
	ldr r0, =gUnknown_0203BCA8
	ldr r1, [r0]
	movs r2, 0xA0
	lsls r2, 3
	movs r0, 0x3
	movs r3, 0
	bl LoadBgTilemap
	b _08167B7E
	.pool
_08167A74:
	ldr r0, =gUnknown_085DFA60
	movs r1, 0xD0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00007b0e
	adds r0, r1
	ldr r1, =0x0000ffb0
	strh r1, [r0]
	b _08167B7E
	.pool
_08167A9C:
	ldr r0, =gUnknown_08DCCF7C
	ldr r1, =gUnknown_0203BCA4
_08167AA0:
	ldr r1, [r1]
	bl LZ77UnCompVram
	b _08167B7E
	.pool
_08167AB0:
	ldr r0, =gUnknown_08DCD81C
	ldr r1, =gUnknown_0203BCA0
	ldr r1, [r1]
	bl LZ77UnCompVram
	ldr r0, =gUnknown_08DCCF5C
	movs r1, 0x20
	movs r2, 0x20
	bl LoadPalette
	b _08167B7E
	.pool
_08167AD4:
	ldr r0, =gUnknown_0203BCA4
	ldr r1, [r0]
	movs r2, 0xD0
	lsls r2, 5
	movs r3, 0xA0
	lsls r3, 2
	movs r0, 0x1
	bl LoadBgTiles
	b _08167B7E
	.pool
_08167AEC:
	ldr r0, =gUnknown_0203BCA0
	ldr r1, [r0]
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, =gUnknown_08DCDA30
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0x4
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0xD
	bl CopyToBgTilemapBufferRect
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	b _08167B7E
	.pool
_08167B1C:
	ldr r0, =gUnknown_085DFC0C
	ldr r1, =gUnknown_0203BCAC
	ldr r1, [r1]
	ldr r2, =0x00007304
	adds r1, r2
	bl LZ77UnCompVram
	b _08167B7E
	.pool
_08167B38:
	ldr r0, =gUnknown_0203BCAC
	ldr r1, [r0]
	ldr r0, =0x00007304
	adds r1, r0
	movs r2, 0xA0
	lsls r2, 3
	movs r0, 0x2
	movs r3, 0
	bl LoadBgTilemap
	ldr r0, =gUnknown_086231E8
	movs r1, 0x30
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_08623208
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0x2
	bl sub_81D21DC
	b _08167B7E
	.pool
_08167B78:
	movs r0, 0
	strb r0, [r1]
	b _08167B8E
_08167B7E:
	ldr r0, =gUnknown_0203BCAC
	ldr r1, [r0]
	ldr r2, =0x00008048
	adds r1, r2
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	movs r0, 0x1
_08167B8E:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8167930

	thumb_func_start sub_8167BA0
sub_8167BA0: @ 8167BA0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	ldr r7, =gUnknown_0203BCAC
	ldr r3, [r7]
	ldr r1, =0x00008041
	adds r0, r3, r1
	ldrb r1, [r0]
	ldr r2, =0x00008040
	adds r0, r3, r2
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	beq _08167C46
	lsls r2, r4, 6
	ldr r0, =0x00007b95
	adds r2, r0
	adds r2, r3, r2
	movs r0, 0x1
	str r0, [sp]
	movs r5, 0
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl Print
	ldr r0, [r7]
	ldr r1, =0x00008041
	adds r0, r1
	ldrb r0, [r0]
	bl sub_81672A4
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	bl GetNature
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, [r7]
	ldr r6, =0x0000804a
	adds r0, r6
	ldr r1, =gUnknown_085EBF8D
	bl StringCopy
	ldr r1, =gNatureNamePointers
	lsls r4, 2
	adds r4, r1
	ldr r1, [r4]
	bl StringCopy
	ldr r0, =gUnknown_085DFCC9
	str r0, [sp]
	str r5, [sp, 0x4]
	ldr r0, [r7]
	adds r0, r6
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x2
	movs r3, 0x1
	bl box_print
_08167C46:
	mov r2, r8
	cmp r2, 0
	beq _08167C84
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0x1
	movs r1, 0x3
	bl CopyWindowToVram
	b _08167C94
	.pool
_08167C84:
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
_08167C94:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8167BA0

	thumb_func_start sub_8167CA0
sub_8167CA0: @ 8167CA0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0
	beq _08167CC0
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00007fb5
	adds r0, r1
	b _08167CC8
	.pool
_08167CC0:
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r2, =0x00007fb4
	adds r0, r2
_08167CC8:
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r5, =gUnknown_0203BCAC
	ldr r2, [r5]
	ldr r3, =0x00007c58
	adds r0, r2, r3
	ldr r4, =0x00007fb3
	adds r1, r2, r4
	movs r3, 0
	ldrsb r3, [r1, r3]
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 2
	ldr r4, =0x00007c6c
	adds r1, r4
	adds r1, r2, r1
	lsls r3, r6, 2
	adds r3, r6
	lsls r3, 2
	adds r3, r4
	adds r2, r3
	bl sub_81D1F84
	ldr r4, [r5]
	ldr r1, =0x00008041
	adds r0, r4, r1
	ldrb r1, [r0]
	ldr r2, =0x00008040
	mov r12, r2
	adds r0, r4, r2
	ldrb r0, [r0]
	subs r0, 0x1
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	mov r8, r0
	cmp r7, 0
	beq _08167D98
	ldr r3, =0x00007fb4
	adds r0, r4, r3
	ldrb r1, [r0]
	subs r2, 0x8B
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, [r5]
	ldr r4, =0x00007fb3
	adds r1, r0, r4
	ldrb r1, [r1]
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r4
	strb r6, [r0]
	ldr r0, [r5]
	adds r2, r0, r2
	ldrb r1, [r2]
	ldr r2, =0x00007fb6
	adds r0, r2
	strb r1, [r0]
	ldr r1, [r5]
	adds r3, 0x8D
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _08167D58
	mov r4, r12
	adds r0, r1, r4
	ldrb r0, [r0]
_08167D58:
	subs r2, r0, 0x1
	ldr r0, =0x00008041
	adds r1, r0
	strb r2, [r1]
	ldr r1, =gUnknown_0203BCAC
	ldr r3, [r1]
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r6, r1, 0
	cmp r0, 0
	bne _08167D74
	ldr r1, =0x00008040
	adds r0, r3, r1
	ldrb r0, [r0]
_08167D74:
	subs r1, r0, 0x1
	b _08167E1E
	.pool
_08167D98:
	ldr r3, =0x00007fb5
	adds r0, r4, r3
	ldrb r1, [r0]
	ldr r2, =0x00007fb4
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, [r5]
	ldr r4, =0x00007fb3
	adds r1, r0, r4
	ldrb r1, [r1]
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r4
	strb r6, [r0]
	ldr r0, [r5]
	adds r2, r0, r2
	ldrb r1, [r2]
	ldr r2, =0x00007fb6
	adds r0, r2
	strb r1, [r0]
	ldr r2, [r5]
	adds r3, 0x8C
	adds r0, r2, r3
	ldrb r1, [r0]
	adds r4, 0x8D
	adds r0, r2, r4
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	bge _08167DEC
	adds r3, r1, 0x1
	b _08167DEE
	.pool
_08167DEC:
	movs r3, 0
_08167DEE:
	ldr r1, =0x00008041
	adds r0, r2, r1
	strb r3, [r0]
	ldr r2, =gUnknown_0203BCAC
	ldr r3, [r2]
	adds r1, r3, r1
	ldrb r1, [r1]
	ldr r4, =0x00008040
	adds r0, r3, r4
	ldrb r0, [r0]
	subs r0, 0x1
	adds r6, r2, 0
	cmp r1, r0
	bge _08167E1C
	adds r1, 0x1
	b _08167E1E
	.pool
_08167E1C:
	movs r1, 0
_08167E1E:
	ldr r2, =0x00007b4c
	adds r0, r3, r2
	strb r1, [r0]
	adds r5, r6, 0
	ldr r0, [r5]
	ldr r3, =0x00008041
	adds r1, r0, r3
	ldrb r2, [r1]
	ldr r4, =0x00008040
	adds r1, r0, r4
	ldrb r1, [r1]
	subs r1, 0x1
	eors r2, r1
	negs r1, r2
	orrs r1, r2
	lsrs r4, r1, 31
	ldr r1, =0x00007b1c
	adds r0, r1
	bl sub_81D3520
	mov r2, r8
	cmp r2, 0
	bne _08167E70
	ldr r0, [r5]
	ldr r3, =0x00008044
	adds r0, r3
	ldr r1, =sub_8167EA4
	b _08167E90
	.pool
_08167E70:
	cmp r4, 0
	bne _08167E88
	ldr r0, [r5]
	ldr r4, =0x00008044
	adds r0, r4
	ldr r1, =sub_8167FA4
	b _08167E90
	.pool
_08167E88:
	ldr r0, [r6]
	ldr r1, =0x00008044
	adds r0, r1
	ldr r1, =sub_8168048
_08167E90:
	str r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8167CA0

	thumb_func_start sub_8167EA4
sub_8167EA4: @ 8167EA4
	push {r4-r6,lr}
	ldr r4, =gUnknown_0203BCAC
	ldr r1, [r4]
	ldr r5, =0x00008048
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08167EE4
	cmp r0, 0x1
	bgt _08167EC8
	cmp r0, 0
	beq _08167ED2
	b _08167F9C
	.pool
_08167EC8:
	cmp r0, 0x2
	beq _08167F08
	cmp r0, 0x3
	beq _08167F48
	b _08167F9C
_08167ED2:
	ldr r2, =0x00007fb3
	adds r0, r1, r2
	ldrb r0, [r0]
	bl sub_8167608
	b _08167F2C
	.pool
_08167EE4:
	ldr r6, =0x00007fb3
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl sub_8167BA0
	ldr r1, [r4]
	ldr r0, =0x00008048
	adds r1, r0
	b _08167F30
	.pool
_08167F08:
	ldr r2, =0x00007c58
	adds r0, r1, r2
	ldr r6, =0x00007b0e
	adds r1, r6
	bl sub_81D3178
	lsls r0, 24
	cmp r0, 0
	bne _08167F9C
	ldr r1, [r4]
	ldr r2, =0x00007b4c
	adds r0, r1, r2
	ldrb r0, [r0]
	ldr r6, =0x00007fb6
	adds r1, r6
	ldrb r1, [r1]
	bl sub_816753C
_08167F2C:
	ldr r1, [r4]
	adds r1, r5
_08167F30:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08167F9C
	.pool
_08167F48:
	ldr r2, =0x00007b1c
	adds r0, r1, r2
	bl sub_81D3464
	ldr r3, [r4]
	ldr r6, =0x00008041
	adds r0, r3, r6
	ldrb r1, [r0]
	ldr r2, =0x00008040
	adds r0, r3, r2
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	beq _08167F82
	subs r6, 0x8E
	adds r0, r3, r6
	movs r1, 0
	ldrsb r1, [r0, r1]
	subs r2, 0x90
	adds r0, r3, r2
	adds r0, r1
	ldrb r2, [r0]
	ldr r6, =0x00007b1c
	adds r0, r3, r6
	subs r6, 0xC
	adds r1, r3, r6
	ldrb r1, [r1]
	bl sub_81D3480
_08167F82:
	ldr r0, [r4]
	adds r0, r5
	movs r1, 0
	strb r1, [r0]
	movs r0, 0
	b _08167F9E
	.pool
_08167F9C:
	movs r0, 0x1
_08167F9E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8167EA4

	thumb_func_start sub_8167FA4
sub_8167FA4: @ 8167FA4
	push {r4,r5,lr}
	ldr r4, =gUnknown_0203BCAC
	ldr r1, [r4]
	ldr r5, =0x00008048
	adds r2, r1, r5
	ldrb r0, [r2]
	cmp r0, 0x1
	beq _08167FF0
	cmp r0, 0x1
	bgt _08167FC8
	cmp r0, 0
	beq _08167FD2
	b _0816803E
	.pool
_08167FC8:
	cmp r0, 0x2
	beq _08168014
	cmp r0, 0x3
	beq _08168038
	b _0816803E
_08167FD2:
	ldr r2, =0x00007c58
	adds r0, r1, r2
	ldr r2, =0x00007b0e
	adds r1, r2
	bl sub_81D31A4
	lsls r0, 24
	cmp r0, 0
	bne _0816803E
	b _08168024
	.pool
_08167FF0:
	ldr r2, =0x00007fb3
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl sub_8167BA0
	ldr r1, [r4]
	ldr r0, =0x00008048
	adds r1, r0
	b _08168028
	.pool
_08168014:
	ldr r2, =0x00007b4c
	adds r0, r1, r2
	ldrb r0, [r0]
	ldr r2, =0x00007fb6
	adds r1, r2
	ldrb r1, [r1]
	bl sub_816753C
_08168024:
	ldr r1, [r4]
	adds r1, r5
_08168028:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0816803E
	.pool
_08168038:
	movs r0, 0
	strb r0, [r2]
	b _08168040
_0816803E:
	movs r0, 0x1
_08168040:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8167FA4

	thumb_func_start sub_8168048
sub_8168048: @ 8168048
	push {r4-r6,lr}
	ldr r4, =gUnknown_0203BCAC
	ldr r1, [r4]
	ldr r5, =0x00008048
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081680A8
	cmp r0, 0x1
	bgt _0816806C
	cmp r0, 0
	beq _08168076
	b _08168160
	.pool
_0816806C:
	cmp r0, 0x2
	beq _081680CC
	cmp r0, 0x3
	beq _0816810C
	b _08168160
_08168076:
	ldr r2, =0x00007c58
	adds r0, r1, r2
	bl sub_81D2074
	ldr r0, [r4]
	ldr r6, =0x00007b0e
	adds r0, r6
	bl sub_81D3150
	lsls r0, 24
	cmp r0, 0
	bne _08168160
	ldr r0, [r4]
	ldr r1, =0x00007fb3
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8167608
	b _081680F0
	.pool
_081680A8:
	ldr r2, =0x00007fb3
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl sub_8167BA0
	ldr r1, [r4]
	ldr r6, =0x00008048
	adds r1, r6
	b _081680F4
	.pool
_081680CC:
	ldr r2, =0x00007c58
	adds r0, r1, r2
	ldr r6, =0x00007b0e
	adds r1, r6
	bl sub_81D3178
	lsls r0, 24
	cmp r0, 0
	bne _08168160
	ldr r1, [r4]
	ldr r2, =0x00007b4c
	adds r0, r1, r2
	ldrb r0, [r0]
	ldr r6, =0x00007fb6
	adds r1, r6
	ldrb r1, [r1]
	bl sub_816753C
_081680F0:
	ldr r1, [r4]
	adds r1, r5
_081680F4:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08168160
	.pool
_0816810C:
	ldr r2, =0x00007b1c
	adds r0, r1, r2
	bl sub_81D3464
	ldr r3, [r4]
	ldr r6, =0x00008041
	adds r0, r3, r6
	ldrb r1, [r0]
	ldr r2, =0x00008040
	adds r0, r3, r2
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	beq _08168146
	subs r6, 0x8E
	adds r0, r3, r6
	movs r1, 0
	ldrsb r1, [r0, r1]
	subs r2, 0x90
	adds r0, r3, r2
	adds r0, r1
	ldrb r2, [r0]
	ldr r6, =0x00007b1c
	adds r0, r3, r6
	subs r6, 0xC
	adds r1, r3, r6
	ldrb r1, [r1]
	bl sub_81D3480
_08168146:
	ldr r0, [r4]
	adds r0, r5
	movs r1, 0
	strb r1, [r0]
	movs r0, 0
	b _08168162
	.pool
_08168160:
	movs r0, 0x1
_08168162:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8168048

	thumb_func_start sub_8168168
sub_8168168: @ 8168168
	ldr r1, =gUnknown_0203BCAC
	ldr r1, [r1]
	ldr r2, =0x00007b0e
	adds r1, r2
	ldrh r1, [r1]
	adds r1, 0x26
	strh r1, [r0, 0x20]
	bx lr
	.pool
	thumb_func_end sub_8168168

	thumb_func_start sub_8168180
sub_8168180: @ 8168180
	push {lr}
	adds r2, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r2, r0]
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r3, =0x00008041
	adds r0, r3
	ldrb r0, [r0]
	cmp r1, r0
	bne _081681A8
	adds r0, r2, 0
	movs r1, 0
	bl StartObjectImageAnim
	b _081681B0
	.pool
_081681A8:
	adds r0, r2, 0
	movs r1, 0x1
	bl StartObjectImageAnim
_081681B0:
	pop {r0}
	bx r0
	thumb_func_end sub_8168180

	thumb_func_start sub_81681B4
sub_81681B4: @ 81681B4
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r2, =0x00008041
	adds r1, r0, r2
	ldrb r1, [r1]
	subs r2, 0x1
	adds r0, r2
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	bne _081681DC
	movs r0, 0x65
	b _081681DE
	.pool
_081681DC:
	movs r0, 0x66
_081681DE:
	bl IndexOfSpritePaletteTag
	lsls r0, 4
	ldrb r2, [r4, 0x5]
	movs r1, 0xF
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0x5]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81681B4

	thumb_func_start sub_81681F4
sub_81681F4: @ 81681F4
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x30
	bl GetMonData
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r3, =0x00007fb3
	adds r1, r0, r3
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	subs r3, 0x3
	adds r0, r3
	adds r4, r0, r1
	cmp r2, 0xFF
	beq _0816823C
	adds r0, r2, 0
	movs r1, 0x1D
	bl __udivsi3
	b _0816823E
	.pool
_0816823C:
	movs r0, 0x9
_0816823E:
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81681F4

	thumb_func_start sub_8168248
sub_8168248: @ 8168248
	push {lr}
	sub sp, 0x10
	ldr r0, =gUnknown_085DFDB8
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	ldr r0, =gUnknown_08DCCBB8
	str r0, [sp]
	ldr r1, =0xffff0000
	ldr r0, [sp, 0x4]
	ands r0, r1
	movs r1, 0x80
	lsls r1, 4
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	adds r1, 0x1
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r0, sp
	bl LoadCompressedObjectPic
	add r0, sp, 0x8
	bl LoadTaggedObjectPalette
	add sp, 0x10
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8168248

	thumb_func_start sub_8168294
sub_8168294: @ 8168294
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00007b44
	adds r7, r0, r1
	ldr r0, =gUnknown_085DFDA0
	mov r10, r0
	movs r6, 0
	movs r1, 0x40
	mov r9, r1
	movs r0, 0x60
	negs r0, r0
	mov r8, r0
_081682B6:
	mov r5, r9
	muls r5, r6
	mov r0, r8
	adds r1, r0, r5
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x11
	lsls r2, r0, 16
	mov r0, r10
	asrs r2, 16
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _081682FE
	ldr r0, =gSprites
	lsls r4, r1, 4
	adds r4, r1
	lsls r4, 2
	adds r4, r0
	movs r1, 0x8
	strh r1, [r4, 0x2E]
	movs r0, 0x20
	orrs r5, r0
	strh r5, [r4, 0x30]
	strh r6, [r4, 0x32]
	lsls r1, r6, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartObjectImageAnim
	lsls r0, r6, 2
	adds r0, r7
	str r4, [r0]
_081682FE:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x1
	bls _081682B6
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8168294

	thumb_func_start sub_8168328
sub_8168328: @ 8168328
	push {r4,r5,lr}
	ldr r4, =gUnknown_0203BCAC
	ldr r0, [r4]
	ldr r5, =0x00008048
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0
	beq _08168348
	cmp r0, 0x1
	beq _08168360
	b _0816836C
	.pool
_08168348:
	bl sub_8168248
	ldr r1, [r4]
	ldr r0, =0x00008048
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	movs r0, 0x1
	b _0816836E
	.pool
_08168360:
	bl sub_8168294
	ldr r0, [r4]
	adds r0, r5
	movs r1, 0
	strb r1, [r0]
_0816836C:
	movs r0, 0
_0816836E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8168328

	thumb_func_start sub_8168374
sub_8168374: @ 8168374
	push {r4,lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x20]
	ldrh r1, [r2, 0x2E]
	adds r3, r0, r1
	strh r3, [r2, 0x20]
	lsls r0, 16
	asrs r4, r0, 16
	movs r0, 0x30
	ldrsh r1, [r2, r0]
	cmp r4, r1
	bgt _08168398
	lsls r0, r3, 16
	asrs r0, 16
	cmp r0, r1
	bge _081683A0
	cmp r4, r1
	blt _081683A8
_08168398:
	lsls r0, r3, 16
	asrs r0, 16
	cmp r0, r1
	bgt _081683A8
_081683A0:
	ldrh r0, [r2, 0x30]
	strh r0, [r2, 0x20]
	ldr r0, =DummyObjectCallback
	str r0, [r2, 0x1C]
_081683A8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8168374

	thumb_func_start nullsub_117
nullsub_117: @ 81683B4
	bx lr
	thumb_func_end nullsub_117

	thumb_func_start bx_goto_buffer_A_ch0_tbl3
bx_goto_buffer_A_ch0_tbl3: @ 81683B8
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_exec_buffer_A_ch0_tbl2
	str r1, [r0]
	ldr r2, =gBattleStruct
	ldr r0, [r2]
	adds r0, 0x94
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0x95
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0x96
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0x97
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end bx_goto_buffer_A_ch0_tbl3

	thumb_func_start bx_exec_buffer_A_ch0_tbl2
bx_exec_buffer_A_ch0_tbl2: @ 81683F4
	push {lr}
	ldr r2, =gBattleExecBuffer
	ldr r1, =gBitTable
	ldr r0, =gActiveBank
	ldrb r3, [r0]
	lsls r0, r3, 2
	adds r0, r1
	ldr r1, [r2]
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _08168440
	ldr r0, =gBattleBufferA
	lsls r1, r3, 9
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x38
	bhi _0816843C
	ldr r0, =gUnknown_085DFDC0
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	bl _call_via_r0
	b _08168440
	.pool
_0816843C:
	bl dp01_tbl5_exec_completed
_08168440:
	pop {r0}
	bx r0
	thumb_func_end bx_exec_buffer_A_ch0_tbl2

	thumb_func_start sub_8168444
sub_8168444: @ 8168444
	push {r4,r5,lr}
	ldr r1, =gBattleStruct
	ldr r0, [r1]
	adds r0, 0x94
	ldrb r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x5
	bls _08168456
	b _08168564
_08168456:
	lsls r0, 2
	ldr r1, =_08168468
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08168468:
	.4byte _08168480
	.4byte _08168492
	.4byte _081684B0
	.4byte _081684CE
	.4byte _08168508
	.4byte _08168540
_08168480:
	ldr r0, [r4]
	adds r0, 0x96
	movs r1, 0x40
	strb r1, [r0]
	ldr r1, [r4]
	adds r1, 0x94
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_08168492:
	ldr r1, [r4]
	adds r1, 0x96
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _08168564
	movs r0, 0x5
	bl audio_play
	movs r0, 0x1
	movs r1, 0
	b _081684E4
_081684B0:
	ldr r1, [r4]
	adds r1, 0x96
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _08168564
	movs r0, 0x5
	bl audio_play
	movs r0, 0x1
	movs r1, 0
	b _081684E4
_081684CE:
	ldr r1, [r4]
	adds r1, 0x96
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _08168564
	movs r0, 0x1
	movs r1, 0x9
_081684E4:
	movs r2, 0
	bl dp01_build_cmdbuf_x21_a_bb
	bl dp01_tbl5_exec_completed
	ldr r1, [r4]
	adds r1, 0x94
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, 0x95
	strb r5, [r0]
	ldr r0, [r4]
	adds r0, 0x96
	movs r1, 0x40
	strb r1, [r0]
	b _08168564
_08168508:
	ldr r1, [r4]
	adds r1, 0x96
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	cmp r0, 0
	bne _08168564
	movs r0, 0x5
	bl audio_play
	movs r0, 0
	bl sub_8059CF8
	movs r0, 0x1
	movs r1, 0
	bl sub_8059CB4
	ldr r0, [r4]
	adds r0, 0x96
	movs r1, 0x40
	strb r1, [r0]
	ldr r1, [r4]
	adds r1, 0x94
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08168564
_08168540:
	ldr r1, [r4]
	adds r1, 0x96
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	cmp r0, 0
	bne _08168564
	movs r0, 0x5
	bl audio_play
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl dp01_build_cmdbuf_x21_a_bb
	bl dp01_tbl5_exec_completed
_08168564:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8168444

	thumb_func_start sub_816856C
sub_816856C: @ 816856C
	push {lr}
	ldr r2, =gSprites
	ldr r1, =gBankSpriteIds
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _08168590
	bl dp01_tbl5_exec_completed
_08168590:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816856C

	thumb_func_start sub_81685A4
sub_81685A4: @ 81685A4
	push {lr}
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _081685B6
	bl dp01_tbl5_exec_completed
_081685B6:
	pop {r0}
	bx r0
	thumb_func_end sub_81685A4

	thumb_func_start bx_wait_t5
bx_wait_t5: @ 81685BC
	push {lr}
	ldr r0, =gDoingBattleAnim
	ldrb r0, [r0]
	cmp r0, 0
	bne _081685CA
	bl dp01_tbl5_exec_completed
_081685CA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_wait_t5

	thumb_func_start sub_81685D4
sub_81685D4: @ 81685D4
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081685FC
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8168610
	str r1, [r0]
	bl nullsub_35
	bl FreeAllWindowBuffers
	bl DoWallyTutorialBagMenu
_081685FC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81685D4

	thumb_func_start sub_8168610
sub_8168610: @ 8168610
	push {lr}
	ldr r0, =gMain
	ldr r1, [r0, 0x4]
	ldr r0, =sub_8038420
	cmp r1, r0
	bne _08168636
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08168636
	ldr r0, =gUnknown_0203CE7C
	ldrh r1, [r0]
	movs r0, 0x1
	bl dp01_build_cmdbuf_x23_aa_0
	bl dp01_tbl5_exec_completed
_08168636:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8168610

	thumb_func_start sub_816864C
sub_816864C: @ 816864C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, =gUnknown_020244D0
	ldr r0, [r4]
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	ldr r1, [r0, 0x4]
	lsls r3, r2, 1
	adds r0, r3, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r7, 0x88
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _08168684
	ldr r0, =gBattlePartyID
	adds r0, r3, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r1, r0
	adds r0, r2, 0
	bl sub_8172EF0
_08168684:
	ldr r1, [r4]
	ldrb r0, [r5]
	movs r6, 0x2
	adds r2, r6, 0
	eors r2, r0
	ldr r1, [r1, 0x4]
	lsls r3, r2, 1
	adds r0, r3, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _081686B6
	ldr r0, =gBattlePartyID
	adds r0, r3, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r1, r0
	adds r0, r2, 0
	bl sub_8172EF0
_081686B6:
	ldr r0, [r4]
	ldrb r2, [r5]
	ldr r3, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0]
	movs r4, 0x8
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _081686D2
	b _081687DC
_081686D2:
	adds r1, r2, 0
	eors r1, r6
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	bne _081687DC
	ldr r0, =gSprites
	mov r8, r0
	ldr r7, =gUnknown_03005D7C
	adds r0, r2, r7
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	mov r4, r8
	adds r4, 0x1C
	adds r0, r4
	ldr r3, [r0]
	ldr r0, =DummyObjectCallback
	cmp r3, r0
	bne _081687DC
	ldr r0, =gBankSpriteIds
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r0, [r0]
	cmp r0, r3
	bne _081687DC
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0816877A
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0816877A
	ldrb r0, [r5]
	eors r0, r6
	adds r0, r7
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	bl DestroySprite
	ldr r4, =gUnknown_03005D70
	ldrb r0, [r5]
	adds r1, r6, 0
	eors r1, r0
	adds r0, r1, r4
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gPlayerParty
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
	ldrb r0, [r5]
	eors r0, r6
	bl sub_8076918
	ldrb r0, [r5]
	eors r0, r6
	adds r0, r4
	ldrb r0, [r0]
	bl sub_80729D0
_0816877A:
	ldr r1, =gUnknown_03005D7C
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	ldr r5, =gUnknown_03005D70
	ldrb r1, [r4]
	adds r0, r1, r5
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gPlayerParty
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
	ldrb r0, [r4]
	bl sub_8076918
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	bl sub_80729D0
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r2, [r0, 0x8]
	ldrb r1, [r2, 0x9]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x9]
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8168818
	str r1, [r0]
_081687DC:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816864C

	thumb_func_start sub_8168818
sub_8168818: @ 8168818
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r4, 0
	ldr r2, =gSprites
	ldr r0, =gUnknown_03005D70
	ldr r1, =gActiveBank
	mov r8, r1
	ldrb r3, [r1]
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _08168842
	movs r4, 0x1
_08168842:
	cmp r4, 0
	beq _08168904
	ldr r7, =gUnknown_020244D0
	ldr r0, [r7]
	ldr r4, [r0, 0x4]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r2, r0, r4
	ldrb r1, [r2, 0x1]
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _08168904
	movs r6, 0x2
	adds r1, r6, 0
	eors r1, r3
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0, 0x1]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _08168904
	ldrb r1, [r2]
	movs r3, 0x7F
	adds r0, r3, 0
	ands r0, r1
	strb r0, [r2]
	ldr r0, [r7]
	mov r1, r8
	ldrb r2, [r1]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r4, 0x2
	negs r4, r4
	adds r0, r4, 0
	ands r0, r2
	strb r0, [r1, 0x1]
	ldr r2, [r7]
	mov r1, r8
	ldrb r0, [r1]
	adds r1, r6, 0
	eors r1, r0
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	ands r3, r1
	strb r3, [r0]
	ldr r2, [r7]
	mov r1, r8
	ldrb r0, [r1]
	adds r1, r6, 0
	eors r1, r0
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1]
	ands r4, r1
	strb r4, [r0, 0x1]
	ldr r4, =0x000027f9
	adds r0, r4, 0
	bl FreeObjectTilesByTag
	adds r0, r4, 0
	bl FreeObjectPaletteByTag
	ldr r0, =c3_0802FDF4
	movs r1, 0xA
	bl CreateTask
	ldr r2, =gBattlePartyID
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, 1
	adds r0, r2
	ldrh r2, [r0]
	movs r0, 0x64
	muls r0, r2
	ldr r2, =gPlayerParty
	adds r0, r2
	bl sub_805E990
	bl dp01_tbl5_exec_completed
_08168904:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8168818

	thumb_func_start sub_8168934
sub_8168934: @ 8168934
	push {r4-r6,lr}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	ldr r6, =gUnknown_03005D70
	adds r1, r0, r6
	ldrb r1, [r1]
	movs r2, 0
	movs r3, 0
	bl sub_8074AA0
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldrb r0, [r5]
	adds r0, r6
	ldrb r0, [r0]
	bl sub_80729D0
	lsls r4, 16
	asrs r1, r4, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0816897C
	ldrb r0, [r5]
	adds r0, r6
	ldrb r0, [r0]
	movs r2, 0
	bl heathbar_draw_hp
	b _08168996
	.pool
_0816897C:
	ldr r2, =gBattlePartyID
	ldrb r1, [r5]
	lsls r0, r1, 1
	adds r0, r2
	ldrh r2, [r0]
	movs r0, 0x64
	muls r0, r2
	ldr r2, =gPlayerParty
	adds r0, r2
	bl sub_805E990
	bl dp01_tbl5_exec_completed
_08168996:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8168934

	thumb_func_start bx_blink_t5
bx_blink_t5: @ 81689A4
	push {r4,lr}
	ldr r1, =gBankSpriteIds
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	ldr r2, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, r0, r2
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	cmp r0, 0x20
	bne _081689F0
	movs r3, 0
	movs r0, 0
	strh r0, [r4, 0x30]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	subs r0, 0x5
	ands r0, r1
	strb r0, [r2]
	ldr r0, =gDoingBattleAnim
	strb r3, [r0]
	bl dp01_tbl5_exec_completed
	b _08168A1A
	.pool
_081689F0:
	ldrh r0, [r4, 0x30]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _08168A14
	adds r3, r4, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_08168A14:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
_08168A1A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end bx_blink_t5

	thumb_func_start sub_8168A20
sub_8168A20: @ 8168A20
	push {r4-r6,lr}
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r6, =gActiveBank
	ldrb r2, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08168A74
	ldr r5, =gBankSpriteIds
	adds r0, r2, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl obj_free_rotscale_entry
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	ldr r1, =gUnknown_03005D70
	ldrb r0, [r6]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8072984
	bl dp01_tbl5_exec_completed
_08168A74:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8168A20

	thumb_func_start sub_8168A90
sub_8168A90: @ 8168A90
	push {lr}
	ldr r2, =gSprites
	ldr r1, =gBankSpriteIds
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _08168AB4
	bl dp01_tbl5_exec_completed
_08168AB4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8168A90

	thumb_func_start sub_8168AC8
sub_8168AC8: @ 8168AC8
	push {lr}
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _08168AEA
	bl dp01_tbl5_exec_completed
_08168AEA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8168AC8

	thumb_func_start dp01_tbl5_exec_completed
dp01_tbl5_exec_completed: @ 8168AF8
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gBattleBankFunc
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_exec_buffer_A_ch0_tbl2
	str r1, [r0]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08168B4C
	bl link_get_multiplayer_id
	mov r1, sp
	strb r0, [r1]
	movs r0, 0x2
	movs r1, 0x4
	mov r2, sp
	bl PrepareBufferDataTransferLink
	ldr r1, =gBattleBufferA
	ldrb r0, [r4]
	lsls r0, 9
	adds r0, r1
	movs r1, 0x38
	strb r1, [r0]
	b _08168B5E
	.pool
_08168B4C:
	ldr r2, =gBattleExecBuffer
	ldr r1, =gBitTable
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
_08168B5E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_tbl5_exec_completed

	thumb_func_start sub_8168B70
sub_8168B70: @ 8168B70
	push {lr}
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _08168B92
	bl dp01_tbl5_exec_completed
_08168B92:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8168B70

	thumb_func_start dp01t_00_5_getattr
dp01t_00_5_getattr: @ 8168BA0
	push {r4-r6,lr}
	sub sp, 0x100
	movs r6, 0
	ldr r1, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x2
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0
	bne _08168BD8
	ldr r0, =gBattlePartyID
	lsls r1, r2, 1
	adds r1, r0
	ldrb r0, [r1]
	mov r1, sp
	bl sub_8168C14
	adds r6, r0, 0
	b _08168BFA
	.pool
_08168BD8:
	ldrb r4, [r1]
	movs r5, 0
_08168BDC:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _08168BF2
	lsls r0, r5, 24
	lsrs r0, 24
	mov r2, sp
	adds r1, r2, r6
	bl sub_8168C14
	adds r6, r0
_08168BF2:
	lsrs r4, 1
	adds r5, 0x1
	cmp r5, 0x5
	ble _08168BDC
_08168BFA:
	lsls r1, r6, 16
	lsrs r1, 16
	movs r0, 0x1
	mov r2, sp
	bl dp01_build_cmdbuf_x1D_1D_numargs_varargs
	bl dp01_tbl5_exec_completed
	add sp, 0x100
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end dp01t_00_5_getattr

	thumb_func_start sub_8168C14
sub_8168C14: @ 8168C14
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x90
	adds r7, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	movs r6, 0
	ldr r2, =gBattleBufferA
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	lsls r0, 9
	adds r1, r2, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x3B
	bls _08168C3E
	bl _081693AA
_08168C3E:
	lsls r0, 2
	ldr r1, =_08168C54
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08168C54:
	.4byte _08168D44
	.4byte _08168F68
	.4byte _08168F78
	.4byte _08168F88
	.4byte _08168FF0
	.4byte _08168FF0
	.4byte _08168FF0
	.4byte _08168FF0
	.4byte _0816900C
	.4byte _08169048
	.4byte _08169048
	.4byte _08169048
	.4byte _08169048
	.4byte _081693AA
	.4byte _081693AA
	.4byte _081693AA
	.4byte _081693AA
	.4byte _08169064
	.4byte _08169074
	.4byte _081690A4
	.4byte _081690B4
	.4byte _081690C4
	.4byte _081690D4
	.4byte _081690E4
	.4byte _081690F4
	.4byte _08169104
	.4byte _08169114
	.4byte _08169124
	.4byte _08169134
	.4byte _08169144
	.4byte _08169154
	.4byte _08169164
	.4byte _081691B4
	.4byte _081691C4
	.4byte _081691D4
	.4byte _081691E4
	.4byte _081691F4
	.4byte _08169204
	.4byte _08169214
	.4byte _08169224
	.4byte _08169234
	.4byte _08169268
	.4byte _08169278
	.4byte _08169288
	.4byte _08169298
	.4byte _081692A8
	.4byte _081692B8
	.4byte _081692C8
	.4byte _081692D8
	.4byte _081692F8
	.4byte _08169308
	.4byte _08169318
	.4byte _08169328
	.4byte _08169338
	.4byte _08169348
	.4byte _08169358
	.4byte _08169368
	.4byte _08169378
	.4byte _08169388
	.4byte _08169398
_08168D44:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	mov r1, sp
	strh r0, [r1]
	adds r0, r4, 0
	movs r1, 0xC
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x2E]
	movs r6, 0
	add r0, sp, 0x24
	mov r9, r0
	movs r1, 0x3B
	add r1, sp
	mov r10, r1
	mov r2, sp
	adds r2, 0x2B
	str r2, [sp, 0x80]
	mov r0, sp
	adds r0, 0x2A
	str r0, [sp, 0x7C]
	mov r1, sp
	adds r1, 0x68
	str r1, [sp, 0x8C]
	adds r2, 0x5
	str r2, [sp, 0x84]
	adds r0, 0x12
	str r0, [sp, 0x88]
	mov r8, r4
	add r4, sp, 0xC
_08168D90:
	adds r1, r6, 0
	adds r1, 0xD
	mov r0, r8
	bl GetMonData
	strh r0, [r4]
	adds r1, r6, 0
	adds r1, 0x11
	mov r0, r8
	bl GetMonData
	mov r2, r9
	adds r1, r2, r6
	strb r0, [r1]
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0x3
	ble _08168D90
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x15
	bl GetMonData
	mov r1, r10
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x20
	bl GetMonData
	ldr r2, [sp, 0x80]
	strb r0, [r2]
	adds r0, r4, 0
	movs r1, 0x19
	bl GetMonData
	str r0, [sp, 0x44]
	adds r0, r4, 0
	movs r1, 0x27
	bl GetMonData
	mov r3, sp
	movs r5, 0x1F
	ands r0, r5
	ldrb r2, [r3, 0x14]
	movs r1, 0x20
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x14]
	adds r0, r4, 0
	movs r1, 0x28
	bl GetMonData
	mov r3, sp
	movs r6, 0x1F
	ands r0, r6
	lsls r0, 5
	ldrh r2, [r3, 0x14]
	ldr r1, =0xfffffc1f
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x14]
	adds r0, r4, 0
	movs r1, 0x29
	bl GetMonData
	mov r3, sp
	ands r0, r5
	lsls r0, 2
	ldrb r2, [r3, 0x15]
	movs r1, 0x7D
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x15]
	adds r0, r4, 0
	movs r1, 0x2A
	bl GetMonData
	movs r1, 0x1F
	ands r1, r0
	lsls r1, 15
	ldr r0, [sp, 0x14]
	ldr r2, =0xfff07fff
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x14]
	adds r0, r4, 0
	movs r1, 0x2B
	bl GetMonData
	mov r3, sp
	ands r0, r6
	lsls r0, 4
	ldrh r2, [r3, 0x16]
	ldr r1, =0xfffffe0f
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x16]
	adds r0, r4, 0
	movs r1, 0x2C
	bl GetMonData
	mov r3, sp
	ands r0, r5
	lsls r0, 1
	ldrb r2, [r3, 0x17]
	movs r1, 0x3F
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x17]
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	str r0, [sp, 0x48]
	adds r0, r4, 0
	movs r1, 0x37
	bl GetMonData
	str r0, [sp, 0x4C]
	adds r0, r4, 0
	movs r1, 0x38
	bl GetMonData
	ldr r1, [sp, 0x7C]
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x28]
	adds r0, r4, 0
	movs r1, 0x3A
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x2C]
	adds r0, r4, 0
	movs r1, 0x3B
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x2]
	adds r0, r4, 0
	movs r1, 0x3C
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x4]
	adds r0, r4, 0
	movs r1, 0x3D
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x6]
	adds r0, r4, 0
	movs r1, 0x3E
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x8]
	adds r0, r4, 0
	movs r1, 0x3F
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0xA]
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	mov r3, sp
	movs r1, 0x1
	ands r0, r1
	lsls r0, 6
	ldrb r2, [r3, 0x17]
	movs r1, 0x41
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x17]
	adds r0, r4, 0
	movs r1, 0x2E
	bl GetMonData
	mov r3, sp
	lsls r0, 7
	ldrb r2, [r3, 0x17]
	movs r1, 0x7F
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x17]
	adds r0, r4, 0
	movs r1, 0x1
	bl GetMonData
	str r0, [sp, 0x54]
	adds r0, r4, 0
	movs r1, 0x2
	ldr r2, [sp, 0x8C]
	bl GetMonData
	ldr r0, [sp, 0x84]
	ldr r1, [sp, 0x8C]
	bl StringCopy10
	adds r0, r4, 0
	movs r1, 0x7
	ldr r2, [sp, 0x88]
	bl GetMonData
	mov r2, sp
	movs r6, 0
_08168F48:
	adds r0, r7, r6
	adds r1, r2, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0x57
	bls _08168F48
	b _081693AA
	.pool
_08168F68:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	b _081692E2
	.pool
_08168F78:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xC
	b _081692E2
	.pool
_08168F88:
	movs r6, 0
	add r2, sp, 0x58
	mov r9, r2
	add r0, sp, 0x60
	mov r10, r0
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	mov r8, r9
_08168F9E:
	adds r1, r6, 0
	adds r1, 0xD
	adds r0, r4, 0
	bl GetMonData
	mov r1, r8
	strh r0, [r1]
	adds r1, r6, 0
	adds r1, 0x11
	adds r0, r4, 0
	bl GetMonData
	mov r2, r10
	adds r1, r2, r6
	strb r0, [r1]
	movs r0, 0x2
	add r8, r0
	adds r6, 0x1
	cmp r6, 0x3
	ble _08168F9E
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x15
	bl GetMonData
	mov r1, r9
	strb r0, [r1, 0xC]
	mov r2, r9
	movs r6, 0
_08168FDC:
	adds r0, r7, r6
	adds r1, r2, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0xF
	bls _08168FDC
	b _081693AA
	.pool
_08168FF0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldrb r1, [r3]
	lsls r1, 9
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	adds r1, 0x9
	b _081692E2
	.pool
_0816900C:
	movs r6, 0
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r2, =gPlayerParty
	mov r8, r2
_08169018:
	adds r1, r6, 0
	adds r1, 0x11
	mov r2, r8
	adds r0, r4, r2
	bl GetMonData
	adds r1, r7, r6
	strb r0, [r1]
	adds r6, 0x1
	cmp r6, 0x3
	ble _08169018
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x15
	bl GetMonData
	adds r1, r7, r6
	strb r0, [r1]
	adds r6, 0x1
	b _081693AA
	.pool
_08169048:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldrb r1, [r3]
	lsls r1, 9
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	adds r1, 0x8
	b _081693A2
	.pool
_08169064:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1
	b _0816907E
	.pool
_08169074:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x19
_0816907E:
	bl GetMonData
	adds r1, r0, 0
	strb r1, [r7]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	lsrs r0, 8
	strb r0, [r7, 0x1]
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	lsrs r0, 16
	strb r0, [r7, 0x2]
	movs r6, 0x3
	b _081693AA
	.pool
_081690A4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1A
	b _081693A2
	.pool
_081690B4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1B
	b _081693A2
	.pool
_081690C4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1C
	b _081693A2
	.pool
_081690D4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1D
	b _081693A2
	.pool
_081690E4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1E
	b _081693A2
	.pool
_081690F4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1F
	b _081693A2
	.pool
_08169104:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x20
	b _081693A2
	.pool
_08169114:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x22
	b _081693A2
	.pool
_08169124:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x23
	b _081693A2
	.pool
_08169134:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x24
	b _081693A2
	.pool
_08169144:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x25
	b _081693A2
	.pool
_08169154:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x26
	b _081693A2
	.pool
_08169164:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x27
	bl GetMonData
	strb r0, [r7]
	adds r0, r4, 0
	movs r1, 0x28
	bl GetMonData
	strb r0, [r7, 0x1]
	adds r0, r4, 0
	movs r1, 0x29
	bl GetMonData
	strb r0, [r7, 0x2]
	adds r0, r4, 0
	movs r1, 0x2A
	bl GetMonData
	strb r0, [r7, 0x3]
	adds r0, r4, 0
	movs r1, 0x2B
	bl GetMonData
	strb r0, [r7, 0x4]
	adds r0, r4, 0
	movs r1, 0x2C
	bl GetMonData
	strb r0, [r7, 0x5]
	movs r6, 0x6
	b _081693AA
	.pool
_081691B4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x27
	b _081693A2
	.pool
_081691C4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x28
	b _081693A2
	.pool
_081691D4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x29
	b _081693A2
	.pool
_081691E4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2A
	b _081693A2
	.pool
_081691F4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2B
	b _081693A2
	.pool
_08169204:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2C
	b _081693A2
	.pool
_08169214:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0
	b _0816923E
	.pool
_08169224:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x9
	b _081692E2
	.pool
_08169234:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x37
_0816923E:
	bl GetMonData
	adds r1, r0, 0
	strb r1, [r7]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	lsrs r0, 8
	strb r0, [r7, 0x1]
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	lsrs r0, 16
	strb r0, [r7, 0x2]
	lsrs r0, r1, 24
	strb r0, [r7, 0x3]
	movs r6, 0x4
	b _081693AA
	.pool
_08169268:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x38
	b _081693A2
	.pool
_08169278:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x39
	b _081692E2
	.pool
_08169288:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3A
	b _081692E2
	.pool
_08169298:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3B
	b _081692E2
	.pool
_081692A8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3C
	b _081692E2
	.pool
_081692B8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3D
	b _081692E2
	.pool
_081692C8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3E
	b _081692E2
	.pool
_081692D8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3F
_081692E2:
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	strb r0, [r7]
	lsrs r0, 8
	strb r0, [r7, 0x1]
	movs r6, 0x2
	b _081693AA
	.pool
_081692F8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x16
	b _081693A2
	.pool
_08169308:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x17
	b _081693A2
	.pool
_08169318:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x18
	b _081693A2
	.pool
_08169328:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x21
	b _081693A2
	.pool
_08169338:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2F
	b _081693A2
	.pool
_08169348:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x30
	b _081693A2
	.pool
_08169358:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x32
	b _081693A2
	.pool
_08169368:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x33
	b _081693A2
	.pool
_08169378:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x34
	b _081693A2
	.pool
_08169388:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x35
	b _081693A2
	.pool
_08169398:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x36
_081693A2:
	bl GetMonData
	strb r0, [r7]
	movs r6, 0x1
_081693AA:
	adds r0, r6, 0
	add sp, 0x90
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8168C14

	thumb_func_start sub_81693C0
sub_81693C0: @ 81693C0
	push {lr}
	bl sub_805A614
	pop {r0}
	bx r0
	thumb_func_end sub_81693C0

	thumb_func_start sub_81693CC
sub_81693CC: @ 81693CC
	push {r4,r5,lr}
	ldr r1, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x2
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0
	bne _081693FC
	ldr r0, =gBattlePartyID
	lsls r1, r2, 1
	adds r1, r0
	ldrb r0, [r1]
	bl sub_8169424
	b _0816941A
	.pool
_081693FC:
	ldrb r4, [r1]
	movs r5, 0
_08169400:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0816940E
	adds r0, r5, 0
	bl sub_8169424
_0816940E:
	lsrs r4, 1
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _08169400
_0816941A:
	bl dp01_tbl5_exec_completed
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81693CC

	thumb_func_start sub_8169424
sub_8169424: @ 8169424
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x34
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	ldr r2, =gUnknown_02023067
	adds r3, r0, r2
	adds r6, r3, 0
	subs r1, r2, 0x2
	adds r0, r1
	ldrb r0, [r0]
	adds r7, r2, 0
	cmp r0, 0x3B
	bls _08169450
	bl _08169DEA
_08169450:
	lsls r0, 2
	ldr r1, =_08169468
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08169468:
	.4byte _08169558
	.4byte _081696F0
	.4byte _08169710
	.4byte _08169730
	.4byte _08169788
	.4byte _08169788
	.4byte _08169788
	.4byte _08169788
	.4byte _081697B0
	.4byte _08169814
	.4byte _08169814
	.4byte _08169814
	.4byte _08169814
	.4byte _08169DEA
	.4byte _08169DEA
	.4byte _08169DEA
	.4byte _08169DEA
	.4byte _08169844
	.4byte _08169864
	.4byte _08169884
	.4byte _081698A4
	.4byte _081698C4
	.4byte _081698E4
	.4byte _08169904
	.4byte _08169924
	.4byte _08169944
	.4byte _08169964
	.4byte _08169984
	.4byte _081699A4
	.4byte _081699C4
	.4byte _081699E4
	.4byte _08169A04
	.4byte _08169A74
	.4byte _08169A94
	.4byte _08169AB4
	.4byte _08169AD4
	.4byte _08169AF4
	.4byte _08169B14
	.4byte _08169B34
	.4byte _08169B54
	.4byte _08169B74
	.4byte _08169B94
	.4byte _08169BB4
	.4byte _08169BD4
	.4byte _08169BF4
	.4byte _08169C14
	.4byte _08169C34
	.4byte _08169C54
	.4byte _08169C74
	.4byte _08169C94
	.4byte _08169CB4
	.4byte _08169CD4
	.4byte _08169CF4
	.4byte _08169D14
	.4byte _08169D34
	.4byte _08169D54
	.4byte _08169D74
	.4byte _08169D94
	.4byte _08169DB4
	.4byte _08169DD4
_08169558:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xB
	adds r2, r6, 0
	bl SetMonData
	adds r2, r6, 0
	adds r2, 0x2E
	adds r0, r4, 0
	movs r1, 0xC
	bl SetMonData
	movs r0, 0
	mov r8, r0
	movs r0, 0x3B
	adds r0, r6
	mov r10, r0
	adds r0, r6, 0
	adds r0, 0x2B
	str r0, [sp, 0x20]
	adds r0, 0x19
	str r0, [sp, 0x28]
	adds r0, 0x4
	str r0, [sp, 0x2C]
	adds r0, 0x4
	str r0, [sp, 0x30]
	subs r0, 0x22
	str r0, [sp, 0x1C]
	subs r0, 0x2
	str r0, [sp, 0x18]
	adds r0, 0x4
	str r0, [sp, 0x24]
	adds r0, r6, 0x2
	str r0, [sp, 0x4]
	adds r0, r6, 0x4
	str r0, [sp, 0x8]
	adds r0, r6, 0x6
	str r0, [sp, 0xC]
	adds r0, 0x2
	str r0, [sp, 0x10]
	adds r0, 0x2
	str r0, [sp, 0x14]
	mov r9, r4
	adds r7, r6, 0
	adds r7, 0x24
	adds r4, r6, 0
	adds r4, 0xC
_081695BE:
	mov r1, r8
	adds r1, 0xD
	mov r0, r9
	adds r2, r4, 0
	bl SetMonData
	mov r1, r8
	adds r1, 0x11
	mov r0, r9
	adds r2, r7, 0
	bl SetMonData
	adds r7, 0x1
	adds r4, 0x2
	movs r0, 0x1
	add r8, r0
	mov r0, r8
	cmp r0, 0x3
	ble _081695BE
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x15
	mov r2, r10
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x20
	ldr r2, [sp, 0x20]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x19
	ldr r2, [sp, 0x28]
	bl SetMonData
	ldrb r0, [r6, 0x14]
	lsls r0, 27
	lsrs r0, 27
	mov r1, sp
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x27
	mov r2, sp
	bl SetMonData
	mov r1, sp
	ldrh r0, [r6, 0x14]
	lsls r0, 22
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x28
	mov r2, sp
	bl SetMonData
	mov r1, sp
	ldrb r0, [r6, 0x15]
	lsls r0, 25
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x29
	mov r2, sp
	bl SetMonData
	mov r1, sp
	ldr r0, [r6, 0x14]
	lsls r0, 12
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2A
	mov r2, sp
	bl SetMonData
	mov r1, sp
	ldrh r0, [r6, 0x16]
	lsls r0, 23
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2B
	mov r2, sp
	bl SetMonData
	mov r1, sp
	ldrb r0, [r6, 0x17]
	lsls r0, 26
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2C
	mov r2, sp
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0
	ldr r2, [sp, 0x2C]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x37
	ldr r2, [sp, 0x30]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x38
	ldr r2, [sp, 0x1C]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x39
	ldr r2, [sp, 0x18]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x3A
	ldr r2, [sp, 0x24]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x3B
	ldr r2, [sp, 0x4]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x3C
	ldr r2, [sp, 0x8]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x3D
	ldr r2, [sp, 0xC]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x3E
	ldr r2, [sp, 0x10]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x3F
	ldr r2, [sp, 0x14]
	bl SetMonData
	b _08169DEA
	.pool
_081696F0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0xB
	bl SetMonData
	b _08169DEA
	.pool
_08169710:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0xC
	bl SetMonData
	b _08169DEA
	.pool
_08169730:
	movs r0, 0
	mov r8, r0
	movs r0, 0xC
	adds r0, r3
	mov r9, r0
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r7, r1, r0
	adds r6, r3, 0
	adds r6, 0x8
	adds r4, r3, 0
_0816974A:
	mov r1, r8
	adds r1, 0xD
	adds r0, r7, 0
	adds r2, r4, 0
	bl SetMonData
	mov r1, r8
	adds r1, 0x11
	adds r0, r7, 0
	adds r2, r6, 0
	bl SetMonData
	adds r6, 0x1
	adds r4, 0x2
	movs r0, 0x1
	add r8, r0
	mov r0, r8
	cmp r0, 0x3
	ble _0816974A
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x15
	mov r2, r9
	bl SetMonData
	b _08169DEA
	.pool
_08169788:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r3, =gBattleBufferA
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r1, r3, 0x1
	adds r1, r2, r1
	ldrb r1, [r1]
	adds r1, 0x9
	b _0816982C
	.pool
_081697B0:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	lsls r2, 9
	adds r2, r7
	adds r0, r4, 0
	movs r1, 0x11
	bl SetMonData
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x1
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x12
	bl SetMonData
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x2
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x13
	bl SetMonData
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x3
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x14
	bl SetMonData
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x4
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x15
	bl SetMonData
	b _08169DEA
	.pool
_08169814:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r3, =gBattleBufferA
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r1, r3, 0x1
	adds r1, r2, r1
	ldrb r1, [r1]
	adds r1, 0x8
_0816982C:
	adds r3, 0x3
	adds r2, r3
	bl SetMonData
	b _08169DEA
	.pool
_08169844:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x1
	bl SetMonData
	b _08169DEA
	.pool
_08169864:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x19
	bl SetMonData
	b _08169DEA
	.pool
_08169884:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x1A
	bl SetMonData
	b _08169DEA
	.pool
_081698A4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x1B
	bl SetMonData
	b _08169DEA
	.pool
_081698C4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x1C
	bl SetMonData
	b _08169DEA
	.pool
_081698E4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x1D
	bl SetMonData
	b _08169DEA
	.pool
_08169904:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x1E
	bl SetMonData
	b _08169DEA
	.pool
_08169924:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x1F
	bl SetMonData
	b _08169DEA
	.pool
_08169944:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x20
	bl SetMonData
	b _08169DEA
	.pool
_08169964:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x22
	bl SetMonData
	b _08169DEA
	.pool
_08169984:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x23
	bl SetMonData
	b _08169DEA
	.pool
_081699A4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x24
	bl SetMonData
	b _08169DEA
	.pool
_081699C4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x25
	bl SetMonData
	b _08169DEA
	.pool
_081699E4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x26
	bl SetMonData
	b _08169DEA
	.pool
_08169A04:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	lsls r2, 9
	adds r2, r7
	adds r0, r4, 0
	movs r1, 0x27
	bl SetMonData
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x1
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x28
	bl SetMonData
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x2
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x29
	bl SetMonData
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x3
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x2A
	bl SetMonData
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x4
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x2B
	bl SetMonData
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x5
	adds r2, r0
	adds r0, r4, 0
	b _08169B24
	.pool
_08169A74:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x27
	bl SetMonData
	b _08169DEA
	.pool
_08169A94:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x28
	bl SetMonData
	b _08169DEA
	.pool
_08169AB4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x29
	bl SetMonData
	b _08169DEA
	.pool
_08169AD4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x2A
	bl SetMonData
	b _08169DEA
	.pool
_08169AF4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x2B
	bl SetMonData
	b _08169DEA
	.pool
_08169B14:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
_08169B24:
	movs r1, 0x2C
	bl SetMonData
	b _08169DEA
	.pool
_08169B34:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0
	bl SetMonData
	b _08169DEA
	.pool
_08169B54:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x9
	bl SetMonData
	b _08169DEA
	.pool
_08169B74:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x37
	bl SetMonData
	b _08169DEA
	.pool
_08169B94:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x38
	bl SetMonData
	b _08169DEA
	.pool
_08169BB4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x39
	bl SetMonData
	b _08169DEA
	.pool
_08169BD4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x3A
	bl SetMonData
	b _08169DEA
	.pool
_08169BF4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x3B
	bl SetMonData
	b _08169DEA
	.pool
_08169C14:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x3C
	bl SetMonData
	b _08169DEA
	.pool
_08169C34:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x3D
	bl SetMonData
	b _08169DEA
	.pool
_08169C54:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x3E
	bl SetMonData
	b _08169DEA
	.pool
_08169C74:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x3F
	bl SetMonData
	b _08169DEA
	.pool
_08169C94:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x16
	bl SetMonData
	b _08169DEA
	.pool
_08169CB4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x17
	bl SetMonData
	b _08169DEA
	.pool
_08169CD4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x18
	bl SetMonData
	b _08169DEA
	.pool
_08169CF4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x21
	bl SetMonData
	b _08169DEA
	.pool
_08169D14:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x2F
	bl SetMonData
	b _08169DEA
	.pool
_08169D34:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x30
	bl SetMonData
	b _08169DEA
	.pool
_08169D54:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x32
	bl SetMonData
	b _08169DEA
	.pool
_08169D74:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x33
	bl SetMonData
	b _08169DEA
	.pool
_08169D94:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x34
	bl SetMonData
	b _08169DEA
	.pool
_08169DB4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x35
	bl SetMonData
	b _08169DEA
	.pool
_08169DD4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x36
	bl SetMonData
_08169DEA:
	ldr r2, =gBattlePartyID
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	lsls r0, r1, 1
	adds r0, r2
	ldrh r2, [r0]
	movs r0, 0x64
	muls r0, r2
	ldr r2, =gPlayerParty
	adds r0, r2
	bl sub_805E990
	add sp, 0x34
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8169424

	thumb_func_start sub_8169E20
sub_8169E20: @ 8169E20
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8169E20

	thumb_func_start sub_8169E2C
sub_8169E2C: @ 8169E2C
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8169E2C

	thumb_func_start sub_8169E38
sub_8169E38: @ 8169E38
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8169E38

	thumb_func_start sub_8169E44
sub_8169E44: @ 8169E44
	push {r4-r6,lr}
	ldr r0, =gBattleBufferA
	ldr r6, =gActiveBank
	ldrb r2, [r6]
	lsls r1, r2, 9
	adds r0, 0x1
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0
	bne _08169E80
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x1
	bl move_anim_start_t4
	ldr r0, =gBattleBankFunc
	ldrb r1, [r6]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_8168A20
	str r0, [r1]
	b _08169EB6
	.pool
_08169E80:
	ldr r5, =gBankSpriteIds
	adds r0, r2, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl obj_free_rotscale_entry
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	ldr r1, =gUnknown_03005D70
	ldrb r0, [r6]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8072984
	bl dp01_tbl5_exec_completed
_08169EB6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8169E44

	thumb_func_start sub_8169EC8
sub_8169EC8: @ 8169EC8
	push {r4-r6,lr}
	ldr r4, =gActiveBank
	ldrb r1, [r4]
	movs r0, 0x6
	bl sub_805DF84
	ldrb r0, [r4]
	bl GetBankIdentity
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0x6
	bl template_build_for_pokemon_or_trainer
	ldr r0, =gUnknown_0202499C
	ldr r1, =gUnknown_08305D2C
	ldrb r1, [r1, 0x18]
	movs r2, 0x8
	subs r2, r1
	lsls r2, 18
	movs r1, 0xA0
	lsls r1, 15
	adds r2, r1
	asrs r2, 16
	movs r1, 0x50
	movs r3, 0x1E
	bl CreateSprite
	ldr r6, =gBankSpriteIds
	ldrb r1, [r4]
	adds r1, r6
	strb r0, [r1]
	ldr r5, =gSprites
	ldrb r3, [r4]
	adds r0, r3, r6
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	lsls r3, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0xF0
	strh r1, [r0, 0x24]
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =0x0000fffe
	strh r1, [r0, 0x2E]
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r5, 0x1C
	adds r0, r5
	ldr r1, =sub_805D7AC
	str r1, [r0]
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_816856C
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8169EC8

	thumb_func_start dp01t_07_6_
dp01t_07_6_: @ 8169F94
	push {r4-r6,lr}
	ldr r4, =gActiveBank
	ldrb r1, [r4]
	movs r0, 0x6
	bl sub_805DF84
	ldrb r0, [r4]
	bl GetBankIdentity
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0x6
	bl template_build_for_pokemon_or_trainer
	ldr r0, =gUnknown_0202499C
	ldr r1, =gUnknown_08305D2C
	ldrb r1, [r1, 0x18]
	movs r2, 0x8
	subs r2, r1
	lsls r2, 18
	movs r1, 0xA0
	lsls r1, 15
	adds r2, r1
	asrs r2, 16
	movs r1, 0x50
	movs r3, 0x1E
	bl CreateSprite
	ldr r6, =gBankSpriteIds
	ldrb r1, [r4]
	adds r1, r6
	strb r0, [r1]
	ldr r5, =gSprites
	ldrb r3, [r4]
	adds r0, r3, r6
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	lsls r3, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =0x0000ffa0
	strh r1, [r0, 0x24]
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x2
	strh r1, [r0, 0x2E]
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r5, 0x1C
	adds r0, r5
	ldr r1, =sub_805D7AC
	str r1, [r0]
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8168A90
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_07_6_

	thumb_func_start sub_816A060
sub_816A060: @ 816A060
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A060

	thumb_func_start sub_816A06C
sub_816A06C: @ 816A06C
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A06C

	thumb_func_start sub_816A078
sub_816A078: @ 816A078
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A078

	thumb_func_start sub_816A084
sub_816A084: @ 816A084
	push {r4,r5,lr}
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0, 0x8]
	movs r0, 0x4
	strb r0, [r1, 0x8]
	ldr r1, =gDoingBattleAnim
	movs r0, 0x1
	strb r0, [r1]
	ldr r5, =gActiveBank
	ldrb r4, [r5]
	movs r0, 0x1
	bl GetBankByPlayerAI
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r4, 0
	movs r3, 0x4
	bl move_anim_start_t4
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_wait_t5
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816A084

	thumb_func_start sub_816A0D8
sub_816A0D8: @ 816A0D8
	push {r4,r5,lr}
	ldr r1, =gBattleBufferA
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r1, [r0]
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	strb r1, [r0, 0x8]
	ldr r1, =gDoingBattleAnim
	movs r0, 0x1
	strb r0, [r1]
	ldrb r4, [r5]
	movs r0, 0x1
	bl GetBankByPlayerAI
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r4, 0
	movs r3, 0x4
	bl move_anim_start_t4
	ldr r1, =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_wait_t5
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816A0D8

	thumb_func_start sub_816A138
sub_816A138: @ 816A138
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A138

	thumb_func_start sub_816A144
sub_816A144: @ 816A144
	push {r4-r6,lr}
	ldr r0, =gBattleBufferA
	mov r12, r0
	ldr r6, =gActiveBank
	ldrb r2, [r6]
	lsls r2, 9
	adds r0, 0x1
	adds r0, r2, r0
	ldrb r0, [r0]
	mov r1, r12
	adds r1, 0x2
	adds r1, r2, r1
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	ldr r5, =gUnknown_02038432
	mov r1, r12
	adds r1, 0x3
	adds r2, r1
	ldrb r1, [r2]
	strb r1, [r5]
	ldr r4, =gUnknown_02038408
	ldrb r2, [r6]
	lsls r2, 9
	mov r1, r12
	adds r1, 0x4
	adds r1, r2, r1
	ldrb r3, [r1]
	mov r1, r12
	adds r1, 0x5
	adds r2, r1
	ldrb r1, [r2]
	lsls r1, 8
	orrs r3, r1
	strh r3, [r4]
	ldr r4, =gUnknown_02038404
	ldrb r2, [r6]
	lsls r2, 9
	mov r1, r12
	adds r1, 0x6
	adds r1, r2, r1
	ldrb r3, [r1]
	mov r1, r12
	adds r1, 0x7
	adds r1, r2, r1
	ldrb r1, [r1]
	lsls r1, 8
	orrs r3, r1
	mov r1, r12
	adds r1, 0x8
	adds r1, r2, r1
	ldrb r1, [r1]
	lsls r1, 16
	orrs r3, r1
	mov r1, r12
	adds r1, 0x9
	adds r2, r1
	ldrb r1, [r2]
	lsls r1, 24
	orrs r3, r1
	str r3, [r4]
	ldr r3, =gUnknown_0203841A
	ldrb r1, [r6]
	lsls r1, 9
	mov r2, r12
	adds r2, 0xA
	adds r1, r2
	ldrb r1, [r1]
	strb r1, [r3]
	ldr r4, =gUnknown_0203841C
	ldrb r2, [r6]
	lsls r2, 9
	mov r1, r12
	adds r1, 0xC
	adds r1, r2, r1
	ldrb r3, [r1]
	mov r1, r12
	adds r1, 0xD
	adds r2, r1
	ldrb r1, [r2]
	lsls r1, 8
	orrs r3, r1
	strh r3, [r4]
	ldr r3, =gUnknown_02038400
	ldrb r2, [r6]
	lsls r2, 9
	mov r1, r12
	adds r1, 0x10
	adds r2, r1
	str r2, [r3]
	ldr r3, =gUnknown_020244BC
	ldrb r1, [r6]
	lsls r1, 2
	adds r1, r3
	ldr r2, [r2]
	str r2, [r1]
	ldrb r1, [r5]
	bl sub_805DB8C
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	beq _0816A23C
	bl dp01_tbl5_exec_completed
	b _0816A25A
	.pool
_0816A23C:
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strb r3, [r0, 0x4]
	ldr r1, =gBattleBankFunc
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_move_anim_5
	str r1, [r0]
_0816A25A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816A144

	thumb_func_start bx_move_anim_5
bx_move_anim_5: @ 816A26C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r2, =gBattleBufferA
	ldr r6, =gActiveBank
	ldrb r3, [r6]
	lsls r1, r3, 9
	adds r0, r2, 0x1
	mov r9, r0
	adds r0, r1, r0
	ldrb r4, [r0]
	adds r2, 0x2
	mov r8, r2
	add r1, r8
	ldrb r0, [r1]
	lsls r0, 8
	orrs r4, r0
	ldr r7, =gUnknown_020244D0
	ldr r5, [r7]
	ldr r1, [r5, 0x4]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r2, [r0, 0x4]
	cmp r2, 0x1
	beq _0816A2F6
	cmp r2, 0x1
	bgt _0816A2BC
	cmp r2, 0
	beq _0816A2C6
	b _0816A3AC
	.pool
_0816A2BC:
	cmp r2, 0x2
	beq _0816A320
	cmp r2, 0x3
	beq _0816A370
	b _0816A3AC
_0816A2C6:
	ldr r1, [r5]
	lsls r0, r3, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0816A2E2
	adds r0, r3, 0
	adds r1, r3, 0
	adds r2, r3, 0
	movs r3, 0x5
	bl move_anim_start_t4
_0816A2E2:
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0, 0x4]
	b _0816A3AC
_0816A2F6:
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0816A3AC
	movs r0, 0
	bl sub_805EB9C
	adds r0, r4, 0
	bl move_anim_start_t1
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x2
	strb r1, [r0, 0x4]
	b _0816A3AC
_0816A320:
	ldr r0, =gUnknown_020383F8
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gUnknown_020383FD
	ldrb r0, [r0]
	cmp r0, 0
	bne _0816A3AC
	movs r0, 0x1
	bl sub_805EB9C
	ldr r0, [r7]
	ldrb r2, [r6]
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0816A354
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x6
	bl move_anim_start_t4
_0816A354:
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x3
	strb r1, [r0, 0x4]
	b _0816A3AC
	.pool
_0816A370:
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0816A3AC
	bl sub_805E394
	ldrb r0, [r6]
	lsls r2, r0, 9
	mov r3, r9
	adds r1, r2, r3
	ldrb r1, [r1]
	add r2, r8
	ldrb r2, [r2]
	lsls r2, 8
	orrs r1, r2
	bl sub_805E94C
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strb r4, [r0, 0x4]
	bl dp01_tbl5_exec_completed
_0816A3AC:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end bx_move_anim_5

	thumb_func_start sub_816A3B8
sub_816A3B8: @ 816A3B8
	push {r4,lr}
	ldr r0, =gUnknown_02022E14
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E16
	strh r1, [r0]
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 9
	ldr r1, =gUnknown_02023066
	adds r0, r1
	ldrh r0, [r0]
	bl battle_pick_message
	ldr r0, =gUnknown_02022E2C
	movs r1, 0
	bl battle_show_message_maybe
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_81685A4
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816A3B8

	thumb_func_start dp01t_11_5_message_for_player_only
dp01t_11_5_message_for_player_only: @ 816A40C
	push {lr}
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0816A428
	bl sub_816A3B8
	b _0816A42C
	.pool
_0816A428:
	bl dp01_tbl5_exec_completed
_0816A42C:
	pop {r0}
	bx r0
	thumb_func_end dp01t_11_5_message_for_player_only

	thumb_func_start sub_816A430
sub_816A430: @ 816A430
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0816A456
	ldr r0, =gUnknown_02022E14
	strh r1, [r0]
	ldr r1, =gUnknown_02022E16
	movs r0, 0xA0
	strh r0, [r1]
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8168444
	str r1, [r0]
_0816A456:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816A430

	thumb_func_start dp01t_12_1_battle_menu
dp01t_12_1_battle_menu: @ 816A470
	push {r4,lr}
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_816A430
	str r1, [r0]
	ldr r0, =gUnknown_085CCA3A
	movs r1, 0x2
	bl battle_show_message_maybe
	movs r4, 0
_0816A48A:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8059CF8
	adds r4, 0x1
	cmp r4, 0x3
	ble _0816A48A
	ldr r1, =gUnknown_020244AC
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8059CB4
	ldr r0, =gUnknown_085CCA15
	bl get_battle_strings_
	ldr r0, =gUnknown_02022E2C
	movs r1, 0x1
	bl battle_show_message_maybe
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_12_1_battle_menu

	thumb_func_start sub_816A4D8
sub_816A4D8: @ 816A4D8
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A4D8

	thumb_func_start sub_816A4E4
sub_816A4E4: @ 816A4E4
	push {r4,lr}
	ldr r4, =gBattleStruct
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x95
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0816A522
	cmp r0, 0x1
	bgt _0816A504
	cmp r0, 0
	beq _0816A50A
	b _0816A574
	.pool
_0816A504:
	cmp r0, 0x2
	beq _0816A550
	b _0816A574
_0816A50A:
	bl sub_805C210
	ldr r1, [r4]
	adds r1, 0x95
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, 0x97
	movs r1, 0x50
	strb r1, [r0]
	b _0816A574
_0816A522:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0816A574
	ldr r0, =gUnknown_02022E14
	strh r1, [r0]
	ldr r1, =gUnknown_02022E16
	movs r2, 0xA0
	lsls r2, 1
	adds r0, r2, 0
	strh r0, [r1]
	ldr r1, [r4]
	adds r1, 0x95
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0816A574
	.pool
_0816A550:
	adds r1, 0x97
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	cmp r0, 0
	bne _0816A574
	movs r0, 0x5
	bl audio_play
	movs r2, 0x80
	lsls r2, 1
	movs r0, 0x1
	movs r1, 0xA
	bl dp01_build_cmdbuf_x21_a_bb
	bl dp01_tbl5_exec_completed
_0816A574:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_816A4E4

	thumb_func_start sub_816A57C
sub_816A57C: @ 816A57C
	push {lr}
	sub sp, 0x4
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gBattleBankFunc
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_81685D4
	str r1, [r0]
	ldr r1, =gUnknown_020244B8
	ldrb r0, [r2]
	strb r0, [r1]
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816A57C

	thumb_func_start sub_816A5BC
sub_816A5BC: @ 816A5BC
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A5BC

	thumb_func_start sub_816A5C8
sub_816A5C8: @ 816A5C8
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A5C8

	thumb_func_start sub_816A5D4
sub_816A5D4: @ 816A5D4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	movs r0, 0
	bl load_gfxc_health_bar
	ldr r3, =gBattleBufferA
	ldr r0, =gActiveBank
	mov r9, r0
	ldrb r4, [r0]
	lsls r2, r4, 9
	adds r0, r3, 0x2
	adds r0, r2, r0
	ldrb r1, [r0]
	adds r3, 0x3
	adds r2, r3
	ldrb r0, [r2]
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	asrs r7, r1, 16
	ldr r0, =0x00007fff
	cmp r7, r0
	beq _0816A664
	ldr r6, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r6
	ldrh r0, [r0]
	movs r5, 0x64
	muls r0, r5
	ldr r4, =gPlayerParty
	adds r0, r4
	movs r1, 0x3A
	bl GetMonData
	mov r8, r0
	mov r1, r9
	ldrb r0, [r1]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	muls r0, r5
	adds r0, r4
	movs r1, 0x39
	bl GetMonData
	adds r3, r0, 0
	mov r1, r9
	ldrb r0, [r1]
	ldr r1, =gUnknown_03005D70
	adds r1, r0, r1
	ldrb r1, [r1]
	str r7, [sp]
	mov r2, r8
	bl sub_807294C
	b _0816A69E
	.pool
_0816A664:
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3A
	bl GetMonData
	adds r2, r0, 0
	mov r1, r9
	ldrb r0, [r1]
	ldr r4, =gUnknown_03005D70
	adds r1, r0, r4
	ldrb r1, [r1]
	str r7, [sp]
	movs r3, 0
	bl sub_807294C
	mov r1, r9
	ldrb r0, [r1]
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0
	movs r2, 0
	bl heathbar_draw_hp
_0816A69E:
	ldr r1, =gBattleBankFunc
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8168934
	str r1, [r0]
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816A5D4

	thumb_func_start sub_816A6D4
sub_816A6D4: @ 816A6D4
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A6D4

	thumb_func_start sub_816A6E0
sub_816A6E0: @ 816A6E0
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A6E0

	thumb_func_start sub_816A6EC
sub_816A6EC: @ 816A6EC
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A6EC

	thumb_func_start sub_816A6F8
sub_816A6F8: @ 816A6F8
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A6F8

	thumb_func_start sub_816A704
sub_816A704: @ 816A704
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A704

	thumb_func_start sub_816A710
sub_816A710: @ 816A710
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A710

	thumb_func_start sub_816A71C
sub_816A71C: @ 816A71C
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A71C

	thumb_func_start sub_816A728
sub_816A728: @ 816A728
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A728

	thumb_func_start sub_816A734
sub_816A734: @ 816A734
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A734

	thumb_func_start sub_816A740
sub_816A740: @ 816A740
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A740

	thumb_func_start sub_816A74C
sub_816A74C: @ 816A74C
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A74C

	thumb_func_start sub_816A758
sub_816A758: @ 816A758
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A758

	thumb_func_start sub_816A764
sub_816A764: @ 816A764
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A764

	thumb_func_start sub_816A770
sub_816A770: @ 816A770
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A770

	thumb_func_start sub_816A77C
sub_816A77C: @ 816A77C
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A77C

	thumb_func_start sub_816A788
sub_816A788: @ 816A788
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A788

	thumb_func_start sub_816A794
sub_816A794: @ 816A794
	push {r4,lr}
	ldr r3, =gSprites
	ldr r2, =gBankSpriteIds
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	bge _0816A7C8
	bl dp01_tbl5_exec_completed
	b _0816A7F2
	.pool
_0816A7C8:
	ldr r1, =gDoingBattleAnim
	movs r0, 0x1
	strb r0, [r1]
	ldrb r0, [r4]
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0
	strh r1, [r0, 0x30]
	ldrb r0, [r4]
	bl sub_80769F4
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_blink_t5
	str r1, [r0]
_0816A7F2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816A794

	thumb_func_start sub_816A804
sub_816A804: @ 816A804
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816A804

	thumb_func_start sub_816A810
sub_816A810: @ 816A810
	push {lr}
	ldr r2, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	lsls r1, 9
	adds r0, r2, 0x1
	adds r0, r1, r0
	ldrb r0, [r0]
	adds r2, 0x2
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	bl audio_play
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816A810

	thumb_func_start sub_816A840
sub_816A840: @ 816A840
	push {r4,r5,lr}
	ldr r4, =gBattleBufferA
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r3, r0, 9
	adds r0, r4, 0x3
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, 0
	beq _0816A87C
	bl sub_805EA60
	ldrb r1, [r5]
	lsls r1, 9
	adds r0, r4, 0x1
	adds r0, r1, r0
	ldrb r0, [r0]
	adds r2, r4, 0x2
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	bl song_play_for_text
	b _0816A890
	.pool
_0816A87C:
	adds r0, r4, 0x1
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r1, r4, 0x2
	adds r1, r3, r1
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	bl fanfare_play
_0816A890:
	bl dp01_tbl5_exec_completed
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_816A840

	thumb_func_start sub_816A89C
sub_816A89C: @ 816A89C
	push {lr}
	ldr r1, =gBattlePartyID
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x19
	bl cry_related
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816A89C

	thumb_func_start dp01t_2E_5_battle_intro
dp01t_2E_5_battle_intro: @ 816A8D8
	push {lr}
	ldr r1, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	bl battle_intro_launch
	ldr r2, =gUnknown_020243FC
	ldrh r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r2]
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_2E_5_battle_intro

	thumb_func_start sub_816A90C
sub_816A90C: @ 816A90C
	push {r4-r7,lr}
	ldr r6, =gBankSpriteIds
	ldr r7, =gActiveBank
	ldrb r0, [r7]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r5, =gSprites
	adds r0, r5
	bl oamt_add_pos2_onto_pos1
	ldrb r0, [r7]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x32
	strh r1, [r0, 0x2E]
	ldrb r0, [r7]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =0x0000ffd8
	strh r1, [r0, 0x32]
	ldrb r0, [r7]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrh r1, [r0, 0x22]
	strh r1, [r0, 0x36]
	ldrb r0, [r7]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_80A6EEC
	str r1, [r0]
	ldrb r2, [r7]
	adds r0, r2, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x38]
	ldrb r0, [r7]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =sub_805CC00
	bl oamt_set_x3A_32
	ldrb r0, [r7]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x1
	bl StartObjectImageAnim
	ldr r0, =0x0000d6f8
	bl AllocObjectPalette
	adds r4, r0, 0
	lsls r4, 24
	ldr r0, =gTrainerBackPicPaletteTable
	ldr r0, [r0, 0x30]
	lsrs r4, 20
	movs r2, 0x80
	lsls r2, 1
	adds r1, r4, r2
	movs r2, 0x20
	bl LoadCompressedPalette
	ldrb r0, [r7]
	adds r0, r6
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r4
	strb r0, [r1, 0x5]
	ldr r0, =sub_816AC04
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r4
	ldrb r0, [r7]
	strh r0, [r1, 0x8]
	ldr r3, =gUnknown_020244D0
	ldr r0, [r3]
	ldrb r2, [r7]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0816AA24
	ldr r0, =gUnknown_020244B4
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	ldr r1, =sub_8073C30
	str r1, [r0]
_0816AA24:
	ldr r0, [r3]
	ldr r2, [r0, 0x8]
	ldrb r0, [r2, 0x9]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x9]
	ldr r1, =gBattleBankFunc
	ldrb r0, [r7]
	lsls r0, 2
	adds r0, r1
	ldr r1, =nullsub_21
	str r1, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816A90C

	thumb_func_start sub_816AA80
sub_816AA80: @ 816AA80
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0]
	lsls r0, r6, 2
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x2]
	ldr r0, =gBattlePartyID
	lsls r2, r6, 1
	adds r2, r0
	ldr r0, =gBattleBufferA
	lsls r1, r6, 9
	adds r0, 0x1
	adds r1, r0
	ldrb r0, [r1]
	strh r0, [r2]
	ldrh r1, [r2]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	mov r8, r0
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	ldr r0, =sub_805D714
	bl CreateInvisibleSpriteWithCallback
	ldr r1, =gUnknown_03005D7C
	mov r9, r1
	add r9, r6
	mov r1, r9
	strb r0, [r1]
	adds r0, r6, 0
	bl GetBankIdentity
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, r8
	bl sub_806A068
	ldr r0, =gUnknown_0202499C
	mov r10, r0
	adds r0, r6, 0
	movs r1, 0x2
	bl sub_80A5C6C
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r6, 0
	bl sub_80A6138
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	bl sub_80A82E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	mov r0, r10
	adds r1, r5, 0
	adds r2, r4, 0
	bl CreateSprite
	ldr r4, =gBankSpriteIds
	adds r4, r6, r4
	strb r0, [r4]
	ldr r5, =gSprites
	mov r0, r9
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r1, [r4]
	strh r1, [r0, 0x30]
	mov r0, r9
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r6, [r0, 0x32]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r6, [r0, 0x2E]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	mov r1, r8
	strh r1, [r0, 0x32]
	ldrb r0, [r4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	lsls r3, r6, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =gUnknown_020244E4
	adds r6, r1
	ldrb r1, [r6]
	bl StartObjectImageAnim
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =DummyObjectCallback
	str r1, [r0]
	movs r0, 0
	movs r1, 0xFF
	bl sub_80753E8
	mov r1, r9
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r5
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1, 0x2E]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816AA80

	thumb_func_start sub_816AC04
sub_816AC04: @ 816AC04
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r1, r0, r1
	ldrh r2, [r1, 0xA]
	movs r3, 0xA
	ldrsh r0, [r1, r3]
	cmp r0, 0x1E
	bgt _0816AC28
	adds r0, r2, 0x1
	strh r0, [r1, 0xA]
	b _0816AC5E
	.pool
_0816AC28:
	ldr r4, =gActiveBank
	ldrb r5, [r4]
	ldrh r0, [r1, 0x8]
	strb r0, [r4]
	ldr r0, =gBattleBufferA
	ldrb r1, [r4]
	lsls r2, r1, 9
	adds r0, 0x1
	adds r2, r0
	ldr r0, =gBattlePartyID
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r1]
	strb r0, [r2]
	ldrb r0, [r4]
	bl sub_816AA80
	ldr r1, =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_816864C
	str r1, [r0]
	strb r5, [r4]
	adds r0, r6, 0
	bl DestroyTask
_0816AC5E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816AC04

	thumb_func_start sub_816AC78
sub_816AC78: @ 816AC78
	push {r4,r5,lr}
	ldr r1, =gBattleBufferA
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0816ACA8
	adds r0, r2, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0816ACA8
	bl dp01_tbl5_exec_completed
	b _0816ACE6
	.pool
_0816ACA8:
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r5, =gActiveBank
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	ldrb r0, [r5]
	lsls r4, r0, 9
	ldr r3, =gUnknown_02023068
	adds r1, r4, r3
	subs r2, r3, 0x3
	adds r2, r4, r2
	ldrb r2, [r2]
	subs r3, 0x2
	adds r4, r3
	ldrb r3, [r4]
	bl sub_80735DC
	ldr r2, =gUnknown_020244B4
	ldrb r1, [r5]
	adds r1, r2
	strb r0, [r1]
	bl dp01_tbl5_exec_completed
_0816ACE6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816AC78

	thumb_func_start sub_816ACFC
sub_816ACFC: @ 816ACFC
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816ACFC

	thumb_func_start sub_816AD08
sub_816AD08: @ 816AD08
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816AD08

	thumb_func_start sub_816AD14
sub_816AD14: @ 816AD14
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816AD14

	thumb_func_start sub_816AD20
sub_816AD20: @ 816AD20
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r5, =gBattleBufferA
	ldr r6, =gActiveBank
	ldrb r2, [r6]
	lsls r1, r2, 9
	adds r0, r5, 0x1
	adds r0, r1, r0
	ldrb r3, [r0]
	adds r0, r5, 0x2
	adds r0, r1, r0
	ldrb r4, [r0]
	adds r5, 0x3
	adds r1, r5
	ldrb r0, [r1]
	lsls r0, 8
	orrs r4, r0
	str r4, [sp]
	adds r0, r2, 0
	adds r1, r2, 0
	bl move_anim_start_t3
	lsls r0, 24
	cmp r0, 0
	beq _0816AD60
	bl dp01_tbl5_exec_completed
	b _0816AD6C
	.pool
_0816AD60:
	ldr r0, =gBattleBankFunc
	ldrb r1, [r6]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_8168AC8
	str r0, [r1]
_0816AD6C:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816AD20

	thumb_func_start sub_816AD7C
sub_816AD7C: @ 816AD7C
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816AD7C

	thumb_func_start sub_816AD88
sub_816AD88: @ 816AD88
	push {lr}
	bl dp01_tbl5_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_816AD88

	thumb_func_start sub_816AD94
sub_816AD94: @ 816AD94
	push {r4,lr}
	ldr r2, =gBattleOutcome
	ldr r1, =gBattleBufferA
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	movs r0, 0x5
	bl sub_80A2F50
	movs r0, 0x3
	bl BeginFastPaletteFade
	bl dp01_tbl5_exec_completed
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x6
	ands r0, r1
	cmp r0, 0x2
	bne _0816ADD0
	ldr r0, =gBattleBankFunc
	ldrb r1, [r4]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_80587B0
	str r0, [r1]
_0816ADD0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816AD94

	thumb_func_start nullsub_118
nullsub_118: @ 816ADF0
	bx lr
	thumb_func_end nullsub_118

	.align 2, 0 @ Don't pad with nop.
