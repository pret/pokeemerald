	.include "MPlayDef.s"

	.equ	bgm_fanfa_rayquaza_grp, voicegroup_8697670
	.equ	bgm_fanfa_rayquaza_pri, 0
	.equ	bgm_fanfa_rayquaza_rev, reverb_set+50
	.equ	bgm_fanfa_rayquaza_mvl, 127
	.equ	bgm_fanfa_rayquaza_key, 0
	.equ	bgm_fanfa_rayquaza_tbs, 1
	.equ	bgm_fanfa_rayquaza_exg, 0
	.equ	bgm_fanfa_rayquaza_cmp, 1

	.section .rodata
	.global	bgm_fanfa_rayquaza
	.align	2

@********************** Track  1 **********************@

bgm_fanfa_rayquaza_1:
	.byte	KEYSH , bgm_fanfa_rayquaza_key+0
	.byte	TEMPO , 120*bgm_fanfa_rayquaza_tbs/2
	.byte		VOICE , 19
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 79*bgm_fanfa_rayquaza_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		TIE   , Dn4 , v100
	.byte	W60
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		EOT   
	.byte	W12
	.byte		TIE   
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOL   , 77*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        75*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        72*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        70*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        68*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        65*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        63*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        60*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        59*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        56*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        55*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        53*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        48*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        47*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        43*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        38*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        38*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        36*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        31*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        30*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        27*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        25*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        22*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        18*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        16*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        13*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        9*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        8*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        6*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        1*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W10
	.byte		EOT   
	.byte	FINE

@********************** Track  2 **********************@

bgm_fanfa_rayquaza_2:
	.byte	KEYSH , bgm_fanfa_rayquaza_key+0
	.byte		VOICE , 19
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+36
	.byte		VOL   , 79*bgm_fanfa_rayquaza_mvl/mxv
	.byte		N96   , Dn3 , v100
	.byte	W96
	.byte		TIE   
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		N84   
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		TIE   
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		N96   
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		TIE   
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   
	.byte	W96
	.byte		VOL   , 77*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        75*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        72*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        70*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        68*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        65*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        63*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        60*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        59*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        56*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        55*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        53*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        48*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        47*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        43*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        38*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        38*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        36*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        31*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        30*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        27*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        25*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        22*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        18*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        16*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        13*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        9*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        8*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        6*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        1*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W10
	.byte		EOT   
	.byte	FINE

@********************** Track  3 **********************@

bgm_fanfa_rayquaza_3:
	.byte	KEYSH , bgm_fanfa_rayquaza_key+0
	.byte		VOICE , 20
	.byte		BENDR , 12
	.byte		LFOS  , 38
	.byte		PAN   , c_v+6
	.byte		VOL   , 90*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N12   , Dn3 , v096
	.byte	W12
	.byte		N84   , En3 
	.byte	W12
	.byte		VOL   , 79*bgm_fanfa_rayquaza_mvl/mxv
	.byte		MOD   , 1
	.byte	W72
	.byte		VOL   , 90*bgm_fanfa_rayquaza_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		TIE   , En3 
	.byte	W12
	.byte		VOL   , 79*bgm_fanfa_rayquaza_mvl/mxv
	.byte		MOD   , 1
	.byte	W12
	.byte	W96
	.byte		EOT   
	.byte		VOL   , 90*bgm_fanfa_rayquaza_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N24   , An3 
	.byte	W12
	.byte		VOL   , 79*bgm_fanfa_rayquaza_mvl/mxv
	.byte		MOD   , 1
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOL   , 90*bgm_fanfa_rayquaza_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		TIE   , En3 
	.byte	W12
	.byte		VOL   , 79*bgm_fanfa_rayquaza_mvl/mxv
	.byte		MOD   , 1
	.byte	W12
	.byte	W96
	.byte		EOT   
	.byte		MOD   , 0
	.byte		VOL   , 90*bgm_fanfa_rayquaza_mvl/mxv
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		TIE   , Dn3 
	.byte	W12
	.byte		VOL   , 79*bgm_fanfa_rayquaza_mvl/mxv
	.byte		MOD   , 1
	.byte	W12
	.byte		VOL   , 77*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        75*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        72*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        70*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        68*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        65*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        63*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        60*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        59*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        56*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        55*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        53*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        48*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        47*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        43*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        38*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        38*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        36*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        31*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        30*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        27*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        25*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        22*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        18*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        16*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        13*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        9*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        8*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        6*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        1*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W10
	.byte		EOT   
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  4 **********************@

