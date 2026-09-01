#include "constants/field_weather.h"
@ The first .byte argument of each macro below is an index into gFieldEffectScriptFuncs

	.macro field_eff_loadtiles address:req
	.byte 0
	.4byte \address
	.endm

	.macro field_eff_loadfadedpal address:req, color_map_type=COLOR_MAP_DARK_CONTRAST
	.byte 1
	.4byte \address
	.byte  \color_map_type
	.endm

	.macro field_eff_loadpal address:req
	.byte 2
	.4byte \address
	.endm

	.macro field_eff_callnative address:req
	.byte 3
	.4byte \address
	.endm

	.macro field_eff_end
	.byte 4
	.endm

	.macro field_eff_loadgfx_callnative tiles_address:req, palette_address:req, function_address:req, color_map_type=COLOR_MAP_DARK_CONTRAST
	.byte 5
	.4byte \tiles_address
	.4byte \palette_address
	.byte  \color_map_type
	.4byte \function_address
	.endm

	.macro field_eff_loadtiles_callnative tiles_address:req, function_address:req
	.byte 6
	.4byte \tiles_address
	.4byte \function_address
	.endm

	.macro field_eff_loadfadedpal_callnative palette_address:req, function_address:req, color_map_type=COLOR_MAP_DARK_CONTRAST
	.byte 7
	.4byte \palette_address
	.byte  \color_map_type
	.4byte \function_address
	.endm
