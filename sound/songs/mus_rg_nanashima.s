	.include "MPlayDef.s"

	.equ	mus_rg_nanashima_grp, voicegroup187
	.equ	mus_rg_nanashima_pri, 0
	.equ	mus_rg_nanashima_rev, reverb_set+50
	.equ	mus_rg_nanashima_mvl, 127
	.equ	mus_rg_nanashima_key, 0
	.equ	mus_rg_nanashima_tbs, 1
	.equ	mus_rg_nanashima_exg, 0
	.equ	mus_rg_nanashima_cmp, 1

	.section .rodata
	.global	mus_rg_nanashima
	.align	2

@********************** Track  1 **********************@

mus_rg_nanashima_1:
	.byte	KEYSH , mus_rg_nanashima_key+0
	.byte	TEMPO , 124*mus_rg_nanashima_tbs/2
	.byte		VOICE , 60
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-28
	.byte		VOL   , 76*mus_rg_nanashima_mvl/mxv
	.byte	W24
	.byte		N23   , Gn3 , v064
	.byte	W12
	.byte		VOL   , 70*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        62*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        50*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        40*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        30*mus_rg_nanashima_mvl/mxv
	.byte	W12
	.byte		        76*mus_rg_nanashima_mvl/mxv
	.byte		N23   
	.byte	W12
	.byte		VOL   , 70*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        62*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        50*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        40*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        30*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        20*mus_rg_nanashima_mvl/mxv
	.byte	W32
	.byte	W01
	.byte		        76*mus_rg_nanashima_mvl/mxv
	.byte		N23   
	.byte	W12
	.byte		VOL   , 70*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        62*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        50*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        40*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        30*mus_rg_nanashima_mvl/mxv
	.byte	W12
	.byte		        76*mus_rg_nanashima_mvl/mxv
	.byte		N23   
	.byte	W12
	.byte		VOL   , 70*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        62*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        50*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        40*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        30*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        20*mus_rg_nanashima_mvl/mxv
	.byte	W09
	.byte		        54*mus_rg_nanashima_mvl/mxv
	.byte		N23   , An3 
	.byte	W06
	.byte		VOL   , 57*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        63*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        66*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        74*mus_rg_nanashima_mvl/mxv
	.byte	W09
mus_rg_nanashima_1_B1:
	.byte		VOL   , 73*mus_rg_nanashima_mvl/mxv
	.byte		N32   , Bn3 , v064
	.byte	W36
	.byte		        An3 
	.byte	W36
	.byte		N23   , Gn3 
	.byte	W24
mus_rg_nanashima_1_000:
	.byte		N32   , Gn4 , v064
	.byte	W36
	.byte		N23   , Fn4 
	.byte	W24
	.byte		N11   , An4 
	.byte	W12
	.byte		N23   , Gn4 
	.byte	W24
	.byte	PEND
