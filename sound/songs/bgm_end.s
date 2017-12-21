	.include "MPlayDef.s"

	.equ	bgm_end_grp, voicegroup_86951A4
	.equ	bgm_end_pri, 0
	.equ	bgm_end_rev, reverb_set+50
	.equ	bgm_end_mvl, 127
	.equ	bgm_end_key, 0
	.equ	bgm_end_tbs, 1
	.equ	bgm_end_exg, 0
	.equ	bgm_end_cmp, 1

	.section .rodata
	.global	bgm_end
	.align	2

@********************** Track  1 **********************@

bgm_end_1:
	.byte	KEYSH , bgm_end_key+0
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte		VOICE , 24
	.byte		PAN   , c_v+0
	.byte		VOL   , 30*bgm_end_mvl/mxv
	.byte		N03   , Cn4 , v112
	.byte	W24
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds3 , v064
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        As3 , v068
	.byte	W03
	.byte		        Ds4 
	.byte	W03
bgm_end_1_B1:
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte		N03   , Gn4 , v112
	.byte	W42
	.byte		        As3 , v064
	.byte	W03
	.byte		        Ds4 , v068
	.byte	W03
	.byte	TEMPO , 132*bgm_end_tbs/2
	.byte		        An4 , v112
	.byte	W24
	.byte	TEMPO , 124*bgm_end_tbs/2
	.byte	W24
	.byte	TEMPO , 140*bgm_end_tbs/2
	.byte		        As4 
	.byte	W42
	.byte		        Gn4 , v052
	.byte	W03
	.byte		        As4 , v056
	.byte	W03
	.byte	TEMPO , 132*bgm_end_tbs/2
	.byte		        Dn5 , v068
	.byte	W03
	.byte		        Fn5 , v112
	.byte	W21
	.byte	TEMPO , 118*bgm_end_tbs/2
	.byte	W24
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte	W96
	.byte		        Ds5 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte	TEMPO , 128*bgm_end_tbs/2
	.byte		        Cn5 
	.byte	W24
	.byte	TEMPO , 118*bgm_end_tbs/2
	.byte	W12
	.byte	TEMPO , 116*bgm_end_tbs/2
	.byte		        Ds5 
	.byte	W06
	.byte		        Dn4 , v064
	.byte	W03
	.byte		        Fn4 , v072
	.byte	W03
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte		        An4 , v076
	.byte	W03
	.byte		        Dn5 , v112
	.byte	W44
	.byte	W01
	.byte	TEMPO , 128*bgm_end_tbs/2
	.byte		N01   , Fn4 
	.byte	W16
	.byte		        Gn4 
	.byte	W08
	.byte	TEMPO , 122*bgm_end_tbs/2
	.byte	W08
	.byte		        Gs4 
	.byte	W04
	.byte	TEMPO , 108*bgm_end_tbs/2
	.byte	W06
	.byte		N03   , An3 , v068
	.byte	W03
	.byte		        Dn4 , v076
	.byte	W03
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte		        An4 , v112
	.byte	W48
	.byte	TEMPO , 132*bgm_end_tbs/2
	.byte		        Cn5 
	.byte	W24
	.byte	TEMPO , 124*bgm_end_tbs/2
	.byte	W12
	.byte	TEMPO , 114*bgm_end_tbs/2
	.byte	W06
	.byte		        Dn4 , v068
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte		N01   , Cn5 , v112
	.byte	W16
	.byte		        Dn5 
	.byte	W16
	.byte		        As4 
	.byte	W64
	.byte	W09
	.byte		N03   , Fn4 , v068
	.byte	W03
	.byte		        As4 , v076
	.byte	W30
	.byte		        Dn4 , v064
	.byte	W03
	.byte		        Fn4 , v068
	.byte	W03
	.byte	TEMPO , 122*bgm_end_tbs/2
	.byte		N01   , As4 , v112
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte	TEMPO , 100*bgm_end_tbs/2
	.byte	W08
	.byte		        As4 
	.byte	W04
	.byte		N03   , Ds3 , v064
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        As3 , v068
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte	TEMPO , 140*bgm_end_tbs/2
	.byte		        Gn4 , v112
	.byte	W42
	.byte		        As3 , v064
	.byte	W03
	.byte		        Ds4 , v068
	.byte	W03
	.byte		        An4 , v112
	.byte	W48
	.byte		        As4 
	.byte	W42
	.byte		        Gn4 , v052
	.byte	W03
	.byte		        As4 , v056
	.byte	W03
	.byte	TEMPO , 128*bgm_end_tbs/2
	.byte		        Ds5 , v068
	.byte	W03
	.byte		        Gn5 , v112
	.byte	W21
	.byte	TEMPO , 122*bgm_end_tbs/2
	.byte	W12
	.byte	TEMPO , 112*bgm_end_tbs/2
	.byte	W12
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte	W96
	.byte		        An5 
	.byte	W24
	.byte		        Gn5 
	.byte	W24
	.byte	TEMPO , 132*bgm_end_tbs/2
	.byte		        Fn5 
	.byte	W24
	.byte	TEMPO , 118*bgm_end_tbs/2
	.byte	W12
	.byte		        Ds5 
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W03
	.byte		        An4 , v072
	.byte	W03
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte		        Dn5 , v076
	.byte	W03
	.byte		        Fn5 , v112
	.byte	W44
	.byte	W01
	.byte		N01   , Dn5 
	.byte	W16
	.byte		        Ds5 
	.byte	W16
	.byte		        En5 
	.byte	W16
	.byte		N03   , Fn5 
	.byte	W24
	.byte		N01   , Gs5 
	.byte	W24
	.byte	TEMPO , 130*bgm_end_tbs/2
	.byte	W16
	.byte		        Gn5 
	.byte	W08
	.byte	TEMPO , 126*bgm_end_tbs/2
	.byte	W08
	.byte		        Dn5 
	.byte	W04
	.byte	TEMPO , 122*bgm_end_tbs/2
	.byte	W06
	.byte		N03   , Gn4 , v068
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte		        Fn5 , v112
	.byte	W24
	.byte	TEMPO , 122*bgm_end_tbs/2
	.byte	W24
	.byte		        Ds5 
	.byte	W03
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte	W21
	.byte	TEMPO , 118*bgm_end_tbs/2
	.byte	W24
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte		        Dn5 
	.byte	W48
	.byte	TEMPO , 130*bgm_end_tbs/2
	.byte		        Fn5 
	.byte	W24
	.byte	TEMPO , 120*bgm_end_tbs/2
	.byte	W12
	.byte		        Ds3 , v064
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        As3 , v068
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte		        An4 , v112
	.byte	W12
	.byte		        As4 
	.byte	W09
	.byte		        Gn4 , v064
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Fn5 , v112
	.byte	W68
	.byte	W01
	.byte	W48
	.byte	TEMPO , 128*bgm_end_tbs/2
	.byte	W24
	.byte	TEMPO , 122*bgm_end_tbs/2
	.byte	W12
	.byte	TEMPO , 108*bgm_end_tbs/2
	.byte	W06
	.byte		        En4 , v068
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte		        An4 , v112
	.byte	W12
	.byte		        As4 
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W03
	.byte		        En5 
	.byte	W03
	.byte		        Gn5 , v112
	.byte	W72
	.byte	W48
	.byte	TEMPO , 128*bgm_end_tbs/2
	.byte		N01   , An5 
	.byte	W16
	.byte		        Gn5 
	.byte	W08
	.byte	TEMPO , 122*bgm_end_tbs/2
	.byte	W08
	.byte		        En5 
	.byte	W10
	.byte		N03   , As4 , v060
	.byte	W03
	.byte		        Cn5 , v064
	.byte	W03
