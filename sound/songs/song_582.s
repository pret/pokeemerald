	.include "MPlayDef.s"

	.equ	song_582_grp, voicegroup_86A0754
	.equ	song_582_pri, 4
	.equ	song_582_rev, 0
	.equ	song_582_mvl, 127
	.equ	song_582_key, 0
	.equ	song_582_tbs, 1
	.equ	song_582_exg, 0
	.equ	song_582_cmp, 1

	.section .rodata
	.global	song_582
	.align	2

@********************** Track  1 **********************@

song_582_1:
	.byte	KEYSH , song_582_key+0
	.byte	TEMPO , 120*song_582_tbs/2
	.byte		VOICE , 23
	.byte		VOL   , 127*song_582_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_582:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_582_pri	@ Priority
	.byte	song_582_rev	@ Reverb.

	.word	song_582_grp

	.word	song_582_1

	.end
