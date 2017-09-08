	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start mapconnection_get_mapheader
mapconnection_get_mapheader: @ 8087D44
	push {lr}
	ldrb r2, [r0, 0x8]
	ldrb r1, [r0, 0x9]
	adds r0, r2, 0
	bl get_mapheader_by_bank_and_number
	pop {r1}
	bx r1
	thumb_func_end mapconnection_get_mapheader

	thumb_func_start not_trainer_hill_battle_pyramid
not_trainer_hill_battle_pyramid: @ 8087D54
	push {r4,lr}
	ldr r4, =gMapHeader
	adds r0, r4, 0
	bl mapheader_copy_mapdata_with_padding
	ldr r0, [r4, 0x4]
	bl sub_80E8EE0
	bl mapheader_run_script_with_tag_x1
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end not_trainer_hill_battle_pyramid

	thumb_func_start sub_8087D74
sub_8087D74: @ 8087D74
	push {r4,lr}
	ldr r4, =gMapHeader
	adds r0, r4, 0
	bl mapheader_copy_mapdata_with_padding
	movs r0, 0
	bl sub_80E9238
	ldr r0, [r4, 0x4]
	bl sub_80E8EE0
	bl mapdata_from_sav2
	bl mapheader_run_script_with_tag_x1
	ldr r1, =gUnknown_03005DC0
	ldr r0, [r1]
	ldr r1, [r1, 0x4]
	bl UpdateTVScreensOnMap
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8087D74

	thumb_func_start battle_pyramid_map_load_related
battle_pyramid_map_load_related: @ 8087DAC
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =0x03ff03ff
	str r0, [sp]
	ldr r5, =gUnknown_02032318
	ldr r2, =0x01001400
	mov r0, sp
	adds r1, r5, 0
	bl CpuFastSet
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_81AA078
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end battle_pyramid_map_load_related

	thumb_func_start trainer_hill_map_load_related
trainer_hill_map_load_related: @ 8087DE4
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =0x03ff03ff
	str r0, [sp]
	ldr r4, =gUnknown_02032318
	ldr r2, =0x01001400
	mov r0, sp
	adds r1, r4, 0
	bl CpuFastSet
	adds r0, r4, 0
	bl sub_81D5FB4
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end trainer_hill_map_load_related

	thumb_func_start mapheader_copy_mapdata_with_padding
@ void mapheader_copy_mapdata_with_padding(struct mapheader *mapHeader)
mapheader_copy_mapdata_with_padding: @ 8087E14
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	ldr r5, [r6]
	ldr r0, =0x03ff03ff
	str r0, [sp]
	ldr r4, =gUnknown_02032318
	ldr r2, =0x01001400
	mov r0, sp
	adds r1, r4, 0
	bl CpuFastSet
	ldr r2, =gUnknown_03005DC0
	str r4, [r2, 0x8]
	ldr r1, [r5]
	adds r1, 0xF
	str r1, [r2]
	ldr r0, [r5, 0x4]
	adds r0, 0xE
	str r0, [r2, 0x4]
	muls r1, r0
	movs r0, 0xA0
	lsls r0, 6
	cmp r1, r0
	bgt _08087E56
	ldr r0, [r5, 0xC]
	ldrh r1, [r5]
	ldrh r2, [r5, 0x4]
	bl map_copy_with_padding
	adds r0, r6, 0
	bl mapheader_copy_mapdata_of_adjacent_maps
_08087E56:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end mapheader_copy_mapdata_with_padding

	thumb_func_start map_copy_with_padding
@ int map_copy_with_padding(void *src)
map_copy_with_padding: @ 8087E70
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r7, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	lsls r2, 16
	lsrs r2, 16
	ldr r0, =gUnknown_03005DC0
	ldr r4, [r0, 0x8]
	ldr r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 1
	adds r0, 0xE
	adds r4, r0
	cmp r2, 0
	beq _08087EB8
	mov r0, r8
	lsls r6, r0, 1
	adds r5, r2, 0
	movs r0, 0x1E
	adds r0, r6
	mov r9, r0
_08087EA4:
	adds r0, r7, 0
	adds r1, r4, 0
	mov r2, r8
	bl CpuSet
	add r4, r9
	adds r7, r6
	subs r5, 0x1
	cmp r5, 0
	bne _08087EA4
_08087EB8:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end map_copy_with_padding

	thumb_func_start mapheader_copy_mapdata_of_adjacent_maps
@ void mapheader_copy_mapdata_of_adjacent_maps(struct mapheader *mapHeader)
mapheader_copy_mapdata_of_adjacent_maps: @ 8087EC8
	push {r4-r7,lr}
	adds r6, r0, 0
	ldr r0, [r6, 0xC]
	cmp r0, 0
	beq _08087F4C
	ldr r1, [r0]
	ldr r5, [r0, 0x4]
	ldr r2, =gUnknown_02037340
	ldr r0, =gUnknown_08486EF8
	ldr r0, [r0]
	str r0, [r2]
	cmp r1, 0
	ble _08087F4C
	adds r4, r2, 0
	adds r7, r1, 0
_08087EE6:
	adds r0, r5, 0
	bl mapconnection_get_mapheader
	adds r1, r0, 0
	ldr r2, [r5, 0x4]
	ldrb r0, [r5]
	cmp r0, 0x2
	beq _08087F1E
	cmp r0, 0x2
	bgt _08087F08
	cmp r0, 0x1
	beq _08087F12
	b _08087F44
	.pool
_08087F08:
	cmp r0, 0x3
	beq _08087F2A
	cmp r0, 0x4
	beq _08087F36
	b _08087F44
_08087F12:
	adds r0, r6, 0
	bl sub_8087FB8
	ldrb r0, [r4]
	movs r1, 0x1
	b _08087F40
_08087F1E:
	adds r0, r6, 0
	bl sub_8088020
	ldrb r0, [r4]
	movs r1, 0x2
	b _08087F40
_08087F2A:
	adds r0, r6, 0
	bl sub_8088080
	ldrb r0, [r4]
	movs r1, 0x4
	b _08087F40
_08087F36:
	adds r0, r6, 0
	bl sub_80880E0
	ldrb r0, [r4]
	movs r1, 0x8
_08087F40:
	orrs r0, r1
	strb r0, [r4]
_08087F44:
	subs r7, 0x1
	adds r5, 0xC
	cmp r7, 0
	bne _08087EE6
_08087F4C:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end mapheader_copy_mapdata_of_adjacent_maps

	thumb_func_start sub_8087F54
