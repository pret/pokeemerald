	.include "MPlayDef.s"

	.equ	mus_demo1_grp, voicegroup060
	.equ	mus_demo1_pri, 0
	.equ	mus_demo1_rev, reverb_set+50
	.equ	mus_demo1_mvl, 127
	.equ	mus_demo1_key, 0
	.equ	mus_demo1_tbs, 1
	.equ	mus_demo1_exg, 0
	.equ	mus_demo1_cmp, 1

	.section .rodata
	.global	mus_demo1
	.align	2

@********************** Track  1 **********************@

mus_demo1_1:
	.byte	KEYSH , mus_demo1_key+0
	.byte	TEMPO , 118*mus_demo1_tbs/2
	.byte		VOICE , 48
	.byte		PAN   , c_v+35
	.byte		VOL   , 51*mus_demo1_mvl/mxv
	.byte		LFOS  , 44
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	TEMPO , 128*mus_demo1_tbs/2
	.byte	W96
	.byte	TEMPO , 136*mus_demo1_tbs/2
	.byte	W48
	.byte	TEMPO , 60*mus_demo1_tbs/2
	.byte	W24
	.byte	TEMPO , 62*mus_demo1_tbs/2
	.byte		VOL   , 34*mus_demo1_mvl/mxv
	.byte	W12
	.byte	TEMPO , 48*mus_demo1_tbs/2
	.byte		N06   , Gn3 , v112
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte	TEMPO , 154*mus_demo1_tbs/2
	.byte		PAN   , c_v-34
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		TIE   , Gn3 
	.byte	W48
	.byte		VOL   , 34*mus_demo1_mvl/mxv
	.byte	W20
	.byte		        30*mus_demo1_mvl/mxv
	.byte	W06
	.byte		        28*mus_demo1_mvl/mxv
	.byte	W10
	.byte		        24*mus_demo1_mvl/mxv
	.byte	W05
	.byte		        22*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        19*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        17*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        15*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        11*mus_demo1_mvl/mxv
	.byte	W09
	.byte		        9*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        5*mus_demo1_mvl/mxv
	.byte	W09
	.byte		        4*mus_demo1_mvl/mxv
	.byte	W06
	.byte		        2*mus_demo1_mvl/mxv
	.byte	W16
	.byte		EOT   
	.byte	TEMPO , 106*mus_demo1_tbs/2
	.byte	W96
	.byte	W96
	.byte	FINE

@********************** Track  2 **********************@

mus_demo1_2:
	.byte	KEYSH , mus_demo1_key+0
	.byte		VOICE , 73
	.byte		PAN   , c_v+0
	.byte		LFOS  , 44
	.byte		VOL   , 65*mus_demo1_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W72
	.byte		VOL   , 66*mus_demo1_mvl/mxv
	.byte		N03   , Gn5 , v072
	.byte	W03
	.byte		        An5 
	.byte	W03
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		VOL   , 68*mus_demo1_mvl/mxv
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        Cn5 , v028
	.byte	W06
	.byte		N03   , Ds5 , v064
	.byte	W03
	.byte		N80   , Dn5 , v072
	.byte	W09
	.byte		MOD   , 2
	.byte	W12
	.byte		VOL   , 65*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        61*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        59*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        54*mus_demo1_mvl/mxv
	.byte	W04
	.byte		MOD   , 6
	.byte		VOL   , 52*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        48*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        45*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        43*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        41*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        40*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        36*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        34*mus_demo1_mvl/mxv
	.byte	W04
	.byte		MOD   , 9
	.byte		VOL   , 32*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        31*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        28*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        27*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        24*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        21*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        17*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        14*mus_demo1_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_demo1_mvl/mxv
	.byte		N03   , Gs4 , v084
	.byte	W03
	.byte		N21   , An4 , v092
	.byte	W21
	.byte		N24   , Bn4 , v096
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		N03   , Gs5 , v092
	.byte	W03
	.byte		N92   , Gn5 , v100
	.byte	W21
	.byte		MOD   , 6
	.byte		VOL   , 67*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        63*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        62*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        58*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        56*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        55*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        52*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        51*mus_demo1_mvl/mxv
	.byte	W06
	.byte		        48*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        45*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        44*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        41*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        39*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        37*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        35*mus_demo1_mvl/mxv
	.byte	W04
	.byte		MOD   , 12
	.byte	W02
	.byte		VOL   , 32*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        29*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        28*mus_demo1_mvl/mxv
	.byte	W06
	.byte		        27*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        25*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        24*mus_demo1_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_demo1_mvl/mxv
	.byte		N03   , Fn5 , v092
	.byte	W03
	.byte		        Gn5 , v096
	.byte	W03
	.byte		N06   , Fn5 , v100
	.byte	W06
	.byte		        En5 , v096
	.byte	W06
	.byte		        Dn5 , v100
	.byte	W06
	.byte		VOL   , 68*mus_demo1_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , Cn5 
	.byte	W12
	.byte		N03   , Ds5 , v080
	.byte	W03
	.byte		TIE   , Dn5 , v096
	.byte	W09
	.byte		MOD   , 2
	.byte	W24
	.byte		VOL   , 67*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        65*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        63*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        59*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        58*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        55*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        54*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        51*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        47*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        45*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        43*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        40*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        39*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        37*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        34*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        33*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        32*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        31*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        29*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        27*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        26*mus_demo1_mvl/mxv
	.byte	W05
	.byte		        25*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        26*mus_demo1_mvl/mxv
	.byte	W04
	.byte		MOD   , 6
	.byte		VOL   , 27*mus_demo1_mvl/mxv
	.byte	W05
	.byte		        29*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        31*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        34*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        36*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        41*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        43*mus_demo1_mvl/mxv
	.byte	W04
	.byte		MOD   , 9
	.byte		VOL   , 47*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        51*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        52*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        58*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        62*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        63*mus_demo1_mvl/mxv
	.byte	W01
	.byte		        63*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        66*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        67*mus_demo1_mvl/mxv
	.byte	W04
	.byte		EOT   
	.byte		MOD   , 0
	.byte		VOL   , 72*mus_demo1_mvl/mxv
	.byte		N06   , Fn5 , v112
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		VOICE , 60
	.byte		VOL   , 68*mus_demo1_mvl/mxv
	.byte		N24   , An4 , v052
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		N03   , Gs5 
	.byte	W03
	.byte		N21   , Gn5 
	.byte	W21
	.byte	W84
	.byte		N06   , Fn4 , v112
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		VOICE , 60
	.byte		VOL   , 68*mus_demo1_mvl/mxv
	.byte		N06   , En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N60   , Gn4 
	.byte	W24
	.byte		MOD   , 4
	.byte		VOL   , 66*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        63*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        60*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        56*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        52*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        47*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        43*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        37*mus_demo1_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 36*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        33*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        31*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        29*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        68*mus_demo1_mvl/mxv
	.byte		N03   , Fs4 , v092
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        En4 , v084
	.byte	W03
	.byte		        Ds4 , v080
	.byte	W03
	.byte		VOICE , 73
	.byte	W12
	.byte		N06   , En4 , v112
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N03   , Cn5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		VOICE , 73
	.byte		N06   , Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N24   , Fn4 
	.byte	W24
	.byte	W03
	.byte		N03   , En4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		VOICE , 73
	.byte		N06   , Gn4 
	.byte	W12
	.byte		        Bn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Gn5 
	.byte	W12
	.byte		        Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		VOICE , 1
	.byte		PAN   , c_v-34
	.byte		N05   , Bn4 , v096
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		N03   , Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N06   , Fn5 
	.byte	W06
	.byte		VOICE , 60
	.byte		PAN   , c_v-12
	.byte		VOL   , 58*mus_demo1_mvl/mxv
	.byte		N60   , En5 , v112
	.byte	W24
	.byte		MOD   , 4
	.byte		VOL   , 54*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        51*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        48*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        46*mus_demo1_mvl/mxv
	.byte	W06
	.byte		        45*mus_demo1_mvl/mxv
	.byte	W06
	.byte		        43*mus_demo1_mvl/mxv
	.byte	W06
	.byte		        42*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        41*mus_demo1_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte		VOL   , 56*mus_demo1_mvl/mxv
	.byte		N06   , Fn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Dn5 
	.byte	W03
	.byte		VOICE , 48
	.byte	W03
	.byte		N06   , Fn5 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		VOL   , 56*mus_demo1_mvl/mxv
	.byte		N24   , Gn5 , v092
	.byte	W24
	.byte		        Fn5 
	.byte	W24
	.byte		N16   , En5 
	.byte	W16
	.byte		        Dn5 
	.byte	W16
	.byte		        Cn5 
	.byte	W16
	.byte		VOICE , 60
	.byte		PAN   , c_v-16
	.byte		VOL   , 62*mus_demo1_mvl/mxv
	.byte		N06   , Gn3 , v112
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N18   , Bn3 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N18   , Dn4 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N03   , Cn4 , v092
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		N08   , Fn4 , v104
	.byte	W08
	.byte		N04   , Dn4 , v108
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		TIE   , Gn4 
	.byte	W48
	.byte		MOD   , 7
	.byte		VOL   , 62*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        60*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        58*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        55*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        54*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        51*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        51*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        48*mus_demo1_mvl/mxv
	.byte	W06
	.byte		        45*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        43*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        41*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        38*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        36*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        35*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        33*mus_demo1_mvl/mxv
	.byte	W06
	.byte		        30*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        28*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        24*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        22*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        20*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        17*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        14*mus_demo1_mvl/mxv
	.byte	W06
	.byte		        12*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        11*mus_demo1_mvl/mxv
	.byte	W07
	.byte		        10*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        7*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        6*mus_demo1_mvl/mxv
	.byte	W07
	.byte		EOT   
	.byte		MOD   , 1
	.byte	W96
	.byte	W96
	.byte	FINE

