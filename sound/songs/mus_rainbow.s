	.include "MPlayDef.s"

	.equ	mus_rainbow_grp, voicegroup068
	.equ	mus_rainbow_pri, 0
	.equ	mus_rainbow_rev, reverb_set+50
	.equ	mus_rainbow_mvl, 127
	.equ	mus_rainbow_key, 0
	.equ	mus_rainbow_tbs, 1
	.equ	mus_rainbow_exg, 0
	.equ	mus_rainbow_cmp, 1

	.section .rodata
	.global	mus_rainbow
	.align	2

@********************** Track  1 **********************@

mus_rainbow_1:
	.byte	KEYSH , mus_rainbow_key+0
	.byte	TEMPO , 128*mus_rainbow_tbs/2
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		PAN   , c_v+30
	.byte		VOL   , 59*mus_rainbow_mvl/mxv
	.byte		N04   , Gn2 , v112
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		N08   , Gn3 
	.byte	W08
	.byte		N04   , As3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		N08   , Gn3 
	.byte	W08
	.byte		N04   , As3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N08   , Cn3 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N08   , Cn3 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N08   , Cn3 
	.byte	W08
	.byte		N04   , An2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N40   , Ds3 
	.byte	W40
	.byte		N08   , En3 
	.byte	W08
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
mus_rainbow_1_B1:
	.byte		N20   , As2 , v112
	.byte	W24
	.byte		N24   , Fn2 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		N16   , As2 
	.byte	W16
	.byte		N32   , Cn3 
	.byte	W08
	.byte	W24
	.byte		N24   , An2 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		N16   , Cn3 
	.byte	W16
	.byte		N08   , Cs3 
	.byte	W08
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N04   , En3 , v080
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		N24   , Dn3 , v112
	.byte	W24
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N04   , Cn3 
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N04   , Bn2 
	.byte	W08
	.byte		N16   , Cn3 
	.byte	W16
	.byte		N04   , Gn2 
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N04   , Bn2 
	.byte	W08
	.byte		N24   , Ds3 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		N04   , As2 
	.byte	W16
	.byte		N08   , Dn3 
	.byte	W08
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		N16   , As2 
	.byte	W16
	.byte		N20   , En3 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N32   , Fn3 
	.byte	W32
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N72   , As2 
	.byte	W80
	.byte		N04   , Dn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		N40   , Cn3 
	.byte	W40
	.byte		N04   , Fn2 
	.byte	W08
	.byte		N24   
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		N72   , Dn3 
	.byte	W72
	.byte		N04   , As2 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N40   , Bn2 
	.byte	W40
	.byte		N04   , Gn2 
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N04   , Fn2 
	.byte	W08
	.byte		N16   , Ds2 
	.byte	W16
	.byte		N04   , Dn2 
	.byte	W08
	.byte		N48   , Ds2 
	.byte	W48
	.byte		N24   , Fs2 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		N04   , Fn3 
	.byte	W16
	.byte		N24   , As2 
	.byte	W24
	.byte		N04   , Cn3 
	.byte	W08
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N40   , En3 
	.byte	W40
	.byte		N04   , Cn3 
	.byte	W08
	.byte		N20   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N04   , Cn3 
	.byte	W08
	.byte		        Ds3 
	.byte	W16
	.byte		N32   , Fn2 
	.byte	W32
	.byte		N04   , Cn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		N64   , As3 
	.byte	W64
	.byte		N04   , Gs3 
	.byte	W24
	.byte		        Fs3 
	.byte	W08
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N04   , As3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		N24   , Fs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N24   , Cn3 
	.byte	W24
	.byte		N56   , Cn4 
	.byte	W56
	.byte		N08   , Gs4 
	.byte	W08
	.byte		N04   , As4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		N08   , Fs4 
	.byte	W08
	.byte		N04   , Gs4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		N08   , Fn4 
	.byte	W08
	.byte		N04   , Fs4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N08   , Gs3 
	.byte	W08
	.byte		N04   , As3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N64   , As3 
	.byte	W64
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		N16   , An3 
	.byte	W16
	.byte		N04   , Gs3 
	.byte	W08
	.byte		N16   , An3 
	.byte	W16
	.byte		N04   , Cs4 
	.byte	W08
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		N48   , Gs3 
	.byte	W48
	.byte		N24   , Cn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		N32   , As3 
	.byte	W32
	.byte		N04   , Bn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		N16   , Fs3 
	.byte	W16
	.byte		N24   , As3 
	.byte	W24
	.byte		N04   , Fs3 
	.byte	W08
	.byte		N16   , An3 
	.byte	W16
	.byte		N04   , Bn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W24
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N08   , Ds3 
	.byte	W08
	.byte		N32   , Cn4 
	.byte	W32
	.byte		N04   , Cs4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N04   , Bn3 
	.byte	W08
	.byte		N16   , As3 
	.byte	W16
	.byte		N04   , Cn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		N16   , As3 
	.byte	W16
	.byte		N04   , Gs3 
	.byte	W24
	.byte		N56   , Fs3 
	.byte	W56
	.byte		N16   , An3 
	.byte	W16
	.byte		N04   , Gs3 
	.byte	W24
	.byte		N08   , Fs3 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N12   , An3 
	.byte	W12
	.byte		N04   , As3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		N48   , Cs4 
	.byte	W48
	.byte		        Cn4 
	.byte	W48
	.byte		        As3 
	.byte	W48
	.byte		        Cn4 
	.byte	W48
	.byte	GOTO
	 .word	mus_rainbow_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_rainbow_2:
	.byte	KEYSH , mus_rainbow_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 81*mus_rainbow_mvl/mxv
	.byte		N04   , Fn3 , v112
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		TIE   , Dn4 
	.byte	W96
	.byte	W40
	.byte		EOT   
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N08   , As3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		N48   , An3 
	.byte	W48
	.byte		        As3 
	.byte	W48
	.byte		        Bn3 
	.byte	W48
	.byte		        Cn4 
	.byte	W48
