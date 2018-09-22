	.include "MPlayDef.s"

	.equ	mus_tsuretek_grp, voicegroup066
	.equ	mus_tsuretek_pri, 0
	.equ	mus_tsuretek_rev, reverb_set+50
	.equ	mus_tsuretek_mvl, 127
	.equ	mus_tsuretek_key, 0
	.equ	mus_tsuretek_tbs, 1
	.equ	mus_tsuretek_exg, 0
	.equ	mus_tsuretek_cmp, 1

	.section .rodata
	.global	mus_tsuretek
	.align	2

@********************** Track  1 **********************@

mus_tsuretek_1:
	.byte	KEYSH , mus_tsuretek_key+0
	.byte	TEMPO , 128*mus_tsuretek_tbs/2
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 35*mus_tsuretek_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N04   , Cn5 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Cn5 , v096
	.byte	W08
	.byte		        Cn5 , v064
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cn5 , v112
	.byte	W16
	.byte		        Cn5 , v084
	.byte	W08
	.byte		        Cn5 , v112
	.byte	W16
	.byte		        Cn5 , v060
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        Cn5 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Cn5 , v096
	.byte	W08
	.byte		        Cn5 , v064
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cn5 , v112
	.byte	W08
	.byte		        Cn5 , v060
	.byte	W08
	.byte		        Cn5 , v084
	.byte	W08
	.byte		        Cn5 , v112
	.byte	W16
	.byte		        Cn5 , v060
	.byte	W04
	.byte		N04   
	.byte	W04
mus_tsuretek_1_B1:
mus_tsuretek_1_000:
	.byte		N04   , Cn5 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Cn5 , v096
	.byte	W08
	.byte		        Cn5 , v064
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cn5 , v112
	.byte	W16
	.byte		        Cn5 , v084
	.byte	W08
	.byte		        Cn5 , v112
	.byte	W16
	.byte		        Cn5 , v060
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	mus_tsuretek_1_000
	.byte	PATT
	 .word	mus_tsuretek_1_000
	.byte	PATT
	 .word	mus_tsuretek_1_000
mus_tsuretek_1_001:
	.byte		N04   , Cn5 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Cn5 , v096
	.byte	W04
	.byte		        Cn5 , v048
	.byte	W04
	.byte		        Cn5 , v060
	.byte	W04
	.byte		        Cn5 , v044
	.byte	W04
	.byte		        Cn5 , v052
	.byte	W04
	.byte		        Cn5 , v040
	.byte	W04
	.byte		        Cn5 , v112
	.byte	W16
	.byte		        Cn5 , v084
	.byte	W08
	.byte		        Cn5 , v096
	.byte	W04
	.byte		        Cn5 , v048
	.byte	W04
	.byte		        Cn5 , v060
	.byte	W04
	.byte		        Cn5 , v044
	.byte	W04
	.byte		        Cn5 , v052
	.byte	W04
	.byte		        Cn5 , v040
	.byte	W04
	.byte	PEND
mus_tsuretek_1_002:
	.byte		N04   , Cn5 , v112
	.byte	W12
	.byte		N04   
	.byte	W12
	.byte		N04   
	.byte	W04
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v112
	.byte	W08
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W04
	.byte		        Cn5 , v048
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	mus_tsuretek_1_000
	.byte	PATT
	 .word	mus_tsuretek_1_000
	.byte	PATT
	 .word	mus_tsuretek_1_000
	.byte	PATT
	 .word	mus_tsuretek_1_000
	.byte	PATT
	 .word	mus_tsuretek_1_001
	.byte	PATT
	 .word	mus_tsuretek_1_002
	.byte	GOTO
	 .word	mus_tsuretek_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_tsuretek_2:
	.byte	KEYSH , mus_tsuretek_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 54*mus_tsuretek_mvl/mxv
	.byte		N16   , En5 , v112
	.byte	W16
	.byte		N04   , Dn5 
	.byte	W08
	.byte		        Cs5 
	.byte	W16
	.byte		        Dn5 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        En5 
	.byte	W48
