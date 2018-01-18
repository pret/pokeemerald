	.include "MPlayDef.s"

	.equ	mus_rg_fan6_grp, voicegroup_86B0BD0
	.equ	mus_rg_fan6_pri, 5
	.equ	mus_rg_fan6_rev, reverb_set+50
	.equ	mus_rg_fan6_mvl, 127
	.equ	mus_rg_fan6_key, 0
	.equ	mus_rg_fan6_tbs, 1
	.equ	mus_rg_fan6_exg, 0
	.equ	mus_rg_fan6_cmp, 1

	.section .rodata
	.global	mus_rg_fan6
	.align	2

@********************** Track  1 **********************@

mus_rg_fan6_1:
	.byte	KEYSH , mus_rg_fan6_key+0
	.byte	TEMPO , 64*mus_rg_fan6_tbs/2
	.byte		VOICE , 60
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 59*mus_rg_fan6_mvl/mxv
	.byte		PAN   , c_v-48
	.byte		BEND  , c_v+1
	.byte	W12
	.byte	TEMPO , 136*mus_rg_fan6_tbs/2
	.byte		N06   , En3 , v096
	.byte	W06
	.byte		        En3 , v040
	.byte	W06
	.byte		        Fs3 , v096
	.byte	W06
	.byte		        Fs3 , v040
	.byte	W06
	.byte		        Gs3 , v096
	.byte	W06
	.byte		        Gs3 , v040
	.byte	W06
	.byte		N03   , Gs3 , v096
	.byte	W03
	.byte		        Gs3 , v040
	.byte	W03
	.byte		        Gs3 , v096
	.byte	W03
	.byte		        Gs3 , v040
	.byte	W03
	.byte		N06   , Bn3 , v096
	.byte	W06
	.byte		        Bn3 , v040
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		        Cs4 , v040
	.byte	W06
	.byte		        Ds4 , v096
	.byte	W06
	.byte		        Bn3 , v040
	.byte	W06
	.byte		N03   , Ds4 , v096
	.byte	W03
	.byte		        Ds4 , v040
	.byte	W03
	.byte		        Ds4 , v096
	.byte	W03
	.byte		        Ds4 , v040
	.byte	W03
	.byte		VOL   , 25*mus_rg_fan6_mvl/mxv
	.byte		N48   , En4 , v096
	.byte	W06
	.byte		VOL   , 29*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        31*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		MOD   , 5
	.byte		VOL   , 34*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        41*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        44*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        50*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        55*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        64*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        71*mus_rg_fan6_mvl/mxv
	.byte	W15
	.byte		MOD   , 0
	.byte		N06   , En4 , v040
	.byte	W24
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_fan6_2:
	.byte	KEYSH , mus_rg_fan6_key+0
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 94*mus_rg_fan6_mvl/mxv
	.byte		PAN   , c_v-18
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		N06   , Gs4 , v127
	.byte	W03
	.byte		MOD   , 6
	.byte	W03
	.byte		        0
	.byte		N06   , Gs4 , v052
	.byte	W06
	.byte		N03   , Gs4 , v120
	.byte	W03
	.byte		        Gs4 , v052
	.byte	W03
	.byte		        Gs4 , v120
	.byte	W03
	.byte		        Gs4 , v052
	.byte	W03
	.byte		N06   , En4 , v127
	.byte	W03
	.byte		MOD   , 6
	.byte	W03
	.byte		        0
	.byte		N06   , En4 , v052
	.byte	W06
	.byte		N03   , En4 , v120
	.byte	W03
	.byte		        En4 , v052
	.byte	W03
	.byte		        En4 , v120
	.byte	W03
	.byte		        En4 , v052
	.byte	W03
	.byte		N06   , Bn4 , v127
	.byte	W03
	.byte		MOD   , 6
	.byte	W03
	.byte		        0
	.byte		N06   , Bn4 , v052
	.byte	W06
	.byte		N03   , Bn4 , v120
	.byte	W03
	.byte		        Bn4 , v052
	.byte	W03
	.byte		        Bn4 , v120
	.byte	W03
	.byte		        Bn4 , v052
	.byte	W03
	.byte		N06   , An4 , v127
	.byte	W03
	.byte		MOD   , 6
	.byte	W03
	.byte		        0
	.byte		N06   , An4 , v052
	.byte	W06
	.byte		N03   , An4 , v120
	.byte	W03
	.byte		        An4 , v052
	.byte	W03
	.byte		        An4 , v120
	.byte	W03
	.byte		        An4 , v052
	.byte	W03
	.byte		VOL   , 31*mus_rg_fan6_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N48   , Gs4 , v127
	.byte	W03
	.byte		VOL   , 34*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        43*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		MOD   , 6
	.byte		VOL   , 49*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        67*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        74*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        82*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        91*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        94*mus_rg_fan6_mvl/mxv
	.byte	W18
	.byte		N06   , Gs4 , v048
	.byte	W09
	.byte		MOD   , 0
	.byte	W15
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_fan6_3:
	.byte	KEYSH , mus_rg_fan6_key+0
	.byte		VOICE , 87
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 47*mus_rg_fan6_mvl/mxv
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		BEND  , c_v+0
	.byte		N24   , Bn3 , v120
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N24   , Cs4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , An4 
	.byte	W12
	.byte		N03   , Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		VOL   , 28*mus_rg_fan6_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N48   , Gs4 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 38*mus_rg_fan6_mvl/mxv
	.byte	W12
	.byte		        47*mus_rg_fan6_mvl/mxv
	.byte	W12
	.byte		        59*mus_rg_fan6_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte	W24
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_fan6_4:
	.byte	KEYSH , mus_rg_fan6_key+0
	.byte		VOICE , 80
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 94*mus_rg_fan6_mvl/mxv
	.byte	W12
	.byte		BEND  , c_v+0
	.byte		N09   , Bn1 , v096
	.byte	W12
	.byte		N03   , En2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N24   , An1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N06   , Gs1 
	.byte	W12
	.byte		N03   , Bn1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		N09   , Fs1 
	.byte	W06
	.byte		BEND  , c_v+6
	.byte	W03
	.byte		        c_v+0
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		VOL   , 28*mus_rg_fan6_mvl/mxv
	.byte		N48   , En1 , v127
	.byte	W03
	.byte		VOL   , 31*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        32*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        35*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        40*mus_rg_fan6_mvl/mxv
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 48*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        53*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        62*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        66*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        70*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        77*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        88*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        94*mus_rg_fan6_mvl/mxv
	.byte	W14
	.byte		MOD   , 0
	.byte	W22
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_fan6_5:
	.byte	KEYSH , mus_rg_fan6_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 71*mus_rg_fan6_mvl/mxv
	.byte	W12
	.byte		N06   , Bn3 , v127
	.byte	W06
	.byte		MOD   , 4
	.byte		N06   , Bn3 , v052
	.byte	W06
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W03
	.byte		        Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W03
	.byte		MOD   , 0
	.byte		N06   , Gs3 , v127
	.byte	W06
	.byte		MOD   , 4
	.byte		N06   , Gs3 , v052
	.byte	W06
	.byte		N03   , Gs3 , v120
	.byte	W03
	.byte		        Gs3 , v052
	.byte	W03
	.byte		        Gs3 , v120
	.byte	W03
	.byte		        Gs3 , v052
	.byte	W03
	.byte		MOD   , 0
	.byte		N06   , En4 , v127
	.byte	W06
	.byte		MOD   , 4
	.byte		N06   , En4 , v052
	.byte	W06
	.byte		N03   , En4 , v120
	.byte	W03
	.byte		        En4 , v052
	.byte	W03
	.byte		        En4 , v120
	.byte	W03
	.byte		        En4 , v052
	.byte	W03
	.byte		MOD   , 0
	.byte		N06   , Bn3 , v127
	.byte	W06
	.byte		        Bn3 , v052
	.byte	W06
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W03
	.byte		        Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W03
	.byte		VOL   , 19*mus_rg_fan6_mvl/mxv
	.byte		N48   , En4 , v127
	.byte	W03
	.byte		VOL   , 22*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        25*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		MOD   , 4
	.byte		VOL   , 26*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        28*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        34*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        40*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        46*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        59*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        82*mus_rg_fan6_mvl/mxv
	.byte	W15
	.byte		MOD   , 0
	.byte		N06   , En4 , v040
	.byte	W24
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_fan6_6:
	.byte	KEYSH , mus_rg_fan6_key+0
	.byte		VOICE , 2
	.byte		PAN   , c_v+32
	.byte		VOL   , 65*mus_rg_fan6_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		N06   , Gs3 , v127
	.byte	W06
	.byte		        Gs3 , v052
	.byte	W06
	.byte		N03   , Gs3 , v120
	.byte	W03
	.byte		        Gs3 , v052
	.byte	W03
	.byte		        Gs3 , v120
	.byte	W03
	.byte		        Gs3 , v052
	.byte	W03
	.byte		N06   , En3 , v127
	.byte	W06
	.byte		        En3 , v052
	.byte	W06
	.byte		N03   , En3 , v120
	.byte	W03
	.byte		        En3 , v052
	.byte	W03
	.byte		        En3 , v120
	.byte	W03
	.byte		        En3 , v052
	.byte	W03
	.byte		N06   , Bn3 , v127
	.byte	W06
	.byte		        Bn3 , v052
	.byte	W06
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W03
	.byte		        Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W03
	.byte		N06   , An3 , v127
	.byte	W06
	.byte		        An3 , v052
	.byte	W06
	.byte		N03   , An3 , v120
	.byte	W03
	.byte		        An3 , v052
	.byte	W03
	.byte		        An3 , v120
	.byte	W03
	.byte		        An3 , v052
	.byte	W03
	.byte		N48   , Gs3 , v127
	.byte	W72
	.byte	FINE

