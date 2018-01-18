	.include "MPlayDef.s"

	.equ	mus_con_fan_grp, voicegroup_868EC7C
	.equ	mus_con_fan_pri, 0
	.equ	mus_con_fan_rev, reverb_set+50
	.equ	mus_con_fan_mvl, 127
	.equ	mus_con_fan_key, 0
	.equ	mus_con_fan_tbs, 1
	.equ	mus_con_fan_exg, 0
	.equ	mus_con_fan_cmp, 1

	.section .rodata
	.global	mus_con_fan
	.align	2

@********************** Track  1 **********************@

mus_con_fan_1:
	.byte	KEYSH , mus_con_fan_key+0
	.byte	TEMPO , 148*mus_con_fan_tbs/2
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 79*mus_con_fan_mvl/mxv
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_con_fan_1_B1:
mus_con_fan_1_000:
	.byte		N02   , Gn5 , v076
	.byte	W08
	.byte		        Gn5 , v036
	.byte	W08
	.byte		        Gn5 , v048
	.byte	W08
	.byte		        Gn5 , v076
	.byte	W08
	.byte		        Gn5 , v036
	.byte	W08
	.byte		        Gn5 , v048
	.byte	W08
	.byte		        Gn5 , v076
	.byte	W08
	.byte		        Gn5 , v036
	.byte	W08
	.byte		        Gn5 , v048
	.byte	W08
	.byte		        Gn5 , v076
	.byte	W08
	.byte		        Gn5 , v036
	.byte	W08
	.byte		        Gn5 , v048
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_con_fan_1_000
	.byte	PATT
	 .word	mus_con_fan_1_000
	.byte		N02   , Gn5 , v076
	.byte	W08
	.byte		        Gn5 , v036
	.byte	W08
	.byte		        Gn5 , v048
	.byte	W08
	.byte		        Gn5 , v076
	.byte	W08
	.byte		        Gn5 , v036
	.byte	W08
	.byte		        Gn5 , v048
	.byte	W08
	.byte		        Gn5 , v076
	.byte	W08
	.byte		        Gn5 , v036
	.byte	W08
	.byte		        Gn5 , v048
	.byte	W08
	.byte		        Gn5 , v076
	.byte	W08
	.byte		        Gn5 , v036
	.byte	W08
	.byte		        Gn5 , v056
	.byte	W08
	.byte	GOTO
	 .word	mus_con_fan_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_con_fan_2:
	.byte	KEYSH , mus_con_fan_key+0
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-1
	.byte		VOL   , 100*mus_con_fan_mvl/mxv
	.byte	W12
	.byte		N06   , Fn3 , v088
	.byte	W12
	.byte		        Cn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N04   , Fn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N06   , Fs3 
	.byte	W12
	.byte		        Cs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        As3 
	.byte	W12
	.byte		        Fs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N04   , Fs4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		N24   , An4 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N04   
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
mus_con_fan_2_B1:
	.byte		VOICE , 24
	.byte		PAN   , c_v+16
	.byte		VOL   , 94*mus_con_fan_mvl/mxv
	.byte		N04   , Fs4 , v052
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        An4 
	.byte	W24
	.byte		VOICE , 73
	.byte		N04   , Fs5 , v040
	.byte	W08
	.byte		        Gn5 
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte		        An5 
	.byte	W08
	.byte		        Dn6 
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		N36   , An5 , v032
	.byte	W12
	.byte		MOD   , 5
	.byte		VOL   , 94*mus_con_fan_mvl/mxv
	.byte	W04
	.byte		        88*mus_con_fan_mvl/mxv
	.byte	W04
	.byte		        81*mus_con_fan_mvl/mxv
	.byte	W04
	.byte		        77*mus_con_fan_mvl/mxv
	.byte	W04
	.byte		        74*mus_con_fan_mvl/mxv
	.byte	W04
	.byte		        94*mus_con_fan_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		N04   , Bn5 
	.byte	W04
	.byte		N08   , An5 
	.byte	W08
	.byte		N48   , Gn5 
	.byte	W24
	.byte		MOD   , 5
	.byte		VOL   , 90*mus_con_fan_mvl/mxv
	.byte	W04
	.byte		        88*mus_con_fan_mvl/mxv
	.byte	W04
	.byte		        83*mus_con_fan_mvl/mxv
	.byte	W04
	.byte		        77*mus_con_fan_mvl/mxv
	.byte	W04
	.byte		        74*mus_con_fan_mvl/mxv
	.byte	W04
	.byte		        71*mus_con_fan_mvl/mxv
	.byte	W04
	.byte		VOICE , 24
	.byte		MOD   , 0
	.byte		VOL   , 94*mus_con_fan_mvl/mxv
	.byte		N04   , En4 , v052
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W24
	.byte		VOICE , 73
	.byte		N04   , En5 , v040
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		        Gn5 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		N36   , Dn5 
	.byte	W12
	.byte		MOD   , 5
	.byte		VOL   , 89*mus_con_fan_mvl/mxv
	.byte	W04
	.byte		        86*mus_con_fan_mvl/mxv
	.byte	W04
	.byte		        83*mus_con_fan_mvl/mxv
	.byte	W04
	.byte		        78*mus_con_fan_mvl/mxv
	.byte	W04
	.byte		        75*mus_con_fan_mvl/mxv
	.byte	W04
	.byte		        74*mus_con_fan_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 94*mus_con_fan_mvl/mxv
	.byte		N04   , Cs5 
	.byte	W04
	.byte		N08   , Dn5 
	.byte	W08
	.byte		N24   , En5 
	.byte	W24
	.byte		N16   , Cn6 
	.byte	W16
	.byte		N04   , As5 
	.byte	W08
	.byte	GOTO
	 .word	mus_con_fan_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_con_fan_3:
	.byte	KEYSH , mus_con_fan_key+0
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_con_fan_mvl/mxv
	.byte		N04   , Cn2 , v064
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N24   , Fn1 
	.byte	W36
	.byte		N03   , Cn2 , v032
	.byte	W06
	.byte		        Cn2 , v048
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Cn2 , v060
	.byte	W12
	.byte		N04   , Cn2 , v064
	.byte	W08
	.byte		        Fn2 , v052
	.byte	W08
	.byte		        Cn2 , v064
	.byte	W08
	.byte		N24   , Fs1 
	.byte	W36
	.byte		N03   , Cs2 , v032
	.byte	W06
	.byte		        Cs2 , v048
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Cs2 , v060
	.byte	W12
	.byte		N04   , Cs2 , v064
	.byte	W08
	.byte		        Fs2 , v052
	.byte	W08
	.byte		        Cs2 , v064
	.byte	W08
	.byte		N06   , Gn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		N04   , Gn2 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		        Gn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		N20   , An1 
	.byte	W48
	.byte		N04   , En2 
	.byte	W12
	.byte		N08   , An1 
	.byte	W12
	.byte		N04   , An2 
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		        An1 
	.byte	W08
