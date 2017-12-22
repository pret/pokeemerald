	.include "MPlayDef.s"

	.equ	mus_me_symbolget_grp, voicegroup_869557C
	.equ	mus_me_symbolget_pri, 5
	.equ	mus_me_symbolget_rev, reverb_set+50
	.equ	mus_me_symbolget_mvl, 127
	.equ	mus_me_symbolget_key, 0
	.equ	mus_me_symbolget_tbs, 1
	.equ	mus_me_symbolget_exg, 0
	.equ	mus_me_symbolget_cmp, 1

	.section .rodata
	.global	mus_me_symbolget
	.align	2

@********************** Track  1 **********************@

mus_me_symbolget_1:
	.byte	KEYSH , mus_me_symbolget_key+0
	.byte	TEMPO , 122*mus_me_symbolget_tbs/2
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 100*mus_me_symbolget_mvl/mxv
	.byte		PAN   , c_v-7
	.byte	W12
	.byte		N04   , Cn4 , v096
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Cn5 
	.byte	W12
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		MOD   , 4
	.byte		N32   , Fn5 
	.byte	W12
	.byte		VOL   , 88*mus_me_symbolget_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 75*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        62*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        100*mus_me_symbolget_mvl/mxv
	.byte		N02   , Fn4 
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte	TEMPO , 116*mus_me_symbolget_tbs/2
	.byte		MOD   , 4
	.byte		N48   
	.byte	W12
	.byte		VOL   , 88*mus_me_symbolget_mvl/mxv
	.byte	W12
	.byte	TEMPO , 108*mus_me_symbolget_tbs/2
	.byte		MOD   , 0
	.byte		VOL   , 75*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        62*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        50*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        37*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte	TEMPO , 90*mus_me_symbolget_tbs/2
	.byte		        88*mus_me_symbolget_mvl/mxv
	.byte		N06   
	.byte	W24
	.byte	FINE

@********************** Track  2 **********************@

mus_me_symbolget_2:
	.byte	KEYSH , mus_me_symbolget_key+0
	.byte		VOICE , 14
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 50*mus_me_symbolget_mvl/mxv
	.byte	W12
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N08   , Cn5 , v100
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N08   , Cn4 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N08   , Fn4 
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N08   , Gn4 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N08   , Fn4 
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N08   , Gn4 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N08   , Cn5 
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N08   , Fn4 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N08   , Gn4 
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N08   , Cn5 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N08   , Gn5 
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N08   , En5 
	.byte	W08
	.byte		MOD   , 4
	.byte		PAN   , c_v-32
	.byte		N08   , Cn5 
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N08   , Fn4 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N08   , Gn4 
	.byte	W08
	.byte		MOD   , 0
	.byte		PAN   , c_v+32
	.byte		N08   , Cn5 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N08   , As4 
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N08   , Gn4 
	.byte	W08
	.byte		MOD   , 3
	.byte		PAN   , c_v-32
	.byte		N08   , Fn4 
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N08   , An3 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N08   , Cn4 
	.byte	W08
	.byte		MOD   , 0
	.byte		PAN   , c_v+32
	.byte		N08   , Fn4 , v092
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N08   , Gn4 , v088
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N08   , Fn4 
	.byte	W08
	.byte		PAN   , c_v-16
	.byte		N08   , An4 , v100
	.byte	W24
	.byte	FINE

@********************** Track  3 **********************@

