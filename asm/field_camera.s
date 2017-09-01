	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start move_tilemap_camera_to_upper_left_corner_
@ void move_tilemap_camera_to_upper_left_corner_(struc_28 *a1)
move_tilemap_camera_to_upper_left_corner_: @ 8089B58
	movs r1, 0
	strb r1, [r0, 0x2]
	strb r1, [r0, 0x3]
	strb r1, [r0]
	strb r1, [r0, 0x1]
	movs r1, 0x1
	strb r1, [r0, 0x4]
	bx lr
	thumb_func_end move_tilemap_camera_to_upper_left_corner_

	thumb_func_start tilemap_move_something
@ void tilemap_move_something(struct struc_28 *, u8 deltaX, u8 deltaY)
tilemap_move_something: @ 8089B68
	ldrb r3, [r0, 0x2]
	adds r3, r1
	strb r3, [r0, 0x2]
	ldrb r1, [r0, 0x2]
	movs r3, 0x1F
	ands r1, r3
	strb r1, [r0, 0x2]
	ldrb r1, [r0, 0x3]
	adds r1, r2
	strb r1, [r0, 0x3]
	ldrb r1, [r0, 0x3]
	ands r1, r3
	strb r1, [r0, 0x3]
	bx lr
	thumb_func_end tilemap_move_something

	thumb_func_start coords8_add
@ void coords8_add(struct coords8 *coords, u8 x, u8 y)
coords8_add: @ 8089B84
	ldrb r3, [r0]
	adds r3, r1
	strb r3, [r0]
	ldrb r1, [r0, 0x1]
	adds r1, r2
	strb r1, [r0, 0x1]
	bx lr
	thumb_func_end coords8_add

	thumb_func_start move_tilemap_camera_to_upper_left_corner
@ void move_tilemap_camera_to_upper_left_corner()
move_tilemap_camera_to_upper_left_corner: @ 8089B94
	push {lr}
	ldr r0, =gUnknown_03000E20
	bl move_tilemap_camera_to_upper_left_corner_
	pop {r0}
	bx r0
	.pool
	thumb_func_end move_tilemap_camera_to_upper_left_corner

	thumb_func_start FieldUpdateBgTilemapScroll
@ void FieldUpdateBgTilemapScroll()
FieldUpdateBgTilemapScroll: @ 8089BA4
	push {r4,r5,lr}
	ldr r1, =gUnknown_03000E20
	ldr r0, =gUnknown_03000E28
	movs r2, 0
	ldrsh r5, [r0, r2]
	ldrb r0, [r1]
	adds r5, r0
	ldr r0, =gUnknown_03000E2A
	movs r2, 0
	ldrsh r4, [r0, r2]
	ldrb r1, [r1, 0x1]
	adds r4, r1
	adds r4, 0x8
	lsls r5, 16
	lsrs r5, 16
	movs r0, 0x14
	adds r1, r5, 0
	bl SetGpuReg
	lsls r4, 16
	lsrs r4, 16
	movs r0, 0x16
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x18
	adds r1, r5, 0
	bl SetGpuReg
	movs r0, 0x1A
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x1C
	adds r1, r5, 0
	bl SetGpuReg
	movs r0, 0x1E
	adds r1, r4, 0
	bl SetGpuReg
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldUpdateBgTilemapScroll

	thumb_func_start sub_8089C08
sub_8089C08: @ 8089C08
	push {r4,lr}
	ldr r3, =gUnknown_03000E20
	ldr r2, =gUnknown_03000E28
	ldrh r2, [r2]
	ldrb r4, [r3]
	adds r2, r4
	strh r2, [r0]
	ldr r0, =gUnknown_03000E2A
	ldrh r0, [r0]
	ldrb r3, [r3, 0x1]
	adds r0, r3
	adds r0, 0x8
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8089C08

	thumb_func_start DrawWholeMapView
@ void DrawWholeMapView()
DrawWholeMapView: @ 8089C34
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	ldr r2, =gUnknown_02037318
	ldr r2, [r2]
	bl DrawWholeMapViewInternal
	ldr r1, =gUnknown_03000E20
	movs r0, 0x1
	strb r0, [r1, 0x4]
	pop {r0}
	bx r0
	.pool
	thumb_func_end DrawWholeMapView

	thumb_func_start DrawWholeMapViewInternal
