	.include "MPlayDef.s"

	.equ	song_602_grp, voicegroup_86A0754
	.equ	song_602_pri, 4
	.equ	song_602_rev, 0
	.equ	song_602_mvl, 127
	.equ	song_602_key, 0
	.equ	song_602_tbs, 1
	.equ	song_602_exg, 0
	.equ	song_602_cmp, 1

	.section .rodata
	.global	song_602
	.align	2

@********************** Track  1 **********************@

song_602_1:
	.byte	KEYSH , song_602_key+0
	.byte	TEMPO , 120*song_602_tbs/2
	.byte		VOICE , 43
	.byte		VOL   , 127*song_602_mvl/mxv
	.byte		TIE   , Cn3 , v127
	.byte	W96
song_602_1_B1:
	.byte	W96
	.byte	GOTO
	 .word	song_602_1_B1
	.byte	W48
	.byte		EOT   , Cn3 
	.byte	FINE

@******************************************************@
	.align	2

song_602:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_602_pri	@ Priority
	.byte	song_602_rev	@ Reverb.

	.word	song_602_grp

	.word	song_602_1

	.end
