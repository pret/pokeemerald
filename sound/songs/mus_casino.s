	.include "MPlayDef.s"

	.equ	mus_casino_grp, voicegroup_868A674
	.equ	mus_casino_pri, 0
	.equ	mus_casino_rev, reverb_set+50
	.equ	mus_casino_mvl, 127
	.equ	mus_casino_key, 0
	.equ	mus_casino_tbs, 1
	.equ	mus_casino_exg, 0
	.equ	mus_casino_cmp, 1

	.section .rodata
	.global	mus_casino
	.align	2

@********************** Track  1 **********************@

mus_casino_1:
	.byte	KEYSH , mus_casino_key+0
	.byte	TEMPO , 182*mus_casino_tbs/2
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 31*mus_casino_mvl/mxv
	.byte	W06
mus_casino_1_B1:
mus_casino_1_000:
	.byte		VOICE , 127
	.byte		N04   , En5 , v112
	.byte	W16
	.byte		        En5 , v064
	.byte	W08
	.byte		VOICE , 126
	.byte		N24   , Gs5 , v112
	.byte	W24
	.byte		VOICE , 127
	.byte		N04   , En5 
	.byte	W16
	.byte		        En5 , v064
	.byte	W08
	.byte		VOICE , 126
	.byte		N24   , Gs5 , v096
	.byte	W24
	.byte	PEND
mus_casino_1_001:
	.byte		VOICE , 127
	.byte		N04   , En5 , v112
	.byte	W16
	.byte		        En5 , v064
	.byte	W08
	.byte		VOICE , 126
	.byte		N24   , Gs5 , v096
	.byte	W24
	.byte		VOICE , 127
	.byte		N04   , En5 , v112
	.byte	W16
	.byte		        En5 , v064
	.byte	W08
	.byte		VOICE , 126
	.byte		N24   , Gs5 , v096
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte		N04   , En5 , v112
	.byte	W96
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte		VOICE , 127
	.byte		N04   , En5 , v112
	.byte	W16
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W16
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W16
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W16
	.byte		        En5 , v064
	.byte	W08
mus_casino_1_002:
	.byte		N04   , En5 , v112
	.byte	W08
	.byte		        En5 , v092
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W16
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W16
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W16
	.byte		        En5 , v064
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_casino_1_002
mus_casino_1_003:
	.byte		N04   , En5 , v112
	.byte	W16
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W08
	.byte		        En5 , v092
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W16
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W16
	.byte		        En5 , v064
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_casino_1_003
	.byte		N04   , En5 , v112
	.byte	W16
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W16
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W16
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W08
	.byte		        En5 , v092
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W16
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W16
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W16
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W16
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W16
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W16
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W08
	.byte		        En5 , v092
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W08
	.byte		        En5 , v092
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte	PATT
	 .word	mus_casino_1_000
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	PATT
	 .word	mus_casino_1_001
	.byte	GOTO
	 .word	mus_casino_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_casino_2:
	.byte	KEYSH , mus_casino_key+0
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 54*mus_casino_mvl/mxv
	.byte		PAN   , c_v-16
	.byte	W06
mus_casino_2_B1:
	.byte		VOICE , 1
	.byte		VOL   , 52*mus_casino_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N16   , As1 , v112
	.byte	W16
	.byte		N04   , Fn4 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		N08   , An4 
	.byte	W24
	.byte		        As4 , v084
	.byte	W08
	.byte		N24   , As1 , v112
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 48
	.byte		VOL   , 30*mus_casino_mvl/mxv
	.byte		N88   , Gn3 
	.byte	W88
	.byte		N08   , Gs3 
	.byte	W08
	.byte		N88   , As3 
	.byte	W88
	.byte		N08   , An3 
	.byte	W08
	.byte		N72   , Gs3 
	.byte	W72
	.byte		N16   , As3 
	.byte	W16
	.byte		N08   , Gs3 
	.byte	W08
	.byte		N48   , Gn3 
	.byte	W48
	.byte		        Fn3 
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		VOICE , 48
	.byte		VOL   , 14*mus_casino_mvl/mxv
	.byte		N04   , En4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		TIE   , As4 
	.byte	W96
	.byte	W44
	.byte		EOT   
	.byte		N04   , Bn4 
	.byte	W04
	.byte		N44   , Cn5 
	.byte	W22
	.byte		N04   , Ds4 
	.byte	W22
	.byte		        Bn4 
	.byte	W04
	.byte		N92   , As4 
	.byte	W92
	.byte		N04   , Bn4 
	.byte	W04
	.byte		N48   , Cn5 
	.byte	W48
	.byte		N04   , Cs5 
	.byte	W04
	.byte		N36   , Dn5 
	.byte	W36
	.byte		N08   , Gn4 
	.byte	W08
	.byte		N72   , As4 
	.byte	W72
	.byte		N16   
	.byte	W16
	.byte		N04   , Gs4 
	.byte	W08
	.byte		N48   , Fn4 
	.byte	W48
	.byte		        Gs4 
	.byte	W48
	.byte		TIE   , As4 
	.byte	W96
	.byte	W40
	.byte		EOT   
	.byte		N08   , Bn4 
	.byte	W08
	.byte		N44   , Cs5 
	.byte	W44
	.byte		N04   , Bn4 
	.byte	W04
	.byte		TIE   , Cn5 
	.byte	W96
	.byte	W72
	.byte		EOT   
	.byte		N14   , Dn5 
	.byte	W14
	.byte		N10   , Cn5 
	.byte	W10
	.byte		N96   , As4 
	.byte	W96
	.byte		N48   , Gs4 
	.byte	W48
	.byte		        Gn4 
	.byte	W48
	.byte		N72   , Gs4 
	.byte	W72
	.byte		N16   , As4 
	.byte	W16
	.byte		N08   , Gs4 
	.byte	W08
	.byte		N48   , Gn4 
	.byte	W48
	.byte		N44   , Fn4 
	.byte	W48
	.byte		TIE   , As4 
	.byte	W96
	.byte	W40
	.byte		EOT   
	.byte		N04   , Bn4 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		N48   , Cs5 
	.byte	W48
	.byte		VOICE , 17
	.byte		VOL   , 22*mus_casino_mvl/mxv
	.byte		N16   , Gs4 
	.byte	W16
	.byte		N04   , Cn5 
	.byte	W08
	.byte		        Ds5 
	.byte	W16
	.byte		        Gn5 
	.byte	W24
	.byte		TIE   , Cn6 
	.byte	W32
	.byte	W88
	.byte		EOT   
	.byte		N08   , Dn6 
	.byte	W08
	.byte		N04   , Bn5 
	.byte	W04
	.byte		N36   , As5 
	.byte	W36
	.byte		N08   , Gn5 
	.byte	W08
	.byte		        Gs5 
	.byte	W16
	.byte		N32   , As5 
	.byte	W32
	.byte		N08   , Gn5 
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte		        As5 
	.byte	W08
	.byte		N40   , Dn6 
	.byte	W40
	.byte		N04   , Cn6 
	.byte	W08
	.byte		N16   , As5 
	.byte	W16
	.byte		N04   , Gn5 
	.byte	W08
	.byte		        An5 
	.byte	W04
	.byte		N36   , Gs5 
	.byte	W36
	.byte		N04   , Fn5 
	.byte	W08
	.byte		        Gn5 
	.byte	W16
	.byte		        Gs5 
	.byte	W24
	.byte		        Fn5 
	.byte	W08
	.byte		        Gn5 
	.byte	W16
	.byte		N32   , Gs5 
	.byte	W32
	.byte		N12   , Cn6 
	.byte	W12
	.byte		N04   , As5 , v088
	.byte	W04
	.byte		        Cn6 
	.byte	W04
	.byte		        As5 
	.byte	W04
	.byte		N16   , Gs5 , v112
	.byte	W16
	.byte		N04   , Fn5 
	.byte	W08
	.byte	W16
	.byte		N24   , Gn5 
	.byte	W32
	.byte		N16   , Gs5 
	.byte	W24
	.byte		N16   
	.byte	W24
	.byte		N08   , An5 
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		N24   , As5 
	.byte	W32
	.byte		N16   , Bn5 
	.byte	W16
	.byte		N04   , Gs5 , v092
	.byte	W04
	.byte		        As5 
	.byte	W04
	.byte		TIE   , Cn6 , v112
	.byte	W96
	.byte	W88
	.byte		EOT   
	.byte		N04   , Dn6 , v092
	.byte	W04
	.byte		        Cn6 
	.byte	W04
	.byte		N92   , As5 
	.byte	W92
	.byte		N04   , Gn5 
	.byte	W04
	.byte		N88   , As5 
	.byte	W88
	.byte		N04   , As5 , v112
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		VOL   , 20*mus_casino_mvl/mxv
	.byte		N72   , Ds6 
	.byte	W72
	.byte		N16   , Dn6 
	.byte	W16
	.byte		N08   , Ds6 
	.byte	W08
	.byte		VOL   , 23*mus_casino_mvl/mxv
	.byte		N04   , Bn5 
	.byte	W04
	.byte		N84   , As5 
	.byte	W84
	.byte		N04   , Gn5 
	.byte	W04
	.byte		        Fs5 
	.byte	W04
	.byte		N88   , Fn5 
	.byte	W88
	.byte		N04   , Gn5 
	.byte	W04
	.byte		        Gs5 
	.byte	W04
	.byte		N40   , As5 
	.byte	W40
	.byte		N04   , Bn5 
	.byte	W04
	.byte		        Cn6 
	.byte	W04
	.byte		N48   , Dn6 
	.byte	W48
	.byte	GOTO
	 .word	mus_casino_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_casino_3:
	.byte	KEYSH , mus_casino_key+0
	.byte		VOICE , 35
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 70*mus_casino_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W06
mus_casino_3_B1:
	.byte		VOL   , 70*mus_casino_mvl/mxv
	.byte		N08   , Ds1 , v112
	.byte	W96
	.byte		        En1 
	.byte	W96
	.byte		        Fn1 
	.byte	W96
	.byte		        As0 
	.byte	W08
	.byte		N04   , Fn1 
	.byte	W08
	.byte		        As0 
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N04   , An0 
	.byte	W08
	.byte		N08   , As0 
	.byte	W08
	.byte		N04   , Fn1 
	.byte	W08
	.byte		        As0 
	.byte	W08
	.byte		N20   
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		N04   , Fn1 
	.byte	W08
	.byte		        As0 
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N04   , As1 
	.byte	W32
	.byte		N16   , As0 
	.byte	W16
	.byte		N08   , Dn1 
	.byte	W08