@********************** Track  3 **********************@

mus_demo1_3:
	.byte	KEYSH , mus_demo1_key+0
	.byte		VOICE , 58
	.byte		PAN   , c_v+0
	.byte		LFOS  , 44
	.byte		VOL   , 88*mus_demo1_mvl/mxv
	.byte	W96
	.byte	W48
	.byte		N06   , Cn2 , v072
	.byte	W06
	.byte		        Cn2 , v024
	.byte	W06
	.byte		        Bn1 , v072
	.byte	W06
	.byte		        Bn1 , v024
	.byte	W06
	.byte		        An1 , v072
	.byte	W06
	.byte		        An1 , v024
	.byte	W06
	.byte		        Gn1 , v072
	.byte	W06
	.byte		        Gn1 , v024
	.byte	W06
	.byte		N12   , Fn1 , v092
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W06
	.byte		        Cn2 , v036
	.byte	W06
	.byte		        Gn2 , v080
	.byte	W06
	.byte		        Gn2 , v036
	.byte	W06
	.byte		N36   , An2 , v084
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		VOL   , 85*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        77*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        75*mus_demo1_mvl/mxv
	.byte	W01
	.byte		        72*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        70*mus_demo1_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 87*mus_demo1_mvl/mxv
	.byte		N09   , Gn2 , v080
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		N12   , Fn1 , v096
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Dn2 , v036
	.byte	W06
	.byte		        An2 , v072
	.byte	W06
	.byte		        An2 , v036
	.byte	W06
	.byte		N36   , Bn2 , v080
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		VOL   , 85*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        77*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        75*mus_demo1_mvl/mxv
	.byte	W01
	.byte		        72*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        70*mus_demo1_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 87*mus_demo1_mvl/mxv
	.byte		N09   , Cn3 , v072
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N12   , Fn1 , v096
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W06
	.byte		        Cn2 , v036
	.byte	W06
	.byte		        Gn2 , v080
	.byte	W06
	.byte		        Gn2 , v036
	.byte	W06
	.byte		N60   , An2 , v088
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		VOL   , 85*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        79*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        75*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        70*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        65*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        60*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        58*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        56*mus_demo1_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 89*mus_demo1_mvl/mxv
	.byte		N12   , Fn1 , v096
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Dn2 , v036
	.byte	W06
	.byte		        An2 , v084
	.byte	W06
	.byte		        An2 , v036
	.byte	W06
	.byte		N36   , Bn2 , v084
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		VOL   , 85*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        77*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        75*mus_demo1_mvl/mxv
	.byte	W01
	.byte		        72*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        70*mus_demo1_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_demo1_mvl/mxv
	.byte		N12   , An2 , v080
	.byte	W12
	.byte		        Gn2 , v072
	.byte	W12
	.byte		N06   , Fn1 , v112
	.byte	W12
	.byte		N12   , En1 
	.byte	W24
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Cn2 
	.byte	W24
	.byte		        Fs1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N06   , Fs1 
	.byte	W12
	.byte		N04   , Gn1 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		N36   , Gn0 , v088
	.byte	W12
	.byte		VOL   , 89*mus_demo1_mvl/mxv
	.byte		MOD   , 6
	.byte	W02
	.byte		VOL   , 80*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        69*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        67*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        60*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        56*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        51*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        40*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        90*mus_demo1_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Gn1 , v112
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N12   , Cn1 , v127
	.byte	W60
	.byte		        Gn0 , v112
	.byte	W12
	.byte		        Gn0 , v036
	.byte	W12
	.byte		        Gn1 , v112
	.byte	W12
	.byte		N06   , Cn1 , v127
	.byte	W12
	.byte		        Cn1 , v036
	.byte	W24
	.byte		        Gn1 , v120
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		N12   , Cn2 , v124
	.byte	W12
	.byte		N06   , Cn2 , v036
	.byte	W12
	.byte		        Gn1 , v112
	.byte	W12
	.byte		        Gn1 , v036
	.byte	W12
	.byte		N12   , Gn1 , v052
	.byte	W60
	.byte		N06   , Gn0 , v112
	.byte	W12
	.byte		        Gn0 , v036
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Gn0 , v036
	.byte	W24
	.byte		        Gn1 , v120
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		N12   , Gn1 , v124
	.byte	W12
	.byte		N06   , Gn1 , v036
	.byte	W12
	.byte		        Gn0 , v112
	.byte	W12
	.byte		        Gn0 , v036
	.byte	W12
	.byte		N12   , An0 , v052
	.byte	W60
	.byte		N06   , En0 , v112
	.byte	W12
	.byte		        En0 , v036
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        An0 , v036
	.byte	W24
	.byte		        En1 , v116
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		N12   , An1 , v124
	.byte	W12
	.byte		N06   , An1 , v036
	.byte	W12
	.byte		        En0 , v112
	.byte	W12
	.byte		        En0 , v036
	.byte	W12
	.byte		VOICE , 58
	.byte		VOL   , 78*mus_demo1_mvl/mxv
	.byte		N48   , Gn1 , v112
	.byte	W24
	.byte		VOL   , 77*mus_demo1_mvl/mxv
	.byte		MOD   , 10
	.byte	W02
	.byte		VOL   , 75*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        72*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        69*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        65*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        61*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        57*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        54*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        78*mus_demo1_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , Fn1 
	.byte	W24
	.byte		VOL   , 73*mus_demo1_mvl/mxv
	.byte		MOD   , 10
	.byte	W02
	.byte		VOL   , 70*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        65*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        60*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        57*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        55*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        48*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        46*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        79*mus_demo1_mvl/mxv
	.byte		MOD   , 0
	.byte		N30   , Dn1 
	.byte	W15
	.byte		VOL   , 75*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        73*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        70*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        70*mus_demo1_mvl/mxv
	.byte	W06
	.byte		N06   , Cn1 , v116
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        An0 
	.byte	W06
	.byte		VOICE , 58
	.byte		VOL   , 79*mus_demo1_mvl/mxv
	.byte		TIE   , Gn0 
	.byte	W48
	.byte		VOL   , 80*mus_demo1_mvl/mxv
	.byte		MOD   , 7
	.byte	W02
	.byte		VOL   , 76*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        74*mus_demo1_mvl/mxv
	.byte	W07
	.byte		        70*mus_demo1_mvl/mxv
	.byte	W05
	.byte		        68*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        66*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        64*mus_demo1_mvl/mxv
	.byte	W05
	.byte		        62*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        60*mus_demo1_mvl/mxv
	.byte	W06
	.byte		        56*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        55*mus_demo1_mvl/mxv
	.byte	W07
	.byte		        51*mus_demo1_mvl/mxv
	.byte	W08
	.byte		        47*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        45*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        39*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        38*mus_demo1_mvl/mxv
	.byte	W07
	.byte		        34*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        30*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        28*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        24*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        22*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        17*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        11*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        5*mus_demo1_mvl/mxv
	.byte	W04
	.byte		EOT   
	.byte		VOL   , 4*mus_demo1_mvl/mxv
	.byte		MOD   , 0
	.byte	W24
	.byte		VOICE , 47
	.byte		VOL   , 86*mus_demo1_mvl/mxv
	.byte	W48
	.byte		N20   , Gn1 , v084
	.byte	W24
	.byte		N24   , Gn1 , v076
	.byte	W96
	.byte	FINE

