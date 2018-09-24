	.include "MPlayDef.s"

	.equ	mus_kakkoii_grp, voicegroup063
	.equ	mus_kakkoii_pri, 0
	.equ	mus_kakkoii_rev, reverb_set+50
	.equ	mus_kakkoii_mvl, 127
	.equ	mus_kakkoii_key, 0
	.equ	mus_kakkoii_tbs, 1
	.equ	mus_kakkoii_exg, 0
	.equ	mus_kakkoii_cmp, 1

	.section .rodata
	.global	mus_kakkoii
	.align	2

@********************** Track  1 **********************@

mus_kakkoii_1:
	.byte	KEYSH , mus_kakkoii_key+0
	.byte	TEMPO , 140*mus_kakkoii_tbs/2
	.byte		VOICE , 127
	.byte		PAN   , c_v+63
	.byte		VOL   , 43*mus_kakkoii_mvl/mxv
	.byte	W12
mus_kakkoii_1_000:
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        En4 , v064
	.byte	W18
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v064
	.byte	W18
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v064
	.byte	W18
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v064
	.byte	W18
	.byte	PEND
	.byte	PATT
	 .word	mus_kakkoii_1_000
mus_kakkoii_1_B1:
mus_kakkoii_1_001:
	.byte		N03   , En4 , v112
	.byte	W12
	.byte		        En4 , v084
	.byte	W06
	.byte		        En4 , v072
	.byte	W06
	.byte		        En4 , v112
	.byte	W12
	.byte		        En4 , v084
	.byte	W06
	.byte		        En4 , v072
	.byte	W06
	.byte		        En4 , v112
	.byte	W12
	.byte		        En4 , v084
	.byte	W06
	.byte		        En4 , v072
	.byte	W06
	.byte		        En4 , v112
	.byte	W12
	.byte		        En4 , v084
	.byte	W06
	.byte		        En4 , v072
	.byte	W06
	.byte	PEND
mus_kakkoii_1_002:
	.byte		N02   , En4 , v112
	.byte	W04
	.byte		        En4 , v088
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N03   
	.byte	W06
	.byte		        En4 , v072
	.byte	W06
	.byte		        En4 , v112
	.byte	W12
	.byte		        En4 , v084
	.byte	W06
	.byte		        En4 , v072
	.byte	W06
	.byte		        En4 , v112
	.byte	W12
	.byte		        En4 , v084
	.byte	W06
	.byte		        En4 , v072
	.byte	W06
	.byte		        En4 , v112
	.byte	W12
	.byte		        En4 , v084
	.byte	W06
	.byte		        En4 , v072
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_kakkoii_1_001
mus_kakkoii_1_003:
	.byte		N02   , En4 , v112
	.byte	W04
	.byte		        En4 , v088
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N03   
	.byte	W06
	.byte		        En4 , v072
	.byte	W06
	.byte		        En4 , v112
	.byte	W12
	.byte		        En4 , v084
	.byte	W06
	.byte		        En4 , v072
	.byte	W06
	.byte		N02   , En4 , v112
	.byte	W04
	.byte		        En4 , v088
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N03   
	.byte	W06
	.byte		        En4 , v072
	.byte	W06
	.byte		        En4 , v112
	.byte	W12
	.byte		        En4 , v084
	.byte	W06
	.byte		        En4 , v072
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_kakkoii_1_001
	.byte	PATT
	 .word	mus_kakkoii_1_002
	.byte	PATT
	 .word	mus_kakkoii_1_001
	.byte	PATT
	 .word	mus_kakkoii_1_003
	.byte	PATT
	 .word	mus_kakkoii_1_001
	.byte	PATT
	 .word	mus_kakkoii_1_002
	.byte	PATT
	 .word	mus_kakkoii_1_001
	.byte	PATT
	 .word	mus_kakkoii_1_003
	.byte	PATT
	 .word	mus_kakkoii_1_001
	.byte	PATT
	 .word	mus_kakkoii_1_002
	.byte	PATT
	 .word	mus_kakkoii_1_001
	.byte	PATT
	 .word	mus_kakkoii_1_003
	.byte	GOTO
	 .word	mus_kakkoii_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_kakkoii_2:
	.byte	KEYSH , mus_kakkoii_key+0
	.byte		VOICE , 126
	.byte		PAN   , c_v+63
	.byte		VOL   , 43*mus_kakkoii_mvl/mxv
	.byte	W12
	.byte	W36
	.byte		N10   , Fn4 , v096
	.byte	W24
	.byte		N10   
	.byte	W24
	.byte		N10   
	.byte	W12
	.byte	W12
	.byte		N10   
	.byte	W24
	.byte		N10   
	.byte	W24
	.byte		N10   
	.byte	W24
	.byte		N10   
	.byte	W12
