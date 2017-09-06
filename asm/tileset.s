	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80A0954
@ void sub_80A0954()
sub_80A0954: @ 80A0954
	push {lr}
	sub sp, 0x4
	ldr r1, =gUnknown_03000F34
	movs r0, 0
	strb r0, [r1]
	movs r0, 0
	str r0, [sp]
	ldr r1, =gUnknown_02037624
	ldr r2, =0x0500003c
	mov r0, sp
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A0954

	thumb_func_start sub_80A0980
sub_80A0980: @ 80A0980
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r2, 16
	lsrs r6, r2, 16
	ldr r3, =gUnknown_03000F34
	ldrb r0, [r3]
	cmp r0, 0x13
	bhi _080A09C0
	ldr r2, =gUnknown_02037624
	adds r1, r0, 0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	str r4, [r0]
	ldrb r1, [r3]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r1, r2, 0x4
	adds r0, r1
	str r5, [r0]
	ldrb r1, [r3]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r6, [r0, 0x8]
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
_080A09C0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A0980

	thumb_func_start sub_80A09D0
sub_80A09D0: @ 80A09D0
	push {r4-r6,lr}
	movs r3, 0
	ldr r4, =gUnknown_03000F34
	adds r6, r4, 0
	ldrb r0, [r4]
	cmp r3, r0
	bge _080A0A02
	ldr r2, =0x040000d4
	ldr r1, =gUnknown_02037624
	movs r5, 0x80
	lsls r5, 24
_080A09E6:
	ldr r0, [r1]
	str r0, [r2]
	ldr r0, [r1, 0x4]
	str r0, [r2, 0x4]
	ldrh r0, [r1, 0x8]
	lsrs r0, 1
	orrs r0, r5
	str r0, [r2, 0x8]
	ldr r0, [r2, 0x8]
	adds r1, 0xC
	adds r3, 0x1
	ldrb r0, [r4]
	cmp r3, r0
	blt _080A09E6
_080A0A02:
	movs r0, 0
	strb r0, [r6]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A09D0

	thumb_func_start cur_mapheader_run_tileset_funcs_after_some_cpuset
cur_mapheader_run_tileset_funcs_after_some_cpuset: @ 80A0A18
	push {lr}
	bl sub_80A0954
	bl cur_mapheader_run_tileset1_func
	bl cur_mapheader_run_tileset2_func
	pop {r0}
	bx r0
	thumb_func_end cur_mapheader_run_tileset_funcs_after_some_cpuset

	thumb_func_start sub_80A0A2C
sub_80A0A2C: @ 80A0A2C
	push {lr}
	bl cur_mapheader_run_tileset2_func
	pop {r0}
	bx r0
	thumb_func_end sub_80A0A2C

	thumb_func_start sub_80A0A38
sub_80A0A38: @ 80A0A38
	push {r4,lr}
	bl sub_80A0954
	ldr r2, =gUnknown_03000F36
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	ldr r1, =gUnknown_03000F38
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r1]
	cmp r0, r1
	bcc _080A0A56
	movs r0, 0
	strh r0, [r2]
_080A0A56:
	ldr r4, =gUnknown_03000F3A
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	ldr r1, =gUnknown_03000F3C
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r1]
	cmp r0, r1
	bcc _080A0A6E
	movs r0, 0
	strh r0, [r4]
_080A0A6E:
	ldr r0, =gUnknown_03000F40
	ldr r1, [r0]
	cmp r1, 0
	beq _080A0A7C
	ldrh r0, [r2]
	bl _call_via_r1
_080A0A7C:
	ldr r0, =gUnknown_03000F44
	ldr r1, [r0]
	cmp r1, 0
	beq _080A0A8A
	ldrh r0, [r4]
	bl _call_via_r1
_080A0A8A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A0A38

	thumb_func_start cur_mapheader_run_tileset1_func
cur_mapheader_run_tileset1_func: @ 80A0AA8
	push {lr}
	ldr r0, =gUnknown_03000F36
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_03000F38
	strh r1, [r0]
	ldr r1, =gUnknown_03000F40
	movs r0, 0
	str r0, [r1]
	ldr r0, =gMapHeader
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	cmp r0, 0
	beq _080A0ACE
	ldr r0, [r0, 0x14]
	cmp r0, 0
	beq _080A0ACE
	bl _call_via_r0
_080A0ACE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end cur_mapheader_run_tileset1_func

	thumb_func_start cur_mapheader_run_tileset2_func