mus_rainbow_2_B1:
mus_rainbow_2_000:
	.byte		N16   , Dn4 , v112
	.byte	W16
	.byte		N04   , Ds4 
	.byte	W08
	.byte		        Fn4 
	.byte	W16
	.byte		N24   
	.byte	W24
	.byte		N04   , Ds4 
	.byte	W08
	.byte		        Dn4 
	.byte	W16
	.byte		TIE   , Cn4 
	.byte	W08
	.byte	PEND
	.byte	W96
	.byte		EOT   
mus_rainbow_2_001:
	.byte		N16   , Dn4 , v112
	.byte	W16
	.byte		N04   , Ds4 
	.byte	W08
	.byte		        Fn4 
	.byte	W16
	.byte		N24   , As4 
	.byte	W24
	.byte		N04   , Fn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte	PEND
mus_rainbow_2_002:
	.byte		N16   , Cn4 , v112
	.byte	W16
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		N24   , Bn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte	PEND
mus_rainbow_2_003:
	.byte		N48   , As3 , v112
	.byte	W48
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte	PEND
	.byte		        Dn4 
	.byte	W24
	.byte		N04   , Fn4 
	.byte	W16
	.byte		N24   , As3 
	.byte	W24
	.byte		N04   , An3 
	.byte	W08
	.byte		N16   , As3 
	.byte	W16
	.byte		N04   , Bn3 
	.byte	W08
	.byte		N64   , Cn4 
	.byte	W64
	.byte		N20   , As3 
	.byte	W32
	.byte		N16   
	.byte	W16
	.byte		N04   , An3 
	.byte	W08
	.byte		        As3 
	.byte	W16
	.byte		N56   , Cn4 
	.byte	W56
	.byte	PATT
	 .word	mus_rainbow_2_000
	.byte	W96
	.byte		EOT   , Cn4 
	.byte	PATT
	 .word	mus_rainbow_2_001
	.byte	PATT
	 .word	mus_rainbow_2_002
	.byte	PATT
	 .word	mus_rainbow_2_003
	.byte		N24   , Dn4 , v112
	.byte	W24
	.byte		N04   , Fn4 
	.byte	W16
	.byte		N24   , As4 
	.byte	W24
	.byte		N04   , Gn4 
	.byte	W08
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N04   , Dn4 
	.byte	W08
	.byte		N64   , As3 
	.byte	W64
	.byte		N20   , Cn4 
	.byte	W32
	.byte		N16   , As3 
	.byte	W16
	.byte		N04   , Gs3 
	.byte	W08
	.byte		        Fs3 
	.byte	W16
	.byte		N32   , Fn3 
	.byte	W32
	.byte		N04   , Gn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		N64   , Fn4 
	.byte	W64
	.byte		N04   , Ds4 
	.byte	W24
	.byte		        Cs4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N04   , Fn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N04   , Gs3 
	.byte	W24
	.byte		N56   , Gs4 
	.byte	W56
	.byte	W72
	.byte		N04   , Gs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N64   , Fn4 
	.byte	W64
	.byte		N04   , Fs4 
	.byte	W24
	.byte		        Fn4 
	.byte	W08
	.byte		N24   , Fs4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N16   , Fs4 
	.byte	W16
	.byte		N04   , Fn4 
	.byte	W08
	.byte		N16   , Fs4 
	.byte	W16
	.byte		N04   , Gs4 
	.byte	W08
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N04   , Ds4 
	.byte	W24
	.byte		        Cs4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		N48   , Fn4 
	.byte	W48
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		N64   , Fn4 
	.byte	W64
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N04   , Cs4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N04   , Fn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Cs4 
	.byte	W24
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		N60   , Gs4 
	.byte	W64
	.byte		N04   , Fs4 
	.byte	W24
	.byte		        Fn4 
	.byte	W08
	.byte		N16   , Fs4 
	.byte	W16
	.byte		N04   , Gs4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		N24   , Fn4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		N72   , As4 
	.byte	W72
	.byte		N04   , Fs4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N04   , Ds4 
	.byte	W24
	.byte		N08   , Cs4 
	.byte	W24
	.byte		N04   , Cn4 
	.byte	W08
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N04   , Ds4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		TIE   , Gs4 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte	GOTO
	 .word	mus_rainbow_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_rainbow_3:
	.byte	KEYSH , mus_rainbow_key+0
	.byte		VOICE , 35
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 86*mus_rainbow_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W24
	.byte		N04   , Cn1 , v096
	.byte	W16
	.byte		        Cn1 , v088
	.byte	W08
	.byte		        Cn2 , v112
	.byte	W16
	.byte		        Cn1 , v084
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W16
	.byte		        Cn1 , v088
	.byte	W08
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		        Cn2 , v084
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W16
	.byte		        Cn1 , v088
	.byte	W08
	.byte		        Cn2 , v112
	.byte	W16
	.byte		        Cn1 , v084
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W16
	.byte		        Cn1 , v088
	.byte	W08
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        Dn1 
	.byte	W08
	.byte		        En1 , v084
	.byte	W08
	.byte		        Fn1 , v096
	.byte	W08
	.byte		        Fn2 , v112
	.byte	W08
	.byte		        Fn1 , v088
	.byte	W08
	.byte		N16   , Fn2 , v112
	.byte	W16
	.byte		N04   , Fn1 , v084
	.byte	W08
	.byte		N12   , Fn1 , v096
	.byte	W16
	.byte		N04   , Fn1 , v088
	.byte	W08
	.byte		        Fn1 , v112
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		        Fn2 , v084
	.byte	W08
	.byte		        Fn1 , v096
	.byte	W08
	.byte		        Fn2 , v112
	.byte	W08
	.byte		        Fn1 , v088
	.byte	W08
	.byte		N16   , Fn2 , v112
	.byte	W16
	.byte		N04   , Fn1 , v084
	.byte	W08
	.byte		        Fn1 , v096
	.byte	W16
	.byte		        Fn1 , v088
	.byte	W08
	.byte		        Fn1 , v112
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		        An1 , v084
	.byte	W08
