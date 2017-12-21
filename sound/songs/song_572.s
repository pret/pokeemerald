	.include "MPlayDef.s"

	.equ	song_572_grp, voicegroup_86A0754
	.equ	song_572_pri, 4
	.equ	song_572_rev, 0
	.equ	song_572_mvl, 127
	.equ	song_572_key, 0
	.equ	song_572_tbs, 1
	.equ	song_572_exg, 0
	.equ	song_572_cmp, 1

	.section .rodata
	.global	song_572
	.align	2

@********************** Track  1 **********************@

song_572_1:
	.byte	KEYSH , song_572_key+0
	.byte	TEMPO , 120*song_572_tbs/2
	.byte		VOICE , 13
	.byte		VOL   , 127*song_572_mvl/mxv
	.byte		TIE   , Cn3 , v127
	.byte	W96
song_572_1_B1:
	.byte	W96
	.byte	GOTO
	 .word	song_572_1_B1
	.byte	W48
	.byte		EOT   , Cn3 
	.byte	FINE

@******************************************************@
	.align	2

song_572:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_572_pri	@ Priority
	.byte	song_572_rev	@ Reverb.

	.word	song_572_grp

	.word	song_572_1

	.end
