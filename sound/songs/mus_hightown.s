	.include "MPlayDef.s"

	.equ	mus_hightown_grp, voicegroup073
	.equ	mus_hightown_pri, 0
	.equ	mus_hightown_rev, reverb_set+50
	.equ	mus_hightown_mvl, 127
	.equ	mus_hightown_key, 0
	.equ	mus_hightown_tbs, 1
	.equ	mus_hightown_exg, 0
	.equ	mus_hightown_cmp, 1

	.section .rodata
	.global	mus_hightown
	.align	2

@********************** Track  1 **********************@

mus_hightown_1:
	.byte	KEYSH , mus_hightown_key+0
mus_hightown_1_B1:
	.byte	TEMPO , 94*mus_hightown_tbs/2
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 30*mus_hightown_mvl/mxv
	.byte		N02   , En5 , v112
	.byte	W16
	.byte		        En5 , v072
	.byte	W08
	.byte		        En5 , v084
	.byte	W16
	.byte		        En5 , v072
	.byte	W08
	.byte		        En5 , v112
	.byte	W16
	.byte		        En5 , v072
	.byte	W08
	.byte		        En5 , v088
	.byte	W16
	.byte		        En5 , v072
	.byte	W08
mus_hightown_1_000:
	.byte		N02   , En5 , v112
	.byte	W16
	.byte		        En5 , v072
	.byte	W08
	.byte		        En5 , v084
	.byte	W16
	.byte		        En5 , v072
	.byte	W08
	.byte		        En5 , v112
	.byte	W16
	.byte		        En5 , v072
	.byte	W08
	.byte		        En5 , v088
	.byte	W16
	.byte		        En5 , v072
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_hightown_1_000
	.byte	PATT
	 .word	mus_hightown_1_000
	.byte	PATT
	 .word	mus_hightown_1_000
	.byte	PATT
	 .word	mus_hightown_1_000
	.byte		N02   , En5 , v112
	.byte	W16
	.byte		        En5 , v072
	.byte	W08
	.byte		        En5 , v084
	.byte	W16
	.byte		        En5 , v088
	.byte	W08
	.byte		        En5 , v112
	.byte	W16
	.byte		        En5 , v072
	.byte	W08
	.byte		        En5 , v088
	.byte	W16
	.byte		        En5 , v072
	.byte	W08
	.byte	PATT
	 .word	mus_hightown_1_000
	.byte	PATT
	 .word	mus_hightown_1_000
	.byte	PATT
	 .word	mus_hightown_1_000
	.byte		PAN   , c_v+63
	.byte		VOL   , 28*mus_hightown_mvl/mxv
	.byte		N02   , En5 , v116
	.byte	W08
	.byte		        En5 , v072
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		        En5 , v124
	.byte	W08
	.byte		        En5 , v072
	.byte	W08
	.byte		        En5 , v068
	.byte	W08
	.byte		        En5 , v084
	.byte	W08
	.byte		        En5 , v127
	.byte	W08
	.byte		        En5 , v072
	.byte	W08
	.byte		        En5 , v124
	.byte	W08
	.byte		        En5 , v084
	.byte	W08
	.byte		        En5 , v092
	.byte	W08
	.byte		        En5 , v116
	.byte	W08
	.byte		        En5 , v072
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		        En5 , v124
	.byte	W08
	.byte		        En5 , v072
	.byte	W08
	.byte		        En5 , v068
	.byte	W08
	.byte		        En5 , v088
	.byte	W08
	.byte		        En5 , v124
	.byte	W08
	.byte		        En5 , v072
	.byte	W08
	.byte		        En5 , v124
	.byte	W08
	.byte		        En5 , v072
	.byte	W08
	.byte		N08   , Gs5 , v096
	.byte	W08
	.byte		N02   , En5 , v116
	.byte	W08
	.byte		        En5 , v072
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		        En5 , v124
	.byte	W08
	.byte		        En5 , v072
	.byte	W08
	.byte		        En5 , v068
	.byte	W08
	.byte		        En5 , v084
	.byte	W08
	.byte		        En5 , v127
	.byte	W08
	.byte		        En5 , v072
	.byte	W08
	.byte		        En5 , v124
	.byte	W08
	.byte		        En5 , v084
	.byte	W08
	.byte		        En5 , v092
	.byte	W08
	.byte		        En5 , v116
	.byte	W08
	.byte		        En5 , v072
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		        En5 , v124
	.byte	W08
	.byte		        En5 , v072
	.byte	W08
	.byte		        En5 , v068
	.byte	W08
	.byte		        En5 , v088
	.byte	W08
	.byte		        En5 , v124
	.byte	W08
	.byte		        En5 , v072
	.byte	W08
	.byte		        En5 , v124
	.byte	W08
	.byte		        En5 , v072
	.byte	W06
	.byte		VOICE , 126
	.byte	W02
	.byte		N08   , Gs5 , v096
	.byte	W08
mus_hightown_1_001:
	.byte		VOICE , 127
	.byte		N02   , En5 , v116
	.byte	W08
	.byte		        En5 , v072
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		        En5 , v124
	.byte	W08
	.byte		        En5 , v072
	.byte	W08
	.byte		        En5 , v068
	.byte	W08
	.byte		        En5 , v084
	.byte	W08
	.byte		        En5 , v127
	.byte	W08
	.byte		        En5 , v072
	.byte	W08
	.byte		        En5 , v124
	.byte	W08
	.byte		        En5 , v084
	.byte	W08
	.byte		        En5 , v092
	.byte	W08
	.byte	PEND
