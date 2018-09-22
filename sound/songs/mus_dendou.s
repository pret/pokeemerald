	.include "MPlayDef.s"

	.equ	mus_dendou_grp, voicegroup082
	.equ	mus_dendou_pri, 0
	.equ	mus_dendou_rev, reverb_set+50
	.equ	mus_dendou_mvl, 127
	.equ	mus_dendou_key, 0
	.equ	mus_dendou_tbs, 1
	.equ	mus_dendou_exg, 0
	.equ	mus_dendou_cmp, 1

	.section .rodata
	.global	mus_dendou
	.align	2

@********************** Track  1 **********************@

mus_dendou_1:
	.byte	KEYSH , mus_dendou_key+0
	.byte	TEMPO , 122*mus_dendou_tbs/2
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 30*mus_dendou_mvl/mxv
	.byte	W12
mus_dendou_1_B1:
	.byte	W96
	.byte	W96
mus_dendou_1_000:
	.byte		N02   , Gs5 , v112
	.byte	W08
	.byte		        Gs5 , v084
	.byte	W04
	.byte		        Gs5 , v064
	.byte	W04
	.byte		        Gs5 , v096
	.byte	W08
	.byte		        Gs5 , v112
	.byte	W16
	.byte		        Gs5 , v088
	.byte	W08
	.byte		        Gs5 , v112
	.byte	W08
	.byte		        Gs5 , v080
	.byte	W08
	.byte		        Gs5 , v088
	.byte	W08
	.byte		        Gs5 , v112
	.byte	W16
	.byte		        Gs5 , v084
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_dendou_1_000
	.byte	PATT
	 .word	mus_dendou_1_000
	.byte	PATT
	 .word	mus_dendou_1_000
	.byte	PATT
	 .word	mus_dendou_1_000
	.byte	PATT
	 .word	mus_dendou_1_000
	.byte	PATT
	 .word	mus_dendou_1_000
	.byte	PATT
	 .word	mus_dendou_1_000
	.byte	PATT
	 .word	mus_dendou_1_000
	.byte	PATT
	 .word	mus_dendou_1_000
	.byte	PATT
	 .word	mus_dendou_1_000
	.byte	PATT
	 .word	mus_dendou_1_000
	.byte	PATT
	 .word	mus_dendou_1_000
	.byte	PATT
	 .word	mus_dendou_1_000
	.byte	PATT
	 .word	mus_dendou_1_000
	.byte	PATT
	 .word	mus_dendou_1_000
	.byte	GOTO
	 .word	mus_dendou_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_dendou_2:
	.byte	KEYSH , mus_dendou_key+0
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 49*mus_dendou_mvl/mxv
	.byte	W12
mus_dendou_2_B1:
	.byte		VOICE , 56
	.byte		VOL   , 78*mus_dendou_mvl/mxv
	.byte		N04   , An3 , v116
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		VOL   , 49*mus_dendou_mvl/mxv
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
	.byte	W92
	.byte		VOICE , 14
	.byte	W04
	.byte		VOL   , 57*mus_dendou_mvl/mxv
	.byte		N40   , An4 , v112
	.byte	W48
	.byte		        Fs4 
	.byte	W48
	.byte		        Gn4 
	.byte	W48
	.byte		        En4 
	.byte	W48
	.byte		        Gn4 
	.byte	W48
	.byte		        Dn4 
	.byte	W48
	.byte		N24   , Cn5 
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte	GOTO
	 .word	mus_dendou_2_B1
	.byte		VOL   , 47*mus_dendou_mvl/mxv
	.byte	FINE

@********************** Track  3 **********************@

mus_dendou_3:
	.byte	KEYSH , mus_dendou_key+0
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+14
	.byte		VOL   , 40*mus_dendou_mvl/mxv
	.byte	W12
