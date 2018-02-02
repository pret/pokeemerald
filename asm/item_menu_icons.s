	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start RemoveBagObject
@ void RemoveBagObject(u8 a1)
RemoveBagObject: @ 80D4CA8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_0203CE54
	ldr r2, =0x00000804
	adds r1, r4, r2
	ldr r0, [r0]
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, 0xFF
	beq _080D4CEE
	adds r4, 0x64
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl FreeSpriteOamMatrix
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	movs r0, 0xFF
	strb r0, [r5]
_080D4CEE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end RemoveBagObject

	thumb_func_start AddBagVisualObject
@ void AddBagVisualObject(u8 bagPocketId)
AddBagVisualObject: @ 80D4D00
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gUnknown_0203CE54
	ldr r4, [r0]
	ldr r0, =0x00000804
	adds r4, r0
	ldr r0, =gUnknown_0857FB4C
	movs r1, 0x44
	movs r2, 0x42
	movs r3, 0
	bl CreateSprite
	strb r0, [r4]
	adds r0, r5, 0
	movs r1, 0
	bl SetBagVisualPocketId
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AddBagVisualObject

	thumb_func_start SetBagVisualPocketId
@ void SetBagVisualPocketId(u8 bagPocketId, bool8 isSwitchingPockets)
SetBagVisualPocketId: @ 80D4D38
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	ldr r2, =0x00000804
	adds r0, r2
	ldrb r2, [r0]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	ldr r2, =gSprites
	adds r2, r0, r2
	cmp r1, 0
	beq _080D4D84
	ldr r0, =0x0000fffb
	strh r0, [r2, 0x26]
	ldr r0, =ObjectCB_BagVisualSwitchingPockets
	str r0, [r2, 0x1C]
	adds r0, r3, 0x1
	strh r0, [r2, 0x2E]
	adds r0, r2, 0
	movs r1, 0
	bl StartSpriteAnim
	b _080D4D90
	.pool
_080D4D84:
	adds r1, r3, 0x1
	lsls r1, 24
	lsrs r1, 24
	adds r0, r2, 0
	bl StartSpriteAnim
_080D4D90:
	pop {r0}
	bx r0
	thumb_func_end SetBagVisualPocketId

	thumb_func_start ObjectCB_BagVisualSwitchingPockets
@ void ObjectCB_BagVisualSwitchingPockets(struct obj *object)
ObjectCB_BagVisualSwitchingPockets: @ 80D4D94
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x26]
	movs r2, 0x26
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _080D4DA8
	adds r0, r1, 0x1
	strh r0, [r4, 0x26]
	b _080D4DB8
_080D4DA8:
	ldrh r1, [r4, 0x2E]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
_080D4DB8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ObjectCB_BagVisualSwitchingPockets

	thumb_func_start ShakeBagVisual
@ void ShakeBagVisual()
ShakeBagVisual: @ 80D4DC4
	push {r4,lr}
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	ldr r1, =0x00000804
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r4, r0, r1
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080D4DF4
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	ldr r0, =ObjectCB_ShakeBagVisual
	str r0, [r4, 0x1C]
_080D4DF4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ShakeBagVisual

	thumb_func_start ObjectCB_ShakeBagVisual
@ void ObjectCB_ShakeBagVisual(struct obj *object)
ObjectCB_ShakeBagVisual: @ 80D4E0C
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080D4E28
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAffineAnim
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
_080D4E28:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ObjectCB_ShakeBagVisual

	thumb_func_start AddSwitchPocketRotatingBallObject
@ void AddSwitchPocketRotatingBallObject(u16 rotationDirection)
AddSwitchPocketRotatingBallObject: @ 80D4E34
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	ldr r0, =gUnknown_0203CE54
	ldr r4, [r0]
	ldr r0, =0x00000805
	adds r4, r0
	ldr r0, =gUnknown_0857FBA0
	bl LoadSpriteSheet
	ldr r0, =gUnknown_0857FBA8
	bl LoadSpritePalette
	ldr r0, =gUnknown_0857FBB0
	movs r1, 0x10
	movs r2, 0x10
	movs r3, 0
	bl CreateSprite
	strb r0, [r4]
	ldr r2, =gSprites
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r5, [r0, 0x2E]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AddSwitchPocketRotatingBallObject

	thumb_func_start update_switch_pocket_rotating_ball_coords
