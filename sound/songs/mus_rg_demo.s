	.include "MPlayDef.s"

	.equ	mus_rg_demo_grp, voicegroup_86A29D4
	.equ	mus_rg_demo_pri, 0
	.equ	mus_rg_demo_rev, reverb_set+50
	.equ	mus_rg_demo_mvl, 127
	.equ	mus_rg_demo_key, 0
	.equ	mus_rg_demo_tbs, 1
	.equ	mus_rg_demo_exg, 0
	.equ	mus_rg_demo_cmp, 1

	.section .rodata
	.global	mus_rg_demo
	.align	2

@********************** Track  1 **********************@

mus_rg_demo_1:
	.byte	KEYSH , mus_rg_demo_key+0
	.byte	TEMPO , 188*mus_rg_demo_tbs/2
	.byte		VOICE , 87
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		VOL   , 56*mus_rg_demo_mvl/mxv
	.byte		BEND  , c_v+1
	.byte	W48
	.byte		N03   , An1 , v127
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N03   , An1 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , An1 , v127
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N06   , Ds2 
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N03   , An1 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , An1 , v127
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N03   , An1 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , An1 , v127
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N18   , As1 
	.byte	W06
	.byte		MOD   , 5
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , An1 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N03   , As1 , v120
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , An1 , v127
	.byte	W12
	.byte		N15   
	.byte	W12
	.byte		N06   , Gn2 
	.byte	W06
	.byte		MOD   , 5
	.byte	W18
	.byte		VOICE , 86
	.byte		MOD   , 0
	.byte		VOL   , 79*mus_rg_demo_mvl/mxv
	.byte		N48   , An1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W42
	.byte		        0
	.byte		N48   , Dn1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W42
	.byte		        0
	.byte		N48   , Gs1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W42
	.byte		        0
	.byte		VOL   , 77*mus_rg_demo_mvl/mxv
	.byte		N24   , Cn1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N24   , Cs1 , v120
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		VOICE , 87
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_rg_demo_mvl/mxv
	.byte		N03   , An1 , v127
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N03   , An1 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , An1 , v127
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N06   , Ds2 
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N03   , An1 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , An1 , v127
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N06   , Fn2 
	.byte	W06
	.byte		MOD   , 5
	.byte	W18
	.byte		        0
	.byte		N03   , An1 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        An1 , v120
	.byte	W06
	.byte		N24   , Gn2 , v127
	.byte	W06
	.byte		MOD   , 5
	.byte	W18
	.byte		VOL   , 22*mus_rg_demo_mvl/mxv
	.byte		MOD   , 0
	.byte		N96   , Fs3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W60
	.byte		VOL   , 45*mus_rg_demo_mvl/mxv
	.byte	W24
	.byte		        55*mus_rg_demo_mvl/mxv
	.byte		MOD   , 0
	.byte		N03   , Dn4 
	.byte	W96
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_demo_2:
	.byte	KEYSH , mus_rg_demo_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 56*mus_rg_demo_mvl/mxv
	.byte	W48
	.byte		N03   , Dn2 , v127
	.byte	W12
	.byte		VOICE , 83
	.byte		N03   , Dn2 , v100
	.byte	W12
	.byte		VOICE , 80
	.byte		N12   , An2 , v127
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N03   , Dn2 , v100
	.byte	W06
	.byte		MOD   , 15
	.byte		N03   
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , Dn2 , v127
	.byte	W12
	.byte		VOICE , 83
	.byte		N03   , Dn2 , v100
	.byte	W12
	.byte		VOICE , 80
	.byte		N12   , As2 , v127
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N03   , Dn2 , v100
	.byte	W06
	.byte		MOD   , 15
	.byte		N03   
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , Dn2 , v127
	.byte	W12
	.byte		VOICE , 83
	.byte		N03   , Dn2 , v100
	.byte	W12
	.byte		VOICE , 80
	.byte		N12   , An2 , v127
	.byte	W06
	.byte		MOD   , 5
	.byte	W12
	.byte		        16
	.byte	W06
	.byte		        0
	.byte		N03   , Dn2 
	.byte	W12
	.byte		VOICE , 83
	.byte		N09   , Dn2 , v100
	.byte	W12
	.byte		VOICE , 80
	.byte		N12   , Cs2 , v127
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N06   , Fn2 , v092
	.byte	W06
	.byte		MOD   , 15
	.byte		N06   , En2 , v088
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , Dn2 , v127
	.byte	W12
	.byte		VOICE , 83
	.byte		N03   , Dn2 , v096
	.byte	W12
	.byte		VOICE , 80
	.byte		N12   , An2 , v127
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N03   , Dn2 , v100
	.byte	W06
	.byte		MOD   , 15
	.byte		N03   
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , Dn2 , v127
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   , Dn2 , v100
	.byte	W12
	.byte		VOICE , 80
	.byte		N06   , Cs3 , v127
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N03   , An2 , v088
	.byte	W06
	.byte		MOD   , 15
	.byte		N03   , Cs3 , v092
	.byte	W06
	.byte		VOICE , 80
	.byte		MOD   , 0
	.byte		N48   , Dn4 , v096
	.byte	W48
	.byte		VOICE , 85
	.byte		N48   , Dn3 , v092
	.byte	W06
	.byte		MOD   , 5
	.byte	W42
	.byte		VOICE , 80
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N48   , Cn4 
	.byte	W48
	.byte		VOICE , 85
	.byte		VOL   , 25*mus_rg_demo_mvl/mxv
	.byte		N48   , Cn3 , v120
	.byte	W02
	.byte		VOL   , 27*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        31*mus_rg_demo_mvl/mxv
	.byte	W01
	.byte		MOD   , 5
	.byte	W02
	.byte		VOL   , 36*mus_rg_demo_mvl/mxv
	.byte	W04
	.byte		        41*mus_rg_demo_mvl/mxv
	.byte	W02
	.byte		        45*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        50*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        57*mus_rg_demo_mvl/mxv
	.byte	W04
	.byte		        64*mus_rg_demo_mvl/mxv
	.byte	W02
	.byte		        72*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        75*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        77*mus_rg_demo_mvl/mxv
	.byte	W16
	.byte		VOICE , 80
	.byte		MOD   , 0
	.byte		VOL   , 56*mus_rg_demo_mvl/mxv
	.byte		N03   , Dn3 , v127
	.byte	W12
	.byte		VOICE , 83
	.byte		N03   , Dn3 , v100
	.byte	W12
	.byte		VOICE , 80
	.byte		N12   , An3 , v127
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N03   , Gn3 , v064
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		MOD   , 0
	.byte		N03   , Dn3 , v127
	.byte	W12
	.byte		VOICE , 83
	.byte		N03   , Dn3 , v100
	.byte	W12
	.byte		VOICE , 80
	.byte		N12   , As3 , v127
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N03   , Dn3 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , Dn3 , v127
	.byte	W12
	.byte		VOICE , 83
	.byte		N03   , Dn3 , v100
	.byte	W12
	.byte		VOICE , 80
	.byte		N12   , Cn4 , v127
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N03   , Dn3 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , Dn3 , v127
	.byte	W12
	.byte		VOICE , 83
	.byte		N03   , Dn3 , v104
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 80
	.byte		N12   , Cs4 , v127
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N03   , An3 , v072
	.byte	W03
	.byte		        As3 , v080
	.byte	W03
	.byte		        Cn4 , v092
	.byte	W03
	.byte		        Cs4 , v096
	.byte	W03
	.byte		VOICE , 88
	.byte		MOD   , 0
	.byte		VOL   , 22*mus_rg_demo_mvl/mxv
	.byte		N96   , Dn4 , v127
	.byte	W12
	.byte		MOD   , 5
	.byte		VOL   , 24*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        29*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        33*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        36*mus_rg_demo_mvl/mxv
	.byte	W09
	.byte		        41*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        51*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        60*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        72*mus_rg_demo_mvl/mxv
	.byte	W09
	.byte		        79*mus_rg_demo_mvl/mxv
	.byte	W32
	.byte	W01
	.byte		MOD   , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 68*mus_rg_demo_mvl/mxv
	.byte		N03   , Dn5 
	.byte	W96
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_demo_3:
	.byte	KEYSH , mus_rg_demo_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-63
	.byte		VOL   , 56*mus_rg_demo_mvl/mxv
	.byte		BEND  , c_v+1
	.byte	W48
	.byte		N03   , Dn2 , v127
	.byte	W12
	.byte		        Dn2 , v100
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   , An2 , v127
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N03   , Dn2 , v100
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 81
	.byte		MOD   , 0
	.byte		N03   , Dn2 , v127
	.byte	W12
	.byte		        Dn2 , v100
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   , An2 , v127
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N03   , Dn2 , v100
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 81
	.byte		MOD   , 0
	.byte		N03   , Dn2 , v127
	.byte	W12
	.byte		        Dn2 , v100
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   , An2 , v127
	.byte	W06
	.byte		MOD   , 5
	.byte	W18
	.byte		VOICE , 81
	.byte		MOD   , 0
	.byte		N03   , Dn2 
	.byte	W12
	.byte		N09   , Dn2 , v100
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   , Fs2 , v127
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N06   , Fn2 , v092
	.byte	W06
	.byte		        En2 , v088
	.byte	W06
	.byte		VOICE , 81
	.byte		MOD   , 0
	.byte		N03   , Dn2 , v127
	.byte	W12
	.byte		        Dn2 , v096
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   , An2 , v127
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N03   , Dn2 , v100
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 81
	.byte		MOD   , 0
	.byte		N03   , Dn2 , v127
	.byte	W12
	.byte		N12   , Dn2 , v100
	.byte	W12
	.byte		VOICE , 84
	.byte		N06   , As2 , v127
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N03   , Fn2 , v080
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		VOICE , 81
	.byte		MOD   , 0
	.byte		VOL   , 21*mus_rg_demo_mvl/mxv
	.byte		N48   , An3 , v100
	.byte	W06
	.byte		MOD   , 5
	.byte		VOL   , 34*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        41*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        51*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_demo_mvl/mxv
	.byte	W24
	.byte		VOICE , 82
	.byte		MOD   , 0
	.byte		VOL   , 21*mus_rg_demo_mvl/mxv
	.byte		N48   , Dn3 , v096
	.byte	W06
	.byte		MOD   , 5
	.byte		VOL   , 34*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        41*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        51*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_demo_mvl/mxv
	.byte	W24
	.byte		VOICE , 81
	.byte		MOD   , 0
	.byte		VOL   , 21*mus_rg_demo_mvl/mxv
	.byte		N48   , Gs3 
	.byte	W06
	.byte		MOD   , 5
	.byte		VOL   , 34*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        41*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        51*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_demo_mvl/mxv
	.byte	W24
	.byte		VOICE , 82
	.byte		MOD   , 0
	.byte		VOL   , 21*mus_rg_demo_mvl/mxv
	.byte		N48   , Dn3 , v127
	.byte	W06
	.byte		MOD   , 5
	.byte		VOL   , 34*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        41*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        51*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        68*mus_rg_demo_mvl/mxv
	.byte	W24
	.byte		VOICE , 81
	.byte		MOD   , 0
	.byte		VOL   , 56*mus_rg_demo_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N03   
	.byte	W12
	.byte		        Dn3 , v100
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   , An3 , v127
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N03   , Dn3 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 81
	.byte		MOD   , 0
	.byte		N03   , Dn3 , v127
	.byte	W12
	.byte		        Dn3 , v100
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   , As3 , v127
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N03   , Dn3 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 81
	.byte		MOD   , 0
	.byte		N03   , Dn3 , v127
	.byte	W12
	.byte		        Dn3 , v100
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   , Cn4 , v127
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N03   , Dn3 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 81
	.byte		MOD   , 0
	.byte		N03   , Dn3 , v127
	.byte	W12
	.byte		        Dn3 , v104
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 84
	.byte		N12   , As3 , v127
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N03   , En4 , v056
	.byte	W03
	.byte		        Fn4 , v060
	.byte	W03
	.byte		        Fs4 , v068
	.byte	W03
	.byte		        Gn4 , v072
	.byte	W03
	.byte		VOICE , 89
	.byte		MOD   , 0
	.byte		VOL   , 34*mus_rg_demo_mvl/mxv
	.byte		N96   , An4 , v127
	.byte	W09
	.byte		VOL   , 40*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 47*mus_rg_demo_mvl/mxv
	.byte	W12
	.byte		        52*mus_rg_demo_mvl/mxv
	.byte	W12
	.byte		        58*mus_rg_demo_mvl/mxv
	.byte	W09
	.byte		        69*mus_rg_demo_mvl/mxv
	.byte	W15
	.byte		        79*mus_rg_demo_mvl/mxv
	.byte	W24
	.byte		VOICE , 81
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_rg_demo_mvl/mxv
	.byte		N03   , Dn3 
	.byte	W96
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_demo_4:
	.byte	KEYSH , mus_rg_demo_key+0
	.byte		VOICE , 38
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 90*mus_rg_demo_mvl/mxv
	.byte	W48
	.byte		N12   , Dn2 , v127
	.byte	W12
	.byte		N03   , An2 
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 7
	.byte	W06
	.byte		N03   , An2 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		MOD   , 0
	.byte		N12   , Dn2 , v127
	.byte	W12
	.byte		N03   , As2 
	.byte	W12
	.byte		N12   , An2 
	.byte	W06
	.byte		MOD   , 7
	.byte	W06
	.byte		N03   , An2 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		MOD   , 0
	.byte		N12   , Dn2 , v127
	.byte	W12
	.byte		N03   , An2 
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 7
	.byte	W06
	.byte		N03   , An2 , v120
	.byte	W12
	.byte		MOD   , 0
	.byte		N12   , Dn2 , v127
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N18   , Cs3 
	.byte	W06
	.byte		MOD   , 7
	.byte	W12
	.byte		N06   , As2 , v120
	.byte	W06
	.byte		MOD   , 0
	.byte		N12   , Dn2 , v127
	.byte	W12
	.byte		N03   , An2 
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 7
	.byte	W06
	.byte		N03   , An2 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		MOD   , 0
	.byte		N12   , Dn2 , v127
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        As2 
	.byte	W06
	.byte		MOD   , 7
	.byte	W06
	.byte		N12   , Cs3 , v088
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 72*mus_rg_demo_mvl/mxv
	.byte		N48   , An2 , v127
	.byte	W06
	.byte		MOD   , 7
	.byte	W42
	.byte		        0
	.byte		VOL   , 89*mus_rg_demo_mvl/mxv
	.byte		N48   , Dn2 
	.byte	W06
	.byte		MOD   , 7
	.byte	W42
	.byte		        0
	.byte		VOL   , 72*mus_rg_demo_mvl/mxv
	.byte		N48   , Gs2 
	.byte	W06
	.byte		MOD   , 7
	.byte	W42
	.byte		        0
	.byte		VOL   , 90*mus_rg_demo_mvl/mxv
	.byte		N24   , Cn2 
	.byte	W06
	.byte		MOD   , 7
	.byte	W42
	.byte		        0
	.byte		VOL   , 90*mus_rg_demo_mvl/mxv
	.byte		N12   , Dn2 
	.byte	W12
	.byte		N03   , An2 
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 7
	.byte	W06
	.byte		N06   , An2 , v120
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		MOD   , 0
	.byte		N12   , Dn2 , v127
	.byte	W12
	.byte		N03   , As2 
	.byte	W12
	.byte		N12   , An2 
	.byte	W06
	.byte		MOD   , 7
	.byte	W06
	.byte		N03   , An2 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		MOD   , 0
	.byte		N12   , Dn2 , v127
	.byte	W12
	.byte		N03   , Cn3 
	.byte	W12
	.byte		N12   , As2 
	.byte	W06
	.byte		MOD   , 7
	.byte	W06
	.byte		N03   , As2 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		MOD   , 0
	.byte		N12   , Dn2 , v127
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        As2 
	.byte	W06
	.byte		MOD   , 7
	.byte	W06
	.byte		N06   , En3 , v100
	.byte	W06
	.byte		        Fn3 , v108
	.byte	W06
	.byte		MOD   , 0
	.byte		N96   , Fs3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W84
	.byte		        0
	.byte		N06   , Dn2 
	.byte	W96
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_demo_5:
	.byte	KEYSH , mus_rg_demo_key+0
	.byte		VOICE , 29
	.byte		LFOS  , 54
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 65*mus_rg_demo_mvl/mxv
	.byte	W48
	.byte		MOD   , 0
	.byte		N03   , Dn3 , v127
	.byte	W12
	.byte		N09   , Dn3 , v100
	.byte	W12
	.byte		N12   , An3 , v104
	.byte	W12
	.byte		MOD   , 14
	.byte		N03   , Dn3 , v120
	.byte	W06
	.byte		        Dn3 , v104
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , Dn3 , v127
	.byte	W12
	.byte		N09   , Dn3 , v100
	.byte	W12
	.byte		N12   , As3 , v108
	.byte	W12
	.byte		MOD   , 14
	.byte	W06
	.byte		N03   , Dn3 , v096
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , Dn3 , v127
	.byte	W12
	.byte		N09   , Dn3 , v100
	.byte	W12
	.byte		N12   , An3 , v108
	.byte	W12
	.byte		MOD   , 14
	.byte		N03   , Dn3 , v120
	.byte	W06
	.byte		        Dn3 , v092
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , Dn3 , v127
	.byte	W12
	.byte		N12   , Dn3 , v100
	.byte	W12
	.byte		        Fs3 , v108
	.byte	W12
	.byte		N06   , Fn3 , v092
	.byte	W06
	.byte		        En3 , v088
	.byte	W06
	.byte		N03   , Dn3 , v127
	.byte	W12
	.byte		N06   , Dn3 , v096
	.byte	W12
	.byte		N12   , An3 , v112
	.byte	W12
	.byte		MOD   , 14
	.byte		N03   , Dn3 , v120
	.byte	W06
	.byte		        Dn3 , v092
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , Dn3 , v127
	.byte	W12
	.byte		N06   , Dn3 , v100
	.byte	W12
	.byte		N12   , Cs4 , v112
	.byte	W12
	.byte		N06   , An3 , v088
	.byte	W06
	.byte		        Cs4 , v092
	.byte	W06
	.byte		VOICE , 30
	.byte		VOL   , 56*mus_rg_demo_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N48   , Dn4 , v108
	.byte	W12
	.byte		MOD   , 8
	.byte	W06
	.byte		PAN   , c_v+0
	.byte	W06
	.byte		        c_v-16
	.byte	W06
	.byte		        c_v-32
	.byte	W18
	.byte		MOD   , 0
	.byte		N48   , Dn3 , v100
	.byte	W12
	.byte		MOD   , 8
	.byte	W06
	.byte		PAN   , c_v+0
	.byte	W06
	.byte		        c_v+16
	.byte	W06
	.byte		        c_v+32
	.byte	W18
	.byte		MOD   , 0
	.byte		N48   , Cn4 , v104
	.byte	W12
	.byte		MOD   , 8
	.byte	W06
	.byte		PAN   , c_v+0
	.byte	W06
	.byte		        c_v-16
	.byte	W06
	.byte		        c_v-32
	.byte	W18
	.byte		MOD   , 0
	.byte		VOL   , 28*mus_rg_demo_mvl/mxv
	.byte		N48   , Cn3 , v096
	.byte	W02
	.byte		VOL   , 32*mus_rg_demo_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v-27
	.byte	W02
	.byte		        c_v-20
	.byte		VOL   , 35*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-14
	.byte		VOL   , 38*mus_rg_demo_mvl/mxv
	.byte	W04
	.byte		MOD   , 8
	.byte		PAN   , c_v-10
	.byte		VOL   , 41*mus_rg_demo_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-5
	.byte		VOL   , 47*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v+5
	.byte		VOL   , 54*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v+10
	.byte		VOL   , 59*mus_rg_demo_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v+15
	.byte	W02
	.byte		        c_v+19
	.byte	W22
	.byte		VOICE , 62
	.byte		MOD   , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 62*mus_rg_demo_mvl/mxv
	.byte		N03   , Dn4 , v127
	.byte	W12
	.byte		N09   , Dn4 , v100
	.byte	W12
	.byte		N12   , An4 , v127
	.byte	W06
	.byte		MOD   , 15
	.byte	W06
	.byte		        0
	.byte		N03   , Dn4 , v120
	.byte	W06
	.byte		        Dn4 , v096
	.byte	W06
	.byte		        Dn4 , v127
	.byte	W12
	.byte		N06   , Dn4 , v100
	.byte	W12
	.byte		N12   , As4 , v127
	.byte	W06
	.byte		MOD   , 15
	.byte	W06
	.byte		        0
	.byte		N03   , Dn4 , v120
	.byte	W06
	.byte		        Dn4 , v096
	.byte	W06
	.byte		        Dn4 , v127
	.byte	W12
	.byte		N06   , Dn4 , v100
	.byte	W12
	.byte		MOD   , 0
	.byte		N24   , Cn5 , v127
	.byte	W06
	.byte		MOD   , 10
	.byte	W18
	.byte		        0
	.byte		N03   , Dn4 
	.byte	W12
	.byte		        Dn4 , v120
	.byte	W06
	.byte		        Dn4 , v088
	.byte	W06
	.byte		N12   , Cs5 , v127
	.byte	W06
	.byte		MOD   , 15
	.byte	W06
	.byte		VOICE , 62
	.byte		MOD   , 0
	.byte		N03   , An4 , v072
	.byte	W03
	.byte		        As4 , v080
	.byte	W03
	.byte		        Cn5 , v092
	.byte	W03
	.byte		        Cs5 , v096
	.byte	W03
	.byte		VOL   , 20*mus_rg_demo_mvl/mxv
	.byte		N96   , Dn5 , v127
	.byte	W06
	.byte		VOL   , 24*mus_rg_demo_mvl/mxv
	.byte	W09
	.byte		        33*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        37*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 43*mus_rg_demo_mvl/mxv
	.byte	W09
	.byte		        49*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_demo_mvl/mxv
	.byte	W09
	.byte		        68*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        75*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        79*mus_rg_demo_mvl/mxv
	.byte	W32
	.byte	W01
	.byte		VOICE , 1
	.byte		MOD   , 0
	.byte		N03   , Dn5 , v100
	.byte	W96
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_demo_6:
	.byte	KEYSH , mus_rg_demo_key+0
	.byte		VOICE , 62
	.byte		PAN   , c_v-8
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 62*mus_rg_demo_mvl/mxv
	.byte	W48
	.byte		PAN   , c_v-48
	.byte		N24   , Dn2 , v120
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N24   , Dn3 , v124
	.byte	W24
	.byte		PAN   , c_v+48
	.byte		N24   , Dn2 , v120
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N24   , Ds3 , v124
	.byte	W24
	.byte		PAN   , c_v-48
	.byte		N24   , Dn2 , v120
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N24   , Dn3 , v127
	.byte	W24
	.byte		PAN   , c_v+48
	.byte		N24   , Dn2 , v120
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N24   , As2 , v127
	.byte	W24
	.byte		PAN   , c_v-48
	.byte		N24   , Dn2 , v120
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N24   , Dn3 , v127
	.byte	W24
	.byte		PAN   , c_v+48
	.byte		N24   , Dn2 , v120
	.byte	W24
	.byte		PAN   , c_v-1
	.byte		N24   , Gn3 , v124
	.byte	W24
	.byte		PAN   , c_v-48
	.byte		VOL   , 56*mus_rg_demo_mvl/mxv
	.byte		N12   , Dn3 , v120
	.byte	W12
	.byte		N03   , En3 , v088
	.byte	W03
	.byte		        Gn3 , v092
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N03   , An3 , v100
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		PAN   , c_v+48
	.byte		N24   , Dn4 , v108
	.byte	W24
	.byte		N48   , Dn2 
	.byte	W48
	.byte		N12   , Cn3 , v112
	.byte	W12
	.byte		N03   , En3 , v080
	.byte	W03
	.byte		        Gn3 , v088
	.byte	W03
	.byte		        An3 , v092
	.byte	W03
	.byte		        Bn3 , v100
	.byte	W03
	.byte		PAN   , c_v-48
	.byte		N24   , Cn4 , v108
	.byte	W24
	.byte		VOL   , 29*mus_rg_demo_mvl/mxv
	.byte		N48   , Cn2 , v127
	.byte	W02
	.byte		VOL   , 34*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_demo_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v-32
	.byte	W02
	.byte		VOL   , 44*mus_rg_demo_mvl/mxv
	.byte	W04
	.byte		        52*mus_rg_demo_mvl/mxv
	.byte		PAN   , c_v-16
	.byte	W02
	.byte		VOL   , 52*mus_rg_demo_mvl/mxv
	.byte	W01
	.byte		        59*mus_rg_demo_mvl/mxv
	.byte	W02
	.byte		        58*mus_rg_demo_mvl/mxv
	.byte	W01
	.byte		        65*mus_rg_demo_mvl/mxv
	.byte		PAN   , c_v+16
	.byte	W02
	.byte		VOL   , 59*mus_rg_demo_mvl/mxv
	.byte	W01
	.byte		        70*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v+34
	.byte	W06
	.byte		        c_v+41
	.byte	W18
	.byte		VOICE , 62
	.byte		VOL   , 59*mus_rg_demo_mvl/mxv
	.byte		N24   , Dn2 , v120
	.byte	W24
	.byte		PAN   , c_v-1
	.byte		N24   , Dn4 , v104
	.byte	W24
	.byte		PAN   , c_v-48
	.byte		N24   , Dn2 , v120
	.byte	W24
	.byte		PAN   , c_v-1
	.byte		N24   , Ds4 , v104
	.byte	W24
	.byte		PAN   , c_v+48
	.byte		N24   , Dn2 , v120
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N24   , Fn4 , v104
	.byte	W24
	.byte		PAN   , c_v-48
	.byte		N24   , Dn2 , v120
	.byte	W24
	.byte		PAN   , c_v-1
	.byte		N24   , Gn4 , v100
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		VOL   , 29*mus_rg_demo_mvl/mxv
	.byte		N96   , Dn3 , v120
	.byte	W06
	.byte		VOL   , 34*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        37*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        41*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        48*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        51*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        55*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        62*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        65*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        70*mus_rg_demo_mvl/mxv
	.byte	W09
	.byte		        73*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        77*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        78*mus_rg_demo_mvl/mxv
	.byte	W09
	.byte		        79*mus_rg_demo_mvl/mxv
	.byte		N03   , Dn5 , v108
	.byte	W96
	.byte	FINE

