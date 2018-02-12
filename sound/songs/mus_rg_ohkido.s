	.include "MPlayDef.s"

	.equ	mus_rg_ohkido_grp, voicegroup_86AAEDC
	.equ	mus_rg_ohkido_pri, 0
	.equ	mus_rg_ohkido_rev, reverb_set+50
	.equ	mus_rg_ohkido_mvl, 127
	.equ	mus_rg_ohkido_key, 0
	.equ	mus_rg_ohkido_tbs, 1
	.equ	mus_rg_ohkido_exg, 0
	.equ	mus_rg_ohkido_cmp, 1

	.section .rodata
	.global	mus_rg_ohkido
	.align	2

@********************** Track  1 **********************@

mus_rg_ohkido_1:
	.byte	KEYSH , mus_rg_ohkido_key+0
	.byte	TEMPO , 160*mus_rg_ohkido_tbs/2
	.byte		VOICE , 1
	.byte		PAN   , c_v-19
	.byte		VOL   , 67*mus_rg_ohkido_mvl/mxv
	.byte		N06   , Gn2 , v096
	.byte	W06
	.byte		        Cn3 , v080
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N72   , Gn3 , v088
	.byte	W72
	.byte		VOL   , 86*mus_rg_ohkido_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_ohkido_1_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_ohkido_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_ohkido_2:
	.byte	KEYSH , mus_rg_ohkido_key+0
	.byte		VOICE , 1
	.byte		PAN   , c_v+16
	.byte		VOL   , 77*mus_rg_ohkido_mvl/mxv
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		N06   , Cn4 , v096
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N72   , Cn5 
	.byte	W72
	.byte		VOICE , 58
	.byte		PAN   , c_v+0
	.byte		VOL   , 51*mus_rg_ohkido_mvl/mxv
	.byte		N12   , Cn4 , v127
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N24   , Fn4 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 43*mus_rg_ohkido_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 52*mus_rg_ohkido_mvl/mxv
	.byte		N06   , En4 
	.byte	W06
	.byte		N03   , Fn4 , v100
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		N12   , Dn4 , v127
	.byte	W12
	.byte		N09   , As3 , v120
	.byte	W12
	.byte		VOICE , 73
	.byte		VOL   , 75*mus_rg_ohkido_mvl/mxv
	.byte		N12   , Cn5 , v127
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		N24   , Fn5 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 67*mus_rg_ohkido_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 75*mus_rg_ohkido_mvl/mxv
	.byte		N06   , En5 
	.byte	W06
	.byte		N03   , Fn5 , v096
	.byte	W03
	.byte		        En5 
	.byte	W03
	.byte		N24   , Dn5 , v127
	.byte	W12
	.byte		VOL   , 69*mus_rg_ohkido_mvl/mxv
	.byte	W12
	.byte		VOICE , 58
	.byte		VOL   , 52*mus_rg_ohkido_mvl/mxv
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   , As3 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		VOL   , 46*mus_rg_ohkido_mvl/mxv
	.byte		N03   , Cs4 , v088
	.byte	W03
	.byte		N21   , Cn4 , v127
	.byte	W09
	.byte		MOD   , 4
	.byte		VOL   , 53*mus_rg_ohkido_mvl/mxv
	.byte	W12
	.byte		VOICE , 73
	.byte		VOL   , 75*mus_rg_ohkido_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N24   , As4 
	.byte	W12
	.byte		VOL   , 65*mus_rg_ohkido_mvl/mxv
	.byte	W12
	.byte		        75*mus_rg_ohkido_mvl/mxv
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N03   , Dn5 , v084
	.byte	W03
	.byte		N21   , Cn5 , v127
	.byte	W09
	.byte		MOD   , 4
	.byte		VOL   , 69*mus_rg_ohkido_mvl/mxv
	.byte	W12
	.byte		        86*mus_rg_ohkido_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N24   , Fn4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , En4 
	.byte	W06
	.byte		N03   , Fn4 , v096
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		N24   , Dn4 , v127
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 79*mus_rg_ohkido_mvl/mxv
	.byte	W12
	.byte		        70*mus_rg_ohkido_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Cn5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		N24   , Fn5 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 61*mus_rg_ohkido_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 71*mus_rg_ohkido_mvl/mxv
	.byte		N06   , En5 
	.byte	W06
	.byte		N03   , Fn5 , v092
	.byte	W03
	.byte		        En5 
	.byte	W03
	.byte		N12   , Dn5 , v120
	.byte	W12
	.byte		N09   , As4 
	.byte	W12
	.byte		VOL   , 86*mus_rg_ohkido_mvl/mxv
	.byte		N12   , Cn4 , v127
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   , As3 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N03   , Cs4 , v088
	.byte	W03
	.byte		N21   , Cn4 , v127
	.byte	W09
	.byte		MOD   , 4
	.byte	W12
	.byte		VOL   , 71*mus_rg_ohkido_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N24   , As4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N03   , Cs5 , v096
	.byte	W03
	.byte		N21   , Cn5 , v127
	.byte	W09
	.byte		MOD   , 4
	.byte	W12
