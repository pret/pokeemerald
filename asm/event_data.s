	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


	thumb_func_start ClearTempFieldEventData
ClearTempFieldEventData: @ 809D344
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00001270
	adds r2, r0, r1
	movs r1, 0
	str r1, [r2]
	ldr r1, =0x0000139c
	adds r0, r1
	movs r1, 0
	movs r2, 0x20
	bl memset
	ldr r0, =0x000008ad
	bl FlagReset
	ldr r0, =0x000008ae
	bl FlagReset
	ldr r0, =0x00000889
	bl FlagReset
	ldr r0, =0x000008c1
	bl FlagReset
	movs r0, 0x88
	lsls r0, 4
	bl FlagReset
	pop {r0}
	bx r0
	.pool
	thumb_func_end ClearTempFieldEventData

	thumb_func_start ClearUpperFlags
ClearUpperFlags: @ 809D3A0
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00001394
	adds r0, r1
	movs r1, 0
	movs r2, 0x8
	bl memset
	pop {r0}
	bx r0
	.pool
	thumb_func_end ClearUpperFlags

	thumb_func_start DisableNationalPokedex
DisableNationalPokedex: @ 809D3C0
	push {lr}
	ldr r0, =0x00004046
	bl GetVarPointer
	ldr r1, =gSaveBlock2Ptr
	ldr r2, [r1]
	movs r1, 0
	strb r1, [r2, 0x1A]
	strh r1, [r0]
	ldr r0, =0x00000896
	bl FlagReset
	pop {r0}
	bx r0
	.pool
	thumb_func_end DisableNationalPokedex

	thumb_func_start EnableNationalPokedex
EnableNationalPokedex: @ 809D3E8
	push {r4,r5,lr}
	ldr r0, =0x00004046
	bl GetVarPointer
	ldr r4, =gSaveBlock2Ptr
	ldr r2, [r4]
	movs r5, 0
	movs r1, 0xDA
	strb r1, [r2, 0x1A]
	ldr r2, =0x00000302
	adds r1, r2, 0
	strh r1, [r0]
	ldr r0, =0x00000896
	bl FlagSet
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0x19]
	ldr r0, [r4]
	strb r5, [r0, 0x18]
	bl sub_80BB358
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EnableNationalPokedex

	thumb_func_start IsNationalPokedexEnabled
IsNationalPokedexEnabled: @ 809D42C
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1A]
	cmp r0, 0xDA
	bne _0809D468
	ldr r0, =0x00004046
	bl VarGet
	lsls r0, 16
	ldr r1, =0x03020000
	cmp r0, r1
	bne _0809D468
	ldr r0, =0x00000896
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0809D468
	movs r0, 0x1
	b _0809D46A
	.pool
_0809D468:
	movs r0, 0
_0809D46A:
	pop {r1}
	bx r1
	thumb_func_end IsNationalPokedexEnabled

	thumb_func_start DisableMysteryGift
DisableMysteryGift: @ 809D470
	push {lr}
	ldr r0, =0x000008ac
	bl FlagReset
	pop {r0}
	bx r0
	.pool
	thumb_func_end DisableMysteryGift

	thumb_func_start EnableMysteryGift
EnableMysteryGift: @ 809D480
	push {lr}
	ldr r0, =0x000008ac
	bl FlagSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end EnableMysteryGift

	thumb_func_start IsMysteryGiftEnabled
IsMysteryGiftEnabled: @ 809D490
	push {lr}
	ldr r0, =0x000008ac
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end IsMysteryGiftEnabled

	thumb_func_start sub_809D4A4
sub_809D4A4: @ 809D4A4
	push {lr}
	ldr r0, =0x000008db
	bl FlagReset
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809D4A4

	thumb_func_start sub_809D4B4
sub_809D4B4: @ 809D4B4
	push {lr}
	ldr r0, =0x000008db
	bl FlagSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809D4B4

	thumb_func_start sub_809D4C4
sub_809D4C4: @ 809D4C4
	push {lr}
	ldr r0, =0x000008db
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809D4C4

	thumb_func_start sub_809D4D8
sub_809D4D8: @ 809D4D8
	push {lr}
	movs r0, 0xF2
	lsls r0, 1
	bl FlagReset
	ldr r0, =0x000001e5
	bl FlagReset
	movs r0, 0xF3
	lsls r0, 1
	bl FlagReset
	ldr r0, =0x000001e7
	bl FlagReset
	movs r0, 0xF4
	lsls r0, 1
	bl FlagReset
	ldr r0, =0x000001e9
	bl FlagReset
	movs r0, 0xF5
	lsls r0, 1
	bl FlagReset
	ldr r0, =0x000001eb
	bl FlagReset
	movs r0, 0xF6
	lsls r0, 1
	bl FlagReset
	ldr r0, =0x000001ed
	bl FlagReset
	movs r0, 0xF7
	lsls r0, 1
	bl FlagReset
	ldr r0, =0x000001ef
	bl FlagReset
	movs r0, 0xF8
	lsls r0, 1
	bl FlagReset
	ldr r0, =0x000001f1
	bl FlagReset
	movs r0, 0xF9
	lsls r0, 1
	bl FlagReset
	ldr r0, =0x000001f3
	bl FlagReset
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809D4D8

	thumb_func_start sub_809D570
sub_809D570: @ 809D570
	push {lr}
	ldr r0, =0x000040dd
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040de
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040df
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040e0
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040e1
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040e2
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040e3
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040e4
	movs r1, 0
	bl VarSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809D570

	thumb_func_start sub_809D5D8