bgm_end_1_000:
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte		N03   , Fn5 , v112
	.byte	W96
	.byte	PEND
	.byte	W90
	.byte		        Fn4 , v060
	.byte	W03
	.byte		        As4 , v064
	.byte	W03
	.byte		        Cn5 , v068
	.byte	W03
	.byte		        Ds5 , v072
	.byte	W03
	.byte		        Fn5 , v112
	.byte	W90
	.byte	W84
	.byte	W03
	.byte		        As3 , v056
	.byte	W03
	.byte		        Dn4 , v068
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        As4 , v112
	.byte	W03
	.byte		        Dn5 
	.byte	W44
	.byte	W01
	.byte	TEMPO , 128*bgm_end_tbs/2
	.byte		        Ds5 
	.byte	W24
	.byte	TEMPO , 122*bgm_end_tbs/2
	.byte	W24
	.byte	PATT
	 .word	bgm_end_1_000
	.byte	W24
	.byte		N03   , Dn5 , v112
	.byte	W24
	.byte	TEMPO , 128*bgm_end_tbs/2
	.byte		        Ds5 
	.byte	W24
	.byte	TEMPO , 118*bgm_end_tbs/2
	.byte		        Fn5 
	.byte	W18
	.byte		        As4 , v056
	.byte	W03
	.byte		        Dn5 , v060
	.byte	W03
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte		        As5 , v112
	.byte	W24
	.byte		        Fn5 
	.byte	W18
	.byte		        As4 , v060
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte	TEMPO , 132*bgm_end_tbs/2
	.byte		N01   , Ds5 , v112
	.byte	W16
	.byte		        Fn5 
	.byte	W08
	.byte	TEMPO , 128*bgm_end_tbs/2
	.byte	W08
	.byte		        Dn5 
	.byte	W04
	.byte	TEMPO , 122*bgm_end_tbs/2
	.byte	W12
