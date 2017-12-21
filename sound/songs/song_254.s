	.include "MPlayDef.s"

	.equ	song_254_grp, voicegroup_86A0154
	.equ	song_254_pri, 5
	.equ	song_254_rev, reverb_set+50
	.equ	song_254_mvl, 127
	.equ	song_254_key, 0
	.equ	song_254_tbs, 1
	.equ	song_254_exg, 0
	.equ	song_254_cmp, 1

	.section .rodata
	.global	song_254
	.align	2

@********************** Track  1 **********************@

song_254_1:
	.byte	KEYSH , song_254_key+0
	.byte	TEMPO , 310*song_254_tbs/2
	.byte		VOICE , 3
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 100*song_254_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N02   , Bn3 , v120
	.byte	W03
	.byte	W03
	.byte	W02
	.byte		        En4 , v127
	.byte	W01
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@********************** Track  2 **********************@

song_254_2:
	.byte	KEYSH , song_254_key+0
	.byte		VOICE , 126
	.byte		VOL   , 100*song_254_mvl/mxv
	.byte	W03
	.byte	W01
	.byte		N01   , Cn2 , v120
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

song_254:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_254_pri	@ Priority
	.byte	song_254_rev	@ Reverb.

	.word	song_254_grp

	.word	song_254_1
	.word	song_254_2

	.end