mus_con_fan_3_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_con_fan_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_con_fan_4:
	.byte	KEYSH , mus_con_fan_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 100*mus_con_fan_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		N02   , Fn4 , v040
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N32   
	.byte	W12
	.byte		MOD   , 5
	.byte	W22
	.byte		        0
	.byte	W02
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N04   
	.byte	W12
	.byte		N04   
	.byte	W12
	.byte		N04   
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		N32   , Fs4 
	.byte	W14
	.byte		MOD   , 5
	.byte	W22
	.byte		        0
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W08
	.byte		N04   
	.byte	W10
	.byte		N04   
	.byte	W12
	.byte		N04   
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N04   
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        An3 
	.byte	W08
mus_con_fan_4_B1:
	.byte		PAN   , c_v-64
	.byte		VOL   , 69*mus_con_fan_mvl/mxv
	.byte		N04   , Fs4 , v040
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		PAN   , c_v+63
	.byte		N04   , Fs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		PAN   , c_v-64
	.byte		N04   , En4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		PAN   , c_v+63
	.byte		N04   , Cn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		PAN   , c_v-64
	.byte		N04   , En4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		PAN   , c_v+63
	.byte		N04   , En4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		PAN   , c_v-64
	.byte		N04   , As3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		PAN   , c_v+63
	.byte		N04   , En4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte	GOTO
	 .word	mus_con_fan_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_con_fan_5:
	.byte	KEYSH , mus_con_fan_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 96*mus_con_fan_mvl/mxv
	.byte		N02   , Cn2 , v064
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N72   , Fn1 , v072
	.byte	W72
	.byte		N04   , Cn1 , v064
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		N30   , Fs1 , v072
	.byte	W36
	.byte		N03   , Fs1 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N04   , Cs1 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		N06   , Gn1 , v072
	.byte	W12
	.byte		        Dn1 , v064
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N04   
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		N24   , An1 , v072
	.byte	W36
	.byte		N03   , An1 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N04   
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Cs2 
	.byte	W08
