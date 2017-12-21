	.include "MPlayDef.s"

	.equ	song_561_grp, voicegroup_86A0754
	.equ	song_561_pri, 4
	.equ	song_561_rev, 0
	.equ	song_561_mvl, 127
	.equ	song_561_key, 0
	.equ	song_561_tbs, 1
	.equ	song_561_exg, 0
	.equ	song_561_cmp, 1

	.section .rodata
	.global	song_561
	.align	2

@********************** Track  1 **********************@

song_561_1:
	.byte	KEYSH , song_561_key+0
	.byte	TEMPO , 120*song_561_tbs/2
	.byte		VOICE , 2
	.byte		VOL   , 127*song_561_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_561:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_561_pri	@ Priority
	.byte	song_561_rev	@ Reverb.

	.word	song_561_grp

	.word	song_561_1

	.end