sub_8087F54: @ 8087F54
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r5, [sp, 0x18]
	ldr r4, [r2]
	ldr r7, [r4]
	adds r2, r7, 0
	muls r2, r5
	adds r2, r3
	lsls r2, 1
	ldr r3, [r4, 0xC]
	adds r6, r3, r2
	ldr r3, =gUnknown_03005DC0
	ldr r2, [r3]
	muls r1, r2
	adds r1, r0
	lsls r1, 1
	ldr r0, [r3, 0x8]
	adds r5, r0, r1
	ldr r0, [sp, 0x20]
	cmp r0, 0
	ble _08087FA6
	adds r4, r0, 0
	ldr r3, =0x001fffff
	mov r8, r3
_08087F86:
	adds r0, r6, 0
	adds r1, r5, 0
	ldr r2, [sp, 0x1C]
	mov r3, r8
	ands r2, r3
	bl CpuSet
	ldr r0, =gUnknown_03005DC0
	ldr r0, [r0]
	lsls r0, 1
	adds r5, r0
	lsls r0, r7, 1
	adds r6, r0
	subs r4, 0x1
	cmp r4, 0
	bne _08087F86
_08087FA6:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8087F54

	thumb_func_start sub_8087FB8
sub_8087FB8: @ 8087FB8
	push {r4-r7,lr}
	sub sp, 0xC
	adds r3, r0, 0
	adds r5, r1, 0
	cmp r5, 0
	beq _08088012
	ldr r0, [r5]
	ldr r4, [r0]
	adds r2, 0x7
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	adds r7, r0, 0x7
	cmp r2, 0
	bge _08087FEC
	negs r6, r2
	adds r2, r4
	ldr r0, =gUnknown_03005DC0
	ldr r3, [r0]
	cmp r2, r3
	bge _08087FE2
	adds r3, r2, 0
_08087FE2:
	movs r2, 0
	b _08087FFC
	.pool
_08087FEC:
	movs r6, 0
	adds r0, r2, r4
	ldr r1, =gUnknown_03005DC0
	ldr r1, [r1]
	subs r3, r1, r2
	cmp r0, r1
	bge _08087FFC
	adds r3, r4, 0
_08087FFC:
	movs r0, 0
	str r0, [sp]
	str r3, [sp, 0x4]
	movs r0, 0x7
	str r0, [sp, 0x8]
	adds r0, r2, 0
	adds r1, r7, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8087F54
_08088012:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8087FB8

	thumb_func_start sub_8088020
sub_8088020: @ 8088020
	push {r4-r7,lr}
	sub sp, 0xC
	adds r5, r1, 0
	cmp r5, 0
	beq _08088074
	ldr r0, [r5]
	ldr r4, [r0]
	ldr r0, [r0, 0x4]
	adds r2, 0x7
	subs r7, r0, 0x7
	cmp r2, 0
	bge _08088050
	negs r6, r2
	adds r2, r4
	ldr r0, =gUnknown_03005DC0
	ldr r3, [r0]
	cmp r2, r3
	bge _08088046
	adds r3, r2, 0
_08088046:
	movs r2, 0
	b _08088060
	.pool
_08088050:
	movs r6, 0
	adds r0, r2, r4
	ldr r1, =gUnknown_03005DC0
	ldr r1, [r1]
	subs r3, r1, r2
	cmp r0, r1
	bge _08088060
	adds r3, r4, 0
_08088060:
	str r7, [sp]
	str r3, [sp, 0x4]
	movs r0, 0x7
	str r0, [sp, 0x8]
	adds r0, r2, 0
	movs r1, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8087F54
_08088074:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8088020

	thumb_func_start sub_8088080
sub_8088080: @ 8088080
	push {r4-r7,lr}
	sub sp, 0xC
	adds r5, r1, 0
	cmp r5, 0
	beq _080880D4
	ldr r0, [r5]
	ldr r1, [r0]
	ldr r4, [r0, 0x4]
	adds r2, 0x7
	subs r7, r1, 0x7
	cmp r2, 0
	bge _080880B0
	negs r6, r2
	adds r1, r2, r4
	ldr r0, =gUnknown_03005DC0
	ldr r3, [r0, 0x4]
	cmp r1, r3
	bge _080880A6
	adds r3, r1, 0
_080880A6:
	movs r2, 0
	b _080880C0
	.pool
_080880B0:
	movs r6, 0
	adds r0, r2, r4
	ldr r1, =gUnknown_03005DC0
	ldr r1, [r1, 0x4]
	subs r3, r1, r2
	cmp r0, r1
	bge _080880C0
	adds r3, r4, 0
_080880C0:
	str r6, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	str r3, [sp, 0x8]
	movs r0, 0
	adds r1, r2, 0
	adds r2, r5, 0
	adds r3, r7, 0
	bl sub_8087F54
_080880D4:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8088080

	thumb_func_start sub_80880E0
sub_80880E0: @ 80880E0
	push {r4-r7,lr}
	sub sp, 0xC
	adds r3, r0, 0
	adds r5, r1, 0
	cmp r5, 0
	beq _08088138
	ldr r0, [r5]
	ldr r4, [r0, 0x4]
	ldr r0, [r3]
	ldr r0, [r0]
	adds r7, r0, 0x7
	adds r2, 0x7
	cmp r2, 0
	bge _08088114
	negs r6, r2
	adds r1, r2, r4
	ldr r0, =gUnknown_03005DC0
	ldr r3, [r0, 0x4]
	cmp r1, r3
	bge _0808810A
	adds r3, r1, 0
_0808810A:
	movs r2, 0
	b _08088124
	.pool
_08088114:
	movs r6, 0
	adds r0, r2, r4
	ldr r1, =gUnknown_03005DC0
	ldr r1, [r1, 0x4]
	subs r3, r1, r2
	cmp r0, r1
	bge _08088124
	adds r3, r4, 0
_08088124:
	str r6, [sp]
	movs r0, 0x8
	str r0, [sp, 0x4]
	str r3, [sp, 0x8]
	adds r0, r7, 0
	adds r1, r2, 0
	adds r2, r5, 0
	movs r3, 0
	bl sub_8087F54
_08088138:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80880E0

	thumb_func_start MapGridGetZCoordAt
@ u8 MapGridGetZCoordAt(s32 x, s32 y)
MapGridGetZCoordAt: @ 8088144
	push {r4,lr}
	adds r2, r0, 0
	adds r4, r1, 0
	cmp r2, 0
	blt _08088174
	ldr r1, =gUnknown_03005DC0
	ldr r3, [r1]
	cmp r2, r3
	bge _08088174
	cmp r4, 0
	blt _08088174
	ldr r0, [r1, 0x4]
	cmp r4, r0
	bge _08088174
	adds r0, r3, 0
	muls r0, r4
	adds r0, r2, r0
	ldr r1, [r1, 0x8]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	b _08088196
	.pool