mus_tsuretek_2_B1:
	.byte		N04   , An3 , v112
	.byte	W16
	.byte		        Cs4 
	.byte	W08
	.byte		N16   , En4 
	.byte	W24
	.byte		N04   , Dn4 
	.byte	W16
	.byte		        Fs4 
	.byte	W08
	.byte		N16   , An4 
	.byte	W24
	.byte		N04   , An3 
	.byte	W16
	.byte		        Cs4 
	.byte	W08
	.byte		N16   , En4 
	.byte	W24
	.byte		N04   , Dn4 
	.byte	W16
	.byte		        Cs4 
	.byte	W08
	.byte		N16   , Bn3 
	.byte	W24
	.byte		N04   , En3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N12   , En4 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Dn4 
	.byte	W16
	.byte		        Fs4 
	.byte	W08
	.byte		        An4 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Gs4 
	.byte	W16
	.byte		        En4 
	.byte	W08
	.byte		N12   , Fs4 
	.byte	W16
	.byte		N04   , Gs4 
	.byte	W08
	.byte		        An4 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N16   
	.byte	W24
	.byte	W96
	.byte	W96
	.byte		N04   , Cs5 
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		N16   
	.byte	W24
	.byte		N04   , Fs5 
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		N16   
	.byte	W24
	.byte		N04   , Cs5 
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		N16   
	.byte	W24
	.byte		N04   , Bn4 
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		N16   , Gs4 
	.byte	W24
	.byte		N04   , Cs5 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W16
	.byte		N04   , En4 
	.byte	W08
	.byte		        Fs5 
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		        En5 
	.byte	W08
	.byte		        Dn5 
	.byte	W16
	.byte		        Bn4 
	.byte	W08
	.byte		N12   , An4 
	.byte	W16
	.byte		N04   , Gs4 
	.byte	W08
	.byte		        An4 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N16   
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_tsuretek_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_tsuretek_3:
	.byte	KEYSH , mus_tsuretek_key+0
	.byte		VOICE , 35
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+3
	.byte		VOL   , 74*mus_tsuretek_mvl/mxv
	.byte		N04   , Gs1 , v127
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		        En2 
	.byte	W16
	.byte		        Gs2 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Bn2 
	.byte	W16
	.byte		        Dn3 
	.byte	W08
	.byte		BEND  , c_v+0
	.byte		N04   , En2 
	.byte	W24
	.byte		        Bn1 
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte		BEND  , c_v+0
	.byte		N24   , Gs1 
	.byte	W04
	.byte		BEND  , c_v-8
	.byte	W04
	.byte		        c_v-23
	.byte	W04
	.byte		        c_v-42
	.byte	W04
	.byte		        c_v-52
	.byte	W04
	.byte		        c_v-62
	.byte	W04
mus_tsuretek_3_B1:
	.byte		BEND  , c_v+0
	.byte		N04   , An1 , v127
	.byte	W24
	.byte		N16   , En1 
	.byte	W16
	.byte		N04   , An1 
	.byte	W08
	.byte		        Bn1 
	.byte	W24
	.byte		N16   , Dn2 
	.byte	W16
	.byte		N04   , Gs1 
	.byte	W08
mus_tsuretek_3_000:
	.byte		N04   , An1 , v127
	.byte	W24
	.byte		N16   , En1 
	.byte	W16
	.byte		N04   , An1 
	.byte	W08
	.byte		        Bn1 
	.byte	W24
	.byte		N16   , Dn2 
	.byte	W16
	.byte		N04   , Gs1 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_tsuretek_3_000
