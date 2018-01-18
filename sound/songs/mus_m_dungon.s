	.include "MPlayDef.s"

	.equ	mus_m_dungon_grp, voicegroup_868CA74
	.equ	mus_m_dungon_pri, 0
	.equ	mus_m_dungon_rev, reverb_set+50
	.equ	mus_m_dungon_mvl, 127
	.equ	mus_m_dungon_key, 0
	.equ	mus_m_dungon_tbs, 1
	.equ	mus_m_dungon_exg, 0
	.equ	mus_m_dungon_cmp, 1

	.section .rodata
	.global	mus_m_dungon
	.align	2

@********************** Track  1 **********************@

mus_m_dungon_1:
	.byte	KEYSH , mus_m_dungon_key+0
mus_m_dungon_1_B1:
	.byte	TEMPO , 90*mus_m_dungon_tbs/2
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 35*mus_m_dungon_mvl/mxv
	.byte	W24
	.byte		PAN   , c_v-62
	.byte		N12   , Gn4 , v112
	.byte	W12
	.byte		        Gn4 , v084
	.byte	W12
	.byte		        Gn4 , v068
	.byte	W12
	.byte		        Gn4 , v036
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Gn4 , v112
	.byte	W12
	.byte		        Gn4 , v084
	.byte	W12
mus_m_dungon_1_000:
	.byte		N12   , Gn4 , v068
	.byte	W12
	.byte		        Gn4 , v036
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , Gn4 , v112
	.byte	W12
	.byte		        Gn4 , v084
	.byte	W12
	.byte		        Gn4 , v068
	.byte	W12
	.byte		        Gn4 , v036
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Gn4 , v112
	.byte	W12
	.byte		        Gn4 , v084
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_m_dungon_1_000
	.byte	PATT
	 .word	mus_m_dungon_1_000
mus_m_dungon_1_001:
	.byte		N12   , Gn4 , v068
	.byte	W12
	.byte		        Gn4 , v036
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N06   , Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v092
	.byte	W06
	.byte		        Gn4 , v068
	.byte	W06
	.byte		        Gn4 , v036
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v092
	.byte	W06
	.byte		        Gn4 , v068
	.byte	W06
	.byte		        Gn4 , v036
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v092
	.byte	W06
	.byte		        Gn4 , v068
	.byte	W06
	.byte		        Gn4 , v036
	.byte	W06
	.byte	PEND
mus_m_dungon_1_002:
	.byte		PAN   , c_v+63
	.byte		N06   , Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v092
	.byte	W06
	.byte		        Gn4 , v068
	.byte	W06
	.byte		        Gn4 , v036
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v092
	.byte	W06
	.byte		        Gn4 , v068
	.byte	W06
	.byte		        Gn4 , v036
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v092
	.byte	W06
	.byte		        Gn4 , v068
	.byte	W06
	.byte		        Gn4 , v036
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v092
	.byte	W06
	.byte		        Gn4 , v068
	.byte	W06
	.byte		        Gn4 , v036
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_m_dungon_1_002
	.byte	PATT
	 .word	mus_m_dungon_1_002
	.byte		PAN   , c_v+63
	.byte		N06   , Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v092
	.byte	W06
	.byte		        Gn4 , v068
	.byte	W06
	.byte		        Gn4 , v036
	.byte	W06
	.byte		PAN   , c_v-62
	.byte		N12   , Gn4 , v112
	.byte	W12
	.byte		        Gn4 , v084
	.byte	W12
	.byte		        Gn4 , v068
	.byte	W12
	.byte		        Gn4 , v036
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Gn4 , v112
	.byte	W12
	.byte		        Gn4 , v084
	.byte	W12
	.byte	PATT
	 .word	mus_m_dungon_1_000
	.byte	PATT
	 .word	mus_m_dungon_1_000
	.byte	PATT
	 .word	mus_m_dungon_1_000
	.byte	PATT
	 .word	mus_m_dungon_1_001
	.byte	PATT
	 .word	mus_m_dungon_1_002
	.byte	PATT
	 .word	mus_m_dungon_1_002
	.byte	PATT
	 .word	mus_m_dungon_1_002
	.byte		PAN   , c_v+63
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_m_dungon_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_m_dungon_2:
	.byte	KEYSH , mus_m_dungon_key+0
mus_m_dungon_2_B1:
	.byte		VOICE , 45
	.byte		LFOS  , 44
	.byte		VOL   , 68*mus_m_dungon_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W32
	.byte	W01
	.byte		N03   , Cn2 , v064
	.byte	W03
	.byte		N12   , Dn2 , v112
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Dn2 
	.byte	W21
	.byte		N03   , Cn2 , v064
	.byte	W03
	.byte		N12   , Dn2 , v112
	.byte	W12
mus_m_dungon_2_000:
	.byte		N12   , Gs2 , v112
	.byte	W12
	.byte		        Dn2 
	.byte	W21
	.byte		N03   , Cn2 , v064
	.byte	W03
	.byte		N12   , Dn2 , v112
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Dn2 
	.byte	W21
	.byte		N03   , Cn2 , v064
	.byte	W03
	.byte		N12   , Dn2 , v112
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_m_dungon_2_000
	.byte	PATT
	 .word	mus_m_dungon_2_000
	.byte	PATT
	 .word	mus_m_dungon_2_000
	.byte	PATT
	 .word	mus_m_dungon_2_000
	.byte	PATT
	 .word	mus_m_dungon_2_000
	.byte	PATT
	 .word	mus_m_dungon_2_000
	.byte		N12   , Gs2 , v112
	.byte	W12
	.byte		        Dn2 
	.byte	W21
	.byte		N03   , Ds2 , v064
	.byte	W03
	.byte		N12   , Fn2 , v112
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W21
	.byte		N03   , Ds2 , v064
	.byte	W03
	.byte		N12   , Fn2 , v112
	.byte	W12
