	.include "MPlayDef.s"

	.equ	mus_kazanbai_grp, voicegroup_8687674
	.equ	mus_kazanbai_pri, 0
	.equ	mus_kazanbai_rev, reverb_set+50
	.equ	mus_kazanbai_mvl, 127
	.equ	mus_kazanbai_key, 0
	.equ	mus_kazanbai_tbs, 1
	.equ	mus_kazanbai_exg, 0
	.equ	mus_kazanbai_cmp, 1

	.section .rodata
	.global	mus_kazanbai
	.align	2

@********************** Track  1 **********************@

mus_kazanbai_1:
	.byte	KEYSH , mus_kazanbai_key+0
	.byte	TEMPO , 128*mus_kazanbai_tbs/2
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 44*mus_kazanbai_mvl/mxv
	.byte		PAN   , c_v+63
	.byte	W12
mus_kazanbai_1_B1:
mus_kazanbai_1_000:
	.byte		N03   , En5 , v112
	.byte	W06
	.byte		        En5 , v056
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En5 , v112
	.byte	W06
	.byte		        En5 , v056
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	PATT
	 .word	mus_kazanbai_1_000
	.byte	GOTO
	 .word	mus_kazanbai_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_kazanbai_2:
	.byte	KEYSH , mus_kazanbai_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+3
	.byte		VOL   , 75*mus_kazanbai_mvl/mxv
	.byte		N06   , Fs3 , v112
	.byte	W06
	.byte		        Bn3 
	.byte	W06
mus_kazanbai_2_B1:
mus_kazanbai_2_000:
	.byte		VOICE , 24
	.byte		N36   , Dn4 , v112
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte	W02
	.byte		N22   , Cs4 
	.byte	W22
	.byte		N12   , An3 
	.byte	W12
	.byte	PEND
mus_kazanbai_2_001:
	.byte		N24   , Bn3 , v112
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N36   , Gn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte	PEND
	.byte		        0
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N12   , An3 
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
mus_kazanbai_2_002:
	.byte		N60   , Gn3 , v112
	.byte	W24
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte	PEND
mus_kazanbai_2_003:
	.byte		N72   , An3 , v112
	.byte	W24
	.byte		MOD   , 7
	.byte	W48
	.byte	PEND
mus_kazanbai_2_004:
	.byte		MOD   , 0
	.byte	W48
	.byte		VOICE , 60
	.byte	W12
	.byte		N06   , Dn3 , v112
	.byte	W12
	.byte	PEND
	.byte		VOICE , 60
	.byte		TIE   , An3 
	.byte	W24
	.byte		VOL   , 71*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        70*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        66*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        63*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        62*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        59*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        58*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        55*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        52*mus_kazanbai_mvl/mxv
	.byte		MOD   , 3
	.byte	W02
	.byte		VOL   , 50*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        48*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        46*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        44*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        40*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        37*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        35*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		MOD   , 6
	.byte	W02
	.byte		VOL   , 31*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        29*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        26*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        25*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        22*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        19*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        17*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        15*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        11*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        9*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        9*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        7*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        5*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        3*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        1*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		EOT   
	.byte		VOL   , 1*mus_kazanbai_mvl/mxv
	.byte		MOD   , 0
	.byte	W12
	.byte		VOICE , 24
	.byte		VOL   , 74*mus_kazanbai_mvl/mxv
	.byte		N06   , En4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte	PATT
	 .word	mus_kazanbai_2_000
	.byte		N24   , Gn4 , v112
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N12   , An3 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte	PATT
	 .word	mus_kazanbai_2_003
	.byte	PATT
	 .word	mus_kazanbai_2_004
	.byte		VOICE , 60
	.byte		TIE   , An3 , v112
	.byte	W24
	.byte		VOL   , 71*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        70*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        66*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        63*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        62*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        59*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        58*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        55*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        52*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        50*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        48*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        46*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        44*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        40*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        37*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        35*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		MOD   , 7
	.byte	W02
	.byte		VOL   , 31*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        29*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        26*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        25*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        22*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        19*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        17*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        15*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        11*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        9*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        9*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        7*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        5*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        3*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        1*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		EOT   
	.byte		VOL   , 1*mus_kazanbai_mvl/mxv
	.byte		MOD   , 0
	.byte	W12
	.byte		VOICE , 24
	.byte		VOL   , 74*mus_kazanbai_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N03   , Gn4 
	.byte	W03
	.byte		N09   , Fs4 
	.byte	W09
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N03   , Fn4 
	.byte	W03
	.byte		N21   , En4 
	.byte	W21
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N06   , En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N03   , Gn4 
	.byte	W03
	.byte		N09   , Fs4 
	.byte	W09
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N12   , As4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N12   , En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		VOICE , 60
	.byte		VOL   , 48*mus_kazanbai_mvl/mxv
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		VOL   , 48*mus_kazanbai_mvl/mxv
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N06   , Cs4 
	.byte	W09
	.byte		N03   , Ds4 
	.byte	W03
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N24   , En4 
	.byte	W24
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N03   , Gn4 
	.byte	W03
	.byte		N09   , Fs4 
	.byte	W09
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W09
	.byte		N03   , An4 , v080
	.byte	W03
	.byte		N12   , Gs4 , v112
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N12   , En4 
	.byte	W12
	.byte		N18   , Bn3 
	.byte	W18
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N06   , An4 
	.byte	W12
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N24   , En4 
	.byte	W24
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N03   , Fn4 
	.byte	W03
	.byte		N06   , En4 
	.byte	W09
	.byte		N12   
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N03   , Fs4 
	.byte	W03
	.byte		N21   , Gn4 
	.byte	W21
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N24   , En4 
	.byte	W24
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		VOICE , 73
	.byte		N03   , Ds4 , v096
	.byte	W03
	.byte		N32   , Dn4 , v112
	.byte	W09
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte	W02
	.byte		N22   , Cs4 
	.byte	W22
	.byte		N12   , An3 
	.byte	W12
	.byte	PATT
	 .word	mus_kazanbai_2_001
	.byte		MOD   , 0
	.byte		N03   , Ds4 , v096
	.byte	W03
	.byte		N09   , Dn4 , v112
	.byte	W09
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N12   , An3 
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte	PATT
	 .word	mus_kazanbai_2_002
	.byte		N72   , An3 , v112
	.byte	W24
	.byte		MOD   , 6
	.byte	W48
	.byte	PATT
	 .word	mus_kazanbai_2_004
	.byte		VOICE , 60
	.byte		N12   , An3 , v112
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W12
	.byte		VOL   , 71*mus_kazanbai_mvl/mxv
	.byte		N96   , An3 
	.byte	W02
	.byte		VOL   , 70*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        66*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        63*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        62*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        59*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        58*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        55*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        52*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        50*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        48*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        46*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        44*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        40*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        37*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        35*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		MOD   , 7
	.byte	W02
	.byte		VOL   , 31*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        29*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        26*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        25*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        22*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        19*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        17*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        15*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        11*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        9*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        9*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        7*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        5*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        3*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        1*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        1*mus_kazanbai_mvl/mxv
	.byte		MOD   , 0
	.byte	W12
	.byte		VOICE , 73
	.byte		VOL   , 74*mus_kazanbai_mvl/mxv
	.byte		N06   , En4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N03   , Cs4 , v092
	.byte	W03
	.byte		N32   , Dn4 , v112
	.byte	W09
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte	W02
	.byte		N22   , Cs4 
	.byte	W22
	.byte		N12   , An3 
	.byte	W12
	.byte		N03   , Gs4 , v088
	.byte	W03
	.byte		N21   , Gn4 , v112
	.byte	W21
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N03   , Cs4 , v096
	.byte	W03
	.byte		N09   , Dn4 , v112
	.byte	W09
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N12   , An3 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N03   , Gs4 , v092
	.byte	W03
	.byte		N09   , Gn4 , v112
	.byte	W09
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N03   , As3 , v096
	.byte	W03
	.byte		N68   , An3 , v112
	.byte	W21
	.byte		MOD   , 7
	.byte	W48
	.byte	PATT
	 .word	mus_kazanbai_2_004
	.byte		VOICE , 60
	.byte		N60   , An3 , v112
	.byte	W24
	.byte		VOL   , 71*mus_kazanbai_mvl/mxv
	.byte		MOD   , 5
	.byte	W02
	.byte		VOL   , 70*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        66*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        63*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        62*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        59*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        58*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        55*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        50*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        46*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        42*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        36*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        74*mus_kazanbai_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Dn3 
	.byte	W12
	.byte		N48   , An3 
	.byte	W24
	.byte		VOL   , 74*mus_kazanbai_mvl/mxv
	.byte		MOD   , 6
	.byte	W02
	.byte		VOL   , 70*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        63*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        59*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        52*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        50*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        46*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        42*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        40*mus_kazanbai_mvl/mxv
	.byte		MOD   , 0
	.byte	W02
	.byte		VOL   , 31*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        29*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        25*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		VOICE , 24
	.byte		VOL   , 74*mus_kazanbai_mvl/mxv
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte	GOTO
	 .word	mus_kazanbai_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_kazanbai_3:
	.byte	KEYSH , mus_kazanbai_key+0
	.byte		VOICE , 24
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+28
	.byte		VOL   , 58*mus_kazanbai_mvl/mxv
	.byte	W12