mus_tsuretek_3_001:
	.byte		N04   , Gs1 , v127
	.byte	W24
	.byte		N16   , En1 
	.byte	W16
	.byte		N04   , Gs1 
	.byte	W08
	.byte		        An1 
	.byte	W16
	.byte		        Cs2 
	.byte	W08
	.byte		N16   , An1 
	.byte	W24
	.byte	PEND
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_tsuretek_3_000
	.byte	PATT
	 .word	mus_tsuretek_3_000
	.byte	PATT
	 .word	mus_tsuretek_3_000
	.byte	PATT
	 .word	mus_tsuretek_3_001
	.byte		N04   , En1 , v127
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W24
	.byte		N04   
	.byte	W12
	.byte		N04   
	.byte	W12
	.byte		        Gs1 
	.byte	W04
	.byte		        En1 
	.byte	W12
	.byte		        Gs1 
	.byte	W08
	.byte		N16   , Bn1 
	.byte	W48
	.byte	GOTO
	 .word	mus_tsuretek_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_tsuretek_4:
	.byte	KEYSH , mus_tsuretek_key+0
	.byte		VOICE , 45
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 46*mus_tsuretek_mvl/mxv
	.byte		PAN   , c_v-17
	.byte		N16   , Bn4 , v112
	.byte	W16
	.byte		N04   , An4 
	.byte	W08
	.byte		        Gs4 
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Bn3 
	.byte	W24
	.byte		        Gs3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Gs4 
	.byte	W48
mus_tsuretek_4_B1:
mus_tsuretek_4_000:
	.byte		N04   , En3 , v112
	.byte	W16
	.byte		        An3 
	.byte	W08
	.byte		N16   , Cs4 
	.byte	W24
	.byte		N04   , Bn3 
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte		N16   , Fs4 
	.byte	W24
	.byte	PEND
mus_tsuretek_4_001:
	.byte		N04   , En3 , v112
	.byte	W16
	.byte		        An3 
	.byte	W08
	.byte		N16   , Cs4 
	.byte	W24
	.byte		N04   , Bn3 
	.byte	W16
	.byte		        An3 
	.byte	W08
	.byte		N16   , Gs3 
	.byte	W24
	.byte	PEND
	.byte		N04   , An2 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N12   , Cs4 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Bn3 
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Dn4 
	.byte	W16
	.byte		        An3 
	.byte	W08
	.byte		N12   , Cs4 
	.byte	W16
	.byte		N04   , Dn4 
	.byte	W08
	.byte		        En4 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N16   
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_tsuretek_4_000
	.byte	PATT
	 .word	mus_tsuretek_4_001
	.byte		N04   , An2 , v112
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N12   , Cs4 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Bn3 
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W16
	.byte		        Bn4 
	.byte	W08
	.byte		        An4 
	.byte	W16
	.byte		        Fs4 
	.byte	W08
	.byte		N12   , En4 
	.byte	W16
	.byte		N04   , Dn4 
	.byte	W08
	.byte		        En4 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N16   
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_tsuretek_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_tsuretek_5:
	.byte	KEYSH , mus_tsuretek_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 37*mus_tsuretek_mvl/mxv
	.byte		PAN   , c_v-62
	.byte		N16   , En3 , v112
	.byte	W16
	.byte		N04   , Dn3 
	.byte	W08
	.byte		        Cs3 
	.byte	W16
	.byte		        Dn3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        En2 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        En3 
	.byte	W48
mus_tsuretek_5_B1:
mus_tsuretek_5_000:
	.byte	W16
	.byte		N04   , An2 , v112
	.byte	W04
	.byte		        Gs2 
	.byte	W04
	.byte		N12   , An2 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Gs2 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N16   , Fs2 
	.byte	W16
	.byte		N04   , Gs2 
	.byte	W08
	.byte	PEND
mus_tsuretek_5_001:
	.byte	W16
	.byte		N04   , An2 , v112
	.byte	W04
	.byte		        Gs2 
	.byte	W04
	.byte		N12   , An2 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Bn2 
	.byte	W16
	.byte		        An2 
	.byte	W08
	.byte		N16   , Gs2 
	.byte	W16
	.byte		N04   , Bn2 
	.byte	W08
	.byte	PEND
mus_tsuretek_5_002:
	.byte	W16
	.byte		N04   , An2 , v112
	.byte	W04
	.byte		        Gs2 
	.byte	W04
	.byte		N12   , An2 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Gs2 
	.byte	W16
	.byte		        Bn2 
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N04   , Bn2 
	.byte	W08
	.byte	PEND