sub_809D5D8: @ 809D5D8
	push {lr}
	ldr r0, =0x0000402c
	movs r1, 0
	bl VarSet
	ldr r0, =0x000008c2
	bl FlagReset
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809D5D8

	thumb_func_start sub_809D5F4
sub_809D5F4: @ 809D5F4
	push {lr}
	ldr r0, =0x0000402c
	movs r1, 0x92
	lsls r1, 4
	bl VarSet
	ldr r0, =0x000008c2
	bl FlagSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809D5F4

	thumb_func_start sub_809D614
sub_809D614: @ 809D614
	push {lr}
	ldr r0, =0x000008c2
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0809D640
	ldr r0, =0x0000402c
	bl VarGet
	lsls r0, 16
	movs r1, 0x92
	lsls r1, 20
	cmp r0, r1
	bne _0809D640
	movs r0, 0x1
	b _0809D642
	.pool
_0809D640:
	movs r0, 0
_0809D642:
	pop {r1}
	bx r1
	thumb_func_end sub_809D614

	thumb_func_start GetVarPointer
@ u16 *GetVarPointer(u16 varId)
GetVarPointer: @ 809D648
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	adds r2, r1, 0
	ldr r0, =0x00003fff
	cmp r1, r0
	bhi _0809D660
	movs r0, 0
	b _0809D688
	.pool
_0809D660:
	lsls r0, r1, 16
	cmp r0, 0
	bge _0809D67C
	ldr r0, =gUnknown_081DBA0C
	ldr r2, =0xffff8000
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	b _0809D688
	.pool
_0809D67C:
	ldr r0, =gSaveBlock1Ptr
	lsls r1, r2, 1
	ldr r2, =0xffff939c
	adds r1, r2
	ldr r0, [r0]
	adds r0, r1
_0809D688:
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetVarPointer

	thumb_func_start VarGet
@ u16 VarGet(u16 varId)
VarGet: @ 809D694
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	bl GetVarPointer
	cmp r0, 0
	beq _0809D6A8
	ldrh r0, [r0]
	b _0809D6AA
_0809D6A8:
	adds r0, r4, 0
_0809D6AA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end VarGet

	thumb_func_start VarSet
@ bool8 VarSet(u16 varId, u16 value)
VarSet: @ 809D6B0
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r4, r1, 16
	bl GetVarPointer
	cmp r0, 0
	beq _0809D6C8
	strh r4, [r0]
	movs r0, 0x1
	b _0809D6CA
_0809D6C8:
	movs r0, 0
_0809D6CA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end VarSet

	thumb_func_start VarGetFieldObjectGraphicsId
@ u8 VarGetFieldObjectGraphicsId(u8 index)
VarGetFieldObjectGraphicsId: @ 809D6D0
	push {lr}
	lsls r0, 24
	lsrs r0, 8
	ldr r1, =0x40100000
	adds r0, r1
	lsrs r0, 16
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end VarGetFieldObjectGraphicsId

	thumb_func_start GetFlagPointer
@ u8 *GetFlagPointer(u16 flagId)
GetFlagPointer: @ 809D6EC
	push {lr}
	lsls r1, r0, 16
	lsrs r2, r1, 16
	adds r3, r2, 0
	cmp r2, 0
	bne _0809D6FC
	movs r0, 0
	b _0809D72E
_0809D6FC:
	ldr r0, =0x00003fff
	cmp r2, r0
	bhi _0809D71C
	ldr r0, =gSaveBlock1Ptr
	lsrs r1, 19
	ldr r2, =0x00001270
	adds r1, r2
	ldr r0, [r0]
	b _0809D72C
	.pool
_0809D71C:
	ldr r1, =0xffffc000
	adds r0, r3, r1
	cmp r0, 0
	bge _0809D728
	ldr r2, =0xffffc007
	adds r0, r3, r2
_0809D728:
	asrs r0, 3
	ldr r1, =gUnknown_020375FC
_0809D72C:
	adds r0, r1
_0809D72E:
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetFlagPointer

	thumb_func_start FlagSet
@ bool8 FlagSet(u16 flagId)
FlagSet: @ 809D740
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	bl GetFlagPointer
	adds r2, r0, 0
	cmp r2, 0
	beq _0809D760
	movs r0, 0x7
	ands r0, r4
	movs r1, 0x1
	lsls r1, r0
	ldrb r0, [r2]
	orrs r1, r0
	strb r1, [r2]
_0809D760:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end FlagSet

	thumb_func_start FlagReset
@ bool8 FlagReset(u16 flagId)
FlagReset: @ 809D768
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	bl GetFlagPointer
	adds r2, r0, 0
	cmp r2, 0
	beq _0809D788
	movs r0, 0x7
	ands r0, r4
	movs r1, 0x1
	lsls r1, r0
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
_0809D788:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end FlagReset

	thumb_func_start FlagGet
@ bool8 FlagGet(u16 flagId)
FlagGet: @ 809D790
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	bl GetFlagPointer
	cmp r0, 0
	beq _0809D7B4
	ldrb r0, [r0]
	movs r1, 0x7
	ands r1, r4
	asrs r0, r1
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809D7B4
	movs r0, 0x1
	b _0809D7B6
_0809D7B4:
	movs r0, 0
_0809D7B6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end FlagGet

	.align 2, 0 @ Don't pad with nop.