bgm_fanfa_rayquaza_4:
	.byte	KEYSH , bgm_fanfa_rayquaza_key+0
	.byte		VOICE , 19
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+16
	.byte		VOL   , 90*bgm_fanfa_rayquaza_mvl/mxv
	.byte		N96   , Gn2 , v120
	.byte	W12
	.byte		VOL   , 79*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W48
	.byte		MOD   , 5
	.byte	W36
bgm_fanfa_rayquaza_4_000:
	.byte		MOD   , 0
	.byte		VOL   , 90*bgm_fanfa_rayquaza_mvl/mxv
	.byte		N96   , An2 , v120
	.byte	W12
	.byte		VOL   , 79*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W84
	.byte	PEND
	.byte		        90*bgm_fanfa_rayquaza_mvl/mxv
	.byte		N96   , As2 
	.byte	W12
	.byte		VOL   , 79*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W48
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte		VOL   , 90*bgm_fanfa_rayquaza_mvl/mxv
	.byte		N84   , Gn2 
	.byte	W12
	.byte		VOL   , 79*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W36
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte	W12
bgm_fanfa_rayquaza_4_001:
	.byte		VOL   , 90*bgm_fanfa_rayquaza_mvl/mxv
	.byte		N96   , Gn2 , v120
	.byte	W12
	.byte		VOL   , 79*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W48
	.byte		MOD   , 5
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	bgm_fanfa_rayquaza_4_000
	.byte	PATT
	 .word	bgm_fanfa_rayquaza_4_001
	.byte		MOD   , 0
	.byte		VOL   , 90*bgm_fanfa_rayquaza_mvl/mxv
	.byte		N96   , An2 , v120
	.byte	W12
	.byte		VOL   , 79*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W48
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte		VOL   , 90*bgm_fanfa_rayquaza_mvl/mxv
	.byte		N96   , Gn2 
	.byte	W12
	.byte		VOL   , 79*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W84
	.byte		        90*bgm_fanfa_rayquaza_mvl/mxv
	.byte		N96   , An2 
	.byte	W12
	.byte		VOL   , 79*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W48
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte		VOL   , 90*bgm_fanfa_rayquaza_mvl/mxv
	.byte		N96   , Gn2 
	.byte	W12
	.byte		VOL   , 79*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W48
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte		VOL   , 90*bgm_fanfa_rayquaza_mvl/mxv
	.byte		TIE   , Dn2 
	.byte	W12
	.byte		VOL   , 79*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W48
	.byte		MOD   , 5
	.byte	W36
	.byte		VOL   , 77*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        75*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        72*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        70*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        68*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        65*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        63*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        60*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        59*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        56*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        55*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        53*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        48*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        47*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        43*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        38*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        38*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        36*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        31*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        30*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        27*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        25*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        22*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        18*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        16*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        13*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        9*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        8*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W04
	.byte		        6*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W02
	.byte		        1*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W10
	.byte		EOT   
	.byte	FINE

@********************** Track  5 **********************@

bgm_fanfa_rayquaza_5:
	.byte	KEYSH , bgm_fanfa_rayquaza_key+0
	.byte		VOICE , 80
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 55*bgm_fanfa_rayquaza_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N09   , Dn1 , v064
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N09   , Dn1 , v052
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N09   , Dn1 , v064
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N09   , Dn1 , v052
	.byte	W12
	.byte		        Dn1 , v064
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N09   , Dn1 , v052
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N09   , Dn1 , v064
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N09   , Dn1 , v052
	.byte	W12
bgm_fanfa_rayquaza_5_000:
	.byte		PAN   , c_v+0
	.byte		N09   , Dn1 , v064
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N09   , Dn1 , v052
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N09   , Dn1 , v064
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N09   , Dn1 , v052
	.byte	W12
	.byte		        Dn1 , v064
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N09   , Dn1 , v052
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N09   , Dn1 , v064
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N09   , Dn1 , v052
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_fanfa_rayquaza_5_000
	.byte		PAN   , c_v+0
	.byte		N09   , Dn1 , v064
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N09   , Dn1 , v052
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N09   , Dn1 , v064
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N09   , Dn1 , v052
	.byte	W12
	.byte		        Dn1 , v064
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N09   , Dn1 , v052
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N09   , Dn1 , v064
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	bgm_fanfa_rayquaza_5_000
	.byte	PATT
	 .word	bgm_fanfa_rayquaza_5_000
	.byte	PATT
	 .word	bgm_fanfa_rayquaza_5_000
	.byte		PAN   , c_v+0
	.byte		N09   , Dn1 , v064
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N09   , Dn1 , v052
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N09   , Dn1 , v064
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N09   , Dn1 , v052
	.byte	W12
	.byte		        Dn1 , v064
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N09   , Dn1 , v052
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N21   , Dn1 , v064
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	W12
	.byte	W96
	.byte	FINE

