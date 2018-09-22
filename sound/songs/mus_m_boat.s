	.include "MPlayDef.s"

	.equ	mus_m_boat_grp, voicegroup077
	.equ	mus_m_boat_pri, 0
	.equ	mus_m_boat_rev, reverb_set+50
	.equ	mus_m_boat_mvl, 127
	.equ	mus_m_boat_key, 0
	.equ	mus_m_boat_tbs, 1
	.equ	mus_m_boat_exg, 0
	.equ	mus_m_boat_cmp, 1

	.section .rodata
	.global	mus_m_boat
	.align	2

@********************** Track  1 **********************@

mus_m_boat_1:
	.byte	KEYSH , mus_m_boat_key+0
	.byte	TEMPO , 156*mus_m_boat_tbs/2
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		VOL   , 9*mus_m_boat_mvl/mxv
	.byte		TIE   , Gn5 , v112
	.byte	W96
	.byte		VOL   , 27*mus_m_boat_mvl/mxv
	.byte	W96
	.byte		        43*mus_m_boat_mvl/mxv
	.byte	W48
	.byte		EOT   
	.byte		N08   , Gn4 
	.byte	W08
	.byte		        Gn4 , v088
	.byte	W08
	.byte		        Gn4 , v072
	.byte	W08
	.byte		        Gn4 , v056
	.byte	W08
	.byte		        Gn4 , v036
	.byte	W08
	.byte		        Gn4 , v028
	.byte	W08
	.byte		VOL   , 31*mus_m_boat_mvl/mxv
	.byte		N09   , Cn4 , v084
	.byte	W36
	.byte		N03   , En3 , v064
	.byte	W06
	.byte		        En3 , v076
	.byte	W06
	.byte		N06   , Cn4 , v096
	.byte	W24
	.byte		N09   , Cn5 , v127
	.byte	W12
	.byte		N12   , Gn5 , v112
	.byte	W12
mus_m_boat_1_B1:
	.byte		VOICE , 127
	.byte		PAN   , c_v+63
	.byte		VOL   , 35*mus_m_boat_mvl/mxv
	.byte		N03   , En5 , v112
	.byte	W06
	.byte		        En5 , v060
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v112
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , En5 
	.byte	W12
	.byte		        En5 , v064
	.byte	W12
	.byte		        En5 , v112
	.byte	W12
	.byte		        En5 , v068
	.byte	W12
	.byte		        En5 , v112
	.byte	W06
	.byte		        En5 , v072
	.byte	W06
	.byte		        En5 , v100
	.byte	W06
	.byte		        En5 , v064
	.byte	W06
mus_m_boat_1_000:
	.byte		N03   , En5 , v112
	.byte	W06
	.byte		        En5 , v060
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v112
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , En5 
	.byte	W12
	.byte		        En5 , v064
	.byte	W12
	.byte		        En5 , v112
	.byte	W12
	.byte		        En5 , v068
	.byte	W12
	.byte		        En5 , v112
	.byte	W06
	.byte		        En5 , v072
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v100
	.byte	W12
	.byte	PEND
	.byte		VOICE , 127
	.byte		N03   , En5 , v112
	.byte	W06
	.byte		        En5 , v060
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v112
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , En5 
	.byte	W12
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v104
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , En5 , v112
	.byte	W12
	.byte		        En5 , v068
	.byte	W12
	.byte		        En5 , v112
	.byte	W06
	.byte		        En5 , v072
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v100
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , En5 , v112
	.byte	W06
	.byte		        En5 , v060
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v112
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , En5 
	.byte	W12
	.byte		        En5 , v064
	.byte	W12
	.byte		        En5 , v112
	.byte	W12
	.byte		        En5 , v068
	.byte	W12
	.byte		        En5 , v112
	.byte	W06
	.byte		        En5 , v072
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v100
	.byte	W12
