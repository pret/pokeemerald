	.include "MPlayDef.s"

	.equ	bgm_frlg_mystery_gift_grp, voicegroup_86B1C44
	.equ	bgm_frlg_mystery_gift_pri, 0
	.equ	bgm_frlg_mystery_gift_rev, reverb_set+50
	.equ	bgm_frlg_mystery_gift_mvl, 127
	.equ	bgm_frlg_mystery_gift_key, 0
	.equ	bgm_frlg_mystery_gift_tbs, 1
	.equ	bgm_frlg_mystery_gift_exg, 0
	.equ	bgm_frlg_mystery_gift_cmp, 1

	.section .rodata
	.global	bgm_frlg_mystery_gift
	.align	2

@********************** Track  1 **********************@

bgm_frlg_mystery_gift_1:
	.byte	KEYSH , bgm_frlg_mystery_gift_key+0
	.byte	TEMPO , 124*bgm_frlg_mystery_gift_tbs/2
	.byte		VOICE , 24
	.byte		VOL   , 75*bgm_frlg_mystery_gift_mvl/mxv
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
bgm_frlg_mystery_gift_1_B1:
bgm_frlg_mystery_gift_1_000:
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
	 .word	bgm_frlg_mystery_gift_1_000
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
	 .word	bgm_frlg_mystery_gift_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_frlg_mystery_gift_2:
	.byte	KEYSH , bgm_frlg_mystery_gift_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+32
	.byte		VOL   , 37*bgm_frlg_mystery_gift_mvl/mxv
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
bgm_frlg_mystery_gift_2_B1:
bgm_frlg_mystery_gift_2_000:
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
bgm_frlg_mystery_gift_2_001:
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
	 .word	bgm_frlg_mystery_gift_2_000
	.byte	PATT
	 .word	bgm_frlg_mystery_gift_2_001
bgm_frlg_mystery_gift_2_002:
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
	 .word	bgm_frlg_mystery_gift_2_002
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
	 .word	bgm_frlg_mystery_gift_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_frlg_mystery_gift_3:
	.byte	KEYSH , bgm_frlg_mystery_gift_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 37*bgm_frlg_mystery_gift_mvl/mxv
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
bgm_frlg_mystery_gift_3_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_frlg_mystery_gift_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_frlg_mystery_gift_4:
	.byte	KEYSH , bgm_frlg_mystery_gift_key+0
	.byte		VOICE , 35
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 100*bgm_frlg_mystery_gift_mvl/mxv
	.byte		N04   , Gn1 , v120
	.byte	W24
	.byte		N20   
	.byte	W10
	.byte		VOL   , 88*bgm_frlg_mystery_gift_mvl/mxv
	.byte		MOD   , 8
	.byte	W14
	.byte		VOL   , 100*bgm_frlg_mystery_gift_mvl/mxv
	.byte		MOD   , 0
	.byte		N16   
	.byte	W08
	.byte		VOL   , 88*bgm_frlg_mystery_gift_mvl/mxv
	.byte	W02
	.byte		MOD   , 8
	.byte	W14
	.byte		VOL   , 100*bgm_frlg_mystery_gift_mvl/mxv
	.byte		MOD   , 0
	.byte		N04   
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Gn1 
	.byte	W08
