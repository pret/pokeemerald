	.include "MPlayDef.s"

	.equ	mus_conlobby_grp, voicegroup098
	.equ	mus_conlobby_pri, 0
	.equ	mus_conlobby_rev, reverb_set+50
	.equ	mus_conlobby_mvl, 127
	.equ	mus_conlobby_key, 0
	.equ	mus_conlobby_tbs, 1
	.equ	mus_conlobby_exg, 0
	.equ	mus_conlobby_cmp, 1

	.section .rodata
	.global	mus_conlobby
	.align	2

@********************** Track  1 **********************@

mus_conlobby_1:
	.byte	KEYSH , mus_conlobby_key+0
	.byte	TEMPO , 128*mus_conlobby_tbs/2
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 36*mus_conlobby_mvl/mxv
	.byte	W96
	.byte	W84
	.byte		N12   , Ds3 , v112
	.byte	W12
mus_conlobby_1_B1:
	.byte		N06   , En3 , v112
	.byte	W12
	.byte		N18   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N24   , Gn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		N42   , Dn4 
	.byte	W48
	.byte		N06   
	.byte	W12
	.byte		N18   , As3 
	.byte	W24
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N84   , En4 
	.byte	W84
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N21   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N18   , Fn4 
	.byte	W18
	.byte		N03   , En4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N03   , En3 
	.byte	W06
	.byte		        En3 , v084
	.byte	W06
	.byte		N06   , En3 , v112
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N03   , En3 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W24
	.byte		N03   , Gn3 
	.byte	W12
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N03   , As3 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N03   , Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N18   , As3 
	.byte	W24
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N36   , Gn4 
	.byte	W36
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N30   , En4 
	.byte	W30
	.byte		N03   , Ds4 , v060
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Cn4 , v112
	.byte	W12
	.byte		N21   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N18   , Dn4 
	.byte	W24
	.byte		N18   
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		N12   , Ds3 
	.byte	W12
	.byte	GOTO
	 .word	mus_conlobby_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_conlobby_2:
	.byte	KEYSH , mus_conlobby_key+0
	.byte		VOICE , 58
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 60*mus_conlobby_mvl/mxv
	.byte	W96
	.byte	W84
	.byte		N12   , Bn1 , v112
	.byte	W12
mus_conlobby_2_B1:
mus_conlobby_2_000:
	.byte		N06   , Cn2 , v112
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte	PEND
mus_conlobby_2_001:
	.byte		N06   , As1 , v112
	.byte	W24
	.byte		        Fn1 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		        Fn1 
	.byte	W24
	.byte	PEND
mus_conlobby_2_002:
	.byte		N06   , An1 , v112
	.byte	W24
	.byte		        En1 
	.byte	W24
	.byte		        An1 
	.byte	W24
	.byte		        En1 
	.byte	W24
	.byte	PEND
mus_conlobby_2_003:
	.byte		N06   , Gs1 , v112
	.byte	W24
	.byte		        Ds1 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		        Fn1 
	.byte	W12
	.byte		N12   , Bn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_conlobby_2_000
	.byte	PATT
	 .word	mus_conlobby_2_001
	.byte	PATT
	 .word	mus_conlobby_2_002
	.byte	PATT
	 .word	mus_conlobby_2_003
	.byte	PATT
	 .word	mus_conlobby_2_000
	.byte	PATT
	 .word	mus_conlobby_2_001
	.byte	PATT
	 .word	mus_conlobby_2_002
	.byte	PATT
	 .word	mus_conlobby_2_003
	.byte	PATT
	 .word	mus_conlobby_2_000
	.byte	PATT
	 .word	mus_conlobby_2_001
	.byte	PATT
	 .word	mus_conlobby_2_002
	.byte	PATT
	 .word	mus_conlobby_2_003
	.byte	GOTO
	 .word	mus_conlobby_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_conlobby_3:
	.byte	KEYSH , mus_conlobby_key+0
	.byte		VOICE , 73
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 33*mus_conlobby_mvl/mxv
	.byte	W96
	.byte	W96
