	.include "MPlayDef.s"

	.equ	bgm_deepdeep_grp, voicegroup_8684E48
	.equ	bgm_deepdeep_pri, 0
	.equ	bgm_deepdeep_rev, reverb_set+50
	.equ	bgm_deepdeep_mvl, 127
	.equ	bgm_deepdeep_key, 0
	.equ	bgm_deepdeep_tbs, 1
	.equ	bgm_deepdeep_exg, 0
	.equ	bgm_deepdeep_cmp, 1

	.section .rodata
	.global	bgm_deepdeep
	.align	2

@********************** Track  1 **********************@

bgm_deepdeep_1:
	.byte	KEYSH , bgm_deepdeep_key+0
	.byte	TEMPO , 86*bgm_deepdeep_tbs/2
	.byte		VOICE , 46
	.byte		PAN   , c_v+16
	.byte		VOL   , 75*bgm_deepdeep_mvl/mxv
	.byte	W96
bgm_deepdeep_1_000:
	.byte		N04   , Gn1 , v112
	.byte	W04
	.byte		        Gn1 , v036
	.byte	W04
	.byte		        Bn1 , v112
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Dn2 , v036
	.byte	W04
	.byte		        Fs2 , v112
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Dn3 , v036
	.byte	W04
	.byte		        Fs3 , v112
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Gn3 , v036
	.byte	W04
	.byte		        Bn3 , v112
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Dn4 , v036
	.byte	W04
	.byte		        Fs4 , v112
	.byte	W04
	.byte		PAN   , c_v-16
	.byte		N04   , An4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte	PEND
	.byte		        Fn1 
	.byte	W04
	.byte		        Fn1 , v036
	.byte	W04
	.byte		        An1 , v112
	.byte	W04
	.byte		        Cn2 
	.byte	W04
	.byte		        Cn2 , v036
	.byte	W04
	.byte		        En2 , v112
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Cn3 , v036
	.byte	W04
	.byte		        En3 , v112
	.byte	W04
	.byte		        Fn3 
	.byte	W08
	.byte		        An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Cn4 , v036
	.byte	W04
	.byte		        En4 , v112
	.byte	W04
	.byte		PAN   , c_v+16
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte	PATT
	 .word	bgm_deepdeep_1_000
	.byte		N04   , Gs1 , v112
	.byte	W04
	.byte		        Gs1 , v036
	.byte	W04
	.byte		        Cn2 , v112
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        Ds2 , v036
	.byte	W04
	.byte		        Gn2 , v112
	.byte	W04
	.byte		        Gs2 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Ds3 , v036
	.byte	W04
	.byte		        Gn3 , v112
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Gs3 , v036
	.byte	W04
	.byte		        Cn4 , v112
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Ds4 , v036
	.byte	W04
	.byte		        Gn4 , v112
	.byte	W04
	.byte		PAN   , c_v+16
	.byte		N04   , As4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte	PATT
	 .word	bgm_deepdeep_1_000
bgm_deepdeep_1_001:
	.byte		N04   , Fn1 , v112
	.byte	W04
	.byte		        Fn1 , v036
	.byte	W04
	.byte		        An1 , v112
	.byte	W04
	.byte		        Cn2 
	.byte	W04
	.byte		        Cn2 , v036
	.byte	W04
	.byte		        En2 , v112
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Cn3 , v036
	.byte	W04
	.byte		        En3 , v112
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Fn3 , v036
	.byte	W04
	.byte		        An3 , v112
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Cn4 , v036
	.byte	W04
	.byte		        En4 , v112
	.byte	W04
	.byte		PAN   , c_v+16
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	bgm_deepdeep_1_000
	.byte	TEMPO , 86*bgm_deepdeep_tbs/2
	.byte		N04   , Gs1 , v112
	.byte	W04
	.byte		        Gs1 , v036
	.byte	W04
	.byte		        Cn2 , v112
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        Ds2 , v036
	.byte	W04
	.byte		        Gn2 , v112
	.byte	W04
	.byte		        Gs2 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Ds3 , v036
	.byte	W04
	.byte		        Gn3 , v112
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Gs3 , v036
	.byte	W04
	.byte		        Cn4 , v112
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Ds4 , v036
	.byte	W04
	.byte		        Gn4 , v112
	.byte	W04
	.byte		PAN   , c_v+16
	.byte		N04   , As4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
bgm_deepdeep_1_B1:
bgm_deepdeep_1_002:
	.byte		N04   , Ds1 , v112
	.byte	W04
	.byte		        Gn1 
	.byte	W04
	.byte		        As1 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		PAN   , c_v-16
	.byte		N04   , As4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte	PEND
bgm_deepdeep_1_003:
	.byte		N04   , Dn1 , v112
	.byte	W04
	.byte		        Dn1 , v036
	.byte	W04
	.byte		        Fs1 , v112
	.byte	W04
	.byte		        An1 
	.byte	W04
	.byte		        An1 , v036
	.byte	W04
	.byte		        Cs2 , v112
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        En2 
	.byte	W04
	.byte		        Fs2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        An2 , v036
	.byte	W04
	.byte		        Cs3 , v112
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Dn3 , v036
	.byte	W04
	.byte		        Fs3 , v112
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        An3 , v036
	.byte	W04
	.byte		        Cs4 , v112
	.byte	W04
	.byte		PAN   , c_v+16
	.byte		N04   , En4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte	PEND
bgm_deepdeep_1_004:
	.byte		N04   , Gs1 , v112
	.byte	W04
	.byte		        Cn2 
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        Gs2 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		PAN   , c_v-16
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        Gn4 , v032
	.byte	W04
	.byte		        Gn4 , v112
	.byte	W04
	.byte		        Gn4 , v032
	.byte	W04
	.byte		        Gn4 , v112
	.byte	W04
	.byte		        Gn4 , v032
	.byte	W04
	.byte		        Fn4 , v112
	.byte	W04
	.byte		        Fn4 , v036
	.byte	W04
	.byte		        Ds4 , v112
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Dn4 , v036
	.byte	W04
	.byte		        As3 , v112
	.byte	W04
	.byte	PEND
bgm_deepdeep_1_005:
	.byte		N04   , Gn1 , v112
	.byte	W04
	.byte		        Bn1 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Fs2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		PAN   , c_v+16
	.byte		N04   , An4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	bgm_deepdeep_1_000
	.byte	PATT
	 .word	bgm_deepdeep_1_001
	.byte	PATT
	 .word	bgm_deepdeep_1_000
