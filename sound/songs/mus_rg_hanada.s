	.include "MPlayDef.s"

	.equ	mus_rg_hanada_grp, voicegroup_86AD138
	.equ	mus_rg_hanada_pri, 0
	.equ	mus_rg_hanada_rev, reverb_set+50
	.equ	mus_rg_hanada_mvl, 127
	.equ	mus_rg_hanada_key, 0
	.equ	mus_rg_hanada_tbs, 1
	.equ	mus_rg_hanada_exg, 0
	.equ	mus_rg_hanada_cmp, 1

	.section .rodata
	.global	mus_rg_hanada
	.align	2

@********************** Track  1 **********************@

mus_rg_hanada_1:
	.byte	KEYSH , mus_rg_hanada_key+0
	.byte	TEMPO , 120*mus_rg_hanada_tbs/2
	.byte		VOICE , 17
	.byte		PAN   , c_v+0
	.byte		VOL   , 90*mus_rg_hanada_mvl/mxv
	.byte		N12   , Fn5 , v084
	.byte	W12
	.byte		N03   , En5 
	.byte	W12
	.byte		N12   , Dn5 
	.byte	W12
	.byte		N03   , Cn5 
	.byte	W12
	.byte		N12   , As4 
	.byte	W12
	.byte		N03   , Cn5 
	.byte	W12
	.byte		N12   , Dn5 
	.byte	W12
	.byte		N03   , En5 
	.byte	W12
mus_rg_hanada_1_B1:
	.byte		N36   , Fn5 , v084
	.byte	W09
	.byte		MOD   , 6
	.byte	W24
	.byte	W03
	.byte		        0
	.byte		N06   
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		N06   , Fn5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		N36   , An5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		N06   , As5 
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		N06   , An5 
	.byte	W06
	.byte		N84   , Gn5 
	.byte	W12
	.byte		VOL   , 79*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 68*mus_rg_hanada_mvl/mxv
	.byte	W12
	.byte		        56*mus_rg_hanada_mvl/mxv
	.byte	W12
	.byte		        45*mus_rg_hanada_mvl/mxv
	.byte	W12
	.byte		        34*mus_rg_hanada_mvl/mxv
	.byte	W12
	.byte		        22*mus_rg_hanada_mvl/mxv
	.byte	W12
	.byte		        90*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Fn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		N06   , Fn5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		N36   , An5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		N06   , Gn5 
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		N06   , An5 
	.byte	W06
	.byte		N84   , Cn6 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 79*mus_rg_hanada_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_hanada_mvl/mxv
	.byte	W12
	.byte		        56*mus_rg_hanada_mvl/mxv
	.byte	W12
	.byte		        45*mus_rg_hanada_mvl/mxv
	.byte	W12
	.byte		        34*mus_rg_hanada_mvl/mxv
	.byte	W12
	.byte		VOICE , 24
	.byte		MOD   , 0
	.byte		VOL   , 64*mus_rg_hanada_mvl/mxv
	.byte		N06   , Fn4 , v127
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W12
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N36   , An4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		N06   , As4 
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		N06   , An4 
	.byte	W06
	.byte		N48   , Gn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte	W03
	.byte		        0
	.byte	W09
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        An3 , v092
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v096
	.byte	W06
	.byte		        An3 , v108
	.byte	W12
	.byte		N06   , Fn4 , v127
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W12
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N36   , An4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		N06   , Fn4 
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		N06   , An4 
	.byte	W06
	.byte		N48   , Cn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N24   , Fn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , An4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Fn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Cn5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N12   , An4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N48   , Cn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N48   , Fn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W36
	.byte		        0
	.byte		N24   , Cn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , An3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , As3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N48   , Cn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W36
	.byte		        0
	.byte		N48   
	.byte	W12
	.byte		MOD   , 6
	.byte	W36
	.byte		        0
	.byte		N24   , An3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		VOICE , 17
	.byte		VOL   , 90*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Fn5 , v084
	.byte	W12
	.byte		N03   , En5 
	.byte	W03
	.byte		        Fn5 , v068
	.byte	W03
	.byte		N06   , En5 
	.byte	W06
	.byte		        Dn5 , v084
	.byte	W12
	.byte		N12   , En5 
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_hanada_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_hanada_2:
	.byte	KEYSH , mus_rg_hanada_key+0
	.byte		VOICE , 21
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+32
	.byte		VOL   , 47*mus_rg_hanada_mvl/mxv
	.byte	W48
	.byte		N12   , Fn4 , v127
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
mus_rg_hanada_2_B1:
	.byte		N12   , Cn4 , v127
	.byte	W96
	.byte		N24   
	.byte	W24
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N06   , En4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N48   , An3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W36
	.byte		        0
	.byte		N48   , Fn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W36
	.byte		        0
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        As3 , v120
	.byte	W12
	.byte		        An3 , v127
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N36   , Cn4 , v120
	.byte	W12
	.byte		VOL   , 34*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 23*mus_rg_hanada_mvl/mxv
	.byte	W12
	.byte		        11*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 0
	.byte	W12
	.byte		VOL   , 47*mus_rg_hanada_mvl/mxv
	.byte	W48
	.byte		N24   , Dn4 , v127
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N03   , Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v108
	.byte	W06
	.byte		        Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W24
	.byte		N48   , An3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W24
	.byte		N24   , Fn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W24
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Fn3 
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		        As3 
	.byte	W24
	.byte		        Cn4 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N96   , Fn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W84
	.byte		        0
	.byte		N48   , Gn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W36
	.byte		        0
	.byte		N24   , An3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_hanada_2_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_hanada_3:
	.byte	KEYSH , mus_rg_hanada_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 24*mus_rg_hanada_mvl/mxv
	.byte	W96
