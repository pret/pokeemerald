	.include "MPlayDef.s"

	.equ	song_249_grp, voicegroup_86A0154
	.equ	song_249_pri, 5
	.equ	song_249_rev, reverb_set+50
	.equ	song_249_mvl, 127
	.equ	song_249_key, 0
	.equ	song_249_tbs, 1
	.equ	song_249_exg, 0
	.equ	song_249_cmp, 1

	.section .rodata
	.global	song_249
	.align	2

@********************** Track  1 **********************@

song_249_1:
	.byte	KEYSH , song_249_key+0
	.byte	TEMPO , 182*song_249_tbs/2
	.byte		VOICE , 125
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		PAN   , c_v+0
	.byte		VOL   , 127*song_249_mvl/mxv
	.byte		BEND  , c_v+2
	.byte		N01   , Cn4 , v127
	.byte	W03
	.byte		VOICE , 124
	.byte		N01   , Cn5 , v064
	.byte	W21
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

song_249:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_249_pri	@ Priority
	.byte	song_249_rev	@ Reverb.

	.word	song_249_grp

	.word	song_249_1

	.end
