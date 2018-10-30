	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8108EC8
sub_8108EC8: @ 8108EC8
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0]
	strh r0, [r4, 0x2E]
	movs r0, 0x3C
	strh r0, [r4, 0x30]
	movs r0, 0x9
	strh r0, [r4, 0x32]
	movs r0, 0x1E
	strh r0, [r4, 0x34]
	movs r0, 0xFE
	lsls r0, 8
	strh r0, [r4, 0x36]
	ldr r1, =DestroyAnimSprite
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r1, =sub_80A634C
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8108EC8

	thumb_func_start sub_8108F08
sub_8108F08: @ 8108F08
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	movs r0, 0
	ldrsh r1, [r5, r0]
	adds r0, r4, 0
	bl sub_80A6864
	ldrh r0, [r5, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldrh r0, [r5, 0x8]
	strh r0, [r4, 0x2E]
	ldrh r0, [r5, 0x4]
	strh r0, [r4, 0x30]
	ldrh r0, [r5, 0x6]
	strh r0, [r4, 0x32]
	ldr r0, =sub_80A656C
	str r0, [r4, 0x1C]
	ldr r1, =DestroyAnimSprite
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8108F08

	thumb_func_start sub_8108F4C
sub_8108F4C: @ 8108F4C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6838
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _08108F88
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r4, 0x20]
	ldrh r1, [r2]
	subs r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r2, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldrh r0, [r2, 0x8]
	negs r0, r0
	strh r0, [r4, 0x32]
	adds r1, r2, 0
	b _08108F9E
	.pool
_08108F88:
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	ldrh r0, [r1, 0x2]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	ldrh r0, [r1, 0x8]
	strh r0, [r4, 0x32]
_08108F9E:
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x30]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x36]
	ldrh r0, [r1, 0xA]
	strh r0, [r4, 0x34]
	ldr r0, =sub_8109028
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8108F4C

	thumb_func_start sub_8108FBC
sub_8108FBC: @ 8108FBC
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _08108FF0
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r4, 0x20]
	ldrh r1, [r2]
	subs r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r2, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldrh r0, [r2, 0x8]
	strh r0, [r4, 0x32]
	adds r1, r2, 0
	b _08109008
	.pool
_08108FF0:
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	ldrh r0, [r1, 0x2]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	ldrh r0, [r1, 0x8]
	negs r0, r0
	strh r0, [r4, 0x32]
_08109008:
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x30]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x36]
	ldrh r0, [r1, 0xA]
	strh r0, [r4, 0x34]
	ldr r0, =sub_8109028
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8108FBC

	thumb_func_start sub_8109028
sub_8109028: @ 8109028
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x36
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bge _0810904E
	ldrh r0, [r2, 0x32]
	ldrh r1, [r2, 0x24]
	adds r0, r1
	strh r0, [r2, 0x24]
	ldrh r0, [r2, 0x34]
	ldrh r3, [r2, 0x26]
	adds r0, r3
	strh r0, [r2, 0x26]
_0810904E:
	movs r0, 0x2E
	ldrsh r1, [r2, r0]
	movs r3, 0x30
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bne _08109060
	adds r0, r2, 0
	bl move_anim_8074EE0
_08109060:
	pop {r0}
	bx r0
	thumb_func_end sub_8109028

	thumb_func_start sub_8109064
sub_8109064: @ 8109064
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6838
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _08109090
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r4, 0x20]
	ldrh r2, [r0]
	subs r1, r2
	strh r1, [r4, 0x20]
	b _081090A2
	.pool
_08109090:
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0]
	ldrh r2, [r4, 0x20]
	adds r1, r2
	strh r1, [r4, 0x20]
	adds r2, r4, 0
	adds r2, 0x43
	movs r1, 0x8
	strb r1, [r2]
_081090A2:
	adds r2, r0, 0
	ldrh r0, [r2, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	movs r1, 0
	strh r0, [r4, 0x22]
	ldrh r0, [r2, 0x4]
	strh r0, [r4, 0x2E]
	ldrh r0, [r2, 0x6]
	strh r0, [r4, 0x30]
	ldrh r0, [r2, 0x8]
	strh r0, [r4, 0x32]
	ldrh r0, [r2, 0xA]
	strh r0, [r4, 0x34]
	ldrh r0, [r2, 0xC]
	strh r0, [r4, 0x36]
	strh r1, [r4, 0x38]
	ldr r0, =sub_81090D8
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8109064

	thumb_func_start sub_81090D8
sub_81090D8: @ 81090D8
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _08109160
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	ldr r0, =0x00002710
	cmp r1, r0
	ble _081090F6
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x1
	strb r0, [r1]
_081090F6:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, 0x38]
	lsls r1, 16
	asrs r1, 24
	ldrh r2, [r4, 0x30]
	adds r1, r2
	lsls r1, 16
	asrs r1, 16
	bl Sin
	strh r0, [r4, 0x24]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, 0x38]
	lsls r1, 16
	asrs r1, 24
	ldrh r2, [r4, 0x30]
	adds r1, r2
	lsls r1, 16
	asrs r1, 16
	bl Cos
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	ldrh r2, [r4, 0x2E]
	adds r1, r0, r2
	strh r1, [r4, 0x2E]
	ldrh r0, [r4, 0x36]
	ldrh r2, [r4, 0x38]
	adds r0, r2
	strh r0, [r4, 0x38]
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _0810914C
	ldr r2, =0xffffff00
	b _08109154
	.pool