mus_kazanbai_3_B1:
mus_kazanbai_3_000:
	.byte		PAN   , c_v+0
	.byte		VOL   , 74*mus_kazanbai_mvl/mxv
	.byte		N06   , Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v040
	.byte	W06
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v040
	.byte	W06
	.byte		        Fs2 , v112
	.byte	W06
	.byte		        Fs2 , v040
	.byte	W06
	.byte		        Gn2 , v112
	.byte	W06
	.byte		        Gn2 , v040
	.byte	W06
	.byte		        Bn2 , v112
	.byte	W06
	.byte		        Bn2 , v040
	.byte	W06
	.byte		        Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v040
	.byte	W06
	.byte	PEND
mus_kazanbai_3_001:
	.byte		PAN   , c_v+27
	.byte		VOL   , 59*mus_kazanbai_mvl/mxv
	.byte		N04   , An3 , v112
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		PAN   , c_v-28
	.byte		N04   , An2 
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        Fs2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Cs2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Bn1 
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	mus_kazanbai_3_000
mus_kazanbai_3_002:
	.byte		PAN   , c_v+27
	.byte		VOL   , 59*mus_kazanbai_mvl/mxv
	.byte		N04   , An3 , v112
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		PAN   , c_v-27
	.byte		N04   , An2 
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        Fs2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Cs2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Bn1 
	.byte	W04
	.byte	PEND
mus_kazanbai_3_003:
	.byte		PAN   , c_v+0
	.byte		VOL   , 74*mus_kazanbai_mvl/mxv
	.byte		N06   , Dn1 , v112
	.byte	W06
	.byte		        Dn1 , v040
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v040
	.byte	W06
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v040
	.byte	W06
	.byte		        Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v040
	.byte	W06
	.byte		        Fs2 , v112
	.byte	W06
	.byte		        Fs2 , v040
	.byte	W06
	.byte		        Cs3 , v112
	.byte	W06
	.byte		        Cs3 , v040
	.byte	W06
	.byte	PEND
mus_kazanbai_3_004:
	.byte		PAN   , c_v+28
	.byte		VOL   , 59*mus_kazanbai_mvl/mxv
	.byte		N04   , En3 , v112
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Gs2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Fs2 
	.byte	W04
	.byte		PAN   , c_v-27
	.byte		N04   , En2 
	.byte	W04
	.byte		        Fs2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Cs2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        An1 
	.byte	W16
	.byte	PEND
	.byte		PAN   , c_v+0
	.byte	W72
	.byte	W72
mus_kazanbai_3_005:
	.byte		VOL   , 74*mus_kazanbai_mvl/mxv
	.byte		N06   , Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v040
	.byte	W06
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v040
	.byte	W06
	.byte		        Fs2 , v112
	.byte	W06
	.byte		        Fs2 , v040
	.byte	W06
	.byte		        Gn2 , v112
	.byte	W06
	.byte		        Gn2 , v040
	.byte	W06
	.byte		        Bn2 , v112
	.byte	W06
	.byte		        Bn2 , v040
	.byte	W06
	.byte		        Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v040
	.byte	W06
	.byte	PEND
mus_kazanbai_3_006:
	.byte		PAN   , c_v+29
	.byte		VOL   , 59*mus_kazanbai_mvl/mxv
	.byte		N04   , An3 , v112
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		PAN   , c_v-27
	.byte		N04   , An2 
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        Fs2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Cs2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Bn1 
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	mus_kazanbai_3_000
mus_kazanbai_3_007:
	.byte		PAN   , c_v+28
	.byte		VOL   , 59*mus_kazanbai_mvl/mxv
	.byte		N04   , An3 , v112
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		PAN   , c_v-27
	.byte		N04   , An2 
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        Fs2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Cs2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Bn1 
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	mus_kazanbai_3_003
mus_kazanbai_3_008:
	.byte		PAN   , c_v+28
	.byte		VOL   , 59*mus_kazanbai_mvl/mxv
	.byte		N04   , En3 , v112
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Gs2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Fs2 
	.byte	W04
	.byte		PAN   , c_v-28
	.byte		N04   , En2 
	.byte	W04
	.byte		        Fs2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Cs2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        An1 
	.byte	W16
	.byte	PEND
	.byte		PAN   , c_v+0
	.byte	W72
	.byte	W72
	.byte		VOL   , 78*mus_kazanbai_mvl/mxv
	.byte		N06   , Bn1 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , Bn2 
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   , Bn2 
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N06   , Bn1 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , Bn2 
	.byte	W06
