	.include "MPlayDef.s"

	.equ	song_607_grp, voicegroup_86A0754
	.equ	song_607_pri, 4
	.equ	song_607_rev, 0
	.equ	song_607_mvl, 127
	.equ	song_607_key, 0
	.equ	song_607_tbs, 1
	.equ	song_607_exg, 0
	.equ	song_607_cmp, 1

	.section .rodata
	.global	song_607
	.align	2

@********************** Track  1 **********************@

song_607_1:
	.byte	KEYSH , song_607_key+0
	.byte	TEMPO , 120*song_607_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 127*song_607_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_607:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_607_pri	@ Priority
	.byte	song_607_rev	@ Reverb.

	.word	song_607_grp

	.word	song_607_1

	.end