_0810914C:
	cmp r0, 0
	bge _08109158
	movs r2, 0x80
	lsls r2, 1
_08109154:
	adds r0, r1, r2
	strh r0, [r4, 0x2E]
_08109158:
	ldrh r0, [r4, 0x34]
	subs r0, 0x1
	strh r0, [r4, 0x34]
	b _08109166
_08109160:
	adds r0, r4, 0
	bl move_anim_8074EE0
_08109166:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81090D8

	thumb_func_start sub_810916C
sub_810916C: @ 810916C
	push {lr}
	movs r1, 0
	strh r1, [r0, 0x20]
	strh r1, [r0, 0x22]
	movs r1, 0x3C
	strh r1, [r0, 0x2E]
	movs r1, 0x8C
	strh r1, [r0, 0x32]
	movs r1, 0x50
	strh r1, [r0, 0x36]
	ldr r1, =sub_80A6EEC
	str r1, [r0, 0x1C]
	ldr r1, =DestroyAnimSprite
	bl StoreSpriteCallbackInData6
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810916C

	thumb_func_start sub_8109198
sub_8109198: @ 8109198
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r5, =gBattleAnimAttacker
	ldrb r0, [r5]
	bl GetBattlerSide
	adds r4, r0, 0
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bne _081091DE
	movs r0, 0x2
	bl GetBattlerAtPosition
	ldrb r1, [r5]
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	beq _081091D6
	movs r0, 0x3
	bl GetBattlerAtPosition
	ldrb r1, [r5]
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	bne _081091DE
_081091D6:
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	negs r0, r0
	strh r0, [r1, 0x4]
_081091DE:
	ldr r1, =sub_80A7938
	str r1, [r6, 0x1C]
	adds r0, r6, 0
	bl _call_via_r1
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8109198

	thumb_func_start sub_8109200
sub_8109200: @ 8109200
	ldr r2, =gBattleAnimArgs
	ldrh r1, [r2]
	negs r1, r1
	strh r1, [r2]
	ldrh r1, [r2, 0x4]
	negs r1, r1
	strh r1, [r2, 0x4]
	ldr r1, =sub_80A7938
	str r1, [r0, 0x1C]
	bx lr
	.pool
	thumb_func_end sub_8109200

	thumb_func_start sub_810921C
sub_810921C: @ 810921C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	movs r1, 0
	strh r0, [r4, 0x3C]
	strh r1, [r4, 0x2E]
	ldr r0, =sub_8109244
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810921C

	thumb_func_start sub_8109244
sub_8109244: @ 8109244
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_8109338
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x12
	bne _0810928E
	movs r0, 0x19
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x30]
	ldr r4, =gBattleAnimTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x22]
	strh r0, [r5, 0x34]
	ldrb r0, [r4]
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x36]
	adds r0, r5, 0
	bl InitAnimLinearTranslation
	ldr r0, =sub_810929C
	str r0, [r5, 0x1C]
_0810928E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8109244

	thumb_func_start sub_810929C
sub_810929C: @ 810929C
	push {r4-r6,lr}
	adds r6, r0, 0
	bl TranslateAnimLinear
	lsls r0, 24
	cmp r0, 0
	beq _081092E4
	movs r4, 0
	strh r4, [r6, 0x2E]
	ldr r5, =gBattleAnimTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x20]
	ldrb r0, [r5]
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x22]
	strh r4, [r6, 0x26]
	strh r4, [r6, 0x24]
	ldr r1, =sub_8109314
	str r1, [r6, 0x1C]
	adds r0, r6, 0
	bl _call_via_r1
	b _0810930E
	.pool
_081092E4:
	movs r1, 0x3C
	ldrsh r0, [r6, r1]
	movs r1, 0x1C
	bl Sin
	ldrh r1, [r6, 0x24]
	adds r0, r1
	strh r0, [r6, 0x24]
	movs r1, 0x3C
	ldrsh r0, [r6, r1]
	movs r1, 0x1C
	bl Cos
	ldrh r1, [r6, 0x26]
	adds r0, r1
	strh r0, [r6, 0x26]
	ldrh r0, [r6, 0x3C]
	adds r0, 0x14
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r6, 0x3C]
_0810930E:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_810929C

	thumb_func_start sub_8109314
sub_8109314: @ 8109314
	push {r4,lr}
	adds r4, r0, 0
	bl sub_8109338
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1F
	bne _08109330
	adds r0, r4, 0
	bl DestroyAnimSprite
_08109330:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8109314

	thumb_func_start sub_8109338
sub_8109338: @ 8109338
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x1C
	bl Sin
	strh r0, [r4, 0x24]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x1C
	bl Cos
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x14
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x3C]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8109338

	thumb_func_start sub_8109364
sub_8109364: @ 8109364
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	ldrh r0, [r1, 0x2]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x2E]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x30]
	ldrh r0, [r1, 0x8]
	strh r0, [r4, 0x32]
	ldr r1, =DestroyAnimSprite
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A653C
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8109364

	thumb_func_start sub_81093A4
