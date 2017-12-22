	.include "MPlayDef.s"

	.equ	mus_rg_nana67_grp, voicegroup_86B3E4C
	.equ	mus_rg_nana67_pri, 0
	.equ	mus_rg_nana67_rev, reverb_set+50
	.equ	mus_rg_nana67_mvl, 127
	.equ	mus_rg_nana67_key, 0
	.equ	mus_rg_nana67_tbs, 1
	.equ	mus_rg_nana67_exg, 0
	.equ	mus_rg_nana67_cmp, 1

	.section .rodata
	.global	mus_rg_nana67
	.align	2

@********************** Track  1 **********************@

mus_rg_nana67_1:
	.byte	KEYSH , mus_rg_nana67_key+0
	.byte	TEMPO , 116*mus_rg_nana67_tbs/2
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 63*mus_rg_nana67_mvl/mxv
	.byte	W96
	.byte		N06   , As1 , v092
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        As1 
	.byte	W12
	.byte		N24   , Ds2 , v096
	.byte	W24
	.byte		N12   , Fn2 , v092
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Fn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		N06   , As1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		N03   , Ds1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		        En1 , v096
	.byte	W12
	.byte		N03   , En1 , v092
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		N12   , En1 
	.byte	W12
	.byte		N03   , Fn1 , v096
	.byte	W06
	.byte		N06   , An2 , v092
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , Cn2 , v096
	.byte	W12
	.byte		N24   , An2 
	.byte	W24
	.byte		N06   , Gs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N12   , Fn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
mus_rg_nana67_1_B1:
	.byte		N03   , As1 , v096
	.byte	W06
	.byte		N18   , As1 , v092
	.byte	W30
	.byte		N06   , As1 , v096
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N12   , Fn2 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N12   , Cn2 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N12   , Gn2 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W12
	.byte		N03   , Fn1 
	.byte	W06
	.byte		N18   , Fn1 , v092
	.byte	W30
	.byte		N06   , Fn1 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Fn1 , v092
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Cn2 , v096
	.byte	W06
	.byte		        Ds2 , v092
	.byte	W06
	.byte		N03   , As1 , v096
	.byte	W06
	.byte		N18   , As1 , v092
	.byte	W30
	.byte		N06   , As1 , v096
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N24   , As2 
	.byte	W24
	.byte		N06   , Gn2 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Fn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   , Cn2 , v092
	.byte	W06
	.byte		N18   
	.byte	W30
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn2 , v096
	.byte	W12
	.byte		        Cn2 , v092
	.byte	W06
	.byte		N03   , As1 
	.byte	W03
	.byte		        Gn1 
	.byte	W03
	.byte		N24   , En1 
	.byte	W24
	.byte		N03   , Ds1 , v096
	.byte	W06
	.byte		N18   , Ds1 , v092
	.byte	W30
	.byte		N06   , Ds1 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Cn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		N03   , As1 
	.byte	W06
	.byte		N18   , As1 , v092
	.byte	W30
	.byte		N06   , As1 , v096
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N24   , Gs1 
	.byte	W24
mus_rg_nana67_1_000:
	.byte		N06   , Fs1 , v096
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gs1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Ds2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte	PEND
mus_rg_nana67_1_001:
	.byte		N06   , Fn1 , v096
	.byte	W36
	.byte		        As1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N24   , An1 
	.byte	W24
	.byte		N06   , Gs1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_nana67_1_000
	.byte	PATT
	 .word	mus_rg_nana67_1_001
	.byte		N06   , Ds1 , v096
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N12   , As1 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        En1 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N06   , An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		N36   , Fn1 
	.byte	W36
	.byte		N06   , Fs1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		N24   , An1 
	.byte	W24
	.byte		N12   , Cn2 
	.byte	W12
	.byte		        Bn1 , v092
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_nana67_1_B1
	.byte	W96
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_nana67_2:
	.byte	KEYSH , mus_rg_nana67_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+32
	.byte		VOL   , 46*mus_rg_nana67_mvl/mxv
	.byte	W96
	.byte		N06   , Ds2 , v112
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W12
	.byte		N24   , An3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		N24   , Dn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn3 
	.byte	W12
	.byte		N24   , As2 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N03   , Cn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N24   , As2 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W12
	.byte		N36   , Fn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte	W24
