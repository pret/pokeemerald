	.include "MPlayDef.s"

	.equ	mus_hutago_grp, voicegroup095
	.equ	mus_hutago_pri, 0
	.equ	mus_hutago_rev, reverb_set+50
	.equ	mus_hutago_mvl, 127
	.equ	mus_hutago_key, 0
	.equ	mus_hutago_tbs, 1
	.equ	mus_hutago_exg, 0
	.equ	mus_hutago_cmp, 1

	.section .rodata
	.global	mus_hutago
	.align	2

@********************** Track  1 **********************@

mus_hutago_1:
	.byte	KEYSH , mus_hutago_key+0
	.byte	TEMPO , 134*mus_hutago_tbs/2
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 39*mus_hutago_mvl/mxv
	.byte		N03   , En5 , v112
	.byte	W12
	.byte		        En5 , v060
	.byte	W12
	.byte		        En5 , v112
	.byte	W12
	.byte		        En5 , v060
	.byte	W12
	.byte		        En5 , v112
	.byte	W12
	.byte		        En5 , v064
	.byte	W12
	.byte		        En5 , v112
	.byte	W12
	.byte		        En5 , v064
	.byte	W12
	.byte		        En5 , v112
	.byte	W03
	.byte		        En5 , v072
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        En5 , v112
	.byte	W48
	.byte		N03   
	.byte	W12
	.byte		        En5 , v068
	.byte	W12
	.byte		        En5 , v112
	.byte	W12
mus_hutago_1_B1:
	.byte		N03   , En5 , v112
	.byte	W12
	.byte		        En5 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        En5 , v088
	.byte	W12
	.byte		        En5 , v072
	.byte	W12
	.byte		        En5 , v096
	.byte	W12
	.byte		        En5 , v064
	.byte	W12
	.byte		        En5 , v096
	.byte	W12
	.byte		        En5 , v064
	.byte	W12
	.byte		        En5 , v112
	.byte	W12
	.byte		        En5 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        En5 , v088
	.byte	W24
	.byte		        En5 , v112
	.byte	W12
	.byte		        En5 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        En5 , v088
	.byte	W24
	.byte		        En5 , v112
	.byte	W12
	.byte		        En5 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        En5 , v088
	.byte	W12
	.byte		        En5 , v072
	.byte	W12
	.byte		        En5 , v096
	.byte	W12
	.byte		        En5 , v064
	.byte	W12
	.byte		        En5 , v096
	.byte	W24
	.byte		        En5 , v112
	.byte	W12
	.byte		        En5 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        En5 , v088
	.byte	W24
	.byte		        En5 , v112
	.byte	W03
	.byte		        En5 , v088
	.byte	W03
	.byte		        En5 , v084
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		        En5 , v112
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte	GOTO
	 .word	mus_hutago_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_hutago_2:
	.byte	KEYSH , mus_hutago_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 39*mus_hutago_mvl/mxv
	.byte	W96
	.byte	W24
	.byte		N06   , Gn5 , v096
	.byte	W72
mus_hutago_2_B1:
	.byte	W96
	.byte	W36
	.byte		N06   , Gn5 , v080
	.byte	W48
	.byte		        Gn5 , v096
	.byte	W12
	.byte	W84
	.byte		        Gn5 , v084
	.byte	W12
	.byte	W36
	.byte		N06   
	.byte	W60
	.byte	GOTO
	 .word	mus_hutago_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_hutago_3:
	.byte	KEYSH , mus_hutago_key+0
	.byte		VOICE , 38
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 75*mus_hutago_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W03
	.byte		        c_v+0
	.byte	W92
	.byte	W01
	.byte		N54   , Dn1 , v112
	.byte	W06
	.byte		BEND  , c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W36
	.byte		N06   , Cn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