mus_m_boat_1_001:
	.byte		VOICE , 127
	.byte		N03   , En5 , v112
	.byte	W06
	.byte		        En5 , v060
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v112
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , En5 
	.byte	W12
	.byte		        En5 , v064
	.byte	W12
	.byte		        En5 , v112
	.byte	W12
	.byte		        En5 , v068
	.byte	W12
	.byte		        En5 , v112
	.byte	W06
	.byte		        En5 , v072
	.byte	W06
	.byte		        En5 , v100
	.byte	W06
	.byte		        En5 , v064
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_m_boat_1_000
	.byte	PATT
	 .word	mus_m_boat_1_001
	.byte		VOICE , 127
	.byte		N03   , En5 , v112
	.byte	W06
	.byte		        En5 , v060
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v112
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , En5 
	.byte	W12
	.byte		VOICE , 126
	.byte		N12   , Gn5 
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , En5 
	.byte	W12
	.byte		        En5 , v068
	.byte	W12
	.byte		        En5 , v112
	.byte	W06
	.byte		        En5 , v072
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v108
	.byte	W12
	.byte	PATT
	 .word	mus_m_boat_1_001
	.byte	PATT
	 .word	mus_m_boat_1_000
	.byte	PATT
	 .word	mus_m_boat_1_001
	.byte		N03   , En5 , v112
	.byte	W06
	.byte		        En5 , v060
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v112
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , En5 
	.byte	W12
	.byte		        En5 , v064
	.byte	W12
	.byte		        En5 , v112
	.byte	W12
	.byte		VOICE , 126
	.byte		N12   , Gn5 
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , En5 
	.byte	W06
	.byte		        En5 , v072
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v100
	.byte	W12
	.byte	PATT
	 .word	mus_m_boat_1_001
	.byte	PATT
	 .word	mus_m_boat_1_000
	.byte	PATT
	 .word	mus_m_boat_1_001
	.byte	PATT
	 .word	mus_m_boat_1_000
	.byte	GOTO
	 .word	mus_m_boat_1_B1
	.byte	W96
	.byte	FINE

@********************** Track  2 **********************@

mus_m_boat_2:
	.byte	KEYSH , mus_m_boat_key+0
	.byte		VOICE , 46
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+3
	.byte		VOL   , 69*mus_m_boat_mvl/mxv
	.byte	W12
	.byte		N06   , Gs3 , v112
	.byte	W06
	.byte		        Gs3 , v036
	.byte	W06
	.byte		        Bn3 , v112
	.byte	W06
	.byte		        Bn3 , v036
	.byte	W06
	.byte		        Ds4 , v112
	.byte	W06
	.byte		        Ds4 , v036
	.byte	W06
	.byte		        Gs4 , v112
	.byte	W06
	.byte		        Gs4 , v036
	.byte	W54
	.byte		        As3 , v112
	.byte	W06
	.byte		        As3 , v036
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v036
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v036
	.byte	W06
	.byte		        As4 , v112
	.byte	W12
	.byte		N04   
	.byte	W04
	.byte		        As4 , v036
	.byte	W04
	.byte		        Cs5 , v112
	.byte	W04
	.byte		        Cs5 , v036
	.byte	W04
	.byte		        As4 , v112
	.byte	W04
	.byte		        As4 , v036
	.byte	W04
	.byte		        Fn4 , v112
	.byte	W04
	.byte		        Fn4 , v036
	.byte	W04
	.byte		        As4 , v112
	.byte	W04
	.byte		        As4 , v036
	.byte	W04
	.byte		        Fn4 , v112
	.byte	W04
	.byte		        Fn4 , v036
	.byte	W04
	.byte		N06   , Bn3 , v112
	.byte	W06
	.byte		        Bn3 , v036
	.byte	W06
	.byte		        Ds4 , v112
	.byte	W06
	.byte		        Ds4 , v036
	.byte	W06
	.byte		        Fs4 , v112
	.byte	W06
	.byte		        Fs4 , v036
	.byte	W06
	.byte		        Bn4 , v112
	.byte	W06
	.byte		        Bn4 , v036
	.byte	W06
	.byte		N04   , Cn5 , v112
	.byte	W04
	.byte		        Cn5 , v036
	.byte	W04
	.byte		        Gs4 , v112
	.byte	W04
	.byte		        Gs4 , v036
	.byte	W04
	.byte		        Fs4 , v112
	.byte	W04
	.byte		        Fs4 , v036
	.byte	W04
	.byte		        Ds4 , v112
	.byte	W04
	.byte		        Ds4 , v036
	.byte	W04
	.byte		        Cn4 , v112
	.byte	W04
	.byte		        Cn4 , v036
	.byte	W04
	.byte		        Gs3 , v112
	.byte	W04
	.byte		        Gs3 , v036
	.byte	W04
	.byte		N06   , Gs2 , v112
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
mus_m_boat_2_B1:
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
	 .word	mus_m_boat_2_B1
	.byte	W96
	.byte	FINE

@********************** Track  3 **********************@

mus_m_boat_3:
	.byte	KEYSH , mus_m_boat_key+0
	.byte		VOICE , 35
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 86*mus_m_boat_mvl/mxv
	.byte		N03   , Cn1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
mus_m_boat_3_000:
	.byte		N84   , Cs1 , v127
	.byte	W84
	.byte		N03   , Cn1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_m_boat_3_000
	.byte		N36   , Cs1 , v127
	.byte	W36
	.byte		N03   , Gs0 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N18   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Cs1 , v127
	.byte	W12
	.byte		N06   , Cs1 , v036
	.byte	W12
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v036
	.byte	W06
	.byte		N02   , Cs1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cs2 
	.byte	W03
	.byte		N06   , Cs2 , v036
	.byte	W09
	.byte		        Cs1 , v112
	.byte	W06
	.byte		        Cs1 , v036
	.byte	W06
	.byte		N03   , Cs2 , v112
	.byte	W03
	.byte		N06   , Cs2 , v036
	.byte	W09
