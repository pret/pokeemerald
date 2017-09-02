	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start DecryptMoney
@ int DecryptMoney(u32 *moneyPointer)
DecryptMoney: @ 80E5114
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	adds r1, 0xAC
	ldr r0, [r0]
	ldr r1, [r1]
	eors r0, r1
	bx lr
	.pool
	thumb_func_end DecryptMoney

	thumb_func_start EncryptMoney
@ void EncryptMoney(u32 *moneyPointer, u32 moneyAmount)
EncryptMoney: @ 80E5128
	ldr r2, =gSaveBlock2Ptr
	ldr r2, [r2]
	adds r2, 0xAC
	ldr r2, [r2]
	eors r2, r1
	str r2, [r0]
	bx lr
	.pool
	thumb_func_end EncryptMoney

	thumb_func_start IsEnoughMoney
@ bool8 IsEnoughMoney(u32 *moneyPointer, u32 price)
IsEnoughMoney: @ 80E513C
	push {r4,lr}
	adds r4, r1, 0
	bl DecryptMoney
	cmp r0, r4
	bcs _080E514C
	movs r0, 0
	b _080E514E
_080E514C:
	movs r0, 0x1
_080E514E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end IsEnoughMoney

	thumb_func_start add_money
@ void add_money(int *money_ptr, int amount)
add_money: @ 80E5154
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	bl DecryptMoney
	adds r5, r0, 0
	adds r0, r5, r4
	ldr r5, =0x000f423f
	adds r4, r5, 0
	cmp r0, r5
	bhi _080E5178
	adds r5, r0, 0
	adds r0, r6, 0
	bl DecryptMoney
	cmp r5, r0
	bcs _080E5178
	adds r5, r4, 0
_080E5178:
	adds r0, r6, 0
	adds r1, r5, 0
	bl EncryptMoney
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end add_money

	thumb_func_start subtract_money
@ void subtract_money(int *money_ptr, int amount)
subtract_money: @ 80E518C
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl DecryptMoney
	adds r1, r0, 0
	cmp r1, r4
	bcs _080E51A0
	movs r1, 0
	b _080E51A2
_080E51A0:
	subs r1, r4
_080E51A2:
	adds r0, r5, 0
	bl EncryptMoney
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end subtract_money

	thumb_func_start sub_80E51B0
sub_80E51B0: @ 80E51B0
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x92
	lsls r1, 3
	adds r0, r1
	ldr r1, =gSpecialVar_0x8005
	ldrh r1, [r1]
	bl IsEnoughMoney
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E51B0

	thumb_func_start sub_80E51D4
sub_80E51D4: @ 80E51D4
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x92
	lsls r1, 3
	adds r0, r1
	ldr r1, =gSpecialVar_0x8005
	ldrh r1, [r1]
	bl subtract_money
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E51D4

	thumb_func_start PrintMoneyAmountInMoneyBox
@ void PrintMoneyAmountInMoneyBox(u8 windowId, int amount, s8 a3)
PrintMoneyAmountInMoneyBox: @ 80E51F4
	push {lr}
	sub sp, 0x4
	adds r3, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp]
	movs r1, 0x26
	movs r2, 0x1
	bl PrintMoneyAmount
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end PrintMoneyAmountInMoneyBox

	thumb_func_start PrintMoneyAmount
@ void PrintMoneyAmount(u8 windowId, char x, char y, int amount, u8 a5)
PrintMoneyAmount: @ 80E5214
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	ldr r4, [sp, 0x24]
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r2, 24
	lsrs r6, r2, 24
	lsls r4, 24
	lsrs r5, r4, 24
	ldr r4, =gStringVar1
	adds r0, r4, 0
	adds r1, r3, 0
	movs r2, 0
	movs r3, 0x6
	bl ConvertIntToDecimalStringN
	adds r0, r4, 0
	bl StringLength
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x6
	subs r1, r0
	ldr r2, =gStringVar4
	adds r0, r1, 0
	subs r1, 0x1
	cmp r0, 0
	ble _080E5264
	movs r3, 0x77
_080E5258:
	strb r3, [r2]
	adds r2, 0x1
	adds r0, r1, 0
	subs r1, 0x1
	cmp r0, 0
	bgt _080E5258