mus_rg_nanashima_1_001:
	.byte		N32   , En4 , v064
	.byte	W36
	.byte		N11   , Cn4 
	.byte	W12
	.byte		N15   , Gn3 
	.byte	W16
	.byte		        Cn4 
	.byte	W16
	.byte		        En4 
	.byte	W16
	.byte	PEND
	.byte		N17   , Gn3 
	.byte	W18
	.byte		N05   , Bn3 
	.byte	W06
	.byte		N44   , Dn4 
	.byte	W48
	.byte		N23   , Bn3 
	.byte	W24
	.byte		N32   
	.byte	W36
	.byte		        An3 
	.byte	W36
	.byte		N23   , Gn3 
	.byte	W24
	.byte	PATT
	 .word	mus_rg_nanashima_1_000
	.byte	PATT
	 .word	mus_rg_nanashima_1_001
	.byte		N17   , Gn3 , v064
	.byte	W18
	.byte		N05   , Bn3 
	.byte	W06
	.byte		N44   , Dn4 
	.byte	W24
	.byte		VOL   , 68*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        64*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        59*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        55*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        73*mus_rg_nanashima_mvl/mxv
	.byte		N23   , Bn3 
	.byte	W24
	.byte		N17   , Dn4 
	.byte	W18
	.byte		N05   , Fs4 
	.byte	W06
	.byte		N68   , Gn4 
	.byte	W24
	.byte		VOL   , 68*mus_rg_nanashima_mvl/mxv
	.byte	W24
	.byte		        59*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        53*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        46*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        40*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        73*mus_rg_nanashima_mvl/mxv
	.byte		N15   , Fn3 
	.byte	W16
	.byte		        En3 
	.byte	W16
	.byte		        Dn3 
	.byte	W16
	.byte		N44   , Cn3 
	.byte	W15
	.byte		VOL   , 64*mus_rg_nanashima_mvl/mxv
	.byte	W09
	.byte		        59*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        55*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        73*mus_rg_nanashima_mvl/mxv
	.byte		N68   , Fn3 
	.byte	W72
	.byte		N23   , An3 
	.byte	W24
	.byte		N11   , Gn3 
	.byte	W12
	.byte		N44   , Dn3 
	.byte	W60
	.byte		N23   , An3 
	.byte	W24
	.byte		N17   , Gn3 
	.byte	W18
	.byte		N05   , An3 
	.byte	W06
	.byte		N44   , Bn3 
	.byte	W48
	.byte		N23   , Gn3 
	.byte	W24
	.byte	W12
	.byte		N05   , Fn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N44   , Fn3 
	.byte	W48
	.byte		N23   , An3 
	.byte	W24
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N44   , An3 
	.byte	W48
	.byte		N23   , Cn4 
	.byte	W24
	.byte	W12
	.byte		N05   , Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N68   , Dn4 
	.byte	W24
	.byte		VOL   , 69*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        65*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        60*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        55*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        51*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        47*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        43*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        37*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        73*mus_rg_nanashima_mvl/mxv
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N68   , Gn4 
	.byte	W24
	.byte		VOL   , 66*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        60*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        54*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        47*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        42*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        36*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        28*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        22*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_nanashima_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_nanashima_2:
	.byte	KEYSH , mus_rg_nanashima_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 78*mus_rg_nanashima_mvl/mxv
	.byte		PAN   , c_v-7
	.byte	W24
	.byte		VOL   , 80*mus_rg_nanashima_mvl/mxv
	.byte		N92   , Cn4 , v088
	.byte	W24
	.byte		VOL   , 74*mus_rg_nanashima_mvl/mxv
	.byte	W05
	.byte		        71*mus_rg_nanashima_mvl/mxv
	.byte	W07
	.byte		        69*mus_rg_nanashima_mvl/mxv
	.byte	W05
	.byte		        65*mus_rg_nanashima_mvl/mxv
	.byte	W07
	.byte		        61*mus_rg_nanashima_mvl/mxv
	.byte	W05
	.byte		        57*mus_rg_nanashima_mvl/mxv
	.byte	W07
	.byte		        54*mus_rg_nanashima_mvl/mxv
	.byte	W05
	.byte		        51*mus_rg_nanashima_mvl/mxv
	.byte	W07
	.byte		        47*mus_rg_nanashima_mvl/mxv
	.byte	W05
	.byte		        43*mus_rg_nanashima_mvl/mxv
	.byte	W07
	.byte		        39*mus_rg_nanashima_mvl/mxv
	.byte	W05
	.byte		        35*mus_rg_nanashima_mvl/mxv
	.byte	W07
	.byte		        80*mus_rg_nanashima_mvl/mxv
	.byte		N92   , Dn4 
	.byte	W24
	.byte		VOL   , 74*mus_rg_nanashima_mvl/mxv
	.byte	W05
	.byte		        71*mus_rg_nanashima_mvl/mxv
	.byte	W07
	.byte		        69*mus_rg_nanashima_mvl/mxv
	.byte	W05
	.byte		        65*mus_rg_nanashima_mvl/mxv
	.byte	W07
	.byte		        61*mus_rg_nanashima_mvl/mxv
	.byte	W05
	.byte		        57*mus_rg_nanashima_mvl/mxv
	.byte	W07
	.byte		        54*mus_rg_nanashima_mvl/mxv
	.byte	W05
	.byte		        51*mus_rg_nanashima_mvl/mxv
	.byte	W07
	.byte		        47*mus_rg_nanashima_mvl/mxv
	.byte	W05
	.byte		        43*mus_rg_nanashima_mvl/mxv
	.byte	W07
	.byte		        39*mus_rg_nanashima_mvl/mxv
	.byte	W05
	.byte		        35*mus_rg_nanashima_mvl/mxv
	.byte	W07
mus_rg_nanashima_2_B1:
	.byte		PAN   , c_v-7
	.byte		VOL   , 62*mus_rg_nanashima_mvl/mxv
	.byte		N60   , Gn4 , v088
	.byte	W64
	.byte		N15   , Dn4 
	.byte	W16
	.byte		        Gn4 
	.byte	W16
mus_rg_nanashima_2_000:
	.byte		N60   , Dn5 , v088
	.byte	W64
	.byte		N15   , Fn5 
	.byte	W16
	.byte		        En5 
	.byte	W16
	.byte	PEND