bgm_end_1_001:
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte		N03   , Cn5 , v112
	.byte	W96
	.byte	PEND
bgm_end_1_002:
	.byte	W48
	.byte	TEMPO , 128*bgm_end_tbs/2
	.byte	W24
	.byte	TEMPO , 112*bgm_end_tbs/2
	.byte	W24
	.byte	PEND
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte	W96
	.byte	W48
	.byte	TEMPO , 128*bgm_end_tbs/2
	.byte	W24
	.byte	TEMPO , 108*bgm_end_tbs/2
	.byte	W15
	.byte		N03   , Cn4 , v056
	.byte	W03
	.byte		        Ds4 , v060
	.byte	W03
	.byte		        Fn4 , v064
	.byte	W03
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte		        An4 
	.byte	W03
	.byte		        Cn5 , v112
	.byte	W44
	.byte	W01
	.byte		        Dn5 
	.byte	W48
	.byte		        Ds5 
	.byte	W60
	.byte	TEMPO , 134*bgm_end_tbs/2
	.byte	W12
	.byte	TEMPO , 128*bgm_end_tbs/2
	.byte	W12
	.byte	TEMPO , 126*bgm_end_tbs/2
	.byte	W12
bgm_end_1_003:
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte	W24
	.byte		N03   , Cn5 , v112
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		        Ds5 
	.byte	W24
	.byte	PEND
	.byte		        An5 
	.byte	W24
	.byte		        Gn5 
	.byte	W24
	.byte	TEMPO , 122*bgm_end_tbs/2
	.byte		        An5 
	.byte	W24
	.byte	TEMPO , 118*bgm_end_tbs/2
	.byte	W12
	.byte	TEMPO , 102*bgm_end_tbs/2
	.byte		        Cn6 
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W03
	.byte		        As4 , v072
	.byte	W03
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte		        Dn5 
	.byte	W03
	.byte		        Fn5 , v112
	.byte	W92
	.byte	W01
	.byte	PATT
	 .word	bgm_end_1_002
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte	W96
	.byte	W48
	.byte	TEMPO , 122*bgm_end_tbs/2
	.byte	W24
	.byte	TEMPO , 112*bgm_end_tbs/2
	.byte	W12
	.byte	TEMPO , 102*bgm_end_tbs/2
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W03
	.byte		        Fn4 , v068
	.byte	W03
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte		        As4 
	.byte	W03
	.byte		        Dn5 , v112
	.byte	W44
	.byte	W01
	.byte		        Ds5 
	.byte	W24
	.byte	TEMPO , 132*bgm_end_tbs/2
	.byte	W12
	.byte	TEMPO , 126*bgm_end_tbs/2
	.byte	W12
	.byte	PATT
	 .word	bgm_end_1_000
	.byte	W24
	.byte		N03   , Dn5 , v112
	.byte	W24
	.byte	TEMPO , 128*bgm_end_tbs/2
	.byte		        Ds5 
	.byte	W24
	.byte	TEMPO , 116*bgm_end_tbs/2
	.byte		        Fn5 
	.byte	W18
	.byte		        Dn5 , v064
	.byte	W03
	.byte		        Fn5 , v068
	.byte	W03
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte		        As5 , v112
	.byte	W24
	.byte		        Fn5 
	.byte	W18
	.byte		        An4 , v064
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte	TEMPO , 128*bgm_end_tbs/2
	.byte		N01   , Ds5 , v112
	.byte	W16
	.byte		        Fn5 
	.byte	W08
	.byte	TEMPO , 118*bgm_end_tbs/2
	.byte	W08
	.byte		        Dn5 
	.byte	W16
	.byte	PATT
	 .word	bgm_end_1_001
	.byte	W48
	.byte	TEMPO , 126*bgm_end_tbs/2
	.byte	W24
	.byte	TEMPO , 108*bgm_end_tbs/2
	.byte	W24
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte	W96
	.byte	W48
	.byte	TEMPO , 118*bgm_end_tbs/2
	.byte	W24
	.byte	TEMPO , 108*bgm_end_tbs/2
	.byte	W15
	.byte		N03   , Ds4 , v064
	.byte	W03
	.byte		        Gn4 , v072
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte		        Cn5 , v112
	.byte	W48
	.byte		        Dn5 
	.byte	W24
	.byte	TEMPO , 132*bgm_end_tbs/2
	.byte	W12
	.byte	TEMPO , 122*bgm_end_tbs/2
	.byte	W12
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte		        Ds5 
	.byte	W48
	.byte	TEMPO , 134*bgm_end_tbs/2
	.byte	W24
	.byte	TEMPO , 118*bgm_end_tbs/2
	.byte	W24
	.byte	PATT
	 .word	bgm_end_1_003
	.byte		N03   , An5 , v112
	.byte	W24
	.byte		        Gn5 
	.byte	W24
	.byte	TEMPO , 122*bgm_end_tbs/2
	.byte		        An5 
	.byte	W24
	.byte	TEMPO , 102*bgm_end_tbs/2
	.byte	W12
	.byte		        Cn6 
	.byte	W06
	.byte		        Dn5 , v060
	.byte	W03
	.byte		        Fn5 , v068
	.byte	W03
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte		        As5 , v064
	.byte	W03
	.byte		        Dn6 , v112
	.byte	W92
	.byte	W01
	.byte	W48
	.byte	TEMPO , 130*bgm_end_tbs/2
	.byte	W24
	.byte	TEMPO , 112*bgm_end_tbs/2
	.byte	W24
	.byte	TEMPO , 138*bgm_end_tbs/2
	.byte	W96
	.byte	W24
	.byte	TEMPO , 132*bgm_end_tbs/2
	.byte		        As3 
	.byte	W24
	.byte	TEMPO , 118*bgm_end_tbs/2
	.byte		        Cn4 
	.byte	W24
	.byte	TEMPO , 102*bgm_end_tbs/2
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds3 , v064
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        As3 , v068
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte	GOTO
	 .word	bgm_end_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_end_2:
	.byte	KEYSH , bgm_end_key+0
	.byte		VOICE , 24
	.byte		PAN   , c_v+0
	.byte		VOL   , 36*bgm_end_mvl/mxv
	.byte		N03   , Gs2 , v112
	.byte	W24
	.byte		        Fn2 
	.byte	W24
