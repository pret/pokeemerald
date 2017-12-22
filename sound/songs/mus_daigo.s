	.include "MPlayDef.s"

	.equ	mus_daigo_grp, voicegroup_869467C
	.equ	mus_daigo_pri, 0
	.equ	mus_daigo_rev, reverb_set+50
	.equ	mus_daigo_mvl, 127
	.equ	mus_daigo_key, 0
	.equ	mus_daigo_tbs, 1
	.equ	mus_daigo_exg, 0
	.equ	mus_daigo_cmp, 1

	.section .rodata
	.global	mus_daigo
	.align	2

@********************** Track  1 **********************@

mus_daigo_1:
	.byte	KEYSH , mus_daigo_key+0
	.byte	TEMPO , 142*mus_daigo_tbs/2
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		PAN   , c_v+4
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 44*mus_daigo_mvl/mxv
	.byte		N03   , Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W12
	.byte		        Fs5 , v080
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fs5 , v080
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W12
	.byte		        Fs5 , v064
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W12
	.byte		        Fs5 , v080
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fs5 , v080
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W06
mus_daigo_1_B1:
mus_daigo_1_000:
	.byte		N03   , Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W12
	.byte		        Fs5 , v080
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fs5 , v080
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W12
	.byte		        Fs5 , v064
	.byte	W06
	.byte	PEND
mus_daigo_1_001:
	.byte	W06
	.byte		N03   , Fs5 , v064
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W12
	.byte		        Fs5 , v064
	.byte	W06
	.byte	PEND
mus_daigo_1_002:
	.byte		N03   , Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W12
	.byte		        Fs5 , v080
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fs5 , v080
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W12
	.byte		        Fs5 , v064
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_daigo_1_001
	.byte	PATT
	 .word	mus_daigo_1_000
	.byte	PATT
	 .word	mus_daigo_1_001
	.byte	PATT
	 .word	mus_daigo_1_002
	.byte	PATT
	 .word	mus_daigo_1_002
mus_daigo_1_003:
	.byte	W12
	.byte		N03   , Fs5 , v080
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W06
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_daigo_1_003
	.byte	PATT
	 .word	mus_daigo_1_003
	.byte	PATT
	 .word	mus_daigo_1_003
mus_daigo_1_004:
	.byte		N03   , Fs5 , v112
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Fs5 , v088
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W18
	.byte		        Fs5 , v088
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Fs5 , v096
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_daigo_1_004
	.byte	PATT
	 .word	mus_daigo_1_004
	.byte	PATT
	 .word	mus_daigo_1_004
	.byte	GOTO
	 .word	mus_daigo_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_daigo_2:
	.byte	KEYSH , mus_daigo_key+0
	.byte		VOICE , 17
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 63*mus_daigo_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		N06   , Cn5 , v112
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N03   , Cn4 
	.byte	W06
	.byte		N06   , Cn5 
	.byte	W12
	.byte		        An4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N18   , Ds5 
	.byte	W18
	.byte		N06   , Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte	W06
	.byte	W96