mus_rg_nanashima_2_001:
	.byte		N68   , Cn5 , v088
	.byte	W72
	.byte		N23   , En5 
	.byte	W24
	.byte	PEND
	.byte		N17   , Dn5 
	.byte	W18
	.byte		N05   , Cn5 
	.byte	W06
	.byte		N44   , Bn4 
	.byte	W48
	.byte		N06   
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N48   , Bn4 
	.byte	W48
	.byte		N18   , Gn4 
	.byte	W16
	.byte		N15   , Dn4 
	.byte	W16
	.byte		        Gn4 
	.byte	W16
	.byte	PATT
	 .word	mus_rg_nanashima_2_000
	.byte	PATT
	 .word	mus_rg_nanashima_2_001
	.byte		N17   , Dn5 , v088
	.byte	W18
	.byte		N05   , Cn5 
	.byte	W06
	.byte		N68   , Bn4 
	.byte	W72
	.byte		N92   
	.byte	W96
	.byte		VOICE , 1
	.byte		VOL   , 74*mus_rg_nanashima_mvl/mxv
	.byte		N15   , Cn4 , v127
	.byte	W16
	.byte		        Bn3 
	.byte	W16
	.byte		        An3 , v124
	.byte	W16
	.byte		N44   , Fn3 
	.byte	W48
	.byte		VOICE , 56
	.byte		VOL   , 74*mus_rg_nanashima_mvl/mxv
	.byte		PAN   , c_v+22
	.byte	W12
	.byte		N05   , Fn4 , v088
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Cn5 
	.byte	W12
	.byte		        An4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N44   , Fn5 
	.byte	W12
	.byte		VOL   , 70*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        64*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        51*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        44*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        40*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		VOICE , 48
	.byte		VOL   , 62*mus_rg_nanashima_mvl/mxv
	.byte		PAN   , c_v-6
	.byte	W12
	.byte		N23   , Dn5 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		N11   , An4 
	.byte	W12
	.byte		N15   , Gn4 
	.byte	W16
	.byte		        An4 
	.byte	W16
	.byte		        Bn4 
	.byte	W16
	.byte		N44   , Dn5 
	.byte	W48
	.byte		VOICE , 1
	.byte		N15   , Cn4 , v127
	.byte	W16
	.byte		        Bn3 
	.byte	W16
	.byte		        An3 
	.byte	W16
	.byte		        Fn4 
	.byte	W16
	.byte		        En4 
	.byte	W16
	.byte		        Dn4 
	.byte	W16
	.byte		        An4 
	.byte	W16
	.byte		        Gn4 
	.byte	W16
	.byte		        Fn4 
	.byte	W16
	.byte		        Cn5 
	.byte	W16
	.byte		        Bn4 
	.byte	W16
	.byte		        An4 
	.byte	W16
	.byte		VOICE , 48
	.byte		PAN   , c_v-21
	.byte		N60   , Bn4 , v096
	.byte	W64
	.byte		N15   , Gn4 
	.byte	W16
	.byte		        Bn4 
	.byte	W16
	.byte		N92   , Dn5 
	.byte	W48
	.byte		VOL   , 56*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        52*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        47*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        42*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        37*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        30*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        27*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte		        23*mus_rg_nanashima_mvl/mxv
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_nanashima_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_nanashima_3:
	.byte	KEYSH , mus_rg_nanashima_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-60
	.byte		VOL   , 55*mus_rg_nanashima_mvl/mxv
	.byte	W24
	.byte		PAN   , c_v-59
	.byte		N23   , Cn3 , v064
	.byte	W12
	.byte		VOL   , 50*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        40*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        30*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        20*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        10*mus_rg_nanashima_mvl/mxv
	.byte	W12
	.byte		        53*mus_rg_nanashima_mvl/mxv
	.byte		N23   
	.byte	W12
	.byte		VOL   , 50*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        40*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        30*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        20*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        10*mus_rg_nanashima_mvl/mxv
	.byte	W36
	.byte		        53*mus_rg_nanashima_mvl/mxv
	.byte		N23   , Bn2 
	.byte	W12
	.byte		VOL   , 50*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        40*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        30*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        20*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        10*mus_rg_nanashima_mvl/mxv
	.byte	W12
	.byte		        53*mus_rg_nanashima_mvl/mxv
	.byte		N23   
	.byte	W12
	.byte		VOL   , 50*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        40*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        30*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        20*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        10*mus_rg_nanashima_mvl/mxv
	.byte	W12
	.byte		        32*mus_rg_nanashima_mvl/mxv
	.byte		N23   , An2 
	.byte	W06
	.byte		VOL   , 37*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        42*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        49*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        52*mus_rg_nanashima_mvl/mxv
	.byte	W03
	.byte		        53*mus_rg_nanashima_mvl/mxv
	.byte	W06
mus_rg_nanashima_3_B1:
	.byte		VOL   , 53*mus_rg_nanashima_mvl/mxv
	.byte		N23   , Gn2 , v064
	.byte	W24
	.byte		N11   , Dn2 
	.byte	W12
	.byte		N23   , Dn3 
	.byte	W24
	.byte		N11   , Cn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N23   , As2 
	.byte	W24
	.byte		N11   , Fn2 
	.byte	W12
	.byte		N23   , Fn3 
	.byte	W24
	.byte		N11   , En3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N23   , Cn3 
	.byte	W24
	.byte		N11   , Gn2 
	.byte	W12
	.byte		N23   , En3 
	.byte	W24
	.byte		N11   , Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