mus_casino_3_000:
	.byte		N08   , Ds1 , v112
	.byte	W16
	.byte		        Ds2 
	.byte	W08
	.byte		N16   , Dn2 
	.byte	W24
	.byte		        Cs2 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte	PEND
mus_casino_3_001:
	.byte		N08   , As1 , v112
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W24
	.byte		        Cs2 
	.byte	W24
	.byte		N08   , Cn2 
	.byte	W16
	.byte		        Gn1 
	.byte	W08
	.byte	PEND
mus_casino_3_002:
	.byte		N08   , Fn1 , v112
	.byte	W16
	.byte		        Fn2 
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		N16   , Fn2 
	.byte	W24
	.byte		N08   , En2 
	.byte	W16
	.byte		        Ds2 
	.byte	W08
	.byte	PEND
mus_casino_3_003:
	.byte		N16   , Dn2 , v112
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		        Gs1 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_casino_3_000
	.byte	PATT
	 .word	mus_casino_3_001
mus_casino_3_004:
	.byte		N08   , Fn1 , v112
	.byte	W16
	.byte		        Fn2 
	.byte	W08
	.byte		N16   , En2 
	.byte	W24
	.byte		        Ds2 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte	PEND
	.byte		N08   
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		N16   , Fn1 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte	PATT
	 .word	mus_casino_3_000
	.byte	PATT
	 .word	mus_casino_3_001
	.byte	PATT
	 .word	mus_casino_3_002
	.byte	PATT
	 .word	mus_casino_3_003
	.byte	PATT
	 .word	mus_casino_3_000
	.byte	PATT
	 .word	mus_casino_3_001
	.byte	PATT
	 .word	mus_casino_3_004
	.byte		VOL   , 72*mus_casino_mvl/mxv
	.byte		N08   , As1 , v112
	.byte	W24
	.byte		N72   , As0 
	.byte	W72
	.byte		        Gs1 
	.byte	W72
	.byte		N04   
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte	W16
	.byte		N32   
	.byte	W32
	.byte		N48   , Gn2 
	.byte	W48
	.byte		N64   , Fn2 
	.byte	W64
	.byte		N04   , Dn2 
	.byte	W08
	.byte		N16   , Fn2 
	.byte	W16
	.byte		N04   , En2 , v084
	.byte	W08
	.byte		N88   , Ds2 , v112
	.byte	W88
	.byte		N04   , As1 
	.byte	W08
mus_casino_3_005:
	.byte		N72   , Fn2 , v112
	.byte	W72
	.byte		N04   , Gn2 
	.byte	W16
	.byte		        Fn2 
	.byte	W08
	.byte	PEND
mus_casino_3_006:
	.byte		N12   , As1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Gn1 
	.byte	W16
	.byte		        Gs1 
	.byte	W08
	.byte		N12   , As1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N16   , Cn2 
	.byte	W16
	.byte		N04   , Dn2 
	.byte	W08
	.byte	PEND
	.byte		N40   , Ds2 
	.byte	W40
	.byte		N08   , As1 
	.byte	W08
	.byte		N16   , Ds2 
	.byte	W16
	.byte		N04   , As1 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		N40   , En2 
	.byte	W40
	.byte		N04   , Cs2 
	.byte	W08
	.byte		N40   , Gn2 
	.byte	W40
	.byte		N04   , En2 
	.byte	W08
	.byte		N48   , Gs1 
	.byte	W48
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Gs2 
	.byte	W16
	.byte		        Gs1 
	.byte	W08
	.byte	W16
	.byte		N32   
	.byte	W32
	.byte		N08   , Ds2 
	.byte	W08
	.byte		N04   , Dn2 
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		N24   , Cn2 
	.byte	W24
	.byte		N60   , Dn2 
	.byte	W60
	.byte	W02
	.byte		N04   , Gn1 
	.byte	W10
	.byte		N16   , Dn2 
	.byte	W16
	.byte		N04   , As1 , v084
	.byte	W08
	.byte		N12   , Ds2 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N24   , Gn1 
	.byte	W24
	.byte		N12   , Gn2 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Ds2 
	.byte	W16
	.byte		        Cn2 
	.byte	W08
	.byte	PATT
	 .word	mus_casino_3_005
	.byte	PATT
	 .word	mus_casino_3_006
	.byte		N12   , Gn2 , v112
	.byte	W16
	.byte		N04   , Ds2 
	.byte	W08
	.byte		N24   , As1 
	.byte	W24
	.byte		N12   , Dn2 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N24   , Ds2 
	.byte	W24
	.byte		N16   , En2 
	.byte	W16
	.byte		N04   , Cs2 
	.byte	W08
	.byte		N24   , As1 
	.byte	W24
	.byte		N16   , En2 
	.byte	W16
	.byte		N04   , Cs2 
	.byte	W08
	.byte		N16   , Gn2 
	.byte	W16
	.byte		N04   , As1 
	.byte	W08
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
	 .word	mus_casino_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_casino_4:
	.byte	KEYSH , mus_casino_key+0
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 63*mus_casino_mvl/mxv
	.byte		N02   , Fn3 , v112
	.byte	W02
	.byte		        Gn3 
	.byte	W02
	.byte		        Gs3 
	.byte	W02
