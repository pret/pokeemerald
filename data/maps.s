#include "constants/global.h"
#include "generated/constants/layouts.h"
#include "constants/map_types.h"
#include "constants/maps.h"
#include "constants/weather.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"
#include "constants/trainer_hill.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.include "build/assets/data/layouts/layouts.inc"
	.include "build/assets/data/layouts/layouts_table.inc"
	.include "build/assets/data/maps/headers.inc"
	.include "build/assets/data/maps/groups.inc"
	.include "build/assets/data/maps/connections.inc"
