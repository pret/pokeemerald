	.include "MPlayDef.s"

	.equ	mus_machi_s4_grp, voicegroup019
	.equ	mus_machi_s4_pri, 0
	.equ	mus_machi_s4_rev, reverb_set+50
	.equ	mus_machi_s4_mvl, 127
	.equ	mus_machi_s4_key, 0
	.equ	mus_machi_s4_tbs, 1
	.equ	mus_machi_s4_exg, 1
	.equ	mus_machi_s4_cmp, 1

	.section .rodata
	.global	mus_machi_s4
	.align	2

@********************** Track  1 **********************@

mus_machi_s4_1:
	.byte	KEYSH , mus_machi_s4_key+0
mus_machi_s4_1_B1:
	.byte	TEMPO , 100*mus_machi_s4_tbs/2
	.byte		VOICE , 73
	.byte		LFOS  , 44
	.byte		VOL   , 80*mus_machi_s4_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N36   , As4 , v108
	.byte	W15
	.byte		MOD   , 6
	.byte	W21
	.byte		        0
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N32   , As3 , v108, gtp1
	.byte	W15
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 76*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        62*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        42*mus_machi_s4_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 80*mus_machi_s4_mvl/mxv
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N09   , As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N96   , Cn4 
	.byte	W24
	.byte		VOL   , 77*mus_machi_s4_mvl/mxv
	.byte		MOD   , 6
	.byte	W05
	.byte		VOL   , 69*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        65*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        58*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        53*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        47*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        39*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        32*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        26*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        19*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        14*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        3*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		VOICE , 45
	.byte		VOL   , 80*mus_machi_s4_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , An4 , v072
	.byte	W36
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		VOICE , 73
	.byte		N36   , As4 , v108
	.byte	W15
	.byte		MOD   , 6
	.byte	W21
	.byte		        0
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N32   , As3 , v108, gtp1
	.byte	W15
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 76*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        62*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        42*mus_machi_s4_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 80*mus_machi_s4_mvl/mxv
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N12   , An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		N96   , Dn5 
	.byte	W24
	.byte		VOL   , 77*mus_machi_s4_mvl/mxv
	.byte		MOD   , 6
	.byte	W05
	.byte		VOL   , 69*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        65*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        58*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        53*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        47*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        39*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        32*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        26*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        19*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        14*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        3*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		VOICE , 45
	.byte		MOD   , 0
	.byte		VOL   , 80*mus_machi_s4_mvl/mxv
	.byte		N06   , Gn4 , v072
	.byte	W36
	.byte		        Ds4 
	.byte	W12
	.byte		        An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		VOICE , 73
	.byte		N32   , Dn5 , v108, gtp1
	.byte	W12
	.byte		MOD   , 6
	.byte	W21
	.byte		        0
	.byte	W03
	.byte		N06   , As4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N09   , Dn5 
	.byte	W12
	.byte		        As5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		N32   , Fn5 , v108, gtp1
	.byte	W12
	.byte		MOD   , 6
	.byte	W21
	.byte		        0
	.byte	W03
	.byte		N12   , Gn5 
	.byte	W12
	.byte		N48   , Dn5 
	.byte	W15
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 80*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        70*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        50*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        34*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        17*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		MOD   , 0
	.byte		N32   , Ds5 , v108, gtp1
	.byte	W12
	.byte		MOD   , 6
	.byte	W21
	.byte		        0
	.byte	W03
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N09   , Ds5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N32   , As4 , v108, gtp1
	.byte	W12
	.byte		MOD   , 6
	.byte	W21
	.byte		        0
	.byte	W03
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N48   , An4 
	.byte	W15
	.byte		MOD   , 6
	.byte	W09
	.byte		VOL   , 74*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        63*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        51*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        34*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		MOD   , 0
	.byte		N32   , As4 , v108, gtp1
	.byte	W15
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte	W03
	.byte		N06   , Ds5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Gn5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        As5 
	.byte	W12
	.byte		N12   , As4 
	.byte	W12
	.byte		MOD   , 0
	.byte		N32   , Cs5 , v108, gtp1
	.byte	W15
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte	W03
	.byte		N06   , Ds5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte		        As5 
	.byte	W12
	.byte		N12   , As4 
	.byte	W12
	.byte		N36   , Cn5 
	.byte	W15
	.byte		MOD   , 6
	.byte	W21
	.byte		        0
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N08   , As5 
	.byte	W08
	.byte		        An5 
	.byte	W08
	.byte		        As5 
	.byte	W08
	.byte		N90   , An5 
	.byte	W18
	.byte		MOD   , 6
	.byte	W06
	.byte		VOL   , 80*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        78*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        75*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        70*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        68*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        63*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        56*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        50*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        43*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        36*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        26*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        15*mus_machi_s4_mvl/mxv
	.byte	W01
	.byte		MOD   , 0
	.byte	W06
	.byte	GOTO
	 .word	mus_machi_s4_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_machi_s4_2:
	.byte	KEYSH , mus_machi_s4_key+0
