	.include "MPlayDef.s"

	.equ	song_559_grp, voicegroup_86A0754
	.equ	song_559_pri, 4
	.equ	song_559_rev, 0
	.equ	song_559_mvl, 127
	.equ	song_559_key, 0
	.equ	song_559_tbs, 1
	.equ	song_559_exg, 0
	.equ	song_559_cmp, 1

	.section .rodata
	.global	song_559
	.align	2

@********************** Track  1 **********************@

song_559_1:
	.byte	KEYSH , song_559_key+0
	.byte	TEMPO , 120*song_559_tbs/2
	.byte		VOICE , 0
	.byte		VOL   , 127*song_559_mvl/mxv
	.byte		N44   , Cn3 , v127
	.byte	W44
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

song_559:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_559_pri	@ Priority
	.byte	song_559_rev	@ Reverb.

	.word	song_559_grp

	.word	song_559_1

	.end
