	.include "MPlayDef.s"

	.equ	song_584_grp, voicegroup_86A0754
	.equ	song_584_pri, 4
	.equ	song_584_rev, 0
	.equ	song_584_mvl, 127
	.equ	song_584_key, 0
	.equ	song_584_tbs, 1
	.equ	song_584_exg, 0
	.equ	song_584_cmp, 1

	.section .rodata
	.global	song_584
	.align	2

@********************** Track  1 **********************@

song_584_1:
	.byte	KEYSH , song_584_key+0
	.byte	TEMPO , 120*song_584_tbs/2
	.byte		VOICE , 25
	.byte		VOL   , 127*song_584_mvl/mxv
	.byte		TIE   , Cn3 , v127
	.byte	W96
song_584_1_B1:
	.byte	W96
	.byte	GOTO
	 .word	song_584_1_B1
	.byte	W48
	.byte		EOT   , Cn3 
	.byte	FINE

@******************************************************@
	.align	2

song_584:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_584_pri	@ Priority
	.byte	song_584_rev	@ Reverb.

	.word	song_584_grp

	.word	song_584_1

	.end