mus_con_fan_5_B1:
	.byte		VOL   , 88*mus_con_fan_mvl/mxv
	.byte		N08   , Dn2 , v072
	.byte	W16
	.byte		N04   , Dn2 , v056
	.byte	W08
	.byte		N08   , An1 
	.byte	W16
	.byte		N04   , Dn2 
	.byte	W08
	.byte		N08   , Dn2 , v072
	.byte	W16
	.byte		N04   , Dn2 , v056
	.byte	W08
	.byte		N08   , An1 
	.byte	W08
	.byte		N04   , As1 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		N08   , Cn2 , v072
	.byte	W16
	.byte		N04   , Cn2 , v056
	.byte	W08
	.byte		N08   , An1 
	.byte	W16
	.byte		N04   , Cn2 
	.byte	W08
	.byte		N08   , Cn2 , v072
	.byte	W16
	.byte		N04   , Cn2 , v056
	.byte	W08
	.byte		N08   , Gn1 
	.byte	W08
	.byte		N04   , An1 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		N08   , Bn1 , v072
	.byte	W16
	.byte		N04   , Bn1 , v056
	.byte	W08
	.byte		N08   , Gn1 
	.byte	W16
	.byte		N04   , Bn1 
	.byte	W08
	.byte		N08   , Bn1 , v072
	.byte	W16
	.byte		N04   , Bn1 , v056
	.byte	W08
	.byte		N08   , Gn1 
	.byte	W08
	.byte		N04   , Gs1 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		N08   , As1 , v072
	.byte	W16
	.byte		N04   , As1 , v056
	.byte	W08
	.byte		N08   , Fn1 
	.byte	W08
	.byte		N04   , As1 
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		N08   , Cn2 , v072
	.byte	W16
	.byte		N04   , Cn2 , v056
	.byte	W08
	.byte		N08   , Gn1 
	.byte	W16
	.byte		N04   , Cn2 
	.byte	W08
	.byte	GOTO
	 .word	mus_con_fan_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_con_fan_6:
	.byte	KEYSH , mus_con_fan_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_con_fan_mvl/mxv
	.byte	W12
	.byte		N48   , An2 , v048
	.byte	W96
	.byte		        An2 , v064
	.byte	W96
	.byte		N24   , An2 , v052
	.byte	W24
	.byte		        Gn2 , v044
	.byte	W24
	.byte		        An2 , v056
	.byte	W24
	.byte		        Gn2 , v044
	.byte	W24
	.byte		N48   , An2 , v064
	.byte	W96
mus_con_fan_6_B1:
	.byte		VOL   , 77*mus_con_fan_mvl/mxv
	.byte		N04   , Cn1 , v096
	.byte		N48   , An2 
	.byte	W16
	.byte		N04   , Cn1 , v080
	.byte	W08
	.byte		        En1 , v096
	.byte	W16
	.byte		        En1 , v080
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W16
	.byte		        En1 , v076
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En1 , v096
	.byte	W16
	.byte		        En1 , v080
	.byte	W08