bgm_deepdeep_1_006:
	.byte		N04   , Fn1 , v112
	.byte	W04
	.byte		        Fn1 , v036
	.byte	W04
	.byte		        An1 , v112
	.byte	W04
	.byte		        Cn2 
	.byte	W04
	.byte		        Cn2 , v036
	.byte	W04
	.byte		        En2 , v112
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Cn3 , v036
	.byte	W04
	.byte		        En3 , v112
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Fn3 , v036
	.byte	W04
	.byte		        An3 , v112
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Cn4 , v036
	.byte	W04
	.byte		        En4 , v112
	.byte	W04
	.byte		PAN   , c_v+16
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte	PEND
	.byte		        Ds1 
	.byte	W04
	.byte		        Gn1 
	.byte	W04
	.byte		        As1 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		PAN   , c_v-16
	.byte		N04   , Ds4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte	PATT
	 .word	bgm_deepdeep_1_003
	.byte	PATT
	 .word	bgm_deepdeep_1_004
	.byte		N04   , Gn1 , v112
	.byte	W04
	.byte		        Gn1 , v036
	.byte	W04
	.byte		        Bn1 , v112
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Dn2 , v036
	.byte	W04
	.byte		        Fs2 , v112
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Dn3 , v036
	.byte	W04
	.byte		        Fs3 , v112
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Gn3 , v036
	.byte	W04
	.byte		        Bn3 , v112
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Dn4 , v036
	.byte	W04
	.byte		        Fs4 , v112
	.byte	W04
	.byte		PAN   , c_v+16
	.byte		N04   , An4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte	PATT
	 .word	bgm_deepdeep_1_002
	.byte	PATT
	 .word	bgm_deepdeep_1_003
	.byte	PATT
	 .word	bgm_deepdeep_1_004
	.byte	PATT
	 .word	bgm_deepdeep_1_005
	.byte	PATT
	 .word	bgm_deepdeep_1_000
	.byte		N04   , Fn1 , v112
	.byte	W04
	.byte		        Fn1 , v036
	.byte	W04
	.byte		        An1 , v112
	.byte	W04
	.byte		        Cn2 
	.byte	W04
	.byte		        Cn2 , v036
	.byte	W04
	.byte		        En2 , v112
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Cn3 , v036
	.byte	W04
	.byte		        En3 , v112
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Fn3 , v036
	.byte	W04
	.byte		        An3 , v112
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Cn4 , v036
	.byte	W04
	.byte		        En4 , v112
	.byte	W04
	.byte		PAN   , c_v+16
	.byte		N04   , Fn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte	PATT
	 .word	bgm_deepdeep_1_000
	.byte	PATT
	 .word	bgm_deepdeep_1_006
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_deepdeep_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_deepdeep_2:
	.byte	KEYSH , bgm_deepdeep_key+0
	.byte		VOICE , 23
	.byte		PAN   , c_v+0
	.byte		VOL   , 47*bgm_deepdeep_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_deepdeep_2_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOL   , 34*bgm_deepdeep_mvl/mxv
	.byte		N04   , Cn2 , v064
	.byte	W04
	.byte		        Ds2 , v044
	.byte	W04
	.byte		        Gs2 
	.byte	W04
	.byte		        Cn2 , v064
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		N02   , Fn2 , v044
	.byte	W02
	.byte		        Cn2 , v064
	.byte	W02
	.byte		VOL   , 42*bgm_deepdeep_mvl/mxv
	.byte		N04   , An1 
	.byte	W04
	.byte		        Bn1 
	.byte	W04
	.byte		        An1 , v048
	.byte	W04
	.byte		        As1 , v040
	.byte	W04
	.byte		        Bn1 , v048
	.byte	W04
	.byte		        An1 , v064
	.byte	W04
	.byte		VOL   , 47*bgm_deepdeep_mvl/mxv
	.byte		N04   , Cn2 
	.byte	W04
	.byte		        As1 , v048
	.byte	W04
	.byte		        Ds2 , v060
	.byte	W04
	.byte		        Bn1 , v040
	.byte	W04
	.byte		        En2 , v060
	.byte	W04
	.byte		        An1 , v064
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		N02   , Bn1 , v044
	.byte	W02
	.byte		        Dn2 , v032
	.byte	W02
	.byte		N04   , Cn3 , v064
	.byte	W04
	.byte		        As1 , v044
	.byte	W04
	.byte		        Ds3 , v060
	.byte	W04
	.byte		        As1 , v032
	.byte	W04
	.byte		        Cs2 , v064
	.byte	W04
	.byte		N02   , Dn2 
	.byte	W02
	.byte		        Cn2 
	.byte	W02
	.byte		N04   , Cs2 , v040
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        An1 
	.byte	W04
	.byte		VOL   , 42*bgm_deepdeep_mvl/mxv
	.byte		N04   , Bn1 , v064
	.byte	W04
	.byte		        Gs1 
	.byte	W04
	.byte		        Cn2 , v032
	.byte	W04
	.byte		        As1 
	.byte	W04
	.byte		        En2 , v040
	.byte	W04
	.byte		        Bn1 , v064
	.byte	W04
	.byte		VOL   , 37*bgm_deepdeep_mvl/mxv
	.byte		N04   , Gn2 
	.byte	W04
	.byte		        Cs2 , v040
	.byte	W04
	.byte		        An2 , v064
	.byte	W04
	.byte		        Cn2 , v040
	.byte	W04
	.byte		        Bn2 , v064
	.byte	W04
	.byte		        Bn1 , v040
	.byte	W04
	.byte		VOL   , 31*bgm_deepdeep_mvl/mxv
	.byte		N04   , As2 , v064
	.byte	W04
	.byte		        Dn2 , v040
	.byte	W04
	.byte		        Dn3 , v068
	.byte	W04
	.byte		        Cs2 , v040
	.byte	W04
	.byte		        Fn3 , v068
	.byte	W04
	.byte		        Cn2 , v044
	.byte	W04
	.byte	GOTO
	 .word	bgm_deepdeep_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_deepdeep_3:
	.byte	KEYSH , bgm_deepdeep_key+0
	.byte		VOICE , 35
	.byte		PAN   , c_v+0
	.byte		VOL   , 94*bgm_deepdeep_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_deepdeep_3_B1:
bgm_deepdeep_3_000:
	.byte		N04   , Ds1 , v127
	.byte	W08
	.byte		        Dn1 
	.byte	W04
	.byte		N08   , Ds1 
	.byte	W08
	.byte		N04   , Gn1 
	.byte	W04
	.byte		N08   , Gn1 , v036
	.byte	W08
	.byte		N04   , As1 , v127
	.byte	W04
	.byte		N08   , As1 , v036
	.byte	W08
	.byte		N04   , Dn2 , v127
	.byte	W04
	.byte		N08   , Dn2 , v036
	.byte	W32
	.byte		N04   , Dn2 , v127
	.byte	W04
	.byte		N12   , Ds1 
	.byte	W12
	.byte	PEND
bgm_deepdeep_3_001:
	.byte		N04   , Dn1 , v127
	.byte	W08
	.byte		        Cs1 
	.byte	W04
	.byte		N08   , Dn1 
	.byte	W08
	.byte		N04   , Fs1 
	.byte	W04
	.byte		N08   , Fs1 , v036
	.byte	W08
	.byte		N04   , An1 , v127
	.byte	W04
	.byte		N08   , An1 , v036
	.byte	W08
	.byte		N04   , Cs2 , v127
	.byte	W04
	.byte		N08   , Cs2 , v036
	.byte	W20
	.byte		N04   , Cs2 , v127
	.byte	W04
	.byte		N08   , Cs2 , v036
	.byte	W08
	.byte		N04   , Cs2 , v127
	.byte	W04
	.byte		N12   , Dn1 
	.byte	W12
	.byte	PEND
	.byte		N04   , Fn1 
	.byte	W08
	.byte		        En1 
	.byte	W04
	.byte		N08   , Fn1 
	.byte	W08
	.byte		N04   , Gs1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W04
	.byte		        Ds2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Dn2 
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Cn2 
	.byte	W08
	.byte		        Gs1 
	.byte	W04
bgm_deepdeep_3_002:
	.byte		N04   , Gn1 , v127
	.byte	W08
	.byte		        Fs1 
	.byte	W04
	.byte		N08   , Gn1 
	.byte	W08
	.byte		N04   , Bn1 
	.byte	W04
	.byte		N08   , Bn1 , v036
	.byte	W08
	.byte		N04   , Dn2 , v127
	.byte	W04
	.byte		N08   , Dn2 , v036
	.byte	W08
	.byte		N04   , Fs2 , v127
	.byte	W04
	.byte		N08   , Fs2 , v036
	.byte	W08
	.byte		N04   , Fs2 , v127
	.byte	W04
	.byte		N08   , Gn1 
	.byte	W12
	.byte		N04   , Fs2 
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte	PEND
bgm_deepdeep_3_003:
	.byte		N12   , Gn1 , v127
	.byte	W12
	.byte		N08   , Gn1 , v036
	.byte	W08
	.byte		N04   , Gn1 , v127
	.byte	W04
	.byte		N08   , Gn1 , v036
	.byte	W68
	.byte		N04   , Gn2 , v127
	.byte	W04
	.byte	PEND
bgm_deepdeep_3_004:
	.byte		N12   , Fn1 , v127
	.byte	W12
	.byte		N08   , Fn1 , v036
	.byte	W08
	.byte		N04   , Fn1 , v127
	.byte	W04
	.byte		N08   , Fn1 , v036
	.byte	W68
	.byte		N04   , Gn2 , v127
	.byte	W04
	.byte	PEND
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N08   , Gn1 , v036
	.byte	W08
	.byte		N04   , Gn1 , v124
	.byte	W04
	.byte		N08   , Gn1 , v036
	.byte	W68
	.byte		N04   , Gn2 , v127
	.byte	W04
bgm_deepdeep_3_005:
	.byte		N12   , Fn1 , v127
	.byte	W12
	.byte		N08   , Fn1 , v036
	.byte	W08
	.byte		N04   , Fn1 , v127
	.byte	W04
	.byte		N08   , Fn1 , v036
	.byte	W72
	.byte	PEND
	.byte	PATT
	 .word	bgm_deepdeep_3_000
	.byte	PATT
	 .word	bgm_deepdeep_3_001
	.byte		N04   , Fn1 , v127
	.byte	W08
	.byte		        En1 
	.byte	W04
	.byte		N08   , Fn1 
	.byte	W08
	.byte		N04   , Gs1 
	.byte	W04
	.byte		N08   , Gs1 , v036
	.byte	W08
	.byte		N04   , Cn2 , v127
	.byte	W04
	.byte		N08   , Cn2 , v036
	.byte	W08
	.byte		N04   , Dn2 , v127
	.byte	W04
	.byte		        Ds2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Dn2 
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Cn2 
	.byte	W08
	.byte		        Gs1 
	.byte	W04
	.byte	PATT
	 .word	bgm_deepdeep_3_002
	.byte	PATT
	 .word	bgm_deepdeep_3_000
	.byte		N04   , Dn1 , v127
	.byte	W08
	.byte		        Cs1 
	.byte	W04
	.byte		N08   , Dn1 
	.byte	W08
	.byte		N04   , Fs1 
	.byte	W04
	.byte		N08   
	.byte	W08
	.byte		N04   , An1 
	.byte	W04
	.byte		N08   , An1 , v036
	.byte	W08
	.byte		N04   , Cs2 , v127
	.byte	W06
	.byte		N08   , Cs2 , v036
	.byte	W18
	.byte		N04   , Cs2 , v127
	.byte	W04
	.byte		N08   , Cs2 , v036
	.byte	W08
	.byte		N04   , Cs2 , v127
	.byte	W04
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N04   , Fn1 
	.byte	W08
	.byte		        En1 
	.byte	W04
	.byte		N08   , Fn1 
	.byte	W08
	.byte		N04   , Gs1 
	.byte	W04
	.byte		N08   
	.byte	W08
	.byte		N04   , Cn2 
	.byte	W04
	.byte		N08   , Cn2 , v036
	.byte	W08
	.byte		N04   , Dn2 , v127
	.byte	W04
	.byte		        Ds2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Dn2 
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Cn2 
	.byte	W08
	.byte		        Gs1 
	.byte	W04
	.byte		        Gn1 
	.byte	W08
	.byte		        Fs1 
	.byte	W04
	.byte		N08   , Gn1 
	.byte	W08
	.byte		N04   , Bn1 
	.byte	W04
	.byte		N08   
	.byte	W08
	.byte		N04   , Dn2 
	.byte	W04
	.byte		N08   , Dn2 , v036
	.byte	W08
	.byte		N04   , Fs2 , v127
	.byte	W04
	.byte		N08   , Fs2 , v036
	.byte	W08
	.byte		N04   , Fs2 , v127
	.byte	W04
	.byte		N08   , Gn1 
	.byte	W12
	.byte		N04   , Fs2 
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		N12   , Gn1 , v124
	.byte	W12
	.byte		N08   , Gn1 , v036
	.byte	W08
	.byte		N04   , Gn1 , v127
	.byte	W04
	.byte		N08   , Gn1 , v036
	.byte	W68
	.byte		N04   , Gn2 , v127
	.byte	W04
	.byte	PATT
	 .word	bgm_deepdeep_3_004
	.byte	PATT
	 .word	bgm_deepdeep_3_003
	.byte	PATT
	 .word	bgm_deepdeep_3_005
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_deepdeep_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_deepdeep_4:
	.byte	KEYSH , bgm_deepdeep_key+0
	.byte		VOICE , 126
	.byte		VOL   , 31*bgm_deepdeep_mvl/mxv
	.byte		PAN   , c_v-64
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 126
	.byte	W12
	.byte		N08   , Gn4 , v064
	.byte	W24
	.byte		        Gn4 , v092
	.byte	W24
	.byte		        Gn4 , v127
	.byte	W36