mus_daigo_2_B1:
	.byte		VOICE , 17
	.byte		PAN   , c_v+32
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N03   , Cs4 , v112
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		VOICE , 17
	.byte		N06   , An4 
	.byte	W06
	.byte		N03   , Cn5 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N18   , Ds5 
	.byte	W18
	.byte		N06   , En5 
	.byte	W30
	.byte		VOICE , 38
	.byte		MOD   , 8
	.byte		PAN   , c_v+24
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		N03   , En1 
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N03   , Gs1 
	.byte	W06
	.byte		N06   , Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		VOICE , 17
	.byte		VOL   , 63*mus_daigo_mvl/mxv
	.byte		MOD   , 0
	.byte		PAN   , c_v+32
	.byte		N03   , Cs4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		VOICE , 17
	.byte		N06   , An4 
	.byte	W06
	.byte		N03   , Cn5 
	.byte	W12
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N18   , Ds5 
	.byte	W18
	.byte		N06   , En5 
	.byte	W30
	.byte		VOICE , 38
	.byte		MOD   , 6
	.byte		PAN   , c_v+25
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		N03   , En1 
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N03   , Gs1 
	.byte	W06
	.byte		N06   , Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		VOICE , 56
	.byte		MOD   , 0
	.byte		PAN   , c_v+32
	.byte		N03   , Bn3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		VOICE , 56
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , As4 
	.byte	W06
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N18   , Cs5 
	.byte	W18
	.byte		N06   , Dn5 
	.byte	W30
	.byte		VOICE , 38
	.byte		MOD   , 8
	.byte		PAN   , c_v+25
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N03   , Gn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N03   , Gn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N03   , Dn1 
	.byte	W06
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N06   , An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		VOICE , 56
	.byte		VOL   , 63*mus_daigo_mvl/mxv
	.byte		MOD   , 0
	.byte		PAN   , c_v+32
	.byte		N03   , Bn3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		VOICE , 56
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , As4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N18   , Cs5 
	.byte	W18
	.byte		N06   , Dn5 
	.byte	W30
	.byte		VOICE , 56
	.byte	W48
	.byte		N06   , Gn5 
	.byte	W06
	.byte		N03   , Dn5 
	.byte	W06
	.byte		N06   , As4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N06   , Cs5 
	.byte	W06
	.byte		N03   , Dn5 
	.byte	W06
	.byte		VOICE , 24
	.byte		VOL   , 47*mus_daigo_mvl/mxv
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N66   , En5 
	.byte	W24
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 46*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        43*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        40*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        35*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        32*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        30*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        26*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        20*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        20*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        17*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        13*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        9*mus_daigo_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 47*mus_daigo_mvl/mxv
	.byte		N06   , En5 , v088
	.byte	W12
	.byte		        Fn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Gs5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		N03   , Fn5 
	.byte	W03
	.byte		        Gn5 
	.byte	W03
	.byte		N06   , Fn5 
	.byte	W12
	.byte		        En5 
	.byte	W06
	.byte		VOL   , 47*mus_daigo_mvl/mxv
	.byte		N36   , Dn5 
	.byte	W02
	.byte		VOL   , 41*mus_daigo_mvl/mxv
	.byte	W06
	.byte		        38*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        35*mus_daigo_mvl/mxv
	.byte		MOD   , 6
	.byte	W02
	.byte		VOL   , 32*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        28*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        22*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        47*mus_daigo_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		VOICE , 24
	.byte		N30   , Dn5 
	.byte	W36
	.byte		N06   , En5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		N30   , En5 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		N48   , En5 
	.byte	W24
	.byte		MOD   , 5
	.byte		VOL   , 47*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        43*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        40*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        35*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        31*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        26*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        20*mus_daigo_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte		VOL   , 47*mus_daigo_mvl/mxv
	.byte		N03   , Cs5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        En5 
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N06   , Fn5 
	.byte	W18
	.byte		N48   , Dn5 
	.byte	W24
	.byte		MOD   , 5
	.byte		VOL   , 47*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        46*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        41*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        38*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        32*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        28*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        22*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        20*mus_daigo_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 47*mus_daigo_mvl/mxv
	.byte		N03   , An4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N18   , En5 
	.byte	W18
	.byte		N06   , Fn5 
	.byte	W18
	.byte		N48   , Dn5 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 47*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        46*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        41*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        37*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        35*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        33*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        31*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        28*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        22*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        17*mus_daigo_mvl/mxv
	.byte	W10
	.byte		MOD   , 0
	.byte		VOL   , 47*mus_daigo_mvl/mxv
	.byte		N06   , Cn5 
	.byte	W06
	.byte		TIE   , Gn5 
	.byte	W06
	.byte	W24
	.byte		MOD   , 6
	.byte		VOL   , 46*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        43*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        41*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        39*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        37*mus_daigo_mvl/mxv
	.byte	W05
	.byte		        35*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        35*mus_daigo_mvl/mxv
	.byte	W06
	.byte		        32*mus_daigo_mvl/mxv
	.byte	W06
	.byte		        30*mus_daigo_mvl/mxv
	.byte	W06
	.byte		        28*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        28*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        26*mus_daigo_mvl/mxv
	.byte	W06
	.byte		        23*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        22*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        22*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        20*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        20*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        19*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        18*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        17*mus_daigo_mvl/mxv
	.byte	W05
	.byte		        16*mus_daigo_mvl/mxv
	.byte	W30
	.byte	W01
	.byte		        20*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        20*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        23*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        26*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        28*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        31*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        33*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        35*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        37*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        41*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        43*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        47*mus_daigo_mvl/mxv
	.byte	W28
	.byte		EOT   
	.byte	GOTO
	 .word	mus_daigo_2_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  3 **********************@