mus_rg_ohkido_2_B1:
	.byte		VOICE , 21
	.byte		VOL   , 65*mus_rg_ohkido_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , Dn4 , v127
	.byte	W24
	.byte		MOD   , 4
	.byte		VOL   , 56*mus_rg_ohkido_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 65*mus_rg_ohkido_mvl/mxv
	.byte		N06   , As3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N36   , Fn4 
	.byte	W24
	.byte		MOD   , 4
	.byte		VOL   , 56*mus_rg_ohkido_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 65*mus_rg_ohkido_mvl/mxv
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N18   , En4 
	.byte	W18
	.byte		N03   , Dn4 , v088
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		N24   , Dn4 , v127
	.byte	W24
	.byte		N36   , Cn4 
	.byte	W24
	.byte		MOD   , 4
	.byte		VOL   , 59*mus_rg_ohkido_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 65*mus_rg_ohkido_mvl/mxv
	.byte		N06   , An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N48   , Fn4 
	.byte	W24
	.byte		VOL   , 60*mus_rg_ohkido_mvl/mxv
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 54*mus_rg_ohkido_mvl/mxv
	.byte	W12
	.byte		VOICE , 1
	.byte		MOD   , 0
	.byte		VOL   , 65*mus_rg_ohkido_mvl/mxv
	.byte		N36   , Cn5 
	.byte	W24
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , An4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N48   , Fn5 
	.byte	W24
	.byte		VOL   , 60*mus_rg_ohkido_mvl/mxv
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 54*mus_rg_ohkido_mvl/mxv
	.byte	W12
	.byte		VOICE , 58
	.byte		VOL   , 43*mus_rg_ohkido_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , As3 
	.byte	W24
	.byte		MOD   , 4
	.byte		VOL   , 37*mus_rg_ohkido_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 43*mus_rg_ohkido_mvl/mxv
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N48   , En4 
	.byte	W36
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N24   , Fn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		N18   , Dn4 
	.byte	W18
	.byte		N03   , Cs4 , v084
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		N24   , Cs4 , v127
	.byte	W24
	.byte		N36   , Cn4 
	.byte	W24
	.byte		MOD   , 4
	.byte		VOL   , 35*mus_rg_ohkido_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 43*mus_rg_ohkido_mvl/mxv
	.byte		N06   , An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N36   , Fn4 
	.byte	W24
	.byte		MOD   , 4
	.byte		VOL   , 35*mus_rg_ohkido_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 43*mus_rg_ohkido_mvl/mxv
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N96   , An4 
	.byte	W48
	.byte		MOD   , 4
	.byte		VOL   , 39*mus_rg_ohkido_mvl/mxv
	.byte	W06
	.byte		        37*mus_rg_ohkido_mvl/mxv
	.byte	W06
	.byte		        32*mus_rg_ohkido_mvl/mxv
	.byte	W06
	.byte		        27*mus_rg_ohkido_mvl/mxv
	.byte	W06
	.byte		        21*mus_rg_ohkido_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_ohkido_mvl/mxv
	.byte	W06
	.byte		        10*mus_rg_ohkido_mvl/mxv
	.byte	W06
	.byte		        5*mus_rg_ohkido_mvl/mxv
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_ohkido_2_B1
	.byte		MOD   , 0
	.byte		VOL   , 43*mus_rg_ohkido_mvl/mxv
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_ohkido_3:
	.byte	KEYSH , mus_rg_ohkido_key+0
	.byte		VOICE , 14
	.byte		VOL   , 54*mus_rg_ohkido_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Cn5 , v052
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		N36   , Cn6 
	.byte	W06
	.byte		VOL   , 49*mus_rg_ohkido_mvl/mxv
	.byte	W03
	.byte		        44*mus_rg_ohkido_mvl/mxv
	.byte	W03
	.byte		        39*mus_rg_ohkido_mvl/mxv
	.byte	W03
	.byte		        35*mus_rg_ohkido_mvl/mxv
	.byte	W03
	.byte		        31*mus_rg_ohkido_mvl/mxv
	.byte	W03
	.byte		        26*mus_rg_ohkido_mvl/mxv
	.byte	W03
	.byte		        21*mus_rg_ohkido_mvl/mxv
	.byte	W03
	.byte		        16*mus_rg_ohkido_mvl/mxv
	.byte	W03
	.byte		        13*mus_rg_ohkido_mvl/mxv
	.byte	W03
	.byte		        10*mus_rg_ohkido_mvl/mxv
	.byte	W03
	.byte		VOICE , 48
	.byte		VOL   , 54*mus_rg_ohkido_mvl/mxv
	.byte		N06   , Gn3 , v127
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N06   , Cn5 , v104
	.byte	W24
	.byte		PAN   , c_v+32
	.byte	W12
	.byte		N24   , Fn5 , v092
	.byte	W12
	.byte		VOL   , 48*mus_rg_ohkido_mvl/mxv
	.byte	W03
	.byte		        37*mus_rg_ohkido_mvl/mxv
	.byte	W03
	.byte		        28*mus_rg_ohkido_mvl/mxv
	.byte	W03
	.byte		        16*mus_rg_ohkido_mvl/mxv
	.byte	W15
	.byte		        54*mus_rg_ohkido_mvl/mxv
	.byte	W24
	.byte		N06   , Cn4 , v104
	.byte	W24
	.byte		PAN   , c_v-32
	.byte	W12
	.byte		N24   , Fn4 , v100
	.byte	W12
	.byte		VOL   , 48*mus_rg_ohkido_mvl/mxv
	.byte	W03
	.byte		        37*mus_rg_ohkido_mvl/mxv
	.byte	W03
	.byte		        28*mus_rg_ohkido_mvl/mxv
	.byte	W03
	.byte		        16*mus_rg_ohkido_mvl/mxv
	.byte	W03
	.byte		        54*mus_rg_ohkido_mvl/mxv
	.byte		N06   , Fn3 
	.byte	W12
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		VOL   , 43*mus_rg_ohkido_mvl/mxv
	.byte		N03   , Gn3 , v127
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , En4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N03   , Fn4 
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N03   , Dn4 
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N03   , Gn3 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N03   , Gs3 
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
mus_rg_ohkido_3_B1:
mus_rg_ohkido_3_000:
	.byte		PAN   , c_v+32
	.byte		N03   , As3 , v127
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N03   , As3 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N03   , As3 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N03   , As3 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_ohkido_3_000
mus_rg_ohkido_3_001:
	.byte		PAN   , c_v+32
	.byte		N03   , An3 , v127
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N03   , An3 
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N03   , An3 
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N03   , An3 
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W12
	.byte	PEND
	.byte		PAN   , c_v+32
	.byte		N03   , An3 
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N03   , Dn4 
	.byte	W12
	.byte		N06   , En4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N03   , Fn4 
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N03   , Dn4 
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
mus_rg_ohkido_3_002:
	.byte		PAN   , c_v+32
	.byte		N03   , Gn3 , v127
	.byte	W12
	.byte		N06   , As3 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N03   , Gn3 
	.byte	W12
	.byte		N06   , As3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N03   , Gn3 
	.byte	W12
	.byte		N06   , As3 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N03   , Gn3 
	.byte	W12
	.byte		N06   , As3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_ohkido_3_002
	.byte	PATT
	 .word	mus_rg_ohkido_3_001
	.byte		PAN   , c_v+32
	.byte		VOL   , 50*mus_rg_ohkido_mvl/mxv
	.byte		N03   , An3 , v127
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N03   , Dn4 
	.byte	W12
	.byte		N06   , En4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N03   , Fn4 
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N03   , Dn4 
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_ohkido_3_B1
	.byte		VOL   , 45*mus_rg_ohkido_mvl/mxv
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_ohkido_4:
	.byte	KEYSH , mus_rg_ohkido_key+0
	.byte		VOICE , 81
	.byte		PAN   , c_v+0
	.byte		VOL   , 59*mus_rg_ohkido_mvl/mxv
	.byte	W96
