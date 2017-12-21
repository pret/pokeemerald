	.include "MPlayDef.s"

	.equ	song_589_grp, voicegroup_86A0754
	.equ	song_589_pri, 4
	.equ	song_589_rev, 0
	.equ	song_589_mvl, 127
	.equ	song_589_key, 0
	.equ	song_589_tbs, 1
	.equ	song_589_exg, 0
	.equ	song_589_cmp, 1

	.section .rodata
	.global	song_589
	.align	2

@********************** Track  1 **********************@

song_589_1:
	.byte	KEYSH , song_589_key+0
	.byte	TEMPO , 120*song_589_tbs/2
	.byte		VOICE , 30
	.byte		VOL   , 127*song_589_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_589:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_589_pri	@ Priority
	.byte	song_589_rev	@ Reverb.

	.word	song_589_grp

	.word	song_589_1

	.end