bgm_deepdeep_4_B1:
bgm_deepdeep_4_000:
	.byte	W24
	.byte		N10   , Gn4 , v112
	.byte	W36
	.byte		N10   
	.byte	W36
	.byte	PEND
bgm_deepdeep_4_001:
	.byte	W24
	.byte		N10   , Gn4 , v112
	.byte	W36
	.byte		N10   
	.byte	W24
	.byte		N10   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_deepdeep_4_000
	.byte	PATT
	 .word	bgm_deepdeep_4_001
	.byte	PATT
	 .word	bgm_deepdeep_4_000
	.byte	PATT
	 .word	bgm_deepdeep_4_001
	.byte	PATT
	 .word	bgm_deepdeep_4_000
	.byte	PATT
	 .word	bgm_deepdeep_4_001
	.byte	PATT
	 .word	bgm_deepdeep_4_000
	.byte	PATT
	 .word	bgm_deepdeep_4_001
	.byte	PATT
	 .word	bgm_deepdeep_4_000
	.byte	PATT
	 .word	bgm_deepdeep_4_001
	.byte	PATT
	 .word	bgm_deepdeep_4_000
	.byte	PATT
	 .word	bgm_deepdeep_4_001
	.byte	PATT
	 .word	bgm_deepdeep_4_000
	.byte	PATT
	 .word	bgm_deepdeep_4_001
	.byte	PATT
	 .word	bgm_deepdeep_4_000
	.byte	PATT
	 .word	bgm_deepdeep_4_001
	.byte	PATT
	 .word	bgm_deepdeep_4_000
	.byte	PATT
	 .word	bgm_deepdeep_4_001
	.byte	PATT
	 .word	bgm_deepdeep_4_000
	.byte	PATT
	 .word	bgm_deepdeep_4_001
	.byte	GOTO
	 .word	bgm_deepdeep_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_deepdeep_5:
	.byte	KEYSH , bgm_deepdeep_key+0
	.byte		VOICE , 9
	.byte		PAN   , c_v-32
	.byte		VOL   , 15*bgm_deepdeep_mvl/mxv
	.byte		N04   , Gn4 , v080
	.byte	W08
	.byte		        Gn4 , v052
	.byte	W04
	.byte		N12   , Gn5 , v084
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		VOL   , 26*bgm_deepdeep_mvl/mxv
	.byte		N04   , Gn4 , v080
	.byte	W04
	.byte		        Gn4 , v044
	.byte	W04
	.byte		        Gn4 , v060
	.byte	W04
	.byte		N12   , Gn5 , v084
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		VOL   , 35*bgm_deepdeep_mvl/mxv
	.byte		N04   , Gn4 , v080
	.byte	W08
	.byte		        Gn4 , v052
	.byte	W04
	.byte		N12   , Gn5 , v084
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		VOL   , 47*bgm_deepdeep_mvl/mxv
	.byte		N04   , Gn4 , v080
	.byte	W08
	.byte		        Gn4 , v052
	.byte	W04
	.byte		N08   , Gn5 , v084
	.byte	W08
	.byte		N04   , Gn5 , v052
	.byte	W04
	.byte		VOL   , 53*bgm_deepdeep_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N04   , Gn4 , v080
	.byte	W04
	.byte		        Gn4 , v048
	.byte	W04
	.byte		        Gn4 , v072
	.byte	W04
	.byte		N08   , Gn5 , v084
	.byte	W08
	.byte		N04   , Gn5 , v064
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Gn4 , v080
	.byte	W08
	.byte		        Gn4 , v052
	.byte	W04
	.byte		N12   , Gn5 , v084
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N04   , Gn4 , v080
	.byte	W08
	.byte		        Gn4 , v052
	.byte	W04
	.byte		N08   , Gn5 , v084
	.byte	W08
	.byte		N04   , Gn5 , v056
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Gn4 , v080
	.byte	W08
	.byte		        Gn4 , v052
	.byte	W04
	.byte		N12   , Gn5 , v084
	.byte	W12
bgm_deepdeep_5_000:
	.byte		PAN   , c_v-32
	.byte		N04   , Gn4 , v080
	.byte	W08
	.byte		        Gn4 , v052
	.byte	W04
	.byte		N12   , Gn5 , v084
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N04   , Gn4 , v080
	.byte	W04
	.byte		        Gn4 , v044
	.byte	W04
	.byte		        Gn4 , v060
	.byte	W04
	.byte		N12   , Gn5 , v084
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N04   , Gn4 , v080
	.byte	W08
	.byte		        Gn4 , v052
	.byte	W04
	.byte		N12   , Gn5 , v084
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N04   , Gn4 , v080
	.byte	W08
	.byte		        Gn4 , v052
	.byte	W04
	.byte		N08   , Gn5 , v084
	.byte	W08
	.byte		N04   , Gn5 , v052
	.byte	W04
	.byte	PEND
bgm_deepdeep_5_001:
	.byte		PAN   , c_v-32
	.byte		N04   , Gn4 , v080
	.byte	W04
	.byte		        Gn4 , v048
	.byte	W04
	.byte		        Gn4 , v072
	.byte	W04
	.byte		N08   , Gn5 , v084
	.byte	W08
	.byte		N04   , Gn5 , v064
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Gn4 , v080
	.byte	W08
	.byte		        Gn4 , v052
	.byte	W04
	.byte		N12   , Gn5 , v084
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N04   , Gn4 , v080
	.byte	W08
	.byte		        Gn4 , v052
	.byte	W04
	.byte		N08   , Gn5 , v084
	.byte	W08
	.byte		N04   , Gn5 , v056
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Gn4 , v080
	.byte	W08
	.byte		        Gn4 , v052
	.byte	W04
	.byte		N12   , Gn5 , v084
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_deepdeep_5_000
	.byte	PATT
	 .word	bgm_deepdeep_5_001
	.byte	PATT
	 .word	bgm_deepdeep_5_000
	.byte	PATT
	 .word	bgm_deepdeep_5_001
	.byte	PATT
	 .word	bgm_deepdeep_5_000