mus_rg_hanada_3_B1:
	.byte		PAN   , c_v-64
	.byte		VOL   , 24*mus_rg_hanada_mvl/mxv
	.byte		N12   , Fn3 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N01   , An3 
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N01   , An3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Fn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N01   , An3 
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N01   , An3 
	.byte	W12
mus_rg_hanada_3_000:
	.byte		N12   , Gn3 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N03   , As3 
	.byte	W12
	.byte		N12   , Gn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N03   , As3 
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N03   , As3 
	.byte	W12
	.byte		N12   , An3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N03   , Gn3 
	.byte	W12
	.byte	PEND
mus_rg_hanada_3_001:
	.byte		N12   , Fn3 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N03   , An3 
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N03   , An3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Fn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N03   , An3 
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N03   , An3 
	.byte	W12
	.byte	PEND
	.byte		N12   , Fn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N03   , An3 
	.byte	W12
	.byte		N12   , Gn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N03   , As3 
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N03   , As3 
	.byte	W12
	.byte		N12   , Gn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N03   , En3 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_hanada_3_001
	.byte	PATT
	 .word	mus_rg_hanada_3_000
	.byte		VOL   , 22*mus_rg_hanada_mvl/mxv
	.byte		N12   , Fn3 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N03   , An3 
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N03   , An3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Fn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N03   , An3 
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N03   , An3 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_hanada_3_000
	.byte		N12   , Fn3 , v127
	.byte	W12
	.byte		N03   , An3 
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W24
	.byte		PAN   , c_v+63
	.byte		N24   
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N03   , As3 
	.byte	W12
	.byte		N12   , Gn3 
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		N24   
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W36
	.byte		PAN   , c_v+63
	.byte		N12   , Fn3 
	.byte	W36
	.byte		PAN   , c_v-64
	.byte		N12   , An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W60
	.byte		PAN   , c_v+63
	.byte		N12   , As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Fn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N03   , An3 
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N03   , An3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Fn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N03   , An3 
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N03   , An3 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_hanada_3_000
	.byte	PATT
	 .word	mus_rg_hanada_3_001
	.byte	PATT
	 .word	mus_rg_hanada_3_000
	.byte	GOTO
	 .word	mus_rg_hanada_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_hanada_4:
	.byte	KEYSH , mus_rg_hanada_key+0
	.byte		VOICE , 81
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 48*mus_rg_hanada_mvl/mxv
	.byte	W96