mus_tsuretek_5_003:
	.byte	W16
	.byte		N04   , Bn2 , v112
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		N12   , Dn3 
	.byte	W16
	.byte		N04   , Bn2 
	.byte	W08
	.byte		        Cs3 
	.byte	W16
	.byte		        Bn2 
	.byte	W08
	.byte		N16   , An2 
	.byte	W16
	.byte		N04   , En2 
	.byte	W08
	.byte	PEND
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_tsuretek_5_000
	.byte	PATT
	 .word	mus_tsuretek_5_001
	.byte	PATT
	 .word	mus_tsuretek_5_002
	.byte	PATT
	 .word	mus_tsuretek_5_003
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_tsuretek_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_tsuretek_6:
	.byte	KEYSH , mus_tsuretek_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 37*mus_tsuretek_mvl/mxv
	.byte		N16   , Bn3 , v112
	.byte	W16
	.byte		N04   , An3 
	.byte	W08
	.byte		        Gs3 
	.byte	W16
	.byte		        An3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Bn2 
	.byte	W24
	.byte		        Gs2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Gs3 
	.byte	W48
mus_tsuretek_6_B1:
mus_tsuretek_6_000:
	.byte	W16
	.byte		N04   , Cs3 , v112
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		N12   , Cs3 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Bn2 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N16   , An2 
	.byte	W16
	.byte		N04   , Bn2 
	.byte	W08
	.byte	PEND
mus_tsuretek_6_001:
	.byte	W16
	.byte		N04   , Cs3 , v112
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		N12   , Cs3 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Dn3 
	.byte	W16
	.byte		        Cs3 
	.byte	W08
	.byte		N16   , Bn2 
	.byte	W16
	.byte		N04   , En3 
	.byte	W08
	.byte	PEND
mus_tsuretek_6_002:
	.byte	W16
	.byte		N04   , Cs3 , v112
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		N12   , Cs3 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Bn2 
	.byte	W16
	.byte		        Dn3 
	.byte	W08
	.byte		N16   , Fs3 
	.byte	W16
	.byte		N04   , Dn3 
	.byte	W08
	.byte	PEND
mus_tsuretek_6_003:
	.byte	W16
	.byte		N04   , Dn3 , v112
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		N12   , Fs3 
	.byte	W16
	.byte		N04   , Dn3 
	.byte	W08
	.byte		        En3 
	.byte	W16
	.byte		        Dn3 
	.byte	W08
	.byte		N16   , Cs3 
	.byte	W16
	.byte		N04   , An2 
	.byte	W08
	.byte	PEND
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_tsuretek_6_000
	.byte	PATT
	 .word	mus_tsuretek_6_001
	.byte	PATT
	 .word	mus_tsuretek_6_002
	.byte	PATT
	 .word	mus_tsuretek_6_003
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_tsuretek_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_tsuretek_7:
	.byte	KEYSH , mus_tsuretek_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 55*mus_tsuretek_mvl/mxv
	.byte		N04   , En1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En1 , v096
	.byte	W08
	.byte		        En1 , v064
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v084
	.byte	W08
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v060
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En1 , v096
	.byte	W08
	.byte		        En1 , v064
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En1 , v112
	.byte	W08
	.byte		        En1 , v060
	.byte	W08
	.byte		        En1 , v084
	.byte	W08
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v060
	.byte	W04
	.byte		N04   
	.byte	W04
mus_tsuretek_7_B1:
mus_tsuretek_7_000:
	.byte		N04   , En1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En1 , v096
	.byte	W08
	.byte		        En1 , v064
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v084
	.byte	W08
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v060
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	mus_tsuretek_7_000
	.byte	PATT
	 .word	mus_tsuretek_7_000
	.byte	PATT
	 .word	mus_tsuretek_7_000
