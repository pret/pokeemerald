	.macro field_eff_loadtiles address
	.byte 0
	.4byte \address
	.endm

	.macro field_eff_loadfadedpal address
	.byte 1
	.4byte \address
	.endm

	.macro field_eff_loadpal address
	.byte 2
	.4byte \address
	.endm

	.macro field_eff_callnative address
	.byte 3
	.4byte \address
	.endm

	.macro field_eff_end
	.byte 4
	.endm

	.macro field_eff_loadgfx_callnative tiles_address, palette_address, function_address
	.byte 5
	.4byte \tiles_address
	.4byte \palette_address
	.4byte \function_address
	.endm

	.macro field_eff_loadtiles_callnative tiles_address, function_address
	.byte 6
	.4byte \tiles_address
	.4byte \function_address
	.endm

	.macro field_eff_loadfadedpal_callnative palette_address, function_address
	.byte 7
	.4byte \palette_address
	.4byte \function_address
	.endm