mus_rg_ohkido_4_000:
	.byte		N36   , Fn1 , v127
	.byte	W36
	.byte		N24   , Cn2 
	.byte	W24
	.byte		N03   , Fn2 
	.byte	W12
	.byte		N18   , Fn1 
	.byte	W24
	.byte	PEND
mus_rg_ohkido_4_001:
	.byte		N36   , Fn1 , v127
	.byte	W36
	.byte		N24   , Cn2 
	.byte	W24
	.byte		N03   , Fn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W12
	.byte	PEND
	.byte		N36   
	.byte	W36
	.byte		N24   , En1 
	.byte	W24
	.byte		N03   , Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
mus_rg_ohkido_4_002:
	.byte		N36   , Fn1 , v127
	.byte	W36
	.byte		N24   , En1 
	.byte	W24
	.byte		N03   , Gn1 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_ohkido_4_000
	.byte	PATT
	 .word	mus_rg_ohkido_4_001
	.byte	PATT
	 .word	mus_rg_ohkido_4_002
	.byte		N36   , Fn1 , v127
	.byte	W36
	.byte		N24   , En1 
	.byte	W24
	.byte		N06   , Gn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
mus_rg_ohkido_4_B1:
	.byte		VOICE , 83
	.byte		VOL   , 56*mus_rg_ohkido_mvl/mxv
	.byte		N24   , Gn1 , v127
	.byte	W24
	.byte		N03   , Dn2 
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W24
	.byte		N03   , As1 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		N03   , Dn2 
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W24
	.byte		N03   , As1 
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N03   , En1 
	.byte	W12