mus_kakkoii_2_B1:
	.byte	W12
	.byte		N10   , Fn4 , v096
	.byte	W84
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
	.byte	GOTO
	 .word	mus_kakkoii_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_kakkoii_3:
	.byte	KEYSH , mus_kakkoii_key+0
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 86*mus_kakkoii_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		        c_v+0
	.byte		N18   , Cn1 , v120
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v032
	.byte	W48
	.byte		        Cn1 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As0 
	.byte	W12
	.byte		N30   , An0 
	.byte	W12
	.byte		BEND  , c_v+16
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N03   , As0 
	.byte	W03
	.byte		N06   , As0 , v032
	.byte	W09
	.byte		        An0 , v120
	.byte	W06
	.byte		N24   , Gs0 
	.byte	W24
	.byte		N06   , As0 
	.byte	W06
	.byte		        Gs0 
	.byte	W06
	.byte		BEND  , c_v+17
	.byte		N12   , As0 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
mus_kakkoii_3_B1:
mus_kakkoii_3_000:
	.byte		BEND  , c_v+0
	.byte		N06   , Cn1 , v120
	.byte	W06
	.byte		        Cn1 , v032
	.byte	W06
	.byte		N12   , Bn1 , v120
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W03
	.byte		N06   , Cn2 , v032
	.byte	W09
	.byte		        Cn1 , v120
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W03
	.byte		N06   , Cn2 , v032
	.byte	W09
	.byte		        As0 , v120
	.byte	W06
	.byte		        As0 , v032
	.byte	W06
	.byte		N12   , An1 , v120
	.byte	W06
	.byte		BEND  , c_v+5
	.byte	W06
	.byte	PEND
mus_kakkoii_3_001:
	.byte		BEND  , c_v+0
	.byte		N06   , An0 , v120
	.byte	W06
	.byte		        An0 , v032
	.byte	W12
	.byte		N03   , An0 , v120
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An0 , v032
	.byte	W06
	.byte		N12   , Gn1 , v120
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v+0
	.byte		N06   , An0 
	.byte	W06
	.byte		        An0 , v032
	.byte	W06
	.byte		        An1 , v120
	.byte	W06
	.byte		        An1 , v032
	.byte	W06
	.byte		N03   , Gs0 , v120
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , As0 
	.byte	W06
	.byte		N06   , Bn0 
	.byte	W06
	.byte	PEND
	.byte		BEND  , c_v+0
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Cn1 , v032
	.byte	W06
	.byte		N12   , Bn1 , v120
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W03
	.byte		N06   , Cn2 , v032
	.byte	W09
	.byte		        Cn1 , v120
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v032
	.byte	W06
	.byte		        Cn2 , v120
	.byte	W06
	.byte		        Cn2 , v032
	.byte	W06
	.byte		        As0 , v120
	.byte	W06
	.byte		        As0 , v032
	.byte	W06
	.byte		        As1 , v120
	.byte	W06
	.byte		        As1 , v032
	.byte	W06