@********************** Track  7 **********************@

mus_rg_fan6_7:
	.byte	KEYSH , mus_rg_fan6_key+0
	.byte		VOICE , 0
	.byte		VOL   , 82*mus_rg_fan6_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		N12   , Cn1 , v127
	.byte	W12
	.byte		N06   , Cn1 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 , v092
	.byte	W18
	.byte		N06   , Cn1 , v076
	.byte	W06
	.byte		N12   , Cn1 , v096
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		VOL   , 94*mus_rg_fan6_mvl/mxv
	.byte		N06   , Dn2 , v088
	.byte	W06
	.byte		N05   , An1 , v104
	.byte	W06
	.byte		N06   , Gn1 , v112
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		VOL   , 71*mus_rg_fan6_mvl/mxv
	.byte		N06   , En1 , v120
	.byte		N42   , An2 
	.byte	W06
	.byte		N03   , En1 , v064
	.byte	W03
	.byte		        En1 , v048
	.byte	W03
	.byte		        En1 , v064
	.byte	W03
	.byte		        En1 , v048
	.byte	W03
	.byte		        En1 , v064
	.byte	W03
	.byte		        En1 , v048
	.byte	W03
	.byte		VOL   , 74*mus_rg_fan6_mvl/mxv
	.byte		N03   , En1 , v064
	.byte	W03
	.byte		VOL   , 81*mus_rg_fan6_mvl/mxv
	.byte		N03   , En1 , v048
	.byte	W03
	.byte		VOL   , 82*mus_rg_fan6_mvl/mxv
	.byte		N03   , En1 , v088
	.byte	W03
	.byte		VOL   , 86*mus_rg_fan6_mvl/mxv
	.byte		N03   , En1 , v056
	.byte	W03
	.byte		VOL   , 88*mus_rg_fan6_mvl/mxv
	.byte		N03   , En1 , v088
	.byte	W03
	.byte		VOL   , 92*mus_rg_fan6_mvl/mxv
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		        En1 , v104
	.byte		N03   , Cn2 
	.byte	W03
	.byte		        En1 , v072
	.byte		N03   , An1 , v092
	.byte	W03
	.byte		VOL   , 82*mus_rg_fan6_mvl/mxv
	.byte		N06   , En1 , v064
	.byte		N06   , Fn1 , v112
	.byte		N24   , Cs2 , v080
	.byte	W06
	.byte		VOL   , 71*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        65*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        59*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        47*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        41*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte		        35*mus_rg_fan6_mvl/mxv
	.byte	W03
	.byte	FINE

@********************** Track  8 **********************@

mus_rg_fan6_8:
	.byte	KEYSH , mus_rg_fan6_key+0
	.byte		VOICE , 1
	.byte		VOL   , 71*mus_rg_fan6_mvl/mxv
	.byte	W12
	.byte	W72
	.byte		PAN   , c_v-32
	.byte		N12   , Bn4 , v052
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N36   , Bn4 , v080
	.byte	W12
	.byte	W72
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_fan6:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_fan6_pri	@ Priority
	.byte	mus_rg_fan6_rev	@ Reverb.

	.word	mus_rg_fan6_grp

	.word	mus_rg_fan6_1
	.word	mus_rg_fan6_2
	.word	mus_rg_fan6_3
	.word	mus_rg_fan6_4
	.word	mus_rg_fan6_5
	.word	mus_rg_fan6_6
	.word	mus_rg_fan6_7
	.word	mus_rg_fan6_8

	.end