_08088174:
	ldr r0, =gMapHeader
	ldr r3, [r0]
	adds r1, r2, 0x1
	movs r2, 0x1
	ands r1, r2
	adds r0, r4, 0x1
	ands r0, r2
	lsls r0, 1
	adds r1, r0
	ldr r0, [r3, 0x8]
	lsls r1, 1
	adds r1, r0
	ldrh r1, [r1]
	movs r2, 0xC0
	lsls r2, 4
	adds r0, r2, 0
	orrs r1, r0
_08088196:
	ldr r0, =0x000003ff
	cmp r1, r0
	beq _080881A8
	lsrs r0, r1, 12
	b _080881AA
	.pool
_080881A8:
	movs r0, 0
_080881AA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end MapGridGetZCoordAt

	thumb_func_start MapGridIsImpassableAt
@ u8 MapGridIsImpassableAt(s32 x, s32 y)
MapGridIsImpassableAt: @ 80881B0
	push {r4,lr}
	adds r2, r0, 0
	adds r4, r1, 0
	cmp r2, 0
	blt _080881E0
	ldr r1, =gUnknown_03005DC0
	ldr r3, [r1]
	cmp r2, r3
	bge _080881E0
	cmp r4, 0
	blt _080881E0
	ldr r0, [r1, 0x4]
	cmp r4, r0
	bge _080881E0
	adds r0, r3, 0
	muls r0, r4
	adds r0, r2, r0
	ldr r1, [r1, 0x8]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	b _08088202
	.pool
_080881E0:
	ldr r0, =gMapHeader
	ldr r3, [r0]
	adds r1, r2, 0x1
	movs r2, 0x1
	ands r1, r2
	adds r0, r4, 0x1
	ands r0, r2
	lsls r0, 1
	adds r1, r0
	ldr r0, [r3, 0x8]
	lsls r1, 1
	adds r1, r0
	ldrh r1, [r1]
	movs r2, 0xC0
	lsls r2, 4
	adds r0, r2, 0
	orrs r1, r0
_08088202:
	ldr r0, =0x000003ff
	cmp r1, r0
	beq _0808821C
	movs r0, 0xC0
	lsls r0, 4
	ands r1, r0
	lsrs r0, r1, 10
	b _0808821E
	.pool
_0808821C:
	movs r0, 0x1
_0808821E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end MapGridIsImpassableAt

	thumb_func_start MapGridGetMetatileIdAt
@ u16 MapGridGetMetatileIdAt(s32 x, s32 y)
MapGridGetMetatileIdAt: @ 8088224
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	cmp r5, 0
	blt _08088254
	ldr r1, =gUnknown_03005DC0
	ldr r2, [r1]
	cmp r5, r2
	bge _08088254
	cmp r6, 0
	blt _08088254
	ldr r0, [r1, 0x4]
	cmp r6, r0
	bge _08088254
	adds r0, r2, 0
	muls r0, r6
	adds r0, r5, r0
	ldr r1, [r1, 0x8]
	lsls r0, 1
	adds r0, r1
	ldrh r4, [r0]
	b _08088278
	.pool
_08088254:
	ldr r0, =gMapHeader
	ldr r3, [r0]
	adds r1, r5, 0x1
	movs r2, 0x1
	ands r1, r2
	adds r0, r6, 0x1
	ands r0, r2
	lsls r0, 1
	adds r1, r0
	ldr r0, [r3, 0x8]
	lsls r1, 1
	adds r1, r0
	ldrh r1, [r1]
	movs r2, 0xC0
	lsls r2, 4
	adds r0, r2, 0
	adds r4, r0, 0
	orrs r4, r1
_08088278:
	ldr r0, =0x000003ff
	cmp r4, r0
	beq _0808828C
	ands r4, r0
	adds r0, r4, 0
	b _080882B0
	.pool
_0808828C:
	ldr r0, =gMapHeader
	ldr r3, [r0]
	adds r1, r5, 0x1
	movs r2, 0x1
	ands r1, r2
	adds r0, r6, 0x1
	ands r0, r2
	lsls r0, 1
	adds r1, r0
	ldr r0, [r3, 0x8]
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r1]
	movs r2, 0xC0
	lsls r2, 4
	adds r1, r2, 0
	orrs r0, r1
	ands r0, r4
_080882B0:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end MapGridGetMetatileIdAt

	thumb_func_start MapGridGetMetatileBehaviorAt
@ u8 MapGridGetMetatileBehaviorAt(s32 x, s32 y)
MapGridGetMetatileBehaviorAt: @ 80882BC
	push {lr}
	bl MapGridGetMetatileIdAt
	lsls r0, 16
	lsrs r0, 16
	bl GetBehaviorByMetatileId
	adds r1, r0, 0
	movs r0, 0xFF
	ands r0, r1
	pop {r1}
	bx r1
	thumb_func_end MapGridGetMetatileBehaviorAt

	thumb_func_start MapGridGetMetatileLayerTypeAt
@ u8 MapGridGetMetatileLayerTypeAt(s32 x, s32 y)
MapGridGetMetatileLayerTypeAt: @ 80882D4
	push {lr}
	bl MapGridGetMetatileIdAt
	lsls r0, 16
	lsrs r0, 16
	bl GetBehaviorByMetatileId
	adds r1, r0, 0
	movs r0, 0xF0
	lsls r0, 8
	ands r0, r1
	lsrs r0, 12
	pop {r1}
	bx r1
	thumb_func_end MapGridGetMetatileLayerTypeAt

	thumb_func_start MapGridSetMetatileIdAt
@ void MapGridSetMetatileIdAt(s32 x, s32 y, u16 metatileId)
MapGridSetMetatileIdAt: @ 80882F0
	push {r4,r5,lr}
	adds r3, r0, 0
	lsls r2, 16
	lsrs r5, r2, 16
	cmp r3, 0
	blt _08088328
	ldr r2, =gUnknown_03005DC0
	ldr r4, [r2]
	cmp r3, r4
	bge _08088328
	cmp r1, 0
	blt _08088328
	ldr r0, [r2, 0x4]
	cmp r1, r0
	bge _08088328
	muls r1, r4
	adds r1, r3, r1
	ldr r0, [r2, 0x8]
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r1]
	movs r2, 0xF0
	lsls r2, 8
	ands r2, r0
	ldr r0, =0x00000fff
	ands r0, r5
	orrs r2, r0
	strh r2, [r1]
_08088328:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end MapGridSetMetatileIdAt

	thumb_func_start MapGridSetMetatileEntryAt