@********************** Track  7 **********************@

mus_rg_demo_7:
	.byte	KEYSH , mus_rg_demo_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v-64
	.byte		VOL   , 11*mus_rg_demo_mvl/mxv
	.byte		N03   , En1 , v112
	.byte	W03
	.byte		PAN   , c_v+63
	.byte		VOL   , 17*mus_rg_demo_mvl/mxv
	.byte		N03   
	.byte	W03
	.byte		PAN   , c_v-64
	.byte		VOL   , 22*mus_rg_demo_mvl/mxv
	.byte		N03   
	.byte	W03
	.byte		PAN   , c_v+63
	.byte		VOL   , 27*mus_rg_demo_mvl/mxv
	.byte		N03   
	.byte	W03
	.byte		PAN   , c_v-64
	.byte		VOL   , 34*mus_rg_demo_mvl/mxv
	.byte		N03   
	.byte	W03
	.byte		PAN   , c_v+63
	.byte		VOL   , 38*mus_rg_demo_mvl/mxv
	.byte		N03   
	.byte	W03
	.byte		PAN   , c_v-64
	.byte		VOL   , 45*mus_rg_demo_mvl/mxv
	.byte		N03   
	.byte	W03
	.byte		PAN   , c_v+63
	.byte		VOL   , 49*mus_rg_demo_mvl/mxv
	.byte		N03   
	.byte	W03
	.byte		PAN   , c_v-64
	.byte		VOL   , 56*mus_rg_demo_mvl/mxv
	.byte		N03   
	.byte	W03
	.byte		PAN   , c_v+63
	.byte		VOL   , 62*mus_rg_demo_mvl/mxv
	.byte		N03   
	.byte	W03
	.byte		PAN   , c_v-64
	.byte		VOL   , 68*mus_rg_demo_mvl/mxv
	.byte		N03   
	.byte	W03
	.byte		PAN   , c_v+63
	.byte		VOL   , 73*mus_rg_demo_mvl/mxv
	.byte		N03   
	.byte	W03
	.byte		PAN   , c_v-64
	.byte		VOL   , 79*mus_rg_demo_mvl/mxv
	.byte		N03   
	.byte	W03
	.byte		PAN   , c_v+63
	.byte		VOL   , 85*mus_rg_demo_mvl/mxv
	.byte		N03   
	.byte	W03
	.byte		PAN   , c_v-64
	.byte		VOL   , 90*mus_rg_demo_mvl/mxv
	.byte		N03   
	.byte	W03
	.byte		PAN   , c_v+63
	.byte		N03   
	.byte	W03
	.byte		VOL   , 90*mus_rg_demo_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N09   , Fn1 , v127
	.byte		N24   , An2 , v112
	.byte	W12
	.byte		N06   , Cn1 , v127
	.byte	W12
	.byte		N12   , Dn1 , v100
	.byte		N48   , En2 , v112
	.byte	W18
	.byte		N03   , En1 , v096
	.byte	W03
	.byte		        En1 , v100
	.byte	W03
	.byte		N06   , En1 , v127
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N12   , Dn1 , v100
	.byte		N24   , Cs2 , v112
	.byte	W12
	.byte		N03   , En1 , v100
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte		N48   , Gn2 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N12   , Dn1 , v088
	.byte	W12
	.byte		N06   , Cn1 , v096
	.byte	W12
	.byte		N12   , En1 
	.byte	W12
	.byte		        Fn1 , v112
	.byte	W12
	.byte		        Dn1 , v127
	.byte		N24   , An2 
	.byte	W12
	.byte		N06   , Cn1 , v112
	.byte		N06   , Dn1 , v072
	.byte	W06
	.byte		N03   , Dn1 , v108
	.byte	W06
	.byte		N10   , Cn1 , v112
	.byte		N24   , Cs2 , v108
	.byte	W12
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		N12   , Dn1 , v124
	.byte	W12
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		N12   , Dn1 
	.byte		N24   , Gn2 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N12   , Dn1 
	.byte		N24   , Bn2 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N04   , Cn1 , v127
	.byte		N04   , Bn1 , v112
	.byte	W16
	.byte		        Cn1 , v084
	.byte		N08   , Fn1 , v127
	.byte	W08
	.byte		N04   , Cn1 
	.byte		N04   , Dn2 , v112
	.byte	W08
	.byte		        Cn1 , v080
	.byte		N04   , Bn1 , v112
	.byte	W04
	.byte		        Cn1 , v076
	.byte		N04   , An1 , v084
	.byte	W04
	.byte		        Cn1 , v100
	.byte		N08   , Fn1 , v127
	.byte	W08
	.byte		N04   , Cn1 , v112
	.byte		N15   , En2 , v127
	.byte	W16
	.byte		N24   , Dn1 
	.byte	W08
	.byte		N08   , Cn1 
	.byte	W16
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        Dn1 , v127
	.byte		N16   , Cs2 
	.byte	W08
	.byte		N04   , Cn1 , v112
	.byte	W08
	.byte		N08   
	.byte		N04   , An1 
	.byte	W04
	.byte		        An1 , v084
	.byte	W04
	.byte		N08   , Cn1 , v127
	.byte		N04   , Cn2 , v104
	.byte	W08
	.byte		        An1 
	.byte	W04
	.byte		        Gn1 , v120
	.byte	W04
	.byte		        Cn1 , v127
	.byte		N04   , Fn1 
	.byte	W04
	.byte		        Fn1 , v120
	.byte	W04
	.byte		VOL   , 90*mus_rg_demo_mvl/mxv
	.byte		N08   , Cn1 , v127
	.byte		N04   , Cn2 , v104
	.byte	W08
	.byte		        An1 
	.byte	W04
	.byte		        Gn1 , v100
	.byte	W04
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		N04   , Cn1 , v120
	.byte		N04   , Fn1 , v127
	.byte	W04
	.byte		        Fn1 , v120
	.byte	W04
	.byte		N08   , Cn1 , v112
	.byte		N16   , Dn1 , v127
	.byte		N24   , Bn2 
	.byte	W16
	.byte		N04   , Cn1 
	.byte		N04   , Dn1 , v100
	.byte	W08
	.byte		N06   , Cn1 , v127
	.byte		N96   , Cs2 , v120
	.byte	W12
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		N12   , Dn1 , v127
	.byte	W12
	.byte		N06   , Cn1 , v120
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 , v127
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte		N48   , En2 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N12   , Dn1 , v127
	.byte	W12
	.byte		N06   , Cn1 , v120
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v127
	.byte		N12   , Gn2 
	.byte	W12
	.byte		N06   , Cn1 
	.byte		N12   , Cs2 , v108
	.byte	W12
	.byte		N06   , Dn1 , v120
	.byte		N24   , An2 
	.byte	W06
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , Dn1 , v127
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		VOL   , 45*mus_rg_demo_mvl/mxv
	.byte		N06   , Dn1 , v120
	.byte		N96   , Cn3 , v104
	.byte	W06
	.byte		VOL   , 53*mus_rg_demo_mvl/mxv
	.byte	W06
	.byte		        59*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        66*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        75*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        78*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        82*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        85*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        90*mus_rg_demo_mvl/mxv
	.byte	W42
	.byte		N03   , Dn2 , v120
	.byte	W03
	.byte		        Cn2 
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		        Fn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn1 
	.byte	W96
	.byte	FINE

