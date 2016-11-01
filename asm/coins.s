	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start PrintCoinsString
@ void PrintCoinsString(s32 coinAmount)
PrintCoinsString: @ 8145B54
	push {r4,lr}
	sub sp, 0xC
	adds r1, r0, 0
	ldr r0, =gUnknown_02021CC4
	movs r2, 0x1
	movs r3, 0x4
	bl ConvertIntToDecimalString
	ldr r4, =gUnknown_02021FC4
	ldr r1, =gUnknown_085E8DAB
	adds r0, r4, 0
	bl ExpandStringRefs
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x40
	bl GetStringRightAlignXOffset
	adds r3, r0, 0
	ldr r0, =gUnknown_0203AB9C
	ldrb r0, [r0]
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x1
	adds r2, r4, 0
	bl Print
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PrintCoinsString

	thumb_func_start ShowCoinsWindow
@ void ShowCoinsWindow(s32 coinAmount, u8 x, u8 y)
ShowCoinsWindow: @ 8145BAC
	push {r4,r5,lr}
	sub sp, 0x18
	adds r5, r0, 0
	adds r4, r1, 0
	adds r3, r2, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x8
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	ldr r0, =0x00000141
	str r0, [sp, 0xC]
	add r0, sp, 0x10
	movs r1, 0
	adds r2, r4, 0
	bl rbox_template_set
	ldr r4, =gUnknown_0203AB9C
	add r0, sp, 0x10
	bl AddWindow
	strb r0, [r4]
	ldrb r0, [r4]
	movs r1, 0
	bl FillWindowPixelBuffer
	ldrb r0, [r4]
	bl PutWindowTilemap
	ldrb r0, [r4]
	movs r2, 0x85
	lsls r2, 2
	movs r1, 0
	movs r3, 0xE
	bl SetWindowBorderStyle
	adds r0, r5, 0
	bl PrintCoinsString
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ShowCoinsWindow

	thumb_func_start HideCoinsWindow
@ void HideCoinsWindow()
HideCoinsWindow: @ 8145C14
	push {r4,lr}
	ldr r4, =gUnknown_0203AB9C
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_819746C
	ldrb r0, [r4]
	bl RemoveWindow
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end HideCoinsWindow

	thumb_func_start GetCoins
@ u16 GetCoins()
GetCoins: @ 8145C30
	ldr r0, =gUnknown_03005D8C
	ldr r1, [r0]
	ldr r0, =0x00000494
	adds r1, r0
	ldr r0, =gUnknown_03005D90
	ldr r0, [r0]
	adds r0, 0xAC
	ldr r0, [r0]
	ldrh r1, [r1]
	eors r0, r1
	lsls r0, 16
	lsrs r0, 16
	bx lr
	.pool
	thumb_func_end GetCoins

	thumb_func_start SetCoins
@ void SetCoins(u16 amount)
SetCoins: @ 8145C58
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gUnknown_03005D8C
	ldr r2, [r1]
	ldr r1, =gUnknown_03005D90
	ldr r1, [r1]
	adds r1, 0xAC
	ldr r1, [r1]
	eors r0, r1
	ldr r1, =0x00000494
	adds r2, r1
	strh r0, [r2]
	bx lr
	.pool
	thumb_func_end SetCoins

	thumb_func_start AddCoins
@ bool8 AddCoins(u16 amount)
AddCoins: @ 8145C80
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	bl GetCoins
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =0x0000270e
	cmp r1, r0
	bls _08145C9C
	movs r0, 0
	b _08145CC0
	.pool
_08145C9C:
	adds r0, r1, r4
	cmp r1, r0
	ble _08145CAC
	ldr r0, =0x0000270f
	b _08145CBA
	.pool
_08145CAC:
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =0x0000270f
	cmp r1, r0
	bls _08145CB8
	adds r1, r0, 0
_08145CB8:
	adds r0, r1, 0
_08145CBA:
	bl SetCoins
	movs r0, 0x1
_08145CC0:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end AddCoins

	thumb_func_start SubtractCoins
@ bool8 SubtractCoins(u16 amount)
SubtractCoins: @ 8145CCC
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	bl GetCoins
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r4
	bcs _08145CE2
	movs r0, 0
	b _08145CEE
_08145CE2:
	subs r0, r4
	lsls r0, 16
	lsrs r0, 16
	bl SetCoins
	movs r0, 0x1
_08145CEE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end SubtractCoins

	.align 2, 0 @ Don't pad with nop.