mus_kazanbai_3_009:
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		N03   , As2 
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N06   , As1 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , As2 
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   , As2 
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte	PEND
mus_kazanbai_3_010:
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , An2 
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   , An2 
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N06   , An1 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , An2 
	.byte	W06
	.byte	PEND
mus_kazanbai_3_011:
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N06   , Gs1 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte	PEND
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N03   , Bn1 
	.byte	W06
	.byte		N06   , Dn2 
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W06
	.byte		N06   , Bn2 
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W06
	.byte		N06   , Dn2 
	.byte	W06
	.byte		N03   , Bn1 
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N03   , Bn1 
	.byte	W06
	.byte		N06   , Dn2 
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W06
	.byte		N06   , An2 
	.byte	W06
	.byte		N03   , En2 
	.byte	W06
	.byte		N06   , Cs2 
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		N06   , Cs2 
	.byte	W06
	.byte		N03   , En2 
	.byte	W06
	.byte		N06   , An2 
	.byte	W06
	.byte		N03   , En2 
	.byte	W06
	.byte		N06   , Cs2 
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		N06   , Fs1 
	.byte	W06
	.byte		N03   , As1 
	.byte	W06
	.byte		N06   , Cs2 
	.byte	W06
	.byte		N03   , En2 
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , En2 
	.byte	W06
	.byte		N06   , Cs2 
	.byte	W06
	.byte		N03   , As1 
	.byte	W06
	.byte		N06   , Fs1 
	.byte	W06
	.byte		N03   , As1 
	.byte	W06
	.byte		N06   , Cs2 
	.byte	W06
	.byte		N03   , En2 
	.byte	W06
	.byte		N06   , As2 
	.byte	W06
	.byte		N03   , Fs2 
	.byte	W06
	.byte		N06   , En2 
	.byte	W06
	.byte		N03   , Cs2 
	.byte	W06
	.byte		N06   , As1 
	.byte	W06
	.byte		N03   , Cs2 
	.byte	W06
	.byte		N06   , En2 
	.byte	W06
	.byte		N03   , Fs2 
	.byte	W06
	.byte		N06   , As2 
	.byte	W06
	.byte		N03   , Fs2 
	.byte	W06
	.byte		N06   , En2 
	.byte	W06
	.byte		N03   , Cs2 
	.byte	W06
	.byte		N06   , Bn1 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , Bn2 
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   , Bn2 
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N06   , Bn1 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , Bn2 
	.byte	W06
	.byte	PATT
	 .word	mus_kazanbai_3_009
	.byte	PATT
	 .word	mus_kazanbai_3_010
	.byte	PATT
	 .word	mus_kazanbai_3_011
	.byte		N06   , Gn1 , v112
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , Bn2 
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   , Bn2 
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , Bn2 
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N06   , Gs1 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N06   , Bn2 
	.byte	W06
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
mus_kazanbai_3_012:
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		N03   , En2 
	.byte	W06
	.byte		N06   , An2 
	.byte	W06
	.byte		N03   , Cs3 
	.byte	W06
	.byte		N06   , En3 
	.byte	W06
	.byte		N03   , Cs3 
	.byte	W06
	.byte		N06   , An2 
	.byte	W06
	.byte		N03   , En2 
	.byte	W06
	.byte		N06   , An1 
	.byte	W06
	.byte		N03   , En2 
	.byte	W06
	.byte		N06   , An2 
	.byte	W06
	.byte		N03   , Cs3 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_kazanbai_3_012
	.byte	PATT
	 .word	mus_kazanbai_3_005
	.byte	PATT
	 .word	mus_kazanbai_3_001
	.byte	PATT
	 .word	mus_kazanbai_3_000
	.byte	PATT
	 .word	mus_kazanbai_3_002
	.byte	PATT
	 .word	mus_kazanbai_3_003
	.byte	PATT
	 .word	mus_kazanbai_3_004
	.byte		PAN   , c_v+0
	.byte	W72
	.byte	W72
	.byte	PATT
	 .word	mus_kazanbai_3_005
	.byte	PATT
	 .word	mus_kazanbai_3_006
	.byte	PATT
	 .word	mus_kazanbai_3_000
	.byte	PATT
	 .word	mus_kazanbai_3_007
	.byte	PATT
	 .word	mus_kazanbai_3_003
	.byte	PATT
	 .word	mus_kazanbai_3_008
	.byte		PAN   , c_v+0
	.byte	W72
	.byte	W72
	.byte	GOTO
	 .word	mus_kazanbai_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_kazanbai_4:
	.byte	KEYSH , mus_kazanbai_key+0
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 82*mus_kazanbai_mvl/mxv
	.byte		PAN   , c_v+15
	.byte	W12
mus_kazanbai_4_B1:
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
mus_kazanbai_4_000:
	.byte	W60
	.byte		N03   , An2 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
	.byte		N12   , Dn2 
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
mus_kazanbai_4_001:
	.byte	W60
	.byte		N03   , An1 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
	.byte		N15   , Dn2 
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	PATT
	 .word	mus_kazanbai_4_000
	.byte		N12   , Dn2 , v120
	.byte	W12
	.byte		N06   , An2 
	.byte	W12
	.byte		N12   , Dn2 
	.byte	W48
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	PATT
	 .word	mus_kazanbai_4_001
	.byte		N15   , Dn2 , v120
	.byte	W60
	.byte		N03   , An1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Dn2 
	.byte	W72
	.byte	GOTO
	 .word	mus_kazanbai_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_kazanbai_5:
	.byte	KEYSH , mus_kazanbai_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 42*mus_kazanbai_mvl/mxv
	.byte		PAN   , c_v-53
	.byte	W12
mus_kazanbai_5_B1:
mus_kazanbai_5_000:
	.byte		N12   , Fs3 , v084
	.byte	W12
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v084
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N09   , Fs3 , v072
	.byte	W12
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte	PEND
mus_kazanbai_5_001:
	.byte		N12   , Fs3 , v084
	.byte	W12
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v064
	.byte	W06
	.byte		        Fs3 , v116
	.byte	W06
	.byte		        Fs3 , v080
	.byte	W06
	.byte		N09   , Fs3 , v072
	.byte	W12
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_kazanbai_5_000
	.byte	PATT
	 .word	mus_kazanbai_5_001
mus_kazanbai_5_002:
	.byte		N12   , Cs3 , v084
	.byte	W12
	.byte		N03   , Cs3 , v112
	.byte	W06
	.byte		        Cs3 , v084
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N09   , Cs3 , v072
	.byte	W12
	.byte		N03   , Cs3 , v112
	.byte	W06
	.byte		        Cs3 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte	PEND