mus_rg_nana67_2_B1:
	.byte	W12
	.byte		N06   , As2 , v112
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   , An3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W12
	.byte		N06   , Cn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N12   , An3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N24   , Dn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Ds3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , En3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		        Cn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N18   , En4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W06
	.byte		VOICE , 24
	.byte		MOD   , 0
	.byte		N03   , Gn4 , v064
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		MOD   , 0
	.byte		N24   , Dn5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W96
	.byte		VOICE , 24
	.byte		N03   , Ds3 , v120
	.byte	W06
	.byte		        As2 , v112
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Ds3 , v120
	.byte	W06
	.byte		        As2 , v112
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N24   , Dn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W24
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N04   , As3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		MOD   , 6
	.byte		N12   
	.byte	W12
	.byte		MOD   , 0
	.byte		N06   , Cn3 
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N24   , Cs3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Ds3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N06   , As3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N04   , Cs4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Cs4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N24   , As4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W24
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N24   , As4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W24
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N36   , Cn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N24   , An3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W24
	.byte	GOTO
	 .word	mus_rg_nana67_2_B1
	.byte	W96
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_nana67_3:
	.byte	KEYSH , mus_rg_nana67_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-3
	.byte		VOL   , 84*mus_rg_nana67_mvl/mxv
	.byte	W96
	.byte		N06   , Gn3 , v116
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W03
	.byte		MOD   , 0
	.byte	W09
	.byte		N12   , An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N36   , Cn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