mus_hightown_1_002:
	.byte		N02   , En5 , v116
	.byte	W08
	.byte		        En5 , v072
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		        En5 , v124
	.byte	W08
	.byte		        En5 , v072
	.byte	W08
	.byte		        En5 , v068
	.byte	W08
	.byte		        En5 , v088
	.byte	W08
	.byte		        En5 , v124
	.byte	W08
	.byte		        En5 , v072
	.byte	W08
	.byte		        En5 , v124
	.byte	W08
	.byte		        En5 , v072
	.byte	W08
	.byte		VOICE , 126
	.byte		N08   , Gs5 , v096
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_hightown_1_001
	.byte	PATT
	 .word	mus_hightown_1_002
	.byte	PATT
	 .word	mus_hightown_1_001
	.byte	PATT
	 .word	mus_hightown_1_002
	.byte	PATT
	 .word	mus_hightown_1_001
	.byte	PATT
	 .word	mus_hightown_1_002
	.byte	PATT
	 .word	mus_hightown_1_001
	.byte	PATT
	 .word	mus_hightown_1_002
	.byte	PATT
	 .word	mus_hightown_1_001
	.byte	PATT
	 .word	mus_hightown_1_002
	.byte	GOTO
	 .word	mus_hightown_1_B1
	.byte		VOICE , 127
	.byte	FINE

@********************** Track  2 **********************@

mus_hightown_2:
	.byte	KEYSH , mus_hightown_key+0
mus_hightown_2_B1:
	.byte		VOICE , 46
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 49*mus_hightown_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N04   , An4 , v112
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		N40   , Dn4 
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
	.byte		VOICE , 73
	.byte	W48
	.byte		PAN   , c_v+0
	.byte	W16
	.byte		N04   , Fs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		N16   , En5 
	.byte	W08
	.byte		MOD   , 5
	.byte	W08
	.byte		        0
	.byte		N04   , Dn5 
	.byte	W24
	.byte		        Fs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		N16   , En5 
	.byte	W08
	.byte		MOD   , 5
	.byte	W08
	.byte		        0
	.byte		N04   , Dn5 
	.byte	W24
	.byte		        Fs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		N16   , En5 
	.byte	W08
	.byte		MOD   , 5
	.byte	W08
	.byte		        0
	.byte		N04   , Dn5 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        An4 
	.byte	W06
	.byte		N02   , Gn5 , v080
	.byte	W02
	.byte		N24   , Fs5 , v112
	.byte	W24
	.byte		N16   , En5 
	.byte	W08
	.byte		MOD   , 5
	.byte	W08
	.byte		        0
	.byte		N04   , Dn5 
	.byte	W08
	.byte		N08   , Gn5 
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		N36   , Dn5 
	.byte	W12
	.byte		MOD   , 5
	.byte	W04
	.byte		VOL   , 45*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        42*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        37*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        34*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        32*mus_hightown_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 49*mus_hightown_mvl/mxv
	.byte	W02
	.byte		N02   , Bn4 , v080
	.byte	W02
	.byte		N08   , As4 , v112
	.byte	W08
	.byte		N04   , Fs5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		N48   , En5 
	.byte	W12
	.byte		MOD   , 5
	.byte		VOL   , 46*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        44*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        42*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        39*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        37*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        35*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        33*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        31*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        27*mus_hightown_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 49*mus_hightown_mvl/mxv
	.byte	W24
	.byte		N04   , An5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Fs5 
	.byte	W04
	.byte		        En5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Ds5 
	.byte	W04
	.byte		N16   , En5 
	.byte	W08
	.byte		MOD   , 5
	.byte	W08
	.byte		        0
	.byte		N04   , Dn5 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Fs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		N16   , En5 
	.byte	W08
	.byte		MOD   , 5
	.byte	W08
	.byte		        0
	.byte		N04   , Dn5 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Fs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		N16   , En5 
	.byte	W08
	.byte		MOD   , 5
	.byte	W08
	.byte		        0
	.byte		N04   , Dn5 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		N08   , Fs5 
	.byte	W08
	.byte		N04   , Gn5 
	.byte	W08
	.byte		        An5 
	.byte	W08
	.byte		        Bn5 
	.byte	W08
	.byte		        An5 
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		N24   , Dn5 
	.byte	W24
	.byte		N04   , Gn5 
	.byte	W04
	.byte		        Fs5 
	.byte	W04
	.byte		        En5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		N24   , Bn4 
	.byte	W24
	.byte		N16   , Cs5 
	.byte	W16
	.byte		N04   , Dn5 
	.byte	W06
	.byte		N02   , Ds5 , v064
	.byte	W02
	.byte		N72   , Dn5 , v112
	.byte	W24
	.byte		MOD   , 5
	.byte		VOL   , 46*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        44*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        41*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        38*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        37*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        35*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        33*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        31*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        28*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        26*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        23*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        22*mus_hightown_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 49*mus_hightown_mvl/mxv
	.byte	W24
	.byte	GOTO
	 .word	mus_hightown_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_hightown_3:
	.byte	KEYSH , mus_hightown_key+0
mus_hightown_3_B1:
	.byte		VOICE , 17
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v-2
	.byte		VOL   , 49*mus_hightown_mvl/mxv
	.byte		N88   , An1 , v112
	.byte	W88
	.byte		N08   , En1 
	.byte	W08
	.byte		N96   , An1 
	.byte	W96
	.byte		VOICE , 35
	.byte		VOL   , 78*mus_hightown_mvl/mxv
	.byte		N12   , Dn2 
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , An1 
	.byte	W08
	.byte		N12   , Dn2 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , An1 
	.byte	W08
	.byte		N12   , Dn2 
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , An1 
	.byte	W08
	.byte		N12   , Dn2 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N12   , Cs2 
	.byte	W16
	.byte		N04   
	.byte	W08