mus_kazanbai_5_003:
	.byte		N12   , Cs3 , v084
	.byte	W12
	.byte		N03   , Cs3 , v112
	.byte	W06
	.byte		        Cs3 , v064
	.byte	W06
	.byte		        Cs3 , v116
	.byte	W06
	.byte		        Cs3 , v080
	.byte	W06
	.byte		N09   , Cs3 , v072
	.byte	W12
	.byte		N03   , Cs3 , v112
	.byte	W06
	.byte		        Cs3 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_kazanbai_5_002
	.byte	PATT
	 .word	mus_kazanbai_5_003
	.byte	PATT
	 .word	mus_kazanbai_5_000
	.byte	PATT
	 .word	mus_kazanbai_5_001
	.byte	PATT
	 .word	mus_kazanbai_5_000
	.byte	PATT
	 .word	mus_kazanbai_5_001
	.byte	PATT
	 .word	mus_kazanbai_5_002
	.byte	PATT
	 .word	mus_kazanbai_5_003
	.byte	PATT
	 .word	mus_kazanbai_5_002
	.byte	PATT
	 .word	mus_kazanbai_5_003
mus_kazanbai_5_004:
	.byte		N12   , Dn3 , v084
	.byte	W12
	.byte		N03   , Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v084
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N09   , Dn3 , v072
	.byte	W12
	.byte		N03   , Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte	PEND
mus_kazanbai_5_005:
	.byte		N12   , Dn3 , v084
	.byte	W12
	.byte		N03   , Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v064
	.byte	W06
	.byte		        Dn3 , v116
	.byte	W06
	.byte		        Dn3 , v080
	.byte	W06
	.byte		N09   , Dn3 , v072
	.byte	W12
	.byte		N03   , Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_kazanbai_5_004
	.byte	PATT
	 .word	mus_kazanbai_5_005
mus_kazanbai_5_006:
	.byte		N12   , Bn3 , v084
	.byte	W12
	.byte		N03   , Bn3 , v112
	.byte	W06
	.byte		        Bn3 , v084
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N09   , Bn3 , v072
	.byte	W12
	.byte		N03   , Bn3 , v112
	.byte	W06
	.byte		        Bn3 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte		        Cs4 , v084
	.byte	W12
	.byte		N03   , Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v064
	.byte	W06
	.byte		        Cs4 , v116
	.byte	W06
	.byte		        Cs4 , v080
	.byte	W06
	.byte		N09   , Cs4 , v072
	.byte	W12
	.byte		N03   , Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        As3 , v084
	.byte	W12
	.byte		N03   , As3 , v112
	.byte	W06
	.byte		        As3 , v084
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N09   , As3 , v072
	.byte	W12
	.byte		N03   , As3 , v112
	.byte	W06
	.byte		        As3 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Fs3 , v084
	.byte	W12
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v064
	.byte	W06
	.byte		        Fs3 , v116
	.byte	W06
	.byte		        Fs3 , v080
	.byte	W06
	.byte		N09   , As3 , v072
	.byte	W12
	.byte		N03   , As3 , v112
	.byte	W06
	.byte		        As3 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
mus_kazanbai_5_007:
	.byte		N12   , Dn4 , v084
	.byte	W12
	.byte		N03   , Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v084
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N09   , Dn4 , v072
	.byte	W12
	.byte		N03   , Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte	PEND
mus_kazanbai_5_008:
	.byte		N12   , Dn4 , v084
	.byte	W12
	.byte		N03   , Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v064
	.byte	W06
	.byte		        Dn4 , v116
	.byte	W06
	.byte		        Dn4 , v080
	.byte	W06
	.byte		N09   , Dn4 , v072
	.byte	W12
	.byte		N03   , Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_kazanbai_5_007
	.byte	PATT
	 .word	mus_kazanbai_5_008
	.byte	PATT
	 .word	mus_kazanbai_5_006
	.byte		N12   , Gs3 , v084
	.byte	W12
	.byte		N03   , Gs3 , v112
	.byte	W06
	.byte		        Gs3 , v064
	.byte	W06
	.byte		        Gs3 , v116
	.byte	W06
	.byte		        Gs3 , v080
	.byte	W06
	.byte		N09   , Gs3 , v072
	.byte	W12
	.byte		N03   , Gs3 , v112
	.byte	W06
	.byte		        Gs3 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        An3 , v084
	.byte	W12
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        An3 , v084
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N09   , An3 , v072
	.byte	W12
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        An3 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        An3 , v084
	.byte	W12
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        An3 , v064
	.byte	W06
	.byte		        An3 , v116
	.byte	W06
	.byte		        An3 , v080
	.byte	W06
	.byte		N09   , Cs4 , v072
	.byte	W12
	.byte		N03   , Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte	PATT
	 .word	mus_kazanbai_5_000
	.byte	PATT
	 .word	mus_kazanbai_5_001
	.byte	PATT
	 .word	mus_kazanbai_5_000
	.byte	PATT
	 .word	mus_kazanbai_5_001
	.byte	PATT
	 .word	mus_kazanbai_5_002
	.byte	PATT
	 .word	mus_kazanbai_5_003
	.byte	PATT
	 .word	mus_kazanbai_5_002
	.byte	PATT
	 .word	mus_kazanbai_5_003
	.byte	PATT
	 .word	mus_kazanbai_5_000
	.byte	PATT
	 .word	mus_kazanbai_5_001
	.byte	PATT
	 .word	mus_kazanbai_5_000
	.byte	PATT
	 .word	mus_kazanbai_5_001
	.byte	PATT
	 .word	mus_kazanbai_5_002
	.byte	PATT
	 .word	mus_kazanbai_5_003
	.byte	PATT
	 .word	mus_kazanbai_5_002
	.byte	PATT
	 .word	mus_kazanbai_5_003
	.byte	GOTO
	 .word	mus_kazanbai_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_kazanbai_6:
	.byte	KEYSH , mus_kazanbai_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 42*mus_kazanbai_mvl/mxv
	.byte		PAN   , c_v+63
	.byte	W12
mus_kazanbai_6_B1:
mus_kazanbai_6_000:
	.byte		N12   , Bn3 , v084
	.byte	W12
	.byte		N03   , Bn3 , v112
	.byte	W06
	.byte		        Bn3 , v084
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N09   , Bn3 , v072
	.byte	W12
	.byte		N03   , Bn3 , v112
	.byte	W06
	.byte		        Bn3 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte	PEND
mus_kazanbai_6_001:
	.byte		N12   , Bn3 , v084
	.byte	W12
	.byte		N03   , Bn3 , v112
	.byte	W06
	.byte		        Bn3 , v064
	.byte	W06
	.byte		        Bn3 , v116
	.byte	W06
	.byte		        Bn3 , v080
	.byte	W06
	.byte		N09   , Bn3 , v072
	.byte	W12
	.byte		N03   , Bn3 , v112
	.byte	W06
	.byte		        Bn3 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_kazanbai_6_000
	.byte	PATT
	 .word	mus_kazanbai_6_001