bgm_deepdeep_5_B1:
	.byte	PATT
	 .word	bgm_deepdeep_5_001
	.byte	PATT
	 .word	bgm_deepdeep_5_000
	.byte	PATT
	 .word	bgm_deepdeep_5_001
	.byte	PATT
	 .word	bgm_deepdeep_5_000
	.byte	PATT
	 .word	bgm_deepdeep_5_001
	.byte	PATT
	 .word	bgm_deepdeep_5_000
	.byte	PATT
	 .word	bgm_deepdeep_5_001
	.byte	PATT
	 .word	bgm_deepdeep_5_000
	.byte	PATT
	 .word	bgm_deepdeep_5_001
	.byte	PATT
	 .word	bgm_deepdeep_5_000
	.byte	PATT
	 .word	bgm_deepdeep_5_001
	.byte	PATT
	 .word	bgm_deepdeep_5_000
	.byte	PATT
	 .word	bgm_deepdeep_5_001
	.byte	PATT
	 .word	bgm_deepdeep_5_000
	.byte	PATT
	 .word	bgm_deepdeep_5_001
	.byte		PAN   , c_v-32
	.byte		N04   , Gn4 , v080
	.byte	W04
	.byte		        Gn4 , v068
	.byte	W04
	.byte		        Gn4 , v064
	.byte	W04
	.byte		N08   , Gn5 
	.byte	W08
	.byte		N04   , Gn5 , v060
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Gn4 , v052
	.byte	W08
	.byte		        Gn4 , v048
	.byte	W04
	.byte		N12   , Gn5 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N04   , Gn4 , v036
	.byte	W08
	.byte		        Gn4 , v032
	.byte	W04
	.byte		N08   , Gn5 , v024
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Gn4 
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		N12   , Gn5 , v020
	.byte	W12
	.byte		VOICE , 45
	.byte		PAN   , c_v-32
	.byte		VOL   , 65*bgm_deepdeep_mvl/mxv
	.byte	W12
	.byte		N04   , Gn4 , v112
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Gn4 , v080
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , Gn4 , v052
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Gn4 , v036
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , Gn4 , v028
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Gn4 , v024
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , Gn4 , v020
	.byte	W04
	.byte		        Dn4 
	.byte	W32
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N04   , Fn4 , v112
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , Fn4 , v080
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Fn4 , v052
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , Fn4 , v036
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Fn4 , v028
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , Fn4 , v024
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Fn4 , v020
	.byte	W04
	.byte		        Cn4 
	.byte	W20
	.byte		VOL   , 53*bgm_deepdeep_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N04   , Bn4 , v112
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Bn4 , v080
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , Bn4 , v052
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Bn4 , v036
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , Bn4 , v028
	.byte	W04
	.byte		VOICE , 9
	.byte		PAN   , c_v-32
	.byte		N04   , Gn4 , v016
	.byte	W08
	.byte		        Gn4 , v036
	.byte	W04
	.byte		N08   , Gn5 , v040
	.byte	W08
	.byte		N04   , Gn5 , v048
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Gn4 , v096
	.byte	W08
	.byte		        Gn4 , v076
	.byte	W04
	.byte		N12   , Gn5 , v092
	.byte	W12
	.byte	PATT
	 .word	bgm_deepdeep_5_000
	.byte	PATT
	 .word	bgm_deepdeep_5_001
	.byte	PATT
	 .word	bgm_deepdeep_5_000
	.byte	GOTO
	 .word	bgm_deepdeep_5_B1
	.byte		PAN   , c_v-32
	.byte	FINE

@********************** Track  6 **********************@

bgm_deepdeep_6:
	.byte	KEYSH , bgm_deepdeep_key+0
	.byte		VOICE , 92
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 35*bgm_deepdeep_mvl/mxv
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 12
	.byte		BENDR , 12
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		VOL   , 39*bgm_deepdeep_mvl/mxv
	.byte	W12
	.byte		N04   , An3 , v048
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		N72   , Dn4 , v112
	.byte	W24
	.byte		MOD   , 3
	.byte		VOL   , 38*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        35*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        31*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        28*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        25*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        21*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		VOL   , 39*bgm_deepdeep_mvl/mxv
	.byte		N04   , Fs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		N92   , Dn4 
	.byte	W12
	.byte		MOD   , 2
	.byte	W24
	.byte		VOL   , 37*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        35*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        32*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        29*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        26*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        23*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		MOD   , 7
	.byte		VOL   , 21*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        19*bgm_deepdeep_mvl/mxv
	.byte	W20
	.byte		MOD   , 0
	.byte	W08
	.byte		VOL   , 38*bgm_deepdeep_mvl/mxv
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N04   , Cs4 
	.byte	W04
	.byte		N92   , Dn4 
	.byte	W24
	.byte		MOD   , 2
	.byte		VOL   , 37*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        34*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        32*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        30*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        28*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        26*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        23*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        22*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        20*bgm_deepdeep_mvl/mxv
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		VOL   , 39*bgm_deepdeep_mvl/mxv
	.byte		N02   , Cs4 
	.byte	W02
	.byte		        Dn4 
	.byte	W02
	.byte		N44   , Ds4 
	.byte	W20
	.byte		MOD   , 7
	.byte	W04
	.byte		VOL   , 34*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        29*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        24*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        20*bgm_deepdeep_mvl/mxv
	.byte	W08
	.byte		MOD   , 0
	.byte		VOL   , 14*bgm_deepdeep_mvl/mxv
	.byte	W02
	.byte		        39*bgm_deepdeep_mvl/mxv
	.byte		N02   , En4 
	.byte	W02
	.byte		VOL   , 39*bgm_deepdeep_mvl/mxv
	.byte		N24   , Fn4 
	.byte	W24
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N02   , Dn4 , v064
	.byte	W02
	.byte		        Cn4 
	.byte	W02
	.byte		        Bn3 
	.byte	W02
	.byte		        An3 
	.byte	W02
	.byte		        Gn3 
	.byte	W02
	.byte		        Fn3 
	.byte	W02
	.byte		        En3 
	.byte	W02
	.byte		        Dn3 
	.byte	W02
bgm_deepdeep_6_B1:
	.byte		VOL   , 27*bgm_deepdeep_mvl/mxv
	.byte		BEND  , c_v+2
	.byte		N04   , Ds1 , v127
	.byte	W08
	.byte		        Dn1 
	.byte	W04
	.byte		N08   , Ds1 
	.byte	W08
	.byte		N04   , Gn1 
	.byte	W04
	.byte		N08   , Gn1 , v036
	.byte	W08
	.byte		N04   , As1 , v127
	.byte	W04
	.byte		N08   , As1 , v036
	.byte	W08
	.byte		N04   , Dn2 , v127
	.byte	W04
	.byte		N08   , Dn2 , v036
	.byte	W32
	.byte		N04   , Dn2 , v127
	.byte	W04
	.byte		N12   , Ds1 
	.byte	W12
	.byte		N04   , Dn1 
	.byte	W08
	.byte		        Cs1 
	.byte	W04
	.byte		N08   , Dn1 
	.byte	W08
	.byte		N04   , Fs1 
	.byte	W04
	.byte		N08   , Fs1 , v036
	.byte	W08
	.byte		N04   , An1 , v127
	.byte	W04
	.byte		N08   , An1 , v036
	.byte	W08
	.byte		N04   , Cs2 , v127
	.byte	W04
	.byte		N08   , Cs2 , v036
	.byte	W20
	.byte		N04   , Cs2 , v127
	.byte	W04
	.byte		N08   , Cs2 , v036
	.byte	W08
	.byte		N04   , Cs2 , v127
	.byte	W04
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N04   , Fn1 
	.byte	W08
	.byte		        En1 
	.byte	W04
	.byte		N08   , Fn1 
	.byte	W08
	.byte		N04   , Gs1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W04
	.byte		        Ds2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Dn2 
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Cn2 
	.byte	W08
	.byte		        Gs1 
	.byte	W04
	.byte		        Gn1 
	.byte	W08
	.byte		        Fs1 
	.byte	W04
	.byte		N08   , Gn1 
	.byte	W08
	.byte		N04   , Bn1 
	.byte	W04
	.byte		N08   , Bn1 , v036
	.byte	W08
	.byte		N04   , Dn2 , v127
	.byte	W04
	.byte		N08   , Dn2 , v036
	.byte	W08
	.byte		N04   , Fs2 , v127
	.byte	W04
	.byte		N08   , Fs2 , v036
	.byte	W08
	.byte		N04   , Fs2 , v127
	.byte	W04
	.byte		N08   , Gn1 
	.byte	W12
	.byte		VOL   , 39*bgm_deepdeep_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N04   , Dn4 , v112
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		N72   , Dn4 
	.byte	W24
	.byte		MOD   , 3
	.byte		VOL   , 35*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        31*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        28*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        25*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        23*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        21*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		VOL   , 39*bgm_deepdeep_mvl/mxv
	.byte		N04   , Fs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		N84   , Dn4 
	.byte	W12
	.byte		MOD   , 2
	.byte	W24
	.byte		        3
	.byte		VOL   , 38*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        35*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        33*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        32*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        29*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        28*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		MOD   , 6
	.byte		VOL   , 25*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        23*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        21*bgm_deepdeep_mvl/mxv
	.byte	W16
	.byte		MOD   , 0
	.byte	W08
	.byte		VOL   , 38*bgm_deepdeep_mvl/mxv
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N04   , Cs4 
	.byte	W04