mus_dendou_3_B1:
	.byte		VOICE , 60
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		N04   , Dn3 , v112
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N72   , En3 
	.byte	W24
	.byte	W48
	.byte		N04   , Fs3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Cn3 
	.byte		N04   , En3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N48   , Cn4 
	.byte	W48
	.byte		N04   , Bn3 
	.byte	W16
	.byte		        Cn4 
	.byte	W08
	.byte		N32   , An3 
	.byte	W32
	.byte		N04   , Fn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N40   , An3 
	.byte	W40
	.byte		N04   , Fs3 
	.byte	W08
	.byte	W48
	.byte		        Fs4 
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		N56   , Gn4 
	.byte	W24
	.byte	W32
	.byte		N04   , Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		N24   , Fs4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		N04   , An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N24   , En4 
	.byte	W24
	.byte		N04   , Cn4 
	.byte	W16
	.byte		        En4 
	.byte	W08
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N04   , En4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_dendou_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_dendou_4:
	.byte	KEYSH , mus_dendou_key+0
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-13
	.byte		VOL   , 72*mus_dendou_mvl/mxv
	.byte		N04   , An2 , v112
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
mus_dendou_4_B1:
	.byte		N12   , En2 , v112
	.byte	W32
	.byte		N04   , An2 
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		N08   , An1 
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		        An1 , v084
	.byte	W08
	.byte		N12   , En2 , v112
	.byte	W16
	.byte		N04   , En2 , v092
	.byte	W16
	.byte		        En2 , v076
	.byte	W08
	.byte		        En2 , v088
	.byte	W08
	.byte		        En2 , v096
	.byte	W08
	.byte		        An2 , v112
	.byte	W04
	.byte		        An2 , v084
	.byte	W04
	.byte		        An2 , v096
	.byte	W08
	.byte		        An2 , v112
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		        An1 , v096
	.byte	W08
	.byte		N08   , Dn2 , v112
	.byte	W16
	.byte		N04   , An1 
	.byte	W08
	.byte		N24   , An2 
	.byte	W56
	.byte		N08   , An3 
	.byte	W08
	.byte		N08   
	.byte	W08
mus_dendou_4_000:
	.byte		N08   , Dn2 , v112
	.byte	W16
	.byte		N04   , An1 
	.byte	W08
	.byte		N24   , An2 
	.byte	W60
	.byte		N04   , An3 , v064
	.byte	W04
	.byte		        An3 , v088
	.byte	W04
	.byte		        An3 , v112
	.byte	W04
	.byte	PEND
mus_dendou_4_001:
	.byte		N24   , An2 , v112
	.byte	W24
	.byte		N04   , Dn2 , v060
	.byte	W08
	.byte		        Dn2 , v076
	.byte	W08
	.byte		        Dn2 , v080
	.byte	W08
	.byte		        Dn2 , v084
	.byte	W08
	.byte		        Dn2 , v088
	.byte	W08
	.byte		        Dn2 , v112
	.byte	W08
	.byte		        Cn3 , v076
	.byte	W08
	.byte		        Cn3 , v068
	.byte	W04
	.byte		        Cn3 , v080
	.byte	W04
	.byte		        Cn3 , v088
	.byte	W04
	.byte		        Cn3 , v112
	.byte	W04
	.byte	PEND
	.byte		N06   , Dn3 
	.byte	W08
	.byte		N04   , Dn2 
	.byte	W16
	.byte		        An3 , v076
	.byte	W08
	.byte		        An3 , v088
	.byte	W08
	.byte		        An3 , v112
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , An2 
	.byte	W16
	.byte		N04   , An2 , v048
	.byte	W04
	.byte		        An2 , v064
	.byte	W04
	.byte		        An2 , v076
	.byte	W04
	.byte		        An2 , v096
	.byte	W04
	.byte		        An2 , v127
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N08   , An2 , v112
	.byte	W16
	.byte		N04   , An1 
	.byte	W08
	.byte		N24   , An2 
	.byte	W56
	.byte		N08   , An3 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte	PATT
	 .word	mus_dendou_4_000
	.byte	PATT
	 .word	mus_dendou_4_001
	.byte		N06   , Dn3 , v112
	.byte	W08
	.byte		N08   , Dn2 
	.byte	W16
	.byte		N04   , An3 , v076
	.byte	W16
	.byte		        An3 , v112
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Dn3 , v076
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        Dn3 , v080
	.byte	W08
	.byte		        Dn3 , v112
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		N16   , Dn2 , v108
	.byte	W40
	.byte		N04   , An1 , v084
	.byte	W08
	.byte		N12   , Dn2 , v112
	.byte	W40
	.byte		N04   , An1 , v080
	.byte	W04
	.byte		N04   
	.byte	W04
mus_dendou_4_002:
	.byte		N12   , Cn2 , v112
	.byte	W56
	.byte		N04   , Cn2 , v108
	.byte	W08
	.byte		        Gn1 , v088
	.byte	W08
	.byte		N08   , Cn2 , v112
	.byte	W16
	.byte		N04   , Gn1 , v080
	.byte	W08
	.byte	PEND