mus_casino_4_B1:
	.byte		VOICE , 56
	.byte		N08   , Ds4 , v120
	.byte	W72
	.byte		        Ds3 , v112
	.byte	W08
	.byte		        Ds3 , v036
	.byte	W16
	.byte		        En4 , v112
	.byte	W08
	.byte		        En4 , v036
	.byte	W08
	.byte		        Cs4 , v112
	.byte	W08
	.byte		        Cs4 , v036
	.byte	W16
	.byte		        As3 , v112
	.byte	W08
	.byte		        As3 , v036
	.byte	W16
	.byte		        Gn3 , v112
	.byte	W08
	.byte		N16   , Fs3 
	.byte	W16
	.byte		N08   , Gn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		N16   , As3 
	.byte	W16
	.byte		N08   , Cn4 
	.byte	W08
	.byte		        Cn4 , v036
	.byte	W16
	.byte		        Ds4 , v112
	.byte	W08
	.byte		        Ds4 , v036
	.byte	W24
	.byte		VOICE , 1
	.byte	W16
	.byte		N32   , Dn4 , v112
	.byte	W32
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Ds4 , v036
	.byte	W16
	.byte		N20   , Ds4 , v112
	.byte	W24
	.byte		N16   , En4 
	.byte	W16
	.byte		N08   , En4 , v036
	.byte	W08
	.byte		        En4 , v112
	.byte	W08
	.byte		        En4 , v036
	.byte	W08
	.byte		        Fn4 , v112
	.byte	W08
	.byte		VOL   , 53*mus_casino_mvl/mxv
	.byte		N08   , Fn4 , v036
	.byte	W16
	.byte		        As4 , v084
	.byte	W08
	.byte		VOL   , 64*mus_casino_mvl/mxv
	.byte		N24   , As2 , v112
	.byte	W24
	.byte		VOICE , 13
	.byte		VOL   , 51*mus_casino_mvl/mxv
	.byte	W16
	.byte		N08   , Gn4 
	.byte	W08
	.byte		        Gn4 , v036
	.byte	W48
	.byte		        As3 , v112
	.byte	W08
	.byte		        As3 , v036
	.byte	W16
	.byte		        Gs4 , v112
	.byte	W16
	.byte		        Gn4 
	.byte	W24
	.byte		        Fs4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		N04   , As3 
	.byte	W08
	.byte		N08   , Fn4 
	.byte	W08
	.byte		N24   , Gn4 
	.byte	W24
	.byte	W16
	.byte		N04   , Gs4 
	.byte	W32
	.byte		N24   
	.byte	W48
	.byte		N08   , As4 
	.byte	W16
	.byte		        Gs4 
	.byte	W24
	.byte		        Gn4 
	.byte	W08
	.byte		N24   , Fn4 
	.byte	W24
	.byte		N08   , Fs4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		VOL   , 33*mus_casino_mvl/mxv
	.byte		N04   , As3 , v104
	.byte	W04
	.byte		        Gn4 , v096
	.byte	W04
	.byte		        As3 , v088
	.byte	W04
	.byte		        Gn4 , v080
	.byte	W04
	.byte		        As3 , v072
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As3 , v068
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As3 , v064
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Cs4 , v104
	.byte	W04
	.byte		        As4 , v096
	.byte	W04
	.byte		        Cs4 , v088
	.byte	W04
	.byte		        As4 , v080
	.byte	W04
	.byte		        Cs4 , v072
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Cs4 , v068
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Cs4 , v064
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Cn4 , v104
	.byte	W04
	.byte		        Gs4 , v096
	.byte	W04
	.byte		        Cn4 , v088
	.byte	W04
	.byte		        Gs4 , v080
	.byte	W04
	.byte		        Cn4 , v072
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Cn4 , v068
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Cn4 , v064
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Dn4 , v104
	.byte	W04
	.byte		        As4 , v096
	.byte	W04
	.byte		        Dn4 , v088
	.byte	W04
	.byte		        As4 , v080
	.byte	W04
	.byte		        Cn4 , v104
	.byte	W04
	.byte		        Gs4 , v096
	.byte	W04
	.byte		        Dn4 , v104
	.byte	W04
	.byte		        Gn4 , v096
	.byte	W04
	.byte		        Dn4 , v088
	.byte	W04
	.byte		        Gn4 , v080
	.byte	W04
	.byte		        Dn4 , v072
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Dn4 , v068
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Dn4 , v064
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As3 , v104
	.byte	W04
	.byte		        Fn4 , v096
	.byte	W04
	.byte		        As3 , v088
	.byte	W04
	.byte		        Fn4 , v080
	.byte	W04
	.byte		        As3 , v072
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        As3 , v068
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        As3 , v064
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 56
	.byte		VOL   , 64*mus_casino_mvl/mxv
	.byte	W16
	.byte		N04   , Gs3 , v112
	.byte	W04
	.byte		N08   , Gs3 , v036
	.byte	W28
	.byte		N16   , Gs3 , v112
	.byte	W16
	.byte		N08   , Gs3 , v036
	.byte	W08
	.byte		N20   , Gs3 , v112
	.byte	W24
	.byte		N08   , As3 
	.byte	W08
	.byte		N02   , An3 , v064
	.byte	W02
	.byte		        Gs3 , v068
	.byte	W02
	.byte		        Gn3 
	.byte	W02
	.byte		        Fs3 , v064
	.byte	W80
	.byte	W02
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 46
	.byte		VOL   , 52*mus_casino_mvl/mxv
	.byte	W80
	.byte		N04   , Cs5 , v112
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		VOICE , 46
	.byte		VOL   , 52*mus_casino_mvl/mxv
	.byte		N04   , Gs4 
	.byte	W08
	.byte		        Cn5 , v076
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		        Gn5 , v112
	.byte	W08
	.byte		        Ds5 , v072
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Gs4 , v112
	.byte	W08
	.byte		        Cn5 , v076
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		        Gn5 , v112
	.byte	W08
	.byte		        Ds5 , v072
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Gs4 , v112
	.byte	W08
	.byte		        Cn5 , v076
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Fn5 , v112
	.byte	W08
	.byte		        Dn5 , v072
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Gs4 , v112
	.byte	W08
	.byte		        Cn5 , v076
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Fn5 , v112
	.byte	W08
	.byte		        Dn5 , v072
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Gn4 , v112
	.byte	W08
	.byte		        As4 , v076
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Fn5 , v112
	.byte	W08
	.byte		        Dn5 , v072
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Gn4 , v112
	.byte	W08
	.byte		        As4 , v076
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Fn5 , v112
	.byte	W08
	.byte		        Dn5 , v072
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Gn4 , v112
	.byte	W08
	.byte		        As4 , v076
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Ds5 , v112
	.byte	W08
	.byte		        Cn5 , v072
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Gn4 , v112
	.byte	W08
	.byte		        As4 , v076
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Ds5 , v112
	.byte	W08
	.byte		        Cn5 , v072
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Fn4 , v112
	.byte	W08
	.byte		        Gs4 , v076
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Ds5 , v112
	.byte	W08
	.byte		        Cn5 , v072
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Fn4 , v112
	.byte	W08
	.byte		        Gs4 , v076
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Ds5 , v112
	.byte	W08
	.byte		        Cn5 , v072
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Fn4 , v112
	.byte	W08
	.byte		        Gs4 , v076
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Dn5 , v112
	.byte	W08
	.byte		        As4 , v072
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Fn4 , v112
	.byte	W08
	.byte		        Gs4 , v076
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Dn5 , v112
	.byte	W08
	.byte		        As4 , v072
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Ds4 , v112
	.byte	W08
	.byte		        Gn4 , v076
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Dn5 , v112
	.byte	W08
	.byte		        As4 , v072
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Ds4 , v112
	.byte	W08
	.byte		        Gn4 , v076
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Dn5 , v112
	.byte	W08
	.byte		        As4 , v072
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        En4 , v112
	.byte	W08
	.byte		        Gn4 , v076
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Cs5 , v112
	.byte	W08
	.byte		        As4 , v072
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        En4 , v112
	.byte	W08
	.byte		        Gn4 , v076
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Cs5 , v112
	.byte	W08
	.byte		        As4 , v072
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		VOICE , 1
	.byte		VOL   , 61*mus_casino_mvl/mxv
	.byte		N04   , Gn3 , v112
	.byte	W04
	.byte		N08   , Gn3 , v036
	.byte	W92
	.byte	W16
	.byte		N04   , Gn3 , v112
	.byte	W04
	.byte		N08   , Gn3 , v036
	.byte	W28
	.byte		N16   , Gn3 , v112
	.byte	W16
	.byte		N08   , Gn3 , v036
	.byte	W08
	.byte		N04   , Fs3 , v112
	.byte	W04
	.byte		N08   , Fs3 , v036
	.byte	W20
	.byte		N04   , Fn3 , v112
	.byte	W04
	.byte		N08   , Fn3 , v036
	.byte	W92
	.byte	W16
	.byte		N04   , Fn3 , v112
	.byte	W04
	.byte		N08   , Fn3 , v036
	.byte	W28
	.byte		N16   , Fn3 , v112
	.byte	W16
	.byte		N08   , Fn3 , v036
	.byte	W08
	.byte		N04   , En3 , v112
	.byte	W04
	.byte		N08   , En3 , v036
	.byte	W20
	.byte		N04   , Ds3 , v112
	.byte	W04
	.byte		N08   , Ds3 , v036
	.byte	W92
	.byte	W16
	.byte		N04   , Ds3 , v112
	.byte	W04
	.byte		N08   , Ds3 , v036
	.byte	W28
	.byte		N16   , Ds3 , v112
	.byte	W16
	.byte		N08   , Ds3 , v036
	.byte	W32
	.byte	W16
	.byte		N24   , Dn3 , v112
	.byte	W24
	.byte		N08   , Dn3 , v036
	.byte	W08
	.byte		N16   , Ds3 , v112
	.byte	W16
	.byte		N08   , Ds3 , v036
	.byte	W08
	.byte		N16   , Ds3 , v112
	.byte	W16
	.byte		N08   , Ds3 , v036
	.byte	W08
	.byte		N16   , Ds3 , v112
	.byte	W16
	.byte		N08   , Ds3 , v036
	.byte	W08
	.byte		N04   , Ds3 , v112
	.byte	W04
	.byte		N08   , Ds3 , v036
	.byte	W12
	.byte		N24   , Fn3 , v112
	.byte	W24
	.byte		N08   , Fn3 , v036
	.byte	W08
	.byte		N24   , Gs3 , v112
	.byte	W24
	.byte		N04   , Gn3 
	.byte	W08
	.byte		        Gn3 , v052
	.byte	W08
	.byte		        Gn3 , v088
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		N08   , Gn3 , v036
	.byte	W20
	.byte		N04   , Gn3 , v088
	.byte	W04
	.byte		N08   , Gn3 , v036
	.byte	W20
	.byte		N04   , Fs3 , v088
	.byte	W04
	.byte		N08   , Fs3 , v036
	.byte	W20
	.byte		N04   , Gn3 , v088
	.byte	W04
	.byte		N08   , Gn3 , v036
	.byte	W12
	.byte		N04   , Gn3 , v112
	.byte	W04
	.byte		N08   , Gn3 , v036
	.byte	W28
	.byte		N16   , Gn3 , v112
	.byte	W16
	.byte		N08   , Gn3 , v036
	.byte	W08
	.byte		N16   , Fs3 , v112
	.byte	W16
	.byte		N08   , Fs3 , v036
	.byte	W08
	.byte		N04   , Fn3 , v112
	.byte	W08
	.byte		        Fn3 , v048
	.byte	W08
	.byte		        Fn3 , v088
	.byte	W08
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W04
	.byte		N08   , Fn3 , v036
	.byte	W20
	.byte		N04   , En3 , v088
	.byte	W04
	.byte		N08   , En3 , v036
	.byte	W20
	.byte		N04   , Fn3 , v088
	.byte	W04
	.byte		N08   , Fn3 , v036
	.byte	W12
	.byte		N04   , Fn3 , v112
	.byte	W04
	.byte		N08   , Fn3 , v036
	.byte	W28
	.byte		N16   , Fn3 , v112
	.byte	W16
	.byte		N08   , Fn3 , v036
	.byte	W08
	.byte		N16   , En3 , v112
	.byte	W16
	.byte		N08   , En3 , v036
	.byte	W08
	.byte		N04   , As3 , v112
	.byte	W08
	.byte		        As3 , v048
	.byte	W08
	.byte		        As3 , v088
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		N08   , As3 , v036
	.byte	W20
	.byte		N04   , As3 , v088
	.byte	W04
	.byte		N08   , As3 , v036
	.byte	W44
	.byte		N04   , As3 , v088
	.byte	W04
	.byte		N08   , As3 , v036
	.byte	W12
	.byte		N04   , As3 , v112
	.byte	W04
	.byte		N08   , As3 , v036
	.byte	W28
	.byte		N16   , As3 , v112
	.byte	W16
	.byte		N08   , As3 , v036
	.byte	W32
	.byte		N04   , As3 , v112
	.byte	W08
	.byte		        As3 , v048
	.byte	W08
	.byte		        As3 , v088
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		N08   , As3 , v036
	.byte	W20
	.byte		N04   , As3 , v088
	.byte	W04
	.byte		N08   , As3 , v036
	.byte	W20
	.byte		N04   , An3 , v088
	.byte	W04
	.byte		N08   , An3 , v036
	.byte	W20
	.byte		N04   , As3 , v088
	.byte	W04
	.byte		N08   , As3 , v036
	.byte	W12
	.byte		N04   , As3 , v112
	.byte	W04
	.byte		N08   , As3 , v036
	.byte	W28
	.byte		N04   , As3 , v088
	.byte	W04
	.byte		N08   , As3 , v036
	.byte	W12
	.byte		N04   , As3 , v112
	.byte	W04
	.byte		N08   , As3 , v036
	.byte	W28
	.byte	GOTO
	 .word	mus_casino_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_casino_5:
	.byte	KEYSH , mus_casino_key+0
	.byte		VOICE , 56
	.byte		PAN   , c_v-8
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 68*mus_casino_mvl/mxv
	.byte		N02   , As3 , v112
	.byte	W02
	.byte		        Cn4 
	.byte	W02
	.byte		        Dn4 
	.byte	W02