bgm_deepdeep_6_000:
	.byte		TIE   , Dn4 , v112
	.byte	W48
	.byte		MOD   , 2
	.byte	W48
	.byte	PEND
	.byte	W24
	.byte		        4
	.byte		VOL   , 38*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        35*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        32*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        29*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        26*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        23*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		MOD   , 6
	.byte		VOL   , 21*bgm_deepdeep_mvl/mxv
	.byte	W24
	.byte		EOT   
	.byte		MOD   , 0
	.byte		VOL   , 39*bgm_deepdeep_mvl/mxv
	.byte		N02   , Cn4 , v064
	.byte	W02
	.byte		        Bn3 
	.byte	W02
	.byte		        An3 
	.byte	W02
	.byte		        Gn3 
	.byte	W02
	.byte		        Fs3 
	.byte	W02
	.byte		        En3 
	.byte	W02
	.byte		        Dn3 
	.byte	W02
	.byte		        Cn3 
	.byte	W02
	.byte		        Bn2 
	.byte	W04
	.byte		        An2 
	.byte	W02
	.byte		        Gs2 
	.byte	W02
	.byte		VOL   , 39*bgm_deepdeep_mvl/mxv
	.byte		N16   , Gn2 , v112
	.byte	W16
	.byte		N14   , Gs2 
	.byte	W14
	.byte		N02   , An2 , v100
	.byte	W02
	.byte		N24   , As2 , v112
	.byte	W24
	.byte	W02
	.byte		N02   , Bn2 
	.byte	W02
	.byte		N12   , As2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N42   , Fs2 
	.byte	W24
	.byte		MOD   , 5
	.byte	W18
	.byte		N02   , Bn2 , v080
	.byte	W02
	.byte		        Cn3 
	.byte	W02
	.byte		        Cs3 
	.byte	W02
	.byte		MOD   , 0
	.byte		N24   , Dn3 , v112
	.byte	W24
	.byte		N08   , Cs3 
	.byte	W08
	.byte		N02   , Cn3 , v080
	.byte	W02
	.byte		        Bn2 
	.byte	W02
	.byte		        As2 
	.byte	W02
	.byte		        An2 
	.byte	W02
	.byte		        Gs2 
	.byte	W02
	.byte		        Gn2 
	.byte	W02
	.byte		        Fs2 
	.byte	W02
	.byte		        Fn2 
	.byte	W02
	.byte		        Bn2 , v112
	.byte	W02
	.byte		N10   , As2 
	.byte	W10
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N22   , Ds3 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gs3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N48   , Bn2 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N08   , Fs3 
	.byte	W08
	.byte		N02   , Fn3 , v080
	.byte	W02
	.byte		        En3 
	.byte	W02
	.byte		        Ds3 
	.byte	W02
	.byte		        Dn3 
	.byte	W02
	.byte		        Cs3 
	.byte	W02
	.byte		        Cn3 
	.byte	W02
	.byte		        Bn2 
	.byte	W02
	.byte		        As2 
	.byte	W02
	.byte		N16   , Gn3 , v112
	.byte	W16
	.byte		        Gs3 
	.byte	W16
	.byte		N24   , As3 
	.byte	W28
	.byte		N12   
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N42   , Fs3 
	.byte	W24
	.byte		MOD   , 5
	.byte	W18
	.byte		N02   , Bn3 , v080
	.byte	W02
	.byte		        Cn4 
	.byte	W02
	.byte		        Cs4 
	.byte	W02
	.byte		MOD   , 0
	.byte		N24   , Dn4 , v112
	.byte	W24
	.byte		N08   , Cs4 
	.byte	W08
	.byte		N02   , Cn4 , v080
	.byte	W02
	.byte		        Bn3 
	.byte	W02
	.byte		        As3 
	.byte	W02
	.byte		        An3 
	.byte	W02
	.byte		        Gs3 
	.byte	W02
	.byte		        Gn3 
	.byte	W02
	.byte		        Fs3 
	.byte	W02
	.byte		        Fn3 
	.byte	W02
	.byte		MOD   , 0
	.byte		N12   , As3 , v112
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N22   , Ds4 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gs4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N48   , Bn3 
	.byte	W24
	.byte		VOL   , 37*bgm_deepdeep_mvl/mxv
	.byte		MOD   , 5
	.byte	W04
	.byte		VOL   , 33*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        30*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        25*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        23*bgm_deepdeep_mvl/mxv
	.byte	W08
	.byte		        39*bgm_deepdeep_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		N72   , Dn4 
	.byte	W24
	.byte		MOD   , 3
	.byte		VOL   , 38*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        34*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        31*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        29*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        26*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        24*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		VOL   , 38*bgm_deepdeep_mvl/mxv
	.byte		N04   , Fs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		N84   , Dn4 
	.byte	W12
	.byte		MOD   , 2
	.byte	W24
	.byte		        3
	.byte		VOL   , 37*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        34*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        32*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        29*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        27*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        25*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		MOD   , 8
	.byte		VOL   , 24*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        22*bgm_deepdeep_mvl/mxv
	.byte	W20
	.byte		MOD   , 0
	.byte	W08
	.byte		VOL   , 38*bgm_deepdeep_mvl/mxv
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N04   , Cs4 
	.byte	W04
	.byte	PATT
	 .word	bgm_deepdeep_6_000
	.byte	W24
	.byte		MOD   , 6
	.byte		VOL   , 35*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        32*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        29*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        27*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        25*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		        23*bgm_deepdeep_mvl/mxv
	.byte	W04
	.byte		MOD   , 8
	.byte		VOL   , 21*bgm_deepdeep_mvl/mxv
	.byte	W24
	.byte		EOT   , Dn4 
	.byte		MOD   , 0
	.byte		VOL   , 38*bgm_deepdeep_mvl/mxv
	.byte		N02   , Cn4 , v064
	.byte	W02
	.byte		        Bn3 
	.byte	W02
	.byte		        An3 
	.byte	W02
	.byte		        Gn3 
	.byte	W02
	.byte		        Fs3 
	.byte	W02
	.byte		        En3 
	.byte	W02
	.byte		        Dn3 
	.byte	W02
	.byte		        Cn3 
	.byte	W02
	.byte		        Bn2 
	.byte	W04
	.byte		        An2 
	.byte	W02
	.byte		        Gs2 
	.byte	W02
	.byte		VOL   , 47*bgm_deepdeep_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_deepdeep_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_deepdeep_7:
	.byte	KEYSH , bgm_deepdeep_key+0
	.byte		VOICE , 80
	.byte		PAN   , c_v+0
	.byte		VOL   , 37*bgm_deepdeep_mvl/mxv
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		BEND  , c_v+2
	.byte	W96
	.byte		        c_v+2
	.byte		N04   , Gn1 , v112
	.byte	W08
	.byte		        Bn1 
	.byte	W04
	.byte		        Dn2 
	.byte	W08
	.byte		        Fs2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		        Dn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W04
	.byte		        Gn3 
	.byte	W08
	.byte		        Bn3 
	.byte	W04
	.byte		        Dn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fn1 
	.byte	W08
	.byte		        An1 
	.byte	W04
	.byte		        Cn2 
	.byte	W08
	.byte		        En2 
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cn3 
	.byte	W08
	.byte		        En3 
	.byte	W04
	.byte		        Fn3 
	.byte	W08
	.byte		        An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W08
	.byte		        En4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Gn1 
	.byte	W08
	.byte		        Bn1 
	.byte	W04
	.byte		        Dn2 
	.byte	W08
	.byte		        Fs2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		        Dn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W04
	.byte		        Gn3 
	.byte	W08
	.byte		        Bn3 
	.byte	W04
	.byte		        Dn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Gs1 
	.byte	W08
	.byte		        Cn2 
	.byte	W04
	.byte		        Ds2 
	.byte	W08
	.byte		        Gn2 
	.byte	W04
	.byte		        Gs2 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W08
	.byte		        Gn3 
	.byte	W04
	.byte		        Gs3 
	.byte	W08
	.byte		        Cn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W08
	.byte		        Gn4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_deepdeep_7_B1:
	.byte		BEND  , c_v+2
	.byte		N04   , Ds1 , v112
	.byte	W04
	.byte		        Gn1 
	.byte	W04
	.byte		        As1 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Dn1 
	.byte	W08
	.byte		        Fs1 
	.byte	W04
	.byte		        An1 
	.byte	W08
	.byte		        Cs2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        En2 
	.byte	W04
	.byte		        Fs2 
	.byte	W04
	.byte		        An2 
	.byte	W08
	.byte		        Cs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W04
	.byte		        An3 
	.byte	W08
	.byte		        Cs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Gs1 
	.byte	W04
	.byte		        Cn2 
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        Gs2 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Gn4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W04
	.byte		        Dn4 
	.byte	W08
	.byte		        As3 
	.byte	W04
	.byte		        Gn1 
	.byte	W04
	.byte		        Bn1 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Fs2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        En4 
	.byte	W28
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N08   , Gn1 , v036
	.byte	W08
	.byte		N04   , Gn1 , v124
	.byte	W04
	.byte		N08   , Gn1 , v036
	.byte	W68
	.byte		N04   , Gn2 , v124
	.byte	W04
bgm_deepdeep_7_000:
	.byte		N12   , Fn1 , v124
	.byte	W12
	.byte		N08   , Fn1 , v036
	.byte	W08
	.byte		N04   , Fn1 , v124
	.byte	W04
	.byte		N08   , Fn1 , v036
	.byte	W68
	.byte		N04   , Gn2 , v124
	.byte	W04
	.byte	PEND
bgm_deepdeep_7_001:
	.byte		N12   , Gn1 , v124
	.byte	W12
	.byte		N08   , Gn1 , v036
	.byte	W08
	.byte		N04   , Gn1 , v124
	.byte	W04
	.byte		N08   , Gn1 , v036
	.byte	W68
	.byte		N04   , Gn2 , v124
	.byte	W04
	.byte	PEND
