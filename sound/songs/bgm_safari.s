	.include "MPlayDef.s"

	.equ	bgm_safari_grp, voicegroup_868B274
	.equ	bgm_safari_pri, 0
	.equ	bgm_safari_rev, reverb_set+50
	.equ	bgm_safari_mvl, 127
	.equ	bgm_safari_key, 0
	.equ	bgm_safari_tbs, 1
	.equ	bgm_safari_exg, 0
	.equ	bgm_safari_cmp, 1

	.section .rodata
	.global	bgm_safari
	.align	2

@********************** Track  1 **********************@

bgm_safari_1:
	.byte	KEYSH , bgm_safari_key+0
	.byte	TEMPO , 142*bgm_safari_tbs/2
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 30*bgm_safari_mvl/mxv
	.byte	W12
bgm_safari_1_B1:
bgm_safari_1_000:
	.byte	W12
	.byte		N03   , En5 , v104
	.byte	W06
	.byte		        En5 , v080
	.byte	W18
	.byte		        En5 , v104
	.byte	W06
	.byte		        En5 , v080
	.byte	W18
	.byte		        En5 , v104
	.byte	W06
	.byte		        En5 , v080
	.byte	W18
	.byte		        En5 , v104
	.byte	W06
	.byte		        En5 , v080
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_safari_1_000
	.byte	PATT
	 .word	bgm_safari_1_000
	.byte	PATT
	 .word	bgm_safari_1_000
	.byte	PATT
	 .word	bgm_safari_1_000
	.byte	PATT
	 .word	bgm_safari_1_000
	.byte	PATT
	 .word	bgm_safari_1_000
	.byte	PATT
	 .word	bgm_safari_1_000
	.byte	PATT
	 .word	bgm_safari_1_000
	.byte	PATT
	 .word	bgm_safari_1_000
	.byte	PATT
	 .word	bgm_safari_1_000
	.byte	PATT
	 .word	bgm_safari_1_000
	.byte	GOTO
	 .word	bgm_safari_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_safari_2:
	.byte	KEYSH , bgm_safari_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 32*bgm_safari_mvl/mxv
	.byte	W12
bgm_safari_2_B1:
bgm_safari_2_000:
	.byte		N12   , Gn5 , v112
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_safari_2_000
	.byte	PATT
	 .word	bgm_safari_2_000
	.byte	PATT
	 .word	bgm_safari_2_000
	.byte	PATT
	 .word	bgm_safari_2_000
	.byte	PATT
	 .word	bgm_safari_2_000
	.byte	PATT
	 .word	bgm_safari_2_000
	.byte	PATT
	 .word	bgm_safari_2_000
	.byte	PATT
	 .word	bgm_safari_2_000
	.byte	PATT
	 .word	bgm_safari_2_000
	.byte	PATT
	 .word	bgm_safari_2_000
	.byte	PATT
	 .word	bgm_safari_2_000
	.byte	GOTO
	 .word	bgm_safari_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_safari_3:
	.byte	KEYSH , bgm_safari_key+0
	.byte		VOICE , 35
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 82*bgm_safari_mvl/mxv
	.byte	W12
bgm_safari_3_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		PAN   , c_v-24
	.byte	W12
	.byte		N06   , Fn0 , v127
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , As0 
	.byte	W24
	.byte		N12   
	.byte	W24
bgm_safari_3_000:
	.byte		BEND  , c_v+0
	.byte	W36
	.byte		N06   , Fn0 , v127
	.byte	W12
	.byte		        En0 
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		N24   
	.byte	W06
	.byte		BEND  , c_v+12
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte	PEND
bgm_safari_3_001:
	.byte	W12
	.byte		N06   , Fn0 , v127
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , As0 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	W36
	.byte		N06   , Fn0 
	.byte	W12
	.byte		        En0 
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		N24   , As0 
	.byte	W06
	.byte		BEND  , c_v+10
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte	PATT
	 .word	bgm_safari_3_001
	.byte	PATT
	 .word	bgm_safari_3_000
	.byte	PATT
	 .word	bgm_safari_3_001
	.byte	W36
	.byte		N06   , Fn0 , v127
	.byte	W12
	.byte		        En0 
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		N24   
	.byte	W06
	.byte		BEND  , c_v+10
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte	GOTO
	 .word	bgm_safari_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_safari_4:
	.byte	KEYSH , bgm_safari_key+0
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 69*bgm_safari_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , Fn1 , v112
	.byte	W06
	.byte		N03   , Ds1 
	.byte	W03
	.byte		        En1 
	.byte	W03