mus_casino_5_B1:
	.byte		VOL   , 72*mus_casino_mvl/mxv
	.byte		N08   , As4 , v120
	.byte	W08
	.byte		        As4 , v036
	.byte	W64
	.byte		        As3 , v112
	.byte	W08
	.byte		        As3 , v036
	.byte	W16
	.byte		        Gs4 , v112
	.byte	W08
	.byte		        Gs4 , v036
	.byte	W08
	.byte		        Gn4 , v112
	.byte	W08
	.byte		        Gn4 , v036
	.byte	W16
	.byte		        Fn4 , v112
	.byte	W08
	.byte		        Fn4 , v036
	.byte	W16
	.byte		        Ds4 , v112
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Ds4 , v036
	.byte	W16
	.byte		        Gn4 , v112
	.byte	W08
	.byte		        Gn4 , v036
	.byte	W24
	.byte	W96
	.byte		VOICE , 1
	.byte		VOL   , 53*mus_casino_mvl/mxv
	.byte	W64
	.byte		N04   , An4 , v076
	.byte	W32
	.byte		VOICE , 56
	.byte		VOL   , 72*mus_casino_mvl/mxv
	.byte	W16
	.byte		N08   , Gn4 , v112
	.byte	W08
	.byte		        Gn4 , v036
	.byte	W48
	.byte		        As3 , v112
	.byte	W08
	.byte		        As3 , v036
	.byte	W16
	.byte		        Gs4 , v112
	.byte	W08
	.byte		        Gs4 , v036
	.byte	W08
	.byte		        Gn4 , v112
	.byte	W08
	.byte		        Gn4 , v036
	.byte	W16
	.byte		        Fs4 , v112
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		N04   , As3 
	.byte	W04
	.byte		        As3 , v036
	.byte	W04
	.byte		N08   , Fn4 , v112
	.byte	W08
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N08   , Gn4 , v036
	.byte	W16
	.byte		N04   , Gs4 , v112
	.byte	W04
	.byte		N08   , Gs4 , v036
	.byte	W28
	.byte		N24   , Gs4 , v112
	.byte	W24
	.byte		N08   , Gs4 , v036
	.byte	W24
	.byte		        As4 , v112
	.byte	W08
	.byte		        As4 , v036
	.byte	W08
	.byte		        Gs4 , v112
	.byte	W08
	.byte		        Gs4 , v036
	.byte	W16
	.byte		        Gn4 , v112
	.byte	W08
	.byte		N24   , Fn4 
	.byte	W24
	.byte		N08   , Fs4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N72   , Gn4 
	.byte	W72
	.byte		N08   , Gn4 , v036
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		VOICE , 60
	.byte		VOL   , 62*mus_casino_mvl/mxv
	.byte		N04   , Dn4 , v112
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Fn4 
	.byte	W07
	.byte		VOICE , 60
	.byte	W01
	.byte		N04   , Gn3 
	.byte	W04
	.byte		N08   , Gn3 , v036
	.byte	W12
	.byte		        Gn4 , v112
	.byte	W08
	.byte		N02   , Fs4 , v064
	.byte	W02
	.byte		        Fn4 , v068
	.byte	W02
	.byte		        En4 
	.byte	W02
	.byte		        Ds4 , v064
	.byte	W02
	.byte		        Dn4 , v068
	.byte	W02
	.byte		        Cs4 
	.byte	W36
	.byte	W02
	.byte		N08   , As3 , v112
	.byte	W08
	.byte		        As3 , v036
	.byte	W16
	.byte		VOL   , 58*mus_casino_mvl/mxv
	.byte		N24   , Gs4 , v112
	.byte	W24
	.byte		N08   , Gn4 
	.byte	W08
	.byte		        Gn4 , v036
	.byte	W08
	.byte		        En4 , v112
	.byte	W08
	.byte		N24   , Fn4 
	.byte	W24
	.byte		N08   , Gn4 
	.byte	W08
	.byte		        Gn4 , v036
	.byte	W08
	.byte		        En4 , v112
	.byte	W08
	.byte		        En4 , v036
	.byte	W16
	.byte		        Gs4 , v104
	.byte	W08
	.byte		        Gs4 , v036
	.byte	W24
	.byte		N24   , Gs4 , v104
	.byte	W24
	.byte		N08   , Gs4 , v036
	.byte	W24
	.byte		N24   , As4 , v100
	.byte	W24
	.byte		N04   , Gs4 , v112
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		N72   , As3 
	.byte	W72
	.byte		N04   , Cn4 , v092
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		N96   , As4 , v100
	.byte	W96
	.byte		VOICE , 56
	.byte		VOL   , 62*mus_casino_mvl/mxv
	.byte		N08   , As4 , v036
	.byte	W16
	.byte		N04   , Gs4 , v112
	.byte	W04
	.byte		N08   , Gs4 , v036
	.byte	W28
	.byte		N16   , Gs4 , v112
	.byte	W16
	.byte		N08   , Gs4 , v036
	.byte	W08
	.byte		N20   , Gs4 , v112
	.byte	W20
	.byte		N04   , Gs4 , v036
	.byte	W04
	.byte		N08   , As4 , v112
	.byte	W08
	.byte		N02   , An4 , v064
	.byte	W02
	.byte		        Gs4 , v068
	.byte	W02
	.byte		        Gn4 
	.byte	W02
	.byte		        Fs4 , v064
	.byte	W80
	.byte	W02
	.byte		VOICE , 24
	.byte		VOL   , 58*mus_casino_mvl/mxv
	.byte	W24
	.byte		N24   , Gn4 , v112
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N24   , Ds4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		N08   , Fn4 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N16   , Cs4 
	.byte	W16
	.byte		N08   , Dn4 
	.byte	W08
	.byte		N24   , Cn5 
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		N16   , Gn4 
	.byte	W16
	.byte		N24   , Gs4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		N08   , As4 
	.byte	W08
	.byte		N16   , Gn4 
	.byte	W16
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Ds4 , v036
	.byte	W24
	.byte		N24   , Gs4 , v112
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N04   , En4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N16   , Cs4 
	.byte	W16
	.byte		N08   , Dn4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N08   , Fn4 
	.byte	W08
	.byte		        Fn4 , v036
	.byte	W24
	.byte		        As4 , v112
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		N16   , Gn4 
	.byte	W16
	.byte		N08   , Fn4 
	.byte	W08
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N08   , Ds4 , v036
	.byte	W16
	.byte		N24   , En4 , v112
	.byte	W24
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N16   , En4 
	.byte	W16
	.byte		N08   , As3 
	.byte	W08
	.byte		N16   , Gn4 
	.byte	W16
	.byte		N08   , En4 
	.byte	W08
	.byte		        En4 , v036
	.byte	W24
	.byte		N24   , Gs4 , v112
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N08   , Cs4 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N16   , En4 
	.byte	W16
	.byte		N08   , Fn4 
	.byte	W08
	.byte		        Fn4 , v036
	.byte	W24
	.byte		N16   , Fn4 , v112
	.byte	W16
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N08   , Cs4 
	.byte	W08
	.byte		N24   , Dn5 
	.byte	W24
	.byte		N48   , Cn5 
	.byte	W48
	.byte		N40   , As4 
	.byte	W40
	.byte		N04   , Gn4 
	.byte	W08
	.byte		N24   , Gs4 
	.byte	W24
	.byte		        Ds5 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		N16   , Dn5 
	.byte	W16
	.byte		N24   , Cn5 
	.byte	W24
	.byte		N08   , Dn5 
	.byte	W08
	.byte		N16   , As4 
	.byte	W16
	.byte		N08   , Dn4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N08   , Fn4 
	.byte	W08
	.byte		N64   , As4 
	.byte	W64
	.byte		N08   , Dn4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N08   , Fn4 
	.byte	W08
	.byte		N48   , As4 
	.byte	W48
	.byte		        Cs5 
	.byte	W48
	.byte		VOICE , 24
	.byte		N40   , Ds4 
	.byte	W40
	.byte		N04   , Cn4 
	.byte	W08
	.byte		        Gn4 
	.byte	W04
	.byte		N08   , Gn4 , v036
	.byte	W20
	.byte		N04   , Gs3 , v112
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Gn4 
	.byte	W04
	.byte		N08   , Gn4 , v036
	.byte	W12
	.byte		N04   , Fs4 , v112
	.byte	W08
	.byte		        Fn4 
	.byte	W04
	.byte		N08   , Fn4 , v036
	.byte	W12
	.byte		N04   , En4 , v112
	.byte	W08
	.byte		        Ds4 
	.byte	W04
	.byte		N08   , Ds4 , v036
	.byte	W12
	.byte		N04   , Dn4 , v112
	.byte	W08
	.byte		        Cn4 
	.byte	W04
	.byte		N08   , Cn4 , v036
	.byte	W12
	.byte		N04   , Dn4 , v112
	.byte	W08
	.byte		N40   , As3 
	.byte	W40
	.byte		N04   , Gn3 
	.byte	W08
	.byte		        Gs3 
	.byte	W04
	.byte		N08   , Gs3 , v036
	.byte	W12
	.byte		N04   , As3 , v112
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		N40   , Dn4 
	.byte	W40
	.byte		N04   , Cn4 
	.byte	W04
	.byte		        Cn4 , v036
	.byte	W04
	.byte		N16   , As3 , v112
	.byte	W16
	.byte		N04   , Gn3 
	.byte	W04
	.byte		        Gn3 , v036
	.byte	W04
	.byte		N40   , Gs3 , v112
	.byte	W40
	.byte		N04   , Fn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W04
	.byte		N08   , Gn3 , v036
	.byte	W12
	.byte		N04   , Gs3 , v112
	.byte	W04
	.byte		N08   , Gs3 , v036
	.byte	W20
	.byte		N04   , Fn3 , v112
	.byte	W08
	.byte		        Gn3 
	.byte	W04
	.byte		N08   , Gn3 , v036
	.byte	W12
	.byte		N32   , Gs3 , v112
	.byte	W32
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N04   , As3 , v088
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		N16   , Gs3 , v112
	.byte	W16
	.byte		N04   , Fn3 
	.byte	W04
	.byte		N08   , Fn3 , v036
	.byte	W04
	.byte	W16
	.byte		N24   , Gn3 , v112
	.byte	W24
	.byte		N08   , Gn3 , v036
	.byte	W08
	.byte		N16   , Gs3 , v112
	.byte	W16
	.byte		N08   , Gs3 , v036
	.byte	W08
	.byte		N16   , Gs3 , v112
	.byte	W16
	.byte		N08   , Gs3 , v036
	.byte	W08
	.byte		N16   , An3 , v112
	.byte	W16
	.byte		N08   , An3 , v036
	.byte	W08
	.byte		N04   , An3 , v112
	.byte	W04
	.byte		N08   , An3 , v036
	.byte	W12
	.byte		N24   , As3 , v112
	.byte	W24
	.byte		N08   , As3 , v036
	.byte	W08
	.byte		N24   , Bn3 , v112
	.byte	W24
	.byte		N08   , Bn3 , v036
	.byte	W24
	.byte		N16   , Gs3 , v112
	.byte	W16
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N08   , Gn4 
	.byte	W08
	.byte		        Gn4 , v036
	.byte	W24
	.byte		N16   , Gs3 , v112
	.byte	W16
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N08   , Gn4 
	.byte	W08
	.byte		N16   , Cn5 , v096
	.byte	W16
	.byte		N04   , As4 , v092
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		N16   , Fn4 , v112
	.byte	W16
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N16   , Gn3 
	.byte	W16
	.byte		N08   , As3 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N08   , Fn4 
	.byte	W08
	.byte		        Fn4 , v036
	.byte	W24
	.byte		N16   , Gn3 , v112
	.byte	W16
	.byte		N08   , As3 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N24   , As4 , v096
	.byte	W24
	.byte		N04   , Gs4 , v088
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		N16   , Dn4 , v112
	.byte	W16
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N16   , As4 , v096
	.byte	W16
	.byte		N08   , Gs4 , v112
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Fs4 , v036
	.byte	W08
	.byte		        Fs4 , v112
	.byte	W08
	.byte		        Fs4 , v036
	.byte	W24
	.byte		N16   , Fn4 , v112
	.byte	W16
	.byte		N08   , Fs4 
	.byte	W08
	.byte		N24   , As4 , v096
	.byte	W24
	.byte		N16   , Gs4 , v112
	.byte	W16
	.byte		N08   , Fn4 
	.byte	W08
	.byte		N16   , Fs4 
	.byte	W16
	.byte		N08   , Fs4 , v036
	.byte	W08
	.byte		N16   , Dn4 , v112
	.byte	W16
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N72   , Fn4 
	.byte	W72
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N08   , Fn4 
	.byte	W08
	.byte		N48   , As4 
	.byte	W48
	.byte		N24   , Dn5 , v096
	.byte	W24
	.byte		VOICE , 56
	.byte		VOL   , 72*mus_casino_mvl/mxv
	.byte		N08   , Gn4 , v112
	.byte	W08
	.byte		N04   , Gs4 
	.byte	W08
	.byte		N08   , An4 
	.byte	W08
	.byte	GOTO
	 .word	mus_casino_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_casino_6:
	.byte	KEYSH , mus_casino_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-61
	.byte		VOL   , 36*mus_casino_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v-64
	.byte	W02