@********************** Track  4 **********************@

mus_demo1_4:
	.byte	KEYSH , mus_demo1_key+0
	.byte		VOICE , 45
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 34*mus_demo1_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N03   , En4 , v068
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W06
	.byte		N02   , Cn4 , v064
	.byte	W06
	.byte		        Cn4 , v036
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W06
	.byte		        Dn4 , v036
	.byte	W06
	.byte		        En4 , v064
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte		        En4 , v028
	.byte	W06
	.byte		        En4 , v016
	.byte	W06
	.byte		        En4 , v020
	.byte	W06
	.byte		        En4 , v012
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		VOL   , 45*mus_demo1_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , Gn3 , v092
	.byte	W06
	.byte		        Gn3 , v036
	.byte	W06
	.byte		        Cn4 , v092
	.byte	W06
	.byte		        Cn4 , v036
	.byte	W06
	.byte		        Dn4 , v092
	.byte	W06
	.byte		        Dn4 , v036
	.byte	W06
	.byte		        En4 , v092
	.byte	W06
	.byte		        En4 , v036
	.byte	W06
	.byte		        Gn4 , v096
	.byte	W06
	.byte		        Gn4 , v036
	.byte	W06
	.byte		        An4 , v096
	.byte	W06
	.byte		        An4 , v036
	.byte	W06
	.byte		        Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v036
	.byte	W06
	.byte		        Dn5 , v104
	.byte	W06
	.byte		        Dn5 , v036
	.byte	W06
	.byte		VOL   , 45*mus_demo1_mvl/mxv
	.byte	W48
	.byte		PAN   , c_v-32
	.byte		N06   , Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v036
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v036
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v036
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v036
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v036
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v036
	.byte	W06
	.byte		        Bn3 , v112
	.byte	W06
	.byte		        Bn3 , v036
	.byte	W06
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v036
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Bn3 , v064
	.byte	W06
	.byte		        Bn3 , v036
	.byte	W06
	.byte		        Gn4 , v060
	.byte	W06
	.byte		        Gn4 , v036
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Bn3 , v032
	.byte	W06
	.byte		        Bn3 , v036
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W06
	.byte		        Gn4 , v036
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Bn3 , v016
	.byte	W06
	.byte		        Bn3 , v036
	.byte	W06
	.byte		        Gn4 , v016
	.byte	W06
	.byte		        Gn4 , v036
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Bn3 , v008
	.byte	W06
	.byte		        Bn3 , v036
	.byte	W06
	.byte		        Gn4 , v008
	.byte	W06
	.byte		        Gn4 , v036
	.byte	W18
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v036
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v036
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v036
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v036
	.byte	W06
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v036
	.byte	W18
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v036
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v036
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v036
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v036
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v036
	.byte	W06
	.byte		VOICE , 56
	.byte		VOL   , 90*mus_demo1_mvl/mxv
	.byte		PAN   , c_v-19
	.byte		N06   , Fn3 , v120
	.byte	W06
	.byte		        Fn3 , v036
	.byte	W06
	.byte		        Cn3 , v124
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N24   , An3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 87*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        77*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        70*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        63*mus_demo1_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_demo1_mvl/mxv
	.byte		N06   , An3 , v120
	.byte	W06
	.byte		        An3 , v036
	.byte	W06
	.byte		        Fn3 , v120
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 84*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        73*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        70*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        62*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        60*mus_demo1_mvl/mxv
	.byte	W01
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_demo1_mvl/mxv
	.byte		N12   , Bn3 , v124
	.byte	W12
	.byte		N03   , As3 , v096
	.byte	W03
	.byte		        Gs3 , v092
	.byte	W03
	.byte		        Gn3 , v080
	.byte	W03
	.byte		        Fn3 , v076
	.byte	W03
	.byte		N04   , Dn4 , v124
	.byte	W04
	.byte		        Dn4 , v036
	.byte	W04
	.byte		        Bn3 , v124
	.byte	W04
	.byte		        Bn3 , v036
	.byte	W04
	.byte		        Dn4 , v124
	.byte	W04
	.byte		        Dn4 , v036
	.byte	W04
	.byte		N36   , Gn4 , v120
	.byte	W09
	.byte		VOL   , 87*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        81*mus_demo1_mvl/mxv
	.byte		MOD   , 7
	.byte	W02
	.byte		VOL   , 73*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        62*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        53*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        46*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        35*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        30*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        25*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        73*mus_demo1_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Bn3 , v112
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		PAN   , c_v+20
	.byte		VOL   , 73*mus_demo1_mvl/mxv
	.byte	W36
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Cn4 , v036
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v036
	.byte	W06
	.byte		N24   , En4 , v112
	.byte	W24
	.byte		N03   , Ds4 , v092
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Cs4 , v084
	.byte	W03
	.byte		        Cn4 , v080
	.byte	W03
	.byte		VOICE , 45
	.byte	W12
	.byte		N06   , Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v036
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v036
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v036
	.byte	W06
	.byte		N03   , Gn4 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Dn4 , v036
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v036
	.byte	W06
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte	W36
	.byte		N06   , Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v036
	.byte	W06
	.byte		        An4 , v112
	.byte	W06
	.byte		        An4 , v036
	.byte	W06
	.byte		N24   , Bn4 , v112
	.byte	W24
	.byte	W03
	.byte		N03   , As4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		VOICE , 56
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Bn3 , v036
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v036
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		VOICE , 1
	.byte		PAN   , c_v-21
	.byte		N05   , Gn4 , v092
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		N03   , Bn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N06   , Dn5 
	.byte	W06
	.byte		PAN   , c_v+36
	.byte	W90
	.byte		N06   , En4 , v080
	.byte	W06
	.byte		PAN   , c_v+26
	.byte		VOL   , 62*mus_demo1_mvl/mxv
	.byte		N24   , Gn4 , v084
	.byte	W24
	.byte		        Fn4 , v088
	.byte	W24
	.byte		N16   , En4 
	.byte	W16
	.byte		        Dn4 
	.byte	W16
	.byte		        Cn4 
	.byte	W16
	.byte		VOICE , 46
	.byte		PAN   , c_v+21
	.byte	W96
	.byte		VOICE , 46
	.byte		VOL   , 79*mus_demo1_mvl/mxv
	.byte	W48
	.byte		N04   , Gn3 , v056
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Fn5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		        Dn6 
	.byte	W04
	.byte		        Fn6 
	.byte	W04
	.byte		        Bn6 
	.byte	W04
	.byte		        Gn6 
	.byte	W04
	.byte		        Fn6 
	.byte	W04
	.byte		        Dn6 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Gn6 
	.byte	W04
	.byte		        Fn6 
	.byte	W04
	.byte		        Dn6 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Fn6 
	.byte	W04
	.byte		        Dn6 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Dn6 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Fn5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Fn5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fn5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		N24   , Gn3 , v060
	.byte	W24
	.byte	W96
	.byte	FINE

