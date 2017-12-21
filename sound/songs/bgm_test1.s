	.include "MPlayDef.s"

	.equ	bgm_test1_grp, voicegroup_867EB18
	.equ	bgm_test1_pri, 0
	.equ	bgm_test1_rev, reverb_set+50
	.equ	bgm_test1_mvl, 127
	.equ	bgm_test1_key, 0
	.equ	bgm_test1_tbs, 1
	.equ	bgm_test1_exg, 0
	.equ	bgm_test1_cmp, 1

	.section .rodata
	.global	bgm_test1
	.align	2

@********************** Track  1 **********************@

bgm_test1_1:
	.byte	KEYSH , bgm_test1_key+0
bgm_test1_1_B1:
	.byte	TEMPO , 128*bgm_test1_tbs/2
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 56*bgm_test1_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , Fn4 , v112
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		        Gn4 , v076
	.byte	W03
	.byte		        Fn4 , v096
	.byte	W03
	.byte		        Gn4 , v076
	.byte	W03
	.byte		        Fn4 , v096
	.byte	W03
	.byte		        Gn4 , v076
	.byte	W03
	.byte		        Fn4 , v096
	.byte	W03
	.byte		        Gn4 , v072
	.byte	W03
	.byte		N06   , Fn4 , v112
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn4 
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
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N24   , Fn4 
	.byte	W24
	.byte		N03   , Ds4 , v096
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Ds3 , v092
	.byte	W03
	.byte		N06   , Dn3 , v112
	.byte	W12
	.byte		N18   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N18   , Fn3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N32   , Cn4 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N18   , Gs3 
	.byte	W24
	.byte		N06   , Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N78   , Dn4 
	.byte	W84
	.byte		N04   , Fs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		N18   , Gs4 
	.byte	W18
	.byte		N03   , Gn4 , v064
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		N06   , Fn4 , v112
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		N06   , Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N18   , Fn3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		N03   , Gs3 
	.byte	W12
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N03   , Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N18   , Gs3 
	.byte	W24
	.byte		N06   , Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N78   , Fn4 
	.byte	W78
	.byte		N03   , Ds4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		N32   , Fn4 
	.byte	W36
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N24   
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		VOICE , 17
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		        24
	.byte	W48
	.byte		VOL   , 38*bgm_test1_mvl/mxv
	.byte	W12
	.byte		N03   , Dn4 
	.byte	W06
	.byte		        Dn4 , v088
	.byte	W06
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		        Dn4 
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W30
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Dn4 , v092
	.byte	W06
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		        Dn4 
	.byte	W18
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W12
	.byte		        As3 
	.byte	W18
	.byte		        Cn4 
	.byte	W12
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        Dn4 , v096
	.byte	W06
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		        Dn4 
	.byte	W30
	.byte		        Ds4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N24   , Fs4 
	.byte	W24
	.byte		N18   , Gs4 
	.byte	W18
	.byte		N03   , Gn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte	GOTO
	 .word	bgm_test1_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_test1_2:
	.byte	KEYSH , bgm_test1_key+0