mus_dendou_4_003:
	.byte		N12   , Bn1 , v112
	.byte	W64
	.byte		N04   , Fs1 , v084
	.byte	W04
	.byte		        Fs1 , v092
	.byte	W04
	.byte		N08   , Bn1 , v112
	.byte	W16
	.byte		N04   , Bn1 , v096
	.byte	W08
	.byte	PEND
	.byte	W08
	.byte		        Fn2 , v084
	.byte	W08
	.byte		        Fn2 , v072
	.byte	W08
	.byte		N12   , As1 , v112
	.byte	W16
	.byte		N04   , As1 , v080
	.byte	W16
	.byte		        Gn2 , v084
	.byte	W08
	.byte		        Gn2 , v092
	.byte	W08
	.byte		        An2 , v112
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		        An2 , v092
	.byte	W04
	.byte		N08   , Dn2 
	.byte	W08
	.byte		N16   , An2 , v108
	.byte	W40
	.byte		N04   , An1 , v084
	.byte	W08
	.byte		N12   , Dn2 , v112
	.byte	W40
	.byte		N04   , An1 , v080
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte	PATT
	 .word	mus_dendou_4_002
	.byte	PATT
	 .word	mus_dendou_4_003
	.byte	W08
	.byte		N04   , Fn2 , v084
	.byte	W08
	.byte		        Fn2 , v072
	.byte	W08
	.byte		N12   , As1 , v112
	.byte	W16
	.byte		N04   , As1 , v080
	.byte	W16
	.byte		        Gn2 , v084
	.byte	W08
	.byte		        Gn2 , v092
	.byte	W08
	.byte		        Gn2 , v112
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		        Gn2 , v092
	.byte	W04
	.byte		        Cn2 
	.byte	W04
	.byte		        Cn2 , v112
	.byte	W04
	.byte	GOTO
	 .word	mus_dendou_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_dendou_5:
	.byte	KEYSH , mus_dendou_key+0
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 60*mus_dendou_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W12
mus_dendou_5_B1:
	.byte		VOICE , 48
	.byte		N08   , An4 , v112
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        An4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		N08   , Bn4 
	.byte	W08
	.byte		N04   , An4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		N08   , Cn5 
	.byte	W08
	.byte		N04   , An4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        An4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		N08   , Cs5 
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		        Cs5 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        En5 
	.byte	W06
	.byte		N02   , Ds4 , v096
	.byte	W02
	.byte		VOL   , 63*mus_dendou_mvl/mxv
	.byte		N08   , Dn4 , v112
	.byte	W08
	.byte		N04   , An3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N48   , En4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W04
	.byte		VOL   , 54*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        49*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        40*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        28*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        20*mus_dendou_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 63*mus_dendou_mvl/mxv
	.byte	W24
	.byte		N08   , Dn4 
	.byte	W08
	.byte		N04   , An3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N48   , En4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W04
	.byte		VOL   , 54*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        49*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        40*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        28*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        20*mus_dendou_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 63*mus_dendou_mvl/mxv
	.byte		N04   , Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N04   , Gn3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N48   , Dn4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W04
	.byte		VOL   , 54*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        49*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        40*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        28*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        20*mus_dendou_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 63*mus_dendou_mvl/mxv
	.byte	W22
	.byte		N02   , Cs4 , v096
	.byte	W02
	.byte		N04   , Cn4 , v112
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N48   , Fn4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W04
	.byte		VOL   , 54*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        49*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        40*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        28*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        20*mus_dendou_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 63*mus_dendou_mvl/mxv
	.byte		N04   , En4 
	.byte	W16
	.byte		VOICE , 56
	.byte		N04   , Cn4 
	.byte	W04
	.byte		VOL   , 76*mus_dendou_mvl/mxv
	.byte	W02
	.byte		N02   , Ds5 , v096
	.byte	W02
	.byte		N04   , Dn5 , v112
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		N48   , En5 
	.byte	W24
	.byte		MOD   , 7
	.byte	W04
	.byte		VOL   , 68*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        62*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        49*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        35*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        24*mus_dendou_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 78*mus_dendou_mvl/mxv
	.byte	W24
	.byte		N08   , Dn5 
	.byte	W08
	.byte		N04   , An4 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		N48   , En5 
	.byte	W24
	.byte		MOD   , 7
	.byte	W04
	.byte		VOL   , 68*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        62*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        49*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        35*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        24*mus_dendou_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 78*mus_dendou_mvl/mxv
	.byte		N04   , Gn5 
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		N08   , Cn5 
	.byte	W08
	.byte		N04   , Gn4 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		N48   , Dn5 
	.byte	W24
	.byte		MOD   , 7
	.byte	W04
	.byte		VOL   , 68*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        62*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        49*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        35*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        24*mus_dendou_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 78*mus_dendou_mvl/mxv
	.byte	W24
	.byte		N04   , Cn5 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        En5 
	.byte	W04
	.byte		VOICE , 24
	.byte	W04
	.byte		VOL   , 68*mus_dendou_mvl/mxv
	.byte		N04   , Fs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		N48   , Dn5 
	.byte	W24
	.byte		MOD   , 7
	.byte	W04
	.byte		VOL   , 68*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        62*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        49*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        35*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        24*mus_dendou_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 69*mus_dendou_mvl/mxv
	.byte		N16   , Fs4 
	.byte	W16
	.byte		N04   , Gn4 
	.byte	W08
	.byte		N32   , An4 
	.byte	W32
	.byte		N04   , Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		N32   , Bn4 
	.byte	W32
	.byte		N04   , An4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		N24   , Dn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		N04   , Fn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
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
	.byte		        Cn3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		VOICE , 48
	.byte		VOL   , 54*mus_dendou_mvl/mxv
	.byte		N04   , Fs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		N08   , Dn5 
	.byte	W08
	.byte		N04   , En5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		N24   , An4 
	.byte	W24
	.byte		N04   , Fs4 
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		N32   
	.byte	W32
	.byte		N04   , Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N02   , Gs4 , v088
	.byte	W02
	.byte		N22   , Gn4 , v112
	.byte	W22
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N04   , Bn4 
	.byte	W16
	.byte		        Cs5 
	.byte	W08
	.byte		N48   , Dn5 
	.byte	W24
	.byte		MOD   , 7
	.byte	W04
	.byte		VOL   , 47*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        44*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        37*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        28*mus_dendou_mvl/mxv
	.byte	W04
	.byte		        24*mus_dendou_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 54*mus_dendou_mvl/mxv
	.byte		N08   , En5 
	.byte	W24
	.byte		N04   , Fn5 
	.byte	W08
	.byte		        An5 
	.byte	W08
	.byte		        Gn5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Fn5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        An5 
	.byte	W08
	.byte	GOTO
	 .word	mus_dendou_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_dendou_6:
	.byte	KEYSH , mus_dendou_key+0
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-61
	.byte		VOL   , 33*mus_dendou_mvl/mxv
	.byte	W12
