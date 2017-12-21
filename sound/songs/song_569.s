	.include "MPlayDef.s"

	.equ	song_569_grp, voicegroup_86A0754
	.equ	song_569_pri, 4
	.equ	song_569_rev, 0
	.equ	song_569_mvl, 127
	.equ	song_569_key, 0
	.equ	song_569_tbs, 1
	.equ	song_569_exg, 0
	.equ	song_569_cmp, 1

	.section .rodata
	.global	song_569
	.align	2

@********************** Track  1 **********************@

song_569_1:
	.byte	KEYSH , song_569_key+0
	.byte	TEMPO , 120*song_569_tbs/2
	.byte		VOICE , 10
	.byte		VOL   , 127*song_569_mvl/mxv
	.byte		TIE   , Cn3 , v127
	.byte	W96
song_569_1_B1:
	.byte	W96
	.byte	GOTO
	 .word	song_569_1_B1
	.byte	W48
	.byte		EOT   , Cn3 
	.byte	FINE

@******************************************************@
	.align	2

song_569:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_569_pri	@ Priority
	.byte	song_569_rev	@ Reverb.

	.word	song_569_grp

	.word	song_569_1

	.end