mus_casino_6_B1:
	.byte		PAN   , c_v-64
	.byte		VOL   , 36*mus_casino_mvl/mxv
	.byte		N08   , Gn2 , v112
	.byte	W96
	.byte		N08   
	.byte	W96
	.byte		        Gs2 
	.byte	W96
	.byte	W16
	.byte		N32   , Fn3 
	.byte	W32
	.byte		N08   
	.byte	W24
	.byte		N20   
	.byte	W24
	.byte		N16   , Gn3 
	.byte	W24
	.byte		N08   
	.byte	W16
	.byte		        Gs3 
	.byte	W32
	.byte		N20   , As2 
	.byte	W20
	.byte		VOICE , 85
	.byte		N02   , Ds3 
	.byte	W02
	.byte		        Fn3 
	.byte	W02
mus_casino_6_000:
	.byte		N02   , Gn3 , v112
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N04   , As3 
	.byte	W16
	.byte		N02   , Gn3 
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N04   , As3 
	.byte	W16
	.byte		N02   , Gn3 
	.byte	W08
	.byte	PEND
mus_casino_6_001:
	.byte		N02   , Gn3 , v112
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N04   , As3 
	.byte	W16
	.byte		N02   , Gn3 
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		        En3 , v076
	.byte	W08
	.byte		        Gn3 , v112
	.byte	W08
	.byte	PEND
mus_casino_6_002:
	.byte		N02   , Gs3 , v112
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N04   , Cn4 
	.byte	W16
	.byte		N02   , Fn3 
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N04   , Cn4 
	.byte	W16
	.byte		N02   , Gs3 
	.byte	W08
	.byte	PEND
mus_casino_6_003:
	.byte		N02   , Dn4 , v112
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N04   , As3 
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		        Gs3 
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		        Fn3 , v076
	.byte	W08
	.byte		        Gs3 , v112
	.byte	W08
	.byte	PEND
mus_casino_6_004:
	.byte		N02   , Gn3 , v112
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N04   , As3 
	.byte	W08
	.byte		N02   , Gn3 , v084
	.byte	W08
	.byte		        As3 , v112
	.byte	W08
	.byte		        Gn3 
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N04   , As3 
	.byte	W16
	.byte		N02   , Gn3 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_casino_6_001
	.byte	PATT
	 .word	mus_casino_6_002
	.byte		N02   , Dn4 , v112
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		N04   , As3 
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Fn3 , v076
	.byte	W08
	.byte		        Gs3 , v112
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		        Fn3 , v076
	.byte	W08
	.byte		        Dn3 , v112
	.byte	W08
	.byte	PATT
	 .word	mus_casino_6_000
	.byte	PATT
	 .word	mus_casino_6_001
	.byte	PATT
	 .word	mus_casino_6_002
	.byte	PATT
	 .word	mus_casino_6_003
	.byte	PATT
	 .word	mus_casino_6_004
	.byte	PATT
	 .word	mus_casino_6_001
	.byte	PATT
	 .word	mus_casino_6_002
	.byte		N04   , Dn4 , v112
	.byte	W72
	.byte		VOICE , 80
	.byte		N04   , An2 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		VOL   , 31*mus_casino_mvl/mxv
	.byte		N96   , Ds3 
	.byte	W96
