	.include "MPlayDef.s"

	.equ	song_587_grp, voicegroup_86A0754
	.equ	song_587_pri, 4
	.equ	song_587_rev, 0
	.equ	song_587_mvl, 127
	.equ	song_587_key, 0
	.equ	song_587_tbs, 1
	.equ	song_587_exg, 0
	.equ	song_587_cmp, 1

	.section .rodata
	.global	song_587
	.align	2

@********************** Track  1 **********************@

song_587_1:
	.byte	KEYSH , song_587_key+0
	.byte	TEMPO , 120*song_587_tbs/2
	.byte		VOICE , 28
	.byte		VOL   , 127*song_587_mvl/mxv
	.byte		TIE   , Cn3 , v127
	.byte	W96
song_587_1_B1:
	.byte	W96
	.byte	GOTO
	 .word	song_587_1_B1
	.byte	W48
	.byte		EOT   , Cn3 
	.byte	FINE

@******************************************************@
	.align	2

song_587:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_587_pri	@ Priority
	.byte	song_587_rev	@ Reverb.

	.word	song_587_grp

	.word	song_587_1

	.end