mus_rg_nanashima_3_000:
	.byte		N11   , Dn3 , v064
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N23   , Dn3 
	.byte	W24
	.byte		N11   , Gn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte	PEND
	.byte		N23   , Gn2 
	.byte	W24
	.byte		N05   , Dn2 
	.byte	W12
	.byte		N23   , Dn3 
	.byte	W24
	.byte		N11   , Cn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N23   , As2 
	.byte	W24
	.byte		N05   , Fn2 
	.byte	W12
	.byte		N23   , Fn3 
	.byte	W24
	.byte		N11   , En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N23   , Cn3 
	.byte	W24
	.byte		N05   , Gn2 
	.byte	W12
	.byte		N23   , En3 
	.byte	W24
	.byte		N11   , Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_nanashima_3_000
	.byte		N11   , Dn3 , v064
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N23   , Gn3 
	.byte	W24
	.byte		N11   , Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		VOICE , 1
	.byte		N15   , Cn5 , v068
	.byte	W16
	.byte		        Bn4 
	.byte	W16
	.byte		        An4 
	.byte	W16
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N11   , Fn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		VOICE , 48
	.byte		N23   , An2 , v064
	.byte	W24
	.byte		N11   , Fn2 
	.byte	W12
	.byte		N23   , Cn3 
	.byte	W24
	.byte		N11   , Fn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		N23   , Bn2 
	.byte	W24
	.byte		N11   , Gn2 
	.byte	W12
	.byte		N23   , Bn2 
	.byte	W24
	.byte		N11   , Gn2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N23   , Gn3 
	.byte	W24
	.byte		N11   , Gn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		VOICE , 1
	.byte		PAN   , c_v-38
	.byte		N15   , Cn5 , v076
	.byte	W16
	.byte		        Bn4 
	.byte	W16
	.byte		        An4 
	.byte	W16
	.byte		        Fn5 
	.byte	W16
	.byte		        En5 
	.byte	W16
	.byte		        Dn5 
	.byte	W16
	.byte		        An5 
	.byte	W16
	.byte		        Gn5 
	.byte	W16
	.byte		        Fn5 
	.byte	W16
	.byte		        Cn6 
	.byte	W16
	.byte		        Bn5 
	.byte	W16
	.byte		        An5 
	.byte	W16
	.byte		N24   , Bn5 
	.byte	W24
	.byte		PAN   , c_v+48
	.byte		N24   , Bn5 , v048
	.byte	W24
	.byte		PAN   , c_v-40
	.byte		N15   , Bn5 , v044
	.byte	W16
	.byte		        Gn5 , v100
	.byte	W16
	.byte		        Bn5 
	.byte	W16
	.byte		N23   , Dn6 , v088
	.byte	W24
	.byte		PAN   , c_v+48
	.byte		N11   , Dn6 , v048
	.byte	W12
	.byte		VOICE , 48
	.byte		PAN   , c_v-41
	.byte		N23   , Gn2 
	.byte	W24
	.byte		N11   , Dn2 , v056
	.byte	W12
	.byte		        Gn2 , v064
	.byte	W12
	.byte		        Dn2 , v072
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_nanashima_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_nanashima_4:
	.byte	KEYSH , mus_rg_nanashima_key+0
	.byte		VOICE , 81
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 68*mus_rg_nanashima_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W24
	.byte		N80   , Cn1 , v120
	.byte	W24
	.byte		VOL   , 51*mus_rg_nanashima_mvl/mxv
	.byte	W05
	.byte		        45*mus_rg_nanashima_mvl/mxv
	.byte	W07
	.byte		        41*mus_rg_nanashima_mvl/mxv
	.byte	W05
	.byte		        37*mus_rg_nanashima_mvl/mxv
	.byte	W07
	.byte		        34*mus_rg_nanashima_mvl/mxv
	.byte	W05
	.byte		        29*mus_rg_nanashima_mvl/mxv
	.byte	W07
	.byte		        25*mus_rg_nanashima_mvl/mxv
	.byte	W05
	.byte		        20*mus_rg_nanashima_mvl/mxv
	.byte	W07
	.byte		        14*mus_rg_nanashima_mvl/mxv
	.byte	W05
	.byte		        10*mus_rg_nanashima_mvl/mxv
	.byte	W07
	.byte		        6*mus_rg_nanashima_mvl/mxv
	.byte		N06   , Cs1 
	.byte	W05
	.byte		VOL   , 3*mus_rg_nanashima_mvl/mxv
	.byte	W07
	.byte		        68*mus_rg_nanashima_mvl/mxv
	.byte		N72   , Dn1 
	.byte	W24
	.byte		VOL   , 51*mus_rg_nanashima_mvl/mxv
	.byte	W05
	.byte		        45*mus_rg_nanashima_mvl/mxv
	.byte	W07
	.byte		        41*mus_rg_nanashima_mvl/mxv
	.byte	W05
	.byte		        37*mus_rg_nanashima_mvl/mxv
	.byte	W07
	.byte		        34*mus_rg_nanashima_mvl/mxv
	.byte	W05
	.byte		        29*mus_rg_nanashima_mvl/mxv
	.byte	W07
	.byte		        25*mus_rg_nanashima_mvl/mxv
	.byte	W05
	.byte		        20*mus_rg_nanashima_mvl/mxv
	.byte	W07
	.byte		        14*mus_rg_nanashima_mvl/mxv
	.byte	W05
	.byte		        10*mus_rg_nanashima_mvl/mxv
	.byte	W07
	.byte		        6*mus_rg_nanashima_mvl/mxv
	.byte	W05
	.byte		        3*mus_rg_nanashima_mvl/mxv
	.byte	W07