mus_machi_s4_2_B1:
	.byte		VOICE , 60
	.byte		PAN   , c_v-12
	.byte	W96
	.byte	W48
	.byte		VOL   , 37*mus_machi_s4_mvl/mxv
	.byte		N48   , Fn2 , v076
	.byte	W05
	.byte		VOL   , 43*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        49*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        57*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        63*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        70*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        78*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		N36   , Fn3 
	.byte	W36
	.byte		N12   , Ds3 , v084
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N96   , Cn3 
	.byte	W24
	.byte		VOL   , 80*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        78*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        76*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        71*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        68*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        59*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        52*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        43*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        32*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        22*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        9*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        1*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte	W96
	.byte	W48
	.byte		        37*mus_machi_s4_mvl/mxv
	.byte		N48   , Cn3 , v076
	.byte	W05
	.byte		VOL   , 43*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        49*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        57*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        63*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        70*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        78*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		N36   , Dn3 , v084
	.byte	W36
	.byte		N12   , As2 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N44   , Cn3 , v084, gtp1
	.byte	W18
	.byte		VOL   , 75*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        60*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        38*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        23*mus_machi_s4_mvl/mxv
	.byte	W12
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N48   , Ds3 
	.byte	W12
	.byte		VOL   , 74*mus_machi_s4_mvl/mxv
	.byte	W02
	.byte		        64*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        53*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        46*mus_machi_s4_mvl/mxv
	.byte	W04
	.byte		        47*mus_machi_s4_mvl/mxv
	.byte	W02
	.byte		        49*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        53*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        59*mus_machi_s4_mvl/mxv
	.byte	W04
	.byte		        63*mus_machi_s4_mvl/mxv
	.byte	W02
	.byte		        76*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		VOICE , 60
	.byte		N48   , Fn2 , v076
	.byte	W06
	.byte		VOL   , 76*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        69*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        60*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        59*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        68*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        76*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		N48   , Gn2 
	.byte	W06
	.byte		VOL   , 76*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        68*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        64*mus_machi_s4_mvl/mxv
	.byte	W13
	.byte		        74*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte	W12
	.byte		N36   , An2 
	.byte	W06
	.byte		VOL   , 68*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        71*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte	W19
	.byte		N12   , Gn2 
	.byte	W12
	.byte		N24   , Fn2 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        Gn2 
	.byte	W12
	.byte		VOL   , 68*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        45*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        28*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        13*mus_machi_s4_mvl/mxv
	.byte	W15
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N12   , Ds2 
	.byte	W12
	.byte		N21   , Gn2 
	.byte	W12
	.byte		VOL   , 68*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        45*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        28*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        13*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W18
	.byte		        An2 
	.byte	W18
	.byte		        As2 
	.byte	W12
	.byte		N44   , Cn3 , v076, gtp1
	.byte	W12
	.byte		VOL   , 76*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        65*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        52*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        39*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        30*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        18*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N32   , As2 , v088, gtp1
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N44   , Ds3 , v088, gtp1
	.byte	W18
	.byte		VOL   , 69*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        62*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        50*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        34*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        18*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N32   , As2 , v088, gtp1
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N48   , Fs3 
	.byte	W18
	.byte		VOL   , 69*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        62*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        50*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        34*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        18*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N48   , Cn3 
	.byte	W48
	.byte		        As2 
	.byte	W48
	.byte		N36   , An2 
	.byte	W36
	.byte		N12   , As2 
	.byte	W12
	.byte		N44   , Cn3 
	.byte	W24
	.byte		VOL   , 75*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        58*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        37*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        24*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte	GOTO
	 .word	mus_machi_s4_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_machi_s4_3:
	.byte	KEYSH , mus_machi_s4_key+0