cur_mapheader_run_tileset2_func: @ 80A0AE4
	push {lr}
	ldr r0, =gUnknown_03000F3A
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_03000F3C
	strh r1, [r0]
	ldr r1, =gUnknown_03000F44
	movs r0, 0
	str r0, [r1]
	ldr r0, =gMapHeader
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	cmp r0, 0
	beq _080A0B0A
	ldr r0, [r0, 0x14]
	cmp r0, 0
	beq _080A0B0A
	bl _call_via_r0
_080A0B0A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end cur_mapheader_run_tileset2_func

	thumb_func_start TilesetCb_General
TilesetCb_General: @ 80A0B20
	ldr r1, =gUnknown_03000F36
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F38
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F40
	ldr r0, =sub_80A0B70
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_General

	thumb_func_start TilesetCb_InsideBuilding
TilesetCb_InsideBuilding: @ 80A0B48
	ldr r1, =gUnknown_03000F36
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F38
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F40
	ldr r0, =sub_80A0BB4
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_InsideBuilding

	thumb_func_start sub_80A0B70
sub_80A0B70: @ 80A0B70
	push {r4,r5,lr}
	lsls r5, r0, 16
	movs r0, 0xF0
	lsls r0, 12
	ands r0, r5
	lsrs r4, r0, 16
	cmp r4, 0
	bne _080A0B86
	lsrs r0, r5, 20
	bl sub_80A0BCC
_080A0B86:
	cmp r4, 0x1
	bne _080A0B90
	lsrs r0, r5, 20
	bl sub_80A0BF4
_080A0B90:
	cmp r4, 0x2
	bne _080A0B9A
	lsrs r0, r5, 20
	bl sub_80A0C1C
_080A0B9A:
	cmp r4, 0x3
	bne _080A0BA4
	lsrs r0, r5, 20
	bl sub_80A0C44
_080A0BA4:
	cmp r4, 0x4
	bne _080A0BAE
	lsrs r0, r5, 20
	bl sub_80A12AC
_080A0BAE:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80A0B70

	thumb_func_start sub_80A0BB4
sub_80A0BB4: @ 80A0BB4
	push {lr}
	lsls r1, r0, 16
	movs r0, 0xE0
	lsls r0, 11
	ands r0, r1
	cmp r0, 0
	bne _080A0BC8
	lsrs r0, r1, 19
	bl sub_80A1688
_080A0BC8:
	pop {r0}
	bx r0
	thumb_func_end sub_80A0BB4

	thumb_func_start sub_80A0BCC
sub_80A0BCC: @ 80A0BCC
	push {lr}
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	ldr r0, =gUnknown_08510764
	lsrs r1, 14
	adds r1, r0
	ldr r0, [r1]
	ldr r1, =0x06003f80
	movs r2, 0x80
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A0BCC

	thumb_func_start sub_80A0BF4
sub_80A0BF4: @ 80A0BF4
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x7
	ands r0, r1
	ldr r1, =gUnknown_08512574
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x06003600
	movs r2, 0xF0
	lsls r2, 2
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A0BF4

	thumb_func_start sub_80A0C1C
sub_80A0C1C: @ 80A0C1C
	push {lr}
	lsls r0, 16
	movs r1, 0xE0
	lsls r1, 11
	ands r1, r0
	ldr r0, =gUnknown_08512E54
	lsrs r1, 14
	adds r1, r0
	ldr r0, [r1]
	ldr r1, =0x06003a00
	movs r2, 0xA0
	lsls r2, 1
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A0C1C

	thumb_func_start sub_80A0C44
sub_80A0C44: @ 80A0C44
	push {lr}
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	ldr r0, =gUnknown_08513174
	lsrs r1, 14
	adds r1, r0
	ldr r0, [r1]
	ldr r1, =0x06003e00
	movs r2, 0xC0
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A0C44

	thumb_func_start TilesetCb_Petalburg
TilesetCb_Petalburg: @ 80A0C6C
	ldr r1, =gUnknown_03000F3A
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F3C
	ldr r0, =gUnknown_03000F38
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03000F44
	movs r0, 0
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_Petalburg

	thumb_func_start TilesetCb_Rustboro
TilesetCb_Rustboro: @ 80A0C94
	ldr r1, =gUnknown_03000F3A
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F3C
	ldr r0, =gUnknown_03000F38
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03000F44
	ldr r0, =sub_80A103C
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_Rustboro

	thumb_func_start TilesetCb_Dewford
TilesetCb_Dewford: @ 80A0CC0
	ldr r1, =gUnknown_03000F3A
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F3C
	ldr r0, =gUnknown_03000F38
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03000F44
	ldr r0, =sub_80A10B8
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_Dewford

	thumb_func_start TilesetCb_Slateport