sub_81093A4: @ 81093A4
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x30]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x2E]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_80A64B0
	str r0, [r4, 0x1C]
	ldr r1, =sub_81093E4
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81093A4

	thumb_func_start sub_81093E4
sub_81093E4: @ 81093E4
	push {lr}
	adds r3, r0, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r3]
	ldrh r1, [r0, 0x30]
	movs r2, 0
	strh r1, [r0, 0x2E]
	strh r2, [r0, 0x30]
	ldr r1, =sub_810940C
	str r1, [r0, 0x1C]
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81093E4

	thumb_func_start sub_810940C
sub_810940C: @ 810940C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, 0x32]
	lsls r1, 16
	asrs r1, 24
	bl Sin
	strh r0, [r4, 0x24]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, 0x32]
	lsls r1, 16
	asrs r1, 24
	bl Cos
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	adds r0, 0xA
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x32]
	adds r0, 0xD0
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _08109458
	adds r0, r4, 0
	bl DestroyAnimSprite
_08109458:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810940C

	thumb_func_start sub_8109460
sub_8109460: @ 8109460
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	movs r0, 0
	bl GetAnimBattlerSpriteId
	lsls r0, 24
	lsrs r0, 24
	movs r5, 0
	strh r0, [r4, 0x26]
	strh r5, [r4, 0x8]
	strh r5, [r4, 0xA]
	strh r5, [r4, 0xC]
	strh r5, [r4, 0xE]
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x22]
	strh r0, [r4, 0x10]
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x12]
	strh r5, [r4, 0x14]
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_80A7270
	ldr r0, =sub_81094D0
	str r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8109460

	thumb_func_start sub_81094D0
sub_81094D0: @ 81094D0
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x6
	bls _081094EC
	b _081097AA
_081094EC:
	lsls r0, 2
	ldr r1, =_08109500
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08109500:
	.4byte _0810951C
	.4byte _08109542
	.4byte _081095F4
	.4byte _08109654
	.4byte _08109672
	.4byte _08109748
	.4byte _0810979C
_0810951C:
	ldrh r1, [r4, 0x26]
	lsls r1, 24
	lsrs r1, 24
	movs r3, 0x80
	lsls r3, 1
	movs r0, 0xE0
	str r0, [sp]
	movs r0, 0x80
	lsls r0, 2
	str r0, [sp, 0x4]
	movs r0, 0x20
	str r0, [sp, 0x8]
	adds r0, r4, 0
	adds r2, r3, 0
	bl sub_80A805C
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_08109542:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0810958A
	movs r0, 0
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08109578
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x3
	b _08109588
	.pool
_08109578:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000fffd
_08109588:
	strh r1, [r0, 0x24]
_0810958A:
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _081095B8
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _081095B8
	movs r0, 0
	strh r0, [r4, 0xE]
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x22]
	adds r1, 0x1
	strh r1, [r0, 0x22]
_081095B8:
	adds r0, r4, 0
	bl sub_80A80C8
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _081095C8
	b _081097AA
_081095C8:
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A7E6C
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r5, [r0, 0x24]
	strh r5, [r4, 0xA]
	strh r5, [r4, 0xC]
	strh r5, [r4, 0xE]
	b _08109790
	.pool
_081095F4:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bgt _08109604
	b _081097AA
_08109604:
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0810962E
	ldrh r1, [r4, 0x26]
	lsls r1, 24
	lsrs r1, 24
	movs r3, 0x80
	lsls r3, 2
	movs r0, 0xC0
	lsls r0, 1
	str r0, [sp]
	movs r0, 0xF0
	str r0, [sp, 0x4]
	movs r0, 0x6
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r2, 0xE0
	bl sub_80A805C
	b _0810964E
_0810962E:
	ldrh r1, [r4, 0x26]
	lsls r1, 24
	lsrs r1, 24
	movs r3, 0x80
	lsls r3, 2
	movs r0, 0xC0
	lsls r0, 1
	str r0, [sp]
	movs r0, 0xC0
	str r0, [sp, 0x4]
	movs r0, 0x6
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r2, 0xE0
	bl sub_80A805C
_0810964E:
	movs r0, 0
	strh r0, [r4, 0xA]
	b _08109790
_08109654:
	adds r0, r4, 0
	bl sub_80A80C8
	lsls r0, 24
	cmp r0, 0
	beq _08109662
	b _081097AA
_08109662:
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	adds r1, r5, 0
	movs r2, 0x6
	bl sub_81097B4
	b _08109790
_08109672:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _081096C0
	movs r0, 0
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081096AC
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x26]
	adds r1, 0x3
	b _081096BE
	.pool
_081096AC:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x26]
	subs r1, 0x3
_081096BE:
	strh r1, [r0, 0x26]
_081096C0:
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x18
	ble _081097AA
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _081096FC
	ldrh r1, [r4, 0x26]
	lsls r1, 24
	lsrs r1, 24
	movs r2, 0xC0
	lsls r2, 1
	movs r0, 0x80
	lsls r0, 1
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x8
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r3, 0xF0
	bl sub_80A805C
	b _0810971A
	.pool
