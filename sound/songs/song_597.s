	.include "MPlayDef.s"

	.equ	song_597_grp, voicegroup_86A0754
	.equ	song_597_pri, 4
	.equ	song_597_rev, 0
	.equ	song_597_mvl, 127
	.equ	song_597_key, 0
	.equ	song_597_tbs, 1
	.equ	song_597_exg, 0
	.equ	song_597_cmp, 1

	.section .rodata
	.global	song_597
	.align	2

@********************** Track  1 **********************@

song_597_1:
	.byte	KEYSH , song_597_key+0
	.byte	TEMPO , 120*song_597_tbs/2
	.byte		VOICE , 38
	.byte		VOL   , 127*song_597_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_597:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_597_pri	@ Priority
	.byte	song_597_rev	@ Reverb.

	.word	song_597_grp

	.word	song_597_1

	.end