mus_hightown_3_000:
	.byte		N08   , Bn1 , v112
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , Fs1 
	.byte	W08
	.byte		        Bn1 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , Fs1 
	.byte	W08
	.byte	PEND
	.byte		        Bn1 
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , Fs1 
	.byte	W08
	.byte		        Bn1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , An1 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		        Gn1 
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , Dn1 , v088
	.byte	W08
	.byte		        Gn1 , v112
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , Dn1 
	.byte	W08
mus_hightown_3_001:
	.byte		N08   , Gn1 , v112
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , Dn1 
	.byte	W08
	.byte		        Gn1 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , Dn1 
	.byte	W08
	.byte	PEND
mus_hightown_3_002:
	.byte		N08   , An1 , v112
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , En1 
	.byte	W08
	.byte		        An1 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , En1 
	.byte	W08
	.byte	PEND
	.byte		N04   , An1 
	.byte	W96
	.byte		N12   , Dn2 
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , An1 
	.byte	W08
	.byte		N12   , Dn2 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , An1 
	.byte	W08
	.byte		N12   , Dn2 
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , An1 
	.byte	W08
	.byte		N04   , Dn2 
	.byte	W08
	.byte		N12   
	.byte	W16
	.byte		        Cs2 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte	PATT
	 .word	mus_hightown_3_000
	.byte		N08   , Bn1 , v112
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , Fs1 
	.byte	W08
	.byte		N04   , Bn1 
	.byte	W08
	.byte		N12   
	.byte	W16
	.byte		N08   , An1 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte	PATT
	 .word	mus_hightown_3_001
	.byte	PATT
	 .word	mus_hightown_3_001
	.byte	PATT
	 .word	mus_hightown_3_002
	.byte		N04   , An1 , v112
	.byte	W96
mus_hightown_3_003:
	.byte		N12   , Dn1 , v112
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , An0 
	.byte	W08
	.byte		N12   , Dn1 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , An0 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_hightown_3_003
	.byte		N12   , Gn1 , v112
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , Dn1 
	.byte	W08
	.byte		N12   , Gn1 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , Dn1 
	.byte	W08
	.byte		N12   , An1 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , En1 
	.byte	W08
	.byte		N12   , An1 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , En1 
	.byte	W08
	.byte	PATT
	 .word	mus_hightown_3_003
	.byte	PATT
	 .word	mus_hightown_3_003
	.byte		N12   , Gn1 , v112
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , Dn1 
	.byte	W08
	.byte		N12   , An1 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , En1 
	.byte	W08
	.byte		N12   , Dn2 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , An1 
	.byte	W08
	.byte		N12   , Dn1 
	.byte	W16
	.byte		N04   
	.byte	W32
	.byte	GOTO
	 .word	mus_hightown_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_hightown_4:
	.byte	KEYSH , mus_hightown_key+0
mus_hightown_4_B1:
	.byte		VOICE , 73
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 50*mus_hightown_mvl/mxv
	.byte		N24   , Cs4 , v112
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		VOICE , 17
	.byte		VOL   , 65*mus_hightown_mvl/mxv
	.byte		N08   , An3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		VOICE , 17
	.byte		VOL   , 63*mus_hightown_mvl/mxv
	.byte		N40   , Gn4 
	.byte	W40
	.byte		N04   , Fs4 
	.byte	W08
	.byte		N24   
	.byte	W48
mus_hightown_4_000:
	.byte	W32
	.byte		N04   , En4 , v112
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		N02   , Gn4 
	.byte	W02
	.byte		        An4 
	.byte	W02
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte	PEND
	.byte		N40   , En4 
	.byte	W40
	.byte		N04   , Dn4 
	.byte	W08
	.byte		N24   
	.byte	W48
	.byte	W32
	.byte		N04   , Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W06
	.byte		N02   , Gn4 , v060
	.byte	W02
	.byte		N04   , Fs4 , v112
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N36   , An4 
	.byte	W36
	.byte		N02   , Bn4 , v048
	.byte	W02
	.byte		        As4 , v060
	.byte	W02
	.byte		N04   , An4 , v088
	.byte	W08
	.byte		N24   , Gn4 , v112
	.byte	W48
	.byte	W32
	.byte		N04   , Bn3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		N02   , An4 
	.byte	W02
	.byte		        Bn4 
	.byte	W02
	.byte		N04   , An4 
	.byte	W04
	.byte		        Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		VOL   , 7*mus_hightown_mvl/mxv
	.byte		N96   , En4 
	.byte	W10
	.byte		VOL   , 9*mus_hightown_mvl/mxv
	.byte	W02
	.byte		        9*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        11*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        15*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        17*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        21*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        22*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        26*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        28*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        32*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        35*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        36*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        39*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        43*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        44*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        46*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        48*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        50*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        52*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        54*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        56*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        58*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        60*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        61*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        63*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        63*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        65*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        65*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        66*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        68*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        68*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        71*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        73*mus_hightown_mvl/mxv
	.byte	W16
	.byte		        68*mus_hightown_mvl/mxv
	.byte		N04   , An4 
	.byte	W24
	.byte		VOICE , 46
	.byte	W48
	.byte		VOL   , 78*mus_hightown_mvl/mxv
	.byte		N04   , Gn4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		N40   , Gn4 
	.byte	W24
	.byte		MOD   , 5
	.byte	W16
	.byte		        0
	.byte		N04   , An4 
	.byte	W08
	.byte		N24   , Fs4 
	.byte	W48
	.byte	PATT
	 .word	mus_hightown_4_000
	.byte		N40   , En4 , v112
	.byte	W24
	.byte		MOD   , 5
	.byte	W16
	.byte		        0
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		N24   , Dn4 
	.byte	W48
	.byte	W32
	.byte		N04   , Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N02   , En4 
	.byte	W02
	.byte		        Fs4 
	.byte	W02
	.byte		N04   , En4 
	.byte	W04
	.byte		        Dn4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N40   , An4 
	.byte	W24
	.byte		MOD   , 5
	.byte	W16
	.byte		        0
	.byte		N04   , Bn4 
	.byte	W08
	.byte		N24   , Gn4 
	.byte	W48
	.byte	W32
	.byte		N04   , Bn3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		N02   , An4 
	.byte	W02
	.byte		        Bn4 
	.byte	W02
	.byte		N04   , An4 
	.byte	W04
	.byte		        Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W04
	.byte		MOD   , 5
	.byte	W04
	.byte		N88   , En4 
	.byte	W12
	.byte		MOD   , 0
	.byte	W76
	.byte		N04   , Fs4 
	.byte	W08
	.byte		VOL   , 40*mus_hightown_mvl/mxv
	.byte		N04   , Gn4 
	.byte	W24
	.byte		VOICE , 48
	.byte	W24
	.byte		N04   , Cs3 
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
mus_hightown_4_001:
	.byte		N48   , An3 , v112
	.byte	W48
	.byte		        As3 
	.byte	W48
	.byte	PEND