mus_rg_nana67_3_B1:
	.byte		N24   , Fn4 , v116
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N84   , Ds4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W72
	.byte		        0
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N72   , Dn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W60
	.byte		        0
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N12   , As3 
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N18   , As4 
	.byte	W36
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N72   , As3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W60
	.byte		        0
	.byte	W24
	.byte		VOICE , 24
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N04   , Cs4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Cs4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Cn4 
	.byte	W12
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N12   , As4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N04   , As4 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N24   , Ds5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Fn5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N72   , Fn5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W60
	.byte		        0
	.byte	W12
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N72   , Fn5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W60
	.byte		        0
	.byte	W12
	.byte		N06   , An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N72   , Cn5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W60
	.byte		        0
	.byte	W24
	.byte		N36   , An4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N24   , Fn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_nana67_3_B1
	.byte	W96
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_nana67_4:
	.byte	KEYSH , mus_rg_nana67_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 42*mus_rg_nana67_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_nana67_4_B1:
	.byte		VOICE , 48
	.byte		VOL   , 52*mus_rg_nana67_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N06   , As2 , v080
	.byte	W06
	.byte		        As2 , v048
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N06   , As2 , v080
	.byte	W06
	.byte		        As2 , v048
	.byte	W06
	.byte		        An2 , v080
	.byte	W06
	.byte		        An2 , v048
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , An2 , v080
	.byte	W06
	.byte		        An2 , v048
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N06   , Cn3 , v080
	.byte	W06
	.byte		        Cn3 , v048
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Cn3 , v080
	.byte	W06
	.byte		        Cn3 , v048
	.byte	W06
	.byte		        As2 , v080
	.byte	W06
	.byte		        As2 , v048
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N06   , As2 , v080
	.byte	W06
	.byte		        As2 , v048
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Cn3 , v080
	.byte	W06
	.byte		        Cn3 , v048
	.byte	W06
	.byte		PAN   , c_v+15
	.byte		N06   , Cn3 , v080
	.byte	W06
	.byte		        Cn3 , v048
	.byte	W06
	.byte		        Bn2 , v080
	.byte	W06
	.byte		        Bn2 , v048
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Bn2 , v080
	.byte	W06
	.byte		        Bn2 , v048
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N06   , Dn3 , v080
	.byte	W06
	.byte		        Dn3 , v048
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Dn3 , v080
	.byte	W06
	.byte		        Dn3 , v048
	.byte	W06
	.byte		        Cn3 , v080
	.byte	W06
	.byte		        Cn3 , v048
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N06   , Cn3 , v080
	.byte	W06
	.byte		        Cn3 , v048
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Ds3 , v080
	.byte	W06
	.byte		        Ds3 , v048
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N06   , Ds3 , v080
	.byte	W06
	.byte		        Ds3 , v048
	.byte	W06
	.byte		        Dn3 , v080
	.byte	W06
	.byte		        Dn3 , v048
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Dn3 , v080
	.byte	W06
	.byte		        Dn3 , v048
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N06   , Fn3 , v060
	.byte	W06
	.byte		        Fn3 , v048
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Fn3 , v060
	.byte	W06
	.byte		        Fn3 , v048
	.byte	W06
	.byte		        Ds3 , v080
	.byte	W06
	.byte		        Ds3 , v048
	.byte	W06
	.byte		PAN   , c_v+15
	.byte		N06   , Ds3 , v080
	.byte	W06
	.byte		        Ds3 , v048
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , As2 , v080
	.byte	W06
	.byte		        As2 , v048
	.byte	W06
	.byte		PAN   , c_v+15
	.byte		N06   , As2 , v080
	.byte	W06
	.byte		        As2 , v048
	.byte	W06
	.byte		        An2 , v080
	.byte	W06
	.byte		        An2 , v048
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , An2 , v080
	.byte	W06
	.byte		        An2 , v048
	.byte	W06
	.byte		PAN   , c_v+15
	.byte		N06   , Gn2 , v080
	.byte	W06
	.byte		        Gn2 , v048
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Gn2 , v080
	.byte	W06
	.byte		        Gn2 , v048
	.byte	W06
	.byte		        As2 , v080
	.byte	W06
	.byte		        As2 , v048
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N06   , As2 , v080
	.byte	W06
	.byte		        As2 , v048
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Gn2 , v080
	.byte	W06
	.byte		        Gn2 , v048
	.byte	W06
	.byte		PAN   , c_v+15
	.byte		N06   , Gn2 , v080
	.byte	W06
	.byte		        Gn2 , v048
	.byte	W06
	.byte		        Fs2 , v080
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Fs2 , v080
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		PAN   , c_v+15
	.byte		N06   , An2 , v080
	.byte	W06
	.byte		        An2 , v048
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , An2 , v080
	.byte	W06
	.byte		        An2 , v048
	.byte	W06
	.byte		        Gn2 , v080
	.byte	W06
	.byte		        Gn2 , v048
	.byte	W06
	.byte		PAN   , c_v+15
	.byte		N06   , Gn2 , v080
	.byte	W06
	.byte		        Gn2 , v048
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , As2 , v080
	.byte	W06
	.byte		        As2 , v048
	.byte	W06
	.byte		PAN   , c_v+15
	.byte		N06   , As2 , v080
	.byte	W06
	.byte		        As2 , v048
	.byte	W06
	.byte		        An2 , v080
	.byte	W06
	.byte		        An2 , v048
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , An2 , v080
	.byte	W06
	.byte		        An2 , v048
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N06   , Cn3 , v080
	.byte	W06
	.byte		        Cn3 , v048
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Cn3 , v080
	.byte	W06
	.byte		        Cn3 , v048
	.byte	W06
	.byte		        Dn3 , v080
	.byte	W06
	.byte		        Dn3 , v048
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N06   , Dn3 , v080
	.byte	W06
	.byte		        Dn3 , v048
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Ds3 , v080
	.byte	W06
	.byte		        Ds3 , v048
	.byte	W06
	.byte		PAN   , c_v+15
	.byte		N06   , Ds3 , v080
	.byte	W06
	.byte		        Ds3 , v048
	.byte	W06
	.byte		        As2 , v080
	.byte	W06
	.byte		        As2 , v048
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , As2 , v080
	.byte	W06
	.byte		        As2 , v048
	.byte	W06
	.byte		PAN   , c_v+15
	.byte		N06   , An2 , v080
	.byte	W06
	.byte		        An2 , v048
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , An2 , v080
	.byte	W06
	.byte		        An2 , v048
	.byte	W06
	.byte		        Cn3 , v080
	.byte	W06
	.byte		        Cn3 , v048
	.byte	W06
	.byte		PAN   , c_v+15
	.byte		N06   , Cn3 , v080
	.byte	W06
	.byte		        Cn3 , v048
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , As2 , v080
	.byte	W06
	.byte		        As2 , v048
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N06   , As2 , v080
	.byte	W06
	.byte		        As2 , v048
	.byte	W06
	.byte		        As2 , v080
	.byte	W06
	.byte		        As2 , v048
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , An2 , v080
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		PAN   , c_v+15
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Dn2 , v048
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Dn2 , v080
	.byte	W06
	.byte		        Dn2 , v048
	.byte	W06
	.byte		        Fn2 , v080
	.byte	W06
	.byte		        Fn2 , v048
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N06   , Fn2 , v080
	.byte	W06
	.byte		        Fn2 , v048
	.byte	W06
	.byte		VOICE , 17
	.byte		PAN   , c_v-32
	.byte		VOL   , 39*mus_rg_nana67_mvl/mxv
	.byte		N06   , Fs4 , v080
	.byte	W12
	.byte		N03   , Cs4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		N12   , As4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		N04   , Cn5 , v088
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		N06   , As4 , v080
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W12
	.byte		N03   , Fn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		N24   , Fn5 
	.byte	W24
	.byte		N06   , As4 
	.byte	W12
	.byte		N03   , An4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		N24   , As5 
	.byte	W24
	.byte		N36   , Gs5 
	.byte	W36
	.byte		N24   , Fs5 
	.byte	W24
	.byte		        Ds5 
	.byte	W24
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		N36   , As5 
	.byte	W36
	.byte		N24   , Gs5 
	.byte	W24
	.byte		        Fn5 
	.byte	W24
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N36   , Fn5 
	.byte	W36
	.byte		        Gn5 
	.byte	W36
	.byte		N12   , As4 
	.byte	W12
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N36   , Fn5 
	.byte	W36
	.byte		        Gn5 
	.byte	W36
	.byte		N12   , As4 
	.byte	W12
	.byte		N06   , An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N36   , Cn5 
	.byte	W36
	.byte		        An5 
	.byte	W60
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_nana67_4_B1
	.byte	W96
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_nana67_5:
	.byte	KEYSH , mus_rg_nana67_key+0
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-64
	.byte		VOL   , 46*mus_rg_nana67_mvl/mxv
	.byte	W96
	.byte		N06   , Ds3 , v080
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N24   , Ds3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N24   , Gn2 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N06   , As2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N24   , En2 
	.byte	W24
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N06   , An2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W24
	.byte		N24   , An3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		VOICE , 80
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
mus_rg_nana67_5_B1:
	.byte		N24   , Dn4 , v080
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W12
	.byte		        0
	.byte		N06   
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N30   , Cn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		N24   , Fn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , An3 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N24   , An3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Fn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , An3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , As3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Cs4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N18   , Dn4 
	.byte	W18
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		N12   , As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N06   , As3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , As3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N18   , Dn4 , v092
	.byte	W12
	.byte		MOD   , 6
	.byte	W06
	.byte		N03   , Dn4 , v080
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		MOD   , 0
	.byte		N18   , Gn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N03   , En4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		VOICE , 82
	.byte		N12   , As3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N36   , Fn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N18   , Dn3 
	.byte	W18
	.byte		N03   , Cn3 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		N24   , As2 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N36   , Cs5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N36   , Cn5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N12   , An4 
	.byte	W12
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N18   , As4 
	.byte	W18
	.byte		N06   , Cn5 
	.byte	W06
	.byte		N36   , Cs5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N12   , Cn5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N06   , As4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N72   , Fn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W60
	.byte		        0
	.byte	W24
	.byte		N36   
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N06   
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N18   , An4 
	.byte	W18
	.byte		N03   , Gn4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		N12   , Cn4 
	.byte	W12
	.byte		VOICE , 80
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_nana67_5_B1
	.byte	W96
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_nana67_6:
	.byte	KEYSH , mus_rg_nana67_key+0
	.byte		VOICE , 92
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 42*mus_rg_nana67_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte		N06   , Gn3 , v040
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N12   , As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   , An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N36   , Cn4 
	.byte	W48
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
mus_rg_nana67_6_B1:
	.byte		N24   , Fn4 , v040
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N84   , Ds4 
	.byte	W84
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N24   , Ds4 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N72   , Dn4 
	.byte	W84
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N24   , Dn4 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N12   , As3 
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		N18   , As4 
	.byte	W36
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N72   , As3 
	.byte	W96
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N04   , Cs4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N24   , Ds4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N12   , As4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N04   , As4 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N24   , Ds5 
	.byte	W24
	.byte		        Fn5 
	.byte	W24
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N72   , Fn5 
	.byte	W84
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N72   , Fn5 
	.byte	W84
	.byte		N06   , An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N72   , Cn5 
	.byte	W96
	.byte		N36   , An4 
	.byte	W36
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N24   , Fn4 
	.byte	W36
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_nana67_6_B1
	.byte	W96
	.byte	FINE