mus_con_fan_6_000:
	.byte		N04   , Cn1 , v096
	.byte	W16
	.byte		        Cn1 , v080
	.byte	W08
	.byte		        En1 , v096
	.byte	W16
	.byte		        En1 , v080
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W16
	.byte		        En1 , v076
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En1 , v096
	.byte	W16
	.byte		        En1 , v080
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_con_fan_6_000
	.byte		N04   , Cn1 , v096
	.byte	W08
	.byte		        En1 , v080
	.byte	W08
	.byte		        Cn1 , v084
	.byte	W08
	.byte		        En1 , v096
	.byte	W16
	.byte		        En1 , v088
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W08
	.byte		        En1 , v084
	.byte	W08
	.byte		        Cn1 , v088
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En1 , v096
	.byte	W08
	.byte	GOTO
	 .word	mus_con_fan_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_con_fan_7:
	.byte	KEYSH , mus_con_fan_key+0
	.byte		VOICE , 83
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 100*mus_con_fan_mvl/mxv
	.byte		PAN   , c_v-62
	.byte		N02   , An3 , v064
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N32   
	.byte	W12
	.byte		MOD   , 5
	.byte	W22
	.byte		        0
	.byte	W02
	.byte		N02   , An3 , v052
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N04   
	.byte	W12
	.byte		N04   
	.byte	W12
	.byte		N04   
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N32   , As3 
	.byte	W14
	.byte		MOD   , 5
	.byte	W22
	.byte		        0
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W08
	.byte		N04   
	.byte	W10
	.byte		N04   
	.byte	W12
	.byte		N04   
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		N24   , An3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        An2 
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N04   
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
mus_con_fan_7_B1:
	.byte		PAN   , c_v+0
	.byte		VOL   , 75*mus_con_fan_mvl/mxv
	.byte		N04   , Fs3 , v052
	.byte	W08
	.byte		N12   , An3 
	.byte	W16
	.byte		N12   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N60   , Dn4 
	.byte	W24
	.byte		MOD   , 5
	.byte	W36
	.byte		N04   , Cn4 
	.byte	W04
	.byte		N08   , Dn4 
	.byte	W08
	.byte		MOD   , 0
	.byte		N04   , Cn4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		N12   , Gn3 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N36   , As3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N04   , An3 
	.byte	W04
	.byte		N08   , As3 
	.byte	W08
	.byte		N04   , Cn4 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N16   , Gn4 
	.byte	W16
	.byte		N04   , Cn5 
	.byte	W08
	.byte	GOTO
	 .word	mus_con_fan_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_con_fan_8:
	.byte	KEYSH , mus_con_fan_key+0
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-16
	.byte		VOL   , 100*mus_con_fan_mvl/mxv
	.byte	W12
	.byte		N06   , An2 , v064
	.byte	W12
	.byte		        Fn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Cn3 
	.byte	W12
	.byte		        An2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N04   , An3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		N06   , As2 
	.byte	W12
	.byte		        Fs2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cs3 
	.byte	W12
	.byte		        As2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W12
	.byte		        Cs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N04   , As3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		N24   , Cs4 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N04   
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
mus_con_fan_8_B1:
	.byte		VOICE , 24
	.byte		VOL   , 93*mus_con_fan_mvl/mxv
	.byte		N04   , Dn4 , v052
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W24
	.byte		VOICE , 73
	.byte		N04   , An4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		N36   , Cn5 
	.byte	W36
	.byte		N04   , Dn5 
	.byte	W04
	.byte		N08   , Cn5 
	.byte	W08
	.byte		N48   
	.byte	W48
	.byte		VOICE , 24
	.byte		N04   , Gn3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Bn3 
	.byte	W24
	.byte		VOICE , 73
	.byte		N04   , Gn4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		N36   , Fn4 
	.byte	W36
	.byte		N04   , En4 
	.byte	W04
	.byte		N08   , Fn4 
	.byte	W08
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N16   , Gn5 
	.byte	W16
	.byte		N04   , En5 
	.byte	W08
	.byte	GOTO
	 .word	mus_con_fan_8_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_con_fan:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_con_fan_pri	@ Priority
	.byte	mus_con_fan_rev	@ Reverb.

	.word	mus_con_fan_grp

	.word	mus_con_fan_1
	.word	mus_con_fan_2
	.word	mus_con_fan_3
	.word	mus_con_fan_4
	.word	mus_con_fan_5
	.word	mus_con_fan_6
	.word	mus_con_fan_7
	.word	mus_con_fan_8

	.end
