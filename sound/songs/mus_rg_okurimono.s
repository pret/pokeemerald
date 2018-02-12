	.include "MPlayDef.s"

	.equ	mus_rg_okurimono_grp, voicegroup_86B1C44
	.equ	mus_rg_okurimono_pri, 0
	.equ	mus_rg_okurimono_rev, reverb_set+50
	.equ	mus_rg_okurimono_mvl, 127
	.equ	mus_rg_okurimono_key, 0
	.equ	mus_rg_okurimono_tbs, 1
	.equ	mus_rg_okurimono_exg, 0
	.equ	mus_rg_okurimono_cmp, 1

	.section .rodata
	.global	mus_rg_okurimono
	.align	2

@********************** Track  1 **********************@

mus_rg_okurimono_1:
	.byte	KEYSH , mus_rg_okurimono_key+0
	.byte	TEMPO , 124*mus_rg_okurimono_tbs/2
	.byte		VOICE , 24
	.byte		VOL   , 75*mus_rg_okurimono_mvl/mxv
	.byte		N04   , Cn4 , v120
	.byte	W24
	.byte		N20   
	.byte	W12
	.byte		MOD   , 7
	.byte	W08
	.byte		        0
	.byte	W04
	.byte		N16   
	.byte	W08
	.byte		MOD   , 7
	.byte	W08
	.byte		        0
	.byte		N02   , Bn3 
	.byte	W08
	.byte		N16   , Cn4 
	.byte	W08
	.byte		MOD   , 7
	.byte	W08
	.byte		N04   , Dn4 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
mus_rg_okurimono_1_B1:
mus_rg_okurimono_1_000:
	.byte		N04   , En4 , v120
	.byte	W16
	.byte		N01   , Gn3 
	.byte	W08
	.byte		N16   , En4 
	.byte	W06
	.byte		MOD   , 7
	.byte	W10
	.byte		N01   , Gn3 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
	.byte		N04   , Dn4 
	.byte	W16
	.byte		N01   , Gn3 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W06
	.byte		MOD   , 7
	.byte	W10
	.byte		N01   , Gn3 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
	.byte	PEND
	.byte		N16   , Cn4 
	.byte	W06
	.byte		MOD   , 7
	.byte	W10
	.byte		N01   , Gn3 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
	.byte		N16   , Cn4 
	.byte	W06
	.byte		MOD   , 7
	.byte	W10
	.byte		N01   , Gn3 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N04   , Bn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N16   , Cn4 
	.byte	W06
	.byte		MOD   , 7
	.byte	W10
	.byte		N01   , Gn3 
	.byte		N04   , Dn4 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
	.byte	PATT
	 .word	mus_rg_okurimono_1_000
	.byte		N16   , Cn4 , v120
	.byte	W06
	.byte		MOD   , 7
	.byte	W10
	.byte		N01   , Gn3 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
	.byte		N16   , Cn4 
	.byte	W06
	.byte		MOD   , 7
	.byte	W10
	.byte		N01   , Gn3 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
	.byte		N04   , Cn4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		N02   , An3 
	.byte	W08
	.byte		N16   , Cn4 
	.byte	W06
	.byte		MOD   , 7
	.byte	W10
	.byte		N01   , Gn3 
	.byte		N04   , Dn4 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
	.byte		N04   , Fn4 
	.byte	W16
	.byte		N01   , An3 
	.byte	W08
	.byte		N16   , Fn4 
	.byte	W06
	.byte		MOD   , 7
	.byte	W10
	.byte		N01   , An3 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
	.byte		N04   , En4 
	.byte	W16
	.byte		N01   , An3 
	.byte	W08
	.byte		N16   , En4 
	.byte	W06
	.byte		MOD   , 7
	.byte	W10
	.byte		N01   , An3 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
	.byte		N16   , Dn4 
	.byte	W06
	.byte		MOD   , 7
	.byte	W10
	.byte		N01   , An3 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
	.byte		N16   , Dn4 
	.byte	W06
	.byte		MOD   , 7
	.byte	W10
	.byte		N01   , An3 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
	.byte		N04   , Dn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		N16   , Cn4 
	.byte	W06
	.byte		MOD   , 7
	.byte	W10
	.byte		N04   , Dn4 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
	.byte		N04   , Fn4 
	.byte	W16
	.byte		N01   , An3 
	.byte	W08
	.byte		N16   , Fn4 
	.byte	W06
	.byte		MOD   , 7
	.byte	W10
	.byte		N01   , An3 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
	.byte		N04   , En4 
	.byte	W16
	.byte		N01   , Gn3 
	.byte	W08
	.byte		N16   , En4 
	.byte	W06
	.byte		MOD   , 7
	.byte	W10
	.byte		N01   , Gn3 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
	.byte		N16   , Dn4 
	.byte	W06
	.byte		MOD   , 7
	.byte	W10
	.byte		N01   , Fn3 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
	.byte		N02   , Dn4 
	.byte	W16
	.byte		N01   , Gn3 
	.byte	W08
	.byte		N16   , Cn4 
	.byte	W06
	.byte		MOD   , 7
	.byte	W10
	.byte		N02   , Bn3 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
	.byte		N16   , Cn4 
	.byte	W06
	.byte		MOD   , 7
	.byte	W10
	.byte		N04   , Dn4 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_okurimono_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_okurimono_2:
	.byte	KEYSH , mus_rg_okurimono_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+32
	.byte		VOL   , 37*mus_rg_okurimono_mvl/mxv
	.byte		N04   , Fn3 , v120
	.byte	W24
	.byte		N20   
	.byte	W12
	.byte		MOD   , 7
	.byte	W08
	.byte		        0
	.byte	W04
	.byte		N16   
	.byte	W08
	.byte		MOD   , 7
	.byte	W08
	.byte		        0
	.byte		N02   , En3 
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W08
	.byte		MOD   , 7
	.byte	W08
	.byte		N04   , Gn3 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