@********************** Track  7 **********************@

mus_rg_nana67_7:
	.byte	KEYSH , mus_rg_nana67_key+0
	.byte		VOICE , 0
	.byte		VOL   , 74*mus_rg_nana67_mvl/mxv
	.byte		N12   , Cn1 , v112
	.byte	W12
	.byte		N06   , Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		        Cn3 , v080
	.byte	W24
	.byte		VOL   , 63*mus_rg_nana67_mvl/mxv
	.byte		N06   , Cs1 , v112
	.byte		N48   , Gn2 , v096
	.byte	W06
	.byte		N06   , Cs1 , v112
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W72
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte		N48   , Bn2 , v104
	.byte	W72
	.byte		N06   , Cs1 , v112
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W03
	.byte		N02   , Bn1 
	.byte	W03
	.byte		        Gn1 
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Cs1 
	.byte		N44   , An2 
	.byte	W12
	.byte		N05   , Cn1 , v124
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W06
	.byte		N05   
	.byte	W18
	.byte		        Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		N06   , Cs1 
	.byte	W06
	.byte		        Cn1 , v092
	.byte	W06
	.byte		        Dn2 , v112
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cs1 
	.byte	W12
	.byte		N05   
	.byte		N36   , Cs2 
	.byte	W12
	.byte		N05   , Dn2 
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		N06   , Cs1 
	.byte	W06
	.byte		N05   , Cn1 
	.byte	W06