mus_daigo_3:
	.byte	KEYSH , mus_daigo_key+0
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 76*mus_daigo_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N06   , An0 , v127
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		BEND  , c_v+10
	.byte	W06
	.byte		        c_v+0
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N18   , An0 
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		BEND  , c_v+0
	.byte		N12   , Gn2 
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , Ds2 
	.byte	W06
	.byte		BEND  , c_v+5
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , Bn1 
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , Gn1 
	.byte	W06
	.byte		BEND  , c_v+5
	.byte	W06
	.byte		        c_v-6
	.byte		N12   , En1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v-5
	.byte		N12   
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v-5
	.byte		N12   
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
mus_daigo_3_B1:
mus_daigo_3_000:
	.byte		BEND  , c_v+0
	.byte		N18   , An0 , v127
	.byte	W18
	.byte		N06   , En1 
	.byte	W18
	.byte		N12   , Bn1 
	.byte	W06
	.byte		BEND  , c_v+5
	.byte	W06
	.byte		        c_v+63
	.byte		N18   , An0 
	.byte	W06
	.byte		BEND  , c_v+1
	.byte	W12
	.byte		N06   , En1 
	.byte	W18
	.byte		N12   , Dn2 
	.byte	W06
	.byte		BEND  , c_v-10
	.byte	W06
	.byte	PEND
	.byte		        c_v+0
	.byte		N12   , Gn1 
	.byte	W06
	.byte		BEND  , c_v+10
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+0
	.byte		N12   
	.byte	W06
	.byte		BEND  , c_v+10
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+0
	.byte		N12   
	.byte	W06
	.byte		BEND  , c_v+10
	.byte	W06
	.byte		        c_v+0
	.byte		N03   , An0 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Gn1 
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , Ds1 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , Bn0 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte	PATT
	 .word	mus_daigo_3_000
	.byte		BEND  , c_v+0
	.byte		N12   , Gn1 , v127
	.byte	W06
	.byte		BEND  , c_v+10
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+0
	.byte		N12   
	.byte	W06
	.byte		BEND  , c_v+10
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+0
	.byte		N12   
	.byte	W06
	.byte		BEND  , c_v+10
	.byte	W06
	.byte		        c_v+0
	.byte		N03   , An0 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , Gn1 
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , Dn1 
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
mus_daigo_3_001:
	.byte		BEND  , c_v+0
	.byte		N18   , Gn0 , v127
	.byte	W18
	.byte		N06   , Dn1 
	.byte	W18
	.byte		N12   , An1 
	.byte	W06
	.byte		BEND  , c_v+5
	.byte	W06
	.byte		        c_v+63
	.byte		N18   , Gn0 
	.byte	W06
	.byte		BEND  , c_v+1
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W18
	.byte		N12   , Cn2 
	.byte	W06
	.byte		BEND  , c_v-10
	.byte	W06
	.byte	PEND
	.byte		        c_v+0
	.byte		N12   , Fn1 
	.byte	W06
	.byte		BEND  , c_v+10
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+0
	.byte		N12   
	.byte	W06
	.byte		BEND  , c_v+10
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+0
	.byte		N12   
	.byte	W06
	.byte		BEND  , c_v+10
	.byte	W06
	.byte		        c_v+0
	.byte		N03   , Gn0 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , Cs1 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , An0 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte	PATT
	 .word	mus_daigo_3_001
	.byte		BEND  , c_v+0
	.byte		N15   , Gn0 , v127
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N12   , Fs1 
	.byte	W06
	.byte		BEND  , c_v+10
	.byte	W06
	.byte		        c_v+1
	.byte		N12   , Gn0 
	.byte	W60
	.byte		BEND  , c_v-5
	.byte		N12   , Fn1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		N03   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		BEND  , c_v-5
	.byte		N12   
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		N03   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		BEND  , c_v-5
	.byte		N12   
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		N03   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		BEND  , c_v-5
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N09   
	.byte	W12
	.byte		N03   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		BEND  , c_v-5
	.byte		N12   , En1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		N03   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		BEND  , c_v-5
	.byte		N12   
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		N03   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		BEND  , c_v-5
	.byte		N12   , An1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		N03   , An2 
	.byte	W06
	.byte		N06   , An1 
	.byte	W06
	.byte		N03   , An2 
	.byte	W06
	.byte		BEND  , c_v-5
	.byte		N12   , An1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N12   , Gn2 
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , Ds2 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , Bn1 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , Gn2 
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v-5
	.byte		N12   , Fn1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		N03   , Fn2 
	.byte	W06
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W06
	.byte		BEND  , c_v-5
	.byte		N12   , Fn1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N12   , En2 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , Bn1 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , Gn1 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , En2 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v-5
	.byte		N12   , Fs1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W06
	.byte		N06   , Fs1 
	.byte	W06
	.byte		N03   , Fs2 
	.byte	W06
	.byte		BEND  , c_v-5
	.byte		N12   , Fs1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N12   , En2 
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , Bn1 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , Gn1 
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , En1 
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v+0
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Fn2 
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , Cs2 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , As1 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v-5
	.byte		N12   , Gn1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N12   , Fn2 
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v+0
	.byte		N03   , Gn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v-5
	.byte		N12   , Gs1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N12   , Fs2 
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , Ds2 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , Bn1 
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , Fs1 
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Dn2 
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte	GOTO
	 .word	mus_daigo_3_B1
	.byte		BEND  , c_v+0
	.byte	FINE

