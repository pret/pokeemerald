	.include "MPlayDef.s"

	.equ	song_581_grp, voicegroup_86A0754
	.equ	song_581_pri, 4
	.equ	song_581_rev, 0
	.equ	song_581_mvl, 127
	.equ	song_581_key, 0
	.equ	song_581_tbs, 1
	.equ	song_581_exg, 0
	.equ	song_581_cmp, 1

	.section .rodata
	.global	song_581
	.align	2

@********************** Track  1 **********************@

song_581_1:
	.byte	KEYSH , song_581_key+0
	.byte	TEMPO , 120*song_581_tbs/2
	.byte		VOICE , 22
	.byte		VOL   , 127*song_581_mvl/mxv
	.byte		TIE   , Cn3 , v127
	.byte	W96
song_581_1_B1:
	.byte	W96
	.byte	GOTO
	 .word	song_581_1_B1
	.byte	W48
	.byte		EOT   , Cn3 
	.byte	FINE

@******************************************************@
	.align	2

song_581:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_581_pri	@ Priority
	.byte	song_581_rev	@ Reverb.

	.word	song_581_grp

	.word	song_581_1

	.end