mus_casino_6_005:
	.byte		N48   , Dn3 , v112
	.byte	W48
	.byte		        Cn3 
	.byte	W48
	.byte	PEND
	.byte		N64   , Dn3 
	.byte	W64
	.byte		N04   , As2 
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N04   , Cs3 
	.byte	W08
	.byte		N88   , Cn3 
	.byte	W88
	.byte		N04   , As2 
	.byte	W08
	.byte		N72   , Cn3 
	.byte	W72
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N04   , Cn3 
	.byte	W08
	.byte		N48   , As2 
	.byte	W48
	.byte		        Gs2 
	.byte	W48
	.byte		N88   , As2 
	.byte	W88
	.byte		N04   , Gn2 
	.byte	W08
	.byte		N48   
	.byte	W48
	.byte		        As2 
	.byte	W48
	.byte		N72   , Gn3 
	.byte	W72
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N08   , Gn3 
	.byte	W08
	.byte		N48   , Fn3 
	.byte	W48
	.byte		        Ds3 
	.byte	W48
	.byte		N64   , Fn3 
	.byte	W64
	.byte		N04   , Dn3 
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N04   , Dn3 
	.byte	W08
	.byte		N48   , Ds3 
	.byte	W48
	.byte		N40   , Cn3 
	.byte	W40
	.byte		N04   , As2 
	.byte	W08
	.byte		N72   , Ds3 
	.byte	W72
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N08   , Ds3 
	.byte	W08
	.byte	PATT
	 .word	mus_casino_6_005
	.byte		N60   , Dn3 , v112
	.byte	W60
	.byte	W02
	.byte		N10   , As2 
	.byte	W08
	.byte		N18   , Cn3 
	.byte	W16
	.byte		N10   , Cs3 
	.byte	W10
	.byte		N48   , En3 
	.byte	W48
	.byte		        Cs3 
	.byte	W48
	.byte		PAN   , c_v+63
	.byte		N04   , Ds3 
	.byte	W96
	.byte	W16
	.byte		N04   
	.byte	W32
	.byte		N16   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		        Dn3 
	.byte	W96
	.byte	W16
	.byte		N04   
	.byte	W32
	.byte		N16   
	.byte	W24
	.byte		N04   , Cs3 
	.byte	W24
	.byte		        Cn3 
	.byte	W96
	.byte	W16
	.byte		N04   
	.byte	W32
	.byte		N16   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte	W16
	.byte		N24   , As2 
	.byte	W32
	.byte		N16   , Cn3 
	.byte	W24
	.byte		N16   
	.byte	W24
	.byte		N16   
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		N24   , Dn3 
	.byte	W32
	.byte		        Fn3 
	.byte	W24
	.byte		N04   , Ds3 
	.byte	W08
	.byte		        Ds3 , v052
	.byte	W08
	.byte		        Ds3 , v088
	.byte	W08
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		        Ds3 , v112
	.byte	W32
	.byte		N16   
	.byte	W24
	.byte		N16   
	.byte	W24
	.byte		N04   , Dn3 
	.byte	W08
	.byte		        Dn3 , v048
	.byte	W08
	.byte		        Dn3 , v088
	.byte	W08
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		        Dn3 , v112
	.byte	W32
	.byte		N16   
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		N04   , Fs3 
	.byte	W08
	.byte		        Fs3 , v048
	.byte	W08
	.byte		        Fs3 , v088
	.byte	W08
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		        Fs3 , v112
	.byte	W32
	.byte		N16   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		        Fn3 
	.byte	W08
	.byte		        Fn3 , v048
	.byte	W08
	.byte		        Fn3 , v088
	.byte	W08
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		        Fn3 , v112
	.byte	W32
	.byte		        Fn3 , v088
	.byte	W16
	.byte		        Fn3 , v112
	.byte	W32
	.byte	GOTO
	 .word	mus_casino_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_casino_7:
	.byte	KEYSH , mus_casino_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 36*mus_casino_mvl/mxv
	.byte		PAN   , c_v+63
	.byte	W06
mus_casino_7_B1:
	.byte		PAN   , c_v+63
	.byte		VOL   , 36*mus_casino_mvl/mxv
	.byte		N08   , Dn3 , v112
	.byte	W96
	.byte		        Cs3 
	.byte	W96
	.byte		        Ds3 
	.byte	W96
	.byte	W16
	.byte		N32   , As3 
	.byte	W32
	.byte		N08   , Cn4 
	.byte	W24
	.byte		N20   
	.byte	W24
	.byte		N16   , Cs4 
	.byte	W24
	.byte		N08   
	.byte	W16
	.byte		        Dn4 
	.byte	W32
	.byte		N20   , As1 
	.byte	W20
	.byte		VOICE , 84
	.byte		N02   , As3 
	.byte	W02
	.byte		        Cn4 
	.byte	W02
mus_casino_7_000:
	.byte		N02   , Ds4 , v112
	.byte	W16
	.byte		        As3 
	.byte	W08
	.byte		N04   , Gn4 
	.byte	W16
	.byte		N02   , Ds4 
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		        As3 
	.byte	W08
	.byte		N04   , Gn4 
	.byte	W16
	.byte		N02   , Ds4 
	.byte	W08
	.byte	PEND
mus_casino_7_001:
	.byte		N02   , En4 , v112
	.byte	W16
	.byte		        As3 
	.byte	W08
	.byte		N04   , Gn4 
	.byte	W16
	.byte		N02   , En4 
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		        Cs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Cs4 , v076
	.byte	W08
	.byte		        En4 , v112
	.byte	W08
	.byte	PEND
mus_casino_7_002:
	.byte		N02   , Fn4 , v112
	.byte	W16
	.byte		        Cn4 
	.byte	W08
	.byte		N04   , Gs4 
	.byte	W16
	.byte		N02   , Ds4 
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		        Cn4 
	.byte	W08
	.byte		N04   , Gs4 
	.byte	W16
	.byte		N02   , Ds4 
	.byte	W08
	.byte	PEND
mus_casino_7_003:
	.byte		N02   , As4 , v112
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N04   , Gs4 
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		        Fn4 
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Cn4 , v076
	.byte	W08
	.byte		        Dn4 , v112
	.byte	W08
	.byte	PEND
