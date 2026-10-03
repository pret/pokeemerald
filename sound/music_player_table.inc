    .bss
    .align 2

	mplay_track BGM, 10
	mplay_track SE1, 3
	mplay_track SE2, 9
	mplay_track SE3, 1

	.section .rodata

	.align 2
gMPlayTable::
	music_player BGM, 0
	music_player SE1, 1
	music_player SE2, 1
	music_player SE3, 0