mus_hightown_4_002:
	.byte		N48   , Bn3 , v112
	.byte	W48
	.byte		        Cn4 
	.byte	W48
	.byte	PEND
	.byte		N08   , Gn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		N24   , Bn2 
	.byte	W24
	.byte		N48   , As2 
	.byte	W48
	.byte		N08   , An2 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		N64   , An3 
	.byte	W64
	.byte		N08   , Gs3 
	.byte	W08
	.byte	PATT
	 .word	mus_hightown_4_001
	.byte	PATT
	 .word	mus_hightown_4_002
	.byte		N48   , Gn4 , v112
	.byte	W48
	.byte		        Gn3 
	.byte	W48
	.byte		N16   , Fs3 
	.byte	W16
	.byte		N04   , Gn3 
	.byte	W08
	.byte		N02   , Fs3 
	.byte	W02
	.byte		        Gn3 
	.byte	W02
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N04   , En3 
	.byte	W08
	.byte		N24   , Fs3 
	.byte	W24
	.byte		VOICE , 73
	.byte	W16
	.byte		N04   , Gn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte	GOTO
	 .word	mus_hightown_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_hightown_5:
	.byte	KEYSH , mus_hightown_key+0
mus_hightown_5_B1:
	.byte		VOICE , 73
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 58*mus_hightown_mvl/mxv
	.byte		PAN   , c_v+14
	.byte		N24   , An4 , v112
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		N48   , Cs4 
	.byte	W48
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
	.byte		VOICE , 73
	.byte	W88
	.byte		N04   , En4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte	GOTO
	 .word	mus_hightown_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_hightown_6:
	.byte	KEYSH , mus_hightown_key+0
mus_hightown_6_B1:
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 26*mus_hightown_mvl/mxv
	.byte	W96
	.byte	W96
	.byte		N32   , Dn3 , v112
	.byte	W32
	.byte		N04   , Cs3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N24   , Fs3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		N48   , Dn3 
	.byte	W48
	.byte		N24   , En3 
	.byte	W24
	.byte		N16   , Fs3 
	.byte	W16
	.byte		N04   , Cs3 
	.byte	W08
	.byte		N24   , Dn3 
	.byte	W32
	.byte		N04   , Cs3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N24   , Fs3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		N32   , Dn3 
	.byte	W32
	.byte		N04   , Cs3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N24   , Bn2 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		        Gn3 
	.byte	W32
	.byte		N04   , Dn3 
	.byte	W08
	.byte		        Gn3 , v088
	.byte	W08
	.byte		N24   , Bn2 , v112
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		N32   , Dn3 
	.byte	W32
	.byte		N04   , Bn2 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N40   , Gn2 
	.byte	W40
	.byte		N04   , Bn2 
	.byte	W08
	.byte		N96   , Cs3 
	.byte	W24
	.byte		MOD   , 4
	.byte	W24
	.byte		VOL   , 23*mus_hightown_mvl/mxv
	.byte	W02
	.byte		        25*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        26*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        28*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        29*mus_hightown_mvl/mxv
	.byte	W02
	.byte		        32*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        33*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        35*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        36*mus_hightown_mvl/mxv
	.byte	W02
	.byte		        38*mus_hightown_mvl/mxv
	.byte	W22
	.byte		        29*mus_hightown_mvl/mxv
	.byte		MOD   , 0
	.byte		N04   , An3 
	.byte	W24
	.byte		VOL   , 39*mus_hightown_mvl/mxv
	.byte	W48
	.byte		PAN   , c_v-58
	.byte	W24
	.byte		VOICE , 84
	.byte		VOL   , 33*mus_hightown_mvl/mxv
	.byte		N08   , Fs3 , v120
	.byte	W08
	.byte		N02   , Fs3 , v104
	.byte	W04
	.byte		        Fn3 , v080
	.byte	W04
	.byte		        Fs3 
	.byte	W08
	.byte		N04   , Fs3 , v112
	.byte	W12
	.byte		N02   , Fs3 , v104
	.byte	W04
	.byte		        Fn3 , v080
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		N08   , Fs3 , v120
	.byte	W08
	.byte		N02   , Fs3 , v104
	.byte	W04
	.byte		        Fn3 , v080
	.byte	W04
	.byte		        Fs3 
	.byte	W08
	.byte		N04   , Fs3 , v112
	.byte	W12
	.byte		N02   , Fs3 , v104
	.byte	W04
	.byte		        Fs3 , v080
	.byte	W08