mus_rg_okurimono_2_B1:
mus_rg_okurimono_2_000:
	.byte		N04   , Cn4 , v120
	.byte	W24
	.byte		N16   
	.byte	W06
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte	W06
	.byte		N04   , Bn3 
	.byte	W24
	.byte		N16   
	.byte	W06
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte	W06
	.byte	PEND
mus_rg_okurimono_2_001:
	.byte		N16   , An3 , v120
	.byte	W06
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte	W06
	.byte		N16   
	.byte	W06
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte	W06
	.byte		N04   
	.byte	W24
	.byte		N16   
	.byte	W06
	.byte		MOD   , 7
	.byte	W10
	.byte		N04   , Bn3 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_okurimono_2_000
	.byte	PATT
	 .word	mus_rg_okurimono_2_001
mus_rg_okurimono_2_002:
	.byte		N04   , Cn4 , v120
	.byte	W24
	.byte		N16   
	.byte	W06
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte	W06
	.byte		N04   
	.byte	W24
	.byte		N16   
	.byte	W06
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte	W06
	.byte	PEND
	.byte		N16   
	.byte	W06
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte	W06
	.byte		N16   
	.byte	W06
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte	W06
	.byte		N04   
	.byte	W24
	.byte		N16   , An3 
	.byte	W06
	.byte		MOD   , 7
	.byte	W10
	.byte		N04   , Cn4 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
	.byte	PATT
	 .word	mus_rg_okurimono_2_002
	.byte		N16   , An3 , v120
	.byte	W06
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte	W06
	.byte		N02   
	.byte	W16
	.byte		        Fn3 
	.byte	W08
	.byte		N16   
	.byte	W06
	.byte		MOD   , 7
	.byte	W10
	.byte		N02   , En3 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
	.byte		N16   , Fn3 
	.byte	W06
	.byte		MOD   , 7
	.byte	W10
	.byte		N04   , Gn3 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_okurimono_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_okurimono_3:
	.byte	KEYSH , mus_rg_okurimono_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 37*mus_rg_okurimono_mvl/mxv
	.byte		N04   , An3 , v120
	.byte	W24
	.byte		N20   
	.byte	W12
	.byte		MOD   , 7
	.byte	W08
	.byte		        0
	.byte	W04
	.byte		N16   
	.byte	W08
	.byte		MOD   , 7
	.byte	W08
	.byte		        0
	.byte		N02   , Gn3 
	.byte	W08
	.byte		N16   , An3 
	.byte	W08
	.byte		MOD   , 7
	.byte	W08
	.byte		N04   , Bn3 
	.byte	W02
	.byte		MOD   , 0
	.byte	W06
mus_rg_okurimono_3_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_okurimono_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_okurimono_4:
	.byte	KEYSH , mus_rg_okurimono_key+0
	.byte		VOICE , 35
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 100*mus_rg_okurimono_mvl/mxv
	.byte		N04   , Gn1 , v120
	.byte	W24
	.byte		N20   
	.byte	W10
	.byte		VOL   , 88*mus_rg_okurimono_mvl/mxv
	.byte		MOD   , 8
	.byte	W14
	.byte		VOL   , 100*mus_rg_okurimono_mvl/mxv
	.byte		MOD   , 0
	.byte		N16   
	.byte	W08
	.byte		VOL   , 88*mus_rg_okurimono_mvl/mxv
	.byte	W02
	.byte		MOD   , 8
	.byte	W14
	.byte		VOL   , 100*mus_rg_okurimono_mvl/mxv
	.byte		MOD   , 0
	.byte		N04   
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Gn1 
	.byte	W08