mus_m_dungon_2_001:
	.byte		N12   , Bn2 , v112
	.byte	W12
	.byte		        Fn2 
	.byte	W21
	.byte		N03   , Ds2 , v064
	.byte	W03
	.byte		N12   , Fn2 , v112
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W21
	.byte		N03   , Ds2 , v064
	.byte	W03
	.byte		N12   , Fn2 , v112
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_m_dungon_2_001
	.byte	PATT
	 .word	mus_m_dungon_2_001
	.byte	PATT
	 .word	mus_m_dungon_2_001
	.byte	PATT
	 .word	mus_m_dungon_2_001
	.byte	PATT
	 .word	mus_m_dungon_2_001
	.byte	PATT
	 .word	mus_m_dungon_2_001
	.byte		N12   , Bn2 , v112
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		VOICE , 60
	.byte	W24
	.byte		VOL   , 49*mus_m_dungon_mvl/mxv
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N84   , Fn3 
	.byte	W60
	.byte	W24
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        An3 
	.byte	W12
	.byte		        Fs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W06
	.byte		        An2 , v096
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Fs2 , v092
	.byte	W06
	.byte		        An2 , v084
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Fs2 , v080
	.byte	W06
	.byte		N04   , An2 
	.byte	W04
	.byte		        Cn3 , v084
	.byte	W04
	.byte		        Ds3 , v088
	.byte	W04
	.byte		        An3 , v092
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		N08   , Dn4 , v104
	.byte	W76
	.byte	GOTO
	 .word	mus_m_dungon_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_m_dungon_3:
	.byte	KEYSH , mus_m_dungon_key+0
mus_m_dungon_3_B1:
	.byte		VOICE , 24
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 88*mus_m_dungon_mvl/mxv
	.byte	W18
	.byte		N03   , En1 , v124
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		N42   , Gn1 
	.byte	W42
	.byte		N03   , En1 
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		N42   , Gn1 
	.byte	W24
mus_m_dungon_3_000:
	.byte	W18
	.byte		N03   , En1 , v124
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		N42   , Gn1 
	.byte	W42
	.byte		N03   , En1 
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		N42   , Gn1 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_m_dungon_3_000
	.byte	PATT
	 .word	mus_m_dungon_3_000
	.byte	PATT
	 .word	mus_m_dungon_3_000
	.byte	PATT
	 .word	mus_m_dungon_3_000
	.byte	PATT
	 .word	mus_m_dungon_3_000
	.byte	PATT
	 .word	mus_m_dungon_3_000
	.byte	W18
	.byte		N03   , En1 , v124
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		N42   , As1 
	.byte	W42
	.byte		N03   , Gn1 
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		N42   , As1 
	.byte	W24
mus_m_dungon_3_001:
	.byte	W18
	.byte		N03   , Gn1 , v124
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		N42   , As1 
	.byte	W42
	.byte		N03   , Gn1 
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		N42   , As1 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_m_dungon_3_001
	.byte	PATT
	 .word	mus_m_dungon_3_001
	.byte	PATT
	 .word	mus_m_dungon_3_001
	.byte	PATT
	 .word	mus_m_dungon_3_001
	.byte	PATT
	 .word	mus_m_dungon_3_001
	.byte	PATT
	 .word	mus_m_dungon_3_001
	.byte	W18
	.byte		N03   , Gn1 , v124
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		VOICE , 48
	.byte		VOL   , 41*mus_m_dungon_mvl/mxv
	.byte	W72
	.byte	W48
	.byte		N06   , As2 , v112
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W12
	.byte		        Cn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Ds3 , v100
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Cn3 , v092
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        An2 , v088
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N04   , Ds3 , v084
	.byte	W04
	.byte		        Fs3 , v088
	.byte	W04
	.byte		        An3 , v092
	.byte	W04
	.byte		        Ds4 , v096
	.byte	W04
	.byte		        Fs4 , v100
	.byte	W04
	.byte		N08   , As4 , v112
	.byte	W52
	.byte		VOICE , 47
	.byte		N24   , As0 
	.byte	W24
	.byte	GOTO
	 .word	mus_m_dungon_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_m_dungon_4:
	.byte	KEYSH , mus_m_dungon_key+0
mus_m_dungon_4_B1:
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		VOL   , 55*mus_m_dungon_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v-8
	.byte	W24
	.byte		BEND  , c_v-8
	.byte		N12   , Gn3 , v112
	.byte	W03
	.byte		BEND  , c_v+5
	.byte	W03
	.byte		        c_v+0
	.byte	W18
	.byte		N12   , Ds3 
	.byte	W24
	.byte		BEND  , c_v-5
	.byte		N12   , Gn3 
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		        c_v+0
	.byte	W18
	.byte		N12   , Gs3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		BEND  , c_v-9
	.byte		N12   , Dn3 
	.byte	W03
	.byte		BEND  , c_v+5
	.byte	W03
	.byte		        c_v+0
	.byte	W18
	.byte		N12   , Cn3 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		BEND  , c_v-7
	.byte		N12   , Gs3 
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		        c_v+0
	.byte	W18
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        Gn3 , v096
	.byte	W12
	.byte		        Ds3 , v112
	.byte	W12
	.byte		        Ds3 , v096
	.byte	W12
	.byte		        Gn3 , v112
	.byte	W12
	.byte		        Gn3 , v096
	.byte	W12
	.byte		        Gs3 , v112
	.byte	W12
	.byte		        Gs3 , v096
	.byte	W12
	.byte		        Gn3 , v112
	.byte	W12
	.byte		        Gn3 , v096
	.byte	W12
	.byte		        Ds3 , v112
	.byte	W12
	.byte		        Ds3 , v096
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W12
	.byte		        Dn3 , v096
	.byte	W12
	.byte		        Cn3 , v112
	.byte	W12
	.byte		        Cn3 , v096
	.byte	W12
	.byte		        Bn2 , v112
	.byte	W12
	.byte		        Bn2 , v096
	.byte	W12
	.byte		        Gn2 , v112
	.byte	W12
	.byte		        Gn2 , v096
	.byte	W12
	.byte		        Bn2 , v112
	.byte	W12
	.byte		        Bn2 , v096
	.byte	W12
	.byte		        Cn3 , v112
	.byte	W12
	.byte		        Cn3 , v096
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W12
	.byte		        Dn3 , v096
	.byte	W12
	.byte		        Ds3 , v112
	.byte	W12
	.byte		        Ds3 , v096
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W12
	.byte		        Dn3 , v096
	.byte	W12
	.byte		        Gs3 , v112
	.byte	W12
	.byte		        Gs3 , v096
	.byte	W12
	.byte		BEND  , c_v-8
	.byte		N12   , As3 , v112
	.byte	W03
	.byte		BEND  , c_v+5
	.byte	W03
	.byte		        c_v+0
	.byte	W18
	.byte		N12   , Fs3 
	.byte	W24
	.byte		BEND  , c_v-5
	.byte		N12   , As3 
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		        c_v+0
	.byte	W18
	.byte		N12   , Bn3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		BEND  , c_v-9
	.byte		N12   , Fn3 
	.byte	W03
	.byte		BEND  , c_v+5
	.byte	W03
	.byte		        c_v+0
	.byte	W18
	.byte		N12   , Ds3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		BEND  , c_v-7
	.byte		N12   , Bn3 
	.byte	W03
	.byte		BEND  , c_v+5
	.byte	W03
	.byte		        c_v+0
	.byte	W18
	.byte		N06   , As3 
	.byte	W12
	.byte		        As3 , v096
	.byte	W12
	.byte		        Fs3 , v112
	.byte	W12
	.byte		        Fs3 , v096
	.byte	W12
	.byte		        As3 , v112
	.byte	W12
	.byte		        As3 , v096
	.byte	W12
	.byte		        Bn3 , v112
	.byte	W12
	.byte		        Bn3 , v096
	.byte	W12
	.byte		        As3 , v112
	.byte	W12
	.byte		        As3 , v096
	.byte	W12
	.byte		        Fs3 , v112
	.byte	W12
	.byte		        Fs3 , v096
	.byte	W12
	.byte		        Fn3 , v112
	.byte	W12
	.byte		        Fn3 , v096
	.byte	W12
	.byte		        Ds3 , v112
	.byte	W12
	.byte		        Ds3 , v096
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W12
	.byte		        Dn3 , v096
	.byte	W12
	.byte		        As2 , v112
	.byte	W12
	.byte		        As2 , v096
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W12
	.byte		        Dn3 , v096
	.byte	W12
	.byte		        Ds3 , v112
	.byte	W12
	.byte		        Ds3 , v096
	.byte	W12
	.byte		        Fn3 , v112
	.byte	W12
	.byte		        Fn3 , v096
	.byte	W12
	.byte		        Fs3 , v112
	.byte	W12
	.byte		        Fs3 , v096
	.byte	W12
	.byte		        Fn3 , v112
	.byte	W12
	.byte		        Fn3 , v096
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N06   , Bn3 , v112
	.byte	W18
	.byte		VOICE , 47
	.byte		N03   , As1 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		VOL   , 70*mus_m_dungon_mvl/mxv
	.byte		N06   , As1 , v120
	.byte	W12
	.byte		        As0 , v124
	.byte	W60
	.byte	W66
	.byte		N03   , An2 , v112
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , As2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        As2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        As1 
	.byte	W84
	.byte		N04   , As1 , v072
	.byte	W04
	.byte		        As1 , v088
	.byte	W04
	.byte		        As1 , v096
	.byte	W04
	.byte		        Fn2 , v100
	.byte	W04
	.byte		        Fn2 , v104
	.byte	W04
	.byte		N08   , As2 , v124
	.byte	W52
	.byte		N14   , As1 , v112
	.byte	W24
	.byte	GOTO
	 .word	mus_m_dungon_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_m_dungon_5:
	.byte	KEYSH , mus_m_dungon_key+0