@********************** Track  5 **********************@

mus_demo1_5:
	.byte	KEYSH , mus_demo1_key+0
	.byte		VOICE , 1
	.byte		PAN   , c_v-47
	.byte		LFOS  , 44
	.byte		VOL   , 37*mus_demo1_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , En4 , v068
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N03   , Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N03   , Gn4 , v060
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N02   , Cn4 , v064
	.byte	W06
	.byte		        Cn4 , v036
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N03   , Dn4 , v060
	.byte	W06
	.byte		        Dn4 , v036
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , En4 , v064
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte		VOL   , 43*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        42*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        39*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        37*mus_demo1_mvl/mxv
	.byte	W06
	.byte		        36*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        33*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        31*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        30*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        28*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        26*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        26*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        25*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        22*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        21*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        20*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        19*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        19*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        17*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        16*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        15*mus_demo1_mvl/mxv
	.byte	W05
	.byte		        14*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        13*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        11*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        10*mus_demo1_mvl/mxv
	.byte	W06
	.byte		        9*mus_demo1_mvl/mxv
	.byte	W06
	.byte		        7*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        5*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        4*mus_demo1_mvl/mxv
	.byte	W06
	.byte		        3*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        2*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        2*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        1*mus_demo1_mvl/mxv
	.byte	W12
	.byte		        45*mus_demo1_mvl/mxv
	.byte	W96
	.byte		        34*mus_demo1_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W24
	.byte		PAN   , c_v+47
	.byte		N12   , Dn5 , v080
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N12   , Dn5 , v048
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N12   , Dn5 , v036
	.byte	W12
	.byte		        Gn5 , v032
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N12   , Dn5 , v024
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N12   , Dn5 , v012
	.byte	W12
	.byte		        Gn5 , v008
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	W48
	.byte	W96
	.byte	W96
	.byte		VOICE , 47
	.byte		VOL   , 88*mus_demo1_mvl/mxv
	.byte		N03   , Gn2 , v124
	.byte	W06
	.byte		        Gn2 , v112
	.byte	W06
	.byte		N12   , Gn1 , v124
	.byte	W12
	.byte		N04   , Gn2 
	.byte	W08
	.byte		        Dn2 , v112
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		N12   , Gn1 
	.byte	W12
	.byte		        Gn1 , v036
	.byte	W24
	.byte		N03   , Gn2 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , Cn2 , v124
	.byte	W60
	.byte		N12   , Gn1 , v112
	.byte	W12
	.byte		        Gn1 , v036
	.byte	W12
	.byte		        Gn2 , v112
	.byte	W12
	.byte		N24   , Cn2 , v124
	.byte	W36
	.byte		N03   , Gn2 , v120
	.byte	W06
	.byte		N06   , Gn2 , v112
	.byte	W06
	.byte		N12   , Cn3 , v124
	.byte	W12
	.byte		        Cn3 , v036
	.byte	W12
	.byte		        Gn2 , v112
	.byte	W12
	.byte		        Gn2 , v036
	.byte	W12
	.byte		N24   , Gn1 , v124
	.byte	W60
	.byte		N12   , Gn1 , v112
	.byte	W12
	.byte		        Gn1 , v036
	.byte	W12
	.byte		        Dn2 , v112
	.byte	W12
	.byte		N24   , Gn1 , v124
	.byte	W36
	.byte		N03   , Gn2 , v120
	.byte	W06
	.byte		        Gn2 , v112
	.byte	W06
	.byte		N12   , Gn2 , v124
	.byte	W12
	.byte		        Gn2 , v036
	.byte	W12
	.byte		        Gn1 , v112
	.byte	W12
	.byte		        Gn1 , v036
	.byte	W12
	.byte		N24   , An1 , v124
	.byte	W60
	.byte		N12   , En1 , v112
	.byte	W12
	.byte		        En1 , v036
	.byte	W12
	.byte		        En2 , v112
	.byte	W12
	.byte		N24   , An1 , v124
	.byte	W36
	.byte		N03   , En2 , v116
	.byte	W06
	.byte		        En2 , v112
	.byte	W06
	.byte		N12   , An2 , v124
	.byte	W12
	.byte		        An2 , v036
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v036
	.byte	W12
	.byte	W96
	.byte		VOICE , 46
	.byte		VOL   , 62*mus_demo1_mvl/mxv
	.byte	W48
	.byte		PAN   , c_v-32
	.byte		BEND  , c_v-2
	.byte	W48
	.byte	W96
	.byte		PAN   , c_v-46
	.byte		VOL   , 45*mus_demo1_mvl/mxv
	.byte	W04
	.byte		N04   , Bn5 , v032
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Fn5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Fn5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fn5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Bn3 , v028
	.byte	W04
	.byte		        Gn3 , v032
	.byte	W20
	.byte	W96
	.byte	FINE

