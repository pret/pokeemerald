@ the third big chunk of data

	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_08589A08:: @ 8589A08
	.4byte BuyMenuTryMakePurchase
	.4byte BuyMenuReturnToItemList

gUnknown_08589A10:: @ 8589A10
	.4byte gUnknown_085E93C7
	.4byte HandleShopMenuBuy
	.4byte gUnknown_085E93CB
	.4byte HandleShopMenuSell
	.4byte gUnknown_085E93D0
	.4byte HandleShopMenuQuit

gUnknown_08589A28:: @ 8589A28
	.4byte gUnknown_085E93C7
	.4byte HandleShopMenuBuy
	.4byte gUnknown_085E93D0
	.4byte HandleShopMenuQuit

gUnknown_08589A38:: @ 8589A38
	.byte 0, 2, 1, 9, 6, 15, 8, 0, 0, 2, 1, 9, 4, 15, 8, 0

gUnknown_08589A48:: @ 8589A48
	.byte 0, 0, 0, 0, 0x3D, 0, 14, 8, 21, 1, 14, 8, 0, 0, 0, 0, 1, 0, 8, 0, 33, 48, 0, 7

gUnknown_08589A60:: @ 8589A60
	.4byte 0x1F8
    .4byte 0x11E1
    .4byte 0x21D2
    .4byte 0x31C3

gUnknown_08589A70:: @ 8589A70
	.byte 0
    .byte 1
    .byte 1
    .byte 10
    .byte 2
    .byte 15
    .2byte 30
    .byte 0
    .byte 14
    .byte 2
    .byte 15
    .byte 16
    .byte 15
    .2byte 50
    .byte 0
    .byte 0
    .byte 13
    .byte 14
    .byte 6
    .byte 15
    .2byte 0x122
    .byte 0
    .byte 1
    .byte 11
    .byte 12
    .byte 2
    .byte 15
    .2byte 0x176
    .byte 0
    .byte 18
    .byte 11
    .byte 10
    .byte 2
    .byte 15
    .2byte 0x18E
    .byte 0
    .byte 2
    .byte 15
    .byte 27
    .byte 4
    .byte 15
    .2byte 0x1A2
    .byte 0xFF
    .byte 0
    .byte 0
    .byte 0
    .byte 0
    .byte 0
    .2byte 0

gUnknown_08589AA8:: @ 8589AA8
	.byte 0
    .byte 21
    .byte 9
    .byte 5
    .byte 4
    .byte 15
    .2byte 0x20E

gUnknown_08589AB0:: @ 8589AB0
	.byte 1, 2, 3

gUnknown_08589AB3:: @ 8589AB3
	.byte 0, 2, 3, 0, 3, 2, 0

gUnknown_08589ABA:: @ 8589ABA
	.2byte 0x284, 0x282, 0x280

gUnknown_08589AC0:: @ 8589AC0
	.2byte 0x285, 0x283, 0x281

gUnknown_08589AC6:: @ 8589AC6
	.2byte 0x28C, 0x28A, 0x288

gUnknown_08589ACC:: @ 8589ACC
	.2byte 0x28D, 0x28B, 0x289

gUnknown_08589AD2:: @ 8589AD2
	.2byte 0x2A0, 0x2A2, 0x2A4

gUnknown_08589AD8:: @ 8589AD8
	.2byte 0x2A1, 0x2A3, 0x2A5

gUnknown_08589ADE:: @ 8589ADE
	.2byte 0x2A8, 0x2AA, 0x2AC