TilesetCb_Slateport: @ 80A0CEC
	ldr r1, =gUnknown_03000F3A
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F3C
	ldr r0, =gUnknown_03000F38
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03000F44
	ldr r0, =sub_80A10D0
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_Slateport

	thumb_func_start TilesetCb_Mauville
TilesetCb_Mauville: @ 80A0D18
	ldr r1, =gUnknown_03000F3A
	ldr r0, =gUnknown_03000F36
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03000F3C
	ldr r0, =gUnknown_03000F38
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03000F44
	ldr r0, =sub_80A10E8
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_Mauville

	thumb_func_start TilesetCb_Lavaridge
TilesetCb_Lavaridge: @ 80A0D48
	ldr r1, =gUnknown_03000F3A
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F3C
	ldr r0, =gUnknown_03000F38
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03000F44
	ldr r0, =sub_80A115C
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_Lavaridge

	thumb_func_start TilesetCb_Fallarbor
TilesetCb_Fallarbor: @ 80A0D74
	ldr r1, =gUnknown_03000F3A
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F3C
	ldr r0, =gUnknown_03000F38
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03000F44
	movs r0, 0
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_Fallarbor

	thumb_func_start TilesetCb_Fortree
TilesetCb_Fortree: @ 80A0D9C
	ldr r1, =gUnknown_03000F3A
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F3C
	ldr r0, =gUnknown_03000F38
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03000F44
	movs r0, 0
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_Fortree

	thumb_func_start TilesetCb_Lilycove
TilesetCb_Lilycove: @ 80A0DC4
	ldr r1, =gUnknown_03000F3A
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F3C
	ldr r0, =gUnknown_03000F38
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03000F44
	movs r0, 0
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_Lilycove

	thumb_func_start TilesetCb_Mossdeep
TilesetCb_Mossdeep: @ 80A0DEC
	ldr r1, =gUnknown_03000F3A
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F3C
	ldr r0, =gUnknown_03000F38
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03000F44
	movs r0, 0
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_Mossdeep

	thumb_func_start TilesetCb_EverGrande
TilesetCb_EverGrande: @ 80A0E14
	ldr r1, =gUnknown_03000F3A
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F3C
	ldr r0, =gUnknown_03000F38
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03000F44
	ldr r0, =sub_80A1188
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_EverGrande

	thumb_func_start TilesetCb_Pacifidlog
TilesetCb_Pacifidlog: @ 80A0E40
	ldr r1, =gUnknown_03000F3A
	ldr r0, =gUnknown_03000F36
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03000F3C
	ldr r0, =gUnknown_03000F38
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03000F44
	ldr r0, =sub_80A11FC
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_Pacifidlog

	thumb_func_start TilesetCb_Sootopolis
TilesetCb_Sootopolis: @ 80A0E70
	ldr r1, =gUnknown_03000F3A
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F3C
	ldr r0, =gUnknown_03000F38
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03000F44
	ldr r0, =sub_80A122C
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_Sootopolis

	thumb_func_start TilesetCb_BattleFrontierOutsideWest
TilesetCb_BattleFrontierOutsideWest: @ 80A0E9C
	ldr r1, =gUnknown_03000F3A
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F3C
	ldr r0, =gUnknown_03000F38
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03000F44
	ldr r0, =sub_80A127C
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_BattleFrontierOutsideWest

	thumb_func_start TilesetCb_BattleFrontierOutsideEast
TilesetCb_BattleFrontierOutsideEast: @ 80A0EC8
	ldr r1, =gUnknown_03000F3A
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F3C
	ldr r0, =gUnknown_03000F38
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03000F44
	ldr r0, =sub_80A1294
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_BattleFrontierOutsideEast

	thumb_func_start TilesetCb_Underwater
TilesetCb_Underwater: @ 80A0EF4
	ldr r1, =gUnknown_03000F3A
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F3C
	movs r0, 0x80
	strh r0, [r1]
	ldr r1, =gUnknown_03000F44
	ldr r0, =sub_80A1244
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_Underwater

	thumb_func_start TilesetCb_SootopolisGym
TilesetCb_SootopolisGym: @ 80A0F18
	ldr r1, =gUnknown_03000F3A
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F3C
	movs r0, 0xF0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F44
	ldr r0, =sub_80A15D8
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_SootopolisGym

	thumb_func_start TilesetCb_Cave
TilesetCb_Cave: @ 80A0F3C
	ldr r1, =gUnknown_03000F3A
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F3C
	ldr r0, =gUnknown_03000F38
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03000F44
	ldr r0, =sub_80A1260
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_Cave

	thumb_func_start TilesetCb_EliteFour
