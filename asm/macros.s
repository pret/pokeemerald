	.include "asm/macros/function.s"
	.include "asm/macros/event.s"
	.include "asm/macros/window.s"
	.include "asm/macros/pokemon_data.s"
	.include "asm/macros/ec.s"
	.include "asm/macros/map.s"

	.macro region_map_entry x, y, width, height, name
	.byte \x
	.byte \y
	.byte \width
	.byte \height
	.4byte gMapName_\name
	.endm

	.macro obj_tiles address, uncompressed_size, tag
	.4byte \address
	.2byte \uncompressed_size
	.2byte \tag
	.endm

	.macro obj_pal address, tag
	.4byte \address
	.2byte \tag
	.2byte 0; padding
	.endm

	.macro zero_fill count
	.fill \count
	.endm