@ void DrawWholeMapViewInternal(s32 x, s32 y, struct mapdata_header *mapGrid)
DrawWholeMapViewInternal: @ 8089C60
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r10, r0
	mov r9, r1
	mov r8, r2
	movs r1, 0
_08089C74:
	ldr r2, =gUnknown_03000E20
	ldrb r0, [r2, 0x3]
	adds r0, r1, r0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1F
	bls _08089C88
	subs r0, 0x20
	lsls r0, 24
	lsrs r0, 24
_08089C88:
	lsls r6, r0, 5
	movs r4, 0
	adds r7, r1, 0x2
	str r7, [sp]
	lsrs r5, r1, 1
_08089C92:
	ldr r1, =gUnknown_03000E20
	ldrb r0, [r1, 0x2]
	adds r0, r4, r0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1F
	bls _08089CA6
	subs r0, 0x20
	lsls r0, 24
	lsrs r0, 24
_08089CA6:
	adds r1, r6, r0
	lsls r1, 16
	lsrs r1, 16
	lsrs r2, r4, 1
	add r2, r10
	mov r0, r8
	mov r7, r9
	adds r3, r7, r5
	bl DrawMetatileAt
	adds r0, r4, 0x2
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1F
	bls _08089C92
	ldr r1, [sp]
	lsls r0, r1, 24
	lsrs r1, r0, 24
	cmp r1, 0x1F
	bls _08089C74
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DrawWholeMapViewInternal

	thumb_func_start RedrawMapSlicesForCameraUpdate
@ void RedrawMapSlicesForCameraUpdate(struct struc_28 *, u8 deltaX, u8 deltaY)
RedrawMapSlicesForCameraUpdate: @ 8089CE4
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	ldr r0, =gUnknown_02037318
	ldr r4, [r0]
	cmp r6, 0
	ble _08089CFC
	adds r0, r5, 0
	adds r1, r4, 0
	bl RedrawMapSliceWest
_08089CFC:
	cmp r6, 0
	bge _08089D08
	adds r0, r5, 0
	adds r1, r4, 0
	bl RedrawMapSliceEast
_08089D08:
	cmp r7, 0
	ble _08089D14
	adds r0, r5, 0
	adds r1, r4, 0
	bl RedrawMapSliceNorth
_08089D14:
	cmp r7, 0
	bge _08089D20
	adds r0, r5, 0
	adds r1, r4, 0
	bl RedrawMapSliceSouth
_08089D20:
	movs r0, 0x1
	strb r0, [r5, 0x4]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end RedrawMapSlicesForCameraUpdate

	thumb_func_start RedrawMapSliceNorth
@ void RedrawMapSliceNorth(struct struc_28 *, struct mapdata_header *mapGrid)
RedrawMapSliceNorth: @ 8089D30
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r7, r1, 0
	ldrb r0, [r5, 0x3]
	adds r0, 0x1C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1F
	bls _08089D48
	subs r0, 0x20
	lsls r0, 24
	lsrs r0, 24
_08089D48:
	lsls r6, r0, 5
	movs r4, 0
_08089D4C:
	ldrb r0, [r5, 0x2]
	adds r0, r4, r0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1F
	bls _08089D5E
	subs r0, 0x20
	lsls r0, 24
	lsrs r0, 24
_08089D5E:
	adds r1, r6, r0
	lsls r1, 16
	lsrs r1, 16
	ldr r0, =gSaveBlock1Ptr
	ldr r3, [r0]
	movs r0, 0
	ldrsh r2, [r3, r0]
	lsrs r0, r4, 1
	adds r2, r0
	movs r0, 0x2
	ldrsh r3, [r3, r0]
	adds r3, 0xE
	adds r0, r7, 0
	bl DrawMetatileAt
	adds r0, r4, 0x2
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1F
	bls _08089D4C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end RedrawMapSliceNorth

	thumb_func_start RedrawMapSliceSouth
@ void RedrawMapSliceSouth(struct struc_28 *, struct mapdata_header *mapGrid)
RedrawMapSliceSouth: @ 8089D90
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r7, r1, 0
	ldrb r0, [r5, 0x3]
	lsls r6, r0, 5
	movs r4, 0