mus_rg_hanada_4_B1:
	.byte		VOICE , 81
	.byte		N06   , Fn1 , v120
	.byte	W42
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W36
	.byte		N12   , En1 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W42
	.byte		N03   , Cn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W42
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , An1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   , As1 
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N03   , En1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N12   , En1 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W42
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W36
	.byte		N12   , En1 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W42
	.byte		N03   , Cn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W18
	.byte		N03   , Fn1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W36
	.byte		        As1 
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N06   , En1 
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		BEND  , c_v+0
	.byte		N24   
	.byte	W06
	.byte		BEND  , c_v+10
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , Fn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N12   , Fn1 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        An1 
	.byte	W06
	.byte		BEND  , c_v+5
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , Gn2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Dn2 
	.byte	W36
	.byte		        As1 
	.byte	W36
	.byte		        Gn1 
	.byte	W24
	.byte		N18   , Cn1 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N36   
	.byte	W12
	.byte		VOL   , 34*mus_rg_hanada_mvl/mxv
	.byte	W06
	.byte		        22*mus_rg_hanada_mvl/mxv
	.byte	W06
	.byte		        17*mus_rg_hanada_mvl/mxv
	.byte	W06
	.byte		        11*mus_rg_hanada_mvl/mxv
	.byte	W06
	.byte		VOICE , 82
	.byte		VOL   , 48*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+1
	.byte		N48   , Fn5 , v048
	.byte	W12
	.byte		VOL   , 34*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 22*mus_rg_hanada_mvl/mxv
	.byte	W12
	.byte		        11*mus_rg_hanada_mvl/mxv
	.byte	W06
	.byte		        4*mus_rg_hanada_mvl/mxv
	.byte	W06
	.byte		        48*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Cn5 
	.byte	W12
	.byte		VOL   , 34*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 48*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Gn5 
	.byte	W12
	.byte		VOL   , 33*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 48*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , An5 
	.byte	W12
	.byte		VOL   , 33*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 48*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , As5 
	.byte	W12
	.byte		VOL   , 33*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 48*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , Cn6 
	.byte	W12
	.byte		VOL   , 33*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 22*mus_rg_hanada_mvl/mxv
	.byte	W12
	.byte		        11*mus_rg_hanada_mvl/mxv
	.byte	W06
	.byte		        4*mus_rg_hanada_mvl/mxv
	.byte	W06
	.byte		        48*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   
	.byte	W12
	.byte		VOL   , 33*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 21*mus_rg_hanada_mvl/mxv
	.byte	W12
	.byte		        11*mus_rg_hanada_mvl/mxv
	.byte	W06
	.byte		        4*mus_rg_hanada_mvl/mxv
	.byte	W06
	.byte		        48*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , An5 
	.byte	W12
	.byte		VOL   , 33*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 48*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , En6 
	.byte	W12
	.byte		VOL   , 33*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 48*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Dn6 
	.byte	W12
	.byte		VOL   , 33*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 48*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , En6 
	.byte	W12
	.byte		VOL   , 33*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 47*mus_rg_hanada_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Fn5 
	.byte	W12
	.byte		N03   , En5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		N06   , En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W12
	.byte		N12   , En5 
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_hanada_4_B1
	.byte		BEND  , c_v+0
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_hanada_5:
	.byte	KEYSH , mus_rg_hanada_key+0
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-30
	.byte		VOL   , 42*mus_rg_hanada_mvl/mxv
	.byte	W72
	.byte		N12   , Dn4 , v120
	.byte	W12
	.byte		N03   , En4 
	.byte	W12