mus_kakkoii_3_002:
	.byte		N06   , Fn0 , v120
	.byte	W06
	.byte		        Fn0 , v032
	.byte	W12
	.byte		N03   , Fn0 , v120
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn0 , v032
	.byte	W06
	.byte		N12   , Ds1 , v120
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v+0
	.byte		N04   , Gs0 
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N06   , Gs1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        As0 
	.byte	W06
	.byte		        As0 , v032
	.byte	W06
	.byte		N12   , An1 , v120
	.byte	W06
	.byte		BEND  , c_v+6
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_kakkoii_3_000
	.byte	PATT
	 .word	mus_kakkoii_3_001
	.byte		BEND  , c_v+0
	.byte		N06   , Cn1 , v120
	.byte	W06
	.byte		        Cn1 , v032
	.byte	W06
	.byte		N12   , Bn1 , v120
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W03
	.byte		N06   , Cn2 , v032
	.byte	W09
	.byte		        Cn1 , v120
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Cn2 
	.byte	W06
	.byte		        Cn2 , v032
	.byte	W06
	.byte		        As0 , v120
	.byte	W06
	.byte		        As0 , v032
	.byte	W06
	.byte		        As1 , v120
	.byte	W06
	.byte		        As1 , v032
	.byte	W06
	.byte	PATT
	 .word	mus_kakkoii_3_002
	.byte		BEND  , c_v+0
	.byte		N06   , Dn1 , v120
	.byte	W06
	.byte		        Dn1 , v032
	.byte	W06
	.byte		N12   , Cs2 , v120
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W03
	.byte		N06   , Dn2 , v032
	.byte	W09
	.byte		        Dn1 , v120
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 , v032
	.byte	W06
	.byte		N03   , Dn2 , v120
	.byte	W03
	.byte		N06   , Dn2 , v032
	.byte	W09
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Cn1 , v032
	.byte	W06
	.byte		N12   , Bn1 , v120
	.byte	W06
	.byte		BEND  , c_v+5
	.byte	W06
mus_kakkoii_3_003:
	.byte		BEND  , c_v+0
	.byte		N06   , Bn0 , v120
	.byte	W06
	.byte		        Bn0 , v032
	.byte	W12
	.byte		N03   , Bn0 , v120
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 , v032
	.byte	W06
	.byte		N12   , An1 , v120
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v+0
	.byte		N06   , Bn0 
	.byte	W06
	.byte		        Bn0 , v032
	.byte	W06
	.byte		        Bn1 , v120
	.byte	W06
	.byte		        Bn1 , v032
	.byte	W06
	.byte		N03   , As0 , v120
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Cn1 
	.byte	W06
	.byte		N06   , Cs1 
	.byte	W06
	.byte	PEND
mus_kakkoii_3_004:
	.byte		BEND  , c_v+0
	.byte		N06   , Dn1 , v120
	.byte	W06
	.byte		        Dn1 , v032
	.byte	W06
	.byte		N12   , Cs2 , v120
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W03
	.byte		N06   , Dn2 , v032
	.byte	W09
	.byte		        Dn1 , v120
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 , v032
	.byte	W06
	.byte		        Dn2 , v120
	.byte	W06
	.byte		        Dn2 , v032
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Cn1 , v032
	.byte	W06
	.byte		        Cn2 , v120
	.byte	W06
	.byte		        Cn2 , v032
	.byte	W06
	.byte	PEND
mus_kakkoii_3_005:
	.byte		N06   , Gn0 , v120
	.byte	W06
	.byte		        Gn0 , v032
	.byte	W12
	.byte		N03   , Gn0 , v120
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gn0 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v+0
	.byte		N04   , As0 
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N06   , As1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v032
	.byte	W06
	.byte		N12   , Bn1 , v120
	.byte	W06
	.byte		BEND  , c_v+6
	.byte	W06
	.byte	PEND
	.byte		        c_v+0
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Dn1 , v032
	.byte	W06
	.byte		N12   , Cs2 , v120
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W03
	.byte		N06   , Dn2 , v032
	.byte	W09
	.byte		        Dn1 , v120
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N03   , Dn2 
	.byte	W03
	.byte		N06   , Dn2 , v032
	.byte	W09
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Cn1 , v032
	.byte	W06
	.byte		N12   , Bn1 , v120
	.byte	W06
	.byte		BEND  , c_v+5
	.byte	W06
	.byte	PATT
	 .word	mus_kakkoii_3_003
	.byte	PATT
	 .word	mus_kakkoii_3_004
	.byte	PATT
	 .word	mus_kakkoii_3_005
	.byte	GOTO
	 .word	mus_kakkoii_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_kakkoii_4:
	.byte	KEYSH , mus_kakkoii_key+0
	.byte		VOICE , 56
	.byte		PAN   , c_v+12
	.byte		VOL   , 86*mus_kakkoii_mvl/mxv
	.byte		N03   , Dn4 , v120
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Bn3 , v048
	.byte	W03
	.byte		        An3 
	.byte	W44
	.byte	W01
	.byte		        Ds4 , v112
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W18
	.byte		        Fn4 
	.byte	W06
	.byte		N03   , An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Gs4 
	.byte	W03
	.byte		N21   , Gn4 
	.byte	W21
	.byte		N24   , Fn4 
	.byte	W24