bgm_frlg_mystery_gift_4_B1:
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
	.byte		VOL   , 88*bgm_frlg_mystery_gift_mvl/mxv
	.byte	W02
	.byte		MOD   , 8
	.byte	W14
	.byte		VOL   , 100*bgm_frlg_mystery_gift_mvl/mxv
	.byte		MOD   , 0
	.byte		N16   
	.byte	W08
	.byte		VOL   , 88*bgm_frlg_mystery_gift_mvl/mxv
	.byte	W02
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N02   , Gn1 
	.byte	W02
	.byte		VOL   , 100*bgm_frlg_mystery_gift_mvl/mxv
	.byte	W06
	.byte		N08   , Cn2 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N16   , Gn2 
	.byte	W08
	.byte		VOL   , 88*bgm_frlg_mystery_gift_mvl/mxv
	.byte		MOD   , 9
	.byte	W08
	.byte		N04   , Gn1 
	.byte	W02
	.byte		VOL   , 100*bgm_frlg_mystery_gift_mvl/mxv
	.byte		MOD   , 0
	.byte	W06
	.byte		N04   , An1 
	.byte	W24
	.byte		N16   , An2 
	.byte	W08
	.byte		VOL   , 88*bgm_frlg_mystery_gift_mvl/mxv
	.byte		MOD   , 8
	.byte	W08
	.byte		N04   , An1 
	.byte	W02
	.byte		VOL   , 100*bgm_frlg_mystery_gift_mvl/mxv
	.byte		MOD   , 0
	.byte	W06
	.byte		N04   
	.byte	W40
	.byte		        Gn1 
	.byte	W08
	.byte		N16   , An1 
	.byte	W08
	.byte		VOL   , 88*bgm_frlg_mystery_gift_mvl/mxv
	.byte	W02
	.byte		MOD   , 8
	.byte	W14
	.byte		VOL   , 100*bgm_frlg_mystery_gift_mvl/mxv
	.byte		MOD   , 0
	.byte		N16   , En2 
	.byte	W08
	.byte		VOL   , 88*bgm_frlg_mystery_gift_mvl/mxv
	.byte	W02
	.byte		MOD   , 8
	.byte	W06
	.byte		N02   , An1 
	.byte	W02
	.byte		VOL   , 100*bgm_frlg_mystery_gift_mvl/mxv
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
	.byte		VOL   , 88*bgm_frlg_mystery_gift_mvl/mxv
	.byte	W08
	.byte		MOD   , 0
	.byte		N04   , An1 
	.byte	W02
	.byte		VOL   , 100*bgm_frlg_mystery_gift_mvl/mxv
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
	.byte		VOL   , 88*bgm_frlg_mystery_gift_mvl/mxv
	.byte	W02
	.byte		MOD   , 8
	.byte	W14
	.byte		VOL   , 100*bgm_frlg_mystery_gift_mvl/mxv
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
	.byte		VOL   , 88*bgm_frlg_mystery_gift_mvl/mxv
	.byte	W02
	.byte		MOD   , 8
	.byte	W14
	.byte		VOL   , 100*bgm_frlg_mystery_gift_mvl/mxv
	.byte		MOD   , 0
	.byte		N02   , Bn1 
	.byte	W16
	.byte		N04   , Gn1 
	.byte	W08
	.byte		N16   
	.byte	W08
	.byte		VOL   , 88*bgm_frlg_mystery_gift_mvl/mxv
	.byte	W02
	.byte		MOD   , 8
	.byte	W14
	.byte		VOL   , 100*bgm_frlg_mystery_gift_mvl/mxv
	.byte		MOD   , 0
	.byte		N04   , Gn2 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte	GOTO
	 .word	bgm_frlg_mystery_gift_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_frlg_mystery_gift_5:
	.byte	KEYSH , bgm_frlg_mystery_gift_key+0
	.byte		VOICE , 0
	.byte		VOL   , 64*bgm_frlg_mystery_gift_mvl/mxv
	.byte	W72
	.byte		N08   , En1 , v120
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
bgm_frlg_mystery_gift_5_B1:
bgm_frlg_mystery_gift_5_000:
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
	 .word	bgm_frlg_mystery_gift_5_000
	.byte	PATT
	 .word	bgm_frlg_mystery_gift_5_000
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
	 .word	bgm_frlg_mystery_gift_5_000
	.byte	PATT
	 .word	bgm_frlg_mystery_gift_5_000
	.byte	PATT
	 .word	bgm_frlg_mystery_gift_5_000
	.byte	PATT
	 .word	bgm_frlg_mystery_gift_5_000
	.byte	GOTO
	 .word	bgm_frlg_mystery_gift_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_frlg_mystery_gift_6:
	.byte	KEYSH , bgm_frlg_mystery_gift_key+0
	.byte		VOICE , 127
	.byte		VOL   , 39*bgm_frlg_mystery_gift_mvl/mxv
	.byte		PAN   , c_v-62
	.byte	W96
bgm_frlg_mystery_gift_6_B1:
bgm_frlg_mystery_gift_6_000:
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
	 .word	bgm_frlg_mystery_gift_6_000
	.byte	PATT
	 .word	bgm_frlg_mystery_gift_6_000
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
	 .word	bgm_frlg_mystery_gift_6_000
	.byte	PATT
	 .word	bgm_frlg_mystery_gift_6_000
	.byte	PATT
	 .word	bgm_frlg_mystery_gift_6_000
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
	 .word	bgm_frlg_mystery_gift_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_frlg_mystery_gift_7:
	.byte	KEYSH , bgm_frlg_mystery_gift_key+0
	.byte		VOICE , 126
	.byte		VOL   , 37*bgm_frlg_mystery_gift_mvl/mxv
	.byte		PAN   , c_v-62
	.byte	W96
bgm_frlg_mystery_gift_7_B1:
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
	 .word	bgm_frlg_mystery_gift_7_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_frlg_mystery_gift:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_frlg_mystery_gift_pri	@ Priority
	.byte	bgm_frlg_mystery_gift_rev	@ Reverb.

	.word	bgm_frlg_mystery_gift_grp

	.word	bgm_frlg_mystery_gift_1
	.word	bgm_frlg_mystery_gift_2
	.word	bgm_frlg_mystery_gift_3
	.word	bgm_frlg_mystery_gift_4
	.word	bgm_frlg_mystery_gift_5
	.word	bgm_frlg_mystery_gift_6
	.word	bgm_frlg_mystery_gift_7

	.end
