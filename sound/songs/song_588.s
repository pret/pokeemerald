	.include "MPlayDef.s"

	.equ	song_588_grp, voicegroup_86A0754
	.equ	song_588_pri, 4
	.equ	song_588_rev, 0
	.equ	song_588_mvl, 127
	.equ	song_588_key, 0
	.equ	song_588_tbs, 1
	.equ	song_588_exg, 0
	.equ	song_588_cmp, 1

	.section .rodata
	.global	song_588
	.align	2

@********************** Track  1 **********************@

song_588_1:
	.byte	KEYSH , song_588_key+0
	.byte	TEMPO , 120*song_588_tbs/2
	.byte		VOICE , 29
	.byte		VOL   , 127*song_588_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_588:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_588_pri	@ Priority
	.byte	song_588_rev	@ Reverb.

	.word	song_588_grp

	.word	song_588_1

	.end
