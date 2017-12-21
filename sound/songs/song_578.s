	.include "MPlayDef.s"

	.equ	song_578_grp, voicegroup_86A0754
	.equ	song_578_pri, 4
	.equ	song_578_rev, 0
	.equ	song_578_mvl, 127
	.equ	song_578_key, 0
	.equ	song_578_tbs, 1
	.equ	song_578_exg, 0
	.equ	song_578_cmp, 1

	.section .rodata
	.global	song_578
	.align	2

@********************** Track  1 **********************@

song_578_1:
	.byte	KEYSH , song_578_key+0
	.byte	TEMPO , 120*song_578_tbs/2
	.byte		VOICE , 19
	.byte		VOL   , 117*song_578_mvl/mxv
	.byte		TIE   , Cn3 , v127
	.byte	W96
song_578_1_B1:
	.byte	W96
	.byte	GOTO
	 .word	song_578_1_B1
	.byte	W48
	.byte		EOT   , Cn3 
	.byte	FINE

@******************************************************@
	.align	2

song_578:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_578_pri	@ Priority
	.byte	song_578_rev	@ Reverb.

	.word	song_578_grp

	.word	song_578_1

	.end