mus_m_boat_3_B1:
mus_m_boat_3_001:
	.byte		N06   , Bn0 , v127
	.byte	W06
	.byte		        Bn0 , v036
	.byte	W06
	.byte		N03   , Bn1 , v112
	.byte	W03
	.byte		N06   , Bn1 , v036
	.byte	W09
	.byte		        Bn0 , v112
	.byte	W06
	.byte		        Bn0 , v036
	.byte	W06
	.byte		N03   , Bn1 , v112
	.byte	W03
	.byte		N06   , Bn1 , v036
	.byte	W09
	.byte		N03   , Bn0 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Bn1 
	.byte	W03
	.byte		N06   , Bn1 , v036
	.byte	W09
	.byte		        Bn0 , v112
	.byte	W06
	.byte		        Bn0 , v036
	.byte	W06
	.byte		N03   , Bn1 , v112
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte	PEND
mus_m_boat_3_002:
	.byte		N06   , Cs1 , v127
	.byte	W06
	.byte		        Cs1 , v036
	.byte	W06
	.byte		N03   , Cs2 , v112
	.byte	W03
	.byte		N06   , Cs2 , v036
	.byte	W09
	.byte		        Gs1 , v112
	.byte	W06
	.byte		        Gs1 , v036
	.byte	W06
	.byte		N03   , Cs2 , v112
	.byte	W03
	.byte		N06   , Cs2 , v036
	.byte	W09
	.byte		N03   , Cs1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cs2 
	.byte	W03
	.byte		N06   , Cs2 , v036
	.byte	W09
	.byte		        Gs1 , v112
	.byte	W06
	.byte		        Gs1 , v036
	.byte	W06
	.byte		N03   , Cs2 , v112
	.byte	W03
	.byte		N06   , Cs2 , v036
	.byte	W09
	.byte	PEND
mus_m_boat_3_003:
	.byte		N06   , As0 , v127
	.byte	W06
	.byte		        As0 , v036
	.byte	W06
	.byte		N03   , As1 , v112
	.byte	W03
	.byte		N06   , As1 , v036
	.byte	W09
	.byte		        As0 , v112
	.byte	W06
	.byte		        As0 , v036
	.byte	W06
	.byte		N03   , As1 , v112
	.byte	W03
	.byte		N06   , As1 , v036
	.byte	W09
	.byte		        As0 , v112
	.byte	W06
	.byte		        As0 , v036
	.byte	W06
	.byte		N03   , As1 , v112
	.byte	W03
	.byte		N06   , As1 , v036
	.byte	W09
	.byte		        Fn1 , v112
	.byte	W06
	.byte		        Fn1 , v036
	.byte	W06
	.byte		N03   , As1 , v112
	.byte	W03
	.byte		N06   , As1 , v036
	.byte	W09
	.byte	PEND
mus_m_boat_3_004:
	.byte		N06   , Ds1 , v127
	.byte	W06
	.byte		        Ds1 , v036
	.byte	W06
	.byte		N03   , Ds2 , v112
	.byte	W03
	.byte		N06   , Ds2 , v036
	.byte	W09
	.byte		        Cs1 , v112
	.byte	W06
	.byte		        Cs1 , v036
	.byte	W06
	.byte		N03   , Cs2 , v112
	.byte	W03
	.byte		N06   , Cs2 , v036
	.byte	W09
	.byte		        Bn0 , v112
	.byte	W06
	.byte		        Bn0 , v036
	.byte	W06
	.byte		N03   , Bn1 , v112
	.byte	W03
	.byte		N06   , Bn1 , v036
	.byte	W09
	.byte		        As0 , v112
	.byte	W06
	.byte		        As0 , v036
	.byte	W06
	.byte		N03   , As1 , v112
	.byte	W03
	.byte		N06   , As1 , v036
	.byte	W09
	.byte	PEND