mus_hightown_6_000:
	.byte		N08   , Fs3 , v120
	.byte	W08
	.byte		N02   , Fs3 , v104
	.byte	W04
	.byte		        Fn3 , v080
	.byte	W04
	.byte		        Fs3 
	.byte	W08
	.byte		N04   , Fs3 , v112
	.byte	W12
	.byte		N02   , Fs3 , v104
	.byte	W04
	.byte		        Fn3 , v080
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		N08   , Fs3 , v120
	.byte	W08
	.byte		N02   , Fs3 , v104
	.byte	W04
	.byte		        Fn3 , v080
	.byte	W04
	.byte		        Fs3 
	.byte	W08
	.byte		N04   , Fs3 , v112
	.byte	W12
	.byte		N02   , Fs3 , v104
	.byte	W04
	.byte		        Fs3 , v080
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte	PEND
mus_hightown_6_001:
	.byte		N08   , Fs3 , v120
	.byte	W08
	.byte		N02   , Fs3 , v104
	.byte	W04
	.byte		        Fn3 , v080
	.byte	W04
	.byte		        Fs3 
	.byte	W08
	.byte		N04   , Fs3 , v112
	.byte	W12
	.byte		N02   , Fs3 , v104
	.byte	W04
	.byte		        Fn3 , v080
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		N08   , Fs3 , v120
	.byte	W08
	.byte		N02   , Fs3 , v104
	.byte	W04
	.byte		        Fn3 , v080
	.byte	W04
	.byte		        Fs3 
	.byte	W08
	.byte		N04   , Fs3 , v112
	.byte	W12
	.byte		N02   , Fs3 , v104
	.byte	W04
	.byte		        Fs3 , v080
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_hightown_6_000
	.byte	PATT
	 .word	mus_hightown_6_001
	.byte		N08   , Fs3 , v120
	.byte	W08
	.byte		N02   , Fs3 , v104
	.byte	W04
	.byte		        Fn3 , v080
	.byte	W04
	.byte		        Fs3 
	.byte	W08
	.byte		N04   , Fs3 , v112
	.byte	W12
	.byte		N02   , Fs3 , v104
	.byte	W04
	.byte		        Fn3 , v080
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		N08   , Fs3 , v120
	.byte	W08
	.byte		N02   , Fs3 , v104
	.byte	W04
	.byte		        Fn3 , v080
	.byte	W04
	.byte		        Fs3 
	.byte	W08
	.byte		N04   , Fs3 , v112
	.byte	W12
	.byte		N02   , Fs3 , v104
	.byte	W04
	.byte		        Fn3 , v080
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		N08   , Gn3 , v120
	.byte	W08
	.byte		N02   , Gn3 , v104
	.byte	W04
	.byte		        Fs3 , v080
	.byte	W04
	.byte		        Gn3 
	.byte	W08
	.byte		N04   , Gn3 , v112
	.byte	W12
	.byte		N02   , Gn3 , v104
	.byte	W04
	.byte		        Fs3 , v080
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		N08   , En3 , v120
	.byte	W08
	.byte		N02   , En3 , v104
	.byte	W04
	.byte		        Ds3 , v080
	.byte	W04
	.byte		        En3 
	.byte	W08
	.byte		N04   , En3 , v112
	.byte	W12
	.byte		N02   , En3 , v104
	.byte	W04
	.byte		        Ds3 , v080
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		N04   , Gn3 , v112
	.byte	W24
	.byte		VOICE , 80
	.byte	W24
	.byte		N04   
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		TIE   , Fs4 
	.byte	W96
	.byte	W48
	.byte		EOT   
	.byte		N24   , An4 
	.byte	W24
	.byte		N08   , Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N48   , Bn3 
	.byte	W48
	.byte		        As3 
	.byte	W48
	.byte		        Dn4 
	.byte	W48
	.byte		N08   , Cs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N24   , Fn4 
	.byte	W24
	.byte		TIE   , Fs4 
	.byte	W96
	.byte	W48
	.byte		EOT   
	.byte		N24   , An4 
	.byte	W24
	.byte		N08   , Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N48   
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte		N72   
	.byte	W96
	.byte	GOTO
	 .word	mus_hightown_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_hightown_7:
	.byte	KEYSH , mus_hightown_key+0