mus_kakkoii_4_B1:
	.byte		VOICE , 56
	.byte		VOL   , 86*mus_kakkoii_mvl/mxv
	.byte	W12
	.byte		N06   , Ds4 , v112
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W18
	.byte		VOICE , 17
	.byte		VOL   , 55*mus_kakkoii_mvl/mxv
	.byte		N03   , Cn5 , v032
	.byte	W06
	.byte		        Cn5 , v040
	.byte	W06
	.byte		        Cn5 , v052
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Cn5 , v068
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W06
	.byte		        Cn5 , v088
	.byte	W06
	.byte		        Cn5 , v100
	.byte	W06
	.byte		        Cn5 , v112
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Cn5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn4 
	.byte	W12
	.byte		VOICE , 56
	.byte		VOL   , 86*mus_kakkoii_mvl/mxv
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , Cn4 
	.byte	W06
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N06   , As4 
	.byte	W06
	.byte		N03   , Cn5 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , As4 
	.byte	W12
	.byte		        An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		VOICE , 17
	.byte		VOL   , 55*mus_kakkoii_mvl/mxv
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N03   , As4 
	.byte	W06
	.byte		N06   , Cn5 
	.byte	W06
	.byte		N03   , Dn5 
	.byte	W06
	.byte		N06   , Ds5 
	.byte	W06
	.byte		N03   , Cn5 
	.byte	W06
	.byte		N06   , Fn5 
	.byte	W06
	.byte		N03   , Gn5 
	.byte	W06
	.byte		N06   , Fn5 
	.byte	W06
	.byte		N03   , Cn5 
	.byte	W06
	.byte		N04   , Dn5 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		VOICE , 56
	.byte		VOL   , 86*mus_kakkoii_mvl/mxv
	.byte		N06   , Dn5 
	.byte	W06
	.byte		N03   , Ds5 
	.byte	W06
	.byte		VOICE , 56
	.byte		VOL   , 86*mus_kakkoii_mvl/mxv
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , Cn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		        Gn4 
	.byte	W06
	.byte		N03   , An4 
	.byte	W06
	.byte		VOICE , 17
	.byte		VOL   , 55*mus_kakkoii_mvl/mxv
	.byte		N06   , As4 
	.byte	W06
	.byte		N03   , An4 
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N06   , An4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Cn4 
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   , An3 
	.byte	W06
	.byte		N04   , Fn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		VOICE , 56
	.byte		VOL   , 86*mus_kakkoii_mvl/mxv
	.byte	W12
	.byte		N06   , Ds5 
	.byte	W06
	.byte		N03   , Dn5 , v084
	.byte	W03
	.byte		        Cn5 , v068
	.byte	W03
	.byte		N06   , As4 , v112
	.byte	W06
	.byte		N03   , An4 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Cn4 
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , Cn4 
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N03   , Cn4 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Cn4 
	.byte	W06
	.byte		VOICE , 17
	.byte		VOL   , 55*mus_kakkoii_mvl/mxv
	.byte		N03   , Fn3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		N06   , Fn5 
	.byte	W12
	.byte		        Ds5 
	.byte	W06
	.byte		        Fn5 
	.byte	W12
	.byte		        Ds5 
	.byte	W06
	.byte		        Fn5 
	.byte	W12
	.byte		        Gn5 
	.byte	W06
	.byte		N03   , Fn5 , v080
	.byte	W03
	.byte		VOICE , 56
	.byte		N03   , Ds5 , v068
	.byte	W03
	.byte		N06   , Dn4 , v112
	.byte	W03
	.byte		VOL   , 86*mus_kakkoii_mvl/mxv
	.byte	W03
	.byte		N06   , En4 
	.byte	W06
	.byte		VOICE , 56
	.byte		VOL   , 86*mus_kakkoii_mvl/mxv
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , En4 
	.byte	W18
	.byte		VOICE , 17
	.byte		VOL   , 55*mus_kakkoii_mvl/mxv
	.byte		N03   , Dn5 , v032
	.byte	W06
	.byte		        Dn5 , v040
	.byte	W06
	.byte		        Dn5 , v052
	.byte	W06
	.byte		        Dn5 , v060
	.byte	W06
	.byte		        Dn5 , v068
	.byte	W06
	.byte		        Dn5 , v080
	.byte	W06
	.byte		        Dn5 , v088
	.byte	W06
	.byte		        Dn5 , v100
	.byte	W06
	.byte		        Dn5 , v112
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		        En5 
	.byte	W03
	.byte		        Dn5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		VOICE , 56
	.byte		VOL   , 86*mus_kakkoii_mvl/mxv
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , An4 
	.byte	W06
	.byte		N06   , Cn5 
	.byte	W06
	.byte		N03   , Dn5 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn5 
	.byte	W12
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		VOICE , 17
	.byte		VOL   , 55*mus_kakkoii_mvl/mxv
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , An4 
	.byte	W06
	.byte		N06   , As4 
	.byte	W06
	.byte		N03   , Cn5 
	.byte	W06
	.byte		N06   , Dn5 
	.byte	W06
	.byte		N03   , En5 
	.byte	W06
	.byte		N06   , Fn5 
	.byte	W06
	.byte		N03   , Dn5 
	.byte	W06
	.byte		N06   , Gn5 
	.byte	W06
	.byte		N03   , An5 
	.byte	W06
	.byte		N06   , Gn5 
	.byte	W06
	.byte		N03   , Dn5 
	.byte	W06
	.byte		N04   , En5 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		VOICE , 56
	.byte		VOL   , 86*mus_kakkoii_mvl/mxv
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N06   , An4 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Dn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn5 
	.byte	W12
	.byte		        An4 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W06
	.byte		VOICE , 17
	.byte		VOL   , 55*mus_kakkoii_mvl/mxv
	.byte		N06   , Cn5 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W06
	.byte		N06   , An4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N06   , Bn4 
	.byte	W06
	.byte		N03   , An4 
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N06   , An4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N04   , Gn3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		VOICE , 56
	.byte		VOL   , 86*mus_kakkoii_mvl/mxv
	.byte	W12
	.byte		N06   , Fn5 
	.byte	W06
	.byte		N03   , En5 , v084
	.byte	W03
	.byte		        Dn5 , v068
	.byte	W03
	.byte		N06   , Cn5 , v112
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N06   , An4 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		VOICE , 17
	.byte		VOL   , 55*mus_kakkoii_mvl/mxv
	.byte		N03   , Gn3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		N06   , Gn5 
	.byte	W12
	.byte		        Fn5 
	.byte	W06
	.byte		        Gn5 
	.byte	W12
	.byte		        Fn5 
	.byte	W06
	.byte		        Gn5 
	.byte	W12
	.byte		        An5 
	.byte	W06
	.byte		N03   , Gn5 , v080
	.byte	W03
	.byte		        Fn5 , v068
	.byte	W03
	.byte		        En5 , v060
	.byte	W03
	.byte		        Dn5 , v048
	.byte	W09
	.byte	GOTO
	 .word	mus_kakkoii_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_kakkoii_5:
	.byte	KEYSH , mus_kakkoii_key+0
	.byte		VOICE , 56
	.byte		PAN   , c_v-30
	.byte		VOL   , 75*mus_kakkoii_mvl/mxv
	.byte		N03   , Gn3 , v112
	.byte	W12
	.byte		VOICE , 82
	.byte		PAN   , c_v+0
	.byte		VOL   , 60*mus_kakkoii_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		N03   , Fn3 , v064
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Dn3 , v048
	.byte	W03
	.byte		        Cn3 
	.byte	W44
	.byte	W01
	.byte		        Gn3 , v112
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W18
	.byte		        An3 
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        An3 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N21   , Gs3 
	.byte	W21
	.byte		N24   , As3 
	.byte	W24