mus_rg_okurimono_4_B1:
	.byte		N04   , Cn2 , v120
	.byte	W40
	.byte		N02   
	.byte	W08
	.byte		N04   
	.byte	W40
	.byte		        Gn1 
	.byte	W08
	.byte		N16   , Cn2 
	.byte	W08
	.byte		VOL   , 88*mus_rg_okurimono_mvl/mxv
	.byte	W02
	.byte		MOD   , 8
	.byte	W14
	.byte		VOL   , 100*mus_rg_okurimono_mvl/mxv
	.byte		MOD   , 0
	.byte		N16   
	.byte	W08
	.byte		VOL   , 88*mus_rg_okurimono_mvl/mxv
	.byte	W02
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N02   , Gn1 
	.byte	W02
	.byte		VOL   , 100*mus_rg_okurimono_mvl/mxv
	.byte	W06
	.byte		N08   , Cn2 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N16   , Gn2 
	.byte	W08
	.byte		VOL   , 88*mus_rg_okurimono_mvl/mxv
	.byte		MOD   , 9
	.byte	W08
	.byte		N04   , Gn1 
	.byte	W02
	.byte		VOL   , 100*mus_rg_okurimono_mvl/mxv
	.byte		MOD   , 0
	.byte	W06
	.byte		N04   , An1 
	.byte	W24
	.byte		N16   , An2 
	.byte	W08
	.byte		VOL   , 88*mus_rg_okurimono_mvl/mxv
	.byte		MOD   , 8
	.byte	W08
	.byte		N04   , An1 
	.byte	W02
	.byte		VOL   , 100*mus_rg_okurimono_mvl/mxv
	.byte		MOD   , 0
	.byte	W06
	.byte		N04   
	.byte	W40
	.byte		        Gn1 
	.byte	W08
	.byte		N16   , An1 
	.byte	W08
	.byte		VOL   , 88*mus_rg_okurimono_mvl/mxv
	.byte	W02
	.byte		MOD   , 8
	.byte	W14
	.byte		VOL   , 100*mus_rg_okurimono_mvl/mxv
	.byte		MOD   , 0
	.byte		N16   , En2 
	.byte	W08
	.byte		VOL   , 88*mus_rg_okurimono_mvl/mxv
	.byte	W02
	.byte		MOD   , 8
	.byte	W06
	.byte		N02   , An1 
	.byte	W02
	.byte		VOL   , 100*mus_rg_okurimono_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		N04   
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N16   , En2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 88*mus_rg_okurimono_mvl/mxv
	.byte	W08
	.byte		MOD   , 0
	.byte		N04   , An1 
	.byte	W02
	.byte		VOL   , 100*mus_rg_okurimono_mvl/mxv
	.byte	W06
	.byte		N04   , Dn2 
	.byte	W40
	.byte		        An1 
	.byte	W08
	.byte		        Dn2 
	.byte	W40
	.byte		        An1 
	.byte	W08
	.byte		N16   , Dn2 
	.byte	W08
	.byte		VOL   , 88*mus_rg_okurimono_mvl/mxv
	.byte	W02
	.byte		MOD   , 8
	.byte	W14
	.byte		VOL   , 100*mus_rg_okurimono_mvl/mxv
	.byte		MOD   , 0
	.byte		N08   , An2 
	.byte	W08
	.byte		N02   , Gn2 
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		N04   , Dn2 
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		        Gn1 
	.byte	W40
	.byte		        Dn1 
	.byte	W08
	.byte		        Gn1 
	.byte	W40
	.byte		        Dn1 
	.byte	W08
	.byte		N16   , Gn1 
	.byte	W08
	.byte		VOL   , 88*mus_rg_okurimono_mvl/mxv
	.byte	W02
	.byte		MOD   , 8
	.byte	W14
	.byte		VOL   , 100*mus_rg_okurimono_mvl/mxv
	.byte		MOD   , 0
	.byte		N02   , Bn1 
	.byte	W16
	.byte		N04   , Gn1 
	.byte	W08
	.byte		N16   
	.byte	W08
	.byte		VOL   , 88*mus_rg_okurimono_mvl/mxv
	.byte	W02
	.byte		MOD   , 8
	.byte	W14
	.byte		VOL   , 100*mus_rg_okurimono_mvl/mxv
	.byte		MOD   , 0
	.byte		N04   , Gn2 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte	GOTO
	 .word	mus_rg_okurimono_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_okurimono_5:
	.byte	KEYSH , mus_rg_okurimono_key+0
	.byte		VOICE , 0
	.byte		VOL   , 64*mus_rg_okurimono_mvl/mxv
	.byte	W72
	.byte		N08   , En1 , v120
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
mus_rg_okurimono_5_B1:
mus_rg_okurimono_5_000:
	.byte		N08   , Cn1 , v120
	.byte	W24
	.byte		        En1 
	.byte	W16
	.byte		        Cn1 
	.byte	W08
	.byte		N08   
	.byte	W24
	.byte		        En1 
	.byte	W16
	.byte		        Cn1 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_okurimono_5_000
	.byte	PATT
	 .word	mus_rg_okurimono_5_000
	.byte		N08   , Cn1 , v120
	.byte	W24
	.byte		        En1 
	.byte	W24
	.byte		        Cn1 
	.byte	W24
	.byte		        En1 
	.byte	W16
	.byte		        Cn1 
	.byte	W08
	.byte	PATT
	 .word	mus_rg_okurimono_5_000
	.byte	PATT
	 .word	mus_rg_okurimono_5_000
	.byte	PATT
	 .word	mus_rg_okurimono_5_000
	.byte	PATT
	 .word	mus_rg_okurimono_5_000
	.byte	GOTO
	 .word	mus_rg_okurimono_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_okurimono_6:
	.byte	KEYSH , mus_rg_okurimono_key+0
	.byte		VOICE , 127
	.byte		VOL   , 39*mus_rg_okurimono_mvl/mxv
	.byte		PAN   , c_v-62
	.byte	W96