mus_rainbow_3_B1:
	.byte		N04   , As1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
mus_rainbow_3_000:
	.byte		N04   , An1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte	PEND
mus_rainbow_3_001:
	.byte		N04   , Gs1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte	PEND
mus_rainbow_3_002:
	.byte		N04   , Gn1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte	PEND
mus_rainbow_3_003:
	.byte		N04   , Fs1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte	PEND
mus_rainbow_3_004:
	.byte		N04   , Fn1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte	PEND
mus_rainbow_3_005:
	.byte		N04   , En1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte	PEND
	.byte		        Ds1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        Ds1 
	.byte	W08
	.byte		        Fn1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		        As1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte	PATT
	 .word	mus_rainbow_3_000
	.byte	PATT
	 .word	mus_rainbow_3_001
	.byte	PATT
	 .word	mus_rainbow_3_002
	.byte		N04   , Fs1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte	PATT
	 .word	mus_rainbow_3_004
	.byte	PATT
	 .word	mus_rainbow_3_005
	.byte		N04   , Ds1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		        Fn1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte	PATT
	 .word	mus_rainbow_3_003
	.byte		N04   , Fs1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte	PATT
	 .word	mus_rainbow_3_004
	.byte		N04   , Fn1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		        Ds1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        Ds1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        Ds1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Dn1 
	.byte	W08
	.byte		        Cs1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        As0 
	.byte	W08
	.byte		        Gs0 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Gs0 
	.byte	W08
	.byte		N12   , Gs1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Bn0 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Bn0 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Fs1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        Bn1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Fn1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        As1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Gs1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Fs1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Fn1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Ds1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        Ds1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Bn1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Fs1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		        Gs1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        Gs1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Gs0 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Gs0 
	.byte	W08
	.byte		N12   , Gs1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Gs0 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Gs0 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte	GOTO
	 .word	mus_rainbow_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_rainbow_4:
	.byte	KEYSH , mus_rainbow_key+0
	.byte		VOICE , 14
	.byte		LFOS  , 44
	.byte		PAN   , c_v-20
	.byte		VOL   , 68*mus_rainbow_mvl/mxv
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rainbow_4_B1:
	.byte		VOL   , 68*mus_rainbow_mvl/mxv
	.byte	W96
	.byte	W24
	.byte		N24   , Fn3 , v112
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N48   , Dn4 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N16   , Cn4 
	.byte	W16
	.byte		N24   , Gn4 , v108
	.byte	W24
	.byte		N06   , Cn4 , v080
	.byte	W08
	.byte		N24   , Ds4 , v104
	.byte	W24
	.byte		        As3 , v112
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		N96   , As4 
	.byte	W24
	.byte		VOL   , 67*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        67*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        65*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        64*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        62*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        60*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        60*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        57*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        56*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        54*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        51*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        50*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        48*mus_rainbow_mvl/mxv
	.byte	W04
	.byte		        43*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        42*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        41*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        39*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        37*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        35*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        34*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        32*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        29*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        29*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        27*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        25*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        23*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        20*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        19*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        16*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        12*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        10*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        6*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        6*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        3*mus_rainbow_mvl/mxv
	.byte	W04
	.byte		VOICE , 56
	.byte	W24
	.byte		VOL   , 68*mus_rainbow_mvl/mxv
	.byte		N08   , An3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N04   , En4 , v080
	.byte	W04
	.byte		        Ds4 , v076
	.byte	W04
	.byte		N96   , Dn4 , v112
	.byte	W24
	.byte		VOL   , 67*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        64*mus_rainbow_mvl/mxv
	.byte	W04
	.byte		        63*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        60*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        60*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        57*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        56*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        53*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        51*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        48*mus_rainbow_mvl/mxv
	.byte	W04
	.byte		        43*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        41*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        38*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        35*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        35*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        32*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        31*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        29*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        26*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        24*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        20*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        19*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        16*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        14*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        12*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        10*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        9*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        8*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        6*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        6*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        3*mus_rainbow_mvl/mxv
	.byte	W05
	.byte		        2*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        68*mus_rainbow_mvl/mxv
	.byte		N24   , Ds4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		N48   , Ds4 
	.byte	W72
	.byte		N04   , Cn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N04   , Cn4 
	.byte	W16
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N04   , Fn4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N04   , As3 
	.byte	W08
	.byte	W24
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N16   , Cn4 
	.byte	W16
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N08   , Cn4 , v088
	.byte	W08
	.byte		N16   , Fs4 , v112
	.byte	W16
	.byte		N04   , Fn4 , v064
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		N24   , Ds4 , v112
	.byte	W24
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N04   , Ds4 , v072
	.byte	W04
	.byte		        Dn4 , v064
	.byte	W04
	.byte		N24   , Cn4 , v112
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 14
	.byte		N24   , Gs4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		        Gs3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
