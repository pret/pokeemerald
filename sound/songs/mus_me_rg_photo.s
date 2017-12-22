	.include "MPlayDef.s"

	.equ	mus_me_rg_photo_grp, voicegroup_86B0FF0
	.equ	mus_me_rg_photo_pri, 5
	.equ	mus_me_rg_photo_rev, reverb_set+50
	.equ	mus_me_rg_photo_mvl, 127
	.equ	mus_me_rg_photo_key, 0
	.equ	mus_me_rg_photo_tbs, 1
	.equ	mus_me_rg_photo_exg, 0
	.equ	mus_me_rg_photo_cmp, 1

	.section .rodata
	.global	mus_me_rg_photo
	.align	2

@********************** Track  1 **********************@

mus_me_rg_photo_1:
	.byte	KEYSH , mus_me_rg_photo_key+0
	.byte	TEMPO , 192*mus_me_rg_photo_tbs/2
	.byte		VOICE , 1
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		PAN   , c_v+0
	.byte		VOL   , 81*mus_me_rg_photo_mvl/mxv
	.byte		BEND  , c_v+2
	.byte		N03   , Ds4 , v068
	.byte	W03
	.byte		        Dn4 , v032
	.byte	W03
	.byte		        Fn4 , v068
	.byte	W03
	.byte		        Ds4 , v032
	.byte	W03
	.byte		        Gn4 , v068
	.byte	W03
	.byte		        Fn4 , v032
	.byte	W03
	.byte		        As4 , v068
	.byte	W03
	.byte		        Gn4 , v032
	.byte	W03
	.byte		        Ds5 , v068
	.byte	W03
	.byte		        As4 , v032
	.byte	W03
	.byte		        Fn5 , v068
	.byte	W03
	.byte		        Dn5 , v032
	.byte	W03
	.byte		        Gn5 , v068
	.byte	W03
	.byte		        Ds5 , v032
	.byte	W03
	.byte		        As5 , v068
	.byte	W03
	.byte		        Gn5 , v032
	.byte	W03
	.byte		        Ds6 , v068
	.byte	W03
	.byte		        As5 , v056
	.byte	W03
	.byte		        Ds6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte		        Ds6 , v028
	.byte	W03
	.byte		        As5 , v024
	.byte	W03
	.byte		        Ds6 , v016
	.byte	W03
	.byte		        As5 , v008
	.byte	W03
	.byte		VOL   , 0*mus_me_rg_photo_mvl/mxv
	.byte	W24
	.byte		        0*mus_me_rg_photo_mvl/mxv
	.byte	FINE

@********************** Track  2 **********************@

mus_me_rg_photo_2:
	.byte	KEYSH , mus_me_rg_photo_key+0
	.byte		VOICE , 5
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		PAN   , c_v-32
	.byte		VOL   , 67*mus_me_rg_photo_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , Gn4 , v068
	.byte	W03
	.byte		        Dn4 , v032
	.byte	W03
	.byte		        Gn4 , v068
	.byte	W03
	.byte		        Ds4 , v032
	.byte	W03
	.byte		        Gn4 , v068
	.byte	W03
	.byte		        Fn4 , v032
	.byte	W03
	.byte		        As4 , v068
	.byte	W03
	.byte		        Gn4 , v032
	.byte	W03
	.byte		        Ds5 , v068
	.byte	W03
	.byte		        As4 , v032
	.byte	W03
	.byte		        Fn5 , v068
	.byte	W03
	.byte		        Dn5 , v032
	.byte	W03
	.byte		        Gn5 , v068
	.byte	W03
	.byte		        Ds5 , v032
	.byte	W03
	.byte		        As5 , v068
	.byte	W03
	.byte		        Gn5 , v032
	.byte	W03
	.byte		        Ds6 , v068
	.byte	W03
	.byte		        As5 , v056
	.byte	W03
	.byte		        Ds6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte		        Ds6 , v028
	.byte	W03
	.byte		        As5 , v024
	.byte	W03
	.byte		        Ds6 , v016
	.byte	W03
	.byte		        As5 , v008
	.byte	W03
	.byte		VOL   , 1*mus_me_rg_photo_mvl/mxv
	.byte	W24
	.byte	FINE

@********************** Track  3 **********************@

mus_me_rg_photo_3:
	.byte	KEYSH , mus_me_rg_photo_key+0
	.byte		VOICE , 4
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		PAN   , c_v+32
	.byte		VOL   , 59*mus_me_rg_photo_mvl/mxv
	.byte		N03   , Ds3 , v068
	.byte	W03
	.byte		        Dn3 , v032
	.byte	W03
	.byte		        Fn3 , v068
	.byte	W03
	.byte		        Ds3 , v032
	.byte	W03
	.byte		        Gn3 , v068
	.byte	W03
	.byte		        Fn3 , v032
	.byte	W03
	.byte		        As3 , v068
	.byte	W03
	.byte		        Gn3 , v032
	.byte	W03
	.byte		        Ds4 , v068
	.byte	W03
	.byte		        As3 , v032
	.byte	W03
	.byte		        Fn4 , v068
	.byte	W03
	.byte		        Dn4 , v032
	.byte	W03
	.byte		        Gn4 , v068
	.byte	W03
	.byte		        Ds4 , v032
	.byte	W03
	.byte		        As4 , v068
	.byte	W03
	.byte		        Gn4 , v032
	.byte	W03
	.byte		        Ds5 , v068
	.byte	W03
	.byte		        As4 , v056
	.byte	W03
	.byte		        Ds5 , v048
	.byte	W03
	.byte		        As4 , v040
	.byte	W03
	.byte		        Ds5 , v028
	.byte	W03
	.byte		        As4 , v024
	.byte	W03
	.byte		        Ds5 , v016
	.byte	W03
	.byte		        As4 , v008
	.byte	W03
	.byte		VOL   , 1*mus_me_rg_photo_mvl/mxv
	.byte	W24
	.byte		        0*mus_me_rg_photo_mvl/mxv
	.byte	FINE

@********************** Track  4 **********************@

mus_me_rg_photo_4:
	.byte	KEYSH , mus_me_rg_photo_key+0
	.byte		VOICE , 127
	.byte		PAN   , c_v+0
	.byte		VOL   , 63*mus_me_rg_photo_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N01   , Cn5 , v112
	.byte	W02
	.byte		        An5 
	.byte	W14
	.byte		N03   , Gs5 , v120
	.byte	W08
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE

@********************** Track  5 **********************@

mus_me_rg_photo_5:
	.byte	KEYSH , mus_me_rg_photo_key+0
	.byte		VOICE , 126
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_me_rg_photo_mvl/mxv
	.byte		N02   , Cs3 , v127
	.byte	W10
	.byte		N01   , Bn3 , v116
	.byte	W06
	.byte		N02   , En4 , v127
	.byte	W08
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

mus_me_rg_photo:
	.byte	5	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_me_rg_photo_pri	@ Priority
	.byte	mus_me_rg_photo_rev	@ Reverb.

	.word	mus_me_rg_photo_grp

	.word	mus_me_rg_photo_1
	.word	mus_me_rg_photo_2
	.word	mus_me_rg_photo_3
	.word	mus_me_rg_photo_4
	.word	mus_me_rg_photo_5

	.end