mus_rg_hanada_5_B1:
mus_rg_hanada_5_000:
	.byte		N06   , Fn4 , v120
	.byte	W06
	.byte		N03   , En4 , v092
	.byte	W03
	.byte		        Dn4 , v076
	.byte	W03
	.byte		        Cn4 , v064
	.byte	W03
	.byte		        As3 , v052
	.byte	W03
	.byte		        An3 , v048
	.byte	W03
	.byte		        Gn3 , v044
	.byte	W72
	.byte	W03
	.byte	PEND
	.byte		        Cn4 , v120
	.byte	W18
	.byte		        Dn4 
	.byte	W18
	.byte		        En4 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Cn4 
	.byte	W18
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_hanada_5_000
	.byte		N03   , Fn4 , v120
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_hanada_5_000
	.byte		VOL   , 21*mus_rg_hanada_mvl/mxv
	.byte		N24   , Dn4 , v120
	.byte	W06
	.byte		VOL   , 31*mus_rg_hanada_mvl/mxv
	.byte	W06
	.byte		        38*mus_rg_hanada_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_hanada_mvl/mxv
	.byte	W06
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N03   , En4 
	.byte	W06
	.byte		VOL   , 21*mus_rg_hanada_mvl/mxv
	.byte		N24   , Dn4 
	.byte	W06
	.byte		VOL   , 33*mus_rg_hanada_mvl/mxv
	.byte	W06
	.byte		        38*mus_rg_hanada_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_hanada_mvl/mxv
	.byte	W06
	.byte		N24   , Cn4 
	.byte	W06
	.byte		VOL   , 34*mus_rg_hanada_mvl/mxv
	.byte	W06
	.byte		        22*mus_rg_hanada_mvl/mxv
	.byte	W06
	.byte		        10*mus_rg_hanada_mvl/mxv
	.byte	W06
	.byte		        43*mus_rg_hanada_mvl/mxv
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , En4 , v092
	.byte	W03
	.byte		        Dn4 , v076
	.byte	W03
	.byte		        Cn4 , v064
	.byte	W03
	.byte		        As3 , v052
	.byte	W03
	.byte		        An3 , v048
	.byte	W03
	.byte		        Gn3 , v044
	.byte	W48
	.byte	W03
	.byte		        Fn4 , v120
	.byte	W18
	.byte		        En4 
	.byte	W18
	.byte		        Fn4 
	.byte	W18
	.byte		        Gn4 
	.byte	W18
	.byte		        Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N06   , An4 
	.byte	W06
	.byte		N03   , Gs4 , v092
	.byte	W03
	.byte		        Fs4 , v076
	.byte	W03
	.byte		        En4 , v064
	.byte	W03
	.byte		        Dn4 , v052
	.byte	W03
	.byte		        Cs4 , v048
	.byte	W03
	.byte		        Bn3 , v044
	.byte	W72
	.byte	W03
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_hanada_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_hanada_6:
	.byte	KEYSH , mus_rg_hanada_key+0
	.byte		VOICE , 84
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 41*mus_rg_hanada_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W72
	.byte		N12   , As3 , v120
	.byte	W12
	.byte		N03   , Gn3 
	.byte	W12
mus_rg_hanada_6_B1:
mus_rg_hanada_6_000:
	.byte		N06   , An3 , v120
	.byte	W06
	.byte		N03   , Gn3 , v096
	.byte	W03
	.byte		        Fn3 , v076
	.byte	W03
	.byte		        En3 , v064
	.byte	W03
	.byte		        Dn3 , v060
	.byte	W03
	.byte		        Cn3 , v052
	.byte	W03
	.byte		        As2 , v048
	.byte	W72
	.byte	W03
	.byte	PEND
	.byte		        Fn3 , v120
	.byte	W18
	.byte		        Gn3 
	.byte	W18
	.byte		        An3 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Fn3 
	.byte	W18
	.byte		        Gn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_hanada_6_000
	.byte		N03   , Cn4 , v120
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_hanada_6_000
	.byte		N24   , Fn3 , v120
	.byte	W24
	.byte		N03   , En3 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		N03   , Cn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , As3 , v096
	.byte	W03
	.byte		        Gs3 , v076
	.byte	W03
	.byte		        Gn3 , v064
	.byte	W03
	.byte		        Fn3 , v060
	.byte	W03
	.byte		        Ds3 , v052
	.byte	W03
	.byte		        Cs3 , v048
	.byte	W48
	.byte	W03
	.byte		        Cn4 , v120
	.byte	W18
	.byte		        Bn3 
	.byte	W18
	.byte		        Cn4 
	.byte	W18
	.byte		        Dn4 
	.byte	W18
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , En4 , v096
	.byte	W03
	.byte		        Dn4 , v076
	.byte	W03
	.byte		        Cn4 , v064
	.byte	W03
	.byte		        As3 , v060
	.byte	W03
	.byte		        An3 , v052
	.byte	W03
	.byte		        Gn3 , v048
	.byte	W72
	.byte	W03
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_hanada_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_rg_hanada_7:
	.byte	KEYSH , mus_rg_hanada_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 50*mus_rg_hanada_mvl/mxv
	.byte	W42
	.byte		N03   , En1 , v100
	.byte	W03
	.byte		        En1 , v088
	.byte	W03
	.byte		N06   , En1 , v120
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn1 , v112
	.byte	W12