mus_rg_ohkido_4_003:
	.byte		N24   , Gn1 , v127
	.byte	W24
	.byte		N03   , Fn2 , v120
	.byte	W12
	.byte		N24   , Fn1 , v127
	.byte	W24
	.byte		N03   , An1 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_ohkido_4_003
	.byte		N24   , Fn1 , v127
	.byte	W24
	.byte		N03   , En2 , v120
	.byte	W12
	.byte		N24   , En1 , v127
	.byte	W24
	.byte		N03   , Gn1 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		        Fn1 
	.byte	W24
	.byte		N03   , En2 , v120
	.byte	W12
	.byte		N24   , En1 , v127
	.byte	W24
	.byte		N03   , Cn2 
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N03   , Gn1 , v120
	.byte	W12
	.byte		N24   , Gn1 , v127
	.byte	W24
	.byte		N03   , Cn2 , v120
	.byte	W12
	.byte		N24   , Fn1 , v127
	.byte	W24
	.byte		N03   , An1 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte	PATT
	 .word	mus_rg_ohkido_4_003
	.byte	GOTO
	 .word	mus_rg_ohkido_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_ohkido_5:
	.byte	KEYSH , mus_rg_ohkido_key+0
	.byte		VOICE , 58
	.byte		PAN   , c_v+0
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte	W96
	.byte		VOL   , 27*mus_rg_ohkido_mvl/mxv
	.byte		N12   , Fn3 , v120
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , An3 
	.byte	W06
	.byte		N03   , As3 , v088
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N12   , Gn3 , v120
	.byte	W12
	.byte		N09   , Fn3 
	.byte	W09
	.byte		N03   , Cs4 
	.byte	W03
	.byte		N60   , Cn4 
	.byte	W24
	.byte		MOD   , 4
	.byte	W12
	.byte		VOL   , 23*mus_rg_ohkido_mvl/mxv
	.byte	W06
	.byte		        20*mus_rg_ohkido_mvl/mxv
	.byte	W06
	.byte		        18*mus_rg_ohkido_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_ohkido_mvl/mxv
	.byte	W06
	.byte		        27*mus_rg_ohkido_mvl/mxv
	.byte		N06   , As3 
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		N03   , Cn4 , v096
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		N24   , An3 , v120
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N03   , Gs3 , v088
	.byte	W03
	.byte		N21   , Gn3 , v120
	.byte	W09
	.byte		MOD   , 4
	.byte	W12
	.byte		VOICE , 73
	.byte		VOL   , 43*mus_rg_ohkido_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N24   , Fn4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   , As4 
	.byte	W12
	.byte		N03   , Bn4 , v092
	.byte	W03
	.byte		N21   , As4 , v120
	.byte	W09
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , An3 
	.byte	W06
	.byte		N03   , As3 , v096
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N24   , Gn3 , v120
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N24   , Cn5 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , An4 
	.byte	W06
	.byte		N03   , As4 , v096
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		N12   , Gn4 , v120
	.byte	W12
	.byte		N09   , Fn4 
	.byte	W09
	.byte		N03   , Cs5 , v092
	.byte	W03
	.byte		N60   , Cn5 , v120
	.byte	W24
	.byte		MOD   , 4
	.byte	W12
	.byte		VOL   , 37*mus_rg_ohkido_mvl/mxv
	.byte	W06
	.byte		        31*mus_rg_ohkido_mvl/mxv
	.byte	W06
	.byte		        23*mus_rg_ohkido_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_ohkido_mvl/mxv
	.byte	W06
	.byte		        42*mus_rg_ohkido_mvl/mxv
	.byte		N12   , Gn4 
	.byte	W03
	.byte		MOD   , 0
	.byte	W09
	.byte		N03   , Fn4 , v088
	.byte	W03
	.byte		N21   , En4 , v120
	.byte	W21
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N24   , Fn4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   , As4 
	.byte	W12
	.byte		N03   , Bn4 , v088
	.byte	W03
	.byte		N21   , As4 , v120
	.byte	W09
	.byte		MOD   , 4
	.byte	W12
