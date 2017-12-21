	.include "MPlayDef.s"

	.equ	song_560_grp, voicegroup_86A0754
	.equ	song_560_pri, 4
	.equ	song_560_rev, 0
	.equ	song_560_mvl, 127
	.equ	song_560_key, 0
	.equ	song_560_tbs, 1
	.equ	song_560_exg, 0
	.equ	song_560_cmp, 1

	.section .rodata
	.global	song_560
	.align	2

@********************** Track  1 **********************@

song_560_1:
	.byte	KEYSH , song_560_key+0
	.byte	TEMPO , 120*song_560_tbs/2
	.byte		VOICE , 1
	.byte		VOL   , 117*song_560_mvl/mxv
	.byte		TIE   , Cn3 , v127
	.byte	W96
song_560_1_B1:
	.byte	W96
	.byte	GOTO
	 .word	song_560_1_B1
	.byte	W48
	.byte		EOT   , Cn3 
	.byte	FINE

@******************************************************@
	.align	2

song_560:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_560_pri	@ Priority
	.byte	song_560_rev	@ Reverb.

	.word	song_560_grp

	.word	song_560_1

	.end