_081096FC:
	ldrh r1, [r4, 0x26]
	lsls r1, 24
	lsrs r1, 24
	movs r2, 0xC0
	lsls r2, 1
	movs r0, 0x80
	lsls r0, 1
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x8
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r3, 0xC0
	bl sub_80A805C
_0810971A:
	ldrh r1, [r4, 0xC]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08109738
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x26]
	subs r1, 0x3
	strh r1, [r0, 0x26]
_08109738:
	movs r0, 0
	strh r0, [r4, 0xA]
	strh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
	b _08109790
	.pool
_08109748:
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _08109764
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x22]
	subs r1, 0x1
	strh r1, [r0, 0x22]
_08109764:
	adds r0, r4, 0
	bl sub_80A80C8
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _081097AA
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r4, 0x10]
	strh r1, [r0, 0x22]
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A7344
	strh r5, [r4, 0xC]
_08109790:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _081097AA
	.pool
_0810979C:
	movs r1, 0x14
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081097AA
	adds r0, r5, 0
	bl DestroyAnimVisualTask
_081097AA:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81094D0

	thumb_func_start sub_81097B4
sub_81097B4: @ 81097B4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	adds r0, r4, 0
	bl sub_8109930
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	ldr r1, =gSprites
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldrh r4, [r0, 0x20]
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	bne _0810980C
	adds r0, r4, 0
	subs r0, 0xC
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x1
	b _08109816
	.pool
_0810980C:
	adds r0, r4, 0
	adds r0, 0x10
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0xFF
_08109816:
	movs r6, 0
	movs r5, 0
	lsls r4, 16
	str r4, [sp, 0x8]
	mov r1, r9
	lsls r1, 16
	str r1, [sp, 0x4]
	ldr r2, =gUnknown_085955CC
	mov r9, r2
	lsls r0, 24
	asrs r0, 24
	str r0, [sp]
	mov r3, r8
	lsls r3, 1
	mov r10, r3