@********************** Track  4 **********************@

mus_daigo_4:
	.byte	KEYSH , mus_daigo_key+0
	.byte		VOICE , 73
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-1
	.byte		VOL   , 47*mus_daigo_mvl/mxv
	.byte	W96
mus_daigo_4_000:
	.byte		N06   , En5 , v112
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte	PEND
mus_daigo_4_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOL   , 19*mus_daigo_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N48   , Dn3 , v112
	.byte	W24
	.byte		VOL   , 17*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        19*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        21*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        22*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        23*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        25*mus_daigo_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v-30
	.byte	W02
	.byte		VOL   , 26*mus_daigo_mvl/mxv
	.byte		PAN   , c_v-23
	.byte	W07
	.byte		VOL   , 27*mus_daigo_mvl/mxv
	.byte		PAN   , c_v-19
	.byte		N06   , En3 
	.byte	W02
	.byte		VOL   , 28*mus_daigo_mvl/mxv
	.byte		PAN   , c_v-14
	.byte	W03
	.byte		VOL   , 29*mus_daigo_mvl/mxv
	.byte		PAN   , c_v-12
	.byte	W01
	.byte		N06   , Fn3 
	.byte	W02
	.byte		VOL   , 32*mus_daigo_mvl/mxv
	.byte		PAN   , c_v-6
	.byte	W04
	.byte		VOL   , 33*mus_daigo_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Gn3 
	.byte	W02
	.byte		PAN   , c_v+9
	.byte	W01
	.byte		VOL   , 34*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        35*mus_daigo_mvl/mxv
	.byte		PAN   , c_v+16
	.byte	W01
	.byte		N06   , An3 
	.byte	W02
	.byte		VOL   , 37*mus_daigo_mvl/mxv
	.byte		PAN   , c_v+22
	.byte	W04
	.byte		VOL   , 39*mus_daigo_mvl/mxv
	.byte		PAN   , c_v+26
	.byte		N06   , As3 
	.byte	W02
	.byte		VOL   , 43*mus_daigo_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W03
	.byte		VOL   , 49*mus_daigo_mvl/mxv
	.byte		PAN   , c_v+36
	.byte	W01
	.byte		N06   , Cn4 
	.byte	W02
	.byte		VOL   , 58*mus_daigo_mvl/mxv
	.byte		PAN   , c_v+41
	.byte	W04
	.byte		VOL   , 62*mus_daigo_mvl/mxv
	.byte		PAN   , c_v+43
	.byte		N06   , Dn4 
	.byte	W02
	.byte		VOL   , 65*mus_daigo_mvl/mxv
	.byte		PAN   , c_v+48
	.byte	W04
	.byte		N06   , Cs4 
	.byte	W06
	.byte		VOL   , 40*mus_daigo_mvl/mxv
	.byte		PAN   , c_v-28
	.byte		N84   , Cn4 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		VOL   , 40*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        35*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        34*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        32*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        29*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        28*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        22*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        16*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        13*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        11*mus_daigo_mvl/mxv
	.byte	W01
	.byte		        10*mus_daigo_mvl/mxv
	.byte	W06
	.byte		        8*mus_daigo_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 41*mus_daigo_mvl/mxv
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N96   , Bn3 
	.byte	W48
	.byte		MOD   , 5
	.byte		VOL   , 40*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        40*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        37*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        33*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        32*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        28*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        23*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        19*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        17*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        14*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        13*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        13*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        12*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        11*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        9*mus_daigo_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte		VOL   , 41*mus_daigo_mvl/mxv
	.byte		N48   
	.byte	W24
	.byte		MOD   , 5
	.byte		VOL   , 37*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        33*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        28*mus_daigo_mvl/mxv
	.byte	W01
	.byte		        28*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        26*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        23*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        23*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        22*mus_daigo_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte		VOL   , 40*mus_daigo_mvl/mxv
	.byte		N48   , As3 
	.byte	W24
	.byte		MOD   , 5
	.byte		VOL   , 37*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        33*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        31*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        26*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        23*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        21*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        20*mus_daigo_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte		VOL   , 40*mus_daigo_mvl/mxv
	.byte		N24   , An4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N03   , En4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		N06   , En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N18   , Bn4 
	.byte	W18
	.byte		N06   , Cn5 
	.byte	W21
	.byte		N44   , An4 
	.byte	W21
	.byte		MOD   , 5
	.byte		VOL   , 37*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        35*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        32*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        28*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        26*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        22*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        18*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        16*mus_daigo_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 41*mus_daigo_mvl/mxv
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N18   , Bn4 
	.byte	W18
	.byte		N06   , Cn5 
	.byte	W18
	.byte		N48   , An4 
	.byte	W24
	.byte		MOD   , 5
	.byte		VOL   , 40*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        37*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        35*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        32*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        31*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        26*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        21*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        17*mus_daigo_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 41*mus_daigo_mvl/mxv
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N42   , Gn4 
	.byte	W06
	.byte	W12
	.byte		MOD   , 5
	.byte		VOL   , 40*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        37*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        35*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        32*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        30*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        26*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        23*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        19*mus_daigo_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 41*mus_daigo_mvl/mxv
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N36   , Bn4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W03
	.byte		VOL   , 36*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        31*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        28*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        26*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        23*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        22*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        18*mus_daigo_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 41*mus_daigo_mvl/mxv
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte	PATT
	 .word	mus_daigo_4_000
	.byte	GOTO
	 .word	mus_daigo_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_daigo_5:
	.byte	KEYSH , mus_daigo_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 40*mus_daigo_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		N06   , En5 , v096
	.byte	W72
	.byte		N06   
	.byte	W12
	.byte	W12
	.byte		N06   
	.byte	W60
	.byte		N06   
	.byte	W24