mus_machi_s4_3_B1:
	.byte		VOICE , 58
	.byte		VOL   , 80*mus_machi_s4_mvl/mxv
	.byte		N24   , As1 , v127
	.byte	W12
	.byte		VOL   , 68*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        45*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        28*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        13*mus_machi_s4_mvl/mxv
	.byte	W24
	.byte	W03
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N24   , An1 
	.byte	W12
	.byte		VOL   , 68*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        45*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        28*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        13*mus_machi_s4_mvl/mxv
	.byte	W24
	.byte	W03
mus_machi_s4_3_000:
	.byte		VOL   , 80*mus_machi_s4_mvl/mxv
	.byte		N24   , Gn1 , v127
	.byte	W12
	.byte		VOL   , 68*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        45*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        28*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        13*mus_machi_s4_mvl/mxv
	.byte	W24
	.byte	W03
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N24   , Fn1 
	.byte	W12
	.byte		VOL   , 68*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        45*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        28*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        13*mus_machi_s4_mvl/mxv
	.byte	W24
	.byte	W03
	.byte	PEND
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N24   
	.byte	W12
	.byte		VOL   , 68*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        45*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        28*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        13*mus_machi_s4_mvl/mxv
	.byte	W24
	.byte	W03
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N24   
	.byte	W12
	.byte		VOL   , 68*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        45*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        28*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        13*mus_machi_s4_mvl/mxv
	.byte	W24
	.byte	W03
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N24   , Cn2 
	.byte	W12
	.byte		VOL   , 68*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        45*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        28*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        13*mus_machi_s4_mvl/mxv
	.byte	W15
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W12
	.byte		VOL   , 68*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        45*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        28*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        13*mus_machi_s4_mvl/mxv
	.byte	W24
	.byte	W03
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N24   , As1 
	.byte	W12
	.byte		VOL   , 68*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        45*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        28*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        13*mus_machi_s4_mvl/mxv
	.byte	W24
	.byte	W03
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N24   , An1 
	.byte	W12
	.byte		VOL   , 68*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        45*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        28*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        13*mus_machi_s4_mvl/mxv
	.byte	W24
	.byte	W03
	.byte	PATT
	 .word	mus_machi_s4_3_000
	.byte		VOL   , 80*mus_machi_s4_mvl/mxv
	.byte		N24   , As1 , v127
	.byte	W12
	.byte		VOL   , 68*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        45*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        28*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        13*mus_machi_s4_mvl/mxv
	.byte	W24
	.byte	W03
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N24   , Bn1 
	.byte	W12
	.byte		VOL   , 68*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        45*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        28*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        13*mus_machi_s4_mvl/mxv
	.byte	W24
	.byte	W03
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N24   , Cn2 
	.byte	W12
	.byte		VOL   , 68*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        45*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        28*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        13*mus_machi_s4_mvl/mxv
	.byte	W15
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		N48   , Fn1 
	.byte	W12
	.byte		VOL   , 74*mus_machi_s4_mvl/mxv
	.byte	W02
	.byte		        64*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        53*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        46*mus_machi_s4_mvl/mxv
	.byte	W04
	.byte		        47*mus_machi_s4_mvl/mxv
	.byte	W02
	.byte		        49*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        53*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        59*mus_machi_s4_mvl/mxv
	.byte	W04
	.byte		        63*mus_machi_s4_mvl/mxv
	.byte	W02
	.byte		        76*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		N24   , As1 
	.byte	W12
	.byte		VOL   , 68*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        45*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        28*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        13*mus_machi_s4_mvl/mxv
	.byte	W15
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N44   , Gn1 , v127, gtp1
	.byte	W18
	.byte		VOL   , 69*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        54*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        37*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        19*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        7*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N24   , Fn1 
	.byte	W12
	.byte		VOL   , 68*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        45*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        28*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        13*mus_machi_s4_mvl/mxv
	.byte	W15
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N24   , As1 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		        Cn2 
	.byte	W12
	.byte		VOL   , 68*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        45*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        28*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        13*mus_machi_s4_mvl/mxv
	.byte	W15
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N24   , Ds2 
	.byte	W12
	.byte		VOL   , 68*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        45*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        28*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        13*mus_machi_s4_mvl/mxv
	.byte	W15
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N32   , As1 , v127, gtp1
	.byte	W12
	.byte		VOL   , 71*mus_machi_s4_mvl/mxv
	.byte	W02
	.byte		        65*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        58*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        55*mus_machi_s4_mvl/mxv
	.byte	W01
	.byte		        62*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        66*mus_machi_s4_mvl/mxv
	.byte	W02
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte	W10
	.byte		N12   , Cn2 
	.byte	W12
	.byte		        An1 
	.byte	W18
	.byte		        Gn1 
	.byte	W18
	.byte		        Fn1 
	.byte	W12
	.byte		N32   , Ds1 , v127, gtp1
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N44   , As1 , v127, gtp1
	.byte	W18
	.byte		VOL   , 69*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        62*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        50*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        34*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        18*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N32   , Fs1 , v127, gtp1
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N44   , Cs1 , v127, gtp1
	.byte	W18
	.byte		VOL   , 69*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        62*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        50*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        34*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        18*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N48   , Fn1 
	.byte	W24
	.byte		VOL   , 75*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        58*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        37*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        24*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N48   , As1 
	.byte	W24
	.byte		VOL   , 75*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        58*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        37*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        24*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N30   , Fn1 
	.byte	W15
	.byte		VOL   , 69*mus_machi_s4_mvl/mxv
	.byte	W02
	.byte		        56*mus_machi_s4_mvl/mxv
	.byte	W03
	.byte		        36*mus_machi_s4_mvl/mxv
	.byte	W04
	.byte		        25*mus_machi_s4_mvl/mxv
	.byte	W12
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		N44   , An1 , v127, gtp1
	.byte	W24
	.byte		VOL   , 75*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        58*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        37*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        24*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte	GOTO
	 .word	mus_machi_s4_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_machi_s4_4:
	.byte	KEYSH , mus_machi_s4_key+0