mus_conlobby_3_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W90
	.byte		N03   , En4 , v112
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		N48   , Gn4 
	.byte	W60
	.byte		N06   , An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N36   , En4 
	.byte	W36
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N48   , Cn4 
	.byte	W48
	.byte		N06   , En4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        En4 , v080
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v080
	.byte	W06
	.byte		N06   , En4 , v112
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N03   , Gs3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
mus_conlobby_3_000:
	.byte		N06   , Gn3 , v112
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   , Cn4 
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   , Cn4 
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , An4 
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_conlobby_3_000
	.byte		N06   , En4 , v112
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N06   , An3 
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N06   , An3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N03   , En3 
	.byte	W06
	.byte		        Gs2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N03   , Cn5 
	.byte	W06
	.byte		N06   , As4 
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte	GOTO
	 .word	mus_conlobby_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_conlobby_4:
	.byte	KEYSH , mus_conlobby_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-61
	.byte		VOL   , 35*mus_conlobby_mvl/mxv
	.byte	W96
	.byte	W96
mus_conlobby_4_B1:
mus_conlobby_4_000:
	.byte		N06   , Cn3 , v112
	.byte	W12
	.byte		N03   , Gn3 
	.byte	W03
	.byte		        En3 , v064
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Cn3 
	.byte	W15
	.byte		        Gn3 , v112
	.byte	W12
	.byte		N06   , Cn3 
	.byte	W12
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W12
	.byte	PEND
mus_conlobby_4_001:
	.byte		N06   , As2 , v112
	.byte	W12
	.byte		N03   , Fn3 
	.byte	W03
	.byte		        En3 , v064
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Cn3 
	.byte	W15
	.byte		        Fn3 , v112
	.byte	W12
	.byte		N06   , As2 
	.byte	W12
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W12
	.byte	PEND
mus_conlobby_4_002:
	.byte		N06   , An2 , v112
	.byte	W12
	.byte		N03   , En3 
	.byte	W03
	.byte		        Dn3 , v064
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        An2 
	.byte	W15
	.byte		        En3 , v112
	.byte	W12
	.byte		N06   , An2 
	.byte	W12
	.byte		N03   , En3 
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte	PEND
mus_conlobby_4_003:
	.byte		N06   , Gs2 , v112
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W03
	.byte		        Dn3 , v064
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        As2 
	.byte	W15
	.byte		        Gs3 , v112
	.byte	W12
	.byte		N06   , As2 
	.byte	W12
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		        As3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_conlobby_4_000
	.byte	PATT
	 .word	mus_conlobby_4_001
	.byte	PATT
	 .word	mus_conlobby_4_002
	.byte	PATT
	 .word	mus_conlobby_4_003
	.byte	PATT
	 .word	mus_conlobby_4_000
	.byte	PATT
	 .word	mus_conlobby_4_001
	.byte	PATT
	 .word	mus_conlobby_4_002
	.byte	PATT
	 .word	mus_conlobby_4_003
	.byte	PATT
	 .word	mus_conlobby_4_000
	.byte	PATT
	 .word	mus_conlobby_4_001
	.byte		N06   , An2 , v112
	.byte	W12
	.byte		N03   , En3 
	.byte	W03
	.byte		        Dn3 , v064
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        An2 
	.byte	W15
	.byte		        En3 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , An2 
	.byte	W12
	.byte		N03   , En3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte	PATT
	 .word	mus_conlobby_4_003
	.byte	GOTO
	 .word	mus_conlobby_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_conlobby_5:
	.byte	KEYSH , mus_conlobby_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 33*mus_conlobby_mvl/mxv
	.byte	W96
	.byte	W96
mus_conlobby_5_B1:
mus_conlobby_5_000:
	.byte		N06   , Gn2 , v112
	.byte	W12
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        An3 , v064
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        En3 
	.byte	W15
	.byte		        Cn4 , v112
	.byte	W12
	.byte		N06   , Gn2 
	.byte	W12
	.byte		N03   , Cn4 
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W12
	.byte	PEND
mus_conlobby_5_001:
	.byte		N06   , Fn2 , v112
	.byte	W12
	.byte		N03   , As3 
	.byte	W03
	.byte		        An3 , v064
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Fn3 
	.byte	W15
	.byte		        As3 , v112
	.byte	W12
	.byte		N06   , Fn2 
	.byte	W12
	.byte		N03   , As3 
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W12
	.byte	PEND