bgm_safari_4_B1:
	.byte		PAN   , c_v-21
	.byte		BEND  , c_v+0
	.byte		N06   , Fn1 , v112
	.byte	W12
	.byte		N12   
	.byte	W18
	.byte		        Fn1 , v076
	.byte	W18
	.byte		PAN   , c_v+7
	.byte		N06   , As2 
	.byte	W12
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N06   , As2 , v072
	.byte	W06
	.byte		PAN   , c_v-21
	.byte	W12
	.byte		N06   , As2 , v112
	.byte	W12
	.byte		PAN   , c_v+6
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-22
	.byte		BEND  , c_v-62
	.byte		N36   , Cn2 
	.byte	W12
	.byte		BEND  , c_v-55
	.byte	W02
	.byte		        c_v-43
	.byte	W03
	.byte		        c_v-32
	.byte	W03
	.byte		        c_v-19
	.byte	W04
	.byte		        c_v+18
	.byte	W02
	.byte		        c_v+32
	.byte	W03
	.byte		        c_v+41
	.byte	W03
	.byte		        c_v+48
	.byte	W04
	.byte		PAN   , c_v+5
	.byte		BEND  , c_v+0
	.byte		N06   , Fn2 
	.byte	W30
	.byte		N03   , As2 , v092
	.byte	W06
	.byte		        As2 , v088
	.byte	W03
	.byte		PAN   , c_v-21
	.byte	W03
	.byte		N03   , Fn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+5
	.byte		N12   , Fn2 , v076
	.byte	W12
	.byte		PAN   , c_v-22
	.byte	W06
	.byte		N12   , Fn1 , v112
	.byte	W18
	.byte		PAN   , c_v+6
	.byte		N06   , As2 , v076
	.byte	W15
	.byte		PAN   , c_v-23
	.byte	W03
	.byte		N06   , Fn2 , v108
	.byte	W12
	.byte		        Fn2 , v112
	.byte	W06
	.byte		PAN   , c_v+5
	.byte		N06   , As2 
	.byte	W12
	.byte		PAN   , c_v-23
	.byte		N06   , As1 
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W36
	.byte		PAN   , c_v+5
	.byte		BEND  , c_v-62
	.byte		N48   , Fn2 
	.byte	W12
	.byte		BEND  , c_v-55
	.byte	W02
	.byte		        c_v-43
	.byte	W03
	.byte		        c_v-32
	.byte	W03
	.byte		        c_v-19
	.byte	W04
	.byte		        c_v+18
	.byte	W02
	.byte		        c_v+32
	.byte	W03
	.byte		        c_v+41
	.byte	W03
	.byte		        c_v+48
	.byte	W04
	.byte		        c_v+58
	.byte	W02
	.byte		        c_v+63
	.byte	W03
	.byte		        c_v+24
	.byte	W03
	.byte		        c_v+62
	.byte	W04
	.byte		PAN   , c_v-21
	.byte		BEND  , c_v+0
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W18
	.byte		N06   , Fn1 , v104
	.byte	W12
	.byte		        Fn2 , v080
	.byte	W06
	.byte		PAN   , c_v+6
	.byte		N06   , As2 , v076
	.byte	W18
	.byte		        As2 , v072
	.byte	W06
	.byte		PAN   , c_v-21
	.byte	W12
	.byte		N06   , As2 , v112
	.byte	W12
	.byte		PAN   , c_v+6
	.byte		N06   , Cn3 
	.byte	W12
	.byte		PAN   , c_v-22
	.byte		N06   , As2 
	.byte	W24
	.byte		        Fn2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		PAN   , c_v+7
	.byte		N06   , As1 , v092
	.byte	W06
	.byte		        As1 , v100
	.byte	W06
	.byte		N18   , Fn1 , v072
	.byte	W18
	.byte		N03   , As2 , v092
	.byte	W06
	.byte		        As2 , v088
	.byte	W03
	.byte		PAN   , c_v-21
	.byte	W03
	.byte		N06   , Fn1 , v112
	.byte	W06
	.byte		        An1 
	.byte	W12
	.byte		PAN   , c_v+7
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v-22
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		PAN   , c_v+6
	.byte		N06   , An2 , v076
	.byte	W15
	.byte		PAN   , c_v-23
	.byte	W03
	.byte		N06   , Fn2 , v108
	.byte	W12
	.byte		        Fn2 , v112
	.byte	W06
	.byte		PAN   , c_v+6
	.byte		N06   , As2 
	.byte	W12
	.byte		PAN   , c_v-23
	.byte		N06   , An1 
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W36
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v-62
	.byte		N36   , Fn2 
	.byte	W12
	.byte		BEND  , c_v-55
	.byte	W02
	.byte		        c_v-43
	.byte	W03
	.byte		        c_v-32
	.byte	W03
	.byte		        c_v-19
	.byte	W04
	.byte		        c_v+18
	.byte	W02
	.byte		        c_v+32
	.byte	W03
	.byte		        c_v+41
	.byte	W03
	.byte		        c_v+48
	.byte	W01
	.byte		        c_v+63
	.byte	W03
	.byte		        c_v+0
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-21
	.byte		N06   , As1 
	.byte	W12
	.byte		N12   , Fn1 
	.byte	W18
	.byte		N06   , As1 , v104
	.byte	W12
	.byte		        Fn2 , v080
	.byte	W06
	.byte		PAN   , c_v+6
	.byte		N06   , As2 , v076
	.byte	W18
	.byte		        As2 , v072
	.byte	W06
	.byte		PAN   , c_v-21
	.byte	W12
	.byte		N06   , As2 , v112
	.byte	W12
	.byte		PAN   , c_v+6
	.byte		N06   , Cn3 
	.byte	W12
	.byte		PAN   , c_v-22
	.byte		N06   , As2 
	.byte	W24
	.byte		        Fn2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		PAN   , c_v+5
	.byte		N06   , As1 , v092
	.byte	W06
	.byte		        As1 , v100
	.byte	W06
	.byte		N18   , Fn1 , v072
	.byte	W18
	.byte		N03   , As2 , v092
	.byte	W06
	.byte		        As2 , v088
	.byte	W03
	.byte		PAN   , c_v-21
	.byte	W03
	.byte		N06   , Fn1 , v112
	.byte	W06
	.byte		        As1 
	.byte	W12
	.byte		PAN   , c_v+5
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v-22
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		PAN   , c_v+5
	.byte		N06   , As2 , v076
	.byte	W15
	.byte		PAN   , c_v-23
	.byte	W03
	.byte		N06   , Fn2 , v108
	.byte	W12
	.byte		        Fn2 , v112
	.byte	W06
	.byte		PAN   , c_v+5
	.byte		N06   , As2 
	.byte	W12
	.byte		PAN   , c_v-23
	.byte		N06   , As1 
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W36
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v-62
	.byte		N48   , En2 
	.byte	W12
	.byte		BEND  , c_v-55
	.byte	W02
	.byte		        c_v-43
	.byte	W03
	.byte		        c_v-32
	.byte	W03
	.byte		        c_v-19
	.byte	W04
	.byte		        c_v+18
	.byte	W02
	.byte		        c_v+32
	.byte	W03
	.byte		        c_v+41
	.byte	W03
	.byte		        c_v+48
	.byte	W04
	.byte		        c_v+58
	.byte	W02
	.byte		        c_v+63
	.byte	W03
	.byte		        c_v+24
	.byte	W03
	.byte		        c_v+62
	.byte	W04
	.byte	GOTO
	 .word	bgm_safari_4_B1
	.byte		BEND  , c_v+0
	.byte	FINE