@ void MapGridSetMetatileEntryAt(s32 x, s32 y, u16 metatileEntry)
MapGridSetMetatileEntryAt: @ 8088338
	push {r4,r5,lr}
	adds r3, r0, 0
	lsls r2, 16
	lsrs r5, r2, 16
	cmp r3, 0
	blt _08088364
	ldr r2, =gUnknown_03005DC0
	ldr r4, [r2]
	cmp r3, r4
	bge _08088364
	cmp r1, 0
	blt _08088364
	ldr r0, [r2, 0x4]
	cmp r1, r0
	bge _08088364
	adds r0, r4, 0
	muls r0, r1
	adds r0, r3, r0
	ldr r1, [r2, 0x8]
	lsls r0, 1
	adds r0, r1
	strh r5, [r0]
_08088364:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end MapGridSetMetatileEntryAt

	thumb_func_start GetBehaviorByMetatileId
@ u16 GetBehaviorByMetatileId(u16 metatileId)
GetBehaviorByMetatileId: @ 8088370
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	adds r3, r2, 0
	ldr r0, =0x000001ff
	cmp r2, r0
	bhi _08088394
	ldr r0, =gMapHeader
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	ldr r1, [r0, 0x10]
	lsls r0, r2, 1
	b _080883B2
	.pool
_08088394:
	ldr r0, =0x000003ff
	cmp r2, r0
	bls _080883A4
	movs r0, 0xFF
	b _080883B6
	.pool
_080883A4:
	ldr r0, =gMapHeader
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldr r1, [r0, 0x10]
	lsls r0, r3, 1
	adds r0, r1
	ldr r1, =0xfffffc00
_080883B2:
	adds r0, r1
	ldrh r0, [r0]
_080883B6:
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetBehaviorByMetatileId

	thumb_func_start save_serialize_map
save_serialize_map: @ 80883C4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	adds r4, r1, 0
	adds r4, 0x34
	ldr r0, =gUnknown_03005DC0
	ldr r0, [r0]
	mov r8, r0
	movs r0, 0
	ldrsh r6, [r1, r0]
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	adds r1, r0, 0
	adds r1, 0xE
	cmp r0, r1
	bge _08088420
	mov r12, r1
	ldr r1, =gUnknown_02032318
	mov r9, r1
	lsls r7, r6, 1
_080883F2:
	adds r1, r6, 0
	adds r3, r1, 0
	adds r3, 0xF
	adds r5, r0, 0x1
	cmp r1, r3
	bge _0808841A
	mov r2, r8
	muls r2, r0
	adds r0, r2, 0
	lsls r0, 1
	add r0, r9
	adds r2, r7, r0
	subs r1, r3, r1
_0808840C:
	ldrh r0, [r2]
	strh r0, [r4]
	adds r4, 0x2
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bne _0808840C
_0808841A:
	adds r0, r5, 0
	cmp r0, r12
	blt _080883F2
_08088420:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end save_serialize_map

	thumb_func_start sub_8088438
sub_8088438: @ 8088438
	push {r4,lr}
	movs r2, 0
	movs r1, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	adds r3, r0, 0
	adds r3, 0x34
	ldr r4, =0x000001ff
_08088448:
	lsls r0, r1, 1
	adds r0, r3, r0
	ldrh r0, [r0]
	orrs r2, r0
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r4
	bls _08088448
	cmp r2, 0
	beq _0808846C
	movs r0, 0
	b _0808846E
	.pool
_0808846C:
	movs r0, 0x1
_0808846E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8088438

	thumb_func_start sav2_mapdata_clear
sav2_mapdata_clear: @ 8088474
	push {lr}
	sub sp, 0x4
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	adds r1, 0x34
	ldr r2, =0x01000100
	mov r0, sp
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sav2_mapdata_clear

	thumb_func_start mapdata_from_sav2
mapdata_from_sav2: @ 808849C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	adds r7, r0, 0
	adds r7, 0x34
	bl sub_8088438
	cmp r0, 0
	bne _080885AC
	ldr r0, =gUnknown_03005DC0
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, [r4]
	movs r2, 0
	ldrsh r1, [r0, r2]
	mov r10, r1
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	mov r8, r1
	mov r6, r8
	adds r0, r6, 0
	adds r0, 0xE
	cmp r6, r0
	bge _0808855A
_080884D6:
	cmp r6, r8
	bne _080884EC
	cmp r6, 0
	beq _080884EC
	movs r0, 0
	mov r9, r0
	b _08088508
	.pool
_080884EC:
	mov r0, r8
	adds r0, 0xD
	movs r1, 0xFF
	mov r9, r1
	cmp r6, r0
	bne _08088508
	ldr r0, =gMapHeader
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	subs r0, 0x1
	cmp r6, r0
	beq _08088508
	movs r2, 0x1
	mov r9, r2
_08088508:
	mov r5, r10
	adds r0, r5, 0
	adds r0, 0xF
	mov r1, r8
	adds r1, 0xE
	str r1, [sp, 0x8]
	adds r2, r6, 0x1
	str r2, [sp, 0x4]
	cmp r5, r0
	bge _08088552
	ldr r0, [sp]
	lsls r3, r0, 16
_08088520:
	ldr r1, [sp]
	adds r0, r1, 0
	muls r0, r6
	adds r0, r5, r0
	lsls r0, 1
	ldr r1, =gUnknown_02032318
	adds r4, r0, r1
	adds r0, r4, 0
	lsrs r1, r3, 16
	mov r2, r9
	str r3, [sp, 0xC]
	bl sub_8088BF0
	lsls r0, 24
	ldr r3, [sp, 0xC]
	cmp r0, 0
	bne _08088546
	ldrh r0, [r7]
	strh r0, [r4]
_08088546:
	adds r7, 0x2
	adds r5, 0x1
	mov r0, r10
	adds r0, 0xF
	cmp r5, r0
	blt _08088520
_08088552:
	ldr r6, [sp, 0x4]
	ldr r2, [sp, 0x8]
	cmp r6, r2
	blt _080884D6
_0808855A:
	mov r5, r10
	adds r0, r5, 0
	adds r0, 0xF
	cmp r5, r0
	bge _080885A8
	mov r0, r8
	subs r0, 0x1
	lsls r0, 16
	mov r9, r0
	lsls r4, r5, 16
	mov r0, r8
	adds r0, 0xD
	lsls r7, r0, 16
_08088574:
	mov r0, r8
	cmp r0, 0
	beq _08088584
	asrs r0, r4, 16
	mov r2, r9
	asrs r1, r2, 16
	bl sub_80D423C
_08088584:
	ldr r0, =gMapHeader
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	subs r0, 0x1
	cmp r6, r0
	bge _08088598
	asrs r0, r4, 16
	asrs r1, r7, 16
	bl sub_80D42B8
_08088598:
	movs r0, 0x80
	lsls r0, 9
	adds r4, r0
	adds r5, 0x1
	mov r0, r10
	adds r0, 0xF
	cmp r5, r0
	blt _08088574
_080885A8:
	bl sav2_mapdata_clear