mus_hightown_7_B1:
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-62
	.byte		VOL   , 32*mus_hightown_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		TIE   , En3 , v112
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		VOL   , 33*mus_hightown_mvl/mxv
	.byte		N32   , An2 
	.byte	W32
	.byte		N04   , Gs2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		N24   , Fs2 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		N48   , Fs2 
	.byte	W48
	.byte		N24   , Gn2 
	.byte	W24
	.byte		N16   , An2 
	.byte	W16
	.byte		N04   , Fs2 
	.byte	W08
	.byte		N24   , Gn2 
	.byte	W32
	.byte		N04   , Fs2 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		N32   , Fs2 
	.byte	W32
	.byte		N04   , Fn2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		N24   , Dn2 
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte		        Dn3 
	.byte	W32
	.byte		N04   , Bn2 
	.byte	W08
	.byte		        Dn3 , v088
	.byte	W08
	.byte		N24   , Gn2 , v112
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		N32   , Bn2 
	.byte	W32
	.byte		N04   , Gn2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		N40   , Dn2 
	.byte	W40
	.byte		N04   , Gn2 
	.byte	W08
	.byte		N96   , An2 
	.byte	W24
	.byte		MOD   , 4
	.byte	W24
	.byte		VOL   , 26*mus_hightown_mvl/mxv
	.byte	W02
	.byte		        27*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        29*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        31*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        32*mus_hightown_mvl/mxv
	.byte	W02
	.byte		        33*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        36*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        38*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        38*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        39*mus_hightown_mvl/mxv
	.byte	W21
	.byte		        29*mus_hightown_mvl/mxv
	.byte		MOD   , 0
	.byte		N04   , En3 
	.byte	W24
	.byte		VOL   , 39*mus_hightown_mvl/mxv
	.byte	W48
	.byte		PAN   , c_v+61
	.byte	W24
	.byte		VOICE , 83
	.byte		VOL   , 34*mus_hightown_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N08   , Dn4 , v120
	.byte	W08
	.byte		N02   , Dn4 , v104
	.byte	W04
	.byte		        Cs4 , v080
	.byte	W04
	.byte		        Dn4 
	.byte	W08
	.byte		N04   , Dn4 , v112
	.byte	W12
	.byte		N02   , Dn4 , v104
	.byte	W04
	.byte		        Cs4 , v080
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		N08   , Dn4 , v120
	.byte	W08
	.byte		N02   , Dn4 , v104
	.byte	W04
	.byte		        Cs4 , v080
	.byte	W04
	.byte		        Dn4 
	.byte	W08
	.byte		N04   , Dn4 , v112
	.byte	W12
	.byte		N02   , Dn4 , v104
	.byte	W04
	.byte		        Dn4 , v080
	.byte	W08
mus_hightown_7_000:
	.byte		N08   , Dn4 , v120
	.byte	W08
	.byte		N02   , Dn4 , v104
	.byte	W04
	.byte		        Cs4 , v080
	.byte	W04
	.byte		        Dn4 
	.byte	W08
	.byte		N04   , Dn4 , v112
	.byte	W12
	.byte		N02   , Dn4 , v104
	.byte	W04
	.byte		        Cs4 , v080
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		N08   , Dn4 , v120
	.byte	W08
	.byte		N02   , Dn4 , v104
	.byte	W04
	.byte		        Cs4 , v080
	.byte	W04
	.byte		        Dn4 
	.byte	W08
	.byte		N04   , Cs4 , v112
	.byte	W12
	.byte		N02   , Cs4 , v104
	.byte	W04
	.byte		        Cs4 , v080
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte	PEND
mus_hightown_7_001:
	.byte		N08   , Dn4 , v120
	.byte	W08
	.byte		N02   , Dn4 , v104
	.byte	W04
	.byte		        Cs4 , v080
	.byte	W04
	.byte		        Dn4 
	.byte	W08
	.byte		N04   , Dn4 , v112
	.byte	W12
	.byte		N02   , Dn4 , v104
	.byte	W04
	.byte		        Cs4 , v080
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		N08   , Dn4 , v120
	.byte	W08
	.byte		N02   , Dn4 , v104
	.byte	W04
	.byte		        Cs4 , v080
	.byte	W04
	.byte		        Dn4 
	.byte	W08
	.byte		N04   , Dn4 , v112
	.byte	W12
	.byte		N02   , Dn4 , v104
	.byte	W04
	.byte		        Dn4 , v080
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_hightown_7_000
	.byte	PATT
	 .word	mus_hightown_7_001
	.byte		N08   , Dn4 , v120
	.byte	W08
	.byte		N02   , Dn4 , v104
	.byte	W04
	.byte		        Cs4 , v080
	.byte	W04
	.byte		        Dn4 
	.byte	W08
	.byte		N04   , Dn4 , v112
	.byte	W12
	.byte		N02   , Dn4 , v104
	.byte	W04
	.byte		        Cs4 , v080
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		N08   , Dn4 , v120
	.byte	W08
	.byte		N02   , Dn4 , v104
	.byte	W04
	.byte		        Cs4 , v080
	.byte	W04
	.byte		        Dn4 
	.byte	W08
	.byte		N04   , Dn4 , v112
	.byte	W12
	.byte		N02   , Dn4 , v104
	.byte	W04
	.byte		        Cs4 , v080
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		N08   , En4 , v120
	.byte	W08
	.byte		N02   , En4 , v104
	.byte	W04
	.byte		        Ds4 , v080
	.byte	W04
	.byte		        En4 
	.byte	W08
	.byte		N04   , En4 , v112
	.byte	W12
	.byte		N02   , En4 , v104
	.byte	W04
	.byte		        Ds4 , v080
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		N08   , Cs4 , v120
	.byte	W08
	.byte		N02   , Cs4 , v104
	.byte	W04
	.byte		        Cn4 , v080
	.byte	W04
	.byte		        Cs4 
	.byte	W08
	.byte		N04   , Cs4 , v112
	.byte	W12
	.byte		N02   , Cs4 , v104
	.byte	W04
	.byte		        Cn4 , v080
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		N04   , En4 , v112
	.byte	W24
	.byte		VOICE , 81
	.byte	W24
	.byte		N04   , Cs4 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
mus_hightown_7_002:
	.byte		N48   , An4 , v112
	.byte	W48
	.byte		        As4 
	.byte	W48
	.byte	PEND