mus_kakkoii_5_B1:
	.byte		VOICE , 56
	.byte		VOL   , 86*mus_kakkoii_mvl/mxv
	.byte	W12
	.byte		N06   , Gn3 , v112
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W18
	.byte		VOICE , 17
	.byte		VOL   , 55*mus_kakkoii_mvl/mxv
	.byte		N03   , Fn4 , v032
	.byte	W06
	.byte		        Fn4 , v040
	.byte	W06
	.byte		        Fn4 , v052
	.byte	W06
	.byte		        Fn4 , v060
	.byte	W06
	.byte		        Fn4 , v068
	.byte	W06
	.byte		        Fn4 , v080
	.byte	W06
	.byte		        Fn4 , v088
	.byte	W06
	.byte		        Fn4 , v100
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Fn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Gn4 
	.byte	W12
	.byte		VOICE , 56
	.byte		VOL   , 86*mus_kakkoii_mvl/mxv
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		VOICE , 17
	.byte		VOL   , 55*mus_kakkoii_mvl/mxv
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W06
	.byte		N06   , As4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N06   , Cn5 
	.byte	W06
	.byte		N03   , Dn5 
	.byte	W06
	.byte		N06   , Cn5 
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W06
	.byte		N02   , As4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		VOICE , 56
	.byte		VOL   , 86*mus_kakkoii_mvl/mxv
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W06
	.byte		VOICE , 56
	.byte		VOL   , 86*mus_kakkoii_mvl/mxv
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Ds4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		VOICE , 17
	.byte		VOL   , 55*mus_kakkoii_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		N03   , Cn4 
	.byte	W06
	.byte		N06   , An3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   , An3 
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N06   , An3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W06
	.byte		N04   
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		VOICE , 56
	.byte		VOL   , 86*mus_kakkoii_mvl/mxv
	.byte	W12
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , Fs4 , v080
	.byte	W03
	.byte		        Fn4 , v076
	.byte	W15
	.byte		N06   , Cn4 , v112
	.byte	W06
	.byte		N03   , An3 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , An3 
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		VOICE , 17
	.byte		VOL   , 55*mus_kakkoii_mvl/mxv
	.byte		N03   , Cn3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		N48   , Cn5 , v096
	.byte	W48
	.byte		N06   , Ds5 , v112
	.byte	W06
	.byte		N03   , Dn5 , v080
	.byte	W03
	.byte		        Cn5 , v068
	.byte	W03
	.byte		VOICE , 56
	.byte		N06   , An3 , v112
	.byte	W03
	.byte		VOL   , 86*mus_kakkoii_mvl/mxv
	.byte	W03
	.byte		N06   , Cs4 
	.byte	W06
	.byte		VOICE , 56
	.byte		VOL   , 86*mus_kakkoii_mvl/mxv
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W06
	.byte		N03   , An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , As3 
	.byte	W12
	.byte		N06   , An3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W18
	.byte		VOICE , 17
	.byte		VOL   , 55*mus_kakkoii_mvl/mxv
	.byte		N03   , Gn4 , v032
	.byte	W06
	.byte		        Gn4 , v040
	.byte	W06
	.byte		        Gn4 , v052
	.byte	W06
	.byte		        Gn4 , v060
	.byte	W06
	.byte		        Gn4 , v068
	.byte	W06
	.byte		        Gn4 , v080
	.byte	W06
	.byte		        Gn4 , v088
	.byte	W06
	.byte		        Gn4 , v100
	.byte	W06
	.byte		        Gn4 , v112
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Gn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , An4 
	.byte	W12
	.byte		VOICE , 56
	.byte		VOL   , 86*mus_kakkoii_mvl/mxv
	.byte	W12
	.byte		N06   , An3 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   , An3 
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Cn4 
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , An4 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		VOICE , 17
	.byte		VOL   , 55*mus_kakkoii_mvl/mxv
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N03   , En4 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N06   , An4 
	.byte	W06
	.byte		N03   , As4 
	.byte	W06
	.byte		N06   , Cn5 
	.byte	W06
	.byte		N03   , An4 
	.byte	W06
	.byte		N06   , Dn5 
	.byte	W06
	.byte		N03   , En5 
	.byte	W06
	.byte		N06   , Dn5 
	.byte	W06
	.byte		N03   , As4 
	.byte	W06
	.byte		N02   , Cn5 
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
	.byte		VOICE , 56
	.byte		VOL   , 86*mus_kakkoii_mvl/mxv
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W06
	.byte		N03   , An3 
	.byte	W06
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Dn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W06
	.byte		VOICE , 17
	.byte		VOL   , 55*mus_kakkoii_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N03   , An3 
	.byte	W06
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N06   , An3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N03   , An3 
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W06
	.byte		N04   
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		VOICE , 56
	.byte		VOL   , 86*mus_kakkoii_mvl/mxv
	.byte	W12
	.byte		N06   , An4 
	.byte	W06
	.byte		N03   , Gs4 , v080
	.byte	W03
	.byte		        Gn4 , v076
	.byte	W15
	.byte		N06   , Dn4 , v112
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , An3 
	.byte	W06
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N03   , An3 
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   , An3 
	.byte	W06
	.byte		VOICE , 17
	.byte		VOL   , 55*mus_kakkoii_mvl/mxv
	.byte		N03   , Dn3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		N48   , Dn5 , v096
	.byte	W48
	.byte		N06   , Fn5 , v112
	.byte	W06
	.byte		N03   , En5 , v080
	.byte	W03
	.byte		        Dn5 , v068
	.byte	W03
	.byte		        Cn5 , v060
	.byte	W03
	.byte		        Bn4 , v048
	.byte	W09
	.byte	GOTO
	 .word	mus_kakkoii_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_kakkoii_6:
	.byte	KEYSH , mus_kakkoii_key+0
	.byte		VOICE , 17
	.byte		PAN   , c_v+0
	.byte		VOL   , 39*mus_kakkoii_mvl/mxv
	.byte		N03   , Cn5 , v076
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Gn5 
	.byte	W03
	.byte		N72   , Cn6 
	.byte	W72
	.byte	W03
	.byte		N03   , Cs6 
	.byte	W03
	.byte		        Cn6 
	.byte	W03
	.byte		        Bn5 
	.byte	W03
	.byte		N06   , As5 
	.byte	W06
	.byte		N03   , Cn6 
	.byte	W03
	.byte		        As5 
	.byte	W03
	.byte		N42   , An5 
	.byte	W42
	.byte		N03   , As5 
	.byte	W03
	.byte		        An5 
	.byte	W03
	.byte		N21   , Gs5 
	.byte	W21
	.byte		N03   , An5 
	.byte	W03
	.byte		N24   , As5 
	.byte	W24