@********************** Track  5 **********************@

bgm_safari_5:
	.byte	KEYSH , bgm_safari_key+0
	.byte		VOICE , 13
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-28
	.byte		VOL   , 24*bgm_safari_mvl/mxv
	.byte	W12
bgm_safari_5_B1:
	.byte	W12
	.byte		N03   , Fn5 , v112
	.byte	W12
	.byte		        Fn5 , v080
	.byte	W24
	.byte		        Fn5 , v104
	.byte	W18
	.byte		        Fn5 , v080
	.byte	W18
	.byte		        Fn5 , v120
	.byte	W12
	.byte	W12
	.byte		        Fn5 , v112
	.byte	W12
	.byte		        Fn5 , v080
	.byte	W18
	.byte		        Fn5 , v052
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Fn5 , v112
	.byte	W18
	.byte		        Fn5 , v084
	.byte	W18
	.byte		        Fn5 , v112
	.byte	W12
	.byte	W06
	.byte		        Fn5 , v060
	.byte	W03
	.byte		        Fn5 , v048
	.byte	W03
	.byte		        Fn5 , v112
	.byte	W12
	.byte		        Fn5 , v080
	.byte	W24
	.byte		        Fn5 , v104
	.byte	W18
	.byte		        Fn5 , v080
	.byte	W12
	.byte		        Fn5 , v064
	.byte	W03
	.byte		        En5 , v048
	.byte	W03
	.byte		        Fn5 , v120
	.byte	W12
	.byte		        Fn5 , v064
	.byte	W03
	.byte		        Fn5 , v048
	.byte	W03
	.byte		        Fn5 , v088
	.byte	W06
	.byte		        Fn5 , v120
	.byte	W12
	.byte		        Fn5 , v080
	.byte	W18
	.byte		        Fn5 , v052
	.byte	W03
	.byte		        En5 
	.byte	W03
	.byte		        Fn5 , v112
	.byte	W18
	.byte		        Fn5 , v084
	.byte	W18
	.byte		        Fn5 , v112
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_safari_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_safari_6:
	.byte	KEYSH , bgm_safari_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-61
	.byte		VOL   , 44*bgm_safari_mvl/mxv
	.byte	W12
