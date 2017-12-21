	.include "MPlayDef.s"

	.equ	song_586_grp, voicegroup_86A0754
	.equ	song_586_pri, 4
	.equ	song_586_rev, 0
	.equ	song_586_mvl, 127
	.equ	song_586_key, 0
	.equ	song_586_tbs, 1
	.equ	song_586_exg, 0
	.equ	song_586_cmp, 1

	.section .rodata
	.global	song_586
	.align	2

@********************** Track  1 **********************@

song_586_1:
	.byte	KEYSH , song_586_key+0
	.byte	TEMPO , 120*song_586_tbs/2
	.byte		VOICE , 27
	.byte		VOL   , 127*song_586_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_586:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_586_pri	@ Priority
	.byte	song_586_rev	@ Reverb.

	.word	song_586_grp

	.word	song_586_1

	.end