TilesetCb_EliteFour: @ 80A0F68
	ldr r1, =gUnknown_03000F3A
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F3C
	movs r0, 0x80
	strh r0, [r1]
	ldr r1, =gUnknown_03000F44
	ldr r0, =sub_80A15F0
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_EliteFour

	thumb_func_start TilesetCb_MauvilleGym
TilesetCb_MauvilleGym: @ 80A0F8C
	ldr r1, =gUnknown_03000F3A
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F3C
	ldr r0, =gUnknown_03000F38
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03000F44
	ldr r0, =sub_80A15C0
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_MauvilleGym

	thumb_func_start TilesetCb_BikeShop
TilesetCb_BikeShop: @ 80A0FB8
	ldr r1, =gUnknown_03000F3A
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F3C
	ldr r0, =gUnknown_03000F38
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03000F44
	ldr r0, =sub_80A161C
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_BikeShop

	thumb_func_start TilesetCb_BattlePyramid
TilesetCb_BattlePyramid: @ 80A0FE4
	ldr r1, =gUnknown_03000F3A
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F3C
	ldr r0, =gUnknown_03000F38
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03000F44
	ldr r0, =sub_80A1634
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_BattlePyramid

	thumb_func_start TilesetCb_BattleDome
TilesetCb_BattleDome: @ 80A1010
	ldr r1, =gUnknown_03000F3A
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000F3C
	ldr r0, =gUnknown_03000F38
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_03000F44
	ldr r0, =sub_80A1658
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end TilesetCb_BattleDome

	thumb_func_start sub_80A103C
sub_80A103C: @ 80A103C
	push {r4-r6,lr}
	lsls r5, r0, 16
	movs r0, 0xE0
	lsls r0, 11
	ands r0, r5
	lsrs r6, r0, 16
	cmp r6, 0
	bne _080A105C
	lsrs r4, r5, 19
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A1434
	adds r0, r4, 0
	bl sub_80A1470
_080A105C:
	cmp r6, 0x1
	bne _080A1068
	lsrs r0, r5, 19
	movs r1, 0x1
	bl sub_80A1434
_080A1068:
	cmp r6, 0x2
	bne _080A1074
	lsrs r0, r5, 19
	movs r1, 0x2
	bl sub_80A1434
_080A1074:
	cmp r6, 0x3
	bne _080A1080
	lsrs r0, r5, 19
	movs r1, 0x3
	bl sub_80A1434
_080A1080:
	cmp r6, 0x4
	bne _080A108C
	lsrs r0, r5, 19
	movs r1, 0x4
	bl sub_80A1434
_080A108C:
	cmp r6, 0x5
	bne _080A1098
	lsrs r0, r5, 19
	movs r1, 0x5
	bl sub_80A1434
_080A1098:
	cmp r6, 0x6
	bne _080A10A4
	lsrs r0, r5, 19
	movs r1, 0x6
	bl sub_80A1434
_080A10A4:
	cmp r6, 0x7
	bne _080A10B0
	lsrs r0, r5, 19
	movs r1, 0x7
	bl sub_80A1434
_080A10B0:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80A103C

	thumb_func_start sub_80A10B8
sub_80A10B8: @ 80A10B8
	push {lr}
	lsls r1, r0, 16
	movs r0, 0xE0
	lsls r0, 11
	ands r0, r1
	cmp r0, 0
	bne _080A10CC
	lsrs r0, r1, 19
	bl sub_80A1520
_080A10CC:
	pop {r0}
	bx r0
	thumb_func_end sub_80A10B8

	thumb_func_start sub_80A10D0
sub_80A10D0: @ 80A10D0
	push {lr}
	lsls r1, r0, 16
	movs r0, 0xF0
	lsls r0, 12
	ands r0, r1
	cmp r0, 0
	bne _080A10E4
	lsrs r0, r1, 20
	bl sub_80A1598
_080A10E4:
	pop {r0}
	bx r0
	thumb_func_end sub_80A10D0

	thumb_func_start sub_80A10E8
sub_80A10E8: @ 80A10E8
	push {r4,r5,lr}
	lsls r4, r0, 16
	movs r0, 0xE0
	lsls r0, 11
	ands r0, r4
	lsrs r5, r0, 16
	cmp r5, 0
	bne _080A1100
	lsrs r0, r4, 19
	movs r1, 0
	bl sub_80A1394
_080A1100:
	cmp r5, 0x1
	bne _080A110C
	lsrs r0, r4, 19
	movs r1, 0x1
	bl sub_80A1394
_080A110C:
	cmp r5, 0x2
	bne _080A1118
	lsrs r0, r4, 19
	movs r1, 0x2
	bl sub_80A1394
