	.include "MPlayDef.s"

	.equ	song_579_grp, voicegroup_86A0754
	.equ	song_579_pri, 4
	.equ	song_579_rev, 0
	.equ	song_579_mvl, 127
	.equ	song_579_key, 0
	.equ	song_579_tbs, 1
	.equ	song_579_exg, 0
	.equ	song_579_cmp, 1

	.section .rodata
	.global	song_579
	.align	2

@********************** Track  1 **********************@

song_579_1:
	.byte	KEYSH , song_579_key+0
	.byte	TEMPO , 120*song_579_tbs/2
	.byte		VOICE , 20
	.byte		VOL   , 127*song_579_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_579:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_579_pri	@ Priority
	.byte	song_579_rev	@ Reverb.

	.word	song_579_grp

	.word	song_579_1

	.end