mus_dendou_6_B1:
	.byte		VOICE , 80
	.byte		N08   , An3 , v112
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        An3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N08   , Bn3 
	.byte	W08
	.byte		N04   , An3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N04   , An3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        An3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N08   , Cs4 
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Cs4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        An2 , v044
	.byte	W08
	.byte		N02   , Dn3 , v112
	.byte	W04
	.byte		N04   , Cs3 
	.byte	W04
	.byte		N02   , Dn3 
	.byte	W08
	.byte		N02   
	.byte	W24
	.byte		N06   , Fs3 
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N04   , An2 , v052
	.byte	W08
	.byte		N02   , Dn3 , v112
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N06   , Fs3 
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N06   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N04   , An2 , v044
	.byte	W08
	.byte		N02   , Dn3 , v112
	.byte	W04
	.byte		N04   , Cs3 
	.byte	W04
	.byte		N02   , Dn3 
	.byte	W08
	.byte		N02   
	.byte	W24
	.byte		N06   , Fs3 
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N06   , Fn3 
	.byte	W08
	.byte		N02   , Fs3 
	.byte	W08
	.byte		N04   , Fn2 , v052
	.byte	W08
	.byte		N02   , Cn3 , v112
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N06   , Fn3 
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N06   , En3 
	.byte	W08
	.byte		N02   , Fn3 
	.byte	W08
	.byte	W48
	.byte		N04   , Dn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		N08   , An3 
	.byte	W08
	.byte		N04   , Bn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N24   , Fs3 
	.byte	W32
	.byte		N04   , En3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		        Fs3 
	.byte	W08
	.byte		N56   , An3 
	.byte	W24
	.byte	W32
	.byte		N08   , Gn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		N48   , En3 
	.byte	W48
	.byte		N04   , Dn3 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