mus_daigo_5_B1:
mus_daigo_5_000:
	.byte	W12
	.byte		N06   , En5 , v096
	.byte	W72
	.byte		N06   
	.byte	W12
	.byte	PEND
mus_daigo_5_001:
	.byte		N06   , En5 , v096
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W48
	.byte		N06   
	.byte	W12
	.byte	PEND
mus_daigo_5_002:
	.byte	W12
	.byte		N06   , En5 , v096
	.byte	W48
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_daigo_5_001
	.byte	PATT
	 .word	mus_daigo_5_000
	.byte	PATT
	 .word	mus_daigo_5_001
	.byte	PATT
	 .word	mus_daigo_5_002
	.byte	PATT
	 .word	mus_daigo_5_002
mus_daigo_5_003:
	.byte		N06   , En5 , v112
	.byte	W30
	.byte		        En5 , v080
	.byte	W12
	.byte		        En5 , v112
	.byte	W12
	.byte		        En5 , v080
	.byte	W18
	.byte		        En5 , v088
	.byte	W12
	.byte		        En5 , v112
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_daigo_5_003
	.byte	PATT
	 .word	mus_daigo_5_003
	.byte	PATT
	 .word	mus_daigo_5_003
mus_daigo_5_004:
	.byte	W36
	.byte		N06   , En5 , v092
	.byte	W48
	.byte		        En5 , v112
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_daigo_5_004
	.byte	PATT
	 .word	mus_daigo_5_004
	.byte	PATT
	 .word	mus_daigo_5_004
	.byte	GOTO
	 .word	mus_daigo_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_daigo_6:
	.byte	KEYSH , mus_daigo_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 38*mus_daigo_mvl/mxv
	.byte		PAN   , c_v-61
	.byte	W96
	.byte		VOL   , 8*mus_daigo_mvl/mxv
	.byte		N96   , Bn3 , v112
	.byte	W08
	.byte		VOL   , 11*mus_daigo_mvl/mxv
	.byte	W12
	.byte		        14*mus_daigo_mvl/mxv
	.byte	W12
	.byte		        17*mus_daigo_mvl/mxv
	.byte	W21
	.byte		        19*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        20*mus_daigo_mvl/mxv
	.byte	W06
	.byte		        23*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        26*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        34*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        38*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        51*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        62*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        65*mus_daigo_mvl/mxv
	.byte	W16
