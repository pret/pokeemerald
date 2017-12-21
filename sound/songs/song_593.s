	.include "MPlayDef.s"

	.equ	song_593_grp, voicegroup_86A0754
	.equ	song_593_pri, 4
	.equ	song_593_rev, 0
	.equ	song_593_mvl, 127
	.equ	song_593_key, 0
	.equ	song_593_tbs, 1
	.equ	song_593_exg, 0
	.equ	song_593_cmp, 1

	.section .rodata
	.global	song_593
	.align	2

@********************** Track  1 **********************@

song_593_1:
	.byte	KEYSH , song_593_key+0
	.byte	TEMPO , 120*song_593_tbs/2
	.byte		VOICE , 34
	.byte		VOL   , 127*song_593_mvl/mxv
	.byte		TIE   , Cn3 , v127
	.byte	W96
song_593_1_B1:
	.byte	W96
	.byte	GOTO
	 .word	song_593_1_B1
	.byte	W48
	.byte		EOT   , Cn3 
	.byte	FINE

@******************************************************@
	.align	2

song_593:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_593_pri	@ Priority
	.byte	song_593_rev	@ Reverb.

	.word	song_593_grp

	.word	song_593_1

	.end