mus_machi_s4_4_B1:
	.byte		PAN   , c_v+0
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte	W24
	.byte		VOICE , 4
	.byte		VOL   , 80*mus_machi_s4_mvl/mxv
	.byte		N06   , As3 , v048
	.byte	W48
	.byte		        An3 
	.byte	W24
mus_machi_s4_4_000:
	.byte	W24
	.byte		N06   , Gn3 , v048
	.byte	W48
	.byte		        Fn3 
	.byte	W24
	.byte	PEND
	.byte	W24
	.byte		        An3 
	.byte	W48
	.byte		        As3 
	.byte	W24
	.byte	W24
	.byte		        An3 
	.byte	W48
	.byte		N06   
	.byte	W24
	.byte	W24
	.byte		        As3 
	.byte	W48
	.byte		        An3 
	.byte	W24
	.byte	PATT
	 .word	mus_machi_s4_4_000
	.byte	W24
	.byte		N06   , As3 , v048
	.byte	W48
	.byte		        Bn3 
	.byte	W24
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		VOICE , 80
	.byte		PAN   , c_v-48
	.byte		N48   , An3 
	.byte	W06
	.byte		VOL   , 74*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        60*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        53*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        63*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        75*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte	W12
	.byte		N06   , As3 , v044
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N48   , An3 
	.byte	W24
	.byte		VOL   , 75*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        65*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        51*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        29*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N48   , As3 
	.byte	W24
	.byte		VOL   , 75*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        65*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        51*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        29*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N12   , An3 , v048
	.byte	W18
	.byte		        Gn3 , v044
	.byte	W18
	.byte		        Fn3 
	.byte	W12
	.byte		VOICE , 6
	.byte		N06   , Ds3 , v040
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 , v048
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        As4 , v032
	.byte	W06
	.byte		        Ds4 , v024
	.byte	W06
	.byte		        As4 , v020
	.byte	W06
	.byte		        Ds4 , v016
	.byte	W06
	.byte		        As4 , v012
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs3 , v040
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 , v048
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs5 , v032
	.byte	W06
	.byte		        Fs4 , v024
	.byte	W06
	.byte		        Cs5 , v020
	.byte	W06
	.byte		        Fs4 , v016
	.byte	W06
	.byte		        Cs5 , v012
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		VOICE , 4
	.byte		N06   , As4 , v048
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N48   , An4 
	.byte	W06
	.byte		VOL   , 80*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        71*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        62*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        55*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        43*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        30*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        15*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte	GOTO
	 .word	mus_machi_s4_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_machi_s4_5:
	.byte	KEYSH , mus_machi_s4_key+0