_080885AC:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end mapdata_from_sav2

	thumb_func_start sub_80885C4
sub_80885C4: @ 80885C4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r3, r0, 24
	adds r2, r3, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x34
	str r0, [sp, 0x4]
	ldr r0, =gUnknown_03005DC0
	ldr r0, [r0]
	str r0, [sp]
	movs r4, 0
	mov r9, r4
	mov r8, r4
	movs r0, 0
	ldrsh r6, [r1, r0]
	str r6, [sp, 0x8]
	movs r4, 0x2
	ldrsh r5, [r1, r4]
	movs r7, 0xF
	movs r6, 0xE
	mov r12, r6
	cmp r3, 0x2
	beq _0808861E
	cmp r3, 0x2
	bgt _08088614
	cmp r3, 0x1
	beq _08088626
	b _0808863E
	.pool
_08088614:
	cmp r2, 0x3
	beq _08088630
	cmp r2, 0x4
	beq _08088638
	b _0808863E
_0808861E:
	adds r5, 0x1
	movs r0, 0xD
	mov r12, r0
	b _0808863E
_08088626:
	movs r1, 0x1
	mov r8, r1
	movs r3, 0xD
	mov r12, r3
	b _0808863E
_08088630:
	ldr r4, [sp, 0x8]
	adds r4, 0x1
	str r4, [sp, 0x8]
	b _0808863C
_08088638:
	movs r6, 0x1
	mov r9, r6
_0808863C:
	movs r7, 0xE
_0808863E:
	movs r1, 0
	cmp r1, r12
	bge _08088682
	ldr r0, =gUnknown_02032318
	mov r10, r0
_08088648:
	adds r4, r1, 0x1
	cmp r7, 0
	beq _0808867C
	adds r0, r1, r5
	ldr r3, [sp]
	adds r2, r3, 0
	muls r2, r0
	add r1, r8
	lsls r0, r1, 4
	subs r0, r1
	add r0, r9
	ldr r6, [sp, 0x8]
	adds r2, r6, r2
	adds r3, r7, 0
	lsls r2, 1
	add r2, r10
	lsls r0, 1
	ldr r6, [sp, 0x4]
	adds r1, r0, r6
_0808866E:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, 0x2
	adds r2, 0x2
	subs r3, 0x1
	cmp r3, 0
	bne _0808866E
_0808867C:
	adds r1, r4, 0
	cmp r1, r12
	blt _08088648
_08088682:
	bl sav2_mapdata_clear
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80885C4

	thumb_func_start GetMapBorderIdAt
@ u32 GetMapBorderIdAt(s32 x, s32 y)
GetMapBorderIdAt: @ 808869C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	cmp r4, 0
	blt _080886D8
	ldr r1, =gUnknown_03005DC0
	ldr r2, [r1]
	cmp r4, r2
	bge _080886D8
	cmp r5, 0
	blt _080886D8
	ldr r0, [r1, 0x4]
	cmp r5, r0
	bge _080886D8
	adds r0, r2, 0
	muls r0, r5
	adds r0, r4, r0
	ldr r1, [r1, 0x8]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	ldr r0, =0x000003ff
	cmp r1, r0
	beq _08088770
	b _08088700
	.pool
_080886D8:
	ldr r0, =gMapHeader
	ldr r3, [r0]
	adds r1, r4, 0x1
	movs r2, 0x1
	ands r1, r2
	adds r0, r5, 0x1
	ands r0, r2
	lsls r0, 1
	adds r1, r0
	ldr r0, [r3, 0x8]
	lsls r1, 1
	adds r1, r0
	ldrh r1, [r1]
	movs r2, 0xC0
	lsls r2, 4
	adds r0, r2, 0
	orrs r0, r1
	ldr r1, =0x000003ff
	cmp r0, r1
	beq _08088770
_08088700:
	ldr r1, =gUnknown_03005DC0
	ldr r0, [r1]
	subs r0, 0x8
	cmp r4, r0
	blt _0808872C
	ldr r0, =gUnknown_02037340
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08088770
	movs r0, 0x4
	b _08088782
	.pool
_0808872C:
	cmp r4, 0x6
	bgt _08088744
	ldr r0, =gUnknown_02037340
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08088770
	movs r0, 0x3
	b _08088782
	.pool
_08088744:
	ldr r0, [r1, 0x4]
	subs r0, 0x7
	cmp r5, r0
	blt _08088760
	ldr r0, =gUnknown_02037340
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08088770
	movs r0, 0x1
	b _08088782
	.pool
_08088760:
	cmp r5, 0x6
	bgt _08088780
	ldr r0, =gUnknown_02037340
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0808877C
_08088770:
	movs r0, 0x1
	negs r0, r0
	b _08088782
	.pool
_0808877C:
	movs r0, 0x2
	b _08088782
_08088780:
	movs r0, 0
_08088782:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end GetMapBorderIdAt

	thumb_func_start GetPostCameraMoveMapBorderId
@ u32 GetPostCameraMoveMapBorderId(s32 deltaX, s32 deltaY)
GetPostCameraMoveMapBorderId: @ 8088788
	push {r4,lr}
	adds r3, r1, 0
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	movs r4, 0
	ldrsh r2, [r1, r4]
	adds r0, 0x7
	adds r2, r0
	movs r0, 0x2
	ldrsh r1, [r1, r0]
	adds r3, 0x7
	adds r1, r3
	adds r0, r2, 0
	bl GetMapBorderIdAt
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetPostCameraMoveMapBorderId

	thumb_func_start CanCameraMoveInDirection
@ bool32 CanCameraMoveInDirection(u8 direction)
CanCameraMoveInDirection: @ 80887B0
	push {r4,r5,lr}
	ldr r1, =gSaveBlock1Ptr
	ldr r4, [r1]
	movs r1, 0
	ldrsh r3, [r4, r1]
	ldr r2, =gUnknown_08339D64
	lsls r0, 3
	adds r1, r0, r2
	ldr r1, [r1]
	adds r1, 0x7
	adds r3, r1
	movs r5, 0x2
	ldrsh r1, [r4, r5]
	adds r2, 0x4
	adds r0, r2
	ldr r0, [r0]
	adds r0, 0x7
	adds r1, r0
	adds r0, r3, 0
	bl GetMapBorderIdAt
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080887F0
	movs r0, 0x1
	b _080887F2
	.pool
_080887F0:
	movs r0, 0
_080887F2:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end CanCameraMoveInDirection

	thumb_func_start sub_80887F8
sub_80887F8: @ 80887F8
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	adds r7, r3, 0
	bl mapconnection_get_mapheader
	adds r3, r0, 0
	cmp r4, 0x2
	beq _08088860
	cmp r4, 0x2
	bgt _08088816
	cmp r4, 0x1
	beq _0808884C
	b _08088872