mus_casino_7_004:
	.byte		N02   , Ds4 , v112
	.byte	W16
	.byte		        As3 
	.byte	W08
	.byte		N04   , Gn4 
	.byte	W08
	.byte		N02   , Ds4 , v084
	.byte	W08
	.byte		        Gn4 , v112
	.byte	W08
	.byte		        Ds4 
	.byte	W16
	.byte		        As3 
	.byte	W08
	.byte		N04   , Gn4 
	.byte	W16
	.byte		N02   , Ds4 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_casino_7_001
	.byte	PATT
	 .word	mus_casino_7_002
	.byte		N02   , An4 , v112
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		N04   , Gs4 
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Dn4 , v076
	.byte	W08
	.byte		        Fn4 , v112
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Cn4 , v076
	.byte	W08
	.byte		        As3 , v112
	.byte	W08
	.byte	PATT
	 .word	mus_casino_7_000
	.byte	PATT
	 .word	mus_casino_7_001
	.byte	PATT
	 .word	mus_casino_7_002
	.byte	PATT
	 .word	mus_casino_7_003
	.byte	PATT
	 .word	mus_casino_7_004
	.byte	PATT
	 .word	mus_casino_7_001
	.byte	PATT
	 .word	mus_casino_7_002
	.byte		N04   , As4 , v112
	.byte	W72
	.byte		VOICE , 81
	.byte		N04   , Cs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		VOL   , 31*mus_casino_mvl/mxv
	.byte		N96   , Gn3 
	.byte	W96
	.byte		N48   , Fn3 
	.byte	W48
	.byte		        Ds3 
	.byte	W48
	.byte		N64   , Fn3 
	.byte	W64
	.byte		N04   , Dn3 
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N04   , En3 
	.byte	W08
	.byte		N88   , Ds3 
	.byte	W88
	.byte		N04   , Cn3 
	.byte	W08
	.byte		N72   , Ds3 
	.byte	W72
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N04   , Ds3 
	.byte	W08
	.byte		N48   , Dn3 
	.byte	W48
	.byte		        Cn3 
	.byte	W48
	.byte		N88   , Dn3 
	.byte	W88
	.byte		N04   , As2 
	.byte	W08
	.byte		N48   , Cs3 
	.byte	W48
	.byte		        En3 
	.byte	W48
	.byte		N72   , Cn4 
	.byte	W72
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N48   , As3 
	.byte	W48
	.byte		        Gs3 
	.byte	W48
	.byte		N60   , As3 
	.byte	W60
	.byte	W02
	.byte		N04   , Gn3 
	.byte	W10
	.byte		N16   , As3 
	.byte	W16
	.byte		N04   , Gn3 
	.byte	W08
	.byte		N48   , Gs3 
	.byte	W48
	.byte		N36   , Gn3 
	.byte	W40
	.byte		N04   , Ds3 
	.byte	W08
	.byte		N72   , Gs3 
	.byte	W72
	.byte		N16   , As3 
	.byte	W16
	.byte		N08   , Gs3 
	.byte	W08
	.byte		N48   , Gn3 
	.byte	W48
	.byte		        Fn3 
	.byte	W48
	.byte		N60   , As3 
	.byte	W60
	.byte	W02
	.byte		N10   , Gn3 
	.byte	W10
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N08   , An3 
	.byte	W08
	.byte		N48   , As3 
	.byte	W48
	.byte		        Gn3 
	.byte	W48
	.byte		PAN   , c_v+0
	.byte		VOL   , 53*mus_casino_mvl/mxv
	.byte		N24   , Gs1 
	.byte	W96
	.byte		PAN   , c_v+0
	.byte		VOL   , 52*mus_casino_mvl/mxv
	.byte		N16   
	.byte	W16
	.byte		N04   , Gs2 
	.byte	W24
	.byte		        Gs1 
	.byte	W08
	.byte		N16   , Gs2 
	.byte	W24
	.byte		N24   , Gs1 
	.byte	W24
	.byte		        Gn1 
	.byte	W96
	.byte		N16   
	.byte	W16
	.byte		N04   , Gn2 
	.byte	W24
	.byte		        Gn1 
	.byte	W08
	.byte		N16   , Gn2 
	.byte	W16
	.byte		N04   , Gn1 
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N04   , Fs1 
	.byte	W08
	.byte		N24   , Fn1 
	.byte	W96
	.byte		N16   
	.byte	W16
	.byte		N04   , Fn2 
	.byte	W24
	.byte		        Fn1 
	.byte	W08
	.byte		N16   , Fn2 
	.byte	W16
	.byte		N04   , Fn1 
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N04   , En1 
	.byte	W08
	.byte		N16   , Ds1 
	.byte	W16
	.byte		N24   , Ds2 
	.byte	W24
	.byte		N04   , En1 
	.byte	W08
	.byte		N16   , Fn1 
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N04   
	.byte		N04   , Bn1 
	.byte	W24
	.byte		N08   , Fn1 
	.byte		N12   , As1 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N04   , An1 
	.byte	W08
	.byte		N24   , Gs1 
	.byte	W96
	.byte		N16   
	.byte	W16
	.byte		N04   , Gs2 
	.byte	W24
	.byte		        Gs1 
	.byte	W08
	.byte		N16   , Gs2 
	.byte	W24
	.byte		N24   , Gs1 
	.byte	W24
	.byte		        Gn1 
	.byte	W96
	.byte		N16   
	.byte	W16
	.byte		N04   , Gn2 
	.byte	W24
	.byte		        Gn1 
	.byte	W08
	.byte		N16   , Gn2 
	.byte	W16
	.byte		N04   , Gn1 
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N04   , As1 
	.byte	W08
	.byte		N24   , Bn1 
	.byte	W96
	.byte		N16   
	.byte	W16
	.byte		N04   , Fs2 
	.byte	W24
	.byte		        Bn1 
	.byte	W08
	.byte		N16   , Bn2 
	.byte	W16
	.byte		N04   , Bn1 
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N04   , Fs1 
	.byte	W08
	.byte		N16   , As1 
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_casino_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_casino_8:
	.byte	KEYSH , mus_casino_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 54*mus_casino_mvl/mxv
	.byte	W06
mus_casino_8_B1:
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
	.byte		VOL   , 65*mus_casino_mvl/mxv
	.byte		N48   , An2 , v112
	.byte	W24
	.byte		N08   , Cn1 
	.byte		N08   , En1 
	.byte	W24
	.byte		N04   , Dn1 
	.byte	W04
	.byte		        Dn1 , v072
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		        Dn1 , v112
	.byte	W08
	.byte		N08   , Cn1 
	.byte		N08   , En1 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Dn1 
	.byte	W08
mus_casino_8_000:
	.byte		N04   , Cn1 , v112
	.byte	W48
	.byte		        En1 
	.byte	W24
	.byte		        Cn1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte	PEND
mus_casino_8_001:
	.byte	W16
	.byte		N04   , Cn1 , v112
	.byte	W32
	.byte		        En1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Cn1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_casino_8_000
	.byte	W16
	.byte		N04   , Cn1 , v112
	.byte	W32
	.byte		        Dn1 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		        Cn1 
	.byte	W16
	.byte		        En1 
	.byte	W08
	.byte	PATT
	 .word	mus_casino_8_000
	.byte	PATT
	 .word	mus_casino_8_001
	.byte	PATT
	 .word	mus_casino_8_000
	.byte	W16
	.byte		N04   , Cn1 , v112
	.byte	W32
	.byte		        Dn1 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		        Cn1 
	.byte	W24
	.byte		VOL   , 54*mus_casino_mvl/mxv
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
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		N04   , Dn1 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte	GOTO
	 .word	mus_casino_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_casino_9:
	.byte	KEYSH , mus_casino_key+0
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 36*mus_casino_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W06
mus_casino_9_B1:
	.byte		BEND  , c_v+2
	.byte		N08   , As4 , v120
	.byte	W72
	.byte		        As3 , v112
	.byte	W24
	.byte		        Gs4 
	.byte	W16
	.byte		        Gn4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N08   , Ds4 
	.byte	W24
	.byte		        Gn4 
	.byte	W32
	.byte	W16
	.byte		N32   , Dn4 
	.byte	W32
	.byte		N08   , Ds4 
	.byte	W24
	.byte		N20   
	.byte	W24
	.byte		N16   , En4 
	.byte	W24
	.byte		N08   
	.byte	W16
	.byte		        Fn4 
	.byte	W24
	.byte		        As4 
	.byte	W32
mus_casino_9_000:
	.byte		N08   , Ds1 , v112
	.byte	W16
	.byte		        Ds2 
	.byte	W08
	.byte		N16   , Dn2 
	.byte	W24
	.byte		        Cs2 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte	PEND
mus_casino_9_001:
	.byte		N08   , As1 , v112
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W24
	.byte		        Cs2 
	.byte	W24
	.byte		N08   , Cn2 
	.byte	W16
	.byte		        Gn1 
	.byte	W08
	.byte	PEND
mus_casino_9_002:
	.byte		N08   , Fn1 , v112
	.byte	W16
	.byte		        Fn2 
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		N16   , Fn2 
	.byte	W24
	.byte		N08   , En2 
	.byte	W16
	.byte		        Ds2 
	.byte	W08
	.byte	PEND
mus_casino_9_003:
	.byte		N16   , Dn2 , v112
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		        Gs1 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_casino_9_000
	.byte	PATT
	 .word	mus_casino_9_001
