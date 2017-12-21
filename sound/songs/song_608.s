	.include "MPlayDef.s"

	.equ	song_608_grp, voicegroup_86A0754
	.equ	song_608_pri, 4
	.equ	song_608_rev, 0
	.equ	song_608_mvl, 127
	.equ	song_608_key, 0
	.equ	song_608_tbs, 1
	.equ	song_608_exg, 0
	.equ	song_608_cmp, 1

	.section .rodata
	.global	song_608
	.align	2

@********************** Track  1 **********************@

song_608_1:
	.byte	KEYSH , song_608_key+0
	.byte	TEMPO , 120*song_608_tbs/2
	.byte		VOICE , 49
	.byte		VOL   , 127*song_608_mvl/mxv
	.byte		TIE   , Cn3 , v127
	.byte	W96
song_608_1_B1:
	.byte	W96
	.byte	GOTO
	 .word	song_608_1_B1
	.byte	W48
	.byte		EOT   , Cn3 
	.byte	FINE

@******************************************************@
	.align	2

song_608:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_608_pri	@ Priority
	.byte	song_608_rev	@ Reverb.

	.word	song_608_grp

	.word	song_608_1

	.end