mus_hightown_7_003:
	.byte		N48   , Bn4 , v112
	.byte	W48
	.byte		        Cn5 
	.byte	W48
	.byte	PEND
	.byte		        Gn4 
	.byte	W48
	.byte		        Dn4 
	.byte	W48
	.byte		        En4 
	.byte	W48
	.byte		N08   , An4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		N24   , Gs4 
	.byte	W24
	.byte	PATT
	 .word	mus_hightown_7_002
	.byte	PATT
	 .word	mus_hightown_7_003
	.byte		N48   , Bn4 , v112
	.byte	W48
	.byte		        En4 
	.byte	W48
	.byte		N72   , An4 
	.byte	W96
	.byte	GOTO
	 .word	mus_hightown_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_hightown_8:
	.byte	KEYSH , mus_hightown_key+0
mus_hightown_8_B1:
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 78*mus_hightown_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		N04   , Dn1 , v112
	.byte	W04
	.byte		        En1 
	.byte	W04
	.byte		        Cn1 
	.byte	W04
	.byte		        En1 
	.byte	W04
	.byte		        Cn1 
	.byte	W08
	.byte		N04   
	.byte	W06
	.byte		N02   , En1 
	.byte	W02
	.byte		N08   , En1 , v124
	.byte	W08
	.byte		N04   , Cn1 , v112
	.byte	W08
mus_hightown_8_000:
	.byte		N04   , Cn1 , v112
	.byte	W24
	.byte		        En1 
	.byte	W16
	.byte		        Cn1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En1 
	.byte	W24
	.byte	PEND
mus_hightown_8_001:
	.byte		N04   , Cn1 , v112
	.byte	W24
	.byte		        En1 
	.byte	W16
	.byte		        Cn1 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		        En1 
	.byte	W16
	.byte		        Cn1 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_hightown_8_000
	.byte		N04   , Cn1 , v112
	.byte	W24
	.byte		        En1 
	.byte	W16
	.byte		        Cn1 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Dn1 
	.byte	W16
	.byte		        En1 
	.byte	W08
	.byte	PATT
	 .word	mus_hightown_8_000
	.byte	PATT
	 .word	mus_hightown_8_001
	.byte	PATT
	 .word	mus_hightown_8_000
	.byte		N04   , Cn1 , v112
	.byte	W08
	.byte		        Dn1 
	.byte	W16
	.byte		        En1 
	.byte	W08
	.byte		        Cn1 , v076
	.byte	W08
	.byte		        Cn1 , v112
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Dn1 
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		        Dn1 
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        Cn1 
	.byte	W08
	.byte	PATT
	 .word	mus_hightown_8_000
	.byte	PATT
	 .word	mus_hightown_8_001
	.byte	PATT
	 .word	mus_hightown_8_000
mus_hightown_8_002:
	.byte		N04   , Cn1 , v112
	.byte	W24
	.byte		        En1 
	.byte	W16
	.byte		        Cn1 
	.byte	W08
	.byte		        Dn1 
	.byte	W04
	.byte		        En1 
	.byte	W04
	.byte		        Cn1 
	.byte	W04
	.byte		        En1 
	.byte	W04
	.byte		        Cn1 
	.byte	W08
	.byte		        En1 , v080
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W08
	.byte		        En1 , v120
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_hightown_8_000
	.byte	PATT
	 .word	mus_hightown_8_001
	.byte	PATT
	 .word	mus_hightown_8_000
	.byte	PATT
	 .word	mus_hightown_8_002
	.byte	GOTO
	 .word	mus_hightown_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_hightown_9:
	.byte	KEYSH , mus_hightown_key+0
mus_hightown_9_B1:
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 31*mus_hightown_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+1
	.byte		N88   , An1 , v112
	.byte	W88
	.byte		N08   , En1 
	.byte	W08
	.byte		N96   , An1 
	.byte	W96
	.byte		VOL   , 35*mus_hightown_mvl/mxv
	.byte		N12   , Dn2 
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , An1 
	.byte	W08
	.byte		N12   , Dn2 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , An1 
	.byte	W08
	.byte		N12   , Dn2 
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , An1 
	.byte	W08
	.byte		N12   , Dn2 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N12   , Cs2 
	.byte	W16
	.byte		N04   
	.byte	W08
mus_hightown_9_000:
	.byte		N08   , Bn1 , v112
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , Fs1 
	.byte	W08
	.byte		        Bn1 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , Fs1 
	.byte	W08
	.byte	PEND
	.byte		        Bn1 
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , Fs1 
	.byte	W08
	.byte		        Bn1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , An1 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		        Gn1 
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , Dn1 , v088
	.byte	W08
	.byte		        Gn1 , v112
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , Dn1 
	.byte	W08
mus_hightown_9_001:
	.byte		N08   , Gn1 , v112
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , Dn1 
	.byte	W08
	.byte		        Gn1 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , Dn1 
	.byte	W08
	.byte	PEND
mus_hightown_9_002:
	.byte		N08   , An1 , v112
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , En1 
	.byte	W08
	.byte		        An1 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , En1 
	.byte	W08
	.byte	PEND
	.byte		N04   , An1 
	.byte	W96
	.byte		VOL   , 39*mus_hightown_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N12   , Dn2 
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , An1 
	.byte	W08
	.byte		N12   , Dn2 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , An1 
	.byte	W08
	.byte		N12   , Dn2 
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , An1 
	.byte	W08
	.byte		N04   , Dn2 
	.byte	W08
	.byte		N12   
	.byte	W16
	.byte		        Cs2 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte	PATT
	 .word	mus_hightown_9_000
	.byte		N08   , Bn1 , v112
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , Fs1 
	.byte	W08
	.byte		N04   , Bn1 
	.byte	W08
	.byte		N12   
	.byte	W16
	.byte		N08   , An1 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte	PATT
	 .word	mus_hightown_9_001
	.byte	PATT
	 .word	mus_hightown_9_001
	.byte	PATT
	 .word	mus_hightown_9_002
	.byte		N04   , An1 , v112
	.byte	W96