mus_m_dungon_5_B1:
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		PAN   , c_v+23
	.byte		BENDR , 12
	.byte		VOL   , 55*mus_m_dungon_mvl/mxv
	.byte	W24
	.byte		        55*mus_m_dungon_mvl/mxv
	.byte	W12
	.byte		N12   , Gn3 , v072
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Gn3 
	.byte	W12
	.byte	W12
	.byte		        Gs3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Dn3 
	.byte	W12
	.byte	W12
	.byte		        Cn3 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		        Bn2 
	.byte	W12
	.byte	W12
	.byte		        Cn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Dn3 
	.byte	W12
	.byte	W12
	.byte		        Gs3 
	.byte	W18
	.byte		N06   , Gn3 , v112
	.byte	W12
	.byte		        Gn3 , v080
	.byte	W12
	.byte		        Ds3 , v112
	.byte	W12
	.byte		        Ds3 , v084
	.byte	W12
	.byte		        Gn3 , v112
	.byte	W12
	.byte		        Gn3 , v088
	.byte	W06
	.byte	W06
	.byte		        Gs3 , v112
	.byte	W12
	.byte		        Gs3 , v084
	.byte	W12
	.byte		        Gn3 , v112
	.byte	W12
	.byte		        Gn3 , v084
	.byte	W12
	.byte		        Ds3 , v112
	.byte	W12
	.byte		        Ds3 , v084
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W12
	.byte		        Dn3 , v080
	.byte	W06
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W12
	.byte		        Cn3 , v088
	.byte	W12
	.byte		        Bn2 , v112
	.byte	W12
	.byte		        Bn2 , v084
	.byte	W12
	.byte		        Gn2 , v112
	.byte	W12
	.byte		        Gn2 , v084
	.byte	W12
	.byte		        Bn2 , v112
	.byte	W12
	.byte		        Bn2 , v088
	.byte	W06
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W12
	.byte		        Cn3 , v088
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W12
	.byte		        Dn3 , v084
	.byte	W12
	.byte		        Ds3 , v112
	.byte	W12
	.byte		        Ds3 , v080
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W12
	.byte		        Dn3 , v084
	.byte	W06
	.byte	W06
	.byte		        Gs3 , v112
	.byte	W12
	.byte		        Gs3 , v088
	.byte	W18
	.byte		N12   , As3 , v072
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        As3 
	.byte	W12
	.byte	W12
	.byte		        Bn3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W12
	.byte	W12
	.byte		        Ds3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Dn3 
	.byte	W12
	.byte	W12
	.byte		        Ds3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W12
	.byte	W12
	.byte		        Bn3 
	.byte	W18
	.byte		N06   , As3 , v112
	.byte	W12
	.byte		        As3 , v080
	.byte	W12
	.byte		        Fs3 , v112
	.byte	W12
	.byte		        Fs3 , v084
	.byte	W12
	.byte		        As3 , v112
	.byte	W12
	.byte		        As3 , v088
	.byte	W06
	.byte	W06
	.byte		        Bn3 , v112
	.byte	W12
	.byte		        Bn3 , v084
	.byte	W12
	.byte		        As3 , v112
	.byte	W12
	.byte		        As3 , v084
	.byte	W12
	.byte		        Fs3 , v112
	.byte	W12
	.byte		        Fs3 , v084
	.byte	W12
	.byte		        Fn3 , v112
	.byte	W12
	.byte		        Fn3 , v080
	.byte	W06
	.byte	W06
	.byte		        Ds3 , v112
	.byte	W12
	.byte		        Ds3 , v088
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W12
	.byte		        Dn3 , v084
	.byte	W12
	.byte		        As2 , v112
	.byte	W12
	.byte		        As2 , v084
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W12
	.byte		        Dn3 , v088
	.byte	W06
	.byte	W06
	.byte		        Ds3 , v112
	.byte	W12
	.byte		        Ds3 , v088
	.byte	W12
	.byte		        Fn3 , v112
	.byte	W12
	.byte		        Fn3 , v084
	.byte	W12
	.byte		        Fs3 , v112
	.byte	W12
	.byte		        Fs3 , v080
	.byte	W12
	.byte		        Fn3 , v112
	.byte	W12
	.byte		        Fn3 , v084
	.byte	W06
	.byte	W06
	.byte		        Bn3 , v112
	.byte	W18
	.byte		VOICE , 35
	.byte		VOL   , 88*mus_m_dungon_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , As1 
	.byte	W12
	.byte		N84   , As0 
	.byte	W60
	.byte	W24
	.byte		BEND  , c_v+0
	.byte		N24   
	.byte	W03
	.byte		BEND  , c_v+4
	.byte	W03
	.byte		        c_v+0
	.byte	W18
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        As0 
	.byte	W06
	.byte		        An0 
	.byte	W06
	.byte		        As0 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		N72   , An0 
	.byte	W72
	.byte		N04   
	.byte	W04
	.byte		        Cn1 
	.byte	W04
	.byte		        Ds1 
	.byte	W04
	.byte		        Fs1 
	.byte	W04
	.byte		        An1 
	.byte	W04
	.byte		N08   , As1 
	.byte	W52
	.byte		N06   , As0 
	.byte	W24
	.byte	GOTO
	 .word	mus_m_dungon_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_m_dungon_6:
	.byte	KEYSH , mus_m_dungon_key+0
