	.include "MPlayDef.s"

	.equ	song_564_grp, voicegroup_86A0754
	.equ	song_564_pri, 4
	.equ	song_564_rev, 0
	.equ	song_564_mvl, 127
	.equ	song_564_key, 0
	.equ	song_564_tbs, 1
	.equ	song_564_exg, 0
	.equ	song_564_cmp, 1

	.section .rodata
	.global	song_564
	.align	2

@********************** Track  1 **********************@

song_564_1:
	.byte	KEYSH , song_564_key+0
	.byte	TEMPO , 120*song_564_tbs/2
	.byte		VOICE , 5
	.byte		VOL   , 127*song_564_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_564:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_564_pri	@ Priority
	.byte	song_564_rev	@ Reverb.

	.word	song_564_grp

	.word	song_564_1

	.end