_080A1118:
	cmp r5, 0x3
	bne _080A1124
	lsrs r0, r4, 19
	movs r1, 0x3
	bl sub_80A1394
_080A1124:
	cmp r5, 0x4
	bne _080A1130
	lsrs r0, r4, 19
	movs r1, 0x4
	bl sub_80A1394
_080A1130:
	cmp r5, 0x5
	bne _080A113C
	lsrs r0, r4, 19
	movs r1, 0x5
	bl sub_80A1394
_080A113C:
	cmp r5, 0x6
	bne _080A1148
	lsrs r0, r4, 19
	movs r1, 0x6
	bl sub_80A1394
_080A1148:
	cmp r5, 0x7
	bne _080A1154
	lsrs r0, r4, 19
	movs r1, 0x7
	bl sub_80A1394
_080A1154:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80A10E8

	thumb_func_start sub_80A115C
sub_80A115C: @ 80A115C
	push {r4,r5,lr}
	lsls r4, r0, 16
	movs r0, 0xF0
	lsls r0, 12
	ands r0, r4
	lsrs r5, r0, 16
	cmp r5, 0
	bne _080A1176
	lsrs r0, r4, 20
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A12D4
_080A1176:
	cmp r5, 0x1
	bne _080A1180
	lsrs r0, r4, 20
	bl sub_80A1498
_080A1180:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80A115C

	thumb_func_start sub_80A1188
sub_80A1188: @ 80A1188
	push {r4,r5,lr}
	lsls r4, r0, 16
	movs r0, 0xE0
	lsls r0, 11
	ands r0, r4
	lsrs r5, r0, 16
	cmp r5, 0
	bne _080A11A0
	lsrs r0, r4, 19
	movs r1, 0
	bl sub_80A14C0
_080A11A0:
	cmp r5, 0x1
	bne _080A11AC
	lsrs r0, r4, 19
	movs r1, 0x1
	bl sub_80A14C0
_080A11AC:
	cmp r5, 0x2
	bne _080A11B8
	lsrs r0, r4, 19
	movs r1, 0x2
	bl sub_80A14C0
_080A11B8:
	cmp r5, 0x3
	bne _080A11C4
	lsrs r0, r4, 19
	movs r1, 0x3
	bl sub_80A14C0
_080A11C4:
	cmp r5, 0x4
	bne _080A11D0
	lsrs r0, r4, 19
	movs r1, 0x4
	bl sub_80A14C0
_080A11D0:
	cmp r5, 0x5
	bne _080A11DC
	lsrs r0, r4, 19
	movs r1, 0x5
	bl sub_80A14C0
_080A11DC:
	cmp r5, 0x6
	bne _080A11E8
	lsrs r0, r4, 19
	movs r1, 0x6
	bl sub_80A14C0
_080A11E8:
	cmp r5, 0x7
	bne _080A11F4
	lsrs r0, r4, 19
	movs r1, 0x7
	bl sub_80A14C0
_080A11F4:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80A1188

	thumb_func_start sub_80A11FC
sub_80A11FC: @ 80A11FC
	push {r4,r5,lr}
	lsls r4, r0, 16
	movs r0, 0xF0
	lsls r0, 12
	ands r0, r4
	lsrs r5, r0, 16
	cmp r5, 0
	bne _080A1216
	lsrs r0, r4, 20
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A131C
_080A1216:
	cmp r5, 0x1
	bne _080A1224
	lsrs r0, r4, 20
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A136C
_080A1224:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80A11FC

	thumb_func_start sub_80A122C
sub_80A122C: @ 80A122C
	push {lr}
	lsls r1, r0, 16
	movs r0, 0xF0
	lsls r0, 12
	ands r0, r1
	cmp r0, 0
	bne _080A1240
	lsrs r0, r1, 20
	bl sub_80A1798
_080A1240:
	pop {r0}
	bx r0
	thumb_func_end sub_80A122C

	thumb_func_start sub_80A1244
sub_80A1244: @ 80A1244
	push {lr}
	lsls r1, r0, 16
	movs r0, 0xF0
	lsls r0, 12
	ands r0, r1
	cmp r0, 0
	bne _080A125C
	lsrs r0, r1, 20
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A1344
_080A125C:
	pop {r0}
	bx r0
	thumb_func_end sub_80A1244

	thumb_func_start sub_80A1260
sub_80A1260: @ 80A1260
	push {lr}
	lsls r1, r0, 16
	movs r0, 0xF0
	lsls r0, 12
	ands r0, r1
	lsrs r0, 16
	cmp r0, 0x1
	bne _080A1276
	lsrs r0, r1, 20
	bl sub_80A14F8