mus_m_boat_3_005:
	.byte		N06   , Gs0 , v127
	.byte	W06
	.byte		        Gs0 , v036
	.byte	W06
	.byte		N03   , Gs1 , v112
	.byte	W03
	.byte		N06   , Gs1 , v036
	.byte	W09
	.byte		        Ds1 , v112
	.byte	W06
	.byte		        Ds1 , v036
	.byte	W06
	.byte		N03   , Gs1 , v112
	.byte	W03
	.byte		N06   , Gs1 , v036
	.byte	W09
	.byte		N03   , Gs0 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Gs1 
	.byte	W03
	.byte		N06   , Gs1 , v036
	.byte	W09
	.byte		        Ds1 , v112
	.byte	W06
	.byte		        Ds1 , v036
	.byte	W06
	.byte		N03   , Gs1 , v112
	.byte	W03
	.byte		N06   , Gs1 , v036
	.byte	W09
	.byte	PEND
	.byte		        Cs1 , v127
	.byte	W06
	.byte		        Cs1 , v036
	.byte	W06
	.byte		N03   , Cs2 , v112
	.byte	W03
	.byte		N06   , Cs2 , v036
	.byte	W09
	.byte		        Gs1 , v112
	.byte	W06
	.byte		        Gs1 , v036
	.byte	W06
	.byte		N03   , Cs2 , v112
	.byte	W03
	.byte		N06   , Cs2 , v036
	.byte	W09
	.byte		N03   , Cs1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cs2 
	.byte	W03
	.byte		N06   , Cs2 , v036
	.byte	W09
	.byte		        Cs1 , v112
	.byte	W06
	.byte		        Cs1 , v036
	.byte	W06
	.byte		N03   , Cs2 , v112
	.byte	W03
	.byte		N06   , Cs2 , v036
	.byte	W09
	.byte		        As0 , v127
	.byte	W06
	.byte		        As0 , v036
	.byte	W06
	.byte		N03   , As1 , v112
	.byte	W03
	.byte		N06   , As1 , v036
	.byte	W09
	.byte		        Fn1 , v112
	.byte	W06
	.byte		        Fn1 , v036
	.byte	W06
	.byte		N03   , As1 , v112
	.byte	W03
	.byte		N06   , As1 , v036
	.byte	W09
	.byte		N03   , As0 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        As1 
	.byte	W03
	.byte		N06   , As1 , v036
	.byte	W09
	.byte		        Fn1 , v112
	.byte	W06
	.byte		        Fn1 , v036
	.byte	W06
	.byte		N03   , As1 , v112
	.byte	W03
	.byte		N06   , As1 , v036
	.byte	W09
	.byte		        Ds1 , v127
	.byte	W06
	.byte		        Ds1 , v036
	.byte	W06
	.byte		N03   , Ds2 , v112
	.byte	W03
	.byte		N06   , Ds2 , v036
	.byte	W09
	.byte		        Cs1 , v112
	.byte	W06
	.byte		        Cs1 , v036
	.byte	W06
	.byte		N03   , Cs2 , v112
	.byte	W03
	.byte		N06   , Cs2 , v036
	.byte	W09
	.byte		N03   , Bn0 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Bn1 
	.byte	W03
	.byte		N06   , Bn1 , v036
	.byte	W09
	.byte		        As0 , v112
	.byte	W06
	.byte		        As0 , v036
	.byte	W06
	.byte		N03   , As1 , v112
	.byte	W03
	.byte		N06   , As1 , v036
	.byte	W09
	.byte	PATT
	 .word	mus_m_boat_3_001
	.byte	PATT
	 .word	mus_m_boat_3_002
	.byte	PATT
	 .word	mus_m_boat_3_003
	.byte	PATT
	 .word	mus_m_boat_3_004
	.byte	PATT
	 .word	mus_m_boat_3_005
	.byte		N06   , Gs0 , v127
	.byte	W06
	.byte		        Gs0 , v036
	.byte	W06
	.byte		N03   , Gs1 , v112
	.byte	W03
	.byte		N06   , Gs1 , v036
	.byte	W09
	.byte		        Ds1 , v112
	.byte	W06
	.byte		        Ds1 , v036
	.byte	W06
	.byte		N03   , Gs1 , v112
	.byte	W03
	.byte		N06   , Gs1 , v036
	.byte	W09
	.byte		N03   , Gs0 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Gs1 
	.byte	W03
	.byte		N06   , Gs1 , v036
	.byte	W09
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Cn1 , v036
	.byte	W06
	.byte		N03   , Gs1 , v112
	.byte	W03
	.byte		N06   , Gs1 , v036
	.byte	W09
	.byte	PATT
	 .word	mus_m_boat_3_002
	.byte		N06   , Cs2 , v127
	.byte	W06
	.byte		        Cs2 , v036
	.byte	W18
	.byte		N03   , Cs1 , v112
	.byte	W03
	.byte		N06   , Cs1 , v036
	.byte	W21
	.byte		N03   , Gs1 , v112
	.byte	W03
	.byte		N06   , Gs1 , v036
	.byte	W21
	.byte		        Fn1 , v112
	.byte	W06
	.byte		        Fn1 , v036
	.byte	W12
	.byte		        As0 , v112
	.byte	W06
	.byte	GOTO
	 .word	mus_m_boat_3_B1
	.byte	W96
	.byte	FINE

@********************** Track  4 **********************@

