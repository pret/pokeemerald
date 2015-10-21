	.include "asm/macros/function.s"
	.include "asm/macros/event.s"
	.include "asm/macros/window.s"
	.include "asm/macros/pokemon_data.s"
	.include "asm/macros/ec.s"

	.macro include_range start, end
	.incbin "base_emerald.gba", \start, \end - \start
	.endm

	.macro region_map_entry x, y, width, height, name
	.byte \x
	.byte \y
	.byte \width
	.byte \height
	.4byte gMapName_\name
	.endm
