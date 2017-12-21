	.include "MPlayDef.s"

	.equ	song_563_grp, voicegroup_86A0754
	.equ	song_563_pri, 4
	.equ	song_563_rev, 0
	.equ	song_563_mvl, 127
	.equ	song_563_key, 0
	.equ	song_563_tbs, 1
	.equ	song_563_exg, 0
	.equ	song_563_cmp, 1

	.section .rodata
	.global	song_563
	.align	2

@********************** Track  1 **********************@

song_563_1:
	.byte	KEYSH , song_563_key+0
	.byte	TEMPO , 120*song_563_tbs/2
	.byte		VOICE , 4
	.byte		VOL   , 127*song_563_mvl/mxv
	.byte		TIE   , Cn3 , v127
	.byte	W96
song_563_1_B1:
	.byte	W96
	.byte	GOTO
	 .word	song_563_1_B1
	.byte	W48
	.byte		EOT   , Cn3 
	.byte	FINE

@******************************************************@
	.align	2

song_563:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_563_pri	@ Priority
	.byte	song_563_rev	@ Reverb.

	.word	song_563_grp

	.word	song_563_1

	.end