mus_daigo_6_B1:
	.byte		VOICE , 80
	.byte		VOL   , 44*mus_daigo_mvl/mxv
	.byte		N09   , Cn6 , v112
	.byte	W12
	.byte		N06   , Cn6 , v092
	.byte	W12
	.byte		N03   , Cn6 , v112
	.byte	W06
	.byte		N12   , Cn6 , v092
	.byte	W12
	.byte		N03   , Cn6 , v112
	.byte	W12
	.byte		        Cn6 , v092
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn6 , v112
	.byte	W12
	.byte		        Cn6 , v096
	.byte	W12
mus_daigo_6_000:
	.byte		N06   , An6 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   , An5 
	.byte	W06
	.byte		N06   , An6 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		N06   , An6 
	.byte	W12
	.byte		N03   , An5 
	.byte	W06
	.byte	PEND
	.byte		N09   , Cn6 
	.byte	W12
	.byte		N06   , Cn6 , v092
	.byte	W12
	.byte		N03   , Cn6 , v112
	.byte	W06
	.byte		N12   , Cn6 , v092
	.byte	W12
	.byte		N03   , Cn6 , v112
	.byte	W12
	.byte		        Cn6 , v092
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn6 , v112
	.byte	W12
	.byte		        Cn6 , v096
	.byte	W12
	.byte	PATT
	 .word	mus_daigo_6_000
mus_daigo_6_001:
	.byte		N09   , As5 , v112
	.byte	W12
	.byte		N06   , As5 , v092
	.byte	W12
	.byte		N03   , As5 , v112
	.byte	W06
	.byte		N12   , As5 , v092
	.byte	W12
	.byte		N03   , As5 , v112
	.byte	W12
	.byte		        As5 , v092
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , As5 , v112
	.byte	W12
	.byte		        As5 , v096
	.byte	W12
	.byte	PEND
	.byte		        Gn6 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   , Gn5 
	.byte	W06
	.byte		N06   , Gn6 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		N06   , Gn6 
	.byte	W12
	.byte		N03   , Gn5 
	.byte	W06
	.byte	PATT
	 .word	mus_daigo_6_001
	.byte		MOD   , 4
	.byte		N06   , Gn6 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   , Gn5 
	.byte	W06
	.byte		N06   , Gn6 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		N06   , Gn6 
	.byte	W06
	.byte		VOICE , 81
	.byte		VOL   , 38*mus_daigo_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte		N03   , Gn5 
	.byte	W06
	.byte		N84   , An3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W60
	.byte		        0
	.byte		N06   , As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N84   , Gs3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W60
	.byte		        0
	.byte		N06   , En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N36   , Gn3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , En3 
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N48   , Gn3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N84   , An3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W60
	.byte		        0
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N30   , An3 
	.byte	W30
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N36   , Cn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N54   , Fs3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N36   , Dn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W03
	.byte		N36   , Gn3 
	.byte	W24
	.byte	W03
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , En3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N36   , Bn3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N24   , Gs3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N03   , En3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte	GOTO
	 .word	mus_daigo_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_daigo_7:
	.byte	KEYSH , mus_daigo_key+0
	.byte		VOICE , 83
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 38*mus_daigo_mvl/mxv
	.byte	W96
	.byte		        8*mus_daigo_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		N96   , Dn3 , v112
	.byte	W08
	.byte		VOL   , 11*mus_daigo_mvl/mxv
	.byte	W12
	.byte		        14*mus_daigo_mvl/mxv
	.byte	W12
	.byte		        17*mus_daigo_mvl/mxv
	.byte	W21
	.byte		        19*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        20*mus_daigo_mvl/mxv
	.byte	W06
	.byte		        23*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        26*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        34*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        38*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        51*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        62*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        65*mus_daigo_mvl/mxv
	.byte	W16