mus_rg_nanashima_4_B1:
	.byte		VOL   , 68*mus_rg_nanashima_mvl/mxv
	.byte		BEND  , c_v-6
	.byte		N15   , Gn1 , v120
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N30   
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N12   , Fs1 
	.byte	W12
	.byte		BEND  , c_v-6
	.byte		N15   , Fn1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N12   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N15   , En1 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N24   
	.byte	W30
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , En2 
	.byte	W06
	.byte		N12   , Ds1 
	.byte	W12
	.byte		N18   , Dn1 
	.byte	W18
	.byte		        Dn2 
	.byte	W18
	.byte		N12   , Cn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		N03   , Gn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , An1 
	.byte	W06
	.byte		BEND  , c_v-11
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N15   , Dn2 
	.byte	W18
	.byte		N06   , Gn1 
	.byte	W18
	.byte		N21   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , An1 
	.byte	W06
	.byte		BEND  , c_v-11
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N15   , Fn1 
	.byte	W18
	.byte		N18   , Fn2 
	.byte	W18
	.byte		N06   , Fn1 
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , En2 
	.byte	W06
	.byte		BEND  , c_v+5
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , Cn2 
	.byte	W06
	.byte		BEND  , c_v+5
	.byte	W06
	.byte		        c_v+0
	.byte		N18   , En1 
	.byte	W18
	.byte		        En2 
	.byte	W18
	.byte		N12   , Dn2 
	.byte	W12
	.byte		N18   , Cn2 
	.byte	W18
	.byte		        Bn1 
	.byte	W18
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N18   , Dn1 
	.byte	W18
	.byte		        Dn2 
	.byte	W18
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N24   , Bn1 
	.byte	W24
	.byte		        An1 
	.byte	W06
	.byte		BEND  , c_v-11
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W18
	.byte		N15   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , An1 
	.byte	W06
	.byte		BEND  , c_v-11
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W18
	.byte		N15   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N24   , Gn1 
	.byte	W06
	.byte		BEND  , c_v+10
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N12   , Fn1 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W12
	.byte		N24   , Bn1 
	.byte	W24
	.byte		        An1 
	.byte	W24
	.byte		N03   , Gn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		N15   , Dn1 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N03   , Cs1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N15   , Dn1 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N24   , Bn1 
	.byte	W06
	.byte		BEND  , c_v-11
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N03   , Dn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , En1 
	.byte	W06
	.byte		BEND  , c_v-11
	.byte	W06
	.byte		        c_v+0
	.byte		N06   , Fs1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		N12   , Gn1 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N03   , Gn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , An1 
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_nanashima_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_nanashima_5:
	.byte	KEYSH , mus_rg_nanashima_key+0
	.byte		VOICE , 92
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 57*mus_rg_nanashima_mvl/mxv
	.byte		BEND  , c_v+1
	.byte	W24
	.byte		N92   , Cn4 , v088
	.byte	W96
	.byte		        Dn4 
	.byte	W96
mus_rg_nanashima_5_B1:
	.byte		N60   , Gn4 , v088
	.byte	W64
	.byte		N15   , Dn4 
	.byte	W16
	.byte		        Gn4 
	.byte	W16
mus_rg_nanashima_5_000:
	.byte		N60   , Dn5 , v088
	.byte	W64
	.byte		N15   , Fn5 
	.byte	W16
	.byte		        En5 
	.byte	W16
	.byte	PEND