mus_rg_ohkido_5_B1:
	.byte		VOICE , 21
	.byte		VOL   , 54*mus_rg_ohkido_mvl/mxv
	.byte		PAN   , c_v-17
	.byte		MOD   , 0
	.byte		N36   , Fn3 , v120
	.byte	W24
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N36   , As3 
	.byte	W24
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn3 , v096
	.byte	W12
	.byte		        Dn4 , v120
	.byte	W12
	.byte		        As3 , v096
	.byte	W12
	.byte		        Dn4 , v120
	.byte	W12
	.byte		N03   , Gs3 , v096
	.byte	W03
	.byte		N09   , Gn3 , v120
	.byte	W09
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N36   , Fn3 
	.byte	W24
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , Cn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N36   , An3 
	.byte	W24
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		VOICE , 73
	.byte		N36   , En3 
	.byte	W24
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , Cn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N36   , Gn3 
	.byte	W24
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 , v096
	.byte	W12
	.byte		        Cn4 , v120
	.byte	W12
	.byte		        As3 , v096
	.byte	W12
	.byte		        Cn4 , v120
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N36   , An3 
	.byte	W24
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N36   , Cn4 
	.byte	W24
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_ohkido_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_ohkido_6:
	.byte	KEYSH , mus_rg_ohkido_key+0
	.byte		VOICE , 80
	.byte		PAN   , c_v+0
	.byte		VOL   , 37*mus_rg_ohkido_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_ohkido_6_B1:
	.byte		PAN   , c_v-59
	.byte		N06   , Fn5 , v080
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , As5 , v120
	.byte	W36
	.byte		PAN   , c_v+63
	.byte		N06   , An5 , v084
	.byte	W09
	.byte		PAN   , c_v-61
	.byte	W03
	.byte		N06   , As5 , v120
	.byte	W36
	.byte		        Fn5 , v084
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , As5 , v120
	.byte	W12
	.byte		        Dn5 , v076
	.byte	W12
	.byte		PAN   , c_v-61
	.byte		N06   , As5 , v120
	.byte	W12
	.byte		        As4 , v080
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , As5 , v120
	.byte	W36