_08088816:
	cmp r4, 0x3
	beq _08088834
	cmp r4, 0x4
	bne _08088872
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	negs r0, r6
	strh r0, [r1]
	ldr r2, [r5, 0x4]
	ldrh r0, [r1, 0x2]
	subs r0, r2
	b _08088870
	.pool
_08088834:
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, [r3]
	ldr r0, [r0]
	strh r0, [r1]
	ldr r2, [r5, 0x4]
	ldrh r0, [r1, 0x2]
	subs r0, r2
	b _08088870
	.pool
_0808884C:
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r2, [r5, 0x4]
	ldrh r0, [r1]
	subs r0, r2
	strh r0, [r1]
	negs r0, r7
	b _08088870
	.pool
_08088860:
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r2, [r5, 0x4]
	ldrh r0, [r1]
	subs r0, r2
	strh r0, [r1]
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
_08088870:
	strh r0, [r1, 0x2]
_08088872:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80887F8

	thumb_func_start CameraMove
@ u8 CameraMove(s32 deltaX, s32 deltaY)
CameraMove: @ 808887C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r10, r0
	mov r9, r1
	ldr r1, =gUnknown_02037334
	ldrb r0, [r1]
	movs r1, 0x2
	negs r1, r1
	ands r1, r0
	ldr r2, =gUnknown_02037334
	strb r1, [r2]
	mov r0, r10
	mov r1, r9
	bl GetPostCameraMoveMapBorderId
	adds r7, r0, 0
	adds r0, r7, 0x1
	cmp r0, 0x1
	bhi _080888C4
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldrh r0, [r1]
	add r0, r10
	strh r0, [r1]
	ldrh r0, [r1, 0x2]
	add r0, r9
	strh r0, [r1, 0x2]
	b _08088932
	.pool
_080888C4:
	bl save_serialize_map
	bl sub_81BE72C
	ldr r1, =gSaveBlock1Ptr
	ldr r0, [r1]
	movs r2, 0
	ldrsh r5, [r0, r2]
	movs r1, 0x2
	ldrsh r6, [r0, r1]
	lsls r2, r7, 24
	lsrs r2, 24
	mov r8, r2
	mov r0, r8
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_8088950
	adds r4, r0, 0
	adds r1, r7, 0
	mov r2, r10
	mov r3, r9
	bl sub_80887F8
	ldrb r0, [r4, 0x8]
	ldrb r1, [r4, 0x9]
	bl mliX_load_map
	ldr r1, =gUnknown_02037334
	ldrb r0, [r1]
	movs r1, 0x1
	orrs r0, r1
	ldr r2, =gUnknown_02037334
	strb r0, [r2]
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r2, 0
	ldrsh r0, [r1, r2]
	subs r5, r0
	ldr r0, =gUnknown_02037334
	str r5, [r0, 0x4]
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	subs r6, r0
	ldr r0, =gUnknown_02037334
	str r6, [r0, 0x8]
	ldrh r0, [r1]
	add r0, r10
	strh r0, [r1]
	ldrh r0, [r1, 0x2]
	add r0, r9
	strh r0, [r1, 0x2]
	mov r0, r8
	bl sub_80885C4
_08088932:
	ldr r0, =gUnknown_02037334
	ldrb r0, [r0]
	lsls r0, 31
	lsrs r0, 31
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CameraMove

	thumb_func_start sub_8088950
sub_8088950: @ 8088950
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r9, r1
	mov r8, r2
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gMapHeader
	ldr r0, [r0, 0xC]
	ldr r7, [r0]
	ldr r4, [r0, 0x4]
	movs r5, 0
	cmp r5, r7
	bge _08088998
_0808896E:
	ldrb r0, [r4]
	cmp r0, r6
	bne _08088990
	adds r0, r6, 0
	mov r1, r9
	mov r2, r8
	adds r3, r4, 0
	bl sub_80889A8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08088990
	adds r0, r4, 0
	b _0808899A
	.pool
_08088990:
	adds r5, 0x1
	adds r4, 0xC
	cmp r5, r7
	blt _0808896E
_08088998:
	movs r0, 0
_0808899A:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8088950

	thumb_func_start sub_80889A8
sub_80889A8: @ 80889A8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r1, 0
	mov r8, r2
	adds r5, r3, 0
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	adds r0, r5, 0
	bl mapconnection_get_mapheader
	adds r2, r0, 0
	cmp r4, 0x1
	blt _08088A00
	cmp r4, 0x2
	bgt _080889E0
	ldr r0, =gMapHeader
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r0, [r2]
	ldr r2, [r0]
	ldr r3, [r5, 0x4]
	adds r0, r7, 0
	b _080889F2
	.pool
_080889E0:
	cmp r6, 0x4
	bgt _08088A00
	ldr r0, =gMapHeader
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	ldr r0, [r2]
	ldr r2, [r0, 0x4]
	ldr r3, [r5, 0x4]
	mov r0, r8
_080889F2:
	bl sub_8088A0C
	lsls r0, 24
	lsrs r0, 24
	b _08088A02
	.pool
_08088A00:
	movs r0, 0
_08088A02:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80889A8

	thumb_func_start sub_8088A0C
sub_8088A0C: @ 8088A0C
	push {r4,lr}
	adds r4, r0, 0
	adds r0, r2, 0
	adds r2, r3, 0
	cmp r3, 0
	bge _08088A1A
	movs r3, 0
_08088A1A:
	adds r2, r0, r2
	cmp r2, r1
	bge _08088A22
	adds r1, r2, 0
_08088A22:
	cmp r3, r4
	bgt _08088A2E
	cmp r4, r1
	bgt _08088A2E
	movs r0, 0x1
	b _08088A30
_08088A2E:
	movs r0, 0
_08088A30:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8088A0C

	thumb_func_start sub_8088A38
sub_8088A38: @ 8088A38
	push {lr}
	cmp r0, 0
	blt _08088A46
	cmp r0, r1
	bge _08088A46
	movs r0, 0x1
	b _08088A48
_08088A46:
	movs r0, 0
_08088A48:
	pop {r1}
	bx r1
	thumb_func_end sub_8088A38

	thumb_func_start sub_8088A4C
sub_8088A4C: @ 8088A4C
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	bl mapconnection_get_mapheader
	adds r1, r0, 0
	ldrb r0, [r4]
	cmp r0, 0x1
	blt _08088A84
	cmp r0, 0x2
	bgt _08088A72
	ldr r0, [r4, 0x4]
	subs r0, r5, r0
	ldr r1, [r1]
	ldr r1, [r1]
	bl sub_8088A38
	b _08088A86