@********************** Track  6 **********************@

mus_demo1_6:
	.byte	KEYSH , mus_demo1_key+0
	.byte		VOICE , 45
	.byte		VOL   , 54*mus_demo1_mvl/mxv
	.byte		LFOS  , 44
	.byte		PAN   , c_v+32
	.byte	W03
	.byte		VOL   , 56*mus_demo1_mvl/mxv
	.byte	W92
	.byte	W01
	.byte		PAN   , c_v+32
	.byte	W48
	.byte		N06   , En4 , v088
	.byte	W06
	.byte		        En4 , v036
	.byte	W06
	.byte		        Fn4 , v092
	.byte	W06
	.byte		        Fn4 , v036
	.byte	W06
	.byte		        Gn4 , v092
	.byte	W06
	.byte		        Gn4 , v036
	.byte	W06
	.byte		        An4 , v104
	.byte	W06
	.byte		        An4 , v036
	.byte	W06
	.byte		PAN   , c_v-51
	.byte	W96
	.byte		VOICE , 48
	.byte		VOL   , 4*mus_demo1_mvl/mxv
	.byte		N96   , Dn5 , v064
	.byte	W15
	.byte		PAN   , c_v-43
	.byte	W02
	.byte		VOL   , 5*mus_demo1_mvl/mxv
	.byte		PAN   , c_v-38
	.byte	W03
	.byte		VOL   , 7*mus_demo1_mvl/mxv
	.byte		PAN   , c_v-34
	.byte	W04
	.byte		VOL   , 9*mus_demo1_mvl/mxv
	.byte		PAN   , c_v-26
	.byte	W02
	.byte		VOL   , 14*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        15*mus_demo1_mvl/mxv
	.byte		PAN   , c_v-22
	.byte	W03
	.byte		VOL   , 19*mus_demo1_mvl/mxv
	.byte		PAN   , c_v-19
	.byte	W04
	.byte		VOL   , 21*mus_demo1_mvl/mxv
	.byte		PAN   , c_v-13
	.byte	W02
	.byte		VOL   , 25*mus_demo1_mvl/mxv
	.byte		PAN   , c_v-7
	.byte	W03
	.byte		VOL   , 29*mus_demo1_mvl/mxv
	.byte		PAN   , c_v-2
	.byte	W03
	.byte		VOL   , 32*mus_demo1_mvl/mxv
	.byte		PAN   , c_v+5
	.byte	W04
	.byte		        c_v+12
	.byte	W02
	.byte		VOL   , 36*mus_demo1_mvl/mxv
	.byte		PAN   , c_v+19
	.byte	W03
	.byte		VOL   , 38*mus_demo1_mvl/mxv
	.byte		PAN   , c_v+24
	.byte	W03
	.byte		VOL   , 42*mus_demo1_mvl/mxv
	.byte		PAN   , c_v+29
	.byte	W04
	.byte		        c_v+35
	.byte	W02
	.byte		VOL   , 32*mus_demo1_mvl/mxv
	.byte		PAN   , c_v+38
	.byte	W03
	.byte		VOL   , 24*mus_demo1_mvl/mxv
	.byte		PAN   , c_v+41
	.byte	W03
	.byte		        c_v+45
	.byte	W04
	.byte		        c_v+47
	.byte	W02
	.byte		VOL   , 21*mus_demo1_mvl/mxv
	.byte		PAN   , c_v+51
	.byte	W03
	.byte		VOL   , 17*mus_demo1_mvl/mxv
	.byte		PAN   , c_v+53
	.byte	W03
	.byte		VOL   , 12*mus_demo1_mvl/mxv
	.byte		PAN   , c_v+56
	.byte	W04
	.byte		VOL   , 11*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        9*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        7*mus_demo1_mvl/mxv
	.byte	W07
	.byte		PAN   , c_v+28
	.byte		VOL   , 34*mus_demo1_mvl/mxv
	.byte		N06   , An4 , v032
	.byte	W06
	.byte		        Cn4 , v036
	.byte	W06
	.byte		        An4 , v040
	.byte	W06
	.byte		        Bn4 , v044
	.byte	W06
	.byte		        An4 , v048
	.byte	W06
	.byte		        Cn4 , v052
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 , v056
	.byte	W06
	.byte		        An4 , v060
	.byte	W06
	.byte		        Cn4 , v064
	.byte	W06
	.byte		        An4 , v068
	.byte	W06
	.byte		        Bn4 , v072
	.byte	W06
	.byte		        An4 , v076
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An4 , v080
	.byte	W06
	.byte		        Bn4 , v084
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn4 , v088
	.byte	W06
	.byte		        Bn4 , v092
	.byte	W06
	.byte		        Cn5 , v096
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Dn4 , v100
	.byte	W06
	.byte		        Bn4 , v104
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Bn4 , v108
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		PAN   , c_v+25
	.byte		VOL   , 39*mus_demo1_mvl/mxv
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N36   , Bn4 
	.byte	W15
	.byte		VOL   , 36*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        32*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        27*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        24*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        19*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        17*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        14*mus_demo1_mvl/mxv
	.byte	W01
	.byte		        14*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        11*mus_demo1_mvl/mxv
	.byte	W05
	.byte		        10*mus_demo1_mvl/mxv
	.byte	W07
	.byte		VOICE , 56
	.byte		PAN   , c_v+30
	.byte		VOL   , 39*mus_demo1_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W92
	.byte	W03
	.byte		VOICE , 48
	.byte	W01
	.byte		PAN   , c_v-2
	.byte		VOL   , 56*mus_demo1_mvl/mxv
	.byte		N48   , Dn5 
	.byte	W48
	.byte		        En5 
	.byte	W48
	.byte		BEND  , c_v+4
	.byte		N48   , Fn5 
	.byte	W48
	.byte		TIE   , Gn5 
	.byte	W48
	.byte		VOL   , 53*mus_demo1_mvl/mxv
	.byte	W05
	.byte		        50*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        48*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        45*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        43*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        42*mus_demo1_mvl/mxv
	.byte	W07
	.byte		        38*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        37*mus_demo1_mvl/mxv
	.byte	W06
	.byte		        32*mus_demo1_mvl/mxv
	.byte	W06
	.byte		        31*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        27*mus_demo1_mvl/mxv
	.byte	W07
	.byte		        26*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        22*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        21*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        19*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        16*mus_demo1_mvl/mxv
	.byte	W05
	.byte		        14*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        11*mus_demo1_mvl/mxv
	.byte	W06
	.byte		        9*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        8*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        7*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        4*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        3*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        2*mus_demo1_mvl/mxv
	.byte	W07
	.byte		EOT   
	.byte	W96
	.byte	W96
	.byte	FINE