mus_rg_nanashima_5_001:
	.byte		N68   , Cn5 , v088
	.byte	W72
	.byte		N23   , En5 
	.byte	W24
	.byte	PEND
	.byte		N17   , Dn5 
	.byte	W18
	.byte		N05   , Cn5 
	.byte	W06
	.byte		N44   , Bn4 
	.byte	W48
	.byte		N06   
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N48   , Bn4 
	.byte	W48
	.byte		N18   , Gn4 
	.byte	W16
	.byte		N15   , Dn4 
	.byte	W16
	.byte		        Gn4 
	.byte	W16
	.byte	PATT
	 .word	mus_rg_nanashima_5_000
	.byte	PATT
	 .word	mus_rg_nanashima_5_001
	.byte		N17   , Dn5 , v088
	.byte	W18
	.byte		N05   , Cn5 
	.byte	W06
	.byte		N68   , Bn4 
	.byte	W72
	.byte		N92   
	.byte	W96
	.byte		N15   , Cn4 
	.byte	W16
	.byte		        Bn3 
	.byte	W16
	.byte		        An3 
	.byte	W16
	.byte		N44   , Fn3 
	.byte	W48
	.byte	W12
	.byte		N05   , Fn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Cn5 
	.byte	W12
	.byte		        An4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N44   , Fn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 40*mus_rg_nanashima_mvl/mxv
	.byte	W24
	.byte		        57*mus_rg_nanashima_mvl/mxv
	.byte		MOD   , 0
	.byte	W12
	.byte		N23   , Dn5 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		N11   , An4 
	.byte	W12
	.byte		N15   , Gn4 
	.byte	W16
	.byte		        An4 
	.byte	W16
	.byte		        Bn4 
	.byte	W16
	.byte		N44   , Dn5 
	.byte	W48
	.byte		N15   , Cn4 
	.byte	W16
	.byte		        Bn3 
	.byte	W16
	.byte		        An3 
	.byte	W16
	.byte		        Fn4 
	.byte	W16
	.byte		        En4 
	.byte	W16
	.byte		        Dn4 
	.byte	W16
	.byte		        An4 
	.byte	W16
	.byte		        Gn4 
	.byte	W16
	.byte		        Fn4 
	.byte	W16
	.byte		        Cn5 
	.byte	W16
	.byte		        Bn4 
	.byte	W16
	.byte		        An4 
	.byte	W16
	.byte		N60   , Bn4 
	.byte	W64
	.byte		N15   , Gn4 
	.byte	W16
	.byte		        Bn4 
	.byte	W16
	.byte		N92   , Dn5 
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_nanashima_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_nanashima_6:
	.byte	KEYSH , mus_rg_nanashima_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 37*mus_rg_nanashima_mvl/mxv
	.byte	W24
	.byte	W96
	.byte	W72
	.byte		VOICE , 80
	.byte	W21
	.byte		N01   , Gn2 , v120
	.byte	W01
	.byte		        Bn2 
	.byte	W02
mus_rg_nanashima_6_B1:
	.byte		N06   , Cs3 , v120
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N01   
	.byte		N01   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        Gn2 
	.byte	W01
	.byte		        Bn2 
	.byte	W02
	.byte		N06   , Cs3 
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn3 
	.byte	W03
	.byte		N01   , Fn2 
	.byte	W01
	.byte		        An2 
	.byte	W02
	.byte		N06   , Cs3 
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N01   , Dn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn3 
	.byte	W03
	.byte		N01   , En2 
	.byte	W01
	.byte		        Gn2 
	.byte	W02
mus_rg_nanashima_6_000:
	.byte		N06   , Bn2 , v120
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N12   , En3 
	.byte	W12
	.byte		N01   , Cn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        En2 
	.byte	W01
	.byte		        Gn2 
	.byte	W02
	.byte		N06   , Bn2 
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W03
	.byte		N01   , Bn2 
	.byte	W01
	.byte		        Dn3 
	.byte	W02
	.byte	PEND
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N01   , Gn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        Bn2 
	.byte	W01
	.byte		        Dn3 
	.byte	W02
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        Gn2 
	.byte	W01
	.byte		        Bn2 
	.byte	W02
	.byte		N06   , Cs3 
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N01   , Dn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        Gn2 
	.byte	W01
	.byte		        Bn2 
	.byte	W02
	.byte		N06   , Cs3 
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W06
	.byte		N01   , Gn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N01   , Fn2 
	.byte	W01
	.byte		        An2 
	.byte	W02
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N01   , Dn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W06
	.byte		N01   , Fn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W03
	.byte		N01   , En2 
	.byte	W01
	.byte		        Gn2 
	.byte	W02
	.byte	PATT
	 .word	mus_rg_nanashima_6_000
	.byte		N06   , Fs3 , v120
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N01   , Gn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        Bn2 
	.byte	W01
	.byte		        Dn3 
	.byte	W02
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N01   , Gn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        Fn2 
	.byte	W01
	.byte		        An2 
	.byte	W02
	.byte		N03   , Cn3 
	.byte	W18
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N13   
	.byte	W15
	.byte		N01   , Fn2 
	.byte	W01
	.byte		        An2 
	.byte	W02
	.byte		N03   , Cn3 
	.byte	W18
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   , Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W03
	.byte		N01   , Bn2 
	.byte	W01
	.byte		        Dn3 
	.byte	W02
	.byte		N03   , Gn3 
	.byte	W18
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N10   , Bn3 
	.byte	W12
	.byte		N01   , Gn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N10   , Dn3 
	.byte	W12
	.byte		N01   , Cs3 
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W18
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N10   , Fn3 
	.byte	W12
	.byte		N02   , Cn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N10   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N10   , Dn3 
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N10   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N10   , Gn3 
	.byte	W12
	.byte		N01   , Dn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N10   , Gn3 
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_nanashima_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_rg_nanashima_7:
	.byte	KEYSH , mus_rg_nanashima_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 42*mus_rg_nanashima_mvl/mxv
	.byte		PAN   , c_v+38
	.byte	W24
	.byte		N96   , En2 , v120
	.byte	W96
	.byte		N92   , Dn2 
	.byte	W72
	.byte		VOICE , 24
	.byte	W21
	.byte		N01   , Bn2 
	.byte	W01
	.byte		        Dn3 
	.byte	W02
