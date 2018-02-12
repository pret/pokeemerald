	.include "MPlayDef.s"

	.equ	mus_rekkuu_kourin_grp, voicegroup_8697670
	.equ	mus_rekkuu_kourin_pri, 0
	.equ	mus_rekkuu_kourin_rev, reverb_set+50
	.equ	mus_rekkuu_kourin_mvl, 127
	.equ	mus_rekkuu_kourin_key, 0
	.equ	mus_rekkuu_kourin_tbs, 1
	.equ	mus_rekkuu_kourin_exg, 0
	.equ	mus_rekkuu_kourin_cmp, 1

	.section .rodata
	.global	mus_rekkuu_kourin
	.align	2

@********************** Track  1 **********************@

mus_rekkuu_kourin_1:
	.byte	KEYSH , mus_rekkuu_kourin_key+0
	.byte	TEMPO , 120*mus_rekkuu_kourin_tbs/2
	.byte		VOICE , 19
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 79*mus_rekkuu_kourin_mvl/mxv
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
	.byte		VOL   , 77*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        75*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        72*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        70*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        68*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        65*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        63*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        60*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        59*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        56*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        55*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        53*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        48*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        47*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        43*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        38*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        38*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        36*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        31*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        30*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        27*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        25*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        22*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        18*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        16*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        13*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        9*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        8*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        6*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        1*mus_rekkuu_kourin_mvl/mxv
	.byte	W10
	.byte		EOT   
	.byte	FINE

@********************** Track  2 **********************@

mus_rekkuu_kourin_2:
	.byte	KEYSH , mus_rekkuu_kourin_key+0
	.byte		VOICE , 19
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+36
	.byte		VOL   , 79*mus_rekkuu_kourin_mvl/mxv
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
	.byte		VOL   , 77*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        75*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        72*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        70*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        68*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        65*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        63*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        60*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        59*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        56*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        55*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        53*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        48*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        47*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        43*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        38*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        38*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        36*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        31*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        30*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        27*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        25*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        22*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        18*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        16*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        13*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        9*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        8*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        6*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        1*mus_rekkuu_kourin_mvl/mxv
	.byte	W10
	.byte		EOT   
	.byte	FINE

@********************** Track  3 **********************@

mus_rekkuu_kourin_3:
	.byte	KEYSH , mus_rekkuu_kourin_key+0
	.byte		VOICE , 20
	.byte		BENDR , 12
	.byte		LFOS  , 38
	.byte		PAN   , c_v+6
	.byte		VOL   , 90*mus_rekkuu_kourin_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N12   , Dn3 , v096
	.byte	W12
	.byte		N84   , En3 
	.byte	W12
	.byte		VOL   , 79*mus_rekkuu_kourin_mvl/mxv
	.byte		MOD   , 1
	.byte	W72
	.byte		VOL   , 90*mus_rekkuu_kourin_mvl/mxv
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
	.byte		VOL   , 79*mus_rekkuu_kourin_mvl/mxv
	.byte		MOD   , 1
	.byte	W12
	.byte	W96
	.byte		EOT   
	.byte		VOL   , 90*mus_rekkuu_kourin_mvl/mxv
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
	.byte		VOL   , 79*mus_rekkuu_kourin_mvl/mxv
	.byte		MOD   , 1
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOL   , 90*mus_rekkuu_kourin_mvl/mxv
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
	.byte		VOL   , 79*mus_rekkuu_kourin_mvl/mxv
	.byte		MOD   , 1
	.byte	W12
	.byte	W96
	.byte		EOT   
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rekkuu_kourin_mvl/mxv
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
	.byte		VOL   , 79*mus_rekkuu_kourin_mvl/mxv
	.byte		MOD   , 1
	.byte	W12
	.byte		VOL   , 77*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        75*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        72*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        70*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        68*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        65*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        63*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        60*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        59*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        56*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        55*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        53*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        48*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        47*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        43*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        38*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        38*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        36*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        31*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        30*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        27*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        25*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        22*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        18*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        16*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        13*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        9*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        8*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        6*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        1*mus_rekkuu_kourin_mvl/mxv
	.byte	W10
	.byte		EOT   
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  4 **********************@

mus_rekkuu_kourin_4:
	.byte	KEYSH , mus_rekkuu_kourin_key+0
	.byte		VOICE , 19
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+16
	.byte		VOL   , 90*mus_rekkuu_kourin_mvl/mxv
	.byte		N96   , Gn2 , v120
	.byte	W12
	.byte		VOL   , 79*mus_rekkuu_kourin_mvl/mxv
	.byte	W48
	.byte		MOD   , 5
	.byte	W36