mus_kazanbai_6_002:
	.byte		N12   , Fs3 , v084
	.byte	W12
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v084
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N09   , Fs3 , v072
	.byte	W12
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte	PEND
mus_kazanbai_6_003:
	.byte		N12   , Fs3 , v084
	.byte	W12
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v064
	.byte	W06
	.byte		        Fs3 , v116
	.byte	W06
	.byte		        Fs3 , v080
	.byte	W06
	.byte		N09   , Fs3 , v072
	.byte	W12
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_kazanbai_6_002
	.byte	PATT
	 .word	mus_kazanbai_6_003
	.byte	PATT
	 .word	mus_kazanbai_6_000
	.byte	PATT
	 .word	mus_kazanbai_6_001
	.byte	PATT
	 .word	mus_kazanbai_6_000
	.byte	PATT
	 .word	mus_kazanbai_6_001
	.byte	PATT
	 .word	mus_kazanbai_6_002
	.byte	PATT
	 .word	mus_kazanbai_6_003
	.byte	PATT
	 .word	mus_kazanbai_6_002
	.byte	PATT
	 .word	mus_kazanbai_6_003
	.byte		N12   , An3 , v084
	.byte	W12
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        An3 , v084
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N09   , An3 , v072
	.byte	W12
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        An3 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        As3 , v084
	.byte	W12
	.byte		N03   , As3 , v112
	.byte	W06
	.byte		        As3 , v064
	.byte	W06
	.byte		        As3 , v116
	.byte	W06
	.byte		        As3 , v080
	.byte	W06
	.byte		N09   , As3 , v072
	.byte	W12
	.byte		N03   , As3 , v112
	.byte	W06
	.byte		        As3 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte	PATT
	 .word	mus_kazanbai_6_000
	.byte		N12   , Cs4 , v084
	.byte	W12
	.byte		N03   , Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v064
	.byte	W06
	.byte		        Cs4 , v116
	.byte	W06
	.byte		        Cs4 , v080
	.byte	W06
	.byte		N09   , Dn4 , v072
	.byte	W12
	.byte		N03   , Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
mus_kazanbai_6_004:
	.byte		N12   , Fs4 , v084
	.byte	W12
	.byte		N03   , Fs4 , v112
	.byte	W06
	.byte		        Fs4 , v084
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N09   , Fs4 , v072
	.byte	W12
	.byte		N03   , Fs4 , v112
	.byte	W06
	.byte		        Fs4 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte		        Gn4 , v084
	.byte	W12
	.byte		N03   , Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		        Gn4 , v116
	.byte	W06
	.byte		        Gn4 , v080
	.byte	W06
	.byte		N09   , Gn4 , v072
	.byte	W12
	.byte		N03   , Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        En4 , v084
	.byte	W12
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        En4 , v084
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N09   , En4 , v072
	.byte	W12
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        En4 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Cs4 , v084
	.byte	W12
	.byte		N03   , Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v064
	.byte	W06
	.byte		        Cs4 , v116
	.byte	W06
	.byte		        Cs4 , v080
	.byte	W06
	.byte		N09   , Fs4 , v072
	.byte	W12
	.byte		N03   , Fs4 , v112
	.byte	W06
	.byte		        Fs4 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        An4 , v084
	.byte	W12
	.byte		N03   , An4 , v112
	.byte	W06
	.byte		        An4 , v084
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N09   , An4 , v072
	.byte	W12
	.byte		N03   , An4 , v112
	.byte	W06
	.byte		        An4 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        As4 , v084
	.byte	W12
	.byte		N03   , As4 , v112
	.byte	W06
	.byte		        As4 , v064
	.byte	W06
	.byte		        As4 , v116
	.byte	W06
	.byte		        As4 , v080
	.byte	W06
	.byte		N09   , As4 , v072
	.byte	W12
	.byte		N03   , As4 , v112
	.byte	W06
	.byte		        As4 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Bn4 , v084
	.byte	W12
	.byte		N03   , Bn4 , v112
	.byte	W06
	.byte		        Bn4 , v084
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N09   , Bn4 , v072
	.byte	W12
	.byte		N03   , Bn4 , v112
	.byte	W06
	.byte		        Bn4 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Cs5 , v084
	.byte	W12
	.byte		N03   , Cs5 , v112
	.byte	W06
	.byte		        Cs5 , v064
	.byte	W06
	.byte		        Cs5 , v116
	.byte	W06
	.byte		        Cs5 , v080
	.byte	W06
	.byte		N09   , Bn4 , v072
	.byte	W12
	.byte		N03   , Bn4 , v112
	.byte	W06
	.byte		        Bn4 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte	PATT
	 .word	mus_kazanbai_6_004
	.byte		N12   , Dn4 , v084
	.byte	W12
	.byte		N03   , Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v064
	.byte	W06
	.byte		        Dn4 , v116
	.byte	W06
	.byte		        Dn4 , v080
	.byte	W06
	.byte		N09   , Dn4 , v072
	.byte	W12
	.byte		N03   , Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Cs4 , v084
	.byte	W12
	.byte		N03   , Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v084
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N09   , Cs4 , v072
	.byte	W12
	.byte		N03   , Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        En4 , v084
	.byte	W12
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        En4 , v064
	.byte	W06
	.byte		        En4 , v116
	.byte	W06
	.byte		        En4 , v080
	.byte	W06
	.byte		N09   , Gn4 , v072
	.byte	W12
	.byte		N03   , Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte	PATT
	 .word	mus_kazanbai_6_000
	.byte	PATT
	 .word	mus_kazanbai_6_001
	.byte	PATT
	 .word	mus_kazanbai_6_000
	.byte	PATT
	 .word	mus_kazanbai_6_001
	.byte	PATT
	 .word	mus_kazanbai_6_002
	.byte	PATT
	 .word	mus_kazanbai_6_003
	.byte	PATT
	 .word	mus_kazanbai_6_002
	.byte	PATT
	 .word	mus_kazanbai_6_003
	.byte	PATT
	 .word	mus_kazanbai_6_000
	.byte	PATT
	 .word	mus_kazanbai_6_001
	.byte	PATT
	 .word	mus_kazanbai_6_000
	.byte	PATT
	 .word	mus_kazanbai_6_001
	.byte	PATT
	 .word	mus_kazanbai_6_002
	.byte	PATT
	 .word	mus_kazanbai_6_003
	.byte	PATT
	 .word	mus_kazanbai_6_002
	.byte	PATT
	 .word	mus_kazanbai_6_003
	.byte	GOTO
	 .word	mus_kazanbai_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_kazanbai_7:
	.byte	KEYSH , mus_kazanbai_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 84*mus_kazanbai_mvl/mxv
	.byte	W12
mus_kazanbai_7_B1:
mus_kazanbai_7_000:
	.byte		N06   , Cn1 , v127
	.byte	W24
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v048
	.byte	W06
	.byte		        Dn1 , v032
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte	PEND
	.byte		        Cn1 , v127
	.byte	W24
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v040
	.byte	W06
	.byte		        Dn1 , v032
	.byte	W06
	.byte		        Dn1 , v020
	.byte	W06
	.byte		        Cn1 , v127
	.byte	W18
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v044
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W24
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v040
	.byte	W06
	.byte		        Dn1 , v028
	.byte	W06
	.byte		        Dn1 , v016
	.byte	W06