_08088A72:
	cmp r0, 0x4
	bgt _08088A84
	ldr r0, [r4, 0x4]
	subs r0, r6, r0
	ldr r1, [r1]
	ldr r1, [r1, 0x4]
	bl sub_8088A38
	b _08088A86
_08088A84:
	movs r0, 0
_08088A86:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8088A4C

	thumb_func_start sub_8088A8C
sub_8088A8C: @ 8088A8C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r1, 16
	lsrs r1, 16
	ldr r2, =gMapHeader
	ldr r0, [r2, 0xC]
	cmp r0, 0
	bne _08088AB4
	b _08088B2A
	.pool
_08088AB0:
	adds r0, r4, 0
	b _08088B2C
_08088AB4:
	ldr r7, [r0]
	ldr r4, [r0, 0x4]
	movs r6, 0
	cmp r6, r7
	bge _08088B2A
	lsls r0, r1, 16
	asrs r5, r0, 16
	mov r9, r2
	mov r1, r8
	lsls r0, r1, 16
	asrs r0, 16
	mov r10, r0
_08088ACC:
	ldrb r1, [r4]
	adds r3, r1, 0
	subs r0, r1, 0x5
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _08088B22
	cmp r1, 0x2
	bne _08088AE2
	cmp r5, 0x6
	bgt _08088B22
_08088AE2:
	cmp r1, 0x1
	bne _08088AF2
	mov r2, r9
	ldr r0, [r2]
	ldr r0, [r0, 0x4]
	adds r0, 0x7
	cmp r5, r0
	blt _08088B22
_08088AF2:
	mov r0, r8
	lsls r2, r0, 16
	cmp r1, 0x3
	bne _08088B00
	mov r1, r10
	cmp r1, 0x6
	bgt _08088B22
_08088B00:
	cmp r3, 0x4
	bne _08088B12
	asrs r1, r2, 16
	mov r3, r9
	ldr r0, [r3]
	ldr r0, [r0]
	adds r0, 0x7
	cmp r1, r0
	blt _08088B22
_08088B12:
	asrs r1, r2, 16
	subs r1, 0x7
	adds r0, r4, 0
	subs r2, r5, 0x7
	bl sub_8088A4C
	cmp r0, 0x1
	beq _08088AB0
_08088B22:
	adds r6, 0x1
	adds r4, 0xC
	cmp r6, r7
	blt _08088ACC
_08088B2A:
	movs r0, 0
_08088B2C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8088A8C

	thumb_func_start sub_8088B3C
sub_8088B3C: @ 8088B3C
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	ldr r2, =gSaveBlock1Ptr
	ldr r2, [r2]
	subs r0, 0x7
	strh r0, [r2]
	subs r1, 0x7
	strh r1, [r2, 0x2]
	bx lr
	.pool
	thumb_func_end sub_8088B3C

	thumb_func_start sav1_camera_get_focus_coords
sav1_camera_get_focus_coords: @ 8088B58
	ldr r2, =gSaveBlock1Ptr
	ldr r3, [r2]
	ldrh r2, [r3]
	adds r2, 0x7
	strh r2, [r0]
	ldrh r0, [r3, 0x2]
	adds r0, 0x7
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sav1_camera_get_focus_coords

	thumb_func_start SetCameraCoords
@ void SetCameraCoords(u16 x, u16 y)
SetCameraCoords: @ 8088B70
	ldr r2, =gSaveBlock1Ptr
	ldr r2, [r2]
	strh r0, [r2]
	strh r1, [r2, 0x2]
	bx lr
	.pool
	thumb_func_end SetCameraCoords

	thumb_func_start GetCameraCoords
@ void GetCameraCoords(u16 *x, u16 *y)
GetCameraCoords: @ 8088B80
	ldr r2, =gSaveBlock1Ptr
	ldr r3, [r2]
	ldrh r2, [r3]
	strh r2, [r0]
	ldrh r0, [r3, 0x2]
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end GetCameraCoords

	thumb_func_start sub_8088B94
sub_8088B94: @ 8088B94
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r3, r1, 0
	adds r5, r2, 0
	cmp r4, 0
	blt _08088BE6
	ldr r2, =gUnknown_03005DC0
	ldr r1, [r2]
	cmp r4, r1
	bge _08088BE6
	cmp r3, 0
	blt _08088BE6
	ldr r0, [r2, 0x4]
	cmp r3, r0
	bge _08088BE6
	cmp r5, 0
	beq _08088BD4
	adds r0, r1, 0
	muls r0, r3
	adds r0, r4, r0
	ldr r1, [r2, 0x8]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r3, 0xC0
	lsls r3, 4
	adds r2, r3, 0
	orrs r1, r2
	strh r1, [r0]
	b _08088BE6
	.pool
_08088BD4:
	muls r1, r3
	adds r1, r4, r1
	ldr r0, [r2, 0x8]
	lsls r1, 1
	adds r1, r0
	ldrh r2, [r1]
	ldr r0, =0x0000f3ff
	ands r0, r2
	strh r0, [r1]
_08088BE6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8088B94

	thumb_func_start sub_8088BF0
sub_8088BF0: @ 8088BF0
	push {lr}
	adds r3, r0, 0
	lsls r1, 16
	lsrs r0, r1, 16
	adds r1, r0, 0
	lsls r2, 24
	lsrs r2, 24
	cmp r2, 0xFF
	beq _08088C24
	cmp r2, 0
	bne _08088C0C
	lsls r0, 1
	subs r3, r0
	b _08088C10
_08088C0C:
	lsls r0, r1, 1
	adds r3, r0
_08088C10:
	ldrh r1, [r3]
	ldr r0, =0x000003ff
	ands r0, r1
	adds r1, r2, 0
	bl sub_80FADE4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08088C2C
_08088C24:
	movs r0, 0
	b _08088C2E
	.pool
_08088C2C:
	movs r0, 0x1
_08088C2E:
	pop {r1}
	bx r1
	thumb_func_end sub_8088BF0

	thumb_func_start copy_tileset_patterns_to_vram
@ void copy_tileset_patterns_to_vram(tileset *tileset, int num_tiles, int offset)
copy_tileset_patterns_to_vram: @ 8088C34
	push {r4-r7,lr}
	sub sp, 0x4
	adds r3, r0, 0
	lsls r1, 16
	lsrs r4, r1, 16
	adds r6, r4, 0
	lsls r2, 16
	lsrs r5, r2, 16
	adds r7, r5, 0
	cmp r3, 0
	beq _08088C70
	ldrb r0, [r3]
	cmp r0, 0
	bne _08088C60
	ldr r1, [r3, 0x4]
	lsls r2, r4, 21
	lsrs r2, 16
	movs r0, 0x2
	adds r3, r5, 0
	bl LoadBgTiles
	b _08088C70