mus_kakkoii_6_B1:
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
	.byte	GOTO
	 .word	mus_kakkoii_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_kakkoii_7:
	.byte	KEYSH , mus_kakkoii_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		PAN   , c_v-64
	.byte		VOL   , 39*mus_kakkoii_mvl/mxv
	.byte	W12
	.byte	W96
	.byte	W96
mus_kakkoii_7_B1:
mus_kakkoii_7_000:
	.byte		N03   , Cn2 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn2 
	.byte	W06
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N06   , Fn2 
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		        Cn3 
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W06
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W18
	.byte	PEND
mus_kakkoii_7_001:
	.byte		N03   , An1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , An2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W06
	.byte		N06   , An2 
	.byte	W06
	.byte		        Cn3 
	.byte	W18
	.byte	PEND
	.byte	PATT
	 .word	mus_kakkoii_7_000
mus_kakkoii_7_002:
	.byte		N03   , An1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , An2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W12
	.byte		N18   , As2 
	.byte	W18
	.byte		N12   , Dn3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_kakkoii_7_000
	.byte	PATT
	 .word	mus_kakkoii_7_001
	.byte	PATT
	 .word	mus_kakkoii_7_000
	.byte	PATT
	 .word	mus_kakkoii_7_002
mus_kakkoii_7_003:
	.byte		N03   , Dn2 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , An2 
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W06
	.byte		N06   , Gn2 
	.byte	W06
	.byte		N03   , An2 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		        Dn3 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N06   , Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W18
	.byte	PEND