mus_kazanbai_7_001:
	.byte		N06   , Cn1 , v127
	.byte	W24
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v048
	.byte	W06
	.byte		        Dn1 , v036
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte	PEND
	.byte		        Cn1 , v127
	.byte	W18
	.byte		        Cn1 , v092
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v040
	.byte	W06
	.byte		        Dn1 , v032
	.byte	W06
	.byte		        Dn1 , v020
	.byte	W06
	.byte		        Cn1 , v127
	.byte	W24
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Dn1 , v048
	.byte	W06
	.byte		        Dn1 , v032
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W18
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v044
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
mus_kazanbai_7_002:
	.byte		N06   , Cn1 , v127
	.byte	W24
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v036
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte	PEND
mus_kazanbai_7_003:
	.byte		N06   , Cn1 , v127
	.byte	W18
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v044
	.byte	W06
	.byte		        Dn1 , v032
	.byte	W06
	.byte		        Dn1 , v024
	.byte	W06
	.byte	PEND
mus_kazanbai_7_004:
	.byte		N06   , Cn1 , v127
	.byte	W24
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v040
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_kazanbai_7_003
	.byte	PATT
	 .word	mus_kazanbai_7_002
	.byte		N06   , Cn1 , v127
	.byte	W24
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v040
	.byte	W06
	.byte		        Dn1 , v028
	.byte	W06
	.byte		        Dn1 , v024
	.byte	W06
	.byte		        Cn1 , v127
	.byte	W24
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v044
	.byte	W06
	.byte		        Dn1 , v024
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W18
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Cn1 , v127
	.byte	W24
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Dn1 , v044
	.byte	W06
	.byte		        Dn1 , v032
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W18
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v044
	.byte	W06
	.byte		        Dn1 , v032
	.byte	W06
	.byte		        Dn1 , v020
	.byte	W06
mus_kazanbai_7_005:
	.byte		N06   , Cn1 , v127
	.byte	W24
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Dn1 , v048
	.byte	W06
	.byte		        Dn1 , v036
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_kazanbai_7_003
mus_kazanbai_7_006:
	.byte		N06   , Cn1 , v127
	.byte	W24
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v040
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte	PEND
	.byte		        Cn1 , v127
	.byte	W18
	.byte		        Cn1 , v092
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v044
	.byte	W06
	.byte		        Dn1 , v032
	.byte	W06
	.byte		        Dn1 , v024
	.byte	W06
mus_kazanbai_7_007:
	.byte		N06   , Cn1 , v127
	.byte	W24
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v044
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte	PEND
	.byte		        Cn1 , v127
	.byte	W18
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v056
	.byte	W06
	.byte		        Dn1 , v044
	.byte	W06
	.byte		        Dn1 , v032
	.byte	W06
	.byte		        Dn1 , v020
	.byte	W06
	.byte	PATT
	 .word	mus_kazanbai_7_000
	.byte		N06   , Cn1 , v127
	.byte	W18
	.byte		        Cn1 , v092
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v040
	.byte	W06
	.byte		        Cn1 , v112
	.byte		N06   , Dn1 , v036
	.byte	W06
	.byte		        Dn1 , v056
	.byte	W06
	.byte		        Cn1 , v127
	.byte	W18
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v040
	.byte	W06
	.byte		        Cn1 , v112
	.byte		N06   , Dn1 , v036
	.byte	W06
	.byte		        Dn1 , v056
	.byte	W06
	.byte		        Cn1 , v127
	.byte	W18
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v040
	.byte	W06
	.byte		        Cn1 , v112
	.byte		N06   , Dn1 , v036
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Cn1 , v127
	.byte	W18
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v040
	.byte	W06
	.byte		        Dn1 , v032
	.byte	W06
	.byte		        Dn1 , v024
	.byte	W06
	.byte	PATT
	 .word	mus_kazanbai_7_004
	.byte		N06   , Cn1 , v127
	.byte	W18
	.byte		        Cn1 , v092
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v040
	.byte	W06
	.byte		        Dn1 , v028
	.byte	W06
	.byte		        Dn1 , v024
	.byte	W06
	.byte	PATT
	 .word	mus_kazanbai_7_005
	.byte		N06   , Cn1 , v127
	.byte	W18
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v056
	.byte	W06
	.byte		        Dn1 , v048
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v044
	.byte	W06
	.byte		        Dn1 , v032
	.byte	W06
	.byte		        Dn1 , v024
	.byte	W06
	.byte		        Cn1 , v127
	.byte	W18
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v040
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Cn1 , v127
	.byte	W24
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v056
	.byte	W06
	.byte		        Dn1 , v048
	.byte	W06
	.byte		        Dn1 , v040
	.byte	W06
	.byte		        Dn1 , v032
	.byte	W06
	.byte	PATT
	 .word	mus_kazanbai_7_005
	.byte		N06   , Cn1 , v127
	.byte	W18
	.byte		        Cn1 , v064
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v056
	.byte	W06
	.byte		        Dn1 , v044
	.byte	W06
	.byte		        Dn1 , v036
	.byte	W06
	.byte		        Dn1 , v024
	.byte	W06
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Dn1 , v048
	.byte	W06
	.byte		        Dn1 , v036
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Cn1 , v127
	.byte	W18
	.byte		        Dn1 , v096
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v056
	.byte	W06
	.byte		        Dn1 , v048
	.byte	W06
	.byte		        Dn1 , v096
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte	PATT
	 .word	mus_kazanbai_7_007
	.byte		N06   , Cn1 , v127
	.byte	W18
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v036
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W06
	.byte		        Dn1 , v024
	.byte	W06
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v048
	.byte	W06
	.byte		        Dn1 , v032
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W18
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v040
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PATT
	 .word	mus_kazanbai_7_006
	.byte		N06   , Cn1 , v127
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v044
	.byte	W06
	.byte		        Dn1 , v036
	.byte	W06
	.byte		        Dn1 , v028
	.byte	W06
	.byte	PATT
	 .word	mus_kazanbai_7_001
	.byte		N06   , Cn1 , v127
	.byte	W18
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v044
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn1 , v056
	.byte	W06
	.byte	GOTO
	 .word	mus_kazanbai_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_kazanbai_8:
	.byte	KEYSH , mus_kazanbai_key+0
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 36*mus_kazanbai_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , Fs3 , v112
	.byte	W02
	.byte		BEND  , c_v+2
	.byte	W04
	.byte		N06   , Bn3 
	.byte	W06
mus_kazanbai_8_B1:
mus_kazanbai_8_000:
	.byte		N36   , Dn4 , v112
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte	W02
	.byte		N22   , Cs4 
	.byte	W22
	.byte		N12   , An3 
	.byte	W12
	.byte	PEND