mus_daigo_7_B1:
	.byte		VOICE , 83
	.byte		VOL   , 38*mus_daigo_mvl/mxv
	.byte		N06   , Gn2 , v112
	.byte	W06
	.byte		N03   , An2 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N06   , Gs2 
	.byte	W06
	.byte		N03   , An2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gs2 
	.byte	W06
	.byte		N03   , An2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Bn1 
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		N06   , Bn1 
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W06
	.byte		N06   , Ds2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N03   , An2 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Cs3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		N24   , Cn4 
	.byte	W24
	.byte	W96
	.byte		N06   , Fn2 
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N03   , As1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , An1 
	.byte	W06
	.byte		N03   , As1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		N03   , Gn1 
	.byte	W06
	.byte		N06   , An1 
	.byte	W06
	.byte		N03   , As1 
	.byte	W06
	.byte		N06   , Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Bn2 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		TIE   , As3 
	.byte	W24
	.byte		MOD   , 4
	.byte	W48
	.byte		VOL   , 40*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        44*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        47*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        52*mus_daigo_mvl/mxv
	.byte	W04
	.byte		        55*mus_daigo_mvl/mxv
	.byte	W02
	.byte		        62*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        68*mus_daigo_mvl/mxv
	.byte	W03
	.byte		        71*mus_daigo_mvl/mxv
	.byte	W16
	.byte		EOT   
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		VOL   , 38*mus_daigo_mvl/mxv
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		VOICE , 82
	.byte		PAN   , c_v+63
	.byte		N84   , En4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W60
	.byte		        0
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N84   , Dn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W60
	.byte		        0
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N36   , Dn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N48   , Dn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N84   , Cs4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W60
	.byte		        0
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N30   , Cn4 
	.byte	W30
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N36   , En4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N54   , Cn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N36   , Gn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N36   , Dn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N36   , En4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N24   , Bn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N03   , Gs3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte	GOTO
	 .word	mus_daigo_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_daigo_8:
	.byte	KEYSH , mus_daigo_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 76*mus_daigo_mvl/mxv
	.byte		N06   , Dn1 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N42   , An2 
	.byte	W42
	.byte	W96
mus_daigo_8_B1:
	.byte	W18
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        En3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W18
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En3 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
mus_daigo_8_000:
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        En3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W18
	.byte		        Dn3 
	.byte	W06
	.byte	PEND
	.byte		        Cn1 
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte	PATT
	 .word	mus_daigo_8_000
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En3 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte	PATT
	 .word	mus_daigo_8_000
	.byte	PATT
	 .word	mus_daigo_8_000
mus_daigo_8_001:
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte	PATT
	 .word	mus_daigo_8_001
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
mus_daigo_8_002:
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N03   , Cn1 , v088
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn1 , v096
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_daigo_8_002
	.byte		N06   , Dn1 , v112
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		N03   , Cn1 , v088
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		N03   , Cn1 , v088
	.byte	W06
	.byte		N06   , Dn1 , v112
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 , v096
	.byte	W06
	.byte	GOTO
	 .word	mus_daigo_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_daigo_9:
	.byte	KEYSH , mus_daigo_key+0
	.byte		VOICE , 29
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 47*mus_daigo_mvl/mxv
	.byte	W96
	.byte	W96
mus_daigo_9_B1:
	.byte		VOICE , 29
	.byte		VOL   , 56*mus_daigo_mvl/mxv
	.byte		N06   , Bn1 , v112
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N06   , Bn1 
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Bn1 
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		N03   , En1 
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N03   , Gs1 
	.byte	W06
	.byte		N06   , Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N06   , Bn1 
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Fn2 , v060
	.byte	W03
	.byte		        Gn2 
	.byte	W03
	.byte		        Gs2 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		N24   , En3 
	.byte	W03
	.byte		BEND  , c_v-6
	.byte	W03
	.byte		        c_v-11
	.byte	W03
	.byte		        c_v-20
	.byte	W03
	.byte		        c_v-26
	.byte	W03
	.byte		        c_v-32
	.byte	W03
	.byte		        c_v-40
	.byte	W03
	.byte		        c_v-50
	.byte	W03
	.byte		        c_v+0
	.byte		N06   , Gn1 , v112
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		N03   , En1 
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N03   , Gs1 
	.byte	W06
	.byte		N06   , Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N06   , An1 
	.byte	W06
	.byte		N03   , As1 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		N06   , An1 
	.byte	W06
	.byte		N03   , As1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , An1 
	.byte	W06
	.byte		N03   , As1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N03   , Gn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N03   , Gn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N03   , Dn1 
	.byte	W06
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N06   , An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N06   , An1 
	.byte	W06
	.byte		N03   , As1 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Ds2 , v064
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		        Fs2 
	.byte	W03
	.byte		        Gn2 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		N24   , Dn3 
	.byte	W03
	.byte		BEND  , c_v-6
	.byte	W03
	.byte		        c_v-11
	.byte	W03
	.byte		        c_v-20
	.byte	W03
	.byte		        c_v-26
	.byte	W03
	.byte		        c_v-32
	.byte	W03
	.byte		        c_v-40
	.byte	W03
	.byte		        c_v-50
	.byte	W03
	.byte		        c_v+0
	.byte	W48
	.byte		VOICE , 85
	.byte	W24
	.byte		VOL   , 21*mus_daigo_mvl/mxv
	.byte		BEND  , c_v+2
	.byte	W12
	.byte		N06   , Bn4 , v104
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+2
	.byte		N66   , En5 
	.byte	W24
	.byte		MOD   , 7
	.byte	W48
	.byte		        0
	.byte		N06   
	.byte	W12
	.byte		        Fn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Gs5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		N03   , Fn5 
	.byte	W03
	.byte		        Gn5 
	.byte	W03
	.byte		N06   , Fn5 
	.byte	W12
	.byte		        En5 
	.byte	W06
	.byte		N36   , Dn5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N30   , Dn5 
	.byte	W36
	.byte		N06   , En5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		N30   , En5 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		N48   , En5 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N03   , Cs5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        En5 
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N06   , Fn5 
	.byte	W18
	.byte		N48   , Dn5 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N03   , An4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N18   , En5 
	.byte	W18
	.byte		N06   , Fn5 
	.byte	W18
	.byte		N48   , Dn5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W36
	.byte		        0
	.byte		N06   , Cn5 
	.byte	W06
	.byte		TIE   , Gn5 
	.byte	W06
	.byte	W24
	.byte		MOD   , 6
	.byte	W72
	.byte	W72
	.byte		EOT   
	.byte		N03   , Fn5 , v060
	.byte	W03
	.byte		        En5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte	GOTO
	 .word	mus_daigo_9_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track 10 **********************@