@ void update_switch_pocket_rotating_ball_coords(struct obj *object)
update_switch_pocket_rotating_ball_coords: @ 80D4E8C
	ldrh r2, [r0, 0x30]
	ldrh r1, [r0, 0x34]
	adds r1, 0x1
	movs r3, 0x1
	ands r1, r3
	subs r2, r1
	adds r1, r0, 0
	adds r1, 0x28
	strb r2, [r1]
	ldrh r2, [r0, 0x30]
	ldrh r1, [r0, 0x34]
	adds r1, 0x1
	ands r1, r3
	subs r2, r1
	adds r0, 0x29
	strb r2, [r0]
	bx lr
	thumb_func_end update_switch_pocket_rotating_ball_coords

	thumb_func_start ObjectCB_SwitchPocketRotatingBallInit
@ void ObjectCB_SwitchPocketRotatingBallInit(struct obj *object)
ObjectCB_SwitchPocketRotatingBallInit: @ 80D4EB0
	push {r4,lr}
	adds r4, r0, 0
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r4, 0x1]
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080D4ED8
	ldr r0, =gUnknown_0857FB98
	b _080D4EDA
	.pool
_080D4ED8:
	ldr r0, =gUnknown_0857FB9C
_080D4EDA:
	str r0, [r4, 0x10]
	adds r0, r4, 0
	bl InitSpriteAffineAnim
	adds r0, r4, 0
	adds r0, 0x28
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	strh r0, [r4, 0x30]
	adds r0, r4, 0
	adds r0, 0x29
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	strh r0, [r4, 0x30]
	adds r0, r4, 0
	bl update_switch_pocket_rotating_ball_coords
	ldr r0, =ObjectCB_SwitchPocketRotatingBallContinue
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ObjectCB_SwitchPocketRotatingBallInit

	thumb_func_start ObjectCB_SwitchPocketRotatingBallContinue
@ void ObjectCB_SwitchPocketRotatingBallContinue(struct obj *object)
ObjectCB_SwitchPocketRotatingBallContinue: @ 80D4F14
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	adds r0, r4, 0
	bl update_switch_pocket_rotating_ball_coords
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, 0x10
	bne _080D4F32
	movs r0, 0x1
	bl RemoveBagObject
_080D4F32:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end ObjectCB_SwitchPocketRotatingBallContinue

	thumb_func_start AddBagItemIconObject
@ void AddBagItemIconObject(u16 itemId, u8 a2)
AddBagItemIconObject: @ 80D4F38
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_0203CE54
	ldr r2, =0x00000806
	adds r1, r4, r2
	ldr r0, [r0]
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, 0xFF
	bne _080D4F86
	adds r4, 0x66
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r6, 0
	bl AddItemIconSprite
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _080D4F86
	strb r2, [r5]
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0x18
	strh r1, [r0, 0x24]
	movs r1, 0x58
	strh r1, [r0, 0x26]
_080D4F86:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AddBagItemIconObject

	thumb_func_start RemoveBagItemIconObject
@ void RemoveBagItemIconObject(u8 a1)
RemoveBagItemIconObject: @ 80D4F98
	push {lr}
	lsls r0, 24
	movs r1, 0x80
	lsls r1, 18
	adds r0, r1
	lsrs r0, 24
	bl RemoveBagObject
	pop {r0}
	bx r0
	thumb_func_end RemoveBagItemIconObject

	thumb_func_start sub_80D4FAC
