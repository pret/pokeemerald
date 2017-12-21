	.include "MPlayDef.s"

	.equ	song_590_grp, voicegroup_86A0754
	.equ	song_590_pri, 4
	.equ	song_590_rev, 0
	.equ	song_590_mvl, 127
	.equ	song_590_key, 0
	.equ	song_590_tbs, 1
	.equ	song_590_exg, 0
	.equ	song_590_cmp, 1

	.section .rodata
	.global	song_590
	.align	2

@********************** Track  1 **********************@

song_590_1:
	.byte	KEYSH , song_590_key+0
	.byte	TEMPO , 120*song_590_tbs/2
	.byte		VOICE , 31
	.byte		VOL   , 127*song_590_mvl/mxv
	.byte		TIE   , Cn3 , v127
	.byte	W96
song_590_1_B1:
	.byte	W96
	.byte	GOTO
	 .word	song_590_1_B1
	.byte	W48
	.byte		EOT   , Cn3 
	.byte	FINE

@******************************************************@
	.align	2

song_590:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_590_pri	@ Priority
	.byte	song_590_rev	@ Reverb.

	.word	song_590_grp

	.word	song_590_1

	.end