_080A1276:
	pop {r0}
	bx r0
	thumb_func_end sub_80A1260

	thumb_func_start sub_80A127C
sub_80A127C: @ 80A127C
	push {lr}
	lsls r1, r0, 16
	movs r0, 0xE0
	lsls r0, 11
	ands r0, r1
	cmp r0, 0
	bne _080A1290
	lsrs r0, r1, 19
	bl sub_80A1548
_080A1290:
	pop {r0}
	bx r0
	thumb_func_end sub_80A127C

	thumb_func_start sub_80A1294
sub_80A1294: @ 80A1294
	push {lr}
	lsls r1, r0, 16
	movs r0, 0xE0
	lsls r0, 11
	ands r0, r1
	cmp r0, 0
	bne _080A12A8
	lsrs r0, r1, 19
	bl sub_80A1570
_080A12A8:
	pop {r0}
	bx r0
	thumb_func_end sub_80A1294

	thumb_func_start sub_80A12AC
sub_80A12AC: @ 80A12AC
	push {lr}
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	ldr r0, =gUnknown_08513684
	lsrs r1, 14
	adds r1, r0
	ldr r0, [r1]
	ldr r1, =0x06003c00
	movs r2, 0xA0
	lsls r2, 1
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A12AC

	thumb_func_start sub_80A12D4
sub_80A12D4: @ 80A12D4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x3
	ands r0, r4
	ldr r5, =gUnknown_08513894
	lsls r0, 2
	adds r0, r5
	ldr r0, [r0]
	ldr r1, =0x06006400
	movs r2, 0x80
	bl sub_80A0980
	adds r1, r4, 0x2
	adds r0, r1, 0
	asrs r0, 2
	lsls r0, 2
	subs r0, r1, r0
	lsls r0, 24
	lsrs r0, 22
	adds r0, r5
	ldr r0, [r0]
	ldr r1, =0x06006480
	movs r2, 0x80
	bl sub_80A0980
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A12D4

	thumb_func_start sub_80A131C
sub_80A131C: @ 80A131C
	push {lr}
	lsls r0, 24
	movs r1, 0xC0
	lsls r1, 18
	ands r1, r0
	ldr r0, =gUnknown_085143E4
	lsrs r1, 22
	adds r1, r0
	ldr r0, [r1]
	ldr r1, =0x06007a00
	movs r2, 0xF0
	lsls r2, 2
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A131C

	thumb_func_start sub_80A1344
sub_80A1344: @ 80A1344
	push {lr}
	lsls r0, 24
	movs r1, 0xC0
	lsls r1, 18
	ands r1, r0
	ldr r0, =gUnknown_085145F4
	lsrs r1, 22
	adds r1, r0
	ldr r0, [r1]
	ldr r1, =0x06007e00
	movs r2, 0x80
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A1344

	thumb_func_start sub_80A136C
sub_80A136C: @ 80A136C
	push {lr}
	lsls r0, 24
	movs r1, 0xE0
	lsls r1, 19
	ands r1, r0
	ldr r0, =gUnknown_08514E04
	lsrs r1, 22
	adds r1, r0
	ldr r0, [r1]
	ldr r1, =0x06007e00
	movs r2, 0x80
	lsls r2, 1
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A136C

	thumb_func_start sub_80A1394
sub_80A1394: @ 80A1394
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r1, 24
	lsrs r6, r1, 24
	subs r0, r5, r6
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0xB
	bhi _080A13F0
	adds r0, r5, 0
	movs r1, 0xC
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 16
	ldr r0, =gUnknown_08515384
	lsrs r4, 14
	adds r0, r4, r0
	ldr r0, [r0]
	ldr r1, =gUnknown_08515344
	lsls r5, r6, 2
	adds r1, r5, r1
	ldr r1, [r1]
	movs r2, 0x80
	bl sub_80A0980
	ldr r0, =gUnknown_085153B4
	adds r4, r0
	ldr r0, [r4]
	ldr r1, =gUnknown_08515364
	adds r5, r1
	ldr r1, [r5]
	movs r2, 0x80
	bl sub_80A0980
	b _080A141C
	.pool
_080A13F0:
	movs r0, 0x3
	ands r5, r0
	ldr r0, =gUnknown_085153E4
	lsls r5, 2
	adds r0, r5, r0
	ldr r0, [r0]
	ldr r1, =gUnknown_08515344
	lsls r4, r6, 2
	adds r1, r4, r1
	ldr r1, [r1]
	movs r2, 0x80
	bl sub_80A0980
	ldr r0, =gUnknown_085153F4
	adds r5, r0
	ldr r0, [r5]
	ldr r1, =gUnknown_08515364
	adds r4, r1
	ldr r1, [r4]
	movs r2, 0x80
	bl sub_80A0980