mus_kazanbai_8_001:
	.byte		N24   , Bn3 , v112
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N36   , Gn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte	PEND
	.byte		        0
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N12   , An3 
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
mus_kazanbai_8_002:
	.byte		N60   , Gn3 , v112
	.byte	W24
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte	PEND
	.byte	W24
	.byte		MOD   , 7
	.byte	W48
	.byte		        0
	.byte	W72
	.byte	W24
	.byte		VOL   , 11*mus_kazanbai_mvl/mxv
	.byte	W24
	.byte		MOD   , 3
	.byte	W24
	.byte		        6
	.byte	W48
	.byte		        0
	.byte	W12
	.byte		VOL   , 36*mus_kazanbai_mvl/mxv
	.byte		N06   , En4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte	PATT
	 .word	mus_kazanbai_8_000
	.byte		N24   , Gn4 , v112
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N12   , An3 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte	W24
	.byte		MOD   , 7
	.byte	W48
	.byte		        0
	.byte	W72
	.byte	W24
	.byte		VOL   , 13*mus_kazanbai_mvl/mxv
	.byte	W48
	.byte		MOD   , 7
	.byte	W48
	.byte		        0
	.byte	W12
	.byte		VOL   , 36*mus_kazanbai_mvl/mxv
	.byte		N06   , An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N03   , Gn4 
	.byte	W03
	.byte		N09   , Fs4 
	.byte	W09
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N03   , Fn4 
	.byte	W03
	.byte		N21   , En4 
	.byte	W21
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N06   , En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N03   , Gn4 
	.byte	W03
	.byte		N09   , Fs4 
	.byte	W09
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N12   , As4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N12   , En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N06   , Cs4 
	.byte	W09
	.byte		N03   , Ds4 
	.byte	W03
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N24   , En4 
	.byte	W24
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N03   , Gn4 
	.byte	W03
	.byte		N09   , Fs4 
	.byte	W09
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W09
	.byte		N03   , An4 , v080
	.byte	W03
	.byte		N12   , Gs4 , v112
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N12   , En4 
	.byte	W12
	.byte		N18   , Bn3 
	.byte	W18
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N06   , An4 
	.byte	W12
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N24   , En4 
	.byte	W24
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N03   , Fn4 
	.byte	W03
	.byte		N06   , En4 
	.byte	W09
	.byte		N12   
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N03   , Fs4 
	.byte	W03
	.byte		N21   , Gn4 
	.byte	W21
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N24   , En4 
	.byte	W24
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N03   , Ds4 , v096
	.byte	W03
	.byte		N32   , Dn4 , v112
	.byte	W09
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte	W02
	.byte		N22   , Cs4 
	.byte	W22
	.byte		N12   , An3 
	.byte	W12
	.byte	PATT
	 .word	mus_kazanbai_8_001
	.byte		MOD   , 0
	.byte		N03   , Ds4 , v096
	.byte	W03
	.byte		N09   , Dn4 , v112
	.byte	W09
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N12   , An3 
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte	PATT
	 .word	mus_kazanbai_8_002
	.byte		N72   , An3 , v112
	.byte	W24
	.byte		MOD   , 6
	.byte	W48
	.byte		        0
	.byte	W72
	.byte	W24
	.byte		VOL   , 9*mus_kazanbai_mvl/mxv
	.byte	W48
	.byte		MOD   , 7
	.byte	W48
	.byte		        0
	.byte	W12
	.byte		VOL   , 36*mus_kazanbai_mvl/mxv
	.byte		N06   , En4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N03   , Cs4 , v092
	.byte	W03
	.byte		N32   , Dn4 , v112
	.byte	W09
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte	W02
	.byte		N22   , Cs4 
	.byte	W22
	.byte		N12   , An3 
	.byte	W12
	.byte		N03   , Gs4 , v088
	.byte	W03
	.byte		N21   , Gn4 , v112
	.byte	W21
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N03   , Cs4 , v096
	.byte	W03
	.byte		N09   , Dn4 , v112
	.byte	W09
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N12   , An3 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N03   , Gs4 , v092
	.byte	W03
	.byte		N09   , Gn4 , v112
	.byte	W09
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N03   , As3 , v096
	.byte	W03
	.byte		N68   , An3 , v112
	.byte	W21
	.byte		MOD   , 7
	.byte	W48
	.byte		        0
	.byte	W72
	.byte	W24
	.byte		VOL   , 13*mus_kazanbai_mvl/mxv
	.byte		MOD   , 5
	.byte	W36
	.byte		VOL   , 42*mus_kazanbai_mvl/mxv
	.byte		MOD   , 0
	.byte	W12
	.byte	W24
	.byte		VOL   , 13*mus_kazanbai_mvl/mxv
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte	W12
	.byte		VOL   , 36*mus_kazanbai_mvl/mxv
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte	GOTO
	 .word	mus_kazanbai_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_kazanbai_9:
	.byte	KEYSH , mus_kazanbai_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 44*mus_kazanbai_mvl/mxv
	.byte		PAN   , c_v-19
	.byte		N06   , Bn2 , v112
	.byte	W06
	.byte		        Dn3 
	.byte	W06
mus_kazanbai_9_B1:
	.byte		VOL   , 46*mus_kazanbai_mvl/mxv
	.byte		N36   , Gn3 , v112
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte	W03
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N09   , Dn3 
	.byte	W09
mus_kazanbai_9_000:
	.byte		N24   , Gn3 , v112
	.byte	W24
	.byte	W03
	.byte		N09   , Gn2 
	.byte	W09
	.byte		N36   , Bn2 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte	PEND
mus_kazanbai_9_001:
	.byte		VOICE , 24
	.byte		MOD   , 0
	.byte		N12   , Gn3 , v112
	.byte	W15
	.byte		N06   , Fs3 
	.byte	W12
	.byte		N09   , Dn3 
	.byte	W09
	.byte		N24   , Fs3 
	.byte	W24
	.byte	W03
	.byte		N09   , Gn2 
	.byte	W09
	.byte	PEND
mus_kazanbai_9_002:
	.byte		N60   , Bn2 , v112
	.byte	W24
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte	PEND
mus_kazanbai_9_003:
	.byte	W03
	.byte		N68   , Dn3 , v112
	.byte	W21
	.byte		MOD   , 7
	.byte	W48
	.byte	PEND