mus_daigo_10:
	.byte	KEYSH , mus_daigo_key+0
	.byte		VOICE , 17
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-17
	.byte		VOL   , 50*mus_daigo_mvl/mxv
	.byte		N06   , Ds4 , v112
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W12
	.byte		        Cn4 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N18   , Gn4 
	.byte	W18
	.byte		N06   , Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte	W96
mus_daigo_10_B1:
	.byte		VOICE , 17
	.byte		VOL   , 52*mus_daigo_mvl/mxv
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		VOICE , 17
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   , En4 
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N18   , Gs4 
	.byte	W18
	.byte		N06   , An4 
	.byte	W30
	.byte		VOICE , 47
	.byte		VOL   , 52*mus_daigo_mvl/mxv
	.byte		PAN   , c_v-10
	.byte		N06   , An2 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gs2 
	.byte	W12
	.byte		VOICE , 17
	.byte		PAN   , c_v-32
	.byte		VOL   , 52*mus_daigo_mvl/mxv
	.byte		N03   , Cs2 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		VOICE , 17
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   , En4 
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N18   , Gs4 
	.byte	W18
	.byte		N06   , An4 
	.byte	W30
	.byte		VOICE , 47
	.byte		VOL   , 52*mus_daigo_mvl/mxv
	.byte		PAN   , c_v-11
	.byte		N06   , An2 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gs2 
	.byte	W12
	.byte		VOICE , 17
	.byte		PAN   , c_v-32
	.byte		N03   , Dn3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		VOICE , 38
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N12   , An3 
	.byte	W12
	.byte		N18   , Fs4 
	.byte	W18
	.byte		N06   , Gn4 
	.byte	W30
	.byte		VOICE , 47
	.byte		VOL   , 52*mus_daigo_mvl/mxv
	.byte		PAN   , c_v-11
	.byte		N06   , Gn2 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fs2 
	.byte	W12
	.byte		VOICE , 17
	.byte		PAN   , c_v-32
	.byte		VOL   , 52*mus_daigo_mvl/mxv
	.byte		N03   , Bn1 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		VOICE , 38
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W12
	.byte		N06   , An3 
	.byte	W06
	.byte		N18   , Fs4 
	.byte	W18
	.byte		N06   , Gn4 
	.byte	W30
	.byte		VOICE , 56
	.byte	W48
	.byte		N06   , As4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_daigo_10_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_daigo:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_daigo_pri	@ Priority
	.byte	mus_daigo_rev	@ Reverb.

	.word	mus_daigo_grp

	.word	mus_daigo_1
	.word	mus_daigo_2
	.word	mus_daigo_3
	.word	mus_daigo_4
	.word	mus_daigo_5
	.word	mus_daigo_6
	.word	mus_daigo_7
	.word	mus_daigo_8
	.word	mus_daigo_9
	.word	mus_daigo_10

	.end