mus_hutago_3_B1:
	.byte		N24   , Gn1 , v112
	.byte	W06
	.byte		BEND  , c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N12   , An1 
	.byte	W12
	.byte		N06   , En1 
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W06
	.byte		BEND  , c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , An1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N36   , Dn1 
	.byte	W06
	.byte		BEND  , c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , Fs1 
	.byte	W12
	.byte		N24   , Bn1 
	.byte	W06
	.byte		BEND  , c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		N36   , Dn1 
	.byte	W06
	.byte		BEND  , c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , En1 
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W06
	.byte		BEND  , c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , An1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		N24   , Dn1 
	.byte	W06
	.byte		BEND  , c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte		N06   , Fs1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte	GOTO
	 .word	mus_hutago_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_hutago_4:
	.byte	KEYSH , mus_hutago_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		PAN   , c_v-35
	.byte		VOL   , 46*mus_hutago_mvl/mxv
	.byte		N06   , An3 , v112
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		N60   , An3 
	.byte	W60
	.byte		N06   , Bn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		N03   , An2 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
mus_hutago_4_B1:
	.byte		N06   , Dn3 , v112
	.byte	W12
	.byte		N03   , Dn3 , v068
	.byte	W12
	.byte		N06   , Dn3 , v112
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		N03   , An2 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		N06   , Fs3 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W12
	.byte		N06   , An2 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W03
	.byte		        Fs2 
	.byte	W03
	.byte		N24   , Cn3 
	.byte	W12
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		N06   , Bn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		N24   , Dn3 
	.byte	W12
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		N06   , Bn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        An2 
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		N06   , Fs3 
	.byte	W24
	.byte		N03   , An1 
	.byte	W03
	.byte		        Cn2 
	.byte	W03
	.byte		        Dn2 
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		N24   , Fs2 
	.byte	W06
	.byte		BEND  , c_v-8
	.byte	W06
	.byte		        c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte	GOTO
	 .word	mus_hutago_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_hutago_5:
	.byte	KEYSH , mus_hutago_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		VOL   , 55*mus_hutago_mvl/mxv
	.byte	W12
	.byte		N03   , Cs5 , v112
	.byte	W24
	.byte		N03   
	.byte	W60
	.byte	W96
mus_hutago_5_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W36
	.byte		N03   , Cs4 , v112
	.byte	W24
	.byte		        Cs5 , v080
	.byte	W36
	.byte	GOTO
	 .word	mus_hutago_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_hutago_6:
	.byte	KEYSH , mus_hutago_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 56*mus_hutago_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , Dn4 , v112
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N03   , Dn3 
	.byte		N06   , Gn4 
	.byte	W03
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		N60   , Dn4 
	.byte	W06
	.byte		BEND  , c_v+8
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+8
	.byte	W06
	.byte		        c_v+0
	.byte	W36
	.byte		N06   , Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
mus_hutago_6_B1:
	.byte		N24   , Bn3 , v112
	.byte	W12
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N36   , Cn4 
	.byte	W12
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W18
	.byte		N06   , An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		N03   , An2 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		N24   , Fs3 
	.byte	W12
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		N24   , Bn3 
	.byte	W12
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fs3 
	.byte	W06
	.byte		N03   , An3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		N06   , Dn4 
	.byte	W24
	.byte		N03   , Dn2 , v080
	.byte		N06   , Dn5 
	.byte	W03
	.byte		N03   , Fs2 , v112
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		N24   , Dn3 
	.byte	W06
	.byte		BEND  , c_v-8
	.byte	W06
	.byte		        c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte	GOTO
	 .word	mus_hutago_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_hutago_7:
	.byte	KEYSH , mus_hutago_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		VOL   , 40*mus_hutago_mvl/mxv
	.byte		PAN   , c_v-62
	.byte	W96
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N36   , Dn3 
	.byte	W72
