	.include "MPlayDef.s"

	.equ	song_265_grp, voicegroup_86A0154
	.equ	song_265_pri, 5
	.equ	song_265_rev, reverb_set+50
	.equ	song_265_mvl, 127
	.equ	song_265_key, 0
	.equ	song_265_tbs, 1
	.equ	song_265_exg, 0
	.equ	song_265_cmp, 1

	.section .rodata
	.global	song_265
	.align	2

@********************** Track  1 **********************@

song_265_1:
	.byte	KEYSH , song_265_key+0
	.byte	TEMPO , 92*song_265_tbs/2
	.byte		VOICE , 116
	.byte		VOL   , 127*song_265_mvl/mxv
	.byte		PAN   , c_v-62
	.byte		N32   , Fn3 , v127
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	FINE

@********************** Track  2 **********************@

song_265_2:
	.byte	KEYSH , song_265_key+0
	.byte		VOICE , 117
	.byte		VOL   , 127*song_265_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		BEND  , c_v+1
	.byte		N32   , An3 , v100
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	FINE

@******************************************************@
	.align	2

song_265:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_265_pri	@ Priority
	.byte	song_265_rev	@ Reverb.

	.word	song_265_grp

	.word	song_265_1
	.word	song_265_2

	.end
