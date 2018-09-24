	.include "MPlayDef.s"

	.equ	se_z_search_grp, voicegroup127
	.equ	se_z_search_pri, 5
	.equ	se_z_search_rev, reverb_set+50
	.equ	se_z_search_mvl, 127
	.equ	se_z_search_key, 0
	.equ	se_z_search_tbs, 1
	.equ	se_z_search_exg, 0
	.equ	se_z_search_cmp, 1

	.section .rodata
	.global	se_z_search
	.align	2

@********************** Track  1 **********************@

se_z_search_1:
	.byte	KEYSH , se_z_search_key+0
	.byte	TEMPO , 144*se_z_search_tbs/2
	.byte		VOICE , 4
	.byte		XCMD  , xIECV , 12
	.byte		        xIECL , 10
	.byte		VOL   , 100*se_z_search_mvl/mxv
	.byte		BEND  , c_v-6
	.byte		N02   , Ds5 , v060
	.byte	W02
	.byte		BEND  , c_v+6
	.byte		N01   , Ds4 , v040
	.byte	W01
	.byte		BEND  , c_v-6
	.byte		N02   , Ds4 , v060
	.byte	W03
	.byte		BEND  , c_v+6
	.byte		N01   , Ds3 , v040
	.byte	W01
	.byte		BEND  , c_v-6
	.byte		N02   , Ds5 , v060
	.byte	W02
	.byte		BEND  , c_v+6
	.byte		N01   , Ds4 , v040
	.byte	W01
	.byte		BEND  , c_v-6
	.byte		N02   , As4 , v060
	.byte	W03
	.byte		BEND  , c_v+6
	.byte		N01   , As3 , v040
	.byte	W01
	.byte		BEND  , c_v-6
	.byte		N02   , Ds5 , v060
	.byte	W02
	.byte		BEND  , c_v+6
	.byte		N01   , Ds4 , v040
	.byte	W02
	.byte		BEND  , c_v-6
	.byte		N02   , As4 , v060
	.byte	W02
	.byte		BEND  , c_v+6
	.byte		N01   , As3 , v040
	.byte	W01
	.byte		BEND  , c_v-6
	.byte		N02   , Ds5 , v060
	.byte	W03
	.byte		BEND  , c_v+6
	.byte		N01   , Ds4 , v040
	.byte	W01
	.byte		BEND  , c_v-6
	.byte		N02   , Ds4 , v060
	.byte	W02
	.byte		BEND  , c_v+6
	.byte		N01   , Ds3 , v040
	.byte	W01
	.byte		BEND  , c_v-6
	.byte		N02   , Ds5 , v060
	.byte	W03
	.byte		BEND  , c_v+6
	.byte		N01   , Ds4 , v040
	.byte	W01
	.byte		BEND  , c_v-6
	.byte		N02   , Ds4 , v060
	.byte	W02
	.byte		BEND  , c_v+6
	.byte		N01   , Ds3 , v040
	.byte	W02
	.byte		BEND  , c_v-6
	.byte		N02   , Ds5 , v060
	.byte	W02
	.byte		BEND  , c_v+6
	.byte		N01   , Ds4 , v040
	.byte	W01
	.byte		BEND  , c_v-6
	.byte		N02   , As4 , v060
	.byte	W03
	.byte		BEND  , c_v+6
	.byte		N01   , As3 , v040
	.byte	W01
	.byte		BEND  , c_v-6
	.byte		N02   , Ds5 , v060
	.byte	W02
	.byte		BEND  , c_v+6
	.byte		N01   , Ds4 , v040
	.byte	W01
	.byte		BEND  , c_v-6
	.byte		N02   , As4 , v060
	.byte	W02
	.byte	W01
	.byte		BEND  , c_v+6
	.byte		N01   , As3 , v040
	.byte	W01
	.byte		BEND  , c_v-6
	.byte		N02   , Ds5 , v060
	.byte	W02
	.byte		BEND  , c_v+6
	.byte		N01   , Ds4 , v040
	.byte	W02
	.byte		BEND  , c_v-6
	.byte		N02   , Ds4 , v060
	.byte	W02
	.byte		BEND  , c_v+6
	.byte		N01   , Ds3 , v040
	.byte	W01
	.byte		BEND  , c_v-6
	.byte		N02   , Ds5 , v060
	.byte	W03
	.byte		BEND  , c_v+6
	.byte		N01   , Ds4 , v040
	.byte	W01
	.byte		BEND  , c_v-6
	.byte		N02   , As4 , v060
	.byte	W02
	.byte		BEND  , c_v+6
	.byte		N01   , As3 , v040
	.byte	W01
	.byte		BEND  , c_v-6
	.byte		N02   , Ds4 , v060
	.byte	W03
	.byte		BEND  , c_v+6
	.byte		N01   , Ds3 , v040
	.byte	W01
	.byte		BEND  , c_v-7
	.byte		N02   , Ds5 , v060
	.byte	W04
	.byte	FINE