mus_tsuretek_7_001:
	.byte		N04   , En1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En1 , v096
	.byte	W04
	.byte		        En1 , v048
	.byte	W04
	.byte		        En1 , v060
	.byte	W04
	.byte		        En1 , v044
	.byte	W04
	.byte		        En1 , v052
	.byte	W04
	.byte		        En1 , v040
	.byte	W04
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v084
	.byte	W08
	.byte		        En1 , v096
	.byte	W04
	.byte		        En1 , v048
	.byte	W04
	.byte		        En1 , v060
	.byte	W04
	.byte		        En1 , v044
	.byte	W04
	.byte		        En1 , v052
	.byte	W04
	.byte		        En1 , v040
	.byte	W04
	.byte	PEND
mus_tsuretek_7_002:
	.byte		N04   , En1 , v112
	.byte	W12
	.byte		N04   
	.byte	W12
	.byte		N04   
	.byte	W04
	.byte		        En1 , v084
	.byte	W12
	.byte		        En1 , v112
	.byte	W08
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W04
	.byte		        En1 , v048
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	mus_tsuretek_7_000
	.byte	PATT
	 .word	mus_tsuretek_7_000
	.byte	PATT
	 .word	mus_tsuretek_7_000
	.byte	PATT
	 .word	mus_tsuretek_7_000
	.byte	PATT
	 .word	mus_tsuretek_7_001
	.byte	PATT
	 .word	mus_tsuretek_7_002
	.byte	GOTO
	 .word	mus_tsuretek_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_tsuretek_8:
	.byte	KEYSH , mus_tsuretek_key+0
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 32*mus_tsuretek_mvl/mxv
	.byte		N16   , En5 , v112
	.byte	W16
	.byte		N04   , Dn5 
	.byte	W08
	.byte		        Cs5 
	.byte	W16
	.byte		        Dn5 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        En5 
	.byte	W48
mus_tsuretek_8_B1:
	.byte		N04   , An3 , v112
	.byte	W16
	.byte		        Cs4 
	.byte	W08
	.byte		N16   , En4 
	.byte	W24
	.byte		N04   , Dn4 
	.byte	W16
	.byte		        Fs4 
	.byte	W08
	.byte		N16   , An4 
	.byte	W24
	.byte		N04   , An3 
	.byte	W16
	.byte		        Cs4 
	.byte	W08
	.byte		N16   , En4 
	.byte	W24
	.byte		N04   , Dn4 
	.byte	W16
	.byte		        Cs4 
	.byte	W08
	.byte		N16   , Bn3 
	.byte	W24
	.byte		N04   , En3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N12   , En4 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Dn4 
	.byte	W16
	.byte		        Fs4 
	.byte	W08
	.byte		        An4 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Gs4 
	.byte	W16
	.byte		        En4 
	.byte	W08
	.byte		N12   , Fs4 
	.byte	W16
	.byte		N04   , Gs4 
	.byte	W08
	.byte		        An4 
	.byte	W04
	.byte		VOL   , 32*mus_tsuretek_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		N04   
	.byte	W08
	.byte		N16   
	.byte	W24
	.byte	W96
	.byte	W96
	.byte		N04   , Cs5 
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		N16   
	.byte	W24
	.byte		N04   , Fs5 
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		N16   
	.byte	W24
	.byte		N04   , Cs5 
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		N16   
	.byte	W24
	.byte		N04   , Bn4 
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		N16   , Gs4 
	.byte	W24
	.byte		N04   , Cs5 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W16
	.byte		N04   , En4 
	.byte	W08
	.byte		        Fs5 
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		        En5 
	.byte	W08
	.byte		        Dn5 
	.byte	W16
	.byte		        Bn4 
	.byte	W08
	.byte		N12   , An4 
	.byte	W16
	.byte		N04   , Gs4 
	.byte	W08
	.byte		        An4 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N16   
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_tsuretek_8_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_tsuretek:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_tsuretek_pri	@ Priority
	.byte	mus_tsuretek_rev	@ Reverb.

	.word	mus_tsuretek_grp

	.word	mus_tsuretek_1
	.word	mus_tsuretek_2
	.word	mus_tsuretek_3
	.word	mus_tsuretek_4
	.word	mus_tsuretek_5
	.word	mus_tsuretek_6
	.word	mus_tsuretek_7
	.word	mus_tsuretek_8

	.end