sub_80D4FAC: @ 80D4FAC
	push {lr}
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	ldr r1, =0x00000808
	adds r0, r1
	movs r1, 0x8
	bl sub_8122344
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D4FAC

	thumb_func_start sub_80D4FC8
sub_80D4FC8: @ 80D4FC8
	push {lr}
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	ldr r1, =0x00000808
	adds r0, r1
	movs r1, 0x8
	bl sub_81223FC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D4FC8

	thumb_func_start sub_80D4FEC
sub_80D4FEC: @ 80D4FEC
	push {lr}
	adds r3, r0, 0
	lsls r3, 24
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	ldr r1, =0x00000808
	adds r0, r1
	lsrs r3, 4
	movs r1, 0x80
	lsls r1, 13
	adds r3, r1
	lsrs r3, 16
	movs r1, 0x88
	movs r2, 0x78
	bl sub_8122448
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D4FEC

	thumb_func_start sub_80D5018
sub_80D5018: @ 80D5018
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r4, r1, 0
	movs r2, 0x80
	lsls r2, 4
	adds r0, r4, 0
	movs r1, 0
	bl memset
	movs r0, 0x80
	lsls r0, 1
	adds r4, r0
	movs r7, 0
_080D5036:
	adds r4, 0x20
	movs r5, 0
	adds r1, r7, 0x1
	mov r8, r1
_080D503E:
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x20
	bl memcpy
	adds r4, 0x20
	adds r6, 0x20
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _080D503E
	cmp r7, 0x5
	beq _080D505C
	adds r4, 0x20
_080D505C:
	mov r1, r8
	lsls r0, r1, 24
	lsrs r7, r0, 24
	cmp r7, 0x5
	bls _080D5036
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80D5018

	thumb_func_start sub_80D5070
sub_80D5070: @ 80D5070
	push {r4,r5,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	cmp r4, 0x2A
	bne _080D5082
	bl IsEnigmaBerryValid
_080D5082:
	ldr r5, =gBerryPicTable
	lsls r4, 3
	adds r0, r5, 0x4
	adds r0, r4, r0
	ldr r0, [r0]
	str r0, [sp]
	ldr r1, =0xffff0000
	ldr r0, [sp, 0x4]
	ands r0, r1
	ldr r1, =0x00007544
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r0, sp
	bl LoadCompressedObjectPalette
	adds r4, r5
	ldr r0, [r4]
	ldr r4, =0x0201d000
	adds r1, r4, 0
	bl LZDecompressWram
	ldr r0, =0xfffff000
	adds r1, r4, r0
	adds r0, r4, 0
	bl sub_80D5018
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D5070

	thumb_func_start sub_80D50D4
sub_80D50D4: @ 80D50D4
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	bl sub_80D5070
	ldr r0, =gUnknown_0857FBEC
	lsls r4, 16
	asrs r4, 16
	lsls r5, 16
	asrs r5, 16
	adds r1, r4, 0
	adds r2, r5, 0
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D50D4

	thumb_func_start sub_80D510C
sub_80D510C: @ 80D510C
	push {lr}
	ldr r0, =0x00007544
	bl FreeSpritePaletteByTag
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D510C

	thumb_func_start sub_80D511C
sub_80D511C: @ 80D511C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	mov r8, r3
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =0x00007544
	bl FreeSpritePaletteByTag
	adds r0, r4, 0
	bl sub_80D5070
	ldr r0, =gUnknown_0857FC7C
	adds r1, r5, 0
	adds r2, r6, 0
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	adds r4, r1, 0
	mov r0, r8
	cmp r0, 0x1
	bne _080D5172
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0x1
	bl StartSpriteAffineAnim
_080D5172:
	adds r0, r4, 0
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D511C

	thumb_func_start sub_80D518C
sub_80D518C: @ 80D518C
	push {lr}
	adds r1, r0, 0
	ldr r0, =gUnknown_0857FE10
	lsls r1, 16
	asrs r1, 16
	movs r2, 0x74
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D518C

	.align 2, 0 @ Don't pad with nop.