bgm_test1_2_B1:
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 79*bgm_test1_mvl/mxv
	.byte		N06   , Fn4 , v112
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		        Gn4 , v076
	.byte	W03
	.byte		        Fn4 , v096
	.byte	W03
	.byte		        Gn4 , v076
	.byte	W03
	.byte		        Fn4 , v096
	.byte	W03
	.byte		        Gn4 , v076
	.byte	W03
	.byte		        Fn4 , v096
	.byte	W03
	.byte		        Gn4 , v072
	.byte	W03
	.byte		N06   , Fn4 , v112
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn4 
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
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N24   , Fn4 
	.byte	W24
	.byte		N03   , Ds4 , v096
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Ds3 , v092
	.byte	W03
	.byte		N06   , Dn3 , v112
	.byte	W12
	.byte		N18   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N18   , Fn3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N32   , Cn4 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N18   , Gs3 
	.byte	W24
	.byte		N06   , Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N78   , Dn4 
	.byte	W84
	.byte		N04   , Fs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		N18   , Gs4 
	.byte	W18
	.byte		N03   , Gn4 , v064
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		N06   , Fn4 , v112
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		N06   , Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N18   , Fn3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		N03   , Gs3 
	.byte	W12
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N03   , Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N18   , Gs3 
	.byte	W24
	.byte		N06   , Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N78   , Fn4 
	.byte	W78
	.byte		N03   , Ds4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		N32   , Fn4 
	.byte	W36
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N24   
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		VOICE , 17
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		        24
	.byte	W48
	.byte		VOL   , 63*bgm_test1_mvl/mxv
	.byte	W12
	.byte		N03   , Dn4 
	.byte	W06
	.byte		        Dn4 , v088
	.byte	W06
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		        Dn4 
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W30
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Dn4 , v092
	.byte	W06
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		        Dn4 
	.byte	W18
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W12
	.byte		        As3 
	.byte	W18
	.byte		        Cn4 
	.byte	W12
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        Dn4 , v096
	.byte	W06
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		        Dn4 
	.byte	W30
	.byte		        Ds4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N24   , Fs4 
	.byte	W24
	.byte		N18   , Gs4 
	.byte	W18
	.byte		N03   , Gn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte	GOTO
	 .word	bgm_test1_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_test1_3:
	.byte	KEYSH , bgm_test1_key+0
bgm_test1_3_B1:
	.byte		VOICE , 60
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 41*bgm_test1_mvl/mxv
	.byte		BEND  , c_v+1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOL   , 63*bgm_test1_mvl/mxv
	.byte	W96
	.byte	W96
	.byte		VOICE , 73
	.byte		VOL   , 56*bgm_test1_mvl/mxv
	.byte		N04   , Dn4 , v112
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		N42   , Fn4 
	.byte	W48
	.byte		N04   
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		N36   , Cn4 
	.byte	W36
	.byte		N06   , An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N36   , Fn4 
	.byte	W36
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		TIE   , Gn4 
	.byte	W72
	.byte	W48
	.byte		EOT   
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		VOL   , 45*bgm_test1_mvl/mxv
	.byte	W12
	.byte		N03   , Dn4 
	.byte	W06
	.byte		        Dn4 , v088
	.byte	W06
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		        Dn4 
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W30
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Dn4 , v092
	.byte	W06
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		        Dn4 
	.byte	W18
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W12
	.byte		        As3 
	.byte	W18
	.byte		        Cn4 
	.byte	W12
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        Dn4 , v096
	.byte	W06
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		        Dn4 
	.byte	W30
	.byte		        Ds4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N24   , Fs4 
	.byte	W24
	.byte		N18   , Gs4 
	.byte	W24
	.byte	GOTO
	 .word	bgm_test1_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_test1_4:
	.byte	KEYSH , bgm_test1_key+0
bgm_test1_4_B1:
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 45*bgm_test1_mvl/mxv
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
	.byte	W96
bgm_test1_4_000:
	.byte		N06   , Gn3 , v112
	.byte	W06
	.byte		N03   , Gn3 , v096
	.byte	W06
	.byte		        Ds3 , v064
	.byte	W06
	.byte		N03   
	.byte	W78
	.byte	PEND
	.byte	PATT
	 .word	bgm_test1_4_000
bgm_test1_4_001:
	.byte		N06   , An3 , v112
	.byte	W06
	.byte		N03   , An3 , v096
	.byte	W06
	.byte		        Fn3 , v064
	.byte	W06
	.byte		N03   
	.byte	W78
	.byte	PEND