_08109834:
	ldr r0, =gUnknown_085955B4
	ldr r2, [sp, 0x8]
	asrs r1, r2, 16
	ldr r3, [sp, 0x4]
	asrs r2, r3, 16
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _081098B6
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r4, r0, r1
	ldrh r2, [r4, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	lsls r0, r5, 2
	adds r0, 0x40
	adds r1, r0
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r3, =0xfffffc00
	adds r0, r3, 0
	ands r2, r0
	orrs r2, r1
	strh r2, [r4, 0x4]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x4
	bls _0810987E
	movs r5, 0
_0810987E:
	lsls r2, r6, 2
	mov r1, r9
	adds r0, r2, r1
	ldrh r0, [r0]
	ldr r3, [sp]
	adds r1, r0, 0
	muls r1, r3
	lsls r1, 16
	asrs r1, 16
	ldr r0, =gUnknown_085955CC+2
	adds r2, r0
	movs r3, 0
	ldrsh r2, [r2, r3]
	adds r0, r4, 0
	bl sub_8109984
	strh r7, [r4, 0x3A]
	mov r0, r8
	strh r0, [r4, 0x3C]
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	add r0, r10
	ldr r1, =gTasks + 0x8
	adds r0, r1
	ldrh r1, [r0]
	adds r1, 0x1
	strh r1, [r0]
_081098B6:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x6
	bls _08109834
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81097B4

	thumb_func_start sub_81098EC
sub_81098EC: @ 81098EC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81099A0
	adds r0, r4, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08109926
	ldr r3, =gTasks
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
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
	bl DestroySprite
_08109926:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81098EC

	thumb_func_start sub_8109930
sub_8109930: @ 8109930
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrh r2, [r1, 0x26]
	ldrh r0, [r1, 0x22]
	adds r2, r0
	adds r1, 0x29
	movs r0, 0
	ldrsb r0, [r1, r0]
	adds r0, r2
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	bne _08109970
	lsls r0, r4, 16
	movs r1, 0x94
	lsls r1, 15
	b _08109976
	.pool
_08109970:
	lsls r0, r4, 16
	movs r1, 0xB0
	lsls r1, 14
_08109976:
	adds r0, r1
	lsrs r4, r0, 16
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8109930

	thumb_func_start sub_8109984
sub_8109984: @ 8109984
	movs r3, 0
	strh r3, [r0, 0x2E]
	strh r3, [r0, 0x30]
	ldrh r3, [r0, 0x20]
	lsls r3, 3
	strh r3, [r0, 0x32]
	ldrh r3, [r0, 0x22]
	lsls r3, 3
	strh r3, [r0, 0x34]
	lsls r1, 3
	strh r1, [r0, 0x36]
	lsls r2, 3
	strh r2, [r0, 0x38]
	bx lr
	thumb_func_end sub_8109984

	thumb_func_start sub_81099A0
sub_81099A0: @ 81099A0
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _081099CA
	movs r0, 0
	strh r0, [r2, 0x2E]
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	ldrh r0, [r2, 0x30]
	adds r1, r0, 0
	muls r1, r0
	adds r0, r1, 0
	ldrh r3, [r2, 0x34]
	adds r0, r3
	strh r0, [r2, 0x34]
_081099CA:
	ldrh r0, [r2, 0x36]
	ldrh r1, [r2, 0x32]
	adds r0, r1
	strh r0, [r2, 0x32]
	lsls r0, 16
	asrs r0, 19
	strh r0, [r2, 0x20]
	ldrh r1, [r2, 0x38]
	ldrh r3, [r2, 0x34]
	adds r1, r3
	strh r1, [r2, 0x34]
	lsls r1, 16
	asrs r3, r1, 19
	strh r3, [r2, 0x22]
	adds r0, 0x8
	lsls r0, 16
	movs r1, 0x80
	lsls r1, 17
	cmp r0, r1
	bhi _08109A00
	adds r1, r3, 0
	movs r0, 0x8
	negs r0, r0
	cmp r1, r0
	blt _08109A00
	cmp r1, 0x78
	ble _08109A0C
_08109A00:
	adds r0, r2, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_08109A0C:
	pop {r0}
	bx r0
	thumb_func_end sub_81099A0

	thumb_func_start sub_8109A10
sub_8109A10: @ 8109A10
	push {r4,r5,lr}
	ldr r3, =gBattleAnimArgs
	ldrh r1, [r3]
	movs r2, 0
	strh r1, [r0, 0x20]
	ldrh r1, [r3, 0x2]
	strh r1, [r0, 0x22]
	strh r2, [r0, 0x2E]
	strh r2, [r0, 0x30]
	strh r2, [r0, 0x32]
	ldrh r1, [r3, 0x4]
	strh r1, [r0, 0x3A]
	ldrh r1, [r3, 0x6]
	strh r1, [r0, 0x3C]
	ldrh r4, [r0, 0x4]
	lsls r2, r4, 22
	lsrs r2, 22
	movs r5, 0x8
	ldrsh r1, [r3, r5]
	lsls r1, 4
	adds r2, r1
	ldr r3, =0x000003ff
	adds r1, r3, 0
	ands r2, r1
	ldr r1, =0xfffffc00
	ands r1, r4
	orrs r1, r2
	strh r1, [r0, 0x4]
	ldr r1, =sub_8109A64
	str r1, [r0, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8109A10

	thumb_func_start sub_8109A64
sub_8109A64: @ 8109A64
	push {r4,lr}
	adds r2, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r2, r1]
	cmp r0, 0x1
	beq _08109A96
	cmp r0, 0x1
	bgt _08109A7A
	cmp r0, 0
	beq _08109A80
	b _08109AF4
_08109A7A:
	cmp r0, 0x2
	beq _08109AB4
	b _08109AF4
_08109A80:
	ldrh r1, [r2, 0x3A]
	movs r3, 0x3A
	ldrsh r0, [r2, r3]
	cmp r0, 0
	beq _08109A90
	subs r0, r1, 0x1
	strh r0, [r2, 0x3A]
	b _08109AF4
_08109A90:
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
_08109A96:
	ldrh r0, [r2, 0x22]
	adds r0, 0x8
	strh r0, [r2, 0x22]
	lsls r0, 16
	asrs r0, 16
	ldrh r3, [r2, 0x3C]
	movs r4, 0x3C
	ldrsh r1, [r2, r4]
	cmp r0, r1
	blt _08109AF4
	strh r3, [r2, 0x22]
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	b _08109AF4
_08109AB4:
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08109AE0
	movs r0, 0
	strh r0, [r2, 0x30]
	ldrh r0, [r2, 0x32]
	adds r0, 0x1
	strh r0, [r2, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08109ADC
	ldr r0, =0x0000fffd
	b _08109ADE
	.pool
_08109ADC:
	movs r0, 0x3
_08109ADE:
	strh r0, [r2, 0x26]
_08109AE0:
	ldrh r0, [r2, 0x34]
	adds r0, 0x1
	strh r0, [r2, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	ble _08109AF4
	adds r0, r2, 0
	bl DestroyAnimSprite
_08109AF4:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8109A64

	thumb_func_start sub_8109AFC
sub_8109AFC: @ 8109AFC
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _08109B70
	cmp r0, 0x1
	bgt _08109B12
	cmp r0, 0
	beq _08109B18
	b _08109C3E
_08109B12:
	cmp r0, 0x2
	beq _08109BCE
	b _08109C3E
_08109B18:
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A69CC
	ldr r4, =gBattleAnimArgs
	ldrb r1, [r4, 0x4]
	adds r0, r5, 0
	bl StartSpriteAnim
	ldrh r0, [r4, 0x4]
	strh r0, [r5, 0x3C]
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _08109B48
	movs r0, 0x4
	b _08109B4A
	.pool
_08109B48:
	ldr r0, =0x0000fffc
_08109B4A:
	strh r0, [r5, 0x36]
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	bl sub_80A8328
	movs r1, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r5, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	b _08109BC6
	.pool
_08109B70:
	ldrh r0, [r5, 0x30]
	adds r0, 0xC0
	strh r0, [r5, 0x30]
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _08109B94
	ldrh r0, [r5, 0x30]
	lsls r0, 16
	asrs r0, 24
	negs r0, r0
	b _08109B9A
	.pool
_08109B94:
	ldrh r0, [r5, 0x30]
	lsls r0, 16
	asrs r0, 24
_08109B9A:
	strh r0, [r5, 0x26]
	movs r2, 0x32
	ldrsh r0, [r5, r2]
	movs r2, 0x36
	ldrsh r1, [r5, r2]
	bl Sin
	strh r0, [r5, 0x24]
	ldrh r0, [r5, 0x32]
	adds r0, 0x4
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x34]
	adds r0, 0x1
	strh r0, [r5, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _08109C3E
	movs r0, 0
	strh r0, [r5, 0x34]
_08109BC6:
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	b _08109C3E
_08109BCE:
	movs r1, 0x32
	ldrsh r0, [r5, r1]
	movs r2, 0x36
	ldrsh r1, [r5, r2]
	bl Sin
	adds r2, r0, 0
	movs r3, 0
	strh r2, [r5, 0x24]
	ldrh r0, [r5, 0x32]
	adds r0, 0x4
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x34]
	adds r0, 0x1
	strh r0, [r5, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1F
	bne _08109C3E
	ldrh r0, [r5, 0x20]
	adds r1, r2, r0
	strh r1, [r5, 0x20]
	ldrh r0, [r5, 0x26]
	ldrh r2, [r5, 0x22]
	adds r0, r2
	strh r0, [r5, 0x22]
	strh r3, [r5, 0x26]
	strh r3, [r5, 0x24]
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r5, 0x2E]
	strh r1, [r5, 0x30]
	ldr r4, =gBattleAnimTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x22]
	strh r0, [r5, 0x34]
	ldrb r0, [r4]
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x36]
	adds r0, r5, 0
	bl sub_80A6FD4
	ldr r0, =sub_8109C4C
	str r0, [r5, 0x1C]