mus_dendou_6_000:
	.byte		N04   , Dn6 , v112
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		        Cs6 
	.byte	W04
	.byte		        Dn6 
	.byte	W04
	.byte		PAN   , c_v+63
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		        Cs6 
	.byte	W04
	.byte		        Dn6 
	.byte	W04
	.byte		PAN   , c_v-61
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_dendou_6_000
	.byte	PATT
	 .word	mus_dendou_6_000
	.byte	PATT
	 .word	mus_dendou_6_000
	.byte		N04   , An5 , v112
	.byte	W08
	.byte		        Gn5 
	.byte	W08
	.byte		        Fs5 
	.byte	W04
	.byte		PAN   , c_v+63
	.byte	W04
	.byte		N04   , Gn5 
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        Dn5 
	.byte	W04
	.byte		PAN   , c_v-61
	.byte	W04
	.byte		N04   , En5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        An5 
	.byte	W08
	.byte		        Gn5 
	.byte	W08
	.byte		        Fs5 
	.byte	W04
	.byte		PAN   , c_v+63
	.byte	W04
	.byte		N04   , Gn5 
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        Dn5 
	.byte	W04
	.byte		PAN   , c_v-61
	.byte	W04
	.byte		N04   , En5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Bn5 
	.byte	W08
	.byte		        An5 
	.byte	W08
	.byte		        Gn5 
	.byte	W04
	.byte		PAN   , c_v+63
	.byte	W04
	.byte		N04   , An5 
	.byte	W08
	.byte		        Gn5 
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		        Gn5 
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		        En5 
	.byte	W04
	.byte		PAN   , c_v-61
	.byte	W04
	.byte		N04   , Bn4 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Bn5 
	.byte	W08
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
	.byte		PAN   , c_v+63
	.byte		N04   , Cn5 
	.byte	W04
	.byte		        Fn5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		PAN   , c_v-61
	.byte		N04   , En5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte	GOTO
	 .word	mus_dendou_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_dendou_7:
	.byte	KEYSH , mus_dendou_key+0
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 33*mus_dendou_mvl/mxv
	.byte	W12
mus_dendou_7_B1:
	.byte		VOICE , 81
	.byte		VOL   , 36*mus_dendou_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		N08   , En4 , v112
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        En4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        En4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , An4 
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        An4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fs3 , v044
	.byte	W08
	.byte		N02   , An3 , v112
	.byte	W04
	.byte		N04   , Gs3 
	.byte	W04
	.byte		N02   , An3 
	.byte	W08
	.byte		N02   
	.byte	W24
	.byte		N06   , Dn4 
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N04   , Fs3 , v052
	.byte	W08
	.byte		N02   , An3 , v112
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N06   , Dn4 
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N06   , Cs4 
	.byte	W08
	.byte		N02   , Dn4 
	.byte	W08
	.byte		N04   , Fs3 , v044
	.byte	W08
	.byte		N02   , An3 , v112
	.byte	W04
	.byte		N04   , Gs3 
	.byte	W04
	.byte		N02   , An3 
	.byte	W08
	.byte		N02   
	.byte	W24
	.byte		N06   , Dn4 
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N06   , Cs4 
	.byte	W08
	.byte		N02   , Dn4 
	.byte	W08
	.byte		N04   , Cn3 , v052
	.byte	W08
	.byte		N02   , Fn3 , v112
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N06   , Cn4 
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N06   , Bn3 
	.byte	W08
	.byte		N02   , Cn4 
	.byte	W08
	.byte	W48
	.byte		N04   , Fs3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N08   , Dn4 
	.byte	W08
	.byte		N04   , En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N24   , An3 
	.byte	W32
	.byte		N04   , Gn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        An3 
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte		N56   , Fs4 
	.byte	W24
	.byte	W32
	.byte		N08   , En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N48   , Cn4 
	.byte	W48
	.byte		N04   , An3 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        En4 
	.byte	W04
	.byte		PAN   , c_v+0
	.byte	W04
	.byte		VOL   , 50*mus_dendou_mvl/mxv
	.byte		N16   , Dn2 
	.byte	W24
	.byte		        Dn2 , v088
	.byte	W16
	.byte		N04   , An1 , v112
	.byte	W08
	.byte		        Dn2 , v096
	.byte	W08
	.byte		N12   , Dn2 , v112
	.byte	W16
	.byte		N16   , Dn2 , v084
	.byte	W16
	.byte		N04   , An1 , v112
	.byte	W08