bgm_safari_6_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		N03   , Gn2 , v112
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
bgm_safari_6_000:
	.byte		N60   , As3 , v112
	.byte	W24
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte		N03   , An3 
	.byte	W24
	.byte		        Gn3 
	.byte	W12
	.byte	PEND
	.byte		N03   
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		VOICE , 84
	.byte	W12
	.byte		N03   , As2 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        Gn2 
	.byte	W03
	.byte		        Fs2 
	.byte	W03
	.byte		PAN   , c_v-1
	.byte		N48   , Fn2 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
bgm_safari_6_001:
	.byte		VOICE , 80
	.byte		MOD   , 0
	.byte		PAN   , c_v-64
	.byte		N03   , Cn4 , v112
	.byte	W12
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W03
	.byte		        Bn3 , v072
	.byte	W03
	.byte		        Cn4 , v092
	.byte	W06
	.byte		        Bn3 , v080
	.byte	W06
	.byte		N06   , Cn4 , v112
	.byte	W18
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		        Bn3 , v064
	.byte	W03
	.byte		        Cn4 , v092
	.byte	W06
	.byte		        Cn4 , v072
	.byte	W06
	.byte	PEND
bgm_safari_6_002:
	.byte		N03   , As3 , v112
	.byte	W12
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W03
	.byte		        An3 , v072
	.byte	W03
	.byte		        As3 , v092
	.byte	W06
	.byte		        An3 , v080
	.byte	W06
	.byte		N06   , As3 , v112
	.byte	W18
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		        An3 , v064
	.byte	W03
	.byte		        As3 , v092
	.byte	W06
	.byte		        As3 , v072
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_safari_6_000
	.byte		N03   , Gn3 , v112
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		VOICE , 84
	.byte	W12
	.byte		N03   , As2 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        Gn2 
	.byte	W03
	.byte		        Fs2 
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N48   , Fn2 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte	PATT
	 .word	bgm_safari_6_001
	.byte	PATT
	 .word	bgm_safari_6_002
	.byte	GOTO
	 .word	bgm_safari_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_safari_7:
	.byte	KEYSH , bgm_safari_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 44*bgm_safari_mvl/mxv
	.byte	W12
bgm_safari_7_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
bgm_safari_7_000:
	.byte		N60   , Ds4 , v112
	.byte	W24
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte		N03   , Dn4 
	.byte	W24
	.byte		        Cn4 
	.byte	W12
	.byte	PEND
	.byte		N03   
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W12
	.byte		VOICE , 83
	.byte	W12
	.byte		N03   , Fn3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N48   , As2 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
bgm_safari_7_001:
	.byte		VOICE , 81
	.byte		MOD   , 0
	.byte		PAN   , c_v+63
	.byte		N03   , Ds4 , v112
	.byte	W12
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W03
	.byte		        Dn4 , v072
	.byte	W03
	.byte		        Ds4 , v092
	.byte	W06
	.byte		        Dn4 , v080
	.byte	W06
	.byte		N06   , Ds4 , v112
	.byte	W18
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		        Dn4 , v064
	.byte	W03
	.byte		        Ds4 , v092
	.byte	W06
	.byte		        Ds4 , v072
	.byte	W06
	.byte	PEND