mus_rainbow_4_000:
	.byte		N48   , Fn4 , v112
	.byte	W48
	.byte		        Cs4 
	.byte	W48
	.byte	PEND
	.byte		        Ds4 
	.byte	W48
	.byte		N44   , Cn4 
	.byte	W48
	.byte		N48   , Gs4 
	.byte	W48
	.byte		        Fn4 
	.byte	W48
	.byte		        Fs4 
	.byte	W48
	.byte		        Dn4 
	.byte	W48
	.byte	W72
	.byte		N04   , Fs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte	PATT
	 .word	mus_rainbow_4_000
	.byte		N48   , Cs5 , v112
	.byte	W12
	.byte		VOL   , 67*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        65*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        64*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        63*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        60*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        60*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        57*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        56*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        54*mus_rainbow_mvl/mxv
	.byte	W04
	.byte		        51*mus_rainbow_mvl/mxv
	.byte	W04
	.byte		        48*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        45*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        41*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        38*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        35*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        31*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        68*mus_rainbow_mvl/mxv
	.byte		N48   , Cn5 
	.byte	W12
	.byte		VOL   , 67*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        65*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        64*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        63*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        60*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        60*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        57*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        56*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        54*mus_rainbow_mvl/mxv
	.byte	W04
	.byte		        51*mus_rainbow_mvl/mxv
	.byte	W04
	.byte		        48*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        45*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        41*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        38*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        35*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        31*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        68*mus_rainbow_mvl/mxv
	.byte		N48   , As4 
	.byte	W12
	.byte		VOL   , 67*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        65*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        64*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        63*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        60*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        60*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        57*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        56*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        54*mus_rainbow_mvl/mxv
	.byte	W04
	.byte		        51*mus_rainbow_mvl/mxv
	.byte	W04
	.byte		        48*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        45*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        41*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        38*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        35*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        31*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        68*mus_rainbow_mvl/mxv
	.byte		N48   , Cn5 
	.byte	W12
	.byte		VOL   , 67*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        65*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        64*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        63*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        60*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        60*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        57*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        56*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        54*mus_rainbow_mvl/mxv
	.byte	W04
	.byte		        51*mus_rainbow_mvl/mxv
	.byte	W04
	.byte		        48*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        45*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        41*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        38*mus_rainbow_mvl/mxv
	.byte	W03
	.byte		        35*mus_rainbow_mvl/mxv
	.byte	W01
	.byte		        31*mus_rainbow_mvl/mxv
	.byte	W03
	.byte	GOTO
	 .word	mus_rainbow_4_B1
	.byte		VOL   , 68*mus_rainbow_mvl/mxv
	.byte	FINE