bgm_test1_4_002:
	.byte		N06   , As3 , v112
	.byte	W06
	.byte		N03   , As3 , v096
	.byte	W06
	.byte		        Fn3 , v064
	.byte	W06
	.byte		N03   
	.byte	W78
	.byte	PEND
	.byte	PATT
	 .word	bgm_test1_4_000
	.byte	PATT
	 .word	bgm_test1_4_000
	.byte	PATT
	 .word	bgm_test1_4_001
	.byte	PATT
	 .word	bgm_test1_4_002
	.byte		N03   , Dn4 , v112
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W78
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        As2 
	.byte	W78
	.byte		        Dn4 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		        Dn2 
	.byte	W03
	.byte		        As1 
	.byte	W03
	.byte		        Dn2 
	.byte	W03
	.byte		        Ds2 
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        As3 
	.byte	W48
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        Gn2 
	.byte	W03
	.byte		        Ds2 
	.byte	W03
	.byte		        As1 
	.byte	W03
	.byte		        Gn1 
	.byte	W03
	.byte		        As1 
	.byte	W03
	.byte		        Ds2 
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		        Gn2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Gn3 
	.byte	W48
	.byte	W03
	.byte	GOTO
	 .word	bgm_test1_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_test1_5:
	.byte	KEYSH , bgm_test1_key+0
bgm_test1_5_B1:
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 45*bgm_test1_mvl/mxv
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
	.byte	W96
bgm_test1_5_000:
	.byte		N06   , Fn4 , v112
	.byte	W06
	.byte		N03   , Fn4 , v096
	.byte	W06
	.byte		        As3 , v064
	.byte	W06
	.byte		N03   
	.byte	W78
	.byte	PEND
	.byte	PATT
	 .word	bgm_test1_5_000
bgm_test1_5_001:
	.byte		N06   , Fn4 , v112
	.byte	W06
	.byte		N03   , Fn4 , v096
	.byte	W06
	.byte		        Cn4 , v064
	.byte	W06
	.byte		N03   
	.byte	W78
	.byte	PEND
	.byte	PATT
	 .word	bgm_test1_5_000
	.byte	PATT
	 .word	bgm_test1_5_000
	.byte	PATT
	 .word	bgm_test1_5_000
	.byte	PATT
	 .word	bgm_test1_5_001
	.byte	PATT
	 .word	bgm_test1_5_000
	.byte		N03   , As4 , v112
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        As3 
	.byte	W78
	.byte		        Gn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W78
	.byte		        As4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        As4 
	.byte	W48
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        Gn2 
	.byte	W03
	.byte		        Ds2 
	.byte	W03
	.byte		        Gn2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Fn4 
	.byte	W48
	.byte	W03
	.byte	GOTO
	 .word	bgm_test1_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_test1_6:
	.byte	KEYSH , bgm_test1_key+0
bgm_test1_6_B1:
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 41*bgm_test1_mvl/mxv
	.byte		N06   , En1 , v112
	.byte		N48   , An2 , v092
	.byte	W06
	.byte		N03   , En1 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		        En1 , v064
	.byte	W06
	.byte		        En1 , v088
	.byte	W06
	.byte		        En1 , v052
	.byte	W06
	.byte		        En1 , v096
	.byte	W06
	.byte		        En1 , v052
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte		N24   , An2 
	.byte	W48
bgm_test1_6_000:
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte		N48   , An2 
	.byte	W48
	.byte	PEND
	.byte		N06   , En1 
	.byte	W12
	.byte		        En1 , v092
	.byte	W24
	.byte		N03   , En1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn1 
	.byte		N24   , An2 , v076
	.byte	W24
	.byte		N06   , Cn1 , v112
	.byte		N48   , An2 
	.byte	W12
	.byte		N06   , En1 
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		N03   , En1 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v032
	.byte	W03
	.byte		        En1 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v104
	.byte	W03
	.byte		        En1 , v036
	.byte	W03
	.byte		        En1 , v096
	.byte	W03
	.byte		        En1 , v036
	.byte	W03
	.byte		        En1 , v104
	.byte	W03
	.byte		        En1 , v032
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v036
	.byte	W03
	.byte		        En1 , v096
	.byte	W03
	.byte		        En1 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v096
	.byte	W03
	.byte		        En1 , v052
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte	PATT
	 .word	bgm_test1_6_000
	.byte		N06   , En1 , v112
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn1 
	.byte		N24   , An2 , v076
	.byte	W24
	.byte		N06   , Cn1 , v112
	.byte		N48   , An2 
	.byte	W06
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   , En1 , v104
	.byte	W03
	.byte		        En1 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v104
	.byte	W03
	.byte		        En1 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v096
	.byte	W03
	.byte		        En1 , v064
	.byte	W03
	.byte		        En1 , v096
	.byte	W03
	.byte		        En1 , v064
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
bgm_test1_6_001:
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 
	.byte	W18
	.byte		N03   , Cn1 , v100
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N03   , Cn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PEND
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 
	.byte	W18
	.byte		N03   , Cn1 , v100
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N03   , Cn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 , v088
	.byte	W06
	.byte	PATT
	 .word	bgm_test1_6_001
