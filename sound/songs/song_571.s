	.include "MPlayDef.s"

	.equ	song_571_grp, voicegroup_86A0754
	.equ	song_571_pri, 4
	.equ	song_571_rev, 0
	.equ	song_571_mvl, 127
	.equ	song_571_key, 0
	.equ	song_571_tbs, 1
	.equ	song_571_exg, 0
	.equ	song_571_cmp, 1

	.section .rodata
	.global	song_571
	.align	2

@********************** Track  1 **********************@

song_571_1:
	.byte	KEYSH , song_571_key+0
	.byte	TEMPO , 120*song_571_tbs/2
	.byte		VOICE , 12
	.byte		VOL   , 127*song_571_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_571:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_571_pri	@ Priority
	.byte	song_571_rev	@ Reverb.

	.word	song_571_grp

	.word	song_571_1

	.end