_08089D9C:
	ldrb r0, [r5, 0x2]
	adds r0, r4, r0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1F
	bls _08089DAE
	subs r0, 0x20
	lsls r0, 24
	lsrs r0, 24
_08089DAE:
	adds r1, r6, r0
	ldr r0, =gSaveBlock1Ptr
	ldr r3, [r0]
	movs r0, 0
	ldrsh r2, [r3, r0]
	lsrs r0, r4, 1
	adds r2, r0
	movs r0, 0x2
	ldrsh r3, [r3, r0]
	adds r0, r7, 0
	bl DrawMetatileAt
	adds r0, r4, 0x2
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1F
	bls _08089D9C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end RedrawMapSliceSouth

	thumb_func_start RedrawMapSliceEast
@ void RedrawMapSliceEast(struct struc_28 *, struct mapdata_header *mapGrid)
RedrawMapSliceEast: @ 8089DDC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	mov r8, r1
	ldrb r6, [r5, 0x2]
	movs r4, 0
_08089DEA:
	ldrb r0, [r5, 0x3]
	adds r0, r4, r0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1F
	bls _08089DFC
	subs r0, 0x20
	lsls r0, 24
	lsrs r0, 24
_08089DFC:
	lsls r1, r0, 5
	adds r1, r6
	lsls r1, 16
	lsrs r1, 16
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r3, 0
	ldrsh r2, [r0, r3]
	movs r7, 0x2
	ldrsh r3, [r0, r7]
	lsrs r0, r4, 1
	adds r3, r0
	mov r0, r8
	bl DrawMetatileAt
	adds r0, r4, 0x2
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1F
	bls _08089DEA
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end RedrawMapSliceEast

	thumb_func_start RedrawMapSliceWest
@ void RedrawMapSliceWest(struct struc_28 *, struct mapdata_header *mapGrid)
RedrawMapSliceWest: @ 8089E34
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	mov r8, r1
	ldrb r0, [r6, 0x2]
	adds r0, 0x1C
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x1F
	bls _08089E52
	adds r0, r5, 0
	subs r0, 0x20
	lsls r0, 24
	lsrs r5, r0, 24
_08089E52:
	movs r4, 0
_08089E54:
	ldrb r0, [r6, 0x3]
	adds r0, r4, r0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1F
	bls _08089E66
	subs r0, 0x20
	lsls r0, 24
	lsrs r0, 24
_08089E66:
	lsls r1, r0, 5
	adds r1, r5
	lsls r1, 16
	lsrs r1, 16
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r3, 0
	ldrsh r2, [r0, r3]
	adds r2, 0xE
	movs r7, 0x2
	ldrsh r3, [r0, r7]
	lsrs r0, r4, 1
	adds r3, r0
	mov r0, r8
	bl DrawMetatileAt
	adds r0, r4, 0x2
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1F
	bls _08089E54
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end RedrawMapSliceWest

	thumb_func_start CurrentMapDrawMetatileAt
@ void CurrentMapDrawMetatileAt(u32 x, u32 y)
CurrentMapDrawMetatileAt: @ 8089EA0
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r6, =gUnknown_03000E20
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl MapPosToBgTilemapOffset
	adds r1, r0, 0
	cmp r1, 0
	blt _08089ECC
	ldr r0, =gUnknown_02037318
	ldr r0, [r0]
	lsls r1, 16
	lsrs r1, 16
	adds r2, r4, 0
	adds r3, r5, 0
	bl DrawMetatileAt
	movs r0, 0x1
	strb r0, [r6, 0x4]
_08089ECC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CurrentMapDrawMetatileAt

	thumb_func_start DrawDoorMetatileAt
