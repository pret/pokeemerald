	.include "MPlayDef.s"

	.equ	song_248_grp, voicegroup_86A0154
	.equ	song_248_pri, 5
	.equ	song_248_rev, reverb_set+50
	.equ	song_248_mvl, 127
	.equ	song_248_key, 0
	.equ	song_248_tbs, 1
	.equ	song_248_exg, 0
	.equ	song_248_cmp, 1

	.section .rodata
	.global	song_248
	.align	2

@********************** Track  1 **********************@

song_248_1:
	.byte	KEYSH , song_248_key+0
	.byte	TEMPO , 110*song_248_tbs/2
	.byte		VOICE , 127
	.byte		VOL   , 100*song_248_mvl/mxv
	.byte		N03   , Fn2 , v100
	.byte		N03   , As2 , v127
	.byte	W06
	.byte		N08   , Fs3 , v096
	.byte	W06
	.byte		VOL   , 88*song_248_mvl/mxv
	.byte	W03
	.byte		        54*song_248_mvl/mxv
	.byte	W03
	.byte		        68*song_248_mvl/mxv
	.byte	W06
	.byte	FINE

@********************** Track  2 **********************@

song_248_2:
	.byte	KEYSH , song_248_key+0
	.byte		VOICE , 92
	.byte		BENDR , 12
	.byte		VOL   , 43*song_248_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W04
	.byte		        c_v-50
	.byte		N10   , Bn5 , v052
	.byte	W02
	.byte		BEND  , c_v-45
	.byte	W01
	.byte		        c_v-23
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+22
	.byte	W01
	.byte		        c_v+28
	.byte	W01
	.byte		        c_v+41
	.byte	W01
	.byte		VOL   , 29*song_248_mvl/mxv
	.byte		BEND  , c_v+53
	.byte	W01
	.byte		        c_v+60
	.byte	W02
	.byte		VOL   , 18*song_248_mvl/mxv
	.byte		BEND  , c_v+63
	.byte	W09
	.byte	FINE

@******************************************************@
	.align	2

song_248:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_248_pri	@ Priority
	.byte	song_248_rev	@ Reverb.

	.word	song_248_grp

	.word	song_248_1
	.word	song_248_2

	.end
