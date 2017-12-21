	.include "MPlayDef.s"

	.equ	song_252_grp, voicegroup_86A0154
	.equ	song_252_pri, 5
	.equ	song_252_rev, reverb_set+50
	.equ	song_252_mvl, 127
	.equ	song_252_key, 0
	.equ	song_252_tbs, 1
	.equ	song_252_exg, 0
	.equ	song_252_cmp, 1

	.section .rodata
	.global	song_252
	.align	2

@********************** Track  1 **********************@

song_252_1:
	.byte	KEYSH , song_252_key+0
	.byte	TEMPO , 310*song_252_tbs/2
	.byte		VOICE , 10
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 127*song_252_mvl/mxv
	.byte		BEND  , c_v+2
	.byte		N01   , Cs4 , v072
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@********************** Track  2 **********************@

song_252_2:
	.byte		VOL   , 127*song_252_mvl/mxv
	.byte	KEYSH , song_252_key+0
	.byte		VOICE , 124
	.byte		N01   , Cs5 , v072
	.byte	W01
	.byte		        Ds5 , v104
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

song_252:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_252_pri	@ Priority
	.byte	song_252_rev	@ Reverb.

	.word	song_252_grp

	.word	song_252_1
	.word	song_252_2

	.end
