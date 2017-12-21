	.include "MPlayDef.s"

	.equ	song_575_grp, voicegroup_86A0754
	.equ	song_575_pri, 4
	.equ	song_575_rev, 0
	.equ	song_575_mvl, 127
	.equ	song_575_key, 0
	.equ	song_575_tbs, 1
	.equ	song_575_exg, 0
	.equ	song_575_cmp, 1

	.section .rodata
	.global	song_575
	.align	2

@********************** Track  1 **********************@

song_575_1:
	.byte	KEYSH , song_575_key+0
	.byte	TEMPO , 120*song_575_tbs/2
	.byte		VOICE , 16
	.byte		VOL   , 127*song_575_mvl/mxv
	.byte		TIE   , Cn3 , v127
	.byte	W96
song_575_1_B1:
	.byte	W96
	.byte	GOTO
	 .word	song_575_1_B1
	.byte	W48
	.byte		EOT   , Cn3 
	.byte	FINE

@******************************************************@
	.align	2

song_575:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_575_pri	@ Priority
	.byte	song_575_rev	@ Reverb.

	.word	song_575_grp

	.word	song_575_1

	.end