_08109C3E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8109AFC

	thumb_func_start sub_8109C4C
sub_8109C4C: @ 8109C4C
	push {r4,lr}
	adds r4, r0, 0
	bl TranslateAnimLinear
	lsls r0, 24
	cmp r0, 0
	bne _08109CA4
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r1, 0x10
	bl Sin
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	ldrh r2, [r4, 0x38]
	adds r0, r2, 0x4
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x38]
	ldrh r0, [r4, 0x38]
	lsls r2, 16
	asrs r2, 16
	cmp r2, 0
	beq _08109C82
	cmp r2, 0xC4
	ble _08109CAA
_08109C82:
	lsls r0, 16
	cmp r0, 0
	ble _08109CAA
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08109CAA
	ldr r0, =gUnknown_02038440
	movs r1, 0
	ldrsb r1, [r0, r1]
	movs r0, 0x90
	bl PlaySE12WithPanning
	b _08109CAA
	.pool
_08109CA4:
	adds r0, r4, 0
	bl DestroyAnimSprite
_08109CAA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8109C4C

	thumb_func_start sub_8109CB0
sub_8109CB0: @ 8109CB0
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _08109CC8
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0]
	strh r0, [r4, 0x30]
	adds r0, r1, 0x1
	strh r0, [r4, 0x2E]
_08109CC8:
	movs r0, 0xC0
	lsls r0, 1
	adds r1, r0, 0
	ldrh r2, [r4, 0x34]
	adds r1, r2
	strh r1, [r4, 0x34]
	ldrh r0, [r4, 0x36]
	adds r0, 0xA0
	strh r0, [r4, 0x36]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	lsls r1, 16
	asrs r1, 24
	bl Sin
	strh r0, [r4, 0x24]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, 0x36]
	lsls r1, 16
	asrs r1, 24
	bl Cos
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	adds r0, 0x7
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x30]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08109D64
	ldrh r0, [r4, 0x30]
	subs r0, 0x40
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x83
	bls _08109D3C
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	bl sub_80A8328
	movs r1, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r4, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x5]
	b _08109D80
	.pool
_08109D3C:
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	bl sub_80A8328
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x1
	movs r1, 0x3
	ands r0, r1
	lsls r0, 2
	ldrb r2, [r4, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0x5]
	b _08109D80
	.pool
_08109D64:
	ldrh r0, [r4, 0x30]
	subs r0, 0x40
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x83
	bls _08109D78
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x1D
	b _08109D7E
_08109D78:
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x1F
_08109D7E:
	strb r0, [r1]
_08109D80:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	ble _08109DA8
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
_08109DA8:
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	cmp r0, 0x1E
	bne _08109DB6
	adds r0, r4, 0
	bl DestroyAnimSprite
_08109DB6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8109CB0

	thumb_func_start sub_8109DBC
sub_8109DBC: @ 8109DBC
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	movs r2, 0x1
	negs r2, r2
	adds r1, r2, 0
	cmp r0, 0
	bne _08109DE2
	movs r1, 0x1
_08109DE2:
	strh r1, [r4, 0x20]
	ldr r0, =gBattleAnimTarget
	ldrb r1, [r0]
	movs r0, 0x2
	eors r0, r1
	bl IsBattlerSpriteVisible
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x1
	strh r0, [r4, 0x22]
	movs r0, 0x1
	bl GetAnimBattlerSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x24]
	movs r0, 0x3
	bl GetAnimBattlerSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x26]
	ldr r0, =sub_8109E2C
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8109DBC

	thumb_func_start sub_8109E2C