mus_rg_okurimono_6_B1:
mus_rg_okurimono_6_000:
	.byte		N02   , Gn5 , v120
	.byte	W16
	.byte		        Gn5 , v060
	.byte	W08
	.byte		        Gn5 , v120
	.byte	W16
	.byte		        Gn5 , v056
	.byte	W08
	.byte		        Gn5 , v120
	.byte	W16
	.byte		        Gn5 , v060
	.byte	W08
	.byte		        Gn5 , v120
	.byte	W16
	.byte		        Gn5 , v056
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_okurimono_6_000
	.byte	PATT
	 .word	mus_rg_okurimono_6_000
	.byte		N02   , Gn5 , v120
	.byte	W16
	.byte		        Gn5 , v060
	.byte	W08
	.byte		        Gn5 , v120
	.byte	W16
	.byte		        Gn5 , v060
	.byte	W08
	.byte		        Gn5 , v120
	.byte	W16
	.byte		        Gn5 , v060
	.byte	W08
	.byte		        Gn5 , v120
	.byte	W16
	.byte		        Gn5 , v056
	.byte	W08
	.byte	PATT
	 .word	mus_rg_okurimono_6_000
	.byte	PATT
	 .word	mus_rg_okurimono_6_000
	.byte	PATT
	 .word	mus_rg_okurimono_6_000
	.byte		N02   , Gn5 , v120
	.byte	W16
	.byte		        Gn5 , v060
	.byte	W24
	.byte		        Gn5 , v056
	.byte	W08
	.byte		        Gn5 , v120
	.byte	W16
	.byte		        Gn5 , v060
	.byte	W08
	.byte		        Gn5 , v120
	.byte	W16
	.byte		        Gn5 , v056
	.byte	W08
	.byte	GOTO
	 .word	mus_rg_okurimono_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_rg_okurimono_7:
	.byte	KEYSH , mus_rg_okurimono_key+0
	.byte		VOICE , 126
	.byte		VOL   , 37*mus_rg_okurimono_mvl/mxv
	.byte		PAN   , c_v-62
	.byte	W96
mus_rg_okurimono_7_B1:
	.byte	W08
	.byte		N08   , Dn6 , v120
	.byte	W88
	.byte	W08
	.byte		N08   
	.byte	W88
	.byte	W08
	.byte		N08   
	.byte	W88
	.byte	W08
	.byte		N08   
	.byte	W24
	.byte		N08   
	.byte	W48
	.byte		N08   
	.byte	W16
	.byte	W96
	.byte	W08
	.byte		N08   
	.byte	W88
	.byte	W08
	.byte		N08   
	.byte	W88
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N08   
	.byte	W72
	.byte	GOTO
	 .word	mus_rg_okurimono_7_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_okurimono:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_okurimono_pri	@ Priority
	.byte	mus_rg_okurimono_rev	@ Reverb.

	.word	mus_rg_okurimono_grp

	.word	mus_rg_okurimono_1
	.word	mus_rg_okurimono_2
	.word	mus_rg_okurimono_3
	.word	mus_rg_okurimono_4
	.word	mus_rg_okurimono_5
	.word	mus_rg_okurimono_6
	.word	mus_rg_okurimono_7

	.end
