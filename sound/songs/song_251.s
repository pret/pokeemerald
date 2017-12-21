	.include "MPlayDef.s"

	.equ	song_251_grp, voicegroup_86A0154
	.equ	song_251_pri, 5
	.equ	song_251_rev, reverb_set+50
	.equ	song_251_mvl, 127
	.equ	song_251_key, 0
	.equ	song_251_tbs, 1
	.equ	song_251_exg, 0
	.equ	song_251_cmp, 1

	.section .rodata
	.global	song_251
	.align	2

@********************** Track  1 **********************@

song_251_1:
	.byte	KEYSH , song_251_key+0
	.byte	TEMPO , 174*song_251_tbs/2
	.byte		VOICE , 46
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 112*song_251_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 112*song_251_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N03   , An5 , v112
	.byte	W03
	.byte		VOL   , 64*song_251_mvl/mxv
	.byte		N03   , Bn5 
	.byte	W03
	.byte		VOL   , 112*song_251_mvl/mxv
	.byte		PAN   , c_v-48
	.byte		N06   , En6 
	.byte	W03
	.byte		VOL   , 64*song_251_mvl/mxv
	.byte	W03
	.byte		        112*song_251_mvl/mxv
	.byte		PAN   , c_v+48
	.byte		N06   , En6 , v040
	.byte	W03
	.byte		VOL   , 64*song_251_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-48
	.byte		VOL   , 97*song_251_mvl/mxv
	.byte		N06   , En6 , v032
	.byte	W03
	.byte		VOL   , 64*song_251_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v+48
	.byte		VOL   , 96*song_251_mvl/mxv
	.byte		N06   , En6 , v024
	.byte	W03
	.byte		VOL   , 64*song_251_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-48
	.byte		VOL   , 80*song_251_mvl/mxv
	.byte		N06   , En6 , v016
	.byte	W03
	.byte		VOL   , 64*song_251_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v+48
	.byte		VOL   , 80*song_251_mvl/mxv
	.byte		N06   , En6 , v012
	.byte	W03
	.byte		VOL   , 48*song_251_mvl/mxv
	.byte	W03
	.byte		N06   , En6 , v008
	.byte	W03
	.byte		VOL   , 2*song_251_mvl/mxv
	.byte	W03
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE

@********************** Track  2 **********************@

song_251_2:
	.byte	KEYSH , song_251_key+0
	.byte		VOICE , 124
	.byte		PAN   , c_v+0
	.byte		VOL   , 64*song_251_mvl/mxv
	.byte		N03   , Cn5 , v092
	.byte	W06
	.byte		        Cn5 , v032
	.byte	W18
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

song_251:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_251_pri	@ Priority
	.byte	song_251_rev	@ Reverb.

	.word	song_251_grp

	.word	song_251_1
	.word	song_251_2

	.end