bgm_test1_6_002:
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 
	.byte	W18
	.byte		N03   , Cn1 , v100
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Cn1 , v092
	.byte	W12
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_test1_6_001
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 
	.byte	W18
	.byte		N03   , Cn1 , v100
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N03   , Cn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 , v104
	.byte	W06
	.byte		        En1 , v092
	.byte	W06
	.byte	PATT
	 .word	bgm_test1_6_001
	.byte	PATT
	 .word	bgm_test1_6_002
bgm_test1_6_003:
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		        Cn1 , v088
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn1 , v092
	.byte	W06
	.byte		        Cn1 , v076
	.byte	W06
	.byte		        Dn1 , v104
	.byte	W12
	.byte		        En1 , v112
	.byte	W06
	.byte		        Cn1 , v096
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_test1_6_003
	.byte	PATT
	 .word	bgm_test1_6_003
	.byte		N06   , Dn1 , v112
	.byte	W06
	.byte		        Dn1 , v080
	.byte	W12
	.byte		        Dn1 , v088
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		        Dn1 , v084
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        Cn1 , v092
	.byte	W06
	.byte		        Cn1 , v076
	.byte	W06
	.byte		        Dn1 , v104
	.byte	W12
	.byte		        En1 , v112
	.byte	W06
	.byte		        Cn1 , v096
	.byte	W06
	.byte	GOTO
	 .word	bgm_test1_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_test1_7:
	.byte	KEYSH , bgm_test1_key+0
bgm_test1_7_B1:
	.byte		VOICE , 83
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 79*bgm_test1_mvl/mxv
	.byte		BEND  , c_v+0
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
	.byte		VOL   , 38*bgm_test1_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N04   , Dn4 , v112
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		N42   , Fn4 
	.byte	W48
	.byte		N04   
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		N36   , Cn4 
	.byte	W36
	.byte		N06   , An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N36   , Fn4 
	.byte	W36
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		TIE   , Gn4 
	.byte	W72
	.byte	W48
	.byte		EOT   
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		VOL   , 45*bgm_test1_mvl/mxv
	.byte	W12
	.byte		N03   , Dn4 
	.byte	W06
	.byte		        Dn4 , v088
	.byte	W06
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		        Dn4 
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W30
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Dn4 , v092
	.byte	W06
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		        Dn4 
	.byte	W18
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W12
	.byte		        As3 
	.byte	W18
	.byte		        Cn4 
	.byte	W12
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        Dn4 , v096
	.byte	W06
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		        Dn4 
	.byte	W30
	.byte		        Ds4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N24   , Fs4 
	.byte	W24
	.byte		N18   , Gs4 
	.byte	W24
	.byte	GOTO
	 .word	bgm_test1_7_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_test1:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_test1_pri	@ Priority
	.byte	bgm_test1_rev	@ Reverb.

	.word	bgm_test1_grp

	.word	bgm_test1_1
	.word	bgm_test1_2
	.word	bgm_test1_3
	.word	bgm_test1_4
	.word	bgm_test1_5
	.word	bgm_test1_6
	.word	bgm_test1_7

	.end
