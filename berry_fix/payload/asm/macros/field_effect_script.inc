	.macro loadtiles address
	.byte 0
	.4byte \address
	.endm

	.macro loadfadedpal address
	.byte 1
	.4byte \address
	.endm

	.macro loadpal address
	.byte 2
	.4byte \address
	.endm

	.macro callnative address
	.byte 3
	.4byte \address
	.endm

	.macro end
	.byte 4
	.endm

	.macro loadgfx_callnative tiles_address, palette_address, function_address
	.byte 5
	.4byte \tiles_address
	.4byte \palette_address
	.4byte \function_address
	.endm

	.macro loadtiles_callnative tiles_address, function_address
	.byte 6
	.4byte \tiles_address
	.4byte \function_address
	.endm

	.macro loadfadedpal_callnative palette_address, function_address
	.byte 7
	.4byte \palette_address
	.4byte \function_address
	.endm