mus_dendou_7_000:
	.byte		N16   , Cn2 , v112
	.byte	W24
	.byte		N08   , Cn2 , v088
	.byte	W16
	.byte		N04   , Gn1 , v112
	.byte	W16
	.byte		        Cn2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , Cn2 , v084
	.byte	W16
	.byte		N04   , Gn1 , v112
	.byte	W08
	.byte	PEND
mus_dendou_7_001:
	.byte		N16   , Bn1 , v112
	.byte	W24
	.byte		N08   , Bn1 , v088
	.byte	W16
	.byte		N04   , Fs1 , v112
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		N12   
	.byte	W16
	.byte		N08   , Bn1 , v084
	.byte	W16
	.byte		N04   , Fs1 , v112
	.byte	W08
	.byte	PEND
mus_dendou_7_002:
	.byte	W08
	.byte		N04   , As1 , v112
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W16
	.byte		N04   , Fn1 
	.byte	W16
	.byte		        Cn2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W16
	.byte		N04   , Gn1 
	.byte	W08
	.byte	PEND
	.byte		N16   , Dn2 
	.byte	W24
	.byte		        Dn2 , v088
	.byte	W16
	.byte		N04   , An1 , v112
	.byte	W08
	.byte		        Dn2 , v096
	.byte	W08
	.byte		N12   , Dn2 , v112
	.byte	W16
	.byte		N16   , Dn2 , v084
	.byte	W16
	.byte		N04   , An1 , v112
	.byte	W08
	.byte	PATT
	 .word	mus_dendou_7_000
	.byte	PATT
	 .word	mus_dendou_7_001
	.byte	PATT
	 .word	mus_dendou_7_002
	.byte	GOTO
	 .word	mus_dendou_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_dendou_8:
	.byte	KEYSH , mus_dendou_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 44*mus_dendou_mvl/mxv
	.byte	W12
mus_dendou_8_B1:
	.byte		N48   , An2 , v112
	.byte	W48
	.byte		        An2 , v092
	.byte	W48
	.byte		N24   , An2 , v088
	.byte	W24
	.byte		        An2 , v120
	.byte	W72
	.byte		N48   , An2 , v112
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N48   
	.byte	W96
	.byte		N48   
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N48   
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_dendou_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_dendou_9:
	.byte	KEYSH , mus_dendou_key+0
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 50*mus_dendou_mvl/mxv
	.byte	W12
mus_dendou_9_B1:
	.byte		VOICE , 82
	.byte		VOL   , 67*mus_dendou_mvl/mxv
	.byte		N12   , An1 , v112
	.byte	W32
	.byte		N04   , An1 , v088
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , An1 , v112
	.byte	W32
	.byte		N04   , An1 , v080
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , An1 , v112
	.byte	W16
	.byte		N04   , An1 , v096
	.byte	W16
	.byte		        An1 , v112
	.byte	W08
	.byte		        An1 , v084
	.byte	W08
	.byte		        An1 , v092
	.byte	W08
	.byte		N12   , An1 , v096
	.byte	W16
	.byte		        An1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