mus_rg_nana67_7_B1:
mus_rg_nana67_7_000:
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W30
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PEND
	.byte		N06   
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Fn2 , v064
	.byte	W12
	.byte		        Cs1 , v112
	.byte	W06
	.byte		        Fn2 , v080
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W30
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W30
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Fn2 , v064
	.byte	W12
	.byte		        Cs1 , v112
	.byte	W06
	.byte		        Fn2 , v080
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
mus_rg_nana67_7_001:
	.byte		N06   , Cn1 , v112
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_nana67_7_000
	.byte	PATT
	 .word	mus_rg_nana67_7_000
	.byte	PATT
	 .word	mus_rg_nana67_7_000
	.byte	PATT
	 .word	mus_rg_nana67_7_001
	.byte	PATT
	 .word	mus_rg_nana67_7_001
	.byte	PATT
	 .word	mus_rg_nana67_7_001
	.byte	PATT
	 .word	mus_rg_nana67_7_001
	.byte	PATT
	 .word	mus_rg_nana67_7_001
	.byte	PATT
	 .word	mus_rg_nana67_7_001
	.byte	PATT
	 .word	mus_rg_nana67_7_001
	.byte	PATT
	 .word	mus_rg_nana67_7_001
	.byte	GOTO
	 .word	mus_rg_nana67_7_B1
	.byte	W96
	.byte	FINE

@********************** Track  8 **********************@

mus_rg_nana67_8:
	.byte	KEYSH , mus_rg_nana67_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 49*mus_rg_nana67_mvl/mxv
	.byte	W96
	.byte		N01   , Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W12
	.byte		        Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v052
	.byte	W12
	.byte		        Cn5 , v112
	.byte	W06
	.byte		N01   
	.byte	W18
	.byte		N01   
	.byte	W06
	.byte		        Cn5 , v068
	.byte	W06
	.byte		        Cn5 , v092
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W12
	.byte		        Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v052
	.byte	W12
	.byte		        Cn5 , v112
	.byte	W06
	.byte		        Cn5 , v068
	.byte	W03
	.byte		        Cn5 , v060
	.byte	W15
	.byte		        Cn5 , v112
	.byte	W06
	.byte		        Cn5 , v068
	.byte	W06
	.byte		        Cn5 , v092
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W12
	.byte		        Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v112
	.byte	W06
	.byte		N01   
	.byte	W18
	.byte		N01   
	.byte	W06
	.byte		        Cn5 , v068
	.byte	W06
	.byte		        Cn5 , v092
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W12
	.byte		        Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v084
	.byte	W24