mus_conlobby_5_002:
	.byte		N06   , En2 , v112
	.byte	W12
	.byte		N03   , An3 
	.byte	W03
	.byte		        Gn3 , v064
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        En3 
	.byte	W15
	.byte		        An3 , v112
	.byte	W12
	.byte		N06   , En2 
	.byte	W12
	.byte		N03   , An3 
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte	PEND
mus_conlobby_5_003:
	.byte		N06   , Ds2 , v112
	.byte	W12
	.byte		N03   , Gs3 
	.byte	W03
	.byte		        Gn3 , v064
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        En3 
	.byte	W15
	.byte		        Cn4 , v112
	.byte	W12
	.byte		N06   , Fn2 
	.byte	W12
	.byte		N03   , As3 
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		        Dn4 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_conlobby_5_000
	.byte	PATT
	 .word	mus_conlobby_5_001
	.byte	PATT
	 .word	mus_conlobby_5_002
	.byte	PATT
	 .word	mus_conlobby_5_003
	.byte	PATT
	 .word	mus_conlobby_5_000
	.byte	PATT
	 .word	mus_conlobby_5_001
	.byte	PATT
	 .word	mus_conlobby_5_002
	.byte	PATT
	 .word	mus_conlobby_5_003
	.byte	PATT
	 .word	mus_conlobby_5_000
	.byte	PATT
	 .word	mus_conlobby_5_001
	.byte		N06   , En2 , v112
	.byte	W12
	.byte		N03   , An3 
	.byte	W03
	.byte		        Gn3 , v064
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        En3 
	.byte	W15
	.byte		        An3 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En2 
	.byte	W12
	.byte		N03   , An3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte	PATT
	 .word	mus_conlobby_5_003
	.byte	GOTO
	 .word	mus_conlobby_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_conlobby_6:
	.byte	KEYSH , mus_conlobby_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 52*mus_conlobby_mvl/mxv
	.byte		N03   , En1 , v112
	.byte	W12
	.byte		        En1 , v060
	.byte	W12
	.byte		        En1 , v100
	.byte	W06
	.byte		        En1 , v064
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		        En1 , v060
	.byte	W06
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v060
	.byte	W12
	.byte		        En1 , v112
	.byte	W03
	.byte		        En1 , v032
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
	.byte		        En1 , v112
	.byte	W03
	.byte		        En1 , v032
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v060
	.byte	W12
	.byte		        En1 , v100
	.byte	W06
	.byte		        En1 , v064
	.byte	W06
	.byte		        En1 , v044
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v060
	.byte	W12
	.byte		        En1 , v112
	.byte	W03
	.byte		        En1 , v032
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
mus_conlobby_6_B1:
mus_conlobby_6_000:
	.byte		N03   , En1 , v112
	.byte	W12
	.byte		        En1 , v060
	.byte	W12
	.byte		        En1 , v100
	.byte	W06
	.byte		        En1 , v064
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		        En1 , v060
	.byte	W06
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v060
	.byte	W12
	.byte		        En1 , v112
	.byte	W03
	.byte		        En1 , v032
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
	.byte	PEND
mus_conlobby_6_001:
	.byte		N03   , En1 , v112
	.byte	W12
	.byte		        En1 , v060
	.byte	W12
	.byte		        En1 , v096
	.byte	W03
	.byte		        En1 , v032
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v060
	.byte	W12
	.byte		        En1 , v112
	.byte	W03
	.byte		        En1 , v032
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
	.byte	PEND
	.byte	PATT
	 .word	mus_conlobby_6_000
	.byte	PATT
	 .word	mus_conlobby_6_001
	.byte	PATT
	 .word	mus_conlobby_6_000