@********************** Track  6 **********************@

bgm_fanfa_rayquaza_6:
	.byte	KEYSH , bgm_fanfa_rayquaza_key+0
	.byte		VOICE , 81
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 79*bgm_fanfa_rayquaza_mvl/mxv
	.byte		N09   , Dn1 , v064
	.byte	W12
	.byte		        Dn1 , v052
	.byte	W12
	.byte		        Dn1 , v064
	.byte	W12
	.byte		        Dn1 , v052
	.byte	W12
	.byte		        Dn1 , v064
	.byte	W12
	.byte		        Dn1 , v052
	.byte	W12
	.byte		        Dn1 , v064
	.byte	W12
	.byte		        Dn1 , v052
	.byte	W12
bgm_fanfa_rayquaza_6_000:
	.byte		N09   , Dn1 , v064
	.byte	W12
	.byte		        Dn1 , v052
	.byte	W12
	.byte		        Dn1 , v064
	.byte	W12
	.byte		        Dn1 , v052
	.byte	W12
	.byte		        Dn1 , v064
	.byte	W12
	.byte		        Dn1 , v052
	.byte	W12
	.byte		        Dn1 , v064
	.byte	W12
	.byte		        Dn1 , v052
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_fanfa_rayquaza_6_000
	.byte		N09   , Dn1 , v064
	.byte	W12
	.byte		        Dn1 , v052
	.byte	W12
	.byte		        Dn1 , v064
	.byte	W12
	.byte		        Dn1 , v052
	.byte	W12
	.byte		        Dn1 , v064
	.byte	W12
	.byte		        Dn1 , v052
	.byte	W12
	.byte		        Dn1 , v064
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	bgm_fanfa_rayquaza_6_000
	.byte	PATT
	 .word	bgm_fanfa_rayquaza_6_000
	.byte	PATT
	 .word	bgm_fanfa_rayquaza_6_000
	.byte		N09   , Dn1 , v064
	.byte	W12
	.byte		        Dn1 , v052
	.byte	W12
	.byte		        Dn1 , v064
	.byte	W12
	.byte		        Dn1 , v052
	.byte	W12
	.byte		        Dn1 , v064
	.byte	W12
	.byte		        Dn1 , v052
	.byte	W12
	.byte		N21   , Dn1 , v064
	.byte	W24
	.byte	W96
	.byte	FINE

@********************** Track  7 **********************@

bgm_fanfa_rayquaza_7:
	.byte	KEYSH , bgm_fanfa_rayquaza_key+0
	.byte		VOICE , 82
	.byte		VOL   , 56*bgm_fanfa_rayquaza_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BEND  , c_v+0
	.byte		TIE   , Dn3 , v100
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		EOT   
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N84   , En4 
	.byte	W84
bgm_fanfa_rayquaza_7_000:
	.byte		N12   , Fn4 , v100
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		TIE   , En4 
	.byte	W24
	.byte	PEND
	.byte	W96
	.byte		EOT   
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N24   , An4 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte	PATT
	 .word	bgm_fanfa_rayquaza_7_000
	.byte	W96
	.byte		EOT   , En4 
	.byte		N12   , Fn4 , v100
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N48   , Dn4 
	.byte	W12
	.byte		VOL   , 45*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W12
	.byte		        34*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W12
	.byte		        22*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W12
	.byte		        11*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W24
	.byte		        1*bgm_fanfa_rayquaza_mvl/mxv
	.byte	W48
	.byte	FINE

@******************************************************@
	.align	2

bgm_fanfa_rayquaza:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_fanfa_rayquaza_pri	@ Priority
	.byte	bgm_fanfa_rayquaza_rev	@ Reverb.

	.word	bgm_fanfa_rayquaza_grp

	.word	bgm_fanfa_rayquaza_1
	.word	bgm_fanfa_rayquaza_2
	.word	bgm_fanfa_rayquaza_3
	.word	bgm_fanfa_rayquaza_4
	.word	bgm_fanfa_rayquaza_5
	.word	bgm_fanfa_rayquaza_6
	.word	bgm_fanfa_rayquaza_7

	.end