mus_rekkuu_kourin_4_000:
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rekkuu_kourin_mvl/mxv
	.byte		N96   , An2 , v120
	.byte	W12
	.byte		VOL   , 79*mus_rekkuu_kourin_mvl/mxv
	.byte	W84
	.byte	PEND
	.byte		        90*mus_rekkuu_kourin_mvl/mxv
	.byte		N96   , As2 
	.byte	W12
	.byte		VOL   , 79*mus_rekkuu_kourin_mvl/mxv
	.byte	W48
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte		VOL   , 90*mus_rekkuu_kourin_mvl/mxv
	.byte		N84   , Gn2 
	.byte	W12
	.byte		VOL   , 79*mus_rekkuu_kourin_mvl/mxv
	.byte	W36
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte	W12
mus_rekkuu_kourin_4_001:
	.byte		VOL   , 90*mus_rekkuu_kourin_mvl/mxv
	.byte		N96   , Gn2 , v120
	.byte	W12
	.byte		VOL   , 79*mus_rekkuu_kourin_mvl/mxv
	.byte	W48
	.byte		MOD   , 5
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	mus_rekkuu_kourin_4_000
	.byte	PATT
	 .word	mus_rekkuu_kourin_4_001
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rekkuu_kourin_mvl/mxv
	.byte		N96   , An2 , v120
	.byte	W12
	.byte		VOL   , 79*mus_rekkuu_kourin_mvl/mxv
	.byte	W48
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte		VOL   , 90*mus_rekkuu_kourin_mvl/mxv
	.byte		N96   , Gn2 
	.byte	W12
	.byte		VOL   , 79*mus_rekkuu_kourin_mvl/mxv
	.byte	W84
	.byte		        90*mus_rekkuu_kourin_mvl/mxv
	.byte		N96   , An2 
	.byte	W12
	.byte		VOL   , 79*mus_rekkuu_kourin_mvl/mxv
	.byte	W48
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte		VOL   , 90*mus_rekkuu_kourin_mvl/mxv
	.byte		N96   , Gn2 
	.byte	W12
	.byte		VOL   , 79*mus_rekkuu_kourin_mvl/mxv
	.byte	W48
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte		VOL   , 90*mus_rekkuu_kourin_mvl/mxv
	.byte		TIE   , Dn2 
	.byte	W12
	.byte		VOL   , 79*mus_rekkuu_kourin_mvl/mxv
	.byte	W48
	.byte		MOD   , 5
	.byte	W36
	.byte		VOL   , 77*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        75*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        72*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        70*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        68*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        65*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        63*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        60*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        59*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        56*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        55*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        53*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        48*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        47*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        43*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        38*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        38*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        36*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        31*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        30*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        27*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        25*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        22*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        18*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        16*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        13*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        9*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        8*mus_rekkuu_kourin_mvl/mxv
	.byte	W04
	.byte		        6*mus_rekkuu_kourin_mvl/mxv
	.byte	W02
	.byte		        1*mus_rekkuu_kourin_mvl/mxv
	.byte	W10
	.byte		EOT   
	.byte	FINE

@********************** Track  5 **********************@

mus_rekkuu_kourin_5:
	.byte	KEYSH , mus_rekkuu_kourin_key+0
	.byte		VOICE , 80
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 55*mus_rekkuu_kourin_mvl/mxv
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
mus_rekkuu_kourin_5_000:
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
	 .word	mus_rekkuu_kourin_5_000
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
	 .word	mus_rekkuu_kourin_5_000
	.byte	PATT
	 .word	mus_rekkuu_kourin_5_000
	.byte	PATT
	 .word	mus_rekkuu_kourin_5_000
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

mus_rekkuu_kourin_6:
	.byte	KEYSH , mus_rekkuu_kourin_key+0
	.byte		VOICE , 81
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 79*mus_rekkuu_kourin_mvl/mxv
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
mus_rekkuu_kourin_6_000:
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
	 .word	mus_rekkuu_kourin_6_000
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
	 .word	mus_rekkuu_kourin_6_000
	.byte	PATT
	 .word	mus_rekkuu_kourin_6_000
	.byte	PATT
	 .word	mus_rekkuu_kourin_6_000
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

mus_rekkuu_kourin_7:
	.byte	KEYSH , mus_rekkuu_kourin_key+0
	.byte		VOICE , 82
	.byte		VOL   , 56*mus_rekkuu_kourin_mvl/mxv
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
mus_rekkuu_kourin_7_000:
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
	 .word	mus_rekkuu_kourin_7_000
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
	.byte		VOL   , 45*mus_rekkuu_kourin_mvl/mxv
	.byte	W12
	.byte		        34*mus_rekkuu_kourin_mvl/mxv
	.byte	W12
	.byte		        22*mus_rekkuu_kourin_mvl/mxv
	.byte	W12
	.byte		        11*mus_rekkuu_kourin_mvl/mxv
	.byte	W24
	.byte		        1*mus_rekkuu_kourin_mvl/mxv
	.byte	W48
	.byte	FINE

@******************************************************@
	.align	2

mus_rekkuu_kourin:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rekkuu_kourin_pri	@ Priority
	.byte	mus_rekkuu_kourin_rev	@ Reverb.

	.word	mus_rekkuu_kourin_grp

	.word	mus_rekkuu_kourin_1
	.word	mus_rekkuu_kourin_2
	.word	mus_rekkuu_kourin_3
	.word	mus_rekkuu_kourin_4
	.word	mus_rekkuu_kourin_5
	.word	mus_rekkuu_kourin_6
	.word	mus_rekkuu_kourin_7

	.end