@********************** Track  8 **********************@

mus_rg_demo_8:
	.byte	KEYSH , mus_rg_demo_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 68*mus_rg_demo_mvl/mxv
	.byte		N03   , Gn4 , v127
	.byte	W03
	.byte		        Gn4 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N12   , Gn4 , v127
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Gn4 , v112
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , Gn4 , v127
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   
	.byte	W24
mus_rg_demo_8_000:
	.byte		N12   , Gn4 , v127
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Gn4 , v112
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte	PEND
	.byte		N12   , Gn4 , v127
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		        Gn4 , v112
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N48   , Gn4 , v127
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Gn4 , v112
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte	PATT
	 .word	mus_rg_demo_8_000
	.byte		N12   , Gn4 , v127
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		VOICE , 125
	.byte		BEND  , c_v-64
	.byte		TIE   , Cn4 , v112
	.byte	W03
	.byte		BEND  , c_v-64
	.byte	W06
	.byte		        c_v-62
	.byte	W03
	.byte		        c_v-59
	.byte	W03
	.byte		        c_v-57
	.byte	W06
	.byte		        c_v-53
	.byte	W03
	.byte		        c_v-49
	.byte	W06
	.byte		        c_v-47
	.byte	W03
	.byte		        c_v-43
	.byte	W03
	.byte		        c_v-39
	.byte	W06
	.byte		        c_v-36
	.byte	W03
	.byte		        c_v-31
	.byte	W06
	.byte		        c_v-25
	.byte	W03
	.byte		        c_v-19
	.byte	W03
	.byte		        c_v-14
	.byte	W03
	.byte		        c_v-9
	.byte	W03
	.byte		        c_v-6
	.byte	W03
	.byte		        c_v-1
	.byte	W03
	.byte		        c_v+3
	.byte	W03
	.byte		        c_v+12
	.byte	W03
	.byte		        c_v+20
	.byte	W03
	.byte		        c_v+28
	.byte	W03
	.byte		        c_v+37
	.byte	W03
	.byte		        c_v+43
	.byte	W03
	.byte		        c_v+53
	.byte	W03
	.byte		        c_v+57
	.byte	W03
	.byte		        c_v+63
	.byte	W03
	.byte		VOL   , 66*mus_rg_demo_mvl/mxv
	.byte	W02
	.byte		        63*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        60*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_demo_mvl/mxv
	.byte	W04
	.byte		EOT   
	.byte		VOL   , 55*mus_rg_demo_mvl/mxv
	.byte	W02
	.byte		        53*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        50*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        48*mus_rg_demo_mvl/mxv
	.byte	W04
	.byte		        47*mus_rg_demo_mvl/mxv
	.byte	W02
	.byte		        45*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        42*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        40*mus_rg_demo_mvl/mxv
	.byte	W04
	.byte		        39*mus_rg_demo_mvl/mxv
	.byte	W02
	.byte		        36*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        31*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        31*mus_rg_demo_mvl/mxv
	.byte	W04
	.byte		        29*mus_rg_demo_mvl/mxv
	.byte	W02
	.byte		        26*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        25*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        21*mus_rg_demo_mvl/mxv
	.byte	W04
	.byte		        21*mus_rg_demo_mvl/mxv
	.byte	W02
	.byte		        19*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        17*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        15*mus_rg_demo_mvl/mxv
	.byte	W04
	.byte		        13*mus_rg_demo_mvl/mxv
	.byte	W02
	.byte		        12*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        9*mus_rg_demo_mvl/mxv
	.byte	W03
	.byte		        7*mus_rg_demo_mvl/mxv
	.byte	W04
	.byte		        2*mus_rg_demo_mvl/mxv
	.byte	W02
	.byte		        0*mus_rg_demo_mvl/mxv
	.byte	W10
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_demo:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_demo_pri	@ Priority
	.byte	mus_rg_demo_rev	@ Reverb.

	.word	mus_rg_demo_grp

	.word	mus_rg_demo_1
	.word	mus_rg_demo_2
	.word	mus_rg_demo_3
	.word	mus_rg_demo_4
	.word	mus_rg_demo_5
	.word	mus_rg_demo_6
	.word	mus_rg_demo_7
	.word	mus_rg_demo_8

	.end