_080A141C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A1394

	thumb_func_start sub_80A1434
sub_80A1434: @ 80A1434
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 24
	lsrs r3, r1, 24
	subs r0, r3
	lsls r0, 16
	movs r1, 0xE0
	lsls r1, 11
	ands r1, r0
	ldr r0, =gUnknown_08515824
	lsrs r1, 14
	adds r1, r0
	ldr r2, [r1]
	cmp r2, 0
	beq _080A1464
	ldr r0, =gUnknown_08515804
	lsls r1, r3, 2
	adds r1, r0
	ldr r1, [r1]
	adds r0, r2, 0
	movs r2, 0x80
	bl sub_80A0980
_080A1464:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A1434

	thumb_func_start sub_80A1470
sub_80A1470: @ 80A1470
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	ands r0, r1
	ldr r1, =gUnknown_08515964
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x06007800
	movs r2, 0x80
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A1470

	thumb_func_start sub_80A1498
sub_80A1498: @ 80A1498
	push {lr}
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	ldr r0, =gUnknown_08515D8C
	lsrs r1, 14
	adds r1, r0
	ldr r0, [r1]
	ldr r1, =0x06005400
	movs r2, 0x80
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A1498

	thumb_func_start sub_80A14C0
sub_80A14C0: @ 80A14C0
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 24
	lsrs r1, 24
	subs r0, r1
	lsls r0, 16
	movs r2, 0xE0
	lsls r2, 11
	ands r2, r0
	ldr r0, =gUnknown_085161DC
	lsrs r2, 14
	adds r2, r0
	ldr r0, [r2]
	ldr r2, =gUnknown_085161BC
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	movs r2, 0x80
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A14C0

	thumb_func_start sub_80A14F8
sub_80A14F8: @ 80A14F8
	push {lr}
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	ldr r0, =gUnknown_08515D8C
	lsrs r1, 14
	adds r1, r0
	ldr r0, [r1]
	ldr r1, =0x06007400
	movs r2, 0x80
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A14F8

	thumb_func_start sub_80A1520
sub_80A1520: @ 80A1520
	push {lr}
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	ldr r0, =gUnknown_085164FC
	lsrs r1, 14
	adds r1, r0
	ldr r0, [r1]
	ldr r1, =0x06005540
	movs r2, 0xC0
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A1520

	thumb_func_start sub_80A1548
sub_80A1548: @ 80A1548
	push {lr}
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	ldr r0, =gUnknown_0851680C
	lsrs r1, 14
	adds r1, r0
	ldr r0, [r1]
	ldr r1, =0x06005b40
	movs r2, 0xC0
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A1548

	thumb_func_start sub_80A1570
sub_80A1570: @ 80A1570
	push {lr}
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	ldr r0, =gUnknown_08516B1C
	lsrs r1, 14
	adds r1, r0
	ldr r0, [r1]
	ldr r1, =0x06005b40
	movs r2, 0xC0
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A1570

	thumb_func_start sub_80A1598
sub_80A1598: @ 80A1598
	push {lr}
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	ldr r0, =gUnknown_08516D2C
	lsrs r1, 14
	adds r1, r0
	ldr r0, [r1]
	ldr r1, =0x06005c00
	movs r2, 0x80
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A1598

	thumb_func_start sub_80A15C0
sub_80A15C0: @ 80A15C0
	push {lr}
	lsls r2, r0, 16
	lsrs r0, r2, 16
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080A15D4
	lsrs r0, r2, 17
	bl sub_80A1748
_080A15D4:
	pop {r0}
	bx r0
	thumb_func_end sub_80A15C0

	thumb_func_start sub_80A15D8
sub_80A15D8: @ 80A15D8
	push {lr}
	lsls r1, r0, 16
	movs r0, 0xE0
	lsls r0, 11
	ands r0, r1
	cmp r0, 0
	bne _080A15EC
	lsrs r0, r1, 19
	bl sub_80A16B0
_080A15EC:
	pop {r0}
	bx r0
	thumb_func_end sub_80A15D8

	thumb_func_start sub_80A15F0
sub_80A15F0: @ 80A15F0
	push {r4,r5,lr}
	lsls r4, r0, 16
	lsrs r0, r4, 16
	adds r5, r0, 0
	movs r0, 0x3F
	ands r0, r5
	cmp r0, 0x1
	bne _080A1606
	lsrs r0, r4, 22
	bl sub_80A1720
_080A1606:
	movs r0, 0x7
	ands r0, r5
	cmp r0, 0x1
	bne _080A1614
	lsrs r0, r4, 19
	bl sub_80A16F8