@********************** Track  7 **********************@

mus_demo1_7:
	.byte	KEYSH , mus_demo1_key+0
	.byte		VOICE , 84
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 22*mus_demo1_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W72
	.byte		VOL   , 34*mus_demo1_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W24
	.byte		VOICE , 85
	.byte		PAN   , c_v-63
	.byte		BEND  , c_v+1
	.byte	W24
	.byte		MOD   , 8
	.byte	W21
	.byte		        0
	.byte	W03
	.byte		N06   , Cn2 , v084
	.byte	W06
	.byte		        Cn2 , v036
	.byte	W06
	.byte		MOD   , 8
	.byte		N06   , Bn1 , v084
	.byte	W06
	.byte		        Bn1 , v036
	.byte	W06
	.byte		MOD   , 0
	.byte		N06   , An1 , v084
	.byte	W06
	.byte		        An1 , v036
	.byte	W06
	.byte		        Gn1 , v084
	.byte	W03
	.byte		MOD   , 8
	.byte	W03
	.byte		N06   , Gn1 , v036
	.byte	W06
	.byte		MOD   , 0
	.byte		N12   , Fn1 , v092
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W06
	.byte		        Cn2 , v036
	.byte	W06
	.byte		        Gn2 , v092
	.byte	W06
	.byte		        Gn2 , v036
	.byte	W06
	.byte		N36   , An2 , v096
	.byte	W12
	.byte		MOD   , 8
	.byte		VOL   , 33*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        30*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        27*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        26*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        24*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        22*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        21*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        19*mus_demo1_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 34*mus_demo1_mvl/mxv
	.byte		N09   , Gn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Dn2 , v036
	.byte	W06
	.byte		        An2 , v096
	.byte	W06
	.byte		        An2 , v036
	.byte	W06
	.byte		N36   , Bn2 , v096
	.byte	W12
	.byte		MOD   , 8
	.byte		VOL   , 34*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        31*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        30*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        29*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        27*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        26*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        24*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        23*mus_demo1_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 34*mus_demo1_mvl/mxv
	.byte		N09   , Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		BEND  , c_v+1
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W06
	.byte		        Cn2 , v036
	.byte	W06
	.byte		        Gn2 , v096
	.byte	W06
	.byte		        Gn2 , v036
	.byte	W06
	.byte		N60   , An2 , v100
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		VOL   , 32*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        29*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        26*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        26*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        24*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        21*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        18*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        16*mus_demo1_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 34*mus_demo1_mvl/mxv
	.byte		N12   , Fn1 , v096
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Dn2 , v036
	.byte	W06
	.byte		        An2 , v104
	.byte	W06
	.byte		        An2 , v036
	.byte	W06
	.byte		N36   , Bn2 , v104
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		VOL   , 33*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        28*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        23*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        19*mus_demo1_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 34*mus_demo1_mvl/mxv
	.byte		N12   , An2 , v100
	.byte	W12
	.byte		        Gn2 , v096
	.byte	W12
	.byte		VOICE , 81
	.byte		PAN   , c_v-64
	.byte		VOL   , 34*mus_demo1_mvl/mxv
	.byte		N06   , Fn1 , v112
	.byte	W12
	.byte		N12   , En1 
	.byte	W18
	.byte		MOD   , 8
	.byte	W06
	.byte		N06   , Fn1 
	.byte	W06
	.byte		MOD   , 0
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   , Cn2 
	.byte	W24
	.byte		MOD   , 8
	.byte		N12   , Fs1 
	.byte	W12
	.byte		MOD   , 0
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N06   , Fs1 
	.byte	W12
	.byte		N04   , Gn1 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		VOICE , 80
	.byte		N36   , Gn1 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 33*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        32*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        30*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        28*mus_demo1_mvl/mxv
	.byte	W04
	.byte		MOD   , 9
	.byte		VOL   , 24*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        21*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        17*mus_demo1_mvl/mxv
	.byte	W07
	.byte		        40*mus_demo1_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Fn2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		VOL   , 38*mus_demo1_mvl/mxv
	.byte		MOD   , 0
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N60   , En4 
	.byte	W24
	.byte		MOD   , 4
	.byte		VOL   , 37*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        34*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        33*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        29*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        28*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        22*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        19*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        17*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        15*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        12*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        11*mus_demo1_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte		VOL   , 39*mus_demo1_mvl/mxv
	.byte		N06   , Fn4 , v084
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Dn4 , v080
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		BEND  , c_v+1
	.byte		N04   , Gn3 , v032
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Fn5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		        Dn6 
	.byte	W04
	.byte		        Fn6 
	.byte	W04
	.byte		VOL   , 24*mus_demo1_mvl/mxv
	.byte		N04   , Bn6 
	.byte	W04
	.byte		        Gn6 
	.byte	W04
	.byte		        Fn6 
	.byte	W04
	.byte		        Dn6 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Gn6 
	.byte	W04
	.byte		        Fn6 
	.byte	W04
	.byte		        Dn6 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Fn6 
	.byte	W04
	.byte		        Dn6 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Dn6 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Fn5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Fn5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fn5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		N03   , Gn3 
	.byte	W24
	.byte	W96
	.byte	FINE