mus_rg_ohkido_6_000:
	.byte		PAN   , c_v-59
	.byte		N06   , Cn5 , v080
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Fn5 , v120
	.byte	W36
	.byte		PAN   , c_v+63
	.byte		N06   , En5 , v084
	.byte	W09
	.byte		PAN   , c_v-61
	.byte	W03
	.byte		N06   , Fn5 , v120
	.byte	W36
	.byte	PEND
mus_rg_ohkido_6_001:
	.byte		N06   , Cn5 , v084
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Fn5 , v120
	.byte	W12
	.byte		        An4 , v076
	.byte	W12
	.byte		PAN   , c_v-61
	.byte		N06   , Fn5 , v120
	.byte	W12
	.byte		        Fn4 , v080
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Fn5 , v120
	.byte	W12
	.byte		        En5 , v072
	.byte	W12
	.byte		        Fn5 , v120
	.byte	W03
	.byte		PAN   , c_v-61
	.byte	W09
	.byte	PEND
	.byte		        c_v-59
	.byte		N06   , Cn5 , v080
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Gn5 , v120
	.byte	W36
	.byte		PAN   , c_v+63
	.byte		N06   , Fs5 , v084
	.byte	W09
	.byte		PAN   , c_v-61
	.byte	W03
	.byte		N06   , Gn5 , v120
	.byte	W36
	.byte		        Cn5 , v084
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Gn5 , v120
	.byte	W12
	.byte		        Fs5 , v076
	.byte	W12
	.byte		PAN   , c_v-61
	.byte		N06   , Gn5 , v120
	.byte	W12
	.byte		        En5 , v080
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Gn5 , v120
	.byte	W36
	.byte	PATT
	 .word	mus_rg_ohkido_6_000
	.byte	PATT
	 .word	mus_rg_ohkido_6_001
	.byte	GOTO
	 .word	mus_rg_ohkido_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_rg_ohkido_7:
	.byte	KEYSH , mus_rg_ohkido_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 68*mus_rg_ohkido_mvl/mxv
	.byte	W84
	.byte		N06   , Dn3 , v120
	.byte	W06
	.byte		        Dn3 , v092
	.byte	W06
mus_rg_ohkido_7_000:
	.byte		N06   , En3 , v120
	.byte	W24
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Dn3 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
mus_rg_ohkido_7_001:
	.byte		N06   , En3 , v120
	.byte	W24
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W24
	.byte		        Dn3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn3 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_ohkido_7_000
	.byte		N06   , En3 , v120
	.byte	W24
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 , v096
	.byte	W12
	.byte		        Dn3 , v120
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn3 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PATT
	 .word	mus_rg_ohkido_7_000
	.byte	PATT
	 .word	mus_rg_ohkido_7_001
	.byte	PATT
	 .word	mus_rg_ohkido_7_000
	.byte		N06   , En3 , v120
	.byte	W24
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Bn1 
	.byte		N06   , Dn3 , v096
	.byte	W12
	.byte		        Fn1 , v127
	.byte		N06   , Dn3 
	.byte	W12
	.byte		        Cn1 , v120
	.byte		N06   , Dn3 
	.byte	W12
	.byte		        Dn1 , v127
	.byte	W06
	.byte		        Dn1 , v104
	.byte	W06