mus_rg_hanada_7_B1:
mus_rg_hanada_7_000:
	.byte		N06   , Cn1 , v120
	.byte	W24
	.byte		        Cs1 , v100
	.byte	W18
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Cn1 , v124
	.byte	W24
	.byte		        Cs1 , v100
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte	PEND
mus_rg_hanada_7_001:
	.byte		N06   , Cn1 , v120
	.byte	W24
	.byte		        Cs1 , v100
	.byte	W18
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Cn1 , v124
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Cs1 , v100
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte	PEND
mus_rg_hanada_7_002:
	.byte		N06   , Cn1 , v120
	.byte	W24
	.byte		        Cs1 , v100
	.byte	W18
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Cn1 , v124
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Cs1 , v100
	.byte	W24
	.byte	PEND
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Cs1 , v112
	.byte	W12
	.byte		N03   , Cs1 , v100
	.byte	W03
	.byte		        Cs1 , v092
	.byte	W03
	.byte		N06   , Cs1 , v120
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 , v100
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Cs1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn1 , v112
	.byte	W12
	.byte	PATT
	 .word	mus_rg_hanada_7_000
	.byte	PATT
	 .word	mus_rg_hanada_7_001
	.byte		N06   , Cn1 , v120
	.byte	W06
	.byte		        Cs1 , v100
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Cs1 , v100
	.byte	W18
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Cn1 , v124
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Cs1 , v100
	.byte	W24
	.byte		        Cn1 , v120
	.byte	W24
	.byte		        Cs1 , v100
	.byte	W18
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Cs1 , v100
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Cs1 , v100
	.byte	W06
	.byte		        Cs1 , v092
	.byte	W06
	.byte		        Fn1 , v108
	.byte	W12
	.byte		        Cs1 , v120
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Fn1 , v112
	.byte	W18
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Cn1 , v124
	.byte	W24
	.byte		        Cs1 , v100
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cs1 , v100
	.byte	W18
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Cn1 , v124
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Cs1 , v100
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		        Cs1 , v100
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Cs1 , v100
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Cs1 , v100
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Cs1 , v100
	.byte	W06
	.byte	PATT
	 .word	mus_rg_hanada_7_002
	.byte		N06   , En3 , v096
	.byte		N03   , Gs4 , v080
	.byte	W12
	.byte		N06   , Gs2 , v076
	.byte		N03   , Gs4 , v044
	.byte	W12
	.byte		N06   , Dn3 , v120
	.byte		N24   , An4 , v088
	.byte	W24
	.byte		N06   , En3 , v096
	.byte		N03   , Gs4 , v080
	.byte	W12
	.byte		N06   , Gs2 , v076
	.byte		N03   , Gs4 , v044
	.byte	W12
	.byte		N06   , Dn3 , v120
	.byte		N12   , An4 , v088
	.byte	W12
	.byte		N03   , An4 , v032
	.byte	W12
	.byte		N06   , En3 , v096
	.byte		N03   , Gs4 , v080
	.byte	W12
	.byte		N06   , Gs2 , v076
	.byte		N03   , Gs4 , v044
	.byte	W12
	.byte		N06   , Dn3 , v120
	.byte		N24   , An4 , v088
	.byte	W12
	.byte		N06   , Gs2 , v076
	.byte	W12
	.byte		        En3 , v096
	.byte		N03   , Gs4 , v080
	.byte	W12
	.byte		N06   , Gs2 , v076
	.byte		N03   , Gs4 , v044
	.byte	W12
	.byte		N06   , Dn3 , v120
	.byte		N12   , An4 , v088
	.byte	W12
	.byte		N03   , An4 , v032
	.byte	W12
	.byte		N06   , En3 , v096
	.byte		N03   , Gs4 , v080
	.byte	W12
	.byte		N06   , Gs2 , v076
	.byte		N03   , Gs4 , v044
	.byte	W12
	.byte		N06   , Dn3 , v120
	.byte		N12   , An4 , v088
	.byte	W12
	.byte		N06   , Gs2 , v076
	.byte		N03   , An4 , v032
	.byte	W12
	.byte		N06   , En3 , v096
	.byte		N03   , Gs4 , v080
	.byte	W12
	.byte		N06   , Gs2 , v076
	.byte		N03   , Gs4 , v044
	.byte	W12
	.byte		N06   , Dn3 , v120
	.byte		N12   , An4 , v088
	.byte	W12
	.byte		N03   , An4 , v032
	.byte	W12
	.byte		N06   , En3 , v096
	.byte		N03   , Gs4 , v080
	.byte	W12
	.byte		N06   , Gs2 , v076
	.byte		N03   , Gs4 , v044
	.byte	W12
	.byte		N06   , Dn3 , v120
	.byte		N24   , An4 , v088
	.byte	W24
	.byte		N06   , Dn2 , v120
	.byte	W12
	.byte		        Fn1 , v112
	.byte	W12
	.byte		        En1 , v120
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_hanada_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_rg_hanada_8:
	.byte	KEYSH , mus_rg_hanada_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 39*mus_rg_hanada_mvl/mxv
	.byte	W48
	.byte		N03   , Cn5 , v092
	.byte	W24
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v092
	.byte	W18