mus_me_symbolget_3:
	.byte	KEYSH , mus_me_symbolget_key+0
	.byte		VOICE , 87
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 79*mus_me_symbolget_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		N02   , Gn1 , v100
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N48   , Cn2 
	.byte	W12
	.byte		VOL   , 68*mus_me_symbolget_mvl/mxv
	.byte		MOD   , 8
	.byte	W12
	.byte		VOL   , 58*mus_me_symbolget_mvl/mxv
	.byte	W12
	.byte		        47*mus_me_symbolget_mvl/mxv
	.byte	W12
	.byte		        79*mus_me_symbolget_mvl/mxv
	.byte		MOD   , 1
	.byte		N24   , As1 
	.byte	W12
	.byte		VOL   , 66*mus_me_symbolget_mvl/mxv
	.byte		MOD   , 8
	.byte	W12
	.byte		VOL   , 79*mus_me_symbolget_mvl/mxv
	.byte		MOD   , 1
	.byte		N24   , Gn1 
	.byte	W12
	.byte		VOL   , 66*mus_me_symbolget_mvl/mxv
	.byte		MOD   , 8
	.byte	W12
	.byte		VOL   , 79*mus_me_symbolget_mvl/mxv
	.byte		MOD   , 1
	.byte		N36   , Fn1 
	.byte	W12
	.byte		VOL   , 66*mus_me_symbolget_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 55*mus_me_symbolget_mvl/mxv
	.byte	W12
	.byte		        79*mus_me_symbolget_mvl/mxv
	.byte		MOD   , 1
	.byte		N02   , An1 
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N48   , Fn1 
	.byte	W12
	.byte		VOL   , 62*mus_me_symbolget_mvl/mxv
	.byte		MOD   , 8
	.byte	W12
	.byte		VOL   , 50*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        37*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        25*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        12*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		MOD   , 1
	.byte		N06   
	.byte	W24
	.byte	FINE

@********************** Track  4 **********************@

mus_me_symbolget_4:
	.byte	KEYSH , mus_me_symbolget_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 75*mus_me_symbolget_mvl/mxv
	.byte		PAN   , c_v+16
	.byte	W12
	.byte		N04   , Fn3 , v064
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		MOD   , 4
	.byte		N32   , Cn5 
	.byte	W12
	.byte		VOL   , 62*mus_me_symbolget_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 50*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        37*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        74*mus_me_symbolget_mvl/mxv
	.byte		N02   , Cn4 
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		MOD   , 4
	.byte		N48   
	.byte	W12
	.byte		VOL   , 62*mus_me_symbolget_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 50*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        37*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        25*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        12*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        75*mus_me_symbolget_mvl/mxv
	.byte		N06   
	.byte	W24
	.byte	FINE

@********************** Track  5 **********************@

mus_me_symbolget_5:
	.byte	KEYSH , mus_me_symbolget_key+0
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 88*mus_me_symbolget_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		N02   , Cn2 , v100
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte	W96
	.byte		N32   , Fn2 
	.byte	W36
	.byte		N02   , An2 
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N32   , Fn2 
	.byte	W36
	.byte		N02   , An1 
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N10   , Fn1 
	.byte	W04
	.byte		VOL   , 75*mus_me_symbolget_mvl/mxv
	.byte	W04
	.byte		        62*mus_me_symbolget_mvl/mxv
	.byte	W04
	.byte		        38*mus_me_symbolget_mvl/mxv
	.byte	W04
	.byte		        25*mus_me_symbolget_mvl/mxv
	.byte	W04
	.byte		        12*mus_me_symbolget_mvl/mxv
	.byte	W04
	.byte		        0*mus_me_symbolget_mvl/mxv
	.byte	FINE

@********************** Track  6 **********************@

mus_me_symbolget_6:
	.byte	KEYSH , mus_me_symbolget_key+0
	.byte		VOICE , 83
	.byte		LFOS  , 51
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 50*mus_me_symbolget_mvl/mxv
	.byte		PAN   , c_v-62
	.byte	W12
	.byte	W12
	.byte		N04   , Gn3 , v088
	.byte	W12
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N24   , As3 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 25*mus_me_symbolget_mvl/mxv
	.byte	W12
	.byte		MOD   , 1
	.byte		VOL   , 50*mus_me_symbolget_mvl/mxv
	.byte		N24   , Gn3 , v084
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 25*mus_me_symbolget_mvl/mxv
	.byte	W12
	.byte		MOD   , 1
	.byte		VOL   , 50*mus_me_symbolget_mvl/mxv
	.byte		N32   , An2 , v088
	.byte	W12
	.byte		VOL   , 37*mus_me_symbolget_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 25*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        12*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        50*mus_me_symbolget_mvl/mxv
	.byte		MOD   , 1
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N48   , An2 , v100
	.byte	W12
	.byte		VOL   , 37*mus_me_symbolget_mvl/mxv
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 25*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        12*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        8*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        2*mus_me_symbolget_mvl/mxv
	.byte	W12
	.byte		        37*mus_me_symbolget_mvl/mxv
	.byte		MOD   , 1
	.byte		N06   , Fn3 
	.byte	W24
	.byte	FINE

