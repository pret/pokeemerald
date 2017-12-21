	.include "MPlayDef.s"

	.equ	song_577_grp, voicegroup_86A0754
	.equ	song_577_pri, 4
	.equ	song_577_rev, 0
	.equ	song_577_mvl, 127
	.equ	song_577_key, 0
	.equ	song_577_tbs, 1
	.equ	song_577_exg, 0
	.equ	song_577_cmp, 1

	.section .rodata
	.global	song_577
	.align	2

@********************** Track  1 **********************@

song_577_1:
	.byte	KEYSH , song_577_key+0
	.byte	TEMPO , 120*song_577_tbs/2
	.byte		VOICE , 18
	.byte		VOL   , 127*song_577_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_577:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_577_pri	@ Priority
	.byte	song_577_rev	@ Reverb.

	.word	song_577_grp

	.word	song_577_1

	.end