_080A1614:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80A15F0

	thumb_func_start sub_80A161C
sub_80A161C: @ 80A161C
	push {lr}
	lsls r1, r0, 16
	movs r0, 0xC0
	lsls r0, 10
	ands r0, r1
	cmp r0, 0
	bne _080A1630
	lsrs r0, r1, 18
	bl sub_80A1770
_080A1630:
	pop {r0}
	bx r0
	thumb_func_end sub_80A161C

	thumb_func_start sub_80A1634
sub_80A1634: @ 80A1634
	push {r4,lr}
	lsls r4, r0, 16
	movs r0, 0xE0
	lsls r0, 11
	ands r0, r4
	cmp r0, 0
	bne _080A1650
	lsrs r4, 19
	adds r0, r4, 0
	bl sub_80A17C0
	adds r0, r4, 0
	bl sub_80A17EC
_080A1650:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A1634

	thumb_func_start sub_80A1658
sub_80A1658: @ 80A1658
	push {lr}
	lsls r1, r0, 16
	movs r0, 0xC0
	lsls r0, 10
	ands r0, r1
	cmp r0, 0
	bne _080A166C
	lsrs r0, r1, 18
	bl sub_80A1818
_080A166C:
	pop {r0}
	bx r0
	thumb_func_end sub_80A1658

	thumb_func_start sub_80A1670
sub_80A1670: @ 80A1670
	push {lr}
	lsls r1, r0, 16
	movs r0, 0xC0
	lsls r0, 10
	ands r0, r1
	cmp r0, 0
	bne _080A1684
	lsrs r0, r1, 18
	bl sub_80A1884
_080A1684:
	pop {r0}
	bx r0
	thumb_func_end sub_80A1670

	thumb_func_start sub_80A1688
sub_80A1688: @ 80A1688
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	ands r0, r1
	ldr r1, =gUnknown_08516E3C
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x06003e00
	movs r2, 0x80
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A1688

	thumb_func_start sub_80A16B0
sub_80A16B0: @ 80A16B0
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 16
	ldr r0, =gUnknown_08517A44
	lsrs r4, 14
	adds r0, r4, r0
	ldr r0, [r0]
	ldr r1, =0x06007e00
	movs r2, 0xC0
	lsls r2, 1
	bl sub_80A0980
	ldr r0, =gUnknown_08517A50
	adds r4, r0
	ldr r0, [r4]
	ldr r1, =0x06007a00
	movs r2, 0xA0
	lsls r2, 2
	bl sub_80A0980
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A16B0

	thumb_func_start sub_80A16F8
sub_80A16F8: @ 80A16F8
	push {lr}
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	ldr r0, =gUnknown_08517BFC
	lsrs r1, 14
	adds r1, r0
	ldr r0, [r1]
	ldr r1, =0x06007f00
	movs r2, 0x20
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A16F8

	thumb_func_start sub_80A1720
sub_80A1720: @ 80A1720
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	ands r0, r1
	ldr r1, =gUnknown_08517C0C
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x06007c00
	movs r2, 0x80
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A1720

	thumb_func_start sub_80A1748
sub_80A1748: @ 80A1748
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	ands r0, r1
	ldr r1, =gUnknown_08518034
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x06005200
	movs r2, 0x80
	lsls r2, 2
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A1748

	thumb_func_start sub_80A1770
sub_80A1770: @ 80A1770
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	ands r0, r1
	ldr r1, =gUnknown_0851829C
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x06007e00
	movs r2, 0x90
	lsls r2, 1
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A1770

	thumb_func_start sub_80A1798
sub_80A1798: @ 80A1798
	push {lr}
	lsls r0, 16
	movs r1, 0xE0
	lsls r1, 11
	ands r1, r0
	ldr r0, =gUnknown_085202C4
	lsrs r1, 14
	adds r1, r0
	ldr r0, [r1]
	ldr r1, =0x06005e00
	movs r2, 0xC0
	lsls r2, 4
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A1798

	thumb_func_start sub_80A17C0
sub_80A17C0: @ 80A17C0
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 16
	ldr r1, =gUnknown_08524864
	lsrs r0, 14
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x060052e0
	movs r2, 0x80
	lsls r2, 1
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A17C0

	thumb_func_start sub_80A17EC
sub_80A17EC: @ 80A17EC
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 16
	ldr r1, =gUnknown_08524870
	lsrs r0, 14
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x060050e0
	movs r2, 0x80
	lsls r2, 1
	bl sub_80A0980
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A17EC

	.align 2, 0 @ Don't pad with nop.
