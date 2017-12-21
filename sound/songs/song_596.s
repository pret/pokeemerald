	.include "MPlayDef.s"

	.equ	song_596_grp, voicegroup_86A0754
	.equ	song_596_pri, 4
	.equ	song_596_rev, 0
	.equ	song_596_mvl, 127
	.equ	song_596_key, 0
	.equ	song_596_tbs, 1
	.equ	song_596_exg, 0
	.equ	song_596_cmp, 1

	.section .rodata
	.global	song_596
	.align	2

@********************** Track  1 **********************@

song_596_1:
	.byte	KEYSH , song_596_key+0
	.byte	TEMPO , 120*song_596_tbs/2
	.byte		VOICE , 37
	.byte		VOL   , 127*song_596_mvl/mxv
	.byte		TIE   , Cn3 , v127
	.byte	W96
song_596_1_B1:
	.byte	W96
	.byte	GOTO
	 .word	song_596_1_B1
	.byte	W48
	.byte		EOT   , Cn3 
	.byte	FINE

@******************************************************@
	.align	2

song_596:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_596_pri	@ Priority
	.byte	song_596_rev	@ Reverb.

	.word	song_596_grp

	.word	song_596_1

	.end