mus_kazanbai_9_004:
	.byte		MOD   , 0
	.byte	W48
	.byte		VOICE , 60
	.byte		VOL   , 57*mus_kazanbai_mvl/mxv
	.byte	W12
	.byte		N06   , Gn2 , v112
	.byte	W12
	.byte	PEND
	.byte		TIE   , En3 
	.byte	W24
	.byte		VOL   , 54*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        51*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        50*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        48*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        44*mus_kazanbai_mvl/mxv
	.byte	W05
	.byte		        42*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        40*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		MOD   , 3
	.byte	W02
	.byte		VOL   , 37*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        35*mus_kazanbai_mvl/mxv
	.byte	W07
	.byte		        31*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        31*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        27*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        26*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        24*mus_kazanbai_mvl/mxv
	.byte		MOD   , 6
	.byte	W02
	.byte		VOL   , 22*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        21*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        19*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        18*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        15*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        15*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        11*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        10*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        9*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        7*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        5*mus_kazanbai_mvl/mxv
	.byte	W06
	.byte		        3*mus_kazanbai_mvl/mxv
	.byte	W06
	.byte		        1*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		EOT   
	.byte		MOD   , 0
	.byte	W12
	.byte		VOICE , 24
	.byte		VOL   , 45*mus_kazanbai_mvl/mxv
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
mus_kazanbai_9_005:
	.byte		N36   , Gn3 , v112
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte	W03
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N09   , Dn3 
	.byte	W09
	.byte	PEND
mus_kazanbai_9_006:
	.byte		N24   , Dn4 , v112
	.byte	W24
	.byte	W03
	.byte		N09   , Gn2 
	.byte	W09
	.byte		N24   , Bn2 
	.byte	W24
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte	PEND
mus_kazanbai_9_007:
	.byte		N12   , Gn3 , v112
	.byte	W15
	.byte		N06   , Fs3 
	.byte	W12
	.byte		N09   , Dn3 
	.byte	W09
	.byte		N24   , Fs3 
	.byte	W24
	.byte	W03
	.byte		N09   , Gn2 
	.byte	W09
	.byte	PEND
mus_kazanbai_9_008:
	.byte		N12   , Dn4 , v112
	.byte	W15
	.byte		N09   , Gn3 
	.byte	W09
	.byte		N12   , Dn3 
	.byte	W15
	.byte		N09   , Fs3 
	.byte	W09
	.byte		N12   , Gn2 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_kazanbai_9_003
	.byte	PATT
	 .word	mus_kazanbai_9_004
	.byte		TIE   , En3 , v112
	.byte	W24
	.byte		VOL   , 54*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        51*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        50*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        48*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        44*mus_kazanbai_mvl/mxv
	.byte	W05
	.byte		        42*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        40*mus_kazanbai_mvl/mxv
	.byte	W06
	.byte		        37*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        35*mus_kazanbai_mvl/mxv
	.byte	W07
	.byte		        31*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        31*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        27*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        26*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        24*mus_kazanbai_mvl/mxv
	.byte		MOD   , 7
	.byte	W02
	.byte		VOL   , 22*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        21*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        19*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        18*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        15*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        15*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        11*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        10*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        9*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        7*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        5*mus_kazanbai_mvl/mxv
	.byte	W06
	.byte		        3*mus_kazanbai_mvl/mxv
	.byte	W06
	.byte		        1*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		EOT   
	.byte		MOD   , 0
	.byte	W12
	.byte		VOL   , 68*mus_kazanbai_mvl/mxv
	.byte	W12
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W54
	.byte		        36*mus_kazanbai_mvl/mxv
	.byte	W06
	.byte		VOICE , 60
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte	PATT
	 .word	mus_kazanbai_9_005
	.byte	PATT
	 .word	mus_kazanbai_9_000
	.byte	PATT
	 .word	mus_kazanbai_9_001
	.byte	PATT
	 .word	mus_kazanbai_9_002
	.byte	W03
	.byte		N68   , Dn3 , v112
	.byte	W21
	.byte		MOD   , 6
	.byte	W48
	.byte	PATT
	 .word	mus_kazanbai_9_004
	.byte		N12   , En3 , v112
	.byte	W12
	.byte		N06   , Gn2 
	.byte	W12
	.byte		VOL   , 54*mus_kazanbai_mvl/mxv
	.byte		N96   , En3 
	.byte	W02
	.byte		VOL   , 51*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        50*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        48*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        44*mus_kazanbai_mvl/mxv
	.byte	W05
	.byte		        42*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        40*mus_kazanbai_mvl/mxv
	.byte	W06
	.byte		        37*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        35*mus_kazanbai_mvl/mxv
	.byte	W07
	.byte		        31*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        31*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        27*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        26*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        24*mus_kazanbai_mvl/mxv
	.byte		MOD   , 7
	.byte	W02
	.byte		VOL   , 22*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        21*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        19*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        18*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        15*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        15*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        11*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        10*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        9*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        7*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        5*mus_kazanbai_mvl/mxv
	.byte	W06
	.byte		        3*mus_kazanbai_mvl/mxv
	.byte	W06
	.byte		        1*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W12
	.byte		VOICE , 60
	.byte		VOL   , 38*mus_kazanbai_mvl/mxv
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte	PATT
	 .word	mus_kazanbai_9_005
	.byte	PATT
	 .word	mus_kazanbai_9_006
	.byte	PATT
	 .word	mus_kazanbai_9_007
	.byte	PATT
	 .word	mus_kazanbai_9_008
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		N68   , Dn3 
	.byte	W21
	.byte		MOD   , 7
	.byte	W48
	.byte	PATT
	 .word	mus_kazanbai_9_004
	.byte		N60   , En3 , v112
	.byte	W24
	.byte		VOL   , 54*mus_kazanbai_mvl/mxv
	.byte		MOD   , 5
	.byte	W02
	.byte		VOL   , 51*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        50*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        48*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        44*mus_kazanbai_mvl/mxv
	.byte	W05
	.byte		        42*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        40*mus_kazanbai_mvl/mxv
	.byte	W06
	.byte		        37*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        35*mus_kazanbai_mvl/mxv
	.byte	W07
	.byte		        63*mus_kazanbai_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Gn2 
	.byte	W12
	.byte		N48   , En3 
	.byte	W21
	.byte		VOL   , 59*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        50*mus_kazanbai_mvl/mxv
	.byte		MOD   , 6
	.byte	W02
	.byte		VOL   , 46*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        36*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        34*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        27*mus_kazanbai_mvl/mxv
	.byte	W02
	.byte		        23*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        19*mus_kazanbai_mvl/mxv
	.byte	W03
	.byte		        17*mus_kazanbai_mvl/mxv
	.byte	W04
	.byte		        15*mus_kazanbai_mvl/mxv
	.byte		MOD   , 0
	.byte	W05
	.byte		VOL   , 13*mus_kazanbai_mvl/mxv
	.byte	W07
	.byte		VOICE , 24
	.byte		VOL   , 68*mus_kazanbai_mvl/mxv
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte	GOTO
	 .word	mus_kazanbai_9_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_kazanbai:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_kazanbai_pri	@ Priority
	.byte	mus_kazanbai_rev	@ Reverb.

	.word	mus_kazanbai_grp

	.word	mus_kazanbai_1
	.word	mus_kazanbai_2
	.word	mus_kazanbai_3
	.word	mus_kazanbai_4
	.word	mus_kazanbai_5
	.word	mus_kazanbai_6
	.word	mus_kazanbai_7
	.word	mus_kazanbai_8
	.word	mus_kazanbai_9

	.end
