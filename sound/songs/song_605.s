	.include "MPlayDef.s"

	.equ	song_605_grp, voicegroup_86A0754
	.equ	song_605_pri, 4
	.equ	song_605_rev, 0
	.equ	song_605_mvl, 127
	.equ	song_605_key, 0
	.equ	song_605_tbs, 1
	.equ	song_605_exg, 0
	.equ	song_605_cmp, 1

	.section .rodata
	.global	song_605
	.align	2

@********************** Track  1 **********************@

song_605_1:
	.byte	KEYSH , song_605_key+0
	.byte	TEMPO , 120*song_605_tbs/2
	.byte		VOICE , 46
	.byte		VOL   , 127*song_605_mvl/mxv
	.byte		TIE   , Cn3 , v127
	.byte	W96
song_605_1_B1:
	.byte	W96
	.byte	GOTO
	 .word	song_605_1_B1
	.byte	W48
	.byte		EOT   , Cn3 
	.byte	FINE

@******************************************************@
	.align	2

song_605:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_605_pri	@ Priority
	.byte	song_605_rev	@ Reverb.

	.word	song_605_grp

	.word	song_605_1

	.end
