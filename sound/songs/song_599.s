	.include "MPlayDef.s"

	.equ	song_599_grp, voicegroup_86A0754
	.equ	song_599_pri, 4
	.equ	song_599_rev, 0
	.equ	song_599_mvl, 127
	.equ	song_599_key, 0
	.equ	song_599_tbs, 1
	.equ	song_599_exg, 0
	.equ	song_599_cmp, 1

	.section .rodata
	.global	song_599
	.align	2

@********************** Track  1 **********************@

song_599_1:
	.byte	KEYSH , song_599_key+0
	.byte	TEMPO , 120*song_599_tbs/2
	.byte		VOICE , 40
	.byte		VOL   , 127*song_599_mvl/mxv
	.byte		TIE   , Cn3 , v127
	.byte	W96
song_599_1_B1:
	.byte	W96
	.byte	GOTO
	 .word	song_599_1_B1
	.byte	W48
	.byte		EOT   , Cn3 
	.byte	FINE

@******************************************************@
	.align	2

song_599:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_599_pri	@ Priority
	.byte	song_599_rev	@ Reverb.

	.word	song_599_grp

	.word	song_599_1

	.end