mus_hutago_7_B1:
	.byte		PAN   , c_v+0
	.byte		N03   , Dn3 , v112
	.byte	W12
	.byte		        Gn3 
	.byte	W03
	.byte		        Fn3 , v064
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Dn3 , v112
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
mus_hutago_7_000:
	.byte		N03   , Cn3 , v112
	.byte	W12
	.byte		        Fn3 
	.byte	W03
	.byte		        En3 , v064
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Cn3 , v112
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte	PEND
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W03
	.byte		        Fn3 , v064
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Dn3 , v112
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte	PATT
	 .word	mus_hutago_7_000
	.byte	GOTO
	 .word	mus_hutago_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_hutago_8:
	.byte	KEYSH , mus_hutago_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		PAN   , c_v+63
	.byte		VOL   , 40*mus_hutago_mvl/mxv
	.byte	W96
	.byte		N03   , Fs4 , v112
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N36   , An3 
	.byte	W72
mus_hutago_8_B1:
mus_hutago_8_000:
	.byte		PAN   , c_v+63
	.byte		N03   , Gn3 , v112
	.byte	W12
	.byte		        Dn4 
	.byte	W03
	.byte		        Bn3 , v064
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		PAN   , c_v-64
	.byte		N03   , Gn3 , v112
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N03   , As3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N03   , As3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte	PEND
mus_hutago_8_001:
	.byte		PAN   , c_v+63
	.byte		N03   , An3 , v112
	.byte	W12
	.byte		        Cn4 
	.byte	W03
	.byte		        Bn3 , v064
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		PAN   , c_v-63
	.byte		N03   , Fn3 , v112
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N03   , Fs3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N03   , Dn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_hutago_8_000
	.byte	PATT
	 .word	mus_hutago_8_001
	.byte	GOTO
	 .word	mus_hutago_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_hutago_9:
	.byte	KEYSH , mus_hutago_key+0
	.byte		VOICE , 0
	.byte		VOL   , 58*mus_hutago_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , En3 , v112
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Dn3 , v080
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn3 , v088
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W72
mus_hutago_9_B1:
mus_hutago_9_000:
	.byte		N06   , En3 , v112
	.byte	W12
	.byte		        En3 , v072
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W36
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte		        En3 
	.byte	W12
	.byte		        En3 , v072
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W36
	.byte		N06   
	.byte	W36
	.byte	PATT
	 .word	mus_hutago_9_000
	.byte		N06   , En3 , v112
	.byte	W12
	.byte		        En3 , v072
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	GOTO
	 .word	mus_hutago_9_B1
	.byte	FINE

@********************** Track 10 **********************@

mus_hutago_10:
	.byte	KEYSH , mus_hutago_key+0
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		VOL   , 27*mus_hutago_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+2
	.byte		N06   , Dn4 , v112
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N03   , Dn3 
	.byte		N06   , Gn4 
	.byte	W03
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		N60   , Dn4 
	.byte	W60
	.byte		N06   , Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
mus_hutago_10_B1:
	.byte		N06   , Bn3 , v112
	.byte	W24
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N18   , Cn4 
	.byte	W12
	.byte	W24
	.byte		N06   , An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		N03   , An2 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		N06   , Fs3 
	.byte	W24
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		N06   , Bn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fs3 
	.byte	W06
	.byte		N03   , An3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		N06   , Dn4 
	.byte	W24
	.byte		N03   , Dn2 
	.byte		N06   , Dn5 
	.byte	W03
	.byte		N03   , Fs2 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		N06   , Dn3 
	.byte	W24
	.byte	GOTO
	 .word	mus_hutago_10_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_hutago:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_hutago_pri	@ Priority
	.byte	mus_hutago_rev	@ Reverb.

	.word	mus_hutago_grp

	.word	mus_hutago_1
	.word	mus_hutago_2
	.word	mus_hutago_3
	.word	mus_hutago_4
	.word	mus_hutago_5
	.word	mus_hutago_6
	.word	mus_hutago_7
	.word	mus_hutago_8
	.word	mus_hutago_9
	.word	mus_hutago_10

	.end