_080E5264:
	ldr r1, =gUnknown_085E969C
	adds r0, r2, 0
	bl StringExpandPlaceholders
	ldr r2, =gStringVar4
	str r6, [sp]
	str r5, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r7, 0
	movs r1, 0x1
	mov r3, r8
	bl Print
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PrintMoneyAmount

	thumb_func_start set_window_border_style_and_print_money_box
@ void set_window_border_style_and_print_money_box(u8 windowId, u16 tileStart, u8 palette, int amount)
set_window_border_style_and_print_money_box: @ 80E5298
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	mov r8, r3
	lsls r6, 24
	lsrs r6, 24
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 24
	lsrs r5, 24
	adds r0, r6, 0
	movs r1, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl SetWindowBorderStyle
	adds r0, r6, 0
	mov r1, r8
	movs r2, 0
	bl PrintMoneyAmountInMoneyBox
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end set_window_border_style_and_print_money_box

	thumb_func_start sub_80E52D4
sub_80E52D4: @ 80E52D4
	push {lr}
	adds r1, r0, 0
	ldr r0, =gUnknown_02039F98
	ldrb r0, [r0]
	movs r2, 0
	bl PrintMoneyAmountInMoneyBox
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E52D4

	thumb_func_start sub_80E52EC
@ void sub_80E52EC(int money, int x, int y)
sub_80E52EC: @ 80E52EC
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x18
	mov r8, r0
	adds r4, r1, 0
	adds r3, r2, 0
	lsls r4, 24
	lsls r3, 24
	lsrs r6, r4, 24
	movs r0, 0x80
	lsls r0, 17
	adds r4, r0
	lsrs r4, 24
	lsrs r5, r3, 24
	adds r3, r0
	lsrs r3, 24
	movs r0, 0xA
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0x8
	str r0, [sp, 0xC]
	add r0, sp, 0x10
	movs r1, 0
	adds r2, r4, 0
	bl rbox_template_set
	ldr r4, =gUnknown_02039F98
	add r0, sp, 0x10
	bl AddWindow
	strb r0, [r4]
	ldrb r0, [r4]
	movs r1, 0
	bl FillWindowPixelBuffer
	ldrb r0, [r4]
	bl PutWindowTilemap
	ldrb r0, [r4]
	movs r1, 0x1
	bl CopyWindowToVram
	ldrb r0, [r4]
	movs r1, 0x85
	lsls r1, 2
	movs r2, 0xE
	mov r3, r8
	bl set_window_border_style_and_print_money_box
	lsls r6, 19
	movs r0, 0x98
	lsls r0, 13
	adds r6, r0
	lsrs r6, 16
	lsls r5, 19
	movs r0, 0xB0
	lsls r0, 12
	adds r5, r0
	lsrs r5, 16
	adds r0, r6, 0
	adds r1, r5, 0
	bl AddMoneyLabelObject
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E52EC

	thumb_func_start sub_80E5384
sub_80E5384: @ 80E5384
	push {r4,lr}
	bl RemoveMoneyLabelObject
	ldr r4, =gUnknown_02039F98
	ldrb r0, [r4]
	movs r1, 0
	bl sub_8198070
	ldrb r0, [r4]
	movs r1, 0x2
	bl CopyWindowToVram
	ldrb r0, [r4]
	bl RemoveWindow
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E5384

	thumb_func_start AddMoneyLabelObject
AddMoneyLabelObject: @ 80E53AC
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	ldr r0, =gUnknown_0858C2A4
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0858C2AC
	bl LoadCompressedObjectPalette
	ldr r0, =gUnknown_0858C28C
	lsls r4, 16
	asrs r4, 16
	lsls r5, 16
	asrs r5, 16
	adds r1, r4, 0
	adds r2, r5, 0
	movs r3, 0
	bl CreateSprite
	ldr r1, =gUnknown_02039F99
	strb r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AddMoneyLabelObject

	thumb_func_start RemoveMoneyLabelObject
RemoveMoneyLabelObject: @ 80E53F4
	push {lr}
	ldr r0, =gUnknown_02039F99
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySpriteAndFreeResources
	pop {r0}
	bx r0
	.pool
	thumb_func_end RemoveMoneyLabelObject

	.align 2, 0 @ Don't pad with nop.