bgm_deepdeep_7_002:
	.byte		N12   , Fn1 , v124
	.byte	W12
	.byte		N08   , Fn1 , v036
	.byte	W08
	.byte		N04   , Fn1 , v124
	.byte	W04
	.byte		N08   , Fn1 , v036
	.byte	W72
	.byte	PEND
	.byte		VOL   , 35*bgm_deepdeep_mvl/mxv
	.byte		N04   , Ds1 , v124
	.byte	W08
	.byte		        Dn1 
	.byte	W04
	.byte		N08   , Ds1 
	.byte	W08
	.byte		N04   , Gn1 
	.byte	W04
	.byte		N08   , Gn1 , v036
	.byte	W08
	.byte		N04   , As1 , v124
	.byte	W04
	.byte		N08   , As1 , v036
	.byte	W08
	.byte		N04   , Dn2 , v124
	.byte	W04
	.byte		N08   , Dn2 , v036
	.byte	W32
	.byte		N04   , Dn2 , v124
	.byte	W04
	.byte		N12   , Ds1 
	.byte	W12
	.byte		N04   , Dn1 
	.byte	W08
	.byte		        Cs1 
	.byte	W04
	.byte		N08   , Dn1 
	.byte	W08
	.byte		N04   , Fs1 
	.byte	W04
	.byte		N08   , Fs1 , v036
	.byte	W08
	.byte		N04   , An1 , v124
	.byte	W04
	.byte		N08   , An1 , v036
	.byte	W08
	.byte		N04   , Cs2 , v124
	.byte	W04
	.byte		N08   , Cs2 , v036
	.byte	W20
	.byte		N04   , Cs2 , v124
	.byte	W04
	.byte		N08   , Cs2 , v036
	.byte	W08
	.byte		N04   , Cs2 , v124
	.byte	W04
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N04   , Fn1 
	.byte	W08
	.byte		        En1 
	.byte	W04
	.byte		N08   , Fn1 
	.byte	W08
	.byte		N04   , Gs1 
	.byte	W04
	.byte		N08   , Gs1 , v036
	.byte	W08
	.byte		N04   , Cn2 , v124
	.byte	W04
	.byte		N08   , Cn2 , v036
	.byte	W08
	.byte		N04   , Dn2 , v124
	.byte	W04
	.byte		BEND  , c_v+0
	.byte		N04   , Ds4 , v112
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		BEND  , c_v+2
	.byte		N04   , Dn2 , v124
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Cn2 
	.byte	W08
	.byte		        Gs1 
	.byte	W04
bgm_deepdeep_7_003:
	.byte		N04   , Gn1 , v124
	.byte	W08
	.byte		        Fs1 
	.byte	W04
	.byte		N08   , Gn1 
	.byte	W08
	.byte		N04   , Bn1 
	.byte	W04
	.byte		N08   , Bn1 , v036
	.byte	W08
	.byte		N04   , Dn2 , v124
	.byte	W04
	.byte		N08   , Dn2 , v036
	.byte	W08
	.byte		N04   , Fs2 , v124
	.byte	W04
	.byte		N08   , Fs2 , v036
	.byte	W08
	.byte		N04   , Fs2 , v124
	.byte	W04
	.byte		N08   , Gn1 
	.byte	W12
	.byte		N04   , Fs2 
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte	PEND
	.byte		        Ds1 
	.byte	W08
	.byte		        Dn1 
	.byte	W04
	.byte		N08   , Ds1 
	.byte	W08
	.byte		N04   , Gn1 
	.byte	W04
	.byte		N08   , Gn1 , v036
	.byte	W08
	.byte		N04   , As1 , v124
	.byte	W04
	.byte		N08   , As1 , v036
	.byte	W08
	.byte		N04   , Dn2 , v124
	.byte	W04
	.byte		N08   , Dn2 , v036
	.byte	W32
	.byte		N04   , Dn2 , v124
	.byte	W04
	.byte		N12   , Ds1 
	.byte	W12
	.byte		N04   , Dn1 
	.byte	W08
	.byte		        Cs1 
	.byte	W04
	.byte		N08   , Dn1 
	.byte	W08
	.byte		N04   , Fs1 
	.byte	W04
	.byte		N08   , Fs1 , v036
	.byte	W08
	.byte		N04   , An1 , v124
	.byte	W04
	.byte		N08   , An1 , v036
	.byte	W08
	.byte		N04   , Cs2 , v124
	.byte	W06
	.byte		N08   , Cs2 , v036
	.byte	W18
	.byte		N04   , Cs2 , v124
	.byte	W04
	.byte		N08   , Cs2 , v036
	.byte	W08
	.byte		N04   , Cs2 , v124
	.byte	W04
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N04   , Fn1 
	.byte	W08
	.byte		        En1 
	.byte	W04
	.byte		N08   , Fn1 
	.byte	W08
	.byte		N04   , Gs1 
	.byte	W04
	.byte		N08   , Gs1 , v036
	.byte	W08
	.byte		N04   , Cn2 , v124
	.byte	W04
	.byte		N08   , Cn2 , v036
	.byte	W08
	.byte		N04   , Dn2 , v124
	.byte	W04
	.byte		        Ds2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Dn2 
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Cn2 
	.byte	W08
	.byte		        Gs1 
	.byte	W04
	.byte	PATT
	 .word	bgm_deepdeep_7_003
	.byte	PATT
	 .word	bgm_deepdeep_7_001
	.byte	PATT
	 .word	bgm_deepdeep_7_000
	.byte	PATT
	 .word	bgm_deepdeep_7_001
	.byte	PATT
	 .word	bgm_deepdeep_7_002
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_deepdeep_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_deepdeep_8:
	.byte	KEYSH , bgm_deepdeep_key+0
	.byte		VOICE , 92
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		LFOS  , 44
	.byte		PAN   , c_v-63
	.byte		BENDR , 12
	.byte		VOL   , 5*bgm_deepdeep_mvl/mxv
	.byte		N04   , Gn6 , v080
	.byte	W08
	.byte		        Gn6 , v052
	.byte	W04
	.byte		N12   , Gn7 , v084
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		VOL   , 8*bgm_deepdeep_mvl/mxv
	.byte		N04   , Gn6 , v080
	.byte	W04
	.byte		        Gn6 , v044
	.byte	W04
	.byte		        Gn6 , v060
	.byte	W04
	.byte		N12   , Gn7 , v084
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		VOL   , 11*bgm_deepdeep_mvl/mxv
	.byte		N04   , Gn6 , v080
	.byte	W08
	.byte		        Gn6 , v052
	.byte	W04
	.byte		N12   , Gn7 , v084
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		VOL   , 15*bgm_deepdeep_mvl/mxv
	.byte		N04   , Gn6 , v080
	.byte	W08
	.byte		        Gn6 , v052
	.byte	W04
	.byte		N08   , Gn7 , v084
	.byte	W08
	.byte		N04   , Gn7 , v052
	.byte	W04
	.byte		PAN   , c_v-63
	.byte		VOL   , 18*bgm_deepdeep_mvl/mxv
	.byte		N04   , Gn6 , v080
	.byte	W04
	.byte		        Gn6 , v048
	.byte	W04
	.byte		        Gn6 , v072
	.byte	W04
	.byte		N08   , Gn7 , v084
	.byte	W08
	.byte		N04   , Gn7 , v064
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Gn6 , v080
	.byte	W08
	.byte		        Gn6 , v052
	.byte	W04
	.byte		N12   , Gn7 , v084
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N04   , Gn6 , v080
	.byte	W08
	.byte		        Gn6 , v052
	.byte	W04
	.byte		N08   , Gn7 , v084
	.byte	W08
	.byte		N04   , Gn7 , v056
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Gn6 , v080
	.byte	W08
	.byte		        Gn6 , v052
	.byte	W04
	.byte		N12   , Gn7 , v084
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N04   , Gn6 , v080
	.byte	W08
	.byte		        Gn6 , v052
	.byte	W04
	.byte		N12   , Gn7 , v084
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N04   , Gn6 , v080
	.byte	W04
	.byte		        Gn6 , v044
	.byte	W04
	.byte		        Gn6 , v060
	.byte	W04
	.byte		N12   , Gn7 , v084
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N04   , Gn6 , v080
	.byte	W08
	.byte		        Gn6 , v052
	.byte	W04
	.byte		N12   , Gn7 , v084
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N04   , Gn6 , v080
	.byte	W08
	.byte		        Gn6 , v052
	.byte	W04
	.byte		N08   , Gn7 , v084
	.byte	W08
	.byte		N04   , Gn7 , v052
	.byte	W04
	.byte		PAN   , c_v-63
	.byte		N04   , Gn6 , v080
	.byte	W04
	.byte		        Gn6 , v048
	.byte	W04
	.byte		        Gn6 , v072
	.byte	W04
	.byte		N08   , Gn7 , v084
	.byte	W08
	.byte		N04   , Gn7 , v064
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Gn6 , v080
	.byte	W08
	.byte		        Gn6 , v052
	.byte	W04
	.byte		N12   , Gn7 , v084
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N04   , Gn6 , v080
	.byte	W08
	.byte		        Gn6 , v052
	.byte	W04
	.byte		N08   , Gn7 , v084
	.byte	W08
	.byte		N04   , Gn7 , v056
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Gn6 , v080
	.byte	W08
	.byte		        Gn6 , v052
	.byte	W04
	.byte		N12   , Gn7 , v084
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N04   , Gn6 , v080
	.byte	W08
	.byte		        Gn6 , v052
	.byte	W04
	.byte		N12   , Gn7 , v084
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N04   , Gn6 , v080
	.byte	W04
	.byte		        Gn6 , v044
	.byte	W04
	.byte		        Gn6 , v060
	.byte	W04
	.byte		N12   , Gn7 , v084
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N04   , Gn6 , v080
	.byte	W08
	.byte		        Gn6 , v052
	.byte	W04
	.byte		N12   , Gn7 , v084
	.byte	W12
	.byte		VOICE , 82
	.byte		PAN   , c_v+0
	.byte		VOL   , 71*bgm_deepdeep_mvl/mxv
	.byte	W12
	.byte		N04   , Fs4 , v048
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		MOD   , 1
	.byte		N72   , Bn4 
	.byte	W24
	.byte		MOD   , 3
	.byte	W22
	.byte		LFOS  , 44
	.byte	W02
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N04   , Dn5 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		N92   , Bn4 
	.byte	W08
	.byte		LFOS  , 36
	.byte	W04
	.byte		MOD   , 1
	.byte	W24
	.byte		        3
	.byte	W18
	.byte		LFOS  , 44
	.byte	W06
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte	W08
	.byte		N06   , Cn5 
	.byte	W12
	.byte		LFOS  , 36
	.byte		N04   , An4 
	.byte	W04
	.byte		MOD   , 1
	.byte		N92   , Bn4 
	.byte	W44
	.byte		MOD   , 3
	.byte	W20
	.byte		LFOS  , 44
	.byte	W04
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N02   , As4 
	.byte	W02
	.byte		        Bn4 
	.byte	W02
	.byte		LFOS  , 36
	.byte		MOD   , 1
	.byte		N44   , Cn5 
	.byte	W08
	.byte		MOD   , 3
	.byte	W12
	.byte		LFOS  , 44
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte	W02
	.byte		N02   , Cs5 
	.byte	W02
	.byte		N24   , Dn5 
	.byte	W14
	.byte		MOD   , 4
	.byte	W10
	.byte		        1
	.byte		N08   , Cn5 
	.byte	W08
	.byte		N02   , Bn4 , v032
	.byte	W02
	.byte		        An4 
	.byte	W02
	.byte		        Gs4 
	.byte	W02
	.byte		        Fs4 
	.byte	W02
	.byte		        En4 
	.byte	W02
	.byte		        Dn4 
	.byte	W02
	.byte		        Cs4 
	.byte	W02
	.byte		        Bn3 
	.byte	W02
