	.include "MPlayDef.s"

	.equ	song_601_grp, voicegroup_86A0754
	.equ	song_601_pri, 4
	.equ	song_601_rev, 0
	.equ	song_601_mvl, 127
	.equ	song_601_key, 0
	.equ	song_601_tbs, 1
	.equ	song_601_exg, 0
	.equ	song_601_cmp, 1

	.section .rodata
	.global	song_601
	.align	2

@********************** Track  1 **********************@

song_601_1:
	.byte	KEYSH , song_601_key+0
	.byte	TEMPO , 120*song_601_tbs/2
	.byte		VOICE , 42
	.byte		VOL   , 127*song_601_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_601:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_601_pri	@ Priority
	.byte	song_601_rev	@ Reverb.

	.word	song_601_grp

	.word	song_601_1

	.end