mus_m_dungon_6_B1:
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		VOL   , 33*mus_m_dungon_mvl/mxv
	.byte		PAN   , c_v-62
	.byte		BENDR , 12
	.byte		BEND  , c_v-26
	.byte		TIE   , Dn2 , v112
	.byte	W02
	.byte		BEND  , c_v-22
	.byte	W03
	.byte		        c_v-18
	.byte	W03
	.byte		        c_v-14
	.byte	W04
	.byte		        c_v-13
	.byte	W02
	.byte		        c_v-9
	.byte	W03
	.byte		        c_v-5
	.byte	W03
	.byte		        c_v-2
	.byte	W04
	.byte		        c_v+0
	.byte	W72
	.byte	W24
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v-1
	.byte	W03
	.byte		        c_v-3
	.byte	W03
	.byte		        c_v-5
	.byte	W04
	.byte		        c_v-5
	.byte	W02
	.byte		        c_v-7
	.byte	W03
	.byte		        c_v-9
	.byte	W03
	.byte		        c_v-10
	.byte	W04
	.byte		        c_v-12
	.byte	W02
	.byte		        c_v-13
	.byte	W03
	.byte		        c_v-14
	.byte	W03
	.byte		        c_v-16
	.byte	W04
	.byte		        c_v-18
	.byte	W02
	.byte		        c_v-21
	.byte	W03
	.byte		        c_v-24
	.byte	W03
	.byte		        c_v-28
	.byte	W04
	.byte		        c_v-31
	.byte	W02
	.byte		        c_v-34
	.byte	W03
	.byte		        c_v-35
	.byte	W03
	.byte		        c_v-34
	.byte	W04
	.byte		        c_v-32
	.byte	W02
	.byte		        c_v-29
	.byte	W03
	.byte		        c_v-26
	.byte	W03
	.byte		        c_v-21
	.byte	W04
	.byte		        c_v-18
	.byte	W02
	.byte		        c_v-14
	.byte	W03
	.byte		        c_v-12
	.byte	W03
	.byte		        c_v-10
	.byte	W04
	.byte		        c_v-7
	.byte	W02
	.byte		        c_v-5
	.byte	W03
	.byte		        c_v-3
	.byte	W03
	.byte		        c_v+0
	.byte	W76
	.byte	W24
	.byte		        c_v-2
	.byte	W02
	.byte		        c_v-4
	.byte	W03
	.byte		        c_v-6
	.byte	W03
	.byte		        c_v-10
	.byte	W04
	.byte		        c_v-12
	.byte	W02
	.byte		        c_v-16
	.byte	W03
	.byte		        c_v-20
	.byte	W03
	.byte		        c_v-24
	.byte	W04
	.byte		        c_v-28
	.byte	W02
	.byte		        c_v-32
	.byte	W03
	.byte		        c_v-37
	.byte	W03
	.byte		        c_v-41
	.byte	W04
	.byte		        c_v-43
	.byte	W02
	.byte		        c_v-45
	.byte	W10
	.byte		        c_v-42
	.byte	W02
	.byte		        c_v-37
	.byte	W03
	.byte		        c_v-32
	.byte	W03
	.byte		        c_v-27
	.byte	W04
	.byte		        c_v-23
	.byte	W02
	.byte		        c_v-16
	.byte	W03
	.byte		        c_v-12
	.byte	W03
	.byte		        c_v-5
	.byte	W04
	.byte		        c_v+6
	.byte	W02
	.byte		        c_v+14
	.byte	W03
	.byte		        c_v+20
	.byte	W03
	.byte		        c_v+26
	.byte	W04
	.byte		        c_v+30
	.byte	W02
	.byte		        c_v+36
	.byte	W03
	.byte		        c_v+41
	.byte	W03
	.byte		        c_v+43
	.byte	W04
	.byte		EOT   
	.byte		BEND  , c_v+0
	.byte		TIE   , Dn3 
	.byte	W06
	.byte		BEND  , c_v-6
	.byte	W06
	.byte		        c_v+0
	.byte	W60
	.byte	W24
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v-3
	.byte	W03
	.byte		        c_v-5
	.byte	W03
	.byte		        c_v-8
	.byte	W04
	.byte		        c_v-11
	.byte	W02
	.byte		        c_v-15
	.byte	W03
	.byte		        c_v-18
	.byte	W03
	.byte		        c_v-22
	.byte	W04
	.byte		        c_v-24
	.byte	W02
	.byte		        c_v-31
	.byte	W03
	.byte		        c_v-36
	.byte	W03
	.byte		        c_v-40
	.byte	W04
	.byte		        c_v-44
	.byte	W02
	.byte		        c_v-46
	.byte	W03
	.byte		        c_v-50
	.byte	W03
	.byte		        c_v-53
	.byte	W04
	.byte		        c_v-54
	.byte	W02
	.byte		        c_v-52
	.byte	W03
	.byte		        c_v-47
	.byte	W03
	.byte		        c_v-42
	.byte	W04
	.byte		        c_v-41
	.byte	W02
	.byte		        c_v-36
	.byte	W03
	.byte		        c_v-33
	.byte	W03
	.byte		        c_v-30
	.byte	W04
	.byte		        c_v-28
	.byte	W02
	.byte		        c_v-24
	.byte	W03
	.byte		        c_v-18
	.byte	W03
	.byte		        c_v-13
	.byte	W04
	.byte		        c_v-11
	.byte	W02
	.byte		        c_v-5
	.byte	W03
	.byte		        c_v-1
	.byte	W03
	.byte		        c_v+0
	.byte	W04
	.byte		        c_v+0
	.byte	W48
	.byte		        c_v-6
	.byte	W06
	.byte		        c_v+0
	.byte	W18
	.byte	W12
	.byte		        c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W18
	.byte		        c_v-4
	.byte	W06
	.byte		        c_v+0
	.byte	W30
	.byte		        c_v-2
	.byte	W02
	.byte		        c_v-3
	.byte	W03
	.byte		        c_v-5
	.byte	W03
	.byte		        c_v-7
	.byte	W04
	.byte		        c_v-9
	.byte	W02
	.byte		        c_v-11
	.byte	W03
	.byte		        c_v-14
	.byte	W03
	.byte		        c_v-19
	.byte	W04
	.byte		        c_v-22
	.byte	W02
	.byte		        c_v-28
	.byte	W03
	.byte		        c_v-35
	.byte	W03
	.byte		        c_v-41
	.byte	W04
	.byte		        c_v-44
	.byte	W02
	.byte		        c_v-46
	.byte	W03
	.byte		        c_v-48
	.byte	W07
	.byte		EOT   
	.byte		BEND  , c_v+0
	.byte		TIE   , Fn2 
	.byte	W72
	.byte		BEND  , c_v+5
	.byte	W24
	.byte		        c_v+0
	.byte	W48
	.byte		        c_v-11
	.byte	W24
	.byte	W24
	.byte		        c_v+0
	.byte	W72