mus_dendou_9_000:
	.byte		N06   , Dn2 , v112
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N04   , Cs2 
	.byte	W04
	.byte		N02   , Dn2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		N02   , Dn2 
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte	PEND
mus_dendou_9_001:
	.byte		N06   , Dn2 , v112
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N04   , Cs2 
	.byte	W04
	.byte		N02   , Dn2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        An1 
	.byte	W16
	.byte		        An2 
	.byte	W08
	.byte		N02   , Dn2 
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte	PEND
	.byte		N06   
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N04   , Cs2 
	.byte	W04
	.byte		N02   , Dn2 
	.byte	W08
	.byte		N32   , Dn3 , v092
	.byte	W32
	.byte		N04   , Dn2 , v112
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		        An2 
	.byte	W16
	.byte		        Dn2 
	.byte	W08
	.byte		N06   
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N04   , Cs2 
	.byte	W04
	.byte		N02   , Dn2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte	PATT
	 .word	mus_dendou_9_000
	.byte	PATT
	 .word	mus_dendou_9_001
	.byte		N06   , Dn2 , v112
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N04   , Cs2 
	.byte	W04
	.byte		N02   , Dn2 
	.byte	W08
	.byte		N32   , Dn3 , v080
	.byte	W32
	.byte		N04   , Dn2 , v112
	.byte	W08
	.byte		        An1 
	.byte	W32
	.byte		N06   , Dn2 
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N04   , Cs2 
	.byte	W04
	.byte		N02   , Dn2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        An1 
	.byte	W32
	.byte		VOICE , 83
	.byte		VOL   , 40*mus_dendou_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N04   , Fs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		N48   , Dn5 
	.byte	W48
	.byte		N16   , Fs4 
	.byte	W16
	.byte		N04   , Gn4 
	.byte	W08
	.byte		N32   , An4 
	.byte	W32
	.byte		N04   , Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		N32   , Bn4 
	.byte	W32
	.byte		N04   , An4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		N24   , Dn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		N04   , Fn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Gn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Gn3 
	.byte	W16
	.byte		N04   
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		        Fs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		N08   , Dn5 
	.byte	W08
	.byte		N04   , En5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		N24   , An4 
	.byte	W24
	.byte		N04   , Fs4 
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		N32   
	.byte	W32
	.byte		N04   , Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N02   , Gs4 , v088
	.byte	W02
	.byte		N22   , Gn4 , v112
	.byte	W22
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N04   , Bn4 
	.byte	W16
	.byte		        Cs5 
	.byte	W08
	.byte		N48   , Dn5 
	.byte	W48
	.byte		N08   , En5 
	.byte	W24
	.byte		N04   , Fn5 
	.byte	W08
	.byte		        An5 
	.byte	W08
	.byte		        Gn5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Fn5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        An5 
	.byte	W08
	.byte	GOTO
	 .word	mus_dendou_9_B1
	.byte		BEND  , c_v+0
	.byte	FINE

@********************** Track 10 **********************@

mus_dendou_10:
	.byte	KEYSH , mus_dendou_key+0
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+13
	.byte		VOL   , 54*mus_dendou_mvl/mxv
	.byte	W12
mus_dendou_10_B1:
	.byte		VOICE , 48
	.byte	W96
	.byte	W96
mus_dendou_10_000:
	.byte		N08   , Fs3 , v112
	.byte	W08
	.byte		N04   , Dn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		N48   , An3 
	.byte	W72
	.byte	PEND
	.byte	PATT
	 .word	mus_dendou_10_000
	.byte		N08   , En3 , v112
	.byte	W08
	.byte		N04   , Cn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		N48   , Gn3 
	.byte	W72
	.byte	W92
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        Fs4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N48   , An4 
	.byte	W72
	.byte		N08   , Fs4 
	.byte	W08
	.byte		N04   , Dn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N48   , An4 
	.byte	W48
	.byte		N04   , Dn5 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		N08   , En4 
	.byte	W08
	.byte		N04   , Cn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		N48   , Gn4 
	.byte	W72
	.byte	W92
	.byte		VOICE , 56
	.byte		VOL   , 38*mus_dendou_mvl/mxv
	.byte	W04
	.byte	W48
	.byte		N04   , An3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N32   , Gn4 
	.byte	W32
	.byte		N04   , Dn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N24   , Dn4 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		N32   , Dn4 
	.byte	W32
	.byte		N04   , En4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		N24   , Gn3 
	.byte	W24
	.byte		        An3 
	.byte	W20
	.byte		VOICE , 24
	.byte	W04
	.byte		N04   , As3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Cn4 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Cn3 
	.byte	W08
	.byte		        Gn2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		VOICE , 56
	.byte	W04
	.byte		N04   , Fs4 
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Fs4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Fs4 
	.byte	W08
	.byte		N40   
	.byte	W40
	.byte		N04   , En4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		N48   , Dn4 
	.byte	W48
	.byte		N04   , Gn4 
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Gn4 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N04   , En4 
	.byte	W08
	.byte		N08   , Fn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte	GOTO
	 .word	mus_dendou_10_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_dendou:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_dendou_pri	@ Priority
	.byte	mus_dendou_rev	@ Reverb.

	.word	mus_dendou_grp

	.word	mus_dendou_1
	.word	mus_dendou_2
	.word	mus_dendou_3
	.word	mus_dendou_4
	.word	mus_dendou_5
	.word	mus_dendou_6
	.word	mus_dendou_7
	.word	mus_dendou_8
	.word	mus_dendou_9
	.word	mus_dendou_10

	.end