mus_rg_hanada_8_B1:
mus_rg_hanada_8_000:
	.byte		N03   , Cn5 , v092
	.byte	W24
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_hanada_8_000
	.byte	PATT
	 .word	mus_rg_hanada_8_000
	.byte		N03   , Cn5 , v092
	.byte	W24
	.byte		        Cn5 , v120
	.byte	W24
	.byte		        Cn5 , v092
	.byte	W24
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte	PATT
	 .word	mus_rg_hanada_8_000
	.byte	PATT
	 .word	mus_rg_hanada_8_000
	.byte	PATT
	 .word	mus_rg_hanada_8_000
	.byte	PATT
	 .word	mus_rg_hanada_8_000
	.byte	PATT
	 .word	mus_rg_hanada_8_000
	.byte	PATT
	 .word	mus_rg_hanada_8_000
	.byte	PATT
	 .word	mus_rg_hanada_8_000
	.byte	W24
	.byte		N03   , Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
mus_rg_hanada_8_001:
	.byte		N03   , Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v088
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v088
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v088
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v088
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_hanada_8_001
	.byte	PATT
	 .word	mus_rg_hanada_8_001
	.byte		N03   , Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v088
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v088
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W24
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_hanada_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_rg_hanada_9:
	.byte	KEYSH , mus_rg_hanada_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 25*mus_rg_hanada_mvl/mxv
	.byte	W60
	.byte		N12   , Gn5 , v120
	.byte	W24
	.byte		N12   
	.byte	W12
mus_rg_hanada_9_B1:
	.byte	W12
	.byte		N12   , Gn5 , v120
	.byte	W84
	.byte	W12
	.byte		N12   
	.byte	W84
	.byte	W12
	.byte		N12   
	.byte	W84
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte	W12
	.byte		N12   
	.byte	W84
	.byte	W12
	.byte		N12   
	.byte	W84
	.byte	W12
	.byte		N12   
	.byte	W84
	.byte	W12
	.byte		N12   
	.byte	W84
	.byte	W12
	.byte		N12   
	.byte	W84
	.byte	W12
	.byte		N12   
	.byte	W84
	.byte	W12
	.byte		N12   
	.byte	W84
	.byte		N24   
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W60
	.byte		N12   
	.byte	W36
	.byte	GOTO
	 .word	mus_rg_hanada_9_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_hanada:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_hanada_pri	@ Priority
	.byte	mus_rg_hanada_rev	@ Reverb.

	.word	mus_rg_hanada_grp

	.word	mus_rg_hanada_1
	.word	mus_rg_hanada_2
	.word	mus_rg_hanada_3
	.word	mus_rg_hanada_4
	.word	mus_rg_hanada_5
	.word	mus_rg_hanada_6
	.word	mus_rg_hanada_7
	.word	mus_rg_hanada_8
	.word	mus_rg_hanada_9

	.end