mus_m_dungon_6_000:
	.byte		BEND  , c_v+5
	.byte	W24
	.byte		        c_v+0
	.byte	W24
	.byte		        c_v-11
	.byte	W24
	.byte		        c_v+0
	.byte	W24
	.byte	PEND
	.byte	W24
	.byte		EOT   , Fn2 
	.byte		BEND  , c_v+0
	.byte		TIE   , Fn3 , v112
	.byte	W72
	.byte		BEND  , c_v+5
	.byte	W24
	.byte		        c_v+0
	.byte	W48
	.byte		        c_v-11
	.byte	W06
	.byte		        c_v+0
	.byte	W18
	.byte		        c_v-8
	.byte	W06
	.byte		        c_v+0
	.byte	W18
	.byte		        c_v+0
	.byte	W72
	.byte	PATT
	 .word	mus_m_dungon_6_000
	.byte	W24
	.byte		EOT   , Fn3 
	.byte	W30
	.byte		N03   , Ds3 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N06   , As2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N84   , Dn3 
	.byte	W60
	.byte	W24
	.byte		N06   , An3 
	.byte	W06
	.byte		        Fs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fs2 , v100
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Ds2 , v096
	.byte	W06
	.byte		        Fs2 , v092
	.byte	W06
	.byte		        Cn2 , v080
	.byte	W06
	.byte		        Ds2 , v076
	.byte	W06
	.byte		N04   , Fs2 , v072
	.byte	W04
	.byte		        An2 , v076
	.byte	W04
	.byte		        Cn3 , v080
	.byte	W04
	.byte		        Ds3 , v088
	.byte	W04
	.byte		        Fs3 , v096
	.byte	W04
	.byte		N08   , An3 , v112
	.byte	W76
	.byte	GOTO
	 .word	mus_m_dungon_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_m_dungon_7:
	.byte	KEYSH , mus_m_dungon_key+0
