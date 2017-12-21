	.include "MPlayDef.s"

	.equ	song_583_grp, voicegroup_86A0754
	.equ	song_583_pri, 4
	.equ	song_583_rev, 0
	.equ	song_583_mvl, 127
	.equ	song_583_key, 0
	.equ	song_583_tbs, 1
	.equ	song_583_exg, 0
	.equ	song_583_cmp, 1

	.section .rodata
	.global	song_583
	.align	2

@********************** Track  1 **********************@

song_583_1:
	.byte	KEYSH , song_583_key+0
	.byte	TEMPO , 120*song_583_tbs/2
	.byte		VOICE , 24
	.byte		VOL   , 127*song_583_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_583:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_583_pri	@ Priority
	.byte	song_583_rev	@ Reverb.

	.word	song_583_grp

	.word	song_583_1

	.end