mus_m_boat_4:
	.byte	KEYSH , mus_m_boat_key+0
	.byte		VOICE , 17
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 32*mus_m_boat_mvl/mxv
	.byte		N03   , Gn4 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N84   , Gs4 
	.byte	W84
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N84   , As4 
	.byte	W84
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N36   , Bn4 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N36   , Cn5 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N32   , Cs5 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   
	.byte	W24
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
mus_m_boat_4_B1:
	.byte		N36   , Ds5 , v112
	.byte	W36
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N06   , Bn4 
	.byte	W12
	.byte		N36   , Ds5 
	.byte	W36
mus_m_boat_4_000:
	.byte		N36   , Fn5 , v112
	.byte	W36
	.byte		N06   , Fs5 
	.byte	W12
	.byte		N03   , Bn5 , v080
	.byte	W03
	.byte		N09   , As5 , v112
	.byte	W09
	.byte		N36   , Gs5 
	.byte	W36
	.byte	PEND
	.byte		N96   , Cs5 
	.byte	W96
	.byte		N36   , Ds5 
	.byte	W36
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N03   , Gn5 , v072
	.byte	W03
	.byte		N09   , Fs5 , v112
	.byte	W09
	.byte		N36   , Ds5 
	.byte	W36
	.byte		        Bn4 
	.byte	W36
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N36   , Bn4 
	.byte	W36
	.byte		        Cs5 
	.byte	W36
	.byte		N06   , Ds5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		N24   , Ds5 
	.byte	W24
	.byte		N12   , Cs5 
	.byte	W12
	.byte		N84   , As4 
	.byte	W84
	.byte		N03   , Bn4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		N36   , Ds5 
	.byte	W36
	.byte		N12   , Cs5 
	.byte	W12
	.byte		N06   , Bn4 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N03   , Cs5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		N30   , Ds5 
	.byte	W30
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N06   , Bn4 
	.byte	W12
	.byte		N36   , Ds5 
	.byte	W36
	.byte	PATT
	 .word	mus_m_boat_4_000
	.byte		N36   , As5 , v112
	.byte	W36
	.byte		N06   , Fn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		N24   , Gs5 
	.byte	W24
	.byte		N12   , An5 
	.byte	W12
	.byte		N24   , As5 , v096
	.byte	W24
	.byte		        Gs5 , v092
	.byte	W24
	.byte		N12   , Gn5 , v088
	.byte	W12
	.byte		N06   , Gs5 
	.byte	W06
	.byte		        Gn5 , v080
	.byte	W06
	.byte		N24   , Ds5 , v088
	.byte	W24
	.byte		N36   , Bn5 , v096
	.byte	W36
	.byte		N12   , Gs5 
	.byte	W12
	.byte		N06   , As5 
	.byte	W12
	.byte		N36   , Bn5 , v112
	.byte	W36
	.byte		        Cn6 , v096
	.byte	W36
	.byte		N06   , Gs5 , v112
	.byte	W12
	.byte		        Ds6 , v092
	.byte	W18
	.byte		        Cs6 , v088
	.byte	W18
	.byte		N12   , Cn6 
	.byte	W12
	.byte		N32   , Cs6 , v092
	.byte	W36
	.byte		N03   , Cs6 , v088
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N32   , Cs6 , v096
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		        Cs6 , v092
	.byte	W06
	.byte		N06   , Cs6 , v112
	.byte	W48
	.byte		N06   
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte	GOTO
	 .word	mus_m_boat_4_B1
	.byte	W96
	.byte	FINE

@********************** Track  5 **********************@

mus_m_boat_5:
	.byte	KEYSH , mus_m_boat_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-22
	.byte		VOL   , 39*mus_m_boat_mvl/mxv
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_m_boat_5_B1:
	.byte		N02   , Fs3 , v112
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N02   , Bn3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N02   , Bn3 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N02   , Bn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N05   , Fn4 
	.byte	W06
	.byte		N02   , Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N05   , Ds4 
	.byte	W06
	.byte		N02   , Gs3 
	.byte	W06
	.byte		N05   , Fs4 
	.byte	W06
	.byte		N02   , Gs3 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N02   , Gs3 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N02   , Gs3 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N02   , Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N02   , As3 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N02   , As3 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N02   , As3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N02   , Fs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N05   , Fs4 
	.byte	W06
	.byte		N02   , Bn3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N02   , Bn3 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N02   , Bn3 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N02   , Bn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N05   , Gs4 
	.byte	W06
	.byte		N02   , Gs3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N02   , Gs3 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N02   , Gs3 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N02   , Gs3 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N05   , Gs4 
	.byte	W06
	.byte		N02   , As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N02   , As3 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N02   , As3 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N02   , As3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N06   , Bn4 
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N06   , As4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N06   , Cn5 
	.byte	W06
	.byte		N03   , Cn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W54
	.byte	GOTO
	 .word	mus_m_boat_5_B1
	.byte	W96
	.byte	FINE