@********************** Track  5 **********************@

mus_rainbow_5:
	.byte	KEYSH , mus_rainbow_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		PAN   , c_v-63
	.byte		VOL   , 37*mus_rainbow_mvl/mxv
	.byte	W24
	.byte		TIE   , Ds3 , v112
	.byte	W96
	.byte	W96
	.byte		EOT   
mus_rainbow_5_000:
	.byte		N48   , Cn3 , v112
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte	PEND
	.byte	PATT
	 .word	mus_rainbow_5_000
mus_rainbow_5_B1:
	.byte		N16   , Fn3 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N24   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		TIE   
	.byte	W08
	.byte	W96
	.byte		EOT   
mus_rainbow_5_001:
	.byte		N16   , Fn3 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N24   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte	PEND
mus_rainbow_5_002:
	.byte		N16   , Fn3 , v112
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte	PEND
	.byte		N48   , Ds3 
	.byte	W48
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N04   , Cs3 
	.byte	W08
	.byte		N64   , Cn3 
	.byte	W64
	.byte		N20   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N32   
	.byte	W32
	.byte		N24   , An2 
	.byte	W24
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N24   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N80   
	.byte	W08
	.byte	W72
	.byte		N08   
	.byte	W08
	.byte		N04   , Gn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte	PATT
	 .word	mus_rainbow_5_001
	.byte	PATT
	 .word	mus_rainbow_5_002
	.byte		N48   , Ds3 , v112
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		N56   
	.byte	W56
	.byte		N48   , Cn3 
	.byte	W48
	.byte		N36   , Gn3 
	.byte	W40
	.byte		N04   , Cn3 
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N32   , An2 
	.byte	W32
	.byte		N24   , Fn3 
	.byte	W24