@********************** Track  8 **********************@

mus_demo1_8:
	.byte	KEYSH , mus_demo1_key+0
	.byte		VOICE , 83
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 22*mus_demo1_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte		VOICE , 86
	.byte		VOL   , 34*mus_demo1_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		N06   , Dn3 , v048
	.byte	W12
	.byte		N03   , Gs3 , v052
	.byte	W03
	.byte		N30   , Gn3 , v048
	.byte	W09
	.byte		MOD   , 8
	.byte	W21
	.byte		        0
	.byte		N03   , Fs3 , v072
	.byte	W03
	.byte		N24   , Fn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , En3 
	.byte	W15
	.byte		MOD   , 8
	.byte	W09
	.byte		        0
	.byte		N21   , Fn3 
	.byte	W21
	.byte		N03   , Fs3 
	.byte	W03
	.byte		N21   , Gn3 
	.byte	W21
	.byte		N03   , Gs3 
	.byte	W03
	.byte		N18   , An3 
	.byte	W18
	.byte		N03   , Dn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		N18   , En4 
	.byte	W18
	.byte		N03   , Dn4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		VOL   , 32*mus_demo1_mvl/mxv
	.byte		N42   , Bn3 
	.byte	W05
	.byte		VOL   , 26*mus_demo1_mvl/mxv
	.byte	W01
	.byte		        29*mus_demo1_mvl/mxv
	.byte	W03
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 26*mus_demo1_mvl/mxv
	.byte	W05
	.byte		        22*mus_demo1_mvl/mxv
	.byte	W01
	.byte		        24*mus_demo1_mvl/mxv
	.byte	W06
	.byte		MOD   , 8
	.byte		VOL   , 21*mus_demo1_mvl/mxv
	.byte	W05
	.byte		        19*mus_demo1_mvl/mxv
	.byte	W07
	.byte		        18*mus_demo1_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 34*mus_demo1_mvl/mxv
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		VOL   , 34*mus_demo1_mvl/mxv
	.byte		N03   , Bn3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		VOICE , 86
	.byte		N06   , Fn4 , v076
	.byte	W06
	.byte		        An3 , v036
	.byte	W06
	.byte		        Fn4 , v040
	.byte	W06
	.byte		        Gn4 , v044
	.byte	W06
	.byte		        Fn4 , v048
	.byte	W06
	.byte		        An3 , v052
	.byte	W06
	.byte		        Fn4 , v056
	.byte	W06
	.byte		        Gn4 , v060
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        An3 , v068
	.byte	W06
	.byte		        Fn4 , v072
	.byte	W06
	.byte		        Gn4 , v076
	.byte	W06
	.byte		        Fn4 , v080
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fn4 , v084
	.byte	W06
	.byte		        Gn4 , v088
	.byte	W06
	.byte		        Dn4 , v092
	.byte	W06
	.byte		        Fn3 , v096
	.byte	W06
	.byte		        Dn4 , v100
	.byte	W06
	.byte		        Fn4 , v104
	.byte	W06
	.byte		        Dn4 , v100
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 , v096
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn3 , v092
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fn4 , v096
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		VOL   , 34*mus_demo1_mvl/mxv
	.byte		N03   , Fn4 
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		VOICE , 80
	.byte		N36   , Gn5 , v032
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        24*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        22*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        19*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        17*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        11*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        10*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        9*mus_demo1_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		N03   , Fn5 
	.byte	W03
	.byte		VOL   , 34*mus_demo1_mvl/mxv
	.byte		N03   , Dn5 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		VOL   , 33*mus_demo1_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Cn4 , v096
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W36
	.byte		N06   , Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N08   , An3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N60   , Cn5 
	.byte	W24
	.byte		VOL   , 34*mus_demo1_mvl/mxv
	.byte		MOD   , 5
	.byte	W02
	.byte		VOL   , 31*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        29*mus_demo1_mvl/mxv
	.byte	W07
	.byte		        25*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        24*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        22*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        19*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        17*mus_demo1_mvl/mxv
	.byte	W02
	.byte		        14*mus_demo1_mvl/mxv
	.byte	W03
	.byte		        10*mus_demo1_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte		VOL   , 34*mus_demo1_mvl/mxv
	.byte		N06   , Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N24   , En5 , v084
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		N16   , Cn5 
	.byte	W16
	.byte		        Bn4 
	.byte	W16
	.byte		        An4 
	.byte	W16
	.byte		N48   , Bn4 , v096
	.byte	W24
	.byte		VOL   , 29*mus_demo1_mvl/mxv
	.byte		MOD   , 5
	.byte	W04
	.byte		VOL   , 25*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        22*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        18*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        15*mus_demo1_mvl/mxv
	.byte	W08
	.byte		        34*mus_demo1_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , Cn5 
	.byte	W24
	.byte		VOL   , 31*mus_demo1_mvl/mxv
	.byte		MOD   , 5
	.byte	W04
	.byte		VOL   , 28*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        25*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        22*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        19*mus_demo1_mvl/mxv
	.byte	W08
	.byte		        34*mus_demo1_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , Dn5 
	.byte	W24
	.byte		VOL   , 29*mus_demo1_mvl/mxv
	.byte		MOD   , 5
	.byte	W04
	.byte		VOL   , 26*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        22*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        19*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        17*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        15*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        34*mus_demo1_mvl/mxv
	.byte		MOD   , 0
	.byte		TIE   , Fn5 , v064
	.byte	W24
	.byte		VOL   , 32*mus_demo1_mvl/mxv
	.byte		MOD   , 8
	.byte	W04
	.byte		VOL   , 31*mus_demo1_mvl/mxv
	.byte	W08
	.byte		        28*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        26*mus_demo1_mvl/mxv
	.byte	W08
	.byte		        25*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        24*mus_demo1_mvl/mxv
	.byte	W08
	.byte		        22*mus_demo1_mvl/mxv
	.byte	W08
	.byte		        21*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        19*mus_demo1_mvl/mxv
	.byte	W08
	.byte		        18*mus_demo1_mvl/mxv
	.byte	W08
	.byte		        17*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        15*mus_demo1_mvl/mxv
	.byte	W08
	.byte		        14*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        12*mus_demo1_mvl/mxv
	.byte	W08
	.byte		        11*mus_demo1_mvl/mxv
	.byte	W04
	.byte		        9*mus_demo1_mvl/mxv
	.byte	W04
	.byte		EOT   
	.byte		MOD   , 0
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	FINE