sub_8109E2C: @ 8109E2C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r2, r0, r1
	movs r0, 0x8
	ldrsh r3, [r2, r0]
	cmp r3, 0x1
	beq _08109EF4
	cmp r3, 0x1
	bgt _08109E54
	cmp r3, 0
	beq _08109E62
	b _0810A054
	.pool
_08109E54:
	cmp r3, 0x2
	bne _08109E5A
	b _08109F7C
_08109E5A:
	cmp r3, 0x3
	bne _08109E60
	b _0810A010
_08109E60:
	b _0810A054
_08109E62:
	movs r1, 0x20
	ldrsh r0, [r2, r1]
	lsls r0, 1
	ldrh r5, [r2, 0x1C]
	adds r0, r5
	strh r0, [r2, 0x1C]
	ldrh r0, [r2, 0xA]
	adds r0, 0x1
	strh r0, [r2, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08109E94
	strh r3, [r2, 0xA]
	ldrh r0, [r2, 0xC]
	adds r0, 0x1
	strh r0, [r2, 0xC]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08109E90
	movs r0, 0x2
	b _08109E92
_08109E90:
	ldr r0, =0x0000fffe
_08109E92:
	strh r0, [r2, 0x1E]
_08109E94:
	movs r1, 0
	strh r1, [r2, 0xE]
	movs r7, 0x22
	ldrsh r0, [r2, r7]
	cmp r1, r0
	bge _08109ED6
	ldr r4, =gSprites
	adds r3, r2, 0
	adds r3, 0x8
_08109EA6:
	movs r1, 0xE
	ldrsh r0, [r2, r1]
	adds r0, 0xE
	lsls r0, 1
	adds r0, r3, r0
	movs r5, 0
	ldrsh r0, [r0, r5]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r2, 0x1E]
	ldrh r7, [r2, 0x1C]
	adds r0, r7
	strh r0, [r1, 0x24]
	ldrh r0, [r2, 0xE]
	adds r0, 0x1
	strh r0, [r2, 0xE]
	lsls r0, 16
	asrs r0, 16
	movs r5, 0x22
	ldrsh r1, [r2, r5]
	cmp r0, r1
	blt _08109EA6
_08109ED6:
	ldrh r0, [r2, 0x1A]
	adds r0, 0x1
	strh r0, [r2, 0x1A]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	beq _08109EE6
	b _0810A054
_08109EE6:
	movs r0, 0
	strh r0, [r2, 0x1A]
	b _0810A000
	.pool
_08109EF4:
	ldrh r0, [r2, 0xA]
	adds r0, 0x1
	strh r0, [r2, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _08109F1C
	movs r0, 0
	strh r0, [r2, 0xA]
	ldrh r0, [r2, 0xC]
	adds r0, 0x1
	strh r0, [r2, 0xC]
	ands r0, r3
	lsls r0, 16
	cmp r0, 0
	beq _08109F18
	movs r0, 0x2
	b _08109F1A
_08109F18:
	ldr r0, =0x0000fffe
_08109F1A:
	strh r0, [r2, 0x1E]
_08109F1C:
	movs r1, 0
	strh r1, [r2, 0xE]
	movs r7, 0x22
	ldrsh r0, [r2, r7]
	cmp r1, r0
	bge _08109F5E
	ldr r4, =gSprites
	adds r3, r2, 0
	adds r3, 0x8
_08109F2E:
	movs r1, 0xE
	ldrsh r0, [r2, r1]
	adds r0, 0xE
	lsls r0, 1
	adds r0, r3, r0
	movs r5, 0
	ldrsh r0, [r0, r5]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r2, 0x1E]
	ldrh r7, [r2, 0x1C]
	adds r0, r7
	strh r0, [r1, 0x24]
	ldrh r0, [r2, 0xE]
	adds r0, 0x1
	strh r0, [r2, 0xE]
	lsls r0, 16
	asrs r0, 16
	movs r5, 0x22
	ldrsh r1, [r2, r5]
	cmp r0, r1
	blt _08109F2E
_08109F5E:
	ldrh r0, [r2, 0x1A]
	adds r0, 0x1
	strh r0, [r2, 0x1A]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x60
	bne _0810A054
	movs r0, 0
	strh r0, [r2, 0x1A]
	b _0810A000
	.pool
_08109F7C:
	movs r7, 0x20
	ldrsh r1, [r2, r7]
	lsls r1, 1
	ldrh r0, [r2, 0x1C]
	subs r0, r1
	strh r0, [r2, 0x1C]
	ldrh r0, [r2, 0xA]
	adds r0, 0x1
	strh r0, [r2, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08109FB0
	movs r0, 0
	strh r0, [r2, 0xA]
	ldrh r0, [r2, 0xC]
	adds r0, 0x1
	strh r0, [r2, 0xC]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08109FAC
	strh r3, [r2, 0x1E]
	b _08109FB0
_08109FAC:
	ldr r0, =0x0000fffe
	strh r0, [r2, 0x1E]
_08109FB0:
	movs r1, 0
	strh r1, [r2, 0xE]
	movs r3, 0x22
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bge _08109FF2
	ldr r4, =gSprites
	adds r3, r2, 0
	adds r3, 0x8
_08109FC2:
	movs r5, 0xE
	ldrsh r0, [r2, r5]
	adds r0, 0xE
	lsls r0, 1
	adds r0, r3, r0
	movs r7, 0
	ldrsh r0, [r0, r7]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r2, 0x1E]
	ldrh r5, [r2, 0x1C]
	adds r0, r5
	strh r0, [r1, 0x24]
	ldrh r0, [r2, 0xE]
	adds r0, 0x1
	strh r0, [r2, 0xE]
	lsls r0, 16
	asrs r0, 16
	movs r7, 0x22
	ldrsh r1, [r2, r7]
	cmp r0, r1
	blt _08109FC2