mus_rainbow_5_003:
	.byte		N64   , Fs3 , v112
	.byte	W64
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte	PEND
	.byte		N16   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N04   , Cn3 
	.byte	W24
	.byte		N56   , Gs3 
	.byte	W56
	.byte	W96
	.byte	PATT
	 .word	mus_rainbow_5_003
	.byte		N24   , Fs3 , v112
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N16   , An3 
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W08
	.byte		N16   , An3 
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N04   
	.byte	W32
	.byte		N48   
	.byte	W48
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		N48   
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte		N16   
	.byte	W24
	.byte		N04   , Ds3 
	.byte		N04   , Fs3 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		N60   , Fn3 
	.byte	W64
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N16   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N16   , Fs3 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N56   , Ds3 
	.byte	W56
	.byte		N16   , Fs3 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , Ds3 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W24
	.byte		N48   , Gs3 
	.byte	W48
	.byte		TIE   
	.byte	W48
	.byte	W96
	.byte		EOT   
	.byte	GOTO
	 .word	mus_rainbow_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_rainbow_6:
	.byte	KEYSH , mus_rainbow_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		PAN   , c_v+63
	.byte		VOL   , 37*mus_rainbow_mvl/mxv
	.byte	W24
	.byte		TIE   , As3 , v112
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		N48   , Gn3 
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte		        An3 
	.byte	W48
mus_rainbow_6_B1:
	.byte		N16   , As3 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N24   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		TIE   , An3 
	.byte	W08
	.byte	W96
	.byte		EOT   
mus_rainbow_6_000:
	.byte		N16   , Gs3 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N24   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		        An3 
	.byte	W08
	.byte	PEND
	.byte		N16   , Gn3 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N48   , Fs3 
	.byte	W48
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W08
	.byte		N64   , Gn3 
	.byte	W64
	.byte		N20   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N16   , Fs3 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N32   , An3 
	.byte	W32
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N16   , As3 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N24   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N80   , An3 
	.byte	W08
	.byte	W72
	.byte		N08   
	.byte	W08
	.byte		N04   , As3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte	PATT
	 .word	mus_rainbow_6_000
	.byte		N16   , Gn3 , v112
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		N48   , Fs3 
	.byte	W48
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		N56   
	.byte	W56
	.byte		N48   , Gn3 
	.byte	W48
	.byte		N36   , Cn4 
	.byte	W40
	.byte		N04   , Gn3 
	.byte	W08
	.byte		N16   , Fs3 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Ds3 
	.byte	W16
	.byte		N32   , Cn3 
	.byte	W32
	.byte		N24   , An3 
	.byte	W24
mus_rainbow_6_001:
	.byte		N64   , Cs4 , v112
	.byte	W64
	.byte		N04   
	.byte	W24
	.byte		        As3 
	.byte	W08
	.byte	PEND
	.byte		N16   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N16   , Cn4 
	.byte	W16
	.byte		N04   , Ds3 
	.byte	W24
	.byte		N56   , Ds4 
	.byte	W56
	.byte	W96
	.byte	PATT
	 .word	mus_rainbow_6_001
	.byte		N24   , Cs4 , v112
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N16   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N16   , Cn4 
	.byte	W16
	.byte		N04   
	.byte	W32
	.byte		N48   
	.byte	W48
	.byte		N24   , Fs3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		N48   , Cs4 
	.byte	W48
	.byte		        As3 
	.byte	W48
	.byte		N16   , Cs4 
	.byte	W20
	.byte		N04   
	.byte	W04
	.byte		        An3 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		N60   , Ds4 
	.byte	W64
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N04   , Bn3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N16   , Cs4 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N56   , As3 
	.byte	W56
	.byte		N16   , Cs4 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , An3 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W24
	.byte		TIE   , Ds4 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte	GOTO
	 .word	mus_rainbow_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_rainbow_7:
	.byte	KEYSH , mus_rainbow_key+0
	.byte		VOICE , 127
	.byte		PAN   , c_v+0
	.byte		VOL   , 54*mus_rainbow_mvl/mxv
	.byte	W24
