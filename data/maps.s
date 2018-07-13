#include "constants/maps.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.include "data/layouts.inc"
	.include "data/layouts_table.inc"
	.include "data/maps/headers.inc"
	.include "data/maps/groups.inc"
	.include "data/maps/connections.inc"