@ void DrawDoorMetatileAt(u32 x, u32 y, u16 *metatile)
DrawDoorMetatileAt: @ 8089EDC
	push {r4-r6,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	ldr r6, =gUnknown_03000E20
	adds r0, r6, 0
	adds r1, r3, 0
	adds r2, r4, 0
	bl MapPosToBgTilemapOffset
	cmp r0, 0
	blt _08089F04
	lsls r2, r0, 16
	lsrs r2, 16
	movs r0, 0x1
	adds r1, r5, 0
	bl DrawMetatile
	movs r0, 0x1
	strb r0, [r6, 0x4]
_08089F04:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DrawDoorMetatileAt

	thumb_func_start DrawMetatileAt
@ void DrawMetatileAt(struct mapdata_header *mapGrid, u16 offset, s32 x, s32 y)
DrawMetatileAt: @ 8089F10
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	adds r6, r2, 0
	adds r7, r3, 0
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	adds r0, r6, 0
	adds r1, r7, 0
	bl MapGridGetMetatileIdAt
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x80
	lsls r0, 3
	cmp r4, r0
	bls _08089F38
	movs r4, 0
_08089F38:
	ldr r0, =0x000001ff
	cmp r4, r0
	bhi _08089F48
	ldr r0, [r5, 0x10]
	ldr r5, [r0, 0xC]
	b _08089F54
	.pool
_08089F48:
	ldr r0, [r5, 0x14]
	ldr r5, [r0, 0xC]
	ldr r1, =0xfffffe00
	adds r0, r4, r1
	lsls r0, 16
	lsrs r4, r0, 16
_08089F54:
	adds r0, r6, 0
	adds r1, r7, 0
	bl MapGridGetMetatileLayerTypeAt
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r4, 4
	adds r1, r5, r1
	mov r2, r8
	bl DrawMetatile
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DrawMetatileAt

	thumb_func_start DrawMetatile
@ void DrawMetatile(u32 layerType, u16 *metatile, u16 offset)
DrawMetatile: @ 8089F78
	push {r4,lr}
	adds r4, r1, 0
	lsls r2, 16
	lsrs r2, 16
	cmp r0, 0x1
	beq _08089FD0
	cmp r0, 0x1
	bgt _08089F8E
	cmp r0, 0
	beq _0808A030
	b _0808A082
_08089F8E:
	cmp r0, 0x2
	bne _0808A082
	ldr r0, =gUnknown_03005DA4
	ldr r0, [r0]
	lsls r3, r2, 1
	adds r0, r3, r0
	ldrh r1, [r4]
	strh r1, [r0]
	ldrh r1, [r4, 0x2]
	strh r1, [r0, 0x2]
	adds r2, r0, 0
	adds r2, 0x40
	ldrh r1, [r4, 0x4]
	strh r1, [r2]
	adds r0, 0x42
	ldrh r1, [r4, 0x6]
	strh r1, [r0]
	ldr r0, =gUnknown_03005D9C
	ldr r0, [r0]
	adds r0, r3, r0
	movs r2, 0
	strh r2, [r0]
	strh r2, [r0, 0x2]
	adds r1, r0, 0
	adds r1, 0x40
	strh r2, [r1]
	adds r0, 0x42
	strh r2, [r0]
	b _0808A066
	.pool
_08089FD0:
	ldr r0, =gUnknown_03005DA4
	ldr r0, [r0]
	lsls r3, r2, 1
	adds r0, r3, r0
	ldrh r1, [r4]
	strh r1, [r0]
	ldrh r1, [r4, 0x2]
	strh r1, [r0, 0x2]
	adds r2, r0, 0
	adds r2, 0x40
	ldrh r1, [r4, 0x4]
	strh r1, [r2]
	adds r0, 0x42
	ldrh r1, [r4, 0x6]
	strh r1, [r0]
	ldr r0, =gUnknown_03005D9C
	ldr r0, [r0]
	adds r0, r3, r0
	ldrh r1, [r4, 0x8]
	strh r1, [r0]
	ldrh r1, [r4, 0xA]
	strh r1, [r0, 0x2]
	adds r2, r0, 0
	adds r2, 0x40
	ldrh r1, [r4, 0xC]
	strh r1, [r2]
	adds r0, 0x42
	ldrh r1, [r4, 0xE]
	strh r1, [r0]
	ldr r0, =gUnknown_03005DA0
	ldr r0, [r0]
	adds r3, r0
	movs r1, 0
	strh r1, [r3]
	strh r1, [r3, 0x2]
	adds r0, r3, 0
	adds r0, 0x40
	strh r1, [r0]
	adds r3, 0x42
	strh r1, [r3]
	b _0808A082
	.pool
_0808A030:
	ldr r0, =gUnknown_03005DA4
	ldr r0, [r0]
	lsls r3, r2, 1
	adds r0, r3, r0
	ldr r1, =0x00003014
	adds r2, r1, 0
	strh r2, [r0]
	strh r2, [r0, 0x2]
	adds r1, r0, 0
	adds r1, 0x40
	strh r2, [r1]
	adds r0, 0x42
	strh r2, [r0]
	ldr r0, =gUnknown_03005D9C
	ldr r0, [r0]
	adds r0, r3, r0
	ldrh r1, [r4]
	strh r1, [r0]
	ldrh r1, [r4, 0x2]
	strh r1, [r0, 0x2]
	adds r2, r0, 0
	adds r2, 0x40
	ldrh r1, [r4, 0x4]
	strh r1, [r2]
	adds r0, 0x42
	ldrh r1, [r4, 0x6]
	strh r1, [r0]
_0808A066:
	ldr r0, =gUnknown_03005DA0
	ldr r0, [r0]
	adds r3, r0
	ldrh r0, [r4, 0x8]
	strh r0, [r3]
	ldrh r0, [r4, 0xA]
	strh r0, [r3, 0x2]
	adds r1, r3, 0
	adds r1, 0x40
	ldrh r0, [r4, 0xC]
	strh r0, [r1]
	adds r3, 0x42
	ldrh r0, [r4, 0xE]
	strh r0, [r3]
_0808A082:
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x3
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DrawMetatile

	thumb_func_start MapPosToBgTilemapOffset
@ u32 MapPosToBgTilemapOffset(struct struc_28 *, u32 x, u32 y)
MapPosToBgTilemapOffset: @ 808A0AC
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r3, [r0]
	movs r5, 0
	ldrsh r0, [r3, r5]
	subs r1, r0
	lsls r1, 1
	cmp r1, 0x1F
	bhi _0808A0D6
	ldrb r0, [r4, 0x2]
	adds r1, r0
	cmp r1, 0x1F
	ble _0808A0CA
	subs r1, 0x20
_0808A0CA:
	movs r5, 0x2
	ldrsh r0, [r3, r5]
	subs r0, r2, r0
	lsls r2, r0, 1
	cmp r2, 0x1F
	bls _0808A0E0
_0808A0D6:
	movs r0, 0x1
	negs r0, r0
	b _0808A0EE
	.pool
_0808A0E0:
	ldrb r0, [r4, 0x3]
	adds r2, r0
	cmp r2, 0x1F
	ble _0808A0EA
	subs r2, 0x20
_0808A0EA:
	lsls r0, r2, 5
	adds r0, r1
_0808A0EE:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end MapPosToBgTilemapOffset

	thumb_func_start CameraUpdateCallback
@ void CameraUpdateCallback(struct CameraUpdateInfo *info)
CameraUpdateCallback: @ 808A0F4
	push {lr}
	adds r3, r0, 0
	ldr r2, [r3, 0x4]
	cmp r2, 0
	beq _0808A114
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r2, 0x32
	ldrsh r1, [r0, r2]
	str r1, [r3, 0x8]
	movs r1, 0x34
	ldrsh r0, [r0, r1]
	str r0, [r3, 0xC]
_0808A114:
	pop {r0}
	bx r0
	.pool
	thumb_func_end CameraUpdateCallback

	thumb_func_start ResetCameraUpdateInfo
@ void ResetCameraUpdateInfo()
ResetCameraUpdateInfo: @ 808A11C
	ldr r1, =gUnknown_03005DD0
	movs r0, 0
	str r0, [r1, 0x8]
	str r0, [r1, 0xC]
	str r0, [r1, 0x10]
	str r0, [r1, 0x14]
	str r0, [r1, 0x4]
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end ResetCameraUpdateInfo

	thumb_func_start InitCameraUpdateCallback
@ u8 InitCameraUpdateCallback(u8 followedObjectId)
InitCameraUpdateCallback: @ 808A134
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gUnknown_03005DD0
	ldr r1, [r4, 0x4]
	cmp r1, 0
	beq _0808A150
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl RemoveObjectAndFreeTiles
_0808A150:
	adds r0, r5, 0
	bl AddCameraObject
	lsls r0, 24
	lsrs r0, 24
	str r0, [r4, 0x4]
	ldr r0, =CameraUpdateCallback
	str r0, [r4]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end InitCameraUpdateCallback

	thumb_func_start CameraUpdate
@ void CameraUpdate()
CameraUpdate: @ 808A174
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r6, =gUnknown_03005DD0
	ldr r1, [r6]
	cmp r1, 0
	beq _0808A188
	adds r0, r6, 0
	bl _call_via_r1
_0808A188:
	ldr r7, [r6, 0x8]
	ldr r0, [r6, 0xC]
	mov r8, r0
	movs r4, 0
	movs r5, 0
	ldr r1, [r6, 0x10]
	ldr r0, [r6, 0x14]
	cmp r1, 0
	bne _0808A1A6
	cmp r7, 0
	beq _0808A1A6
	subs r4, 0x1
	cmp r7, 0
	ble _0808A1A6
	movs r4, 0x1
_0808A1A6:
	cmp r0, 0
	bne _0808A1BA
	mov r2, r8
	cmp r2, 0
	beq _0808A1BA
	movs r5, 0x1
	negs r5, r5
	cmp r2, 0
	ble _0808A1BA
	movs r5, 0x1
_0808A1BA:
	cmp r1, 0
	beq _0808A1CC
	cmn r1, r7
	bne _0808A1CC
	movs r4, 0x1
	negs r4, r4
	cmp r7, 0
	ble _0808A1CC
	movs r4, 0x1
_0808A1CC:
	cmp r0, 0
	beq _0808A1E0
	mov r3, r8
	cmn r0, r3
	bne _0808A1E0
	movs r4, 0x1
	negs r4, r4
	cmp r3, 0
	ble _0808A1E0
	movs r4, 0x1
_0808A1E0:
	ldr r2, =gUnknown_03005DD0
	ldr r0, [r2, 0x10]
	adds r1, r0, r7
	str r1, [r2, 0x10]
	adds r0, r1, 0
	cmp r1, 0
	bge _0808A1F0
	adds r0, 0xF
_0808A1F0:
	asrs r0, 4
	lsls r0, 4
	subs r0, r1, r0
	str r0, [r2, 0x10]
	ldr r0, [r2, 0x14]
	mov r3, r8
	adds r1, r0, r3
	str r1, [r2, 0x14]
	adds r0, r1, 0
	cmp r1, 0
	bge _0808A208
	adds r0, 0xF
_0808A208:
	asrs r0, 4
	lsls r0, 4
	subs r0, r1, r0
	str r0, [r2, 0x14]
	cmp r4, 0
	bne _0808A218
	cmp r5, 0
	beq _0808A24E
_0808A218:
	adds r0, r4, 0
	adds r1, r5, 0
	bl CameraMove
	adds r0, r4, 0
	adds r1, r5, 0
	bl UpdateFieldObjectsForCameraUpdate
	adds r0, r4, 0
	adds r1, r5, 0
	bl RotatingGatePuzzleCameraUpdate
	bl ResetBerryTreeSparkleFlags
	ldr r6, =gUnknown_03000E20
	lsls r4, 1
	lsls r5, 1
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl tilemap_move_something
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl RedrawMapSlicesForCameraUpdate
_0808A24E:
	ldr r0, =gUnknown_03000E20
	adds r1, r7, 0
	mov r2, r8
	bl coords8_add
	ldr r1, =gUnknown_03005DEC
	ldrh r0, [r1]
	subs r0, r7
	strh r0, [r1]
	ldr r1, =gUnknown_03005DE8
	ldrh r0, [r1]
	mov r2, r8
	subs r0, r2
	strh r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CameraUpdate

	thumb_func_start sub_808A284
sub_808A284: @ 808A284
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl CameraMove
	lsls r0, r4, 16
	asrs r0, 16
	lsls r1, r5, 16
	asrs r1, 16
	bl UpdateFieldObjectsForCameraUpdate
	bl DrawWholeMapView
	ldr r1, =gUnknown_03005DEC
	lsls r4, 4
	ldrh r0, [r1]
	subs r0, r4
	strh r0, [r1]
	ldr r1, =gUnknown_03005DE8
	lsls r5, 4
	ldrh r0, [r1]
	subs r0, r5
	strh r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808A284

	thumb_func_start SetCameraPanningCallback
@ void SetCameraPanningCallback(void ( *callback)())
SetCameraPanningCallback: @ 808A2C0
	ldr r1, =gUnknown_03000E30
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end SetCameraPanningCallback

	thumb_func_start SetCameraPanning
@ void SetCameraPanning(s16 x, s16 y)
SetCameraPanning: @ 808A2CC
	ldr r2, =gUnknown_03000E28
	strh r0, [r2]
	ldr r0, =gUnknown_03000E2A
	lsls r1, 16
	asrs r1, 16
	adds r1, 0x20
	strh r1, [r0]
	bx lr
	.pool
	thumb_func_end SetCameraPanning

	thumb_func_start InstallCameraPanAheadCallback
@ void InstallCameraPanAheadCallback()
InstallCameraPanAheadCallback: @ 808A2E4
	ldr r1, =gUnknown_03000E30
	ldr r0, =CameraPanningCB_PanAhead
	str r0, [r1]
	ldr r1, =gUnknown_03000E2C
	movs r0, 0
	strb r0, [r1]
	ldr r1, =gUnknown_03000E28
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03000E2A
	movs r0, 0x20
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end InstallCameraPanAheadCallback

	thumb_func_start UpdateCameraPanning
@ void UpdateCameraPanning()
UpdateCameraPanning: @ 808A314
	push {lr}
	ldr r0, =gUnknown_03000E30
	ldr r0, [r0]
	cmp r0, 0
	beq _0808A322
	bl _call_via_r0
_0808A322:
	ldr r2, =gSpriteCoordOffsetX
	ldr r0, =gUnknown_03005DEC
	ldr r1, =gUnknown_03000E28
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r1
	strh r0, [r2]
	ldr r2, =gSpriteCoordOffsetY
	ldr r0, =gUnknown_03005DE8
	ldr r1, =gUnknown_03000E2A
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r1
	subs r0, 0x8
	strh r0, [r2]
	pop {r0}
	bx r0
	.pool
	thumb_func_end UpdateCameraPanning

	thumb_func_start CameraPanningCB_PanAhead
@ void CameraPanningCB_PanAhead()
CameraPanningCB_PanAhead: @ 808A360
	push {lr}
	ldr r0, =gUnknown_02037348
	ldrb r0, [r0]
	cmp r0, 0
	bne _0808A374
	bl InstallCameraPanAheadCallback
	b _0808A3FC
	.pool
_0808A374:
	ldr r0, =gUnknown_02037590
	ldrb r0, [r0, 0x3]
	cmp r0, 0x1
	bne _0808A394
	ldr r0, =gUnknown_03000E2C
	ldrb r1, [r0]
	movs r2, 0x1
	eors r1, r2
	strb r1, [r0]
	cmp r1, 0
	beq _0808A3FC
	b _0808A39A
	.pool
_0808A394:
	ldr r1, =gUnknown_03000E2C
	movs r0, 0
	strb r0, [r1]
_0808A39A:
	bl player_get_direction_upper_nybble
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _0808A3C4
	ldr r2, =gUnknown_03000E2A
	ldrh r3, [r2]
	movs r0, 0
	ldrsh r1, [r2, r0]
	movs r0, 0x8
	negs r0, r0
	cmp r1, r0
	ble _0808A3FC
	subs r0, r3, 0x2
	b _0808A3FA
	.pool
_0808A3C4:
	cmp r0, 0x1
	bne _0808A3E0
	ldr r1, =gUnknown_03000E2A
	ldrh r2, [r1]
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0x47
	bgt _0808A3FC
	adds r0, r2, 0x2
	strh r0, [r1]
	b _0808A3FC
	.pool
_0808A3E0:
	ldr r2, =gUnknown_03000E2A
	ldrh r0, [r2]
	movs r3, 0
	ldrsh r1, [r2, r3]
	cmp r1, 0x1F
	bgt _0808A3F4
	adds r0, 0x2
	b _0808A3FA
	.pool
_0808A3F4:
	cmp r1, 0x20
	ble _0808A3FC
	subs r0, 0x2
_0808A3FA:
	strh r0, [r2]
_0808A3FC:
	pop {r0}
	bx r0
	thumb_func_end CameraPanningCB_PanAhead

	.align 2, 0 @ Don't pad with nop.