mus_machi_s4_5_B1:
	.byte		PAN   , c_v+0
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		BEND  , c_v+0
	.byte	W24
	.byte		VOICE , 5
	.byte		VOL   , 80*mus_machi_s4_mvl/mxv
	.byte		N06   , Fn3 , v048
	.byte	W48
	.byte		N06   
	.byte	W24
mus_machi_s4_5_000:
	.byte	W24
	.byte		N06   , Dn3 , v048
	.byte	W48
	.byte		        Cn3 
	.byte	W24
	.byte	PEND
mus_machi_s4_5_001:
	.byte	W24
	.byte		N06   , Fn3 , v048
	.byte	W48
	.byte		N06   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_machi_s4_5_001
	.byte	PATT
	 .word	mus_machi_s4_5_001
	.byte	PATT
	 .word	mus_machi_s4_5_000
	.byte	PATT
	 .word	mus_machi_s4_5_001
	.byte	W24
	.byte		N06   , Gn3 , v048
	.byte	W24
	.byte		VOICE , 82
	.byte		PAN   , c_v+50
	.byte		N12   , Fn3 
	.byte	W06
	.byte		VOL   , 74*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		VOICE , 83
	.byte		VOL   , 60*mus_machi_s4_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 53*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        63*mus_machi_s4_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 75*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		N06   , Fn3 , v044
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   , Fn3 , v048
	.byte	W12
	.byte		VOL   , 75*mus_machi_s4_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 65*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        51*mus_machi_s4_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 29*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte		BEND  , c_v-5
	.byte	W03
	.byte		VOICE , 82
	.byte		N06   , Fn3 , v044
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N12   , Gn3 
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   , Gn3 , v048
	.byte	W12
	.byte		VOL   , 75*mus_machi_s4_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 65*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        51*mus_machi_s4_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 29*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		VOICE , 82
	.byte		VOL   , 80*mus_machi_s4_mvl/mxv
	.byte		N12   , Fn3 , v044
	.byte	W18
	.byte		        Ds3 
	.byte	W18
	.byte		        Dn3 
	.byte	W12
	.byte		VOICE , 7
	.byte		BEND  , c_v-5
	.byte	W03
	.byte		N06   , Ds3 , v040
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 , v048
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        As4 , v032
	.byte	W06
	.byte		        Ds4 , v024
	.byte	W06
	.byte		        As4 , v020
	.byte	W06
	.byte		        Ds4 , v016
	.byte	W06
	.byte		        As4 , v012
	.byte	W06
	.byte		        Ds4 
	.byte	W03
	.byte	W03
	.byte		        Fs3 , v040
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 , v048
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs5 , v032
	.byte	W06
	.byte		        Fs4 , v024
	.byte	W06
	.byte		        Cs5 , v020
	.byte	W06
	.byte		        Fs4 , v016
	.byte	W06
	.byte		        Cs5 , v012
	.byte	W06
	.byte		N03   , Fs4 , v016
	.byte	W03
	.byte		VOICE , 5
	.byte		BEND  , c_v+0
	.byte		N06   , Fn4 , v048
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N12   , Fn4 
	.byte	W06
	.byte		VOL   , 80*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		VOICE , 84
	.byte		VOL   , 71*mus_machi_s4_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 62*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        55*mus_machi_s4_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 43*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        30*mus_machi_s4_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 15*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte	GOTO
	 .word	mus_machi_s4_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_machi_s4_6:
	.byte	KEYSH , mus_machi_s4_key+0