mus_rainbow_7_000:
	.byte		N01   , En5 , v112
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		        En5 , v120
	.byte	W08
	.byte		        En5 , v096
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W08
	.byte		        En5 , v064
	.byte	W04
	.byte		        En5 , v072
	.byte	W04
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v120
	.byte	W08
	.byte		        En5 , v096
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte	PEND
mus_rainbow_7_001:
	.byte		N01   , En5 , v112
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		        En5 , v120
	.byte	W08
	.byte		        En5 , v096
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		        En5 , v120
	.byte	W08
	.byte		        En5 , v096
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_rainbow_7_000
	.byte		N01   , En5 , v112
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		        En5 , v120
	.byte	W08
	.byte		        En5 , v096
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		        En5 , v120
	.byte	W08
	.byte		        En5 , v096
	.byte	W04
	.byte		        En5 , v072
	.byte	W04
	.byte		        En5 , v064
	.byte	W08
mus_rainbow_7_B1:
	.byte	PATT
	 .word	mus_rainbow_7_000
	.byte	PATT
	 .word	mus_rainbow_7_001
	.byte	PATT
	 .word	mus_rainbow_7_000
	.byte	PATT
	 .word	mus_rainbow_7_001
	.byte	PATT
	 .word	mus_rainbow_7_000
	.byte	PATT
	 .word	mus_rainbow_7_001
	.byte	PATT
	 .word	mus_rainbow_7_000
	.byte		N01   , En5 , v112
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		        En5 , v120
	.byte	W08
	.byte		        En5 , v096
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N03   , En5 , v120
	.byte	W08
	.byte		N01   , En5 , v096
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte	PATT
	 .word	mus_rainbow_7_000
	.byte	PATT
	 .word	mus_rainbow_7_001
	.byte	PATT
	 .word	mus_rainbow_7_000
	.byte	PATT
	 .word	mus_rainbow_7_001
	.byte	PATT
	 .word	mus_rainbow_7_000
	.byte	PATT
	 .word	mus_rainbow_7_001
	.byte	PATT
	 .word	mus_rainbow_7_000
	.byte	PATT
	 .word	mus_rainbow_7_001
	.byte	PATT
	 .word	mus_rainbow_7_000
	.byte	PATT
	 .word	mus_rainbow_7_001
	.byte	PATT
	 .word	mus_rainbow_7_000
	.byte	PATT
	 .word	mus_rainbow_7_001
	.byte	PATT
	 .word	mus_rainbow_7_000
	.byte	PATT
	 .word	mus_rainbow_7_001
	.byte	PATT
	 .word	mus_rainbow_7_000
	.byte	PATT
	 .word	mus_rainbow_7_001
	.byte	PATT
	 .word	mus_rainbow_7_000
	.byte	PATT
	 .word	mus_rainbow_7_001
	.byte	PATT
	 .word	mus_rainbow_7_000
	.byte	PATT
	 .word	mus_rainbow_7_001
	.byte	PATT
	 .word	mus_rainbow_7_000
	.byte	PATT
	 .word	mus_rainbow_7_001
	.byte	PATT
	 .word	mus_rainbow_7_000
	.byte	PATT
	 .word	mus_rainbow_7_001
	.byte	GOTO
	 .word	mus_rainbow_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_rainbow_8:
	.byte	KEYSH , mus_rainbow_key+0
	.byte		VOICE , 83
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		PAN   , c_v+0
	.byte		VOL   , 45*mus_rainbow_mvl/mxv
	.byte	W24
	.byte		BEND  , c_v+2
	.byte		TIE   , Dn4 , v112
	.byte	W96
	.byte	W40
	.byte		EOT   
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N08   , As3 
	.byte	W08
	.byte		N16   , Gn3 
	.byte	W16
	.byte		N08   , Ds3 
	.byte	W08
	.byte		N48   , An3 
	.byte	W48
	.byte		        As3 
	.byte	W48
	.byte		        Bn3 
	.byte	W48
	.byte		BEND  , c_v+0
	.byte		N48   , Cn4 
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N04   , En4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		N08   , Ds4 
	.byte	W08
mus_rainbow_8_B1:
	.byte		BEND  , c_v+2
	.byte		N16   , Dn4 , v112
	.byte	W16
	.byte		N04   , Ds4 
	.byte	W08
	.byte		        Fn4 
	.byte	W16
	.byte		N24   
	.byte	W24
	.byte		N04   , Ds4 
	.byte	W08
	.byte		        Dn4 
	.byte	W16
	.byte		TIE   , Cn4 
	.byte	W08
	.byte	W96
	.byte		EOT   
mus_rainbow_8_000:
	.byte		N16   , Dn4 , v112
	.byte	W16
	.byte		N04   , Ds4 
	.byte	W08
	.byte		        Fn4 
	.byte	W16
	.byte		N24   , As4 
	.byte	W24
	.byte		N04   , Fn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte	PEND