mus_hightown_9_003:
	.byte		N12   , Dn1 , v112
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , An0 
	.byte	W08
	.byte		N12   , Dn1 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , An0 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_hightown_9_003
	.byte		N12   , Gn1 , v112
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , Dn1 
	.byte	W08
	.byte		N12   , Gn1 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , Dn1 
	.byte	W08
	.byte		N12   , An1 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , En1 
	.byte	W08
	.byte		N12   , An1 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , En1 
	.byte	W08
	.byte	PATT
	 .word	mus_hightown_9_003
	.byte	PATT
	 .word	mus_hightown_9_003
	.byte		N12   , Gn1 , v112
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , Dn1 
	.byte	W08
	.byte		N12   , An1 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , En1 
	.byte	W08
	.byte		N12   , Dn2 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , An1 
	.byte	W08
	.byte		N12   , Dn1 
	.byte	W16
	.byte		N04   
	.byte	W32
	.byte	GOTO
	 .word	mus_hightown_9_B1
	.byte		BEND  , c_v+0
	.byte	FINE

@********************** Track 10 **********************@

mus_hightown_10:
	.byte	KEYSH , mus_hightown_key+0
mus_hightown_10_B1:
	.byte		VOICE , 73
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-23
	.byte		VOL   , 55*mus_hightown_mvl/mxv
	.byte	W96
	.byte	W96
	.byte		VOICE , 17
	.byte		N40   , Bn3 , v112
	.byte	W40
	.byte		N04   , An3 
	.byte	W08
	.byte		N24   
	.byte	W48
mus_hightown_10_000:
	.byte	W32
	.byte		N04   , Cs4 , v112
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		N02   , Dn4 
	.byte	W02
	.byte		        En4 
	.byte	W02
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        Cs4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte	PEND
	.byte		N40   , Gn3 
	.byte	W40
	.byte		N04   , Fs3 
	.byte	W08
	.byte		N24   
	.byte	W48
	.byte	W32
	.byte		N04   , Dn3 
	.byte	W08
	.byte		        En3 
	.byte	W06
	.byte		N02   , As3 , v060
	.byte	W02
	.byte		N04   , An3 , v112
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		N36   , Dn4 
	.byte	W36
	.byte		N02   , En4 , v048
	.byte	W02
	.byte		        Ds4 , v060
	.byte	W02
	.byte		N04   , Dn4 , v088
	.byte	W08
	.byte		N24   , Bn3 , v112
	.byte	W48
	.byte	W32
	.byte		N04   , Dn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N02   , Cs4 
	.byte	W02
	.byte		        Dn4 
	.byte	W02
	.byte		N04   , Cn4 
	.byte	W04
	.byte		        Bn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		VOL   , 6*mus_hightown_mvl/mxv
	.byte		N96   
	.byte	W08
	.byte		VOL   , 1*mus_hightown_mvl/mxv
	.byte	W02
	.byte		        2*mus_hightown_mvl/mxv
	.byte	W02
	.byte		        4*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        6*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        7*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        9*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        11*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        13*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        15*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        17*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        19*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        21*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        22*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        23*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        24*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        27*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        28*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        30*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        33*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        36*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        38*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        39*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        41*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        43*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        44*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        46*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        46*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        47*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        49*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        50*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        52*mus_hightown_mvl/mxv
	.byte	W01
	.byte		        56*mus_hightown_mvl/mxv
	.byte	W04
	.byte		        58*mus_hightown_mvl/mxv
	.byte	W03
	.byte		        60*mus_hightown_mvl/mxv
	.byte	W12
	.byte		        54*mus_hightown_mvl/mxv
	.byte		N04   , Cs4 
	.byte	W24
	.byte		VOICE , 24
	.byte	W48
	.byte		VOL   , 48*mus_hightown_mvl/mxv
	.byte		N04   , Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N40   , Bn3 
	.byte	W40
	.byte		N04   , Cs4 
	.byte	W08
	.byte		N24   , An3 
	.byte	W48
	.byte	PATT
	 .word	mus_hightown_10_000
	.byte		N40   , Gn3 , v112
	.byte	W40
	.byte		N04   , Fs3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		N24   , Fs3 
	.byte	W48
	.byte	W32
	.byte		N04   , Dn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N02   , Gn3 
	.byte	W02
	.byte		        An3 
	.byte	W02
	.byte		N04   , Gn3 
	.byte	W04
	.byte		        Fs3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		N40   , Dn4 
	.byte	W40
	.byte		N04   , En4 
	.byte	W08
	.byte		N24   , Bn3 
	.byte	W48
	.byte	W32
	.byte		N04   , Dn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N02   , Cs4 
	.byte	W02
	.byte		        Dn4 
	.byte	W02
	.byte		N04   , Cs4 
	.byte	W04
	.byte		        Bn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N88   
	.byte	W88
	.byte		N04   , An3 
	.byte	W08
	.byte		        Bn3 
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
	 .word	mus_hightown_10_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_hightown:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_hightown_pri	@ Priority
	.byte	mus_hightown_rev	@ Reverb.

	.word	mus_hightown_grp

	.word	mus_hightown_1
	.word	mus_hightown_2
	.word	mus_hightown_3
	.word	mus_hightown_4
	.word	mus_hightown_5
	.word	mus_hightown_6
	.word	mus_hightown_7
	.word	mus_hightown_8
	.word	mus_hightown_9
	.word	mus_hightown_10

	.end