@********************** Track  2 **********************@

se_z_search_2:
	.byte	KEYSH , se_z_search_key+0
	.byte		VOICE , 14
	.byte		VOL   , 50*se_z_search_mvl/mxv
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		N02   , Ds5 , v060
	.byte	W01
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		        c_v-8
	.byte		N01   , Ds4 , v040
	.byte	W01
	.byte		N02   , Ds4 , v060
	.byte	W02
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		        c_v-8
	.byte		N01   , Ds3 , v040
	.byte	W01
	.byte		N02   , Ds5 , v060
	.byte	W01
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		        c_v-8
	.byte		N01   , Ds4 , v040
	.byte	W02
	.byte		N02   , As4 , v060
	.byte	W01
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		        c_v-8
	.byte		N01   , As3 , v040
	.byte	W01
	.byte		N02   , Ds5 , v060
	.byte	W01
	.byte		BEND  , c_v+4
	.byte	W02
	.byte		        c_v-8
	.byte		N01   , Ds4 , v040
	.byte	W01
	.byte		N02   , As4 , v060
	.byte	W01
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		        c_v-8
	.byte		N01   , As3 , v040
	.byte	W01
	.byte		N02   , Ds5 , v060
	.byte	W02
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		        c_v-8
	.byte		N01   , Ds4 , v040
	.byte	W01
	.byte		N02   , Ds4 , v060
	.byte	W01
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		        c_v-8
	.byte		N01   , Ds3 , v040
	.byte	W02
	.byte		N02   , Ds5 , v060
	.byte	W01
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		        c_v-8
	.byte		N01   , Ds4 , v040
	.byte	W01
	.byte		N02   , Ds4 , v060
	.byte	W01
	.byte		BEND  , c_v+4
	.byte	W02
	.byte		        c_v-8
	.byte		N01   , Ds3 , v040
	.byte	W01
	.byte		N02   , Ds5 , v060
	.byte	W01
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		        c_v-8
	.byte		N01   , Ds4 , v040
	.byte	W01
	.byte		N02   , As4 , v060
	.byte	W02
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		        c_v-8
	.byte		N01   , As3 , v040
	.byte	W01
	.byte		N02   , Ds5 , v060
	.byte	W01
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		        c_v-8
	.byte		N01   , Ds4 , v040
	.byte	W02
	.byte		N02   , As4 , v060
	.byte	W01
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		        c_v-8
	.byte		N01   , As3 , v040
	.byte	W01
	.byte		N02   , Ds5 , v060
	.byte	W01
	.byte		BEND  , c_v+4
	.byte	W02
	.byte		        c_v-8
	.byte		N01   , Ds4 , v040
	.byte	W01
	.byte		N02   , Ds4 , v060
	.byte	W01
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		        c_v-8
	.byte		N01   , Ds3 , v040
	.byte	W01
	.byte		N02   , Ds5 , v060
	.byte	W02
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		        c_v-8
	.byte		N01   , Ds4 , v040
	.byte	W01
	.byte		N02   , As4 , v060
	.byte	W01
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		        c_v-8
	.byte		N01   , As3 , v040
	.byte	W02
	.byte		N02   , Ds4 , v060
	.byte	W01
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		        c_v-8
	.byte		N01   , Ds3 , v040
	.byte	W01
	.byte		N02   , Ds5 , v060
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_z_search:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_z_search_pri	@ Priority
	.byte	se_z_search_rev	@ Reverb.

	.word	se_z_search_grp

	.word	se_z_search_1
	.word	se_z_search_2

	.end
