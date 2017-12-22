	.include "MPlayDef.s"

	.equ	mus_event0_grp, voicegroup_8684848
	.equ	mus_event0_pri, 0
	.equ	mus_event0_rev, reverb_set+50
	.equ	mus_event0_mvl, 127
	.equ	mus_event0_key, 0
	.equ	mus_event0_tbs, 1
	.equ	mus_event0_exg, 0
	.equ	mus_event0_cmp, 1

	.section .rodata
	.global	mus_event0
	.align	2

@********************** Track  1 **********************@

mus_event0_1:
	.byte	KEYSH , mus_event0_key+0
	.byte	TEMPO , 136*mus_event0_tbs/2
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		VOL   , 49*mus_event0_mvl/mxv
	.byte		N03   , Dn5 , v112
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Bn4 
	.byte	W18
	.byte	TEMPO , 112*mus_event0_tbs/2
	.byte		N24   , As4 
	.byte	W15
	.byte	TEMPO , 156*mus_event0_tbs/2
	.byte	W09
mus_event0_1_B1:
mus_event0_1_000:
	.byte	W12
	.byte		N09   , Gn4 , v112
	.byte	W09
	.byte		N06   , Gn4 , v036
	.byte	W09
	.byte		N03   , Gn4 , v112
	.byte	W03
	.byte		N06   , Gn4 , v036
	.byte	W24
	.byte	W03
	.byte		N09   , Gs4 , v112
	.byte	W09
	.byte		N06   , Gs4 , v036
	.byte	W09
	.byte		N03   , Gs4 , v112
	.byte	W03
	.byte		N06   , Gs4 , v036
	.byte	W15
	.byte	PEND
	.byte	W12
	.byte		N09   , An4 , v112
	.byte	W09
	.byte		N06   , An4 , v036
	.byte	W09
	.byte		N03   , An4 , v112
	.byte	W03
	.byte		N06   , An4 , v036
	.byte	W24
	.byte	W03
	.byte		N09   , Gs4 , v112
	.byte	W09
	.byte		N06   , Gs4 , v036
	.byte	W09
	.byte		N03   , Gs4 , v112
	.byte	W03
	.byte		N06   , Gs4 , v036
	.byte	W15
	.byte	PATT
	 .word	mus_event0_1_000
	.byte	W12
	.byte		N09   , An4 , v112
	.byte	W09
	.byte		N06   , An4 , v036
	.byte	W09
	.byte		N03   , An4 , v112
	.byte	W03
	.byte		N06   , An4 , v036
	.byte	W24
	.byte	W03
	.byte		N03   , As4 , v124
	.byte	W06
	.byte		        As4 , v112
	.byte	W06
	.byte		        As4 , v104
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        As4 , v116
	.byte	W06
	.byte	GOTO
	 .word	mus_event0_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_event0_2:
	.byte	KEYSH , mus_event0_key+0
	.byte		VOICE , 38
	.byte		PAN   , c_v+7
	.byte		VOL   , 78*mus_event0_mvl/mxv
	.byte	W06
	.byte	W66
	.byte		N06   , Gn2 , v112
	.byte	W06
	.byte		N24   , Gn1 
	.byte	W24
mus_event0_2_B1:
mus_event0_2_000:
	.byte		N12   , Cn1 , v112
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W12
	.byte	PATT
	 .word	mus_event0_2_000
	.byte		N12   , Cn1 , v112
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N03   , Gn2 , v124
	.byte	W12
	.byte		        Gn1 , v104
	.byte	W06
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Fn2 , v104
	.byte	W06
	.byte		        Gn2 , v112
	.byte	W06
	.byte	GOTO
	 .word	mus_event0_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_event0_3:
	.byte	KEYSH , mus_event0_key+0
	.byte		VOICE , 73
	.byte		PAN   , c_v-46
	.byte		VOL   , 39*mus_event0_mvl/mxv
	.byte	W06
	.byte		N06   , Bn4 , v112
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W18
	.byte		N24   , Fn4 
	.byte	W24
mus_event0_3_B1:
mus_event0_3_000:
	.byte	W12
	.byte		N09   , Cn4 , v112
	.byte	W18
	.byte		N03   
	.byte	W30
	.byte		N09   , Cs4 
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte	PEND
	.byte	W12
	.byte		N09   , Dn4 
	.byte	W18
	.byte		N03   
	.byte	W30
	.byte		N09   , Cs4 
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte	PATT
	 .word	mus_event0_3_000
	.byte	W12
	.byte		N09   , Dn4 , v112
	.byte	W18
	.byte		N03   
	.byte	W30
	.byte		        Fn4 , v124
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v104
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Fn4 , v116
	.byte	W06
	.byte	GOTO
	 .word	mus_event0_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_event0_4:
	.byte	KEYSH , mus_event0_key+0
	.byte		VOICE , 87
	.byte		PAN   , c_v+0
	.byte		VOL   , 48*mus_event0_mvl/mxv
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 12
	.byte		        xIECV , 22
	.byte		BENDR , 12
	.byte		BEND  , c_v+2
	.byte	W06
	.byte	W66
	.byte		N06   , Gn2 , v112
	.byte	W06
	.byte		N24   , Gn1 
	.byte	W24
mus_event0_4_B1:
mus_event0_4_000:
	.byte		N12   , Cn1 , v112
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W12
	.byte	PATT
	 .word	mus_event0_4_000
	.byte		N12   , Cn1 , v112
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N03   , Gn2 , v124
	.byte	W12
	.byte		        Gn1 , v104
	.byte	W06
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Fn2 , v104
	.byte	W06
	.byte		        Gn2 , v112
	.byte	W06
	.byte	GOTO
	 .word	mus_event0_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_event0_5:
	.byte	KEYSH , mus_event0_key+0
	.byte		VOICE , 82
	.byte		PAN   , c_v+63
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 12
	.byte		        xIECV , 22
	.byte		BENDR , 12
	.byte		VOL   , 50*mus_event0_mvl/mxv
	.byte	W06
	.byte	W66
	.byte		N06   , Bn2 , v084
	.byte	W06
	.byte		N24   , Gn3 , v088
	.byte	W24