bgm_deepdeep_8_B1:
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W64
	.byte		LFOS  , 36
	.byte	W08
	.byte		N04   , Bn4 , v112
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		N72   , Bn4 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        7
	.byte	W24
	.byte		        0
	.byte		N04   , Dn5 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		N84   , Bn4 
	.byte	W12
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        7
	.byte	W24
	.byte		        0
	.byte		N08   , Bn4 , v036
	.byte	W08
	.byte		N06   , Cn5 , v112
	.byte	W12
	.byte		N04   , An4 
	.byte	W04
	.byte		TIE   , Bn4 
	.byte	W24
	.byte		MOD   , 4
	.byte	W72
	.byte	W24
	.byte		        8
	.byte	W48
	.byte		EOT   
	.byte		MOD   , 0
	.byte		N02   , An4 , v064
	.byte	W02
	.byte		        Gn4 
	.byte	W02
	.byte		        Fs4 
	.byte	W02
	.byte		        En4 
	.byte	W02
	.byte		        Dn4 
	.byte	W02
	.byte		        Cn4 
	.byte	W02
	.byte		        Bn3 
	.byte	W02
	.byte		        An3 
	.byte	W02
	.byte		        Gn3 
	.byte	W02
	.byte		        Fs3 
	.byte	W02
	.byte		        En3 
	.byte	W02
	.byte		        Ds3 
	.byte	W02
	.byte		N16   , Dn3 , v112
	.byte	W16
	.byte		N14   , Ds3 
	.byte	W14
	.byte		N02   , En3 , v096
	.byte	W02
	.byte		N24   , Fn3 , v112
	.byte	W24
	.byte	W02
	.byte		N02   , Fs3 
	.byte	W02
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N42   , Cs3 
	.byte	W24
	.byte		MOD   , 9
	.byte	W18
	.byte		N02   , Gs3 , v068
	.byte	W02
	.byte		        An3 
	.byte	W02
	.byte		        As3 
	.byte	W02
	.byte		MOD   , 0
	.byte		N24   , Bn3 , v112
	.byte	W24
	.byte		N08   , An3 
	.byte	W08
	.byte		N02   , Gs3 , v064
	.byte	W02
	.byte		        Gn3 
	.byte	W02
	.byte		        Fs3 
	.byte	W02
	.byte		        Fn3 
	.byte	W02
	.byte		        En3 
	.byte	W02
	.byte		        Ds3 
	.byte	W02
	.byte		        Dn3 
	.byte	W02
	.byte		        Cs3 
	.byte	W02
	.byte		        Gs3 , v104
	.byte	W02
	.byte		N10   , Gn3 , v112
	.byte	W10
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N22   , As3 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N48   , Fs3 
	.byte	W24
	.byte		MOD   , 9
	.byte	W24
	.byte		        0
	.byte		N24   , An3 
	.byte	W24
	.byte		N08   , Bn3 
	.byte	W08
	.byte		N02   , As3 , v064
	.byte	W02
	.byte		        An3 
	.byte	W02
	.byte		        Gs3 
	.byte	W02
	.byte		        Gn3 
	.byte	W02
	.byte		        Fs3 
	.byte	W02
	.byte		        Fn3 
	.byte	W02
	.byte		        En3 
	.byte	W02
	.byte		        Ds3 
	.byte	W02
	.byte		N16   , Dn4 , v112
	.byte	W16
	.byte		        Ds4 
	.byte	W16
	.byte		N24   , Fn4 
	.byte	W28
	.byte		N12   
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N42   , Cs4 
	.byte	W24
	.byte		MOD   , 9
	.byte	W18
	.byte		N02   , Gs4 , v064
	.byte	W02
	.byte		        An4 
	.byte	W02
	.byte		        As4 
	.byte	W02
	.byte		MOD   , 0
	.byte		N24   , Bn4 , v112
	.byte	W24
	.byte		N08   , An4 
	.byte	W08
	.byte		N02   , Gs4 , v064
	.byte	W02
	.byte		        Gn4 
	.byte	W02
	.byte		        Fs4 
	.byte	W02
	.byte		        Fn4 
	.byte	W02
	.byte		        En4 
	.byte	W02
	.byte		        Ds4 
	.byte	W02
	.byte		        Dn4 
	.byte	W02
	.byte		        Cs4 
	.byte	W02
	.byte		MOD   , 0
	.byte		N12   , Gn4 , v112
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		N22   , As4 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cn5 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N48   , Fs4 
	.byte	W24
	.byte		MOD   , 9
	.byte	W24
	.byte		        0
	.byte		N24   , An4 
	.byte	W24
	.byte		N04   , Bn4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		N72   , Bn4 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        9
	.byte	W24
	.byte		        0
	.byte		N04   , Dn5 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		N84   , Bn4 
	.byte	W12
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        9
	.byte	W24
	.byte		        0
	.byte	W08
	.byte		N06   , Cn5 
	.byte	W12
	.byte		N04   , An4 
	.byte	W04
	.byte		TIE   , Bn4 
	.byte	W48
	.byte		MOD   , 5
	.byte	W48
	.byte	W24
	.byte		        8
	.byte	W48
	.byte		EOT   
	.byte		MOD   , 0
	.byte		N02   , An4 , v072
	.byte	W02
	.byte		        Gn4 , v068
	.byte	W02
	.byte		        Fs4 , v064
	.byte	W02
	.byte		        En4 , v060
	.byte	W02
	.byte		        Dn4 , v056
	.byte	W02
	.byte		        Cn4 , v052
	.byte	W02
	.byte		        Bn3 , v048
	.byte	W02
	.byte		        An3 , v044
	.byte	W02
	.byte		        Gn3 , v040
	.byte	W02
	.byte		        Fs3 , v036
	.byte	W02
	.byte		        En3 , v032
	.byte	W02
	.byte		        Ds3 , v024
	.byte	W02
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_deepdeep_8_B1
	.byte	FINE

@********************** Track  9 **********************@

bgm_deepdeep_9:
	.byte	KEYSH , bgm_deepdeep_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 94*bgm_deepdeep_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N04   , Cn1 , v127
	.byte	W44
	.byte		        Cn1 , v092
	.byte	W04
	.byte		        Cn1 , v112
	.byte	W48
	.byte		        Cn1 , v127
	.byte	W44
	.byte		        Cn1 , v080
	.byte	W04
	.byte		        Cn1 , v112
	.byte	W48
	.byte		        Cn1 , v127
	.byte	W24
	.byte		        Cn1 , v112
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W20
	.byte		        Cn1 , v080
	.byte	W04
	.byte		        Cn1 , v127
	.byte	W20
	.byte		        Cn1 , v056
	.byte	W04
	.byte		        Cn1 , v112
	.byte	W20
	.byte		        Cn1 , v080
	.byte	W04
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        En1 
	.byte	W04
	.byte		        En1 , v032
	.byte	W04
	.byte		        En1 , v024
	.byte	W04
	.byte		        Cn1 , v080
	.byte	W04
	.byte		        En1 , v112
	.byte	W04
	.byte		        Cn1 
	.byte	W04
	.byte		        Dn1 
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        Dn1 , v080
	.byte	W04
	.byte		        En1 
	.byte	W04