mus_rainbow_8_001:
	.byte		N16   , Cn4 , v112
	.byte	W16
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		N24   , Bn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte	PEND
mus_rainbow_8_002:
	.byte		N48   , As3 , v112
	.byte	W48
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte	PEND
	.byte		        Dn4 
	.byte	W24
	.byte		N04   , Fn4 
	.byte	W16
	.byte		N24   , As3 
	.byte	W24
	.byte		N04   , An3 
	.byte	W08
	.byte		N16   , As3 
	.byte	W16
	.byte		N04   , Bn3 
	.byte	W08
	.byte		N64   , Cn4 
	.byte	W64
	.byte		N20   , As3 
	.byte	W32
	.byte		N16   
	.byte	W16
	.byte		N04   , An3 
	.byte	W08
	.byte		        As3 
	.byte	W16
	.byte		N56   , Cn4 
	.byte	W56
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N04   , Ds4 
	.byte	W08
	.byte		        Fn4 
	.byte	W16
	.byte		N24   
	.byte	W24
	.byte		N04   , Ds4 
	.byte	W08
	.byte		        Dn4 
	.byte	W16
	.byte		TIE   , Cn4 
	.byte	W08
	.byte	W96
	.byte		EOT   
	.byte	PATT
	 .word	mus_rainbow_8_000
	.byte	PATT
	 .word	mus_rainbow_8_001
	.byte	PATT
	 .word	mus_rainbow_8_002
	.byte		N24   , Dn4 , v112
	.byte	W24
	.byte		N04   , Fn4 
	.byte	W16
	.byte		N24   , As4 
	.byte	W24
	.byte		N04   , Gn4 
	.byte	W08
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N04   , Dn4 
	.byte	W08
	.byte		N64   , As3 
	.byte	W64
	.byte		N20   , Cn4 
	.byte	W32
	.byte		N16   , As3 
	.byte	W16
	.byte		N04   , Gs3 
	.byte	W08
	.byte		        Fs3 
	.byte	W16
	.byte		N56   , Fn3 
	.byte	W56
	.byte		N64   , Fn4 
	.byte	W64
	.byte		N04   , Ds4 
	.byte	W24
	.byte		        Cs4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N04   , Fn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N04   , Gs3 
	.byte	W24
	.byte		N56   , Gs4 
	.byte	W56
	.byte	W72
	.byte		N04   , Gs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N64   , Fn4 
	.byte	W64
	.byte		N04   , Fs4 
	.byte	W24
	.byte		        Fn4 
	.byte	W08
	.byte		N24   , Fs4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N16   , Fs4 
	.byte	W16
	.byte		N04   , Fn4 
	.byte	W08
	.byte		N16   , Fs4 
	.byte	W16
	.byte		N04   , Gs4 
	.byte	W08
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N04   , Ds4 
	.byte	W24
	.byte		        Cs4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		N48   , Fn4 
	.byte	W48
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		N64   , Fn4 
	.byte	W64
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N04   , Cs4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N04   , Fn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Cs4 
	.byte	W24
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		N60   , Gs4 
	.byte	W64
	.byte		N04   , Fs4 
	.byte	W24
	.byte		        Fn4 
	.byte	W08
	.byte		N16   , Fs4 
	.byte	W16
	.byte		N04   , Gs4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		N24   , Fn4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N04   , Ds4 
	.byte	W24
	.byte		N56   , Cs4 
	.byte	W56
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N04   , Ds4 
	.byte	W24
	.byte		N08   , Cs4 
	.byte	W24
	.byte		N04   , Cn4 
	.byte	W08
	.byte		N24   , Cs4 
	.byte	W24
	.byte		TIE   , Gs4 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte	GOTO
	 .word	mus_rainbow_8_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_rainbow:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rainbow_pri	@ Priority
	.byte	mus_rainbow_rev	@ Reverb.

	.word	mus_rainbow_grp

	.word	mus_rainbow_1
	.word	mus_rainbow_2
	.word	mus_rainbow_3
	.word	mus_rainbow_4
	.word	mus_rainbow_5
	.word	mus_rainbow_6
	.word	mus_rainbow_7
	.word	mus_rainbow_8

	.end