mus_conlobby_6_002:
	.byte		N03   , En1 , v112
	.byte	W12
	.byte		        En1 , v060
	.byte	W12
	.byte		        En1 , v096
	.byte	W03
	.byte		        En1 , v032
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        En1 , v044
	.byte	W06
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v060
	.byte	W12
	.byte		        En1 , v112
	.byte	W03
	.byte		        En1 , v032
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
	.byte	PEND
	.byte	PATT
	 .word	mus_conlobby_6_000
	.byte	PATT
	 .word	mus_conlobby_6_002
	.byte	PATT
	 .word	mus_conlobby_6_000
	.byte	PATT
	 .word	mus_conlobby_6_001
	.byte	PATT
	 .word	mus_conlobby_6_000
	.byte	PATT
	 .word	mus_conlobby_6_002
	.byte	PATT
	 .word	mus_conlobby_6_000
	.byte	PATT
	 .word	mus_conlobby_6_002
	.byte	PATT
	 .word	mus_conlobby_6_000
	.byte	PATT
	 .word	mus_conlobby_6_002
	.byte	GOTO
	 .word	mus_conlobby_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_conlobby_7:
	.byte	KEYSH , mus_conlobby_key+0
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 45*mus_conlobby_mvl/mxv
	.byte		PAN   , c_v-11
	.byte		BEND  , c_v+1
	.byte	W96
	.byte	W84
	.byte		N12   , Bn1 , v112
	.byte	W12
mus_conlobby_7_B1:
mus_conlobby_7_000:
	.byte		N06   , Cn2 , v112
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte	PEND
mus_conlobby_7_001:
	.byte		N06   , As1 , v112
	.byte	W24
	.byte		        Fn1 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		        Fn1 
	.byte	W24
	.byte	PEND
mus_conlobby_7_002:
	.byte		N06   , An1 , v112
	.byte	W24
	.byte		        En1 
	.byte	W24
	.byte		        An1 
	.byte	W24
	.byte		        En1 
	.byte	W24
	.byte	PEND
mus_conlobby_7_003:
	.byte		N06   , Gs1 , v112
	.byte	W24
	.byte		        Ds1 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		        Fn1 
	.byte	W12
	.byte		N12   , Bn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_conlobby_7_000
	.byte	PATT
	 .word	mus_conlobby_7_001
	.byte	PATT
	 .word	mus_conlobby_7_002
	.byte	PATT
	 .word	mus_conlobby_7_003
	.byte	PATT
	 .word	mus_conlobby_7_000
	.byte	PATT
	 .word	mus_conlobby_7_001
	.byte	PATT
	 .word	mus_conlobby_7_002
	.byte	PATT
	 .word	mus_conlobby_7_003
	.byte	PATT
	 .word	mus_conlobby_7_000
	.byte	PATT
	 .word	mus_conlobby_7_001
	.byte	PATT
	 .word	mus_conlobby_7_002
	.byte	PATT
	 .word	mus_conlobby_7_003
	.byte	GOTO
	 .word	mus_conlobby_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_conlobby_8:
	.byte	KEYSH , mus_conlobby_key+0
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-14
	.byte		VOL   , 28*mus_conlobby_mvl/mxv
	.byte	W96
	.byte	W84
	.byte		N12   , Fs2 , v112
	.byte	W12
mus_conlobby_8_B1:
	.byte		N06   , Gn2 , v112
	.byte	W12
	.byte		N18   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N24   , Cn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		N42   , Fn3 
	.byte	W48
	.byte		N06   
	.byte	W12
	.byte		N18   , Dn3 
	.byte	W24
	.byte		N06   , As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N84   , Cn4 
	.byte	W84
	.byte		N03   , Ds3 
	.byte	W12
	.byte		N21   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N18   , Gs3 
	.byte	W18
	.byte		N03   , Gn3 , v068
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		N12   , Fn3 , v112
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		N03   , Gn2 
	.byte	W06
	.byte		        Gn2 , v080
	.byte	W06
	.byte		N06   , Gn2 , v112
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N03   , Cn3 
	.byte	W12
	.byte		N24   , En3 
	.byte	W24
	.byte		N03   , Dn3 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N03   , En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N18   , Dn3 
	.byte	W24
	.byte		N06   , As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N36   , En4 
	.byte	W36
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N30   , Cn4 
	.byte	W30
	.byte		N03   , Bn3 , v060
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Ds3 , v112
	.byte	W12
	.byte		N21   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N18   , Fn3 
	.byte	W24
	.byte		N18   
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_conlobby_8_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_conlobby:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_conlobby_pri	@ Priority
	.byte	mus_conlobby_rev	@ Reverb.

	.word	mus_conlobby_grp

	.word	mus_conlobby_1
	.word	mus_conlobby_2
	.word	mus_conlobby_3
	.word	mus_conlobby_4
	.word	mus_conlobby_5
	.word	mus_conlobby_6
	.word	mus_conlobby_7
	.word	mus_conlobby_8

	.end