mus_kakkoii_7_004:
	.byte		N03   , Bn1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W06
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W18
	.byte	PEND
	.byte	PATT
	 .word	mus_kakkoii_7_003
mus_kakkoii_7_005:
	.byte		N03   , Bn1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W12
	.byte		N18   , Cn3 
	.byte	W18
	.byte		N12   , En3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_kakkoii_7_003
	.byte	PATT
	 .word	mus_kakkoii_7_004
	.byte	PATT
	 .word	mus_kakkoii_7_003
	.byte	PATT
	 .word	mus_kakkoii_7_005
	.byte	GOTO
	 .word	mus_kakkoii_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_kakkoii_8:
	.byte	KEYSH , mus_kakkoii_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		PAN   , c_v+63
	.byte		VOL   , 41*mus_kakkoii_mvl/mxv
	.byte	W12
	.byte	W96
	.byte	W96
mus_kakkoii_8_B1:
mus_kakkoii_8_000:
	.byte		N03   , Gn2 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W18
	.byte	PEND
mus_kakkoii_8_001:
	.byte		N03   , Fn2 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W06
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Fn3 
	.byte	W18
	.byte	PEND
	.byte	PATT
	 .word	mus_kakkoii_8_000
mus_kakkoii_8_002:
	.byte		N03   , Fn2 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W12
	.byte		N18   , Gn3 
	.byte	W18
	.byte		N12   , As3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_kakkoii_8_000
	.byte	PATT
	 .word	mus_kakkoii_8_001
	.byte	PATT
	 .word	mus_kakkoii_8_000
	.byte	PATT
	 .word	mus_kakkoii_8_002
