	.include "MPlayDef.s"

	.equ	song_566_grp, voicegroup_86A0754
	.equ	song_566_pri, 4
	.equ	song_566_rev, 0
	.equ	song_566_mvl, 127
	.equ	song_566_key, 0
	.equ	song_566_tbs, 1
	.equ	song_566_exg, 0
	.equ	song_566_cmp, 1

	.section .rodata
	.global	song_566
	.align	2

@********************** Track  1 **********************@

song_566_1:
	.byte	KEYSH , song_566_key+0
	.byte	TEMPO , 120*song_566_tbs/2
	.byte		VOICE , 7
	.byte		VOL   , 127*song_566_mvl/mxv
	.byte		TIE   , Cn3 , v127
	.byte	W96
song_566_1_B1:
	.byte	W96
	.byte	GOTO
	 .word	song_566_1_B1
	.byte	W48
	.byte		EOT   , Cn3 
	.byte	FINE

@******************************************************@
	.align	2

song_566:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_566_pri	@ Priority
	.byte	song_566_rev	@ Reverb.

	.word	song_566_grp

	.word	song_566_1

	.end
