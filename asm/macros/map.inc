	.macro new_map_group
	.set cur_map_group, cur_map_group + 1
	.set cur_map_num, 0
	.endm

	.macro map_group map_name
	.set GROUP_\map_name, cur_map_group
	.set MAP_\map_name, cur_map_num
	.set cur_map_num, cur_map_num + 1
	.endm

	.macro map map_name
	.byte GROUP_\map_name
	.byte MAP_\map_name
	.endm
