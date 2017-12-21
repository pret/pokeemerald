	.include "MPlayDef.s"

	.equ	song_595_grp, voicegroup_86A0754
	.equ	song_595_pri, 4
	.equ	song_595_rev, 0
	.equ	song_595_mvl, 127
	.equ	song_595_key, 0
	.equ	song_595_tbs, 1
	.equ	song_595_exg, 0
	.equ	song_595_cmp, 1

	.section .rodata
	.global	song_595
	.align	2

@********************** Track  1 **********************@

song_595_1:
	.byte	KEYSH , song_595_key+0
	.byte	TEMPO , 120*song_595_tbs/2
	.byte		VOICE , 36
	.byte		VOL   , 127*song_595_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_595:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_595_pri	@ Priority
	.byte	song_595_rev	@ Reverb.

	.word	song_595_grp

	.word	song_595_1

	.end