bgm_safari_7_002:
	.byte		N03   , Dn4 , v112
	.byte	W12
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W03
	.byte		        Cs4 , v072
	.byte	W03
	.byte		        Dn4 , v092
	.byte	W06
	.byte		        Cs4 , v080
	.byte	W06
	.byte		N06   , Dn4 , v112
	.byte	W18
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		        Cs4 , v064
	.byte	W03
	.byte		        Dn4 , v092
	.byte	W06
	.byte		        Dn4 , v072
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_safari_7_000
	.byte		N03   , Cn4 , v112
	.byte	W12
	.byte		N06   , As3 
	.byte	W12
	.byte		VOICE , 83
	.byte	W12
	.byte		N03   , Fn3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N48   , As2 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte	PATT
	 .word	bgm_safari_7_001
	.byte	PATT
	 .word	bgm_safari_7_002
	.byte	GOTO
	 .word	bgm_safari_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_safari_8:
	.byte	KEYSH , bgm_safari_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 66*bgm_safari_mvl/mxv
	.byte	W12
bgm_safari_8_B1:
bgm_safari_8_000:
	.byte		N06   , Cn1 , v127
	.byte		N06   , En3 , v112
	.byte	W06
	.byte		        Cn1 , v064
	.byte		N06   , En3 , v076
	.byte	W06
	.byte		        Cn1 , v088
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		        Cn1 , v060
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Cn1 , v064
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		        Cn1 , v084
	.byte		N06   , En3 , v080
	.byte	W06
	.byte		        Cn1 , v064
	.byte	W06
	.byte		        Cn1 , v127
	.byte		N06   , En3 , v112
	.byte	W06
	.byte		        Cn1 , v064
	.byte	W06
	.byte		        Cn1 , v080
	.byte		N06   , En3 , v088
	.byte	W06
	.byte		        Cn1 , v120
	.byte		N06   , En3 , v068
	.byte	W06
	.byte		        Cn1 , v072
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		        Cn1 , v064
	.byte		N06   , En3 , v112
	.byte	W06
	.byte		        Cn1 , v124
	.byte	W06
	.byte		        Cn1 , v060
	.byte		N06   , En3 , v076
	.byte	W06
	.byte	PEND
bgm_safari_8_001:
	.byte		N06   , Cn1 , v127
	.byte		N06   , En3 , v112
	.byte	W06
	.byte		        Cn1 , v064
	.byte		N06   , En3 , v080
	.byte	W06
	.byte		        Cn1 , v088
	.byte		N06   , En3 , v112
	.byte	W06
	.byte		        Cn1 , v060
	.byte	W06
	.byte		        Cn1 , v112
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        Cn1 , v064
	.byte		N06   , Dn3 , v088
	.byte	W06
	.byte		        Cn1 , v084
	.byte		N06   , En3 , v112
	.byte	W06
	.byte		        Cn1 , v064
	.byte		N06   , En3 , v080
	.byte	W06
	.byte		        Cn1 , v127
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		        En3 , v080
	.byte	W03
	.byte		N06   , Cn1 , v064
	.byte		N06   , En3 , v112
	.byte	W06
	.byte		        Cn1 , v080
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		        Cn1 , v120
	.byte		N06   , En3 , v088
	.byte	W06
	.byte		        Cn1 , v072
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		        En3 , v080
	.byte	W03
	.byte		N06   , Cn1 , v064
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		        Cn1 , v124
	.byte		N06   , En3 , v088
	.byte	W06
	.byte		        Cn1 , v060
	.byte		N06   , Dn3 , v088
	.byte	W06
	.byte	PEND
bgm_safari_8_002:
	.byte		N06   , Cn1 , v127
	.byte		N06   , En3 , v112
	.byte	W06
	.byte		        Cn1 , v064
	.byte		N06   , En3 , v080
	.byte	W06
	.byte		        Cn1 , v088
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		        Cn1 , v060
	.byte	W06
	.byte		        Cn1 , v112
	.byte		N03   , Dn3 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Cn1 
	.byte		N06   , Dn3 , v108
	.byte	W06
	.byte		        Cn1 , v084
	.byte		N06   , En3 , v088
	.byte	W06
	.byte		        Cn1 , v064
	.byte	W06
	.byte		        Cn1 , v127
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		        Cn1 , v064
	.byte	W06
	.byte		        Cn1 , v080
	.byte		N06   , En3 , v088
	.byte	W06
	.byte		        Cn1 , v120
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		        Cn1 , v072
	.byte		N06   , En3 , v112
	.byte	W06
	.byte		        Cn1 , v064
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		        Cn1 , v124
	.byte		N06   , En3 , v088
	.byte	W06
	.byte		        Cn1 , v060
	.byte		N06   , En3 , v076
	.byte	W06
	.byte	PEND