mus_machi_s4_6_B1:
	.byte		VOICE , 48
	.byte		VOL   , 80*mus_machi_s4_mvl/mxv
	.byte		PAN   , c_v+10
	.byte		N06   , As3 , v072
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N24   , As4 , v080
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		N06   , Cn5 , v072
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N32   , Gn4 , v072, gtp1
	.byte	W36
	.byte		N12   , An4 
	.byte	W12
	.byte		N44   , Fn4 , v072, gtp1
	.byte	W24
	.byte		VOL   , 74*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        63*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        51*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        34*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte	W96
	.byte	W48
	.byte		N48   , As3 , v096
	.byte	W06
	.byte		VOL   , 61*mus_machi_s4_mvl/mxv
	.byte	W06
	.byte		        51*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        56*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        62*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        66*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        75*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        80*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		N48   , Cn4 
	.byte	W48
	.byte		        As3 
	.byte	W48
	.byte		N36   , An3 
	.byte	W36
	.byte		N12   , As3 
	.byte	W12
	.byte		N44   , Cn4 
	.byte	W24
	.byte		VOL   , 75*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        58*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte		        37*mus_machi_s4_mvl/mxv
	.byte	W05
	.byte		        24*mus_machi_s4_mvl/mxv
	.byte	W07
	.byte	GOTO
	 .word	mus_machi_s4_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_machi_s4_7:
	.byte	KEYSH , mus_machi_s4_key+0
mus_machi_s4_7_B1:
	.byte		VOICE , 81
	.byte		VOL   , 80*mus_machi_s4_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N32   , Cn3 , v048, gtp1
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		N09   , Ds3 
	.byte	W36
	.byte		        Cn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W36
	.byte		        Bn2 
	.byte	W12
	.byte		        As2 
	.byte	W18
	.byte		        Cn3 
	.byte	W18
	.byte		        Dn3 
	.byte	W12
	.byte		N32   , Cn3 , v048, gtp1
	.byte	W48
	.byte	W96
	.byte	W48
	.byte		N48   , Cs3 
	.byte	W48
	.byte		N36   , Fn3 , v048, gtp3
	.byte	W48
	.byte		        Fn3 , v048, gtp3
	.byte	W48
	.byte		N36   
	.byte	W36
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N36   , An3 
	.byte	W48
	.byte	GOTO
	 .word	mus_machi_s4_7_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_machi_s4:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_machi_s4_pri	@ Priority
	.byte	mus_machi_s4_rev	@ Reverb.

	.word	mus_machi_s4_grp

	.word	mus_machi_s4_1
	.word	mus_machi_s4_2
	.word	mus_machi_s4_3
	.word	mus_machi_s4_4
	.word	mus_machi_s4_5
	.word	mus_machi_s4_6
	.word	mus_machi_s4_7

	.end