mus_rg_nanashima_7_B1:
	.byte		N06   , Fs3 , v120
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        Bn2 
	.byte	W01
	.byte		        Dn3 
	.byte	W02
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fn3 
	.byte	W03
	.byte		N01   , An2 
	.byte	W01
	.byte		        Cn3 
	.byte	W02
	.byte		N06   , En3 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N01   , Fn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Ds3 
	.byte	W03
	.byte		N01   , Gn2 
	.byte	W01
	.byte		        Cn3 
	.byte	W02
mus_rg_nanashima_7_000:
	.byte		N06   , Ds3 , v120
	.byte	W06
	.byte		N03   , En3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N01   , En3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        Gn2 
	.byte	W01
	.byte		        Cn3 
	.byte	W02
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N03   , En3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W03
	.byte		N01   , Dn3 
	.byte	W01
	.byte		        Gn3 
	.byte	W02
	.byte	PEND
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N01   , Bn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        Dn3 
	.byte	W01
	.byte		        Gn3 
	.byte	W02
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        Bn2 
	.byte	W01
	.byte		        Dn3 
	.byte	W02
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N01   , Gn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        Bn2 
	.byte	W01
	.byte		        Dn3 
	.byte	W02
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N01   , Dn4 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N01   , An2 
	.byte	W01
	.byte		        Cn3 
	.byte	W02
	.byte		N06   , En3 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N01   , Fn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N01   , As3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W03
	.byte		N01   , Gn2 
	.byte	W01
	.byte		        Cn3 
	.byte	W02
	.byte	PATT
	 .word	mus_rg_nanashima_7_000
	.byte		N06   , As3 , v120
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N01   , Bn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        Dn3 
	.byte	W01
	.byte		        Gn3 
	.byte	W02
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N01   , Bn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        An2 
	.byte	W01
	.byte		        Cn3 
	.byte	W02
	.byte		N03   , Fn3 
	.byte	W18
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N13   
	.byte	W15
	.byte		N01   , An2 
	.byte	W01
	.byte		        Cn3 
	.byte	W02
	.byte		N03   , Fn3 
	.byte	W18
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   , Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W03
	.byte		N01   , Dn3 
	.byte	W01
	.byte		        Gn3 
	.byte	W02
	.byte		N03   , Bn3 
	.byte	W18
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N10   , Dn4 
	.byte	W12
	.byte		N01   , Bn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N10   , An3 
	.byte	W12
	.byte		N01   , Gn3 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W18
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N10   , An3 
	.byte	W12
	.byte		N02   , Fn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N10   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N10   , Fs3 
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W18
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N10   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N10   , Bn3 
	.byte	W12
	.byte		N01   , Gn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N10   , Bn3 
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_nanashima_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_rg_nanashima_8:
	.byte	KEYSH , mus_rg_nanashima_key+0
	.byte		VOICE , 0
	.byte		VOL   , 68*mus_rg_nanashima_mvl/mxv
	.byte		N06   , Cn1 , v120
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		N24   , Cn1 , v120
	.byte	W36
	.byte		N44   
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N20   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Dn1 , v127
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Dn1 , v044
	.byte	W06
mus_rg_nanashima_8_B1:
	.byte		N12   , Cn1 , v120
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N30   
	.byte	W36
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Dn1 , v080
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Dn1 , v040
	.byte	W06
	.byte		N18   , Cn1 , v120
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N24   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Dn1 , v084
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Dn1 , v040
	.byte	W06
	.byte		N18   , Cn1 , v120
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N24   
	.byte	W30
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Dn1 , v084
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Dn1 , v040
	.byte	W06
	.byte		N18   , Cn1 , v120
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N18   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Dn1 , v080
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Dn1 , v048
	.byte	W06
	.byte		N18   , Cn1 , v120
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N18   
	.byte	W36
	.byte		N06   , Dn1 , v112
	.byte	W06
	.byte		        Dn1 , v127
	.byte	W06
	.byte		        Dn1 , v080
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		N18   , Cn1 , v120
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N18   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Dn1 , v076
	.byte	W06
	.byte		        Dn1 , v056
	.byte	W06
	.byte		        Dn1 , v036
	.byte	W06
	.byte		N18   , Cn1 , v120
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N18   
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Dn1 , v080
	.byte	W06
	.byte		N18   , Cn1 , v120
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N24   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Dn1 , v088
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Dn1 , v048
	.byte	W06
	.byte		N18   , Cn1 , v120
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N18   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn2 , v127
	.byte	W12
	.byte		        Fn1 
	.byte	W06
	.byte		N18   , Cn1 , v120
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N18   
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Dn1 , v088
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Dn1 , v040
	.byte	W06
	.byte		N18   , Cn1 , v120
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N18   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W12
	.byte		N24   , Cn1 
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N18   
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N18   
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N06   , Dn1 , v104
	.byte	W06
	.byte		N05   , Dn1 , v124
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N18   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N18   , Cn1 
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N18   , Cn1 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N18   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N24   , Cn1 
	.byte	W30
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N18   
	.byte	W18
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_nanashima_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_rg_nanashima_9:
	.byte	KEYSH , mus_rg_nanashima_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 37*mus_rg_nanashima_mvl/mxv
	.byte	W24