@********************** Track  6 **********************@

mus_m_boat_6:
	.byte	KEYSH , mus_m_boat_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-61
	.byte		VOL   , 38*mus_m_boat_mvl/mxv
	.byte	W12
	.byte		N96   , Bn2 , v112
	.byte	W96
	.byte		        Cs3 
	.byte	W96
	.byte		N48   , Ds3 
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte		N32   , Gs3 
	.byte	W12
	.byte		VOL   , 35*mus_m_boat_mvl/mxv
	.byte	W05
	.byte		        43*mus_m_boat_mvl/mxv
	.byte	W07
	.byte		        48*mus_m_boat_mvl/mxv
	.byte	W12
	.byte		N03   , Cs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   
	.byte	W06
	.byte		VOL   , 36*mus_m_boat_mvl/mxv
	.byte	W06
	.byte		        43*mus_m_boat_mvl/mxv
	.byte	W05
	.byte		        49*mus_m_boat_mvl/mxv
	.byte	W30
	.byte	W01
mus_m_boat_6_B1:
	.byte		VOL   , 39*mus_m_boat_mvl/mxv
	.byte		N24   , Bn2 , v112
	.byte	W24
	.byte		        Ds2 
	.byte	W24
	.byte		        Fs2 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		N36   , Fn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N06   , Cs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N36   , Gs3 
	.byte	W36
	.byte		VOL   , 35*mus_m_boat_mvl/mxv
	.byte		N24   
	.byte	W24
	.byte		VOL   , 49*mus_m_boat_mvl/mxv
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		VOL   , 39*mus_m_boat_mvl/mxv
	.byte		N36   , Bn2 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N06   , Fs2 
	.byte	W12
	.byte		N24   , Ds3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		N36   , Ds3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N06   , Bn2 
	.byte	W12
	.byte		VOL   , 46*mus_m_boat_mvl/mxv
	.byte		N06   , Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Cs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		VOL   , 39*mus_m_boat_mvl/mxv
	.byte		N36   
	.byte	W12
	.byte		MOD   , 8
	.byte	W21
	.byte		N06   , Gs2 
	.byte	W03
	.byte		MOD   , 0
	.byte	W12
	.byte		N06   , Bn2 
	.byte	W12
	.byte		N24   , Cs3 
	.byte	W24
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N24   , Fn2 
	.byte	W24
	.byte		VOL   , 46*mus_m_boat_mvl/mxv
	.byte		N24   , Cs3 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		VOL   , 39*mus_m_boat_mvl/mxv
	.byte		N24   , Fs2 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		VOL   , 46*mus_m_boat_mvl/mxv
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		VOL   , 39*mus_m_boat_mvl/mxv
	.byte		N24   , Bn2 
	.byte	W24
	.byte		        Ds2 
	.byte	W24
	.byte		        Fs2 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		VOL   , 44*mus_m_boat_mvl/mxv
	.byte		N36   , Fn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N06   , Cs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N36   , Gs3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N72   
	.byte	W24
	.byte		MOD   , 6
	.byte	W48
	.byte		        0
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		VOL   , 39*mus_m_boat_mvl/mxv
	.byte		N24   , Ds3 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		VOL   , 46*mus_m_boat_mvl/mxv
	.byte		N24   , As3 
	.byte	W24
	.byte		VOL   , 39*mus_m_boat_mvl/mxv
	.byte		N36   , Ds4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W12
	.byte		VOL   , 47*mus_m_boat_mvl/mxv
	.byte		N24   , Ds4 
	.byte	W24
	.byte		VOL   , 39*mus_m_boat_mvl/mxv
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N36   , Cn4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N06   , Ds3 
	.byte	W12
	.byte		VOL   , 46*mus_m_boat_mvl/mxv
	.byte		N06   , Cn4 
	.byte	W18
	.byte		        As3 
	.byte	W18
	.byte		N12   , Gs3 
	.byte	W12
	.byte		VOL   , 45*mus_m_boat_mvl/mxv
	.byte		N30   , Fn3 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N32   , Ds3 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOL   , 39*mus_m_boat_mvl/mxv
	.byte		N06   , Cs3 
	.byte	W48
	.byte		        Gs2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		N12   , Dn3 
	.byte	W12
	.byte	GOTO
	 .word	mus_m_boat_6_B1
	.byte	W96
	.byte	FINE

@********************** Track  7 **********************@

