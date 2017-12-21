	.include "MPlayDef.s"

	.equ	song_585_grp, voicegroup_86A0754
	.equ	song_585_pri, 4
	.equ	song_585_rev, 0
	.equ	song_585_mvl, 127
	.equ	song_585_key, 0
	.equ	song_585_tbs, 1
	.equ	song_585_exg, 0
	.equ	song_585_cmp, 1

	.section .rodata
	.global	song_585
	.align	2

@********************** Track  1 **********************@

song_585_1:
	.byte	KEYSH , song_585_key+0
	.byte	TEMPO , 120*song_585_tbs/2
	.byte		VOICE , 26
	.byte		VOL   , 127*song_585_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_585:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_585_pri	@ Priority
	.byte	song_585_rev	@ Reverb.

	.word	song_585_grp

	.word	song_585_1

	.end