bgm_end_2_B1:
bgm_end_2_000:
	.byte		N03   , Ds2 , v112
	.byte	W24
	.byte		        As2 , v068
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte	PEND
bgm_end_2_001:
	.byte		N03   , Gn3 , v068
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte	PEND
bgm_end_2_002:
	.byte		N03   , Ds2 , v112
	.byte	W24
	.byte		        Cn3 , v068
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte	PEND
bgm_end_2_003:
	.byte		N03   , An3 , v068
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte	PEND
bgm_end_2_004:
	.byte		N03   , Dn2 , v112
	.byte	W24
	.byte		        An2 , v068
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte	PEND
bgm_end_2_005:
	.byte		N03   , Fn3 , v068
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte	PEND
	.byte		        Gn2 , v112
	.byte	W48
	.byte		        Fs2 
	.byte	W48
	.byte		        Fn2 
	.byte	W48
	.byte		        En2 
	.byte	W48
	.byte	PATT
	 .word	bgm_end_2_000
	.byte	PATT
	 .word	bgm_end_2_001
	.byte	PATT
	 .word	bgm_end_2_002
	.byte	PATT
	 .word	bgm_end_2_003
	.byte	PATT
	 .word	bgm_end_2_004
	.byte	PATT
	 .word	bgm_end_2_005
	.byte		N01   , Gn3 , v112
	.byte	W32
	.byte		        Dn3 , v100
	.byte	W16
	.byte		        Fn3 , v112
	.byte	W16
	.byte		        Dn3 , v100
	.byte	W16
	.byte		        Bn2 , v112
	.byte	W16
	.byte		        Dn3 
	.byte	W32
	.byte		        Gn2 , v100
	.byte	W16
	.byte		        Bn2 , v112
	.byte	W16
	.byte		        Gn2 , v100
	.byte	W16
	.byte		        Fn2 , v112
	.byte	W16
	.byte		N03   , Ds2 
	.byte	W24
	.byte		        As2 , v072
	.byte	W24
	.byte		        Gn3 , v068
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte	PATT
	 .word	bgm_end_2_001
	.byte		N03   , En2 , v112
	.byte	W24
	.byte		        As2 , v068
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte	PATT
	 .word	bgm_end_2_001
	.byte		N03   , Fn2 , v112
	.byte	W24
	.byte		        As2 , v068
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		        Cn4 , v080
	.byte	W96
	.byte	W96
