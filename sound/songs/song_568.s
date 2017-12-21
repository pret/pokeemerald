	.include "MPlayDef.s"

	.equ	song_568_grp, voicegroup_86A0754
	.equ	song_568_pri, 4
	.equ	song_568_rev, 0
	.equ	song_568_mvl, 127
	.equ	song_568_key, 0
	.equ	song_568_tbs, 1
	.equ	song_568_exg, 0
	.equ	song_568_cmp, 1

	.section .rodata
	.global	song_568
	.align	2

@********************** Track  1 **********************@

song_568_1:
	.byte	KEYSH , song_568_key+0
	.byte	TEMPO , 120*song_568_tbs/2
	.byte		VOICE , 9
	.byte		VOL   , 127*song_568_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_568:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_568_pri	@ Priority
	.byte	song_568_rev	@ Reverb.

	.word	song_568_grp

	.word	song_568_1

	.end