_08088C60:
	ldr r1, [r3, 0x4]
	lsls r2, r6, 5
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	adds r3, r7, 0
	bl decompress_and_copy_tile_data_to_vram
_08088C70:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end copy_tileset_patterns_to_vram

	thumb_func_start copy_tileset_patterns_to_vram2
@ void copy_tileset_patterns_to_vram2(tileset *tileset, int num_tiles, int offset)
copy_tileset_patterns_to_vram2: @ 8088C78
	push {r4-r7,lr}
	sub sp, 0x4
	adds r3, r0, 0
	lsls r1, 16
	lsrs r4, r1, 16
	adds r6, r4, 0
	lsls r2, 16
	lsrs r5, r2, 16
	adds r7, r5, 0
	cmp r3, 0
	beq _08088CB4
	ldrb r0, [r3]
	cmp r0, 0
	bne _08088CA4
	ldr r1, [r3, 0x4]
	lsls r2, r4, 21
	lsrs r2, 16
	movs r0, 0x2
	adds r3, r5, 0
	bl LoadBgTiles
	b _08088CB4
_08088CA4:
	ldr r1, [r3, 0x4]
	lsls r2, r6, 5
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	adds r3, r7, 0
	bl copy_decompressed_tile_data_to_vram_autofree
_08088CB4:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end copy_tileset_patterns_to_vram2

	thumb_func_start nullsub_3
nullsub_3: @ 8088CBC
	bx lr
	thumb_func_end nullsub_3

	thumb_func_start nullsub_90
nullsub_90: @ 8088CC0
	bx lr
	thumb_func_end nullsub_90

	thumb_func_start apply_map_tileset_palette
@ void apply_map_tileset_palette(tileset *tileset, int dest_offset, int size)
apply_map_tileset_palette: @ 8088CC4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r1, 16
	lsrs r5, r1, 16
	mov r8, r5
	lsls r6, r2, 16
	lsrs r7, r6, 16
	adds r2, r7, 0
	movs r1, 0
	mov r0, sp
	strh r1, [r0]
	cmp r4, 0
	beq _08088D42
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	bne _08088D18
	mov r0, sp
	adds r1, r5, 0
	movs r2, 0x2
	bl LoadPalette
	ldr r0, [r4, 0x8]
	adds r0, 0x2
	adds r5, 0x1
	lsls r5, 16
	lsrs r5, 16
	subs r4, r7, 0x2
	lsls r2, r4, 16
	lsrs r2, 16
	adds r1, r5, 0
	bl LoadPalette
	lsls r4, 15
	lsrs r4, 16
	adds r0, r5, 0
	adds r1, r4, 0
	bl nullsub_3
	b _08088D42
_08088D18:
	cmp r0, 0x1
	bne _08088D32
	ldr r0, [r4, 0x8]
	adds r0, 0xC0
	adds r1, r5, 0
	adds r2, r7, 0
	bl LoadPalette
	lsrs r1, r6, 17
	adds r0, r5, 0
	bl nullsub_3
	b _08088D42
_08088D32:
	ldr r0, [r4, 0x8]
	mov r1, r8
	bl LoadCompressedPalette
	lsrs r1, r6, 17
	mov r0, r8
	bl nullsub_3
_08088D42:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end apply_map_tileset_palette

	thumb_func_start copy_map_tileset1_to_vram
@ void copy_map_tileset1_to_vram(mapdata_header *a1)
copy_map_tileset1_to_vram: @ 8088D50
	push {lr}
	ldr r0, [r0, 0x10]
	movs r1, 0x80
	lsls r1, 2
	movs r2, 0
	bl copy_tileset_patterns_to_vram
	pop {r0}
	bx r0
	thumb_func_end copy_map_tileset1_to_vram

	thumb_func_start copy_map_tileset2_to_vram
@ void copy_map_tileset2_to_vram(mapdata_header *a1)
copy_map_tileset2_to_vram: @ 8088D64
	push {lr}
	ldr r0, [r0, 0x14]
	movs r2, 0x80
	lsls r2, 2
	adds r1, r2, 0
	bl copy_tileset_patterns_to_vram
	pop {r0}
	bx r0
	thumb_func_end copy_map_tileset2_to_vram

	thumb_func_start copy_map_tileset2_to_vram_2
@ void copy_map_tileset2_to_vram_2(mapdata_header *a1)
copy_map_tileset2_to_vram_2: @ 8088D78
	push {lr}
	ldr r0, [r0, 0x14]
	movs r2, 0x80
	lsls r2, 2
	adds r1, r2, 0
	bl copy_tileset_patterns_to_vram2
	pop {r0}
	bx r0
	thumb_func_end copy_map_tileset2_to_vram_2

	thumb_func_start apply_map_tileset1_palette
@ void apply_map_tileset1_palette(mapdata_header *a1)
apply_map_tileset1_palette: @ 8088D8C
	push {lr}
	ldr r0, [r0, 0x10]
	movs r1, 0
	movs r2, 0xC0
	bl apply_map_tileset_palette
	pop {r0}
	bx r0
	thumb_func_end apply_map_tileset1_palette

	thumb_func_start apply_map_tileset2_palette
@ void apply_map_tileset2_palette(mapdata_header *a1)
apply_map_tileset2_palette: @ 8088D9C
	push {lr}
	ldr r0, [r0, 0x14]
	movs r1, 0x60
	movs r2, 0xE0
	bl apply_map_tileset_palette
	pop {r0}
	bx r0
	thumb_func_end apply_map_tileset2_palette

	thumb_func_start copy_map_tileset1_tileset2_to_vram
@ void copy_map_tileset1_tileset2_to_vram(mapdata_header *a1)
copy_map_tileset1_tileset2_to_vram: @ 8088DAC
	push {r4,r5,lr}
	adds r5, r0, 0
	cmp r5, 0
	beq _08088DCC
	ldr r0, [r5, 0x10]
	movs r4, 0x80
	lsls r4, 2
	adds r1, r4, 0
	movs r2, 0
	bl copy_tileset_patterns_to_vram2
	ldr r0, [r5, 0x14]
	adds r1, r4, 0
	adds r2, r4, 0
	bl copy_tileset_patterns_to_vram2
_08088DCC:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end copy_map_tileset1_tileset2_to_vram

	thumb_func_start apply_map_tileset1_tileset2_palette
@ void apply_map_tileset1_tileset2_palette(mapdata_header *a1)
apply_map_tileset1_tileset2_palette: @ 8088DD4
	push {r4,lr}
	adds r4, r0, 0
	cmp r4, 0
	beq _08088DE6
	bl apply_map_tileset1_palette
	adds r0, r4, 0
	bl apply_map_tileset2_palette
_08088DE6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end apply_map_tileset1_tileset2_palette

	.align 2, 0 @ Don't pad with nop.