mus_m_dungon_7_B1:
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		VOL   , 33*mus_m_dungon_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		BENDR , 12
	.byte		BEND  , c_v-26
	.byte		TIE   , Gn2 , v112
	.byte	W02
	.byte		BEND  , c_v-22
	.byte	W03
	.byte		        c_v-18
	.byte	W03
	.byte		        c_v-14
	.byte	W04
	.byte		        c_v-13
	.byte	W02
	.byte		        c_v-9
	.byte	W03
	.byte		        c_v-5
	.byte	W03
	.byte		        c_v-2
	.byte	W04
	.byte		        c_v+0
	.byte	W72
	.byte	W24
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v-1
	.byte	W03
	.byte		        c_v-3
	.byte	W03
	.byte		        c_v-5
	.byte	W04
	.byte		        c_v-5
	.byte	W02
	.byte		        c_v-7
	.byte	W03
	.byte		        c_v-9
	.byte	W03
	.byte		        c_v-10
	.byte	W04
	.byte		        c_v-12
	.byte	W02
	.byte		        c_v-13
	.byte	W03
	.byte		        c_v-14
	.byte	W03
	.byte		        c_v-16
	.byte	W04
	.byte		        c_v-18
	.byte	W02
	.byte		        c_v-21
	.byte	W03
	.byte		        c_v-24
	.byte	W03
	.byte		        c_v-28
	.byte	W04
	.byte		        c_v-31
	.byte	W02
	.byte		        c_v-34
	.byte	W03
	.byte		        c_v-35
	.byte	W03
	.byte		        c_v-34
	.byte	W04
	.byte		        c_v-32
	.byte	W02
	.byte		        c_v-29
	.byte	W03
	.byte		        c_v-26
	.byte	W03
	.byte		        c_v-21
	.byte	W04
	.byte		        c_v-18
	.byte	W02
	.byte		        c_v-14
	.byte	W03
	.byte		        c_v-12
	.byte	W03
	.byte		        c_v-10
	.byte	W04
	.byte		        c_v-7
	.byte	W02
	.byte		        c_v-5
	.byte	W03
	.byte		        c_v-3
	.byte	W03
	.byte		        c_v+0
	.byte	W76
	.byte	W24
	.byte		        c_v-2
	.byte	W02
	.byte		        c_v-4
	.byte	W03
	.byte		        c_v-6
	.byte	W03
	.byte		        c_v-10
	.byte	W04
	.byte		        c_v-12
	.byte	W02
	.byte		        c_v-16
	.byte	W03
	.byte		        c_v-20
	.byte	W03
	.byte		        c_v-24
	.byte	W04
	.byte		        c_v-28
	.byte	W02
	.byte		        c_v-32
	.byte	W03
	.byte		        c_v-37
	.byte	W03
	.byte		        c_v-41
	.byte	W04
	.byte		        c_v-43
	.byte	W02
	.byte		        c_v-45
	.byte	W10
	.byte		        c_v-42
	.byte	W02
	.byte		        c_v-37
	.byte	W03
	.byte		        c_v-32
	.byte	W03
	.byte		        c_v-27
	.byte	W04
	.byte		        c_v-23
	.byte	W02
	.byte		        c_v-16
	.byte	W03
	.byte		        c_v-12
	.byte	W03
	.byte		        c_v-5
	.byte	W04
	.byte		        c_v+6
	.byte	W02
	.byte		        c_v+14
	.byte	W03
	.byte		        c_v+20
	.byte	W03
	.byte		        c_v+26
	.byte	W04
	.byte		        c_v+30
	.byte	W02
	.byte		        c_v+36
	.byte	W03
	.byte		        c_v+41
	.byte	W03
	.byte		        c_v+43
	.byte	W04
	.byte		EOT   
	.byte		BEND  , c_v+0
	.byte		TIE   , Gn3 
	.byte	W06
	.byte		BEND  , c_v-6
	.byte	W06
	.byte		        c_v+0
	.byte	W60
	.byte	W24
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v-3
	.byte	W03
	.byte		        c_v-5
	.byte	W03
	.byte		        c_v-8
	.byte	W04
	.byte		        c_v-11
	.byte	W02
	.byte		        c_v-15
	.byte	W03
	.byte		        c_v-18
	.byte	W03
	.byte		        c_v-22
	.byte	W04
	.byte		        c_v-24
	.byte	W02
	.byte		        c_v-31
	.byte	W03
	.byte		        c_v-36
	.byte	W03
	.byte		        c_v-40
	.byte	W04
	.byte		        c_v-44
	.byte	W02
	.byte		        c_v-46
	.byte	W03
	.byte		        c_v-50
	.byte	W03
	.byte		        c_v-53
	.byte	W04
	.byte		        c_v-54
	.byte	W02
	.byte		        c_v-52
	.byte	W03
	.byte		        c_v-47
	.byte	W03
	.byte		        c_v-42
	.byte	W04
	.byte		        c_v-41
	.byte	W02
	.byte		        c_v-36
	.byte	W03
	.byte		        c_v-33
	.byte	W03
	.byte		        c_v-30
	.byte	W04
	.byte		        c_v-28
	.byte	W02
	.byte		        c_v-24
	.byte	W03
	.byte		        c_v-18
	.byte	W03
	.byte		        c_v-13
	.byte	W04
	.byte		        c_v-11
	.byte	W02
	.byte		        c_v-5
	.byte	W03
	.byte		        c_v-1
	.byte	W03
	.byte		        c_v+0
	.byte	W04
	.byte		        c_v+0
	.byte	W48
	.byte		        c_v-6
	.byte	W06
	.byte		        c_v+0
	.byte	W18
	.byte	W12
	.byte		        c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W18
	.byte		        c_v-4
	.byte	W06
	.byte		        c_v+0
	.byte	W30
	.byte		        c_v-2
	.byte	W02
	.byte		        c_v-3
	.byte	W03
	.byte		        c_v-5
	.byte	W03
	.byte		        c_v-7
	.byte	W04
	.byte		        c_v-9
	.byte	W02
	.byte		        c_v-11
	.byte	W03
	.byte		        c_v-14
	.byte	W03
	.byte		        c_v-19
	.byte	W04
	.byte		        c_v-22
	.byte	W02
	.byte		        c_v-28
	.byte	W03
	.byte		        c_v-35
	.byte	W03
	.byte		        c_v-41
	.byte	W04
	.byte		        c_v-44
	.byte	W02
	.byte		        c_v-46
	.byte	W03
	.byte		        c_v-48
	.byte	W07
	.byte		EOT   
	.byte		BEND  , c_v+0
	.byte		TIE   , As2 
	.byte	W72
	.byte		BEND  , c_v+5
	.byte	W24
	.byte		        c_v+0
	.byte	W48
	.byte		        c_v-6
	.byte	W24
	.byte	W24
	.byte		        c_v+0
	.byte	W72
mus_m_dungon_7_000:
	.byte		BEND  , c_v+5
	.byte	W24
	.byte		        c_v+0
	.byte	W24
	.byte		        c_v-6
	.byte	W24
	.byte		        c_v+0
	.byte	W24
	.byte	PEND
	.byte	W24
	.byte		EOT   , As2 
	.byte		BEND  , c_v+0
	.byte		TIE   , As3 , v112
	.byte	W72
	.byte		BEND  , c_v+5
	.byte	W24
	.byte		        c_v+0
	.byte	W48
	.byte		        c_v-6
	.byte	W06
	.byte		        c_v+0
	.byte	W18
	.byte		        c_v-8
	.byte	W06
	.byte		        c_v+0
	.byte	W18
	.byte		        c_v+0
	.byte	W72
	.byte	PATT
	 .word	mus_m_dungon_7_000
	.byte	W24
	.byte		EOT   , As3 
	.byte	W30
	.byte		N03   , As3 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N84   , Gs3 
	.byte	W60
	.byte	W24
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cn3 , v100
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        An2 , v096
	.byte	W06
	.byte		        Cn3 , v092
	.byte	W06
	.byte		        Fs2 , v080
	.byte	W06
	.byte		        An2 , v076
	.byte	W06
	.byte		N04   , Cn3 , v072
	.byte	W04
	.byte		        Ds3 , v076
	.byte	W04
	.byte		        Fs3 , v080
	.byte	W04
	.byte		        Cn4 , v088
	.byte	W04
	.byte		        Ds4 , v096
	.byte	W04
	.byte		N08   , Fn4 , v112
	.byte	W76
	.byte	GOTO
	 .word	mus_m_dungon_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_m_dungon_8:
	.byte	KEYSH , mus_m_dungon_key+0
mus_m_dungon_8_B1:
	.byte		VOICE , 0
	.byte		VOL   , 65*mus_m_dungon_mvl/mxv
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
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		N48   , An2 , v112
	.byte	W72
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_m_dungon_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_m_dungon_9:
	.byte	KEYSH , mus_m_dungon_key+0
mus_m_dungon_9_B1:
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		PAN   , c_v+0
	.byte		VOL   , 43*mus_m_dungon_mvl/mxv
	.byte		BEND  , c_v+2
	.byte	W18
	.byte		N03   , En1 , v112
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		N42   , Gn1 
	.byte	W24
	.byte		MOD   , 24
	.byte	W18
	.byte		        0
	.byte		N03   , En1 
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		N42   , Gn1 
	.byte	W24
mus_m_dungon_9_000:
	.byte		MOD   , 24
	.byte	W18
	.byte		        0
	.byte		N03   , En1 , v112
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		N42   , Gn1 
	.byte	W24
	.byte		MOD   , 24
	.byte	W18
	.byte		        0
	.byte		N03   , En1 
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		N42   , Gn1 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_m_dungon_9_000
	.byte	PATT
	 .word	mus_m_dungon_9_000