mus_casino_9_004:
	.byte		N08   , Fn1 , v112
	.byte	W16
	.byte		        Fn2 
	.byte	W08
	.byte		N16   , En2 
	.byte	W24
	.byte		        Ds2 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte	PEND
	.byte		N08   
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		N16   , Fn1 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte	PATT
	 .word	mus_casino_9_000
	.byte	PATT
	 .word	mus_casino_9_001
	.byte	PATT
	 .word	mus_casino_9_002
	.byte	PATT
	 .word	mus_casino_9_003
	.byte	PATT
	 .word	mus_casino_9_000
	.byte	PATT
	 .word	mus_casino_9_001
	.byte	PATT
	 .word	mus_casino_9_004
	.byte		N08   , As1 , v112
	.byte	W96
	.byte		VOICE , 83
	.byte		VOL   , 27*mus_casino_mvl/mxv
	.byte	W24
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N24   , Ds4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		N08   , Fn4 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N16   , Cs4 
	.byte	W16
	.byte		N08   , Dn4 
	.byte	W08
	.byte		N24   , Cn5 
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		N16   , Gn4 
	.byte	W16
	.byte		N24   , Gs4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		N08   , As4 
	.byte	W08
	.byte		N16   , Gn4 
	.byte	W16
	.byte		N08   , Ds4 
	.byte	W08
	.byte	W24
	.byte		N24   , Gs4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N04   , En4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N16   , Cs4 
	.byte	W16
	.byte		N08   , Dn4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N08   , Fn4 
	.byte	W08
	.byte	W24
	.byte		        As4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		N16   , Gn4 
	.byte	W16
	.byte		N08   , Fn4 
	.byte	W08
	.byte		N24   , Ds4 
	.byte	W24
	.byte	W16
	.byte		        En4 
	.byte	W24
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N16   , En4 
	.byte	W16
	.byte		N08   , As3 
	.byte	W08
	.byte		N16   , Gn4 
	.byte	W16
	.byte		N08   , En4 
	.byte	W08
	.byte	W24
	.byte		N24   , Gs4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N08   , Cs4 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N16   , En4 
	.byte	W16
	.byte		N08   , Fn4 
	.byte	W08
	.byte	W24
	.byte		N16   
	.byte	W16
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N08   , Cs4 
	.byte	W08
	.byte		N24   , Dn5 
	.byte	W24
	.byte		N48   , Cn5 
	.byte	W48
	.byte		N40   , As4 
	.byte	W40
	.byte		N04   , Gn4 
	.byte	W08
	.byte		N24   , Gs4 
	.byte	W24
	.byte		        Ds5 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		N16   , Dn5 
	.byte	W16
	.byte		N24   , Cn5 
	.byte	W24
	.byte		N08   , Dn5 
	.byte	W08
	.byte		N16   , As4 
	.byte	W16
	.byte		N08   , Dn4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N08   , Fn4 
	.byte	W08
	.byte		N64   , As4 
	.byte	W64
	.byte		N08   , Dn4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N08   , Fn4 
	.byte	W08
	.byte		N48   , As4 
	.byte	W48
	.byte		        Cs5 
	.byte	W48
	.byte		VOICE , 82
	.byte		VOL   , 30*mus_casino_mvl/mxv
	.byte		PAN   , c_v-64
	.byte		BEND  , c_v+0
	.byte		N40   , Ds4 
	.byte	W40
	.byte		N04   , Cn4 
	.byte	W08
	.byte		        Gn4 
	.byte	W24
	.byte		        Gs3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Gn4 
	.byte	W16
	.byte		        Fs4 
	.byte	W08
	.byte		        Fn4 
	.byte	W16
	.byte		        En4 
	.byte	W08
	.byte		        Ds4 
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte		N40   , As3 
	.byte	W40
	.byte		N04   , Gn3 
	.byte	W08
	.byte		        Gs3 
	.byte	W16
	.byte		        As3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		N40   , Dn4 
	.byte	W40
	.byte		N04   , Cn4 
	.byte	W08
	.byte		N16   , As3 
	.byte	W16
	.byte		N04   , Gn3 
	.byte	W08
	.byte		N40   , Gs3 
	.byte	W40
	.byte		N04   , Fn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W16
	.byte		        Gs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W16
	.byte		N32   , Gs3 
	.byte	W32
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N04   , As3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N04   , Fn3 
	.byte	W08
	.byte	W16
	.byte		N24   , Gn3 
	.byte	W32
	.byte		N16   , Gs3 
	.byte	W24
	.byte		N16   
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		N24   , As3 
	.byte	W32
	.byte		        Bn3 
	.byte	W24
	.byte	W24
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N08   , Gn4 
	.byte	W32
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N08   , Gn4 
	.byte	W08
	.byte		N16   , Cn5 
	.byte	W16
	.byte		N04   , As4 , v092
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		N16   , Fn4 , v112
	.byte	W16
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N16   , Gn3 
	.byte	W16
	.byte		N08   , As3 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N08   , Fn4 
	.byte	W32
	.byte		N16   , Gn3 
	.byte	W16
	.byte		N08   , As3 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N24   , As4 
	.byte	W24
	.byte		N04   , Gs4 , v088
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		N16   , Dn4 , v112
	.byte	W16
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N16   , As4 
	.byte	W16
	.byte		N08   , Gs4 
	.byte	W08
	.byte		        Fs4 
	.byte	W16
	.byte		N08   
	.byte	W32
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N08   , Fs4 
	.byte	W08
	.byte		N24   , As4 
	.byte	W24
	.byte		N16   , Gs4 
	.byte	W16
	.byte		N08   , Fn4 
	.byte	W08
	.byte		N16   , Fs4 
	.byte	W24
	.byte		        Dn4 
	.byte	W16
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N72   , Fn4 
	.byte	W72
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N08   , Fn4 
	.byte	W08
	.byte		N48   , As4 
	.byte	W72
	.byte		N08   , Gn4 
	.byte	W08
	.byte		N04   , Gs4 
	.byte	W08
	.byte		N08   , An4 
	.byte	W08
	.byte	GOTO
	 .word	mus_casino_9_B1
	.byte	FINE

@********************** Track 10 **********************@

mus_casino_10:
	.byte	KEYSH , mus_casino_key+0
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+16
	.byte		VOL   , 49*mus_casino_mvl/mxv
	.byte	W06
mus_casino_10_B1:
	.byte		N08   , As3 , v112
	.byte	W96
	.byte		        As2 
	.byte	W96
	.byte		        Cn3 
	.byte	W96
	.byte	W16
	.byte		N32   , Gs3 
	.byte	W32
	.byte		N08   
	.byte	W24
	.byte		N20   
	.byte	W24
	.byte		N16   , As3 
	.byte	W24
	.byte		N08   
	.byte	W16
	.byte		N08   
	.byte	W24
	.byte		        As5 , v068
	.byte	W32
	.byte		VOICE , 56
	.byte	W16
	.byte		N08   , As3 , v112
	.byte	W56
	.byte		        Ds3 
	.byte	W24
	.byte		        Cs4 
	.byte	W16
	.byte		        As3 
	.byte	W24
	.byte		        En3 
	.byte	W08
	.byte		        Gn3 
	.byte	W24
	.byte		N24   , As3 
	.byte	W24
	.byte	W16
	.byte		N04   , Cn4 
	.byte	W32
	.byte		N24   
	.byte	W48
	.byte		N08   , Dn4 
	.byte	W16
	.byte		        Cn4 
	.byte	W24
	.byte		        As3 
	.byte	W08
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N08   , An3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N72   , As3 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		VOICE , 60
	.byte		N04   
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Ds3 
	.byte	W16
	.byte		N08   , As3 
	.byte	W08
	.byte		N02   , An3 , v064
	.byte	W02
	.byte		        Gs3 , v068
	.byte	W02
	.byte		        Gn3 
	.byte	W02
	.byte		        Fs3 , v064
	.byte	W02
	.byte		        Fn3 , v068
	.byte	W02
	.byte		        En3 
	.byte	W36
	.byte	W02
	.byte		N08   , Ds3 , v112
	.byte	W24
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N08   , As3 
	.byte	W16
	.byte		        Gn3 
	.byte	W08
	.byte		N24   , As3 
	.byte	W24
	.byte		N08   , Cs4 
	.byte	W16
	.byte		        Gn3 
	.byte	W08
	.byte	W16
	.byte		        Ds4 
	.byte	W32
	.byte		N24   , Cn4 
	.byte	W44
	.byte	W02
	.byte		        Dn4 
	.byte	W02
	.byte	W24
	.byte		N04   , Cn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W10
	.byte		        Cn4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        As3 
	.byte	W06
	.byte		        Fn3 
	.byte	W10
	.byte		N72   , Ds3 
	.byte	W72
	.byte		N04   , Fn3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N08   , As3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		N16   , Cs3 
	.byte	W16
	.byte		N08   , Gn3 
	.byte	W08
	.byte		N24   , Cs4 
	.byte	W24
	.byte		VOICE , 56
	.byte	W16
	.byte		N04   , Cn4 
	.byte	W32
	.byte		N16   
	.byte	W24
	.byte		N20   
	.byte	W24
	.byte		N08   , Dn4 
	.byte	W08
	.byte		N02   , Cs4 , v064
	.byte	W02
	.byte		        Cn4 , v068
	.byte	W02
	.byte		        Bn3 
	.byte	W02
	.byte		        As3 , v064
	.byte	W80
	.byte	W02
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
	.byte		VOICE , 1
	.byte		N04   , Cn3 , v112
	.byte	W96
	.byte	W16
	.byte		N04   
	.byte	W32
	.byte		N16   
	.byte	W24
	.byte		N04   , Bn2 
	.byte	W24
	.byte		        As2 
	.byte	W96
	.byte	W16
	.byte		N04   
	.byte	W32
	.byte		N16   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		        Gs2 
	.byte	W96
	.byte	W16
	.byte		N04   
	.byte	W32
	.byte		N16   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte	W16
	.byte		N24   , Gn2 
	.byte	W32
	.byte		N16   , Gs2 
	.byte	W24
	.byte		N16   
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		N24   , As2 
	.byte	W32
	.byte		        Dn3 
	.byte	W24
	.byte		N04   , Cn3 
	.byte	W08
	.byte		        Cn3 , v052
	.byte	W08
	.byte		        Cn3 , v088
	.byte	W08
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		        Cn3 , v112
	.byte	W32
	.byte		N16   
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		N04   , As2 
	.byte	W08
	.byte		        As2 , v048
	.byte	W08
	.byte		        As2 , v088
	.byte	W08
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		        As2 , v112
	.byte	W32
	.byte		N16   
	.byte	W24
	.byte		N16   
	.byte	W24
mus_casino_10_000:
	.byte		N04   , Ds3 , v112
	.byte	W08
	.byte		        Ds3 , v048
	.byte	W08
	.byte		        Ds3 , v088
	.byte	W08
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte	PEND
	.byte		N04   
	.byte	W16
	.byte		        Ds3 , v112
	.byte	W32
	.byte		N16   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte	PATT
	 .word	mus_casino_10_000
	.byte		N04   , Dn3 , v088
	.byte	W16
	.byte		        Dn3 , v112
	.byte	W32
	.byte		        Dn3 , v088
	.byte	W16
	.byte		        Dn3 , v112
	.byte	W32
	.byte	GOTO
	 .word	mus_casino_10_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_casino:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_casino_pri	@ Priority
	.byte	mus_casino_rev	@ Reverb.

	.word	mus_casino_grp

	.word	mus_casino_1
	.word	mus_casino_2
	.word	mus_casino_3
	.word	mus_casino_4
	.word	mus_casino_5
	.word	mus_casino_6
	.word	mus_casino_7
	.word	mus_casino_8
	.word	mus_casino_9
	.word	mus_casino_10

	.end
