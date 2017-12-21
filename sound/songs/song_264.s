	.include "MPlayDef.s"

	.equ	song_264_grp, voicegroup_86A0154
	.equ	song_264_pri, 5
	.equ	song_264_rev, reverb_set+50
	.equ	song_264_mvl, 127
	.equ	song_264_key, 0
	.equ	song_264_tbs, 1
	.equ	song_264_exg, 0
	.equ	song_264_cmp, 1

	.section .rodata
	.global	song_264
	.align	2

@********************** Track  1 **********************@

song_264_1:
	.byte	KEYSH , song_264_key+0
	.byte	TEMPO , 120*song_264_tbs/2
	.byte		VOICE , 10
	.byte		VOL   , 110*song_264_mvl/mxv
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		N01   , Ds3 , v112
	.byte	W04
	.byte		        Gs1 
	.byte	W01
	.byte		        Bn1 , v056
	.byte	W04
	.byte		        Bn1 , v024
	.byte	W02
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@********************** Track  2 **********************@

song_264_2:
	.byte	KEYSH , song_264_key+0
	.byte		VOICE , 82
	.byte		VOL   , 110*song_264_mvl/mxv
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BEND  , c_v+0
	.byte		N01   , Cs3 , v064
	.byte	W01
	.byte		        Fs4 , v032
	.byte	W01
	.byte		BEND  , c_v+0
	.byte		N01   , Gs5 , v028
	.byte	W01
	.byte		BEND  , c_v+63
	.byte	W01
	.byte		        c_v-63
	.byte		N01   , Cs3 , v036
	.byte	W01
	.byte		BEND  , c_v+63
	.byte	W01
	.byte		        c_v-63
	.byte		N01   , Bn4 , v052
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		N01   , Cs1 
	.byte	W02
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

song_264:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_264_pri	@ Priority
	.byte	song_264_rev	@ Reverb.

	.word	song_264_grp

	.word	song_264_1
	.word	song_264_2

	.end
