	.section .rodata

	.include "asm/macros/m4a.inc"

	.include "sound/voice_groups.inc"

	@ keysplit tables, programmable wave data
	.incbin "baserom.gba", 0x6b4698, 0x328

	.include "sound/music_player_table.inc"
	.include "sound/song_table.inc"

	@ direct sound data
	.incbin "baserom.gba", 0x6b5d04, 0x246338