bgm_safari_8_003:
	.byte		N06   , Cn1 , v127
	.byte		N06   , En3 , v112
	.byte	W06
	.byte		        Cn1 , v064
	.byte		N06   , En3 , v080
	.byte	W06
	.byte		        Cn1 , v088
	.byte		N06   , En3 , v112
	.byte	W06
	.byte		        Cn1 , v060
	.byte	W06
	.byte		        Cn1 , v112
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        Cn1 , v064
	.byte		N06   , Dn3 , v088
	.byte	W06
	.byte		        Cn1 , v084
	.byte		N06   , En3 , v112
	.byte	W06
	.byte		        Cn1 , v064
	.byte		N06   , En3 , v080
	.byte	W06
	.byte		        Cn1 , v127
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		        En3 , v080
	.byte	W03
	.byte		N06   , Cn1 , v064
	.byte		N06   , En3 , v112
	.byte	W06
	.byte		        Cn1 , v080
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		        Cn1 , v120
	.byte		N06   , En3 , v088
	.byte	W06
	.byte		        Cn1 , v072
	.byte		N03   , En3 , v112
	.byte	W06
	.byte		N06   , Cn1 , v064
	.byte		N03   , En3 , v080
	.byte	W06
	.byte		N06   , Cn1 , v124
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		        Cn1 , v060
	.byte		N06   , En3 , v080
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_safari_8_000
	.byte	PATT
	 .word	bgm_safari_8_001
	.byte	PATT
	 .word	bgm_safari_8_002
	.byte	PATT
	 .word	bgm_safari_8_003
	.byte	PATT
	 .word	bgm_safari_8_000
	.byte	PATT
	 .word	bgm_safari_8_001
	.byte	PATT
	 .word	bgm_safari_8_002
	.byte	PATT
	 .word	bgm_safari_8_003
	.byte	GOTO
	 .word	bgm_safari_8_B1
	.byte	FINE

@********************** Track  9 **********************@

bgm_safari_9:
	.byte	KEYSH , bgm_safari_key+0
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 19*bgm_safari_mvl/mxv
	.byte	W12
bgm_safari_9_B1:
bgm_safari_9_000:
	.byte		N03   , Cn5 , v112
	.byte	W06
	.byte		        Ds5 , v076
	.byte	W06
	.byte		        As4 , v112
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        As4 , v112
	.byte	W12
	.byte		        Cn5 , v088
	.byte	W06
	.byte		        Cn5 , v068
	.byte	W06
	.byte		        As4 , v112
	.byte	W06
	.byte		        Ds5 
	.byte	W12
	.byte		        Cn5 , v076
	.byte	W06
	.byte	PEND
bgm_safari_9_001:
	.byte		N03   , Cn5 , v112
	.byte	W06
	.byte		        Bn4 , v080
	.byte	W06
	.byte		        Dn5 , v112
	.byte	W12
	.byte		        An4 
	.byte	W06
	.byte		        An4 , v088
	.byte	W06
	.byte		        Bn4 , v112
	.byte	W06
	.byte		        Bn4 , v080
	.byte	W06
	.byte		        Gn5 , v112
	.byte	W03
	.byte		        Bn4 , v080
	.byte	W03
	.byte		        Bn4 , v112
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 , v088
	.byte	W06
	.byte		        Bn4 , v112
	.byte	W03
	.byte		        Bn4 , v080
	.byte	W03
	.byte		        An4 , v112
	.byte	W06
	.byte		        Bn4 , v088
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_safari_9_000
	.byte	PATT
	 .word	bgm_safari_9_001
	.byte	PATT
	 .word	bgm_safari_9_000
	.byte	PATT
	 .word	bgm_safari_9_001
	.byte	PATT
	 .word	bgm_safari_9_000
	.byte	PATT
	 .word	bgm_safari_9_001
	.byte	PATT
	 .word	bgm_safari_9_000
	.byte	PATT
	 .word	bgm_safari_9_001
	.byte	PATT
	 .word	bgm_safari_9_000
	.byte	PATT
	 .word	bgm_safari_9_001
	.byte	GOTO
	 .word	bgm_safari_9_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_safari:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_safari_pri	@ Priority
	.byte	bgm_safari_rev	@ Reverb.

	.word	bgm_safari_grp

	.word	bgm_safari_1
	.word	bgm_safari_2
	.word	bgm_safari_3
	.word	bgm_safari_4
	.word	bgm_safari_5
	.word	bgm_safari_6
	.word	bgm_safari_7
	.word	bgm_safari_8
	.word	bgm_safari_9

	.end