mus_rg_nanashima_9_000:
	.byte		N01   , Cn5 , v127
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W18
	.byte		N01   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W42
	.byte	PEND
mus_rg_nanashima_9_001:
	.byte		N01   , Cn5 , v127
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W18
	.byte		N01   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W24
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte	PEND
mus_rg_nanashima_9_B1:
	.byte	PATT
	 .word	mus_rg_nanashima_9_000
	.byte	PATT
	 .word	mus_rg_nanashima_9_001
	.byte		N01   , Cn5 , v127
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W18
	.byte		N01   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W18
	.byte		N02   , Cn5 , v120
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte	PATT
	 .word	mus_rg_nanashima_9_001
	.byte	PATT
	 .word	mus_rg_nanashima_9_000
	.byte	PATT
	 .word	mus_rg_nanashima_9_001
mus_rg_nanashima_9_002:
	.byte		N01   , Cn5 , v127
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W18
	.byte		N01   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N02   , Cn5 , v120
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W18
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_nanashima_9_001
	.byte	PATT
	 .word	mus_rg_nanashima_9_002
mus_rg_nanashima_9_003:
	.byte		N02   , Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W06
	.byte		N02   
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W06
	.byte		N02   
	.byte	W18
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W30
	.byte	PEND
mus_rg_nanashima_9_004:
	.byte		N02   , Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W18
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W18
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W06
	.byte	PEND
mus_rg_nanashima_9_005:
	.byte		N02   , Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
	.byte	PEND
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		N02   
	.byte	W18
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W18
	.byte		        Cn5 , v060
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte	PATT
	 .word	mus_rg_nanashima_9_003
	.byte	PATT
	 .word	mus_rg_nanashima_9_004
	.byte	PATT
	 .word	mus_rg_nanashima_9_005
	.byte		N02   , Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		N02   
	.byte	W18
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W18
	.byte	GOTO
	 .word	mus_rg_nanashima_9_B1
	.byte	FINE

@********************** Track 10 **********************@

mus_rg_nanashima_10:
	.byte	KEYSH , mus_rg_nanashima_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 40*mus_rg_nanashima_mvl/mxv
	.byte	W24
mus_rg_nanashima_10_000:
	.byte	W24
	.byte		N11   , Gn5 , v127
	.byte	W36
	.byte		N05   
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_nanashima_10_000
mus_rg_nanashima_10_B1:
	.byte	PATT
	 .word	mus_rg_nanashima_10_000
	.byte	PATT
	 .word	mus_rg_nanashima_10_000
	.byte	PATT
	 .word	mus_rg_nanashima_10_000
	.byte	PATT
	 .word	mus_rg_nanashima_10_000
	.byte	PATT
	 .word	mus_rg_nanashima_10_000
	.byte	PATT
	 .word	mus_rg_nanashima_10_000
	.byte	W24
	.byte		N11   , Gn5 , v127
	.byte	W60
	.byte		N12   , Gn5 , v120
	.byte	W12
	.byte	PATT
	 .word	mus_rg_nanashima_10_000
	.byte	W24
	.byte		N11   , Gn5 , v127
	.byte	W60
	.byte		N06   , Fs5 , v120
	.byte		N12   , Gn5 
	.byte	W12
	.byte	W72
	.byte		N24   
	.byte	W24
	.byte	W72
	.byte		N12   
	.byte	W24
	.byte	W96
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W48
	.byte	W72
	.byte		N24   
	.byte	W24
	.byte	W72
	.byte		N12   
	.byte	W24
	.byte	W96
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_nanashima_10_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_nanashima:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_nanashima_pri	@ Priority
	.byte	mus_rg_nanashima_rev	@ Reverb.

	.word	mus_rg_nanashima_grp

	.word	mus_rg_nanashima_1
	.word	mus_rg_nanashima_2
	.word	mus_rg_nanashima_3
	.word	mus_rg_nanashima_4
	.word	mus_rg_nanashima_5
	.word	mus_rg_nanashima_6
	.word	mus_rg_nanashima_7
	.word	mus_rg_nanashima_8
	.word	mus_rg_nanashima_9
	.word	mus_rg_nanashima_10

	.end