@********************** Track  9 **********************@

mus_demo1_9:
	.byte	KEYSH , mus_demo1_key+0
	.byte		VOICE , 0
	.byte		VOL   , 51*mus_demo1_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		N06   , Fs2 , v112
	.byte	W06
	.byte		        Fs2 , v028
	.byte	W06
	.byte		        Fs2 , v040
	.byte	W06
	.byte		        Fs2 , v016
	.byte	W06
	.byte		        Fs2 , v028
	.byte	W12
	.byte		        Fs2 , v020
	.byte	W12
	.byte		        Fs2 , v012
	.byte	W12
	.byte		        Fs2 , v008
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		N36   , An2 , v112
	.byte	W48
	.byte		        An2 , v108
	.byte	W96
	.byte	W96
	.byte		N48   , An2 , v112
	.byte	W96
	.byte	W96
	.byte		N48   
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N06   , En1 
	.byte	W12
	.byte		N04   , En1 , v072
	.byte	W04
	.byte		        En1 , v060
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N06   , En1 , v080
	.byte	W12
	.byte		N04   , En1 , v072
	.byte	W04
	.byte		        En1 , v060
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N06   , En1 , v092
	.byte	W12
	.byte		N04   , En1 , v072
	.byte	W04
	.byte		        En1 , v060
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N06   , En1 , v092
	.byte	W12
	.byte		N04   , En1 , v072
	.byte	W04
	.byte		        En1 , v052
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N06   , En1 , v096
	.byte	W96
	.byte	FINE

@********************** Track 10 **********************@

mus_demo1_10:
	.byte	KEYSH , mus_demo1_key+0
	.byte		VOICE , 73
	.byte		PAN   , c_v+0
	.byte		LFOS  , 16
	.byte		XCMD  , xIECV , 6
	.byte		        xIECV , 4
	.byte		BENDR , 12
	.byte		VOL   , 22*mus_demo1_mvl/mxv
	.byte		N06   , En5 , v020
	.byte	W12
	.byte		        Fn5 , v024
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        En5 
	.byte	W36
	.byte		        Cn4 , v064
	.byte	W12
	.byte		N03   , Ds4 
	.byte	W03
	.byte		N80   , Dn4 
	.byte	W32
	.byte	W01
	.byte		MOD   , 4
	.byte	W24
	.byte		        8
	.byte	W24
	.byte		        0
	.byte		VOL   , 22*mus_demo1_mvl/mxv
	.byte		N03   , Gs3 
	.byte	W03
	.byte		N21   , An3 
	.byte	W21
	.byte		N24   , Bn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		N03   , Gs4 
	.byte	W03
	.byte		N44   , Gn4 
	.byte	W21
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        14
	.byte	W24
	.byte		        0
	.byte		VOL   , 28*mus_demo1_mvl/mxv
	.byte	W24
	.byte		BEND  , c_v+0
	.byte	W24
	.byte		MOD   , 8
	.byte	W24
	.byte		N48   , An3 , v052
	.byte	W24
	.byte		MOD   , 14
	.byte	W24
	.byte		        0
	.byte		N06   , Fn3 
	.byte	W12
	.byte		N03   , Cn4 
	.byte	W03
	.byte		N56   , Bn3 
	.byte	W09
	.byte		MOD   , 6
	.byte	W24
	.byte		        14
	.byte	W24
	.byte		        0
	.byte		N06   , An4 , v064
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		VOL   , 31*mus_demo1_mvl/mxv
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        2
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        2
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 11
	.byte	W12
	.byte		        0
	.byte		N24   , Bn4 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N03   , As4 , v040
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		N04   , Dn5 , v060
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Dn5 , v056
	.byte	W08
	.byte		VOL   , 34*mus_demo1_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W12
	.byte		VOL   , 34*mus_demo1_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		MOD   , 6
	.byte	W36
	.byte		        0
	.byte	W36
	.byte	W96
	.byte	W24
	.byte		        6
	.byte	W24
	.byte		        0
	.byte	W24
	.byte		        6
	.byte	W24
	.byte		        0
	.byte	W24
	.byte		        6
	.byte	W24
	.byte		        0
	.byte	W24
	.byte		        6
	.byte	W24
	.byte	W72
	.byte		        0
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	FINE

@******************************************************@
	.align	2

mus_demo1:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_demo1_pri	@ Priority
	.byte	mus_demo1_rev	@ Reverb.

	.word	mus_demo1_grp

	.word	mus_demo1_1
	.word	mus_demo1_2
	.word	mus_demo1_3
	.word	mus_demo1_4
	.word	mus_demo1_5
	.word	mus_demo1_6
	.word	mus_demo1_7
	.word	mus_demo1_8
	.word	mus_demo1_9
	.word	mus_demo1_10

	.end