mus_rg_ohkido_7_B1:
mus_rg_ohkido_7_002:
	.byte		N06   , Cn1 , v120
	.byte	W24
	.byte		        Gs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W24
	.byte		        Gs1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v096
	.byte	W06
	.byte	PEND
	.byte		        Cn1 , v120
	.byte	W24
	.byte		        Gs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_ohkido_7_002
	.byte		N06   , Cn1 , v120
	.byte	W24
	.byte		        Gs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W24
	.byte		        Gs1 , v100
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Gs1 
	.byte	W06
	.byte		        Cn1 , v096
	.byte	W06
	.byte	PATT
	 .word	mus_rg_ohkido_7_002
	.byte		N06   , Cn1 , v120
	.byte	W24
	.byte		        Gs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Fn1 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_ohkido_7_002
	.byte		N06   , Cn1 , v120
	.byte	W24
	.byte		        Gs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W24
	.byte		        Gs1 
	.byte	W12
	.byte		        Cn2 , v100
	.byte	W12
	.byte		        An1 , v120
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_ohkido_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_rg_ohkido_8:
	.byte	KEYSH , mus_rg_ohkido_key+0
	.byte		VOICE , 127
	.byte		PAN   , c_v+0
	.byte		VOL   , 38*mus_rg_ohkido_mvl/mxv
	.byte	W48
	.byte		N06   , Cn5 , v088
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v108
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
mus_rg_ohkido_8_000:
	.byte		N06   , Cn5 , v088
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v108
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v088
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v108
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_ohkido_8_000
	.byte	PATT
	 .word	mus_rg_ohkido_8_000
	.byte	PATT
	 .word	mus_rg_ohkido_8_000
	.byte	PATT
	 .word	mus_rg_ohkido_8_000
	.byte	PATT
	 .word	mus_rg_ohkido_8_000
	.byte	PATT
	 .word	mus_rg_ohkido_8_000
	.byte	PATT
	 .word	mus_rg_ohkido_8_000
mus_rg_ohkido_8_B1:
mus_rg_ohkido_8_001:
	.byte		N06   , Cn5 , v120
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn5 , v104
	.byte	W06
	.byte	PEND
mus_rg_ohkido_8_002:
	.byte		N06   , Cn5 , v120
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Cn5 , v104
	.byte	W18
	.byte		        Cn5 , v120
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_ohkido_8_001
	.byte	PATT
	 .word	mus_rg_ohkido_8_002
	.byte	PATT
	 .word	mus_rg_ohkido_8_001
	.byte		N06   , Cn5 , v120
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Cn5 , v104
	.byte	W42
	.byte	PATT
	 .word	mus_rg_ohkido_8_001
	.byte		N06   , Cn5 , v120
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte	GOTO
	 .word	mus_rg_ohkido_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_rg_ohkido_9:
	.byte	KEYSH , mus_rg_ohkido_key+0
	.byte		VOICE , 126
	.byte		PAN   , c_v+0
	.byte		VOL   , 38*mus_rg_ohkido_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_ohkido_9_B1:
mus_rg_ohkido_9_000:
	.byte	W12
	.byte		N12   , Gn5 , v120
	.byte	W48
	.byte		N12   
	.byte	W36
	.byte	PEND
mus_rg_ohkido_9_001:
	.byte	W12
	.byte		N12   , Gn5 , v120
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_ohkido_9_000
	.byte	PATT
	 .word	mus_rg_ohkido_9_001
	.byte	PATT
	 .word	mus_rg_ohkido_9_000
	.byte	PATT
	 .word	mus_rg_ohkido_9_001
	.byte	PATT
	 .word	mus_rg_ohkido_9_000
	.byte	W12
	.byte		N12   , Gn5 , v120
	.byte	W72
	.byte		N12   
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_ohkido_9_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_ohkido:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_ohkido_pri	@ Priority
	.byte	mus_rg_ohkido_rev	@ Reverb.

	.word	mus_rg_ohkido_grp

	.word	mus_rg_ohkido_1
	.word	mus_rg_ohkido_2
	.word	mus_rg_ohkido_3
	.word	mus_rg_ohkido_4
	.word	mus_rg_ohkido_5
	.word	mus_rg_ohkido_6
	.word	mus_rg_ohkido_7
	.word	mus_rg_ohkido_8
	.word	mus_rg_ohkido_9

	.end