mus_m_boat_7:
	.byte	KEYSH , mus_m_boat_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 37*mus_m_boat_mvl/mxv
	.byte	W12
	.byte		N96   , Ds3 , v112
	.byte	W96
	.byte		        Fn3 
	.byte	W96
	.byte		N48   , Fs3 
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte		N32   , Cs3 
	.byte	W12
	.byte		VOL   , 35*mus_m_boat_mvl/mxv
	.byte	W05
	.byte		        43*mus_m_boat_mvl/mxv
	.byte	W07
	.byte		        48*mus_m_boat_mvl/mxv
	.byte	W12
	.byte		N03   , Gs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   
	.byte	W06
	.byte		VOL   , 36*mus_m_boat_mvl/mxv
	.byte	W06
	.byte		        43*mus_m_boat_mvl/mxv
	.byte	W05
	.byte		        49*mus_m_boat_mvl/mxv
	.byte	W30
	.byte	W01
mus_m_boat_7_B1:
	.byte		VOL   , 39*mus_m_boat_mvl/mxv
	.byte		N24   , Ds3 , v112
	.byte	W24
	.byte		        Fs2 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		N36   , Cs4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N06   , Fn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N36   , Bn3 
	.byte	W36
	.byte		VOL   , 35*mus_m_boat_mvl/mxv
	.byte		N24   , As3 
	.byte	W24
	.byte		VOL   , 48*mus_m_boat_mvl/mxv
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		VOL   , 39*mus_m_boat_mvl/mxv
	.byte		N36   , Ds3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N06   , Bn2 
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		N36   , Bn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N06   , Fs3 
	.byte	W12
	.byte		VOL   , 46*mus_m_boat_mvl/mxv
	.byte		N06   , Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W12
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		VOL   , 39*mus_m_boat_mvl/mxv
	.byte		N36   , Gs3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N06   , Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N24   , Cs3 
	.byte	W24
	.byte		VOL   , 46*mus_m_boat_mvl/mxv
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		VOL   , 39*mus_m_boat_mvl/mxv
	.byte		N24   , Ds3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		VOL   , 46*mus_m_boat_mvl/mxv
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		VOL   , 39*mus_m_boat_mvl/mxv
	.byte		N24   , Ds3 
	.byte	W24
	.byte		        Fs2 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		VOL   , 44*mus_m_boat_mvl/mxv
	.byte		N36   , Cs4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N06   , Fn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N36   , Bn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N72   , Cs4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W48
	.byte		        0
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		VOL   , 39*mus_m_boat_mvl/mxv
	.byte		N24   , As3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		VOL   , 46*mus_m_boat_mvl/mxv
	.byte		N24   , Ds4 
	.byte	W24
	.byte		VOL   , 39*mus_m_boat_mvl/mxv
	.byte		N36   , Fs4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W12
	.byte		VOL   , 47*mus_m_boat_mvl/mxv
	.byte		N24   , Fs4 
	.byte	W24
	.byte		VOL   , 39*mus_m_boat_mvl/mxv
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N36   , Ds4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N06   , Fs3 
	.byte	W12
	.byte		VOL   , 46*mus_m_boat_mvl/mxv
	.byte		N06   , Ds4 
	.byte	W18
	.byte		        Cs4 
	.byte	W18
	.byte		N12   , Cn4 
	.byte	W12
	.byte		VOL   , 45*mus_m_boat_mvl/mxv
	.byte		N30   , Cs4 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N32   , Bn3 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOL   , 39*mus_m_boat_mvl/mxv
	.byte		N06   , Cs4 
	.byte	W48
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W24
	.byte	GOTO
	 .word	mus_m_boat_7_B1
	.byte	W96
	.byte	FINE

@********************** Track  8 **********************@

