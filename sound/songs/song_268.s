	.include "MPlayDef.s"

	.equ	song_268_grp, voicegroup_86A0154
	.equ	song_268_pri, 5
	.equ	song_268_rev, reverb_set+50
	.equ	song_268_mvl, 127
	.equ	song_268_key, 0
	.equ	song_268_tbs, 1
	.equ	song_268_exg, 0
	.equ	song_268_cmp, 1

	.section .rodata
	.global	song_268
	.align	2

@********************** Track  1 **********************@

song_268_1:
	.byte		VOL   , 127*song_268_mvl/mxv
	.byte	KEYSH , song_268_key+0
	.byte	TEMPO , 112*song_268_tbs/2
	.byte		VOICE , 38
	.byte		MOD   , 2
	.byte		N04   , Gs1 , v120
	.byte	W02
	.byte		MOD   , 7
	.byte	W02
	.byte		        1
	.byte		N04   , Cn2 
	.byte	W03
	.byte		MOD   , 7
	.byte	W02
	.byte		        1
	.byte		N04   , En2 
	.byte	W03
	.byte		MOD   , 7
	.byte	W02
	.byte		        1
	.byte		N04   , Gs2 
	.byte	W02
	.byte		MOD   , 7
	.byte	W03
	.byte		        1
	.byte		N04   , Cn3 
	.byte	W02
	.byte		MOD   , 7
	.byte	W03
	.byte		        1
	.byte		N04   , Ds3 
	.byte	W02
	.byte		MOD   , 7
	.byte	W02
	.byte		        1
	.byte		N04   , En3 , v096
	.byte	W03
	.byte		MOD   , 7
	.byte	W02
	.byte		PAN   , c_v-62
	.byte		MOD   , 1
	.byte		N04   , En4 , v032
	.byte	W03
	.byte		MOD   , 7
	.byte	W02
	.byte		PAN   , c_v+63
	.byte		MOD   , 1
	.byte		N04   , En3 , v048
	.byte	W02
	.byte		MOD   , 7
	.byte	W03
	.byte		PAN   , c_v-62
	.byte		MOD   , 1
	.byte		N04   , En4 , v012
	.byte	W02
	.byte		MOD   , 7
	.byte	W03
	.byte		PAN   , c_v+63
	.byte		MOD   , 1
	.byte		N04   , En3 , v032
	.byte	W02
	.byte		MOD   , 7
	.byte	W02
	.byte		PAN   , c_v-62
	.byte		MOD   , 1
	.byte		N04   , En4 , v008
	.byte	W03
	.byte		MOD   , 7
	.byte	W02
	.byte		        2
	.byte	W03
	.byte	TEMPO , 98*song_268_tbs/2
	.byte		PAN   , c_v+0
	.byte		VOL   , 127*song_268_mvl/mxv
	.byte	W12
	.byte	FINE

@********************** Track  2 **********************@

song_268_2:
	.byte		VOL   , 127*song_268_mvl/mxv
	.byte	KEYSH , song_268_key+0
	.byte		VOICE , 100
	.byte	W12
	.byte	W07
	.byte		N04   , Cn4 , v112
	.byte	W05
	.byte		        As4 
	.byte	W07
	.byte		        Gs5 , v064
	.byte	W05
	.byte		        Ds6 , v048
	.byte	W07
	.byte		        Gn6 , v032
	.byte	W05
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		VOL   , 112*song_268_mvl/mxv
	.byte	W12
	.byte	FINE

@********************** Track  3 **********************@

song_268_3:
	.byte	KEYSH , song_268_key+0
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	W12
	.byte		VOICE , 125
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		MOD   , 2
	.byte		VOL   , 86*song_268_mvl/mxv
	.byte		BEND  , c_v-57
	.byte		N09   , Cn5 , v064
	.byte	W01
	.byte		BEND  , c_v-45
	.byte	W01
	.byte		        c_v-30
	.byte	W01
	.byte		        c_v-18
	.byte	W01
	.byte		        c_v-11
	.byte	W02
	.byte		        c_v+0
	.byte	W03
	.byte		N01   , Gn5 , v096
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

song_268:
	.byte	3	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_268_pri	@ Priority
	.byte	song_268_rev	@ Reverb.

	.word	song_268_grp

	.word	song_268_1
	.word	song_268_2
	.word	song_268_3

	.end