mus_rg_nana67_8_B1:
mus_rg_nana67_8_000:
	.byte		N01   , Cn5 , v112
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W12
	.byte		        Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W12
	.byte	PEND
	.byte		        Cn5 , v112
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Cn5 , v068
	.byte	W03
	.byte		        Cn5 , v060
	.byte	W15
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W18
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte	PATT
	 .word	mus_rg_nana67_8_000
	.byte		N01   , Cn5 , v112
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Cn5 , v068
	.byte	W03
	.byte		        Cn5 , v060
	.byte	W15
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W18
	.byte	PATT
	 .word	mus_rg_nana67_8_000
	.byte		N01   , Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v112
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Cn5 , v068
	.byte	W03
	.byte		        Cn5 , v060
	.byte	W15
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte	PATT
	 .word	mus_rg_nana67_8_000
	.byte		N01   , Cn5 , v112
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W12
mus_rg_nana67_8_001:
	.byte		N01   , Cn5 , v112
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Cn5 , v068
	.byte	W03
	.byte		        Cn5 , v060
	.byte	W15
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		        Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W12
	.byte	PEND
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W18
	.byte		N01   
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W18
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		        Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W18
	.byte	PATT
	 .word	mus_rg_nana67_8_001
	.byte		N01   , Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W18
	.byte		N01   
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W18
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W18
	.byte		        Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v112
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Cn5 , v068
	.byte	W03
	.byte		        Cn5 , v060
	.byte	W03
	.byte		        Cn5 , v072
	.byte	W24
	.byte		        Cn5 , v112
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Cn5 , v068
	.byte	W03
	.byte		        Cn5 , v060
	.byte	W03
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v112
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Cn5 , v068
	.byte	W03
	.byte		        Cn5 , v060
	.byte	W03
	.byte		        Cn5 , v072
	.byte	W24
	.byte		        Cn5 , v112
	.byte	W06
	.byte		        Cn5 , v056
	.byte	W18
	.byte		        Cn5 , v112
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Cn5 , v068
	.byte	W03
	.byte		        Cn5 , v060
	.byte	W03
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W18
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W18
	.byte		N01   
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_nana67_8_B1
	.byte	W96
	.byte	FINE

@********************** Track  9 **********************@

mus_rg_nana67_9:
	.byte	KEYSH , mus_rg_nana67_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 42*mus_rg_nana67_mvl/mxv
	.byte	W72
	.byte		N24   , Gn5 , v112
	.byte	W24
	.byte	W60
	.byte		N12   
	.byte	W36
	.byte	W60
	.byte		N12   
	.byte	W36
	.byte	W60
	.byte		N12   
	.byte	W36
	.byte	W84
	.byte		N11   
	.byte	W12
mus_rg_nana67_9_B1:
	.byte	W96
	.byte	W24
	.byte		N12   , Gn5 , v080
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte	W96
	.byte	W24
	.byte		N12   
	.byte	W60
	.byte		N12   
	.byte	W12
	.byte	W96
	.byte	W72
	.byte		N12   
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		N12   
	.byte	W72
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	W24
	.byte		N12   
	.byte	W72
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte	W60
	.byte		N11   , Gn5 , v112
	.byte	W36
	.byte	W60
	.byte		N11   
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte	W96
	.byte		N12   , Gn5 , v080
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	GOTO
	 .word	mus_rg_nana67_9_B1
	.byte	W96
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_nana67:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_nana67_pri	@ Priority
	.byte	mus_rg_nana67_rev	@ Reverb.

	.word	mus_rg_nana67_grp

	.word	mus_rg_nana67_1
	.word	mus_rg_nana67_2
	.word	mus_rg_nana67_3
	.word	mus_rg_nana67_4
	.word	mus_rg_nana67_5
	.word	mus_rg_nana67_6
	.word	mus_rg_nana67_7
	.word	mus_rg_nana67_8
	.word	mus_rg_nana67_9

	.end