mus_m_boat_8:
	.byte	KEYSH , mus_m_boat_key+0
	.byte		VOICE , 82
	.byte		LFOS  , 28
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 30*mus_m_boat_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N03   , Gn4 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N84   , Gs4 
	.byte	W48
	.byte		MOD   , 4
	.byte	W36
	.byte		        0
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N84   , As4 
	.byte	W48
	.byte		MOD   , 4
	.byte	W36
	.byte		        0
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N36   , Bn4 
	.byte	W24
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N36   , Cn5 
	.byte	W24
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		MOD   , 0
	.byte		N32   , Cs5 
	.byte	W24
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
mus_m_boat_8_B1:
	.byte		N36   , Ds5 , v112
	.byte	W24
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N06   , Bn4 
	.byte	W12
	.byte		N36   , Ds5 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte	W12
	.byte		N36   , Fn5 
	.byte	W24
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , Fs5 
	.byte	W12
	.byte		N03   , Bn5 , v080
	.byte	W03
	.byte		N09   , As5 , v112
	.byte	W09
	.byte		N36   , Gs5 
	.byte	W36
	.byte		N96   , Cs5 
	.byte	W48
	.byte		MOD   , 5
	.byte	W48
	.byte		        0
	.byte		N36   , Ds5 
	.byte	W24
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N03   , Gn5 , v072
	.byte	W03
	.byte		N09   , Fs5 , v112
	.byte	W09
	.byte		N36   , Ds5 
	.byte	W24
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N36   , Bn4 
	.byte	W36
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N36   , Bn4 
	.byte	W24
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N36   , Cs5 
	.byte	W24
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , Ds5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		N24   , Ds5 
	.byte	W24
	.byte		N12   , Cs5 
	.byte	W12
	.byte		N84   , As4 
	.byte	W48
	.byte		MOD   , 6
	.byte	W36
	.byte		        0
	.byte		N03   , Bn4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		N36   , Ds5 
	.byte	W24
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N12   , Cs5 
	.byte	W12
	.byte		N06   , Bn4 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N03   , Cs5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		N30   , Ds5 
	.byte	W18
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N06   , Bn4 
	.byte	W12
	.byte		N36   , Ds5 
	.byte	W24
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N36   , Fn5 
	.byte	W24
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , Fs5 
	.byte	W12
	.byte		N03   , Bn5 , v080
	.byte	W03
	.byte		N09   , As5 , v112
	.byte	W09
	.byte		N36   , Gs5 
	.byte	W24
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N36   , As5 
	.byte	W24
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , Fn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		N24   , Gs5 
	.byte	W24
	.byte		N12   , An5 
	.byte	W12
	.byte		N24   , As5 
	.byte	W24
	.byte		        Gs5 
	.byte	W24
	.byte		N12   , Gn5 
	.byte	W12
	.byte		N06   , Gs5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		N24   , Ds5 
	.byte	W24
	.byte		N36   , Bn5 
	.byte	W24
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N12   , Gs5 
	.byte	W12
	.byte		N06   , As5 
	.byte	W12
	.byte		N36   , Bn5 
	.byte	W24
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N36   , Cn6 
	.byte	W24
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , Gs5 
	.byte	W12
	.byte		        Ds6 
	.byte	W18
	.byte		        Cs6 
	.byte	W18
	.byte		N12   , Cn6 
	.byte	W12
	.byte		N32   , Cs6 
	.byte	W24
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N32   
	.byte	W24
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W48
	.byte		N06   
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte	GOTO
	 .word	mus_m_boat_8_B1
	.byte	W96
	.byte	FINE

@********************** Track  9 **********************@

mus_m_boat_9:
	.byte	KEYSH , mus_m_boat_key+0
	.byte		VOICE , 73
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+19
	.byte		VOL   , 43*mus_m_boat_mvl/mxv
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N32   , Fn3 , v112
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   
	.byte	W24
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
mus_m_boat_9_B1:
mus_m_boat_9_000:
	.byte		N36   , Bn3 , v112
	.byte	W36
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W12
	.byte		N36   , Bn3 
	.byte	W36
	.byte	PEND
mus_m_boat_9_001:
	.byte		N36   , Cs4 , v112
	.byte	W36
	.byte		N06   , Ds4 
	.byte	W12
	.byte		N03   , Gn4 
	.byte	W03
	.byte		N09   , Fs4 
	.byte	W09
	.byte		N36   , Fn4 
	.byte	W36
	.byte	PEND
	.byte		N96   , As3 
	.byte	W96
	.byte		N36   , Fs3 
	.byte	W36
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N03   , Bn3 
	.byte	W03
	.byte		N09   , As3 
	.byte	W09
	.byte		N36   , Fs3 
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W12
	.byte		N36   , Gs3 
	.byte	W36
	.byte		        Fn3 
	.byte	W36
	.byte		N06   , Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W09
	.byte		N24   , Gs3 
	.byte	W24
	.byte	W03
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N72   , Fn3 
	.byte	W96
	.byte		N36   , As3 
	.byte	W36
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte	PATT
	 .word	mus_m_boat_9_000
	.byte	PATT
	 .word	mus_m_boat_9_001
	.byte		N36   , Fn4 , v112
	.byte	W36
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N24   , Fn4 
	.byte	W24
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N36   , Gs4 
	.byte	W36
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W12
	.byte		N24   , Gs4 
	.byte	W24
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N36   , Gs4 
	.byte	W36
	.byte		N06   , Cn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W18
	.byte		        Fn4 
	.byte	W18
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N32   , Gs4 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N32   , Fs4 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W48
	.byte		        Gs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W24
	.byte	GOTO
	 .word	mus_m_boat_9_B1
	.byte	W96
	.byte	FINE

@******************************************************@
	.align	2

mus_m_boat:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_m_boat_pri	@ Priority
	.byte	mus_m_boat_rev	@ Reverb.

	.word	mus_m_boat_grp

	.word	mus_m_boat_1
	.word	mus_m_boat_2
	.word	mus_m_boat_3
	.word	mus_m_boat_4
	.word	mus_m_boat_5
	.word	mus_m_boat_6
	.word	mus_m_boat_7
	.word	mus_m_boat_8
	.word	mus_m_boat_9

	.end