mus_m_dungon_9_001:
	.byte	W18
	.byte		N03   , En1 , v112
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		N42   , Gn1 
	.byte	W42
	.byte		N03   , En1 
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		N42   , Gn1 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_m_dungon_9_001
	.byte	PATT
	 .word	mus_m_dungon_9_001
	.byte	PATT
	 .word	mus_m_dungon_9_001
	.byte	W18
	.byte		N03   , En1 , v112
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		N42   , As1 
	.byte	W42
	.byte		N03   , Gn1 
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		N42   , As1 
	.byte	W24
mus_m_dungon_9_002:
	.byte	W18
	.byte		N03   , Gn1 , v112
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		N42   , As1 
	.byte	W42
	.byte		N03   , Gn1 
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		N42   , As1 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_m_dungon_9_002
	.byte	PATT
	 .word	mus_m_dungon_9_002
	.byte	PATT
	 .word	mus_m_dungon_9_002
	.byte	PATT
	 .word	mus_m_dungon_9_002
	.byte	PATT
	 .word	mus_m_dungon_9_002
	.byte	PATT
	 .word	mus_m_dungon_9_002
	.byte	W18
	.byte		N03   , Gn1 , v112
	.byte	W03
	.byte		        An1 
	.byte	W72
	.byte	W03
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_m_dungon_9_B1
	.byte	FINE

@********************** Track 10 **********************@

mus_m_dungon_10:
	.byte	KEYSH , mus_m_dungon_key+0