_08109FF2:
	ldrh r0, [r2, 0x1A]
	adds r0, 0x1
	strh r0, [r2, 0x1A]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	bne _0810A054
_0810A000:
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
	b _0810A054
	.pool
_0810A010:
	movs r1, 0
	strh r1, [r2, 0xE]
	movs r3, 0x22
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bge _0810A04E
	ldr r6, =gSprites
	adds r3, r2, 0
	adds r3, 0x8
	movs r5, 0
_0810A024:
	movs r7, 0xE
	ldrsh r0, [r2, r7]
	adds r0, 0xE
	lsls r0, 1
	adds r0, r3, r0
	movs r7, 0
	ldrsh r1, [r0, r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r5, [r0, 0x24]
	ldrh r0, [r2, 0xE]
	adds r0, 0x1
	strh r0, [r2, 0xE]
	lsls r0, 16
	asrs r0, 16
	movs r7, 0x22
	ldrsh r1, [r2, r7]
	cmp r0, r1
	blt _0810A024
_0810A04E:
	adds r0, r4, 0
	bl DestroyAnimVisualTask
_0810A054:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8109E2C

	thumb_func_start AnimTask_BlendBackground
AnimTask_BlendBackground: @ 810A060
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldrb r0, [r0, 0x8]
	lsls r0, 4
	ldr r1, =gBattleAnimArgs
	ldrb r2, [r1]
	ldrh r3, [r1, 0x2]
	movs r1, 0x10
	bl BlendPalette
	adds r0, r4, 0
	bl DestroyAnimVisualTask
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AnimTask_BlendBackground

	thumb_func_start sub_810A094
sub_810A094: @ 810A094
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r2, r0, r1
	movs r3, 0x8
	ldrsh r0, [r2, r3]
	mov r9, r1
	ldr r4, =gBattleAnimArgs
	mov r8, r4
	cmp r0, 0
	bne _0810A0CA
	ldrh r0, [r4]
	strh r0, [r2, 0xA]
	ldrh r0, [r4, 0x2]
	strh r0, [r2, 0xC]
	ldrh r0, [r4, 0x4]
	strh r0, [r2, 0xE]
	ldrh r0, [r4, 0x6]
	strh r0, [r2, 0x10]
_0810A0CA:
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
	ldr r1, =gBattlerSpriteIds
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	adds r0, r1
	ldrb r6, [r0]
	movs r5, 0x10
	ldrsh r0, [r2, r5]
	cmp r0, 0
	bne _0810A100
	ldr r4, =gUnknown_08595684
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	b _0810A106
	.pool
_0810A100:
	ldr r4, =gUnknown_08595694
	movs r3, 0x8
	ldrsh r0, [r2, r3]
_0810A106:
	movs r1, 0xA
	bl __modsi3
	lsls r0, 16
	asrs r0, 16
	adds r0, r4
	ldrb r5, [r0]
	lsls r0, r7, 2
	adds r1, r0, r7
	lsls r1, 3
	add r1, r9
	movs r4, 0xE
	ldrsh r1, [r1, r4]
	mov r12, r0
	cmp r1, 0x1
	bne _0810A154
	ldr r2, =gSprites
	lsls r3, r6, 4
	adds r0, r3, r6
	lsls r0, 2
	adds r0, r2
	mov r10, r0
	mov r0, r8
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	lsls r0, r5, 24
	asrs r0, 24
	muls r0, r1
	cmp r0, 0
	bge _0810A144
	negs r0, r0
_0810A144:
	mov r5, r10
	strh r0, [r5, 0x26]
	b _0810A16E
	.pool
_0810A154:
	ldr r3, =gSprites
	lsls r4, r6, 4
	adds r2, r4, r6
	lsls r2, 2
	adds r2, r3
	lsls r0, r5, 24
	asrs r0, 24
	mov r5, r8
	ldrh r1, [r5, 0x2]
	muls r0, r1
	strh r0, [r2, 0x24]
	adds r2, r3, 0
	adds r3, r4, 0
_0810A16E:
	mov r1, r12
	adds r0, r1, r7
	lsls r0, 3
	add r0, r9
	movs r4, 0x8
	ldrsh r1, [r0, r4]
	movs r5, 0xA
	ldrsh r0, [r0, r5]
	cmp r1, r0
	bne _0810A194
	adds r0, r3, r6
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strh r1, [r0, 0x24]
	strh r1, [r0, 0x26]
	adds r0, r7, 0
	bl DestroyAnimVisualTask
_0810A194:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810A094

	.align 2, 0