@********************** Track  7 **********************@

mus_me_symbolget_7:
	.byte	KEYSH , mus_me_symbolget_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 37*mus_me_symbolget_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		N04   , Cn4 , v100
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Cn4 
	.byte	W12
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N24   , Dn4 
	.byte	W08
	.byte		VOL   , 31*mus_me_symbolget_mvl/mxv
	.byte	W04
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_me_symbolget_mvl/mxv
	.byte	W04
	.byte		        24*mus_me_symbolget_mvl/mxv
	.byte	W04
	.byte		        17*mus_me_symbolget_mvl/mxv
	.byte	W04
	.byte		MOD   , 1
	.byte		VOL   , 37*mus_me_symbolget_mvl/mxv
	.byte		N24   , Cn4 , v096
	.byte	W08
	.byte		VOL   , 33*mus_me_symbolget_mvl/mxv
	.byte	W04
	.byte		MOD   , 6
	.byte		VOL   , 29*mus_me_symbolget_mvl/mxv
	.byte	W04
	.byte		        23*mus_me_symbolget_mvl/mxv
	.byte	W04
	.byte		        15*mus_me_symbolget_mvl/mxv
	.byte	W04
	.byte		MOD   , 1
	.byte		VOL   , 37*mus_me_symbolget_mvl/mxv
	.byte		N32   , Fn3 , v100
	.byte	W12
	.byte		VOL   , 25*mus_me_symbolget_mvl/mxv
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 18*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        12*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        7*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        37*mus_me_symbolget_mvl/mxv
	.byte		MOD   , 1
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N48   
	.byte	W12
	.byte		VOL   , 25*mus_me_symbolget_mvl/mxv
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 18*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        12*mus_me_symbolget_mvl/mxv
	.byte	W06
	.byte		        7*mus_me_symbolget_mvl/mxv
	.byte	W09
	.byte		        4*mus_me_symbolget_mvl/mxv
	.byte	W09
	.byte		        37*mus_me_symbolget_mvl/mxv
	.byte		MOD   , 1
	.byte		N06   , Cn4 
	.byte	W24
	.byte	FINE

@********************** Track  8 **********************@

mus_me_symbolget_8:
	.byte	KEYSH , mus_me_symbolget_key+0
	.byte		VOICE , 1
	.byte		PAN   , c_v+0
	.byte		VOL   , 96*mus_me_symbolget_mvl/mxv
	.byte	W12
	.byte	W12
	.byte		N48   , An2 , v100
	.byte	W48
	.byte		N24   , En2 
	.byte	W24
	.byte		        Cs2 
	.byte	W24
	.byte	W96
	.byte		N06   , Gn2 
	.byte	W24
	.byte	FINE

@********************** Track  9 **********************@

mus_me_symbolget_9:
	.byte	KEYSH , mus_me_symbolget_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 50*mus_me_symbolget_mvl/mxv
	.byte	W12
	.byte		N01   , Cn5 , v064
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		        Cn5 , v096
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		        Cn5 , v080
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N01   , Cn5 , v048
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		        Cn5 , v064
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N02   , Cn5 , v080
	.byte	W04
	.byte		N01   , Cn5 , v048
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N04   , Gn5 , v064
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

mus_me_symbolget:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_me_symbolget_pri	@ Priority
	.byte	mus_me_symbolget_rev	@ Reverb.

	.word	mus_me_symbolget_grp

	.word	mus_me_symbolget_1
	.word	mus_me_symbolget_2
	.word	mus_me_symbolget_3
	.word	mus_me_symbolget_4
	.word	mus_me_symbolget_5
	.word	mus_me_symbolget_6
	.word	mus_me_symbolget_7
	.word	mus_me_symbolget_8
	.word	mus_me_symbolget_9

	.end