bgm_end_2_006:
	.byte		N03   , As2 , v112
	.byte	W24
	.byte		        Fn3 , v068
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte	PEND
bgm_end_2_007:
	.byte		N03   , As2 , v112
	.byte	W24
	.byte		        Gn3 , v068
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte	PEND
bgm_end_2_008:
	.byte		N03   , As2 , v112
	.byte	W24
	.byte		        An3 , v068
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte	PEND
	.byte		        As2 , v112
	.byte	W24
	.byte		        As3 , v068
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
bgm_end_2_009:
	.byte		N03   , Fn2 , v112
	.byte	W24
	.byte		        Cn3 , v068
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte	PEND
bgm_end_2_010:
	.byte		N03   , Fn2 , v112
	.byte	W24
	.byte		        Dn3 , v068
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte	PEND
bgm_end_2_011:
	.byte		N03   , Fn2 , v112
	.byte	W24
	.byte		        Ds3 , v068
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte	PEND
bgm_end_2_012:
	.byte		N03   , Fn2 , v112
	.byte	W24
	.byte		        Fn3 , v068
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_end_2_011
bgm_end_2_013:
	.byte		N03   , Fn2 , v112
	.byte	W24
	.byte		        Fn3 , v068
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_end_2_011
	.byte	PATT
	 .word	bgm_end_2_013
	.byte	PATT
	 .word	bgm_end_2_006
	.byte	PATT
	 .word	bgm_end_2_007
	.byte	PATT
	 .word	bgm_end_2_008
	.byte		N03   , As2 , v112
	.byte	W24
	.byte		        Cn4 , v068
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte	PATT
	 .word	bgm_end_2_006
	.byte	PATT
	 .word	bgm_end_2_007
	.byte	PATT
	 .word	bgm_end_2_008
	.byte		N03   , As2 , v112
	.byte	W24
	.byte		        As3 , v068
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte	PATT
	 .word	bgm_end_2_009
	.byte	PATT
	 .word	bgm_end_2_010
	.byte	PATT
	 .word	bgm_end_2_011
	.byte	PATT
	 .word	bgm_end_2_012
	.byte	PATT
	 .word	bgm_end_2_011
	.byte	PATT
	 .word	bgm_end_2_013
	.byte	PATT
	 .word	bgm_end_2_011
	.byte	PATT
	 .word	bgm_end_2_013
	.byte		N03   , As3 , v112
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Gs2 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
	.byte	GOTO
	 .word	bgm_end_2_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_end:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_end_pri	@ Priority
	.byte	bgm_end_rev	@ Reverb.

	.word	bgm_end_grp

	.word	bgm_end_1
	.word	bgm_end_2

	.end
