    .bss
    .align 2

	mplay_track gMPlayTrack_BGM, 10
	mplay_track gMPlayTrack_SE1, 3
	mplay_track gMPlayTrack_SE2, 9
	mplay_track gMPlayTrack_SE3, 1

	.section .rodata

	.align 2
gMPlayTable::
	music_player gMPlayInfo_BGM, gMPlayTrack_BGM, 0
	music_player gMPlayInfo_SE1, gMPlayTrack_SE1, 1
	music_player gMPlayInfo_SE2, gMPlayTrack_SE2, 1
	music_player gMPlayInfo_SE3, gMPlayTrack_SE3, 0