mus_kakkoii_8_003:
	.byte		N03   , An2 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W06
	.byte		N06   , En3 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N03   , An2 
	.byte	W06
	.byte		N06   , En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W18
	.byte	PEND
mus_kakkoii_8_004:
	.byte		N03   , Gn2 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W18
	.byte	PEND
	.byte	PATT
	 .word	mus_kakkoii_8_003
mus_kakkoii_8_005:
	.byte		N03   , Gn2 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		N18   , An3 
	.byte	W18
	.byte		N12   , Cn4 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_kakkoii_8_003
	.byte	PATT
	 .word	mus_kakkoii_8_004
	.byte	PATT
	 .word	mus_kakkoii_8_003
	.byte	PATT
	 .word	mus_kakkoii_8_005
	.byte	GOTO
	 .word	mus_kakkoii_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_kakkoii_9:
	.byte	KEYSH , mus_kakkoii_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v-1
	.byte		VOL   , 86*mus_kakkoii_mvl/mxv
	.byte		N03   , Fs2 , v112
	.byte	W06
	.byte		        Fs2 , v064
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		N06   
	.byte	W54
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N03   , En1 
	.byte	W03
	.byte		        En1 , v088
	.byte	W09
	.byte		N06   , Dn1 , v112
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
mus_kakkoii_9_B1:
mus_kakkoii_9_000:
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte	PEND
mus_kakkoii_9_001:
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte	PEND
mus_kakkoii_9_002:
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W24
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte	PEND
	.byte		        Cn1 
	.byte	W18
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W24
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N06   , Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte	PATT
	 .word	mus_kakkoii_9_000
	.byte	PATT
	 .word	mus_kakkoii_9_001
mus_kakkoii_9_003:
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W24
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte	PEND
mus_kakkoii_9_004:
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W24
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N06   , Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_kakkoii_9_000
	.byte	PATT
	 .word	mus_kakkoii_9_001
	.byte	PATT
	 .word	mus_kakkoii_9_002
	.byte	PATT
	 .word	mus_kakkoii_9_004
	.byte	PATT
	 .word	mus_kakkoii_9_000
	.byte	PATT
	 .word	mus_kakkoii_9_001
	.byte	PATT
	 .word	mus_kakkoii_9_003
	.byte	PATT
	 .word	mus_kakkoii_9_004
	.byte	GOTO
	 .word	mus_kakkoii_9_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_kakkoii:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_kakkoii_pri	@ Priority
	.byte	mus_kakkoii_rev	@ Reverb.

	.word	mus_kakkoii_grp

	.word	mus_kakkoii_1
	.word	mus_kakkoii_2
	.word	mus_kakkoii_3
	.word	mus_kakkoii_4
	.word	mus_kakkoii_5
	.word	mus_kakkoii_6
	.word	mus_kakkoii_7
	.word	mus_kakkoii_8
	.word	mus_kakkoii_9

	.end