mus_m_dungon_10_B1:
	.byte		VOICE , 14
	.byte		PAN   , c_v+0
	.byte		VOL   , 70*mus_m_dungon_mvl/mxv
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		BEND  , c_v+0
	.byte		N48   , Gn2 , v112
	.byte	W24
	.byte		BEND  , c_v-2
	.byte	W02
	.byte		        c_v-5
	.byte	W03
	.byte		        c_v-10
	.byte	W03
	.byte		        c_v-15
	.byte	W04
	.byte		        c_v-16
	.byte	W02
	.byte		        c_v-21
	.byte	W03
	.byte		        c_v-23
	.byte	W07
	.byte		PAN   , c_v+32
	.byte		BEND  , c_v-5
	.byte		N48   , Gn2 , v100
	.byte	W24
	.byte		BEND  , c_v-7
	.byte	W02
	.byte		        c_v-12
	.byte	W03
	.byte		        c_v-17
	.byte	W03
	.byte		        c_v-19
	.byte	W04
	.byte		        c_v-22
	.byte	W02
	.byte		        c_v-24
	.byte	W03
	.byte		        c_v-27
	.byte	W03
	.byte		        c_v-28
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		BEND  , c_v-9
	.byte		N48   , Gn2 , v080
	.byte	W24
	.byte		BEND  , c_v-12
	.byte	W02
	.byte		        c_v-15
	.byte	W03
	.byte		        c_v-20
	.byte	W03
	.byte		        c_v-26
	.byte	W04
	.byte		        c_v-28
	.byte	W02
	.byte		        c_v-32
	.byte	W03
	.byte		        c_v-37
	.byte	W03
	.byte		        c_v-38
	.byte	W04
	.byte		        c_v-14
	.byte		N48   , Gn2 , v084
	.byte	W24
	.byte	W24
	.byte		BEND  , c_v-21
	.byte		N48   , Gn2 , v048
	.byte	W06
	.byte		BEND  , c_v-23
	.byte	W06
	.byte		        c_v-25
	.byte	W02
	.byte		        c_v-28
	.byte	W03
	.byte		        c_v-30
	.byte	W03
	.byte		        c_v-34
	.byte	W04
	.byte		        c_v-36
	.byte	W02
	.byte		        c_v-39
	.byte	W03
	.byte		        c_v-41
	.byte	W03
	.byte		        c_v-43
	.byte	W04
	.byte		        c_v-46
	.byte	W02
	.byte		        c_v-48
	.byte	W03
	.byte		        c_v-51
	.byte	W03
	.byte		        c_v-54
	.byte	W04
	.byte		        c_v+0
	.byte	W24
	.byte	W24
	.byte		PAN   , c_v+32
	.byte	W48
	.byte		        c_v-32
	.byte	W24
	.byte	W24
	.byte		        c_v-32
	.byte		BEND  , c_v+0
	.byte		N48   , Gn3 , v112
	.byte	W24
	.byte		BEND  , c_v-2
	.byte	W02
	.byte		        c_v-5
	.byte	W03
	.byte		        c_v-10
	.byte	W03
	.byte		        c_v-15
	.byte	W04
	.byte		        c_v-16
	.byte	W02
	.byte		        c_v-21
	.byte	W03
	.byte		        c_v-23
	.byte	W07
	.byte		PAN   , c_v+32
	.byte		BEND  , c_v-5
	.byte		N48   , Gn3 , v100
	.byte	W24
	.byte		BEND  , c_v-7
	.byte	W02
	.byte		        c_v-12
	.byte	W03
	.byte		        c_v-17
	.byte	W03
	.byte		        c_v-19
	.byte	W04
	.byte		        c_v-22
	.byte	W02
	.byte		        c_v-24
	.byte	W03
	.byte		        c_v-27
	.byte	W03
	.byte		        c_v-28
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		BEND  , c_v-9
	.byte		N48   , Gn3 , v080
	.byte	W24
	.byte		BEND  , c_v-12
	.byte	W02
	.byte		        c_v-15
	.byte	W03
	.byte		        c_v-20
	.byte	W03
	.byte		        c_v-26
	.byte	W04
	.byte		        c_v-28
	.byte	W02
	.byte		        c_v-32
	.byte	W03
	.byte		        c_v-37
	.byte	W03
	.byte		        c_v-38
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		BEND  , c_v-14
	.byte		N48   , Gn3 , v084
	.byte	W24
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		BEND  , c_v-21
	.byte		N48   , Gn3 , v048
	.byte	W06
	.byte		BEND  , c_v-23
	.byte	W06
	.byte		        c_v-25
	.byte	W02
	.byte		        c_v-28
	.byte	W03
	.byte		        c_v-30
	.byte	W03
	.byte		        c_v-34
	.byte	W04
	.byte		        c_v-36
	.byte	W02
	.byte		        c_v-39
	.byte	W03
	.byte		        c_v-41
	.byte	W03
	.byte		        c_v-43
	.byte	W04
	.byte		        c_v-46
	.byte	W02
	.byte		        c_v-48
	.byte	W03
	.byte		        c_v-51
	.byte	W03
	.byte		        c_v-54
	.byte	W04
	.byte		        c_v+0
	.byte	W24
	.byte	W24
	.byte		N48   , Gn2 , v127
	.byte	W24
	.byte		BEND  , c_v-2
	.byte	W02
	.byte		        c_v-3
	.byte	W03
	.byte		        c_v-5
	.byte	W03
	.byte		        c_v-8
	.byte	W04
	.byte		        c_v-9
	.byte	W02
	.byte		        c_v-11
	.byte	W03
	.byte		        c_v-12
	.byte	W03
	.byte		        c_v-14
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		BEND  , c_v+0
	.byte		N48   , Gn2 , v096
	.byte	W21
	.byte		BEND  , c_v-5
	.byte	W03
	.byte	W02
	.byte		        c_v-10
	.byte	W03
	.byte		        c_v-13
	.byte	W03
	.byte		        c_v-18
	.byte	W04
	.byte		        c_v-23
	.byte	W02
	.byte		        c_v-28
	.byte	W03
	.byte		        c_v-30
	.byte	W03
	.byte		        c_v-35
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		BEND  , c_v+0
	.byte		N24   , As2 , v112
	.byte	W24
	.byte		BEND  , c_v-3
	.byte		N24   , Fn2 
	.byte	W02
	.byte		BEND  , c_v-7
	.byte	W03
	.byte		        c_v-9
	.byte	W03
	.byte		        c_v-12
	.byte	W04
	.byte		        c_v-17
	.byte	W02
	.byte		        c_v-21
	.byte	W03
	.byte		        c_v-23
	.byte	W03
	.byte		        c_v-29
	.byte	W04
	.byte		PAN   , c_v+31
	.byte		BEND  , c_v+0
	.byte		N24   , As2 , v096
	.byte	W24
	.byte		BEND  , c_v-3
	.byte		N24   , Fn2 , v092
	.byte	W02
	.byte		BEND  , c_v-7
	.byte	W03
	.byte		        c_v-9
	.byte	W03
	.byte		        c_v-12
	.byte	W04
	.byte		        c_v-17
	.byte	W02
	.byte		        c_v-21
	.byte	W03
	.byte		        c_v-23
	.byte	W03
	.byte		        c_v-29
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		BEND  , c_v+0
	.byte		N24   , As2 , v080
	.byte	W24
	.byte		BEND  , c_v-3
	.byte		N24   , Fn2 
	.byte	W02
	.byte		BEND  , c_v-7
	.byte	W03
	.byte		        c_v-9
	.byte	W03
	.byte		        c_v-12
	.byte	W04
	.byte		        c_v-17
	.byte	W02
	.byte		        c_v-21
	.byte	W03
	.byte		        c_v-23
	.byte	W03
	.byte		        c_v-29
	.byte	W04
	.byte		PAN   , c_v+31
	.byte		BEND  , c_v+0
	.byte		N24   , As2 , v072
	.byte	W24
	.byte		BEND  , c_v-3
	.byte		N24   , Fn2 , v060
	.byte	W02
	.byte		BEND  , c_v-7
	.byte	W03
	.byte		        c_v-9
	.byte	W03
	.byte		        c_v-12
	.byte	W04
	.byte		        c_v-17
	.byte	W02
	.byte		        c_v-21
	.byte	W03
	.byte		        c_v-23
	.byte	W03
	.byte		        c_v-29
	.byte	W04
	.byte		        c_v+0
	.byte	W72
	.byte	W96
	.byte	W24
	.byte		N72   , As3 , v112
	.byte	W06
	.byte		BEND  , c_v-32
	.byte	W03
	.byte		        c_v+12
	.byte	W03
	.byte		        c_v+0
	.byte	W24
	.byte		        c_v-6
	.byte	W02
	.byte		        c_v-8
	.byte	W03
	.byte		        c_v-9
	.byte	W03
	.byte		        c_v-16
	.byte	W06
	.byte		        c_v-18
	.byte	W03
	.byte		        c_v-24
	.byte	W03
	.byte		        c_v-30
	.byte	W04
	.byte		        c_v-34
	.byte	W02
	.byte		        c_v-42
	.byte	W03
	.byte		        c_v-44
	.byte	W07
	.byte		        c_v+0
	.byte		N48   , As2 
	.byte	W06
	.byte		BEND  , c_v-22
	.byte	W03
	.byte		        c_v+18
	.byte	W06
	.byte		        c_v+0
	.byte	W32
	.byte	W01
	.byte		N48   , Fs3 
	.byte	W48
	.byte		N24   , Ds3 
	.byte	W24
	.byte		VOL   , 61*mus_m_dungon_mvl/mxv
	.byte		N48   , As3 
	.byte	W48
	.byte		BEND  , c_v-4
	.byte		N48   , Bn3 
	.byte	W02
	.byte		BEND  , c_v-6
	.byte	W03
	.byte		        c_v-8
	.byte	W03
	.byte		        c_v-9
	.byte	W06
	.byte		        c_v-11
	.byte	W06
	.byte		        c_v-13
	.byte	W04
	.byte		        c_v-15
	.byte	W02
	.byte		        c_v-18
	.byte	W03
	.byte		        c_v-24
	.byte	W03
	.byte		        c_v-36
	.byte	W04
	.byte		        c_v-42
	.byte	W02
	.byte		        c_v-46
	.byte	W10
	.byte		        c_v+0
	.byte		N24   , Dn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		N48   , As4 
	.byte	W06
	.byte		VOL   , 61*mus_m_dungon_mvl/mxv
	.byte	W06
	.byte		        58*mus_m_dungon_mvl/mxv
	.byte	W05
	.byte		        51*mus_m_dungon_mvl/mxv
	.byte	W07
	.byte		        47*mus_m_dungon_mvl/mxv
	.byte	W05
	.byte		        39*mus_m_dungon_mvl/mxv
	.byte	W07
	.byte		        27*mus_m_dungon_mvl/mxv
	.byte	W05
	.byte		        15*mus_m_dungon_mvl/mxv
	.byte	W07
	.byte		        2*mus_m_dungon_mvl/mxv
	.byte	W24
	.byte		        63*mus_m_dungon_mvl/mxv
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_m_dungon_10_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_m_dungon:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_m_dungon_pri	@ Priority
	.byte	mus_m_dungon_rev	@ Reverb.

	.word	mus_m_dungon_grp

	.word	mus_m_dungon_1
	.word	mus_m_dungon_2
	.word	mus_m_dungon_3
	.word	mus_m_dungon_4
	.word	mus_m_dungon_5
	.word	mus_m_dungon_6
	.word	mus_m_dungon_7
	.word	mus_m_dungon_8
	.word	mus_m_dungon_9
	.word	mus_m_dungon_10

	.end