mus_event0_5_B1:
mus_event0_5_000:
	.byte		PAN   , c_v-62
	.byte		N03   , Gn3 , v096
	.byte	W06
	.byte		        Ds3 , v048
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Gn3 , v096
	.byte	W06
	.byte		        Ds3 , v048
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		PAN   , c_v-62
	.byte		N03   , Gs3 , v096
	.byte	W06
	.byte		        En3 , v048
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Gs3 , v096
	.byte	W06
	.byte		        En3 , v048
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte	PEND
	.byte		PAN   , c_v-62
	.byte		N03   , An3 , v096
	.byte	W06
	.byte		        Fn3 , v048
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , An3 , v096
	.byte	W06
	.byte		        Fn3 , v048
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		PAN   , c_v-62
	.byte		N03   , Gs3 , v096
	.byte	W06
	.byte		        En3 , v048
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Gs3 , v096
	.byte	W06
	.byte		        En3 , v048
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte	PATT
	 .word	mus_event0_5_000
	.byte		PAN   , c_v-62
	.byte		N03   , An3 , v096
	.byte	W06
	.byte		        Fn3 , v048
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , An3 , v096
	.byte	W06
	.byte		        Fn3 , v048
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N04   , As3 , v100
	.byte	W08
	.byte		        Fn3 , v084
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		N03   , Gn2 , v112
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte	GOTO
	 .word	mus_event0_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_event0_6:
	.byte	KEYSH , mus_event0_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 12
	.byte		        xIECV , 22
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 40*mus_event0_mvl/mxv
	.byte	W06
	.byte	W66
	.byte		N06   , Gn3 , v112
	.byte	W06
	.byte		N24   , Bn3 
	.byte	W24
mus_event0_6_B1:
mus_event0_6_000:
	.byte		N12   , Ds3 , v112
	.byte	W18
	.byte		N06   
	.byte	W30
	.byte		N12   , En3 
	.byte	W18
	.byte		N06   
	.byte	W30
	.byte	PEND
	.byte		N12   , Fn3 
	.byte	W18
	.byte		N06   
	.byte	W30
	.byte		N12   , En3 
	.byte	W18
	.byte		N06   
	.byte	W30
	.byte	PATT
	 .word	mus_event0_6_000
	.byte		N12   , Fn3 , v112
	.byte	W18
	.byte		N06   
	.byte	W42
	.byte		N03   , Bn3 , v124
	.byte	W06
	.byte		        Bn3 , v112
	.byte	W06
	.byte		        Bn3 , v104
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Bn3 , v116
	.byte	W06
	.byte	GOTO
	 .word	mus_event0_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_event0_7:
	.byte	KEYSH , mus_event0_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 62*mus_event0_mvl/mxv
	.byte	W06
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		        En1 , v080
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v092
	.byte	W12
	.byte		        En1 , v080
	.byte	W12
	.byte		        En1 , v088
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte		N24   , An2 
	.byte	W12
	.byte		N06   , En1 
	.byte	W06
	.byte		N06   
	.byte	W06
mus_event0_7_B1:
mus_event0_7_000:
	.byte		N06   , Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v072
	.byte	W06
	.byte		        Fs1 , v096
	.byte	W06
	.byte		        Fs1 , v068
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v072
	.byte	W06
	.byte		        Fs1 , v096
	.byte	W06
	.byte		        Fs1 , v068
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v072
	.byte	W06
	.byte		N12   , As1 , v112
	.byte	W12
	.byte		N06   , Fs1 
	.byte	W06
	.byte		        Fs1 , v072
	.byte	W06
	.byte		        Fs1 , v096
	.byte	W06
	.byte		        Fs1 , v068
	.byte	W06
	.byte	PEND
	.byte		        Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v072
	.byte	W06
	.byte		        Fs1 , v096
	.byte	W06
	.byte		        Fs1 , v068
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v072
	.byte	W06
	.byte		        Fs1 , v096
	.byte	W06
	.byte		        Fs1 , v068
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v072
	.byte	W06
	.byte		N12   , As1 , v112
	.byte	W12
	.byte		N06   , Fs1 
	.byte	W06
	.byte		        Fs1 , v072
	.byte	W06
	.byte		        En1 , v127
	.byte	W06
	.byte		        Fs1 , v068
	.byte	W06
	.byte	PATT
	 .word	mus_event0_7_000
	.byte		N06   , Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v072
	.byte	W06
	.byte		        Fs1 , v096
	.byte	W06
	.byte		        Fs1 , v068
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v072
	.byte	W06
	.byte		        Fs1 , v096
	.byte	W06
	.byte		        Fs1 , v068
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v072
	.byte	W06
	.byte		N12   , As1 , v096
	.byte	W12
	.byte		N06   , Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v108
	.byte	W06
	.byte		N12   , As1 , v112
	.byte	W12
	.byte	GOTO
	 .word	mus_event0_7_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_event0:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_event0_pri	@ Priority
	.byte	mus_event0_rev	@ Reverb.

	.word	mus_event0_grp

	.word	mus_event0_1
	.word	mus_event0_2
	.word	mus_event0_3
	.word	mus_event0_4
	.word	mus_event0_5
	.word	mus_event0_6
	.word	mus_event0_7

	.end