bgm_deepdeep_9_B1:
bgm_deepdeep_9_000:
	.byte		N04   , Cn1 , v127
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W04
	.byte		        Cn1 , v112
	.byte	W04
	.byte		        Cn1 , v068
	.byte	W04
	.byte		        Cn1 , v096
	.byte	W04
	.byte		        En1 , v112
	.byte	W04
	.byte		        En1 , v032
	.byte	W04
	.byte		        En1 , v024
	.byte	W04
	.byte		        Cn1 , v124
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W04
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        En1 
	.byte	W04
	.byte		        En1 , v032
	.byte	W04
	.byte		        En1 , v024
	.byte	W08
	.byte		        En1 , v112
	.byte	W04
	.byte		        En1 , v032
	.byte	W04
	.byte		        En1 , v080
	.byte	W04
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W04
	.byte	PEND
bgm_deepdeep_9_001:
	.byte		N04   , Cn1 , v127
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W04
	.byte		        Cn1 , v112
	.byte	W04
	.byte		        Cn1 , v068
	.byte	W04
	.byte		        Cn1 , v096
	.byte	W04
	.byte		        En1 , v112
	.byte	W04
	.byte		        En1 , v032
	.byte	W04
	.byte		        En1 , v024
	.byte	W04
	.byte		        Cn1 , v124
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W04
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        En1 
	.byte	W04
	.byte		        En1 , v032
	.byte	W04
	.byte		        En1 , v024
	.byte	W08
	.byte		        En1 , v112
	.byte	W04
	.byte		        En1 , v032
	.byte	W04
	.byte		        Dn1 , v124
	.byte	W04
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	bgm_deepdeep_9_000
	.byte	PATT
	 .word	bgm_deepdeep_9_001
	.byte	PATT
	 .word	bgm_deepdeep_9_000
	.byte	PATT
	 .word	bgm_deepdeep_9_001
	.byte	PATT
	 .word	bgm_deepdeep_9_000
	.byte	PATT
	 .word	bgm_deepdeep_9_001
	.byte	PATT
	 .word	bgm_deepdeep_9_000
	.byte	PATT
	 .word	bgm_deepdeep_9_001
	.byte	PATT
	 .word	bgm_deepdeep_9_000
	.byte		N04   , Cn1 , v124
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W04
	.byte		        Cn1 , v112
	.byte	W04
	.byte		        Cn1 , v068
	.byte	W04
	.byte		        Cn1 , v096
	.byte	W04
	.byte		        En1 , v112
	.byte	W04
	.byte		        En1 , v032
	.byte	W04
	.byte		        En1 , v024
	.byte	W04
	.byte		        Cn1 , v124
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W04
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        En1 
	.byte	W04
	.byte		        En1 , v032
	.byte	W04
	.byte		        En1 , v024
	.byte	W08
	.byte		        En1 , v112
	.byte	W04
	.byte		        En1 , v032
	.byte	W04
	.byte		        Dn1 , v124
	.byte	W04
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W04
	.byte		        Cn1 , v124
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W04
	.byte		        Cn1 , v112
	.byte	W04
	.byte		        Cn1 , v068
	.byte	W04
	.byte		        Cn1 , v096
	.byte	W04
	.byte		        En1 , v112
	.byte	W04
	.byte		        En1 , v032
	.byte	W04
	.byte		        En1 , v024
	.byte	W04
	.byte		        Cn1 , v124
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W04
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        En1 
	.byte	W04
	.byte		        En1 , v032
	.byte	W04
	.byte		        En1 , v024
	.byte	W08
	.byte		        En1 , v112
	.byte	W04
	.byte		        En1 , v032
	.byte	W04
	.byte		        En1 , v080
	.byte	W04
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W04
	.byte	PATT
	 .word	bgm_deepdeep_9_001
	.byte	PATT
	 .word	bgm_deepdeep_9_000
	.byte	PATT
	 .word	bgm_deepdeep_9_001
	.byte	PATT
	 .word	bgm_deepdeep_9_000
	.byte	PATT
	 .word	bgm_deepdeep_9_001
	.byte	PATT
	 .word	bgm_deepdeep_9_000
	.byte	PATT
	 .word	bgm_deepdeep_9_001
	.byte		N04   , Cn1 , v127
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W04
	.byte		        Cn1 , v112
	.byte	W04
	.byte		        Cn1 , v068
	.byte	W04
	.byte		        Cn1 , v096
	.byte	W04
	.byte		        En1 , v112
	.byte	W04
	.byte		        En1 , v032
	.byte	W08
	.byte		        Cn1 , v124
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W04
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        En1 
	.byte	W04
	.byte		        En1 , v032
	.byte	W04
	.byte		        En1 , v024
	.byte	W08
	.byte		        En1 , v112
	.byte	W04
	.byte		        En1 , v032
	.byte	W04
	.byte		        En1 , v080
	.byte	W04
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W04
	.byte	PATT
	 .word	bgm_deepdeep_9_001
	.byte	GOTO
	 .word	bgm_deepdeep_9_B1
	.byte	FINE

@********************** Track 10 **********************@

bgm_deepdeep_10:
	.byte	KEYSH , bgm_deepdeep_key+0
	.byte		VOICE , 127
	.byte		VOL   , 47*bgm_deepdeep_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		LFOS  , 36
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 127
	.byte		PAN   , c_v-56
	.byte	W20
	.byte		N03   , Fn4 , v056
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		        Fn4 , v112
	.byte	W04
	.byte		N03   
	.byte	W08
	.byte		        Fn4 , v064
	.byte	W04
	.byte		        Fn4 , v112
	.byte	W04
	.byte		        Fn4 , v080
	.byte	W04
	.byte		N03   
	.byte	W04
bgm_deepdeep_10_B1:
bgm_deepdeep_10_000:
	.byte		N03   , Fn4 , v112
	.byte	W08
	.byte		        Fn4 , v064
	.byte	W04
	.byte		        Fn4 , v096
	.byte	W08
	.byte		        Fn4 , v064
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		        Fn4 , v112
	.byte	W04
	.byte		        Fn4 , v088
	.byte	W04
	.byte		        Fn4 , v064
	.byte	W04
	.byte		        Fn4 , v112
	.byte	W08
	.byte		        Fn4 , v064
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		        Fn4 , v112
	.byte	W08
	.byte		        Fn4 , v064
	.byte	W04
	.byte		        Fn4 , v096
	.byte	W08
	.byte		        Fn4 , v064
	.byte	W04
	.byte	PEND
bgm_deepdeep_10_001:
	.byte		N03   , Fn4 , v112
	.byte	W08
	.byte		        Fn4 , v064
	.byte	W04
	.byte		        Fn4 , v096
	.byte	W08
	.byte		        Fn4 , v064
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		        Fn4 , v112
	.byte	W08
	.byte		        Fn4 , v064
	.byte	W04
	.byte		        Fn4 , v112
	.byte	W08
	.byte		        Fn4 , v064
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		        Fn4 , v112
	.byte	W20
	.byte		        Fn4 , v064
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	bgm_deepdeep_10_000
	.byte	PATT
	 .word	bgm_deepdeep_10_001
	.byte	PATT
	 .word	bgm_deepdeep_10_000
	.byte	PATT
	 .word	bgm_deepdeep_10_001
	.byte	PATT
	 .word	bgm_deepdeep_10_000
	.byte	PATT
	 .word	bgm_deepdeep_10_001
	.byte	PATT
	 .word	bgm_deepdeep_10_000
	.byte	PATT
	 .word	bgm_deepdeep_10_001
	.byte	PATT
	 .word	bgm_deepdeep_10_000
	.byte	PATT
	 .word	bgm_deepdeep_10_001
	.byte	PATT
	 .word	bgm_deepdeep_10_000
	.byte	PATT
	 .word	bgm_deepdeep_10_001
	.byte	PATT
	 .word	bgm_deepdeep_10_000
	.byte	PATT
	 .word	bgm_deepdeep_10_001
	.byte	PATT
	 .word	bgm_deepdeep_10_000
	.byte	PATT
	 .word	bgm_deepdeep_10_001
	.byte	PATT
	 .word	bgm_deepdeep_10_000
	.byte	PATT
	 .word	bgm_deepdeep_10_001
	.byte	PATT
	 .word	bgm_deepdeep_10_000
	.byte		N03   , Fn4 , v112
	.byte	W08
	.byte		        Fn4 , v064
	.byte	W04
	.byte		        Fn4 , v096
	.byte	W08
	.byte		        Fn4 , v064
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		        Fn4 , v112
	.byte	W08
	.byte		        Fn4 , v064
	.byte	W04
	.byte		        Fn4 , v112
	.byte	W08
	.byte		        Fn4 , v064
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		        Fn4 , v112
	.byte	W24
	.byte	GOTO
	 .word	bgm_deepdeep_10_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_deepdeep:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_deepdeep_pri	@ Priority
	.byte	bgm_deepdeep_rev	@ Reverb.

	.word	bgm_deepdeep_grp

	.word	bgm_deepdeep_1
	.word	bgm_deepdeep_2
	.word	bgm_deepdeep_3
	.word	bgm_deepdeep_4
	.word	bgm_deepdeep_5
	.word	bgm_deepdeep_6
	.word	bgm_deepdeep_7
	.word	bgm_deepdeep_8
	.word	bgm_deepdeep_9
	.word	bgm_deepdeep_10

	.end
