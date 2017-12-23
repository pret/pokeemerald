	.include "MPlayDef.s"

	.equ	mus_friendly_grp, voicegroup_86826D0
	.equ	mus_friendly_pri, 0
	.equ	mus_friendly_rev, reverb_set+50
	.equ	mus_friendly_mvl, 127
	.equ	mus_friendly_key, 0
	.equ	mus_friendly_tbs, 1
	.equ	mus_friendly_exg, 0
	.equ	mus_friendly_cmp, 1

	.section .rodata
	.global	mus_friendly
	.align	2

@********************** Track  1 **********************@

mus_friendly_1:
	.byte	KEYSH , mus_friendly_key+0
	.byte	TEMPO , 172*mus_friendly_tbs/2
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		VOL   , 53*mus_friendly_mvl/mxv
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N06   , Bn5 , v112
	.byte	W12
	.byte		N03   , An5 , v088
	.byte	W03
	.byte		        Gn5 
	.byte	W03
	.byte		        Fn5 , v084
	.byte	W03
	.byte		        En5 
	.byte	W03
	.byte		        Dn5 , v076
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Gn4 , v072
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Cn4 , v068
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Fn3 
	.byte	W04
	.byte		VOL   , 79*mus_friendly_mvl/mxv
	.byte	W08
	.byte		VOICE , 17
	.byte		N04   , Fs3 , v112
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
mus_friendly_1_B1:
	.byte		VOICE , 17
	.byte		VOL   , 83*mus_friendly_mvl/mxv
	.byte		N08   , Cs4 , v120
	.byte	W08
	.byte		        Cs4 , v032
	.byte	W08
	.byte		N04   , Fs3 , v112
	.byte	W08
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W08
	.byte		N32   , Bn3 , v112
	.byte	W24
	.byte		MOD   , 8
	.byte	W08
	.byte		        0
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N08   , Ds4 , v120
	.byte	W16
	.byte		        Dn4 , v112
	.byte	W08
	.byte		        Ds4 
	.byte	W16
	.byte		N16   , En4 
	.byte	W16
	.byte		N02   , Ds4 , v080
	.byte	W02
	.byte		        Cs4 
	.byte	W02
	.byte		        Bn3 
	.byte	W02
	.byte		        As3 , v076
	.byte	W02
	.byte		        An3 , v072
	.byte	W02
	.byte		        Gn3 
	.byte	W02
	.byte		        Fn3 
	.byte	W04
	.byte		N04   , Ds4 , v112
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		N08   , Fs4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Cs4 , v032
	.byte	W08
	.byte		N04   , Fs3 , v112
	.byte	W08
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W08
	.byte		N32   , Bn3 , v112
	.byte	W24
	.byte		MOD   , 8
	.byte	W08
	.byte		        0
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N08   , Ds4 
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W12
	.byte		N04   , Gn4 , v068
	.byte	W04
	.byte		N16   , Gs4 , v112
	.byte	W16
	.byte		N02   , Gn4 , v084
	.byte	W02
	.byte		        Fn4 
	.byte	W02
	.byte		        En4 , v080
	.byte	W02
	.byte		        Dn4 , v076
	.byte	W02
	.byte		        Cn4 
	.byte	W02
	.byte		        Bn3 , v072
	.byte	W06
	.byte		N04   , En4 , v112
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W08
	.byte		N04   , Gs3 , v112
	.byte	W08
	.byte		N08   , En4 
	.byte	W08
	.byte		        En4 , v032
	.byte	W08
	.byte		N40   , Cs4 , v112
	.byte	W32
	.byte		MOD   , 8
	.byte	W08
	.byte		        0
	.byte		N02   , Bn3 , v080
	.byte	W02
	.byte		        As3 , v076
	.byte	W02
	.byte		        Gs3 , v072
	.byte	W02
	.byte		        Fs3 , v064
	.byte	W02
	.byte		        En3 , v056
	.byte	W02
	.byte		        Ds3 
	.byte	W06
	.byte	W24
	.byte		N24   , Gs3 , v112
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		N40   , Ds4 
	.byte	W40
	.byte		MOD   , 8
	.byte		N04   , En4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		MOD   , 0
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N08   , Bn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		N10   , Cs4 
	.byte	W10
	.byte		N02   , Cn4 , v080
	.byte	W02
	.byte		        Bn3 , v076
	.byte	W02
	.byte		        An3 , v072
	.byte	W02
	.byte		        Gn3 , v064
	.byte	W02
	.byte		        Fn3 , v056
	.byte	W02
	.byte		        En3 
	.byte	W04
	.byte		VOL   , 83*mus_friendly_mvl/mxv
	.byte		N02   , Cs3 , v076
	.byte	W02
	.byte		        Ds3 
	.byte	W02
	.byte		        En3 , v080
	.byte	W02
	.byte		        Fs3 
	.byte	W02
	.byte		        Gs3 
	.byte	W02
	.byte		        As3 , v084
	.byte	W02
	.byte		        Bn3 
	.byte	W02
	.byte		        Cs4 , v088
	.byte	W02
	.byte		        Ds4 
	.byte	W02
	.byte		        En4 
	.byte	W02
	.byte		        Fs4 , v092
	.byte	W02
	.byte		        Gs4 
	.byte	W02
	.byte		        As4 
	.byte	W02
	.byte		VOICE , 1
	.byte		N02   , Bn4 
	.byte	W02
	.byte		N04   , Cn5 , v096
	.byte	W04
	.byte		N16   , Bn4 
	.byte	W16
	.byte		N08   , Fs4 , v112
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		N20   , Cs4 
	.byte	W20
	.byte		N04   , Dn4 
	.byte	W04
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N32   , Bn3 
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N08   , Ds4 
	.byte	W40
	.byte		        En4 
	.byte	W24
	.byte		        Ds4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        En4 , v032
	.byte	W08
	.byte		        Fs4 , v112
	.byte	W08
	.byte		        Cs4 
	.byte		N08   , Fs4 , v032
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Fs3 , v112
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W08
	.byte		N32   , Bn3 , v112
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N08   , Ds4 
	.byte	W36
	.byte		N04   , Gn4 
	.byte	W04
	.byte		N08   , Gs4 
	.byte	W24
	.byte		        Fs4 
	.byte	W16
	.byte		N04   , Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W08
	.byte		        Gs3 , v112
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        En4 , v032
	.byte	W08
	.byte		N56   , Cs4 , v112
	.byte	W56
	.byte		N08   , Cs4 , v032
	.byte	W24
	.byte		        Gs3 , v088
	.byte	W10
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N04   , Gs3 
	.byte	W08
	.byte		N08   , As3 , v096
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N04   , As3 
	.byte	W08
	.byte		N08   , Bn3 , v112
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		N04   , Bn3 
	.byte	W08
	.byte		N40   , Ds4 
	.byte	W40
	.byte		N04   , En4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N08   , Bn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W72
	.byte		VOICE , 17
	.byte		VOL   , 79*mus_friendly_mvl/mxv
	.byte		N08   , Bn3 
	.byte	W08
	.byte		        Bn3 , v032
	.byte	W08
	.byte		        Cs4 , v112
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W16
	.byte		        Ds4 , v112
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W16
	.byte		        Ds4 , v112
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte		N04   , Ds4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N08   , As4 
	.byte	W08
	.byte	W24
	.byte		        Gn4 
	.byte	W08
	.byte		        Gn4 , v032
	.byte	W16
	.byte		        Ds4 , v112
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W16
	.byte		        Cs4 , v112
	.byte	W08
	.byte		        Cs4 , v032
	.byte	W16
	.byte		VOICE , 1
	.byte		VOL   , 78*mus_friendly_mvl/mxv
	.byte		N20   , Cs4 , v112
	.byte	W20
	.byte		N04   , Dn4 
	.byte	W04
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W08
	.byte		N24   , Bn3 , v112
	.byte	W24
	.byte		N08   , As3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Bn3 , v032
	.byte	W08
	.byte		N32   , Cs4 , v112
	.byte	W08
	.byte	W24
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W08
	.byte		N24   , Bn3 , v112
	.byte	W24
	.byte		N08   , As3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Bn3 , v032
	.byte	W08
	.byte		        Cs4 , v112
	.byte	W08
	.byte		VOICE , 17
	.byte		VOL   , 79*mus_friendly_mvl/mxv
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W16
	.byte		        Ds4 , v112
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W16
	.byte		N16   , Ds4 , v112
	.byte	W16
	.byte		N08   , Dn4 
	.byte	W08
	.byte		N04   , Ds4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N08   , As4 
	.byte	W08
	.byte		        As4 , v032
	.byte	W24
	.byte		        Gn4 , v112
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N04   , Gn4 
	.byte	W08
	.byte		N08   , Gs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		N04   , Gs4 
	.byte	W08
	.byte		N08   , As4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		N04   , As4 
	.byte	W08
	.byte		VOICE , 1
	.byte		VOL   , 80*mus_friendly_mvl/mxv
	.byte		N24   
	.byte	W24
	.byte		N08   , Bn4 
	.byte	W08
	.byte		        Bn4 , v032
	.byte	W08
	.byte		        Gs4 , v112
	.byte	W08
	.byte		        Gs4 , v032
	.byte	W16
	.byte		        Gn4 , v112
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Gs4 , v032
	.byte	W08
	.byte		N32   , As4 , v112
	.byte	W08
	.byte	W24
	.byte		N08   , Bn4 
	.byte	W08
	.byte		        Bn4 , v032
	.byte	W08
	.byte		N24   , Gs4 , v112
	.byte	W24
	.byte		N08   , Cs5 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Bn4 , v032
	.byte	W08
	.byte		        As4 , v112
	.byte	W08
	.byte		VOICE , 17
	.byte		VOL   , 43*mus_friendly_mvl/mxv
	.byte		N92   , Bn5 
	.byte	W04
	.byte		VOL   , 42*mus_friendly_mvl/mxv
	.byte	W03
	.byte		        38*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        27*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        17*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        14*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        12*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        10*mus_friendly_mvl/mxv
	.byte	W12
	.byte		        12*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        16*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        18*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        24*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        29*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        37*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        43*mus_friendly_mvl/mxv
	.byte	W01
	.byte		        43*mus_friendly_mvl/mxv
	.byte	W08
	.byte		MOD   , 4
	.byte	W20
	.byte		N04   , As5 
	.byte	W04
	.byte		MOD   , 0
	.byte		N72   , Bn5 
	.byte	W04
	.byte		VOL   , 42*mus_friendly_mvl/mxv
	.byte	W03
	.byte		        38*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        27*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        17*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        14*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        12*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        10*mus_friendly_mvl/mxv
	.byte	W12
	.byte		        12*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        16*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        18*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        24*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        29*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        37*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        43*mus_friendly_mvl/mxv
	.byte	W01
	.byte		        43*mus_friendly_mvl/mxv
	.byte	W08
	.byte		MOD   , 4
	.byte		N08   , Gs5 
	.byte	W08
	.byte		        As5 
	.byte	W08
	.byte		        Bn5 
	.byte	W08
	.byte		MOD   , 0
	.byte		N72   , As5 
	.byte	W04
	.byte		VOL   , 42*mus_friendly_mvl/mxv
	.byte	W03
	.byte		        38*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        27*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        17*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        14*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        12*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        10*mus_friendly_mvl/mxv
	.byte	W12
	.byte		        12*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        16*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        18*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        24*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        29*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        37*mus_friendly_mvl/mxv
	.byte	W04
	.byte		        43*mus_friendly_mvl/mxv
	.byte	W01
	.byte		        43*mus_friendly_mvl/mxv
	.byte	W08
	.byte		MOD   , 4
	.byte		N08   , Gs5 
	.byte	W08
	.byte		N04   , As5 
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte		MOD   , 0
	.byte		N24   , Fs5 
	.byte	W24
	.byte		VOICE , 1
	.byte		VOL   , 75*mus_friendly_mvl/mxv
	.byte		N08   , En5 , v084
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        Gs4 , v080
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Fs4 , v076
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Gs3 , v084
	.byte	W08
	.byte		        As3 , v096
	.byte	W08
	.byte	GOTO
	 .word	mus_friendly_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_friendly_2:
	.byte	KEYSH , mus_friendly_key+0
	.byte		VOICE , 87
	.byte		PAN   , c_v+0
	.byte		XCMD  , xIECV , 12
	.byte		        xIECL , 8
	.byte		BENDR , 12
	.byte		VOL   , 29*mus_friendly_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		N04   , Fs3 , v112
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
mus_friendly_2_B1:
	.byte		N08   , Cs4 , v120
	.byte	W08
	.byte		        Cs4 , v032
	.byte	W08
	.byte		N04   , Fs3 , v112
	.byte	W08
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W08
	.byte		N32   , Bn3 , v112
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N08   , Ds4 , v120
	.byte	W16
	.byte		        Dn4 , v112
	.byte	W08
	.byte		        Ds4 
	.byte	W16
	.byte		N16   , En4 
	.byte	W16
	.byte		N02   , Ds4 , v080
	.byte	W02
	.byte		        Cs4 
	.byte	W02
	.byte		        Bn3 
	.byte	W02
	.byte		        As3 , v076
	.byte	W02
	.byte		        An3 , v072
	.byte	W02
	.byte		        Gn3 
	.byte	W02
	.byte		        Fn3 
	.byte	W04
	.byte		N04   , Ds4 , v112
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		N08   , Fs4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Cs4 , v032
	.byte	W08
	.byte		N04   , Fs3 , v112
	.byte	W08
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W08
	.byte		N32   , Bn3 , v112
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N08   , Ds4 
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W12
	.byte		N04   , Gn4 , v068
	.byte	W04
	.byte		N16   , Gs4 , v112
	.byte	W16
	.byte		N02   , Gn4 , v084
	.byte	W02
	.byte		        Fn4 
	.byte	W02
	.byte		        En4 , v080
	.byte	W02
	.byte		        Dn4 , v076
	.byte	W02
	.byte		        Cn4 
	.byte	W02
	.byte		        Bn3 , v072
	.byte	W06
	.byte		N04   , En4 , v112
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W08
	.byte		N04   , Gs3 , v112
	.byte	W08
	.byte		N08   , En4 
	.byte	W08
	.byte		        En4 , v032
	.byte	W08
	.byte		N40   , Cs4 , v112
	.byte	W40
	.byte		N02   , Bn3 , v080
	.byte	W02
	.byte		        As3 , v076
	.byte	W02
	.byte		        Gs3 , v072
	.byte	W02
	.byte		        Fs3 , v064
	.byte	W02
	.byte		        En3 , v056
	.byte	W02
	.byte		        Ds3 
	.byte	W06
	.byte	W24
	.byte		N24   , Gs3 , v112
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
mus_friendly_2_000:
	.byte		N40   , Ds4 , v112
	.byte	W40
	.byte		N04   , En4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N08   , Bn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte	PEND
	.byte		N10   , Cs4 
	.byte	W10
	.byte		N02   , Cn4 , v080
	.byte	W02
	.byte		        Bn3 , v076
	.byte	W02
	.byte		        An3 , v072
	.byte	W02
	.byte		        Gn3 , v064
	.byte	W02
	.byte		        Fn3 , v056
	.byte	W02
	.byte		        En3 
	.byte	W04
	.byte		        Cs3 , v076
	.byte	W02
	.byte		        Ds3 
	.byte	W02
	.byte		        En3 , v080
	.byte	W02
	.byte		        Fs3 
	.byte	W02
	.byte		        Gs3 
	.byte	W02
	.byte		        As3 , v084
	.byte	W02
	.byte		        Bn3 
	.byte	W02
	.byte		        Cs4 , v088
	.byte	W02
	.byte		        Ds4 
	.byte	W02
	.byte		        En4 
	.byte	W02
	.byte		        Fs4 , v092
	.byte	W02
	.byte		        Gs4 
	.byte	W02
	.byte		BEND  , c_v+0
	.byte		N02   , As4 
	.byte	W02
	.byte		        Bn4 
	.byte	W02
	.byte		N04   , Cn5 , v096
	.byte	W04
	.byte		N16   , Bn4 
	.byte	W16
	.byte		N08   , Fs4 , v112
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		N20   , Cs4 
	.byte	W20
	.byte		N04   , Dn4 
	.byte	W04
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N32   , Bn3 
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N08   , Ds4 
	.byte	W40
	.byte		        En4 
	.byte	W24
	.byte		        Ds4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        En4 , v032
	.byte	W08
	.byte		        Fs4 , v112
	.byte	W08
	.byte		        Cs4 
	.byte		N08   , Fs4 , v032
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Fs3 , v112
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W08
	.byte		N32   , Bn3 , v112
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N08   , Ds4 
	.byte	W36
	.byte		N04   , Gn4 
	.byte	W04
	.byte		N08   , Gs4 
	.byte	W24
	.byte		        Fs4 
	.byte	W16
	.byte		N04   , Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W08
	.byte		        Gs3 , v112
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        En4 , v032
	.byte	W08
	.byte		N56   , Cs4 , v112
	.byte	W56
	.byte		N08   , Cs4 , v032
	.byte	W24
	.byte		        Gs3 , v088
	.byte	W10
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N04   , Gs3 
	.byte	W08
	.byte		N08   , As3 , v096
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N04   , As3 
	.byte	W08
	.byte		N08   , Bn3 , v112
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		N04   , Bn3 
	.byte	W08
	.byte	PATT
	 .word	mus_friendly_2_000
	.byte		N08   , Cs4 , v112
	.byte	W72
	.byte		        Bn3 
	.byte	W08
	.byte		        Bn3 , v032
	.byte	W08
	.byte		        Cs4 , v112
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W16
	.byte		        Ds4 , v112
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W16
	.byte		        Ds4 , v112
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte		N04   , Ds4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N08   , As4 
	.byte	W08
	.byte	W24
	.byte		        Gn4 
	.byte	W08
	.byte		        Gn4 , v032
	.byte	W16
	.byte		        Ds4 , v112
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W16
	.byte		        Cs4 , v112
	.byte	W08
	.byte		        Cs4 , v032
	.byte	W16
	.byte		N20   , Cs4 , v112
	.byte	W20
	.byte		N04   , Dn4 
	.byte	W04
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W08
	.byte		N24   , Bn3 , v112
	.byte	W24
	.byte		N08   , As3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Bn3 , v032
	.byte	W08
	.byte		N32   , Cs4 , v112
	.byte	W08
	.byte	W24
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W08
	.byte		N24   , Bn3 , v112
	.byte	W24
	.byte		N08   , As3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Bn3 , v032
	.byte	W08
	.byte		        Cs4 , v112
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W16
	.byte		        Ds4 , v112
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W16
	.byte		N16   , Ds4 , v112
	.byte	W16
	.byte		N08   , Dn4 
	.byte	W08
	.byte		N04   , Ds4 
	.byte	W08
	.byte		N08   , Dn4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        As4 , v032
	.byte	W24
	.byte		        Gn4 , v112
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N04   , Gn4 
	.byte	W08
	.byte		N08   , Gs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		N04   , Gs4 
	.byte	W08
	.byte		N08   , As4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		N04   , As4 
	.byte	W08
	.byte		N24   
	.byte	W24
	.byte		N08   , Bn4 
	.byte	W08
	.byte		        Bn4 , v032
	.byte	W08
	.byte		        Gs4 , v112
	.byte	W08
	.byte		        Gs4 , v032
	.byte	W16
	.byte		        Gn4 , v112
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Gs4 , v032
	.byte	W08
	.byte		N32   , As4 , v112
	.byte	W08
	.byte	W24
	.byte		N08   , Bn4 
	.byte	W08
	.byte		        Bn4 , v032
	.byte	W08
	.byte		N24   , Gs4 , v112
	.byte	W24
	.byte		N08   , Cs5 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Bn4 , v032
	.byte	W08
	.byte		        As4 , v112
	.byte	W08
	.byte		BEND  , c_v+0
	.byte		N92   , Bn5 
	.byte	W92
	.byte		N04   , As5 
	.byte	W04
	.byte		N72   , Bn5 
	.byte	W72
	.byte		N08   , Gs5 
	.byte	W08
	.byte		        As5 
	.byte	W08
	.byte		        Bn5 
	.byte	W08
	.byte		N72   , As5 
	.byte	W72
	.byte		N08   , Gs5 
	.byte	W08
	.byte		N04   , As5 
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte		N24   , Fs5 
	.byte	W24
	.byte		N08   , En6 
	.byte	W08
	.byte		        Cs6 
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte		        As5 
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte	GOTO
	 .word	mus_friendly_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_friendly_3:
	.byte	KEYSH , mus_friendly_key+0
	.byte		VOICE , 35
	.byte		VOL   , 85*mus_friendly_mvl/mxv
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_friendly_3_B1:
mus_friendly_3_000:
	.byte		PAN   , c_v+0
	.byte		N08   , Bn0 , v127
	.byte	W08
	.byte		        Bn0 , v032
	.byte	W16
	.byte		PAN   , c_v-32
	.byte		N08   , Ds3 , v048
	.byte	W08
	.byte		        Ds3 , v016
	.byte	W08
	.byte		N04   , Bn2 , v048
	.byte	W04
	.byte		        Bn2 , v016
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N08   , Bn0 , v120
	.byte	W08
	.byte		        Bn0 , v032
	.byte	W16
	.byte		PAN   , c_v-32
	.byte		N04   , Ds3 , v048
	.byte	W04
	.byte		N08   , Ds3 , v016
	.byte	W20
	.byte	PEND
	.byte		PAN   , c_v+0
	.byte		N08   , Bn0 , v127
	.byte	W08
	.byte		        Bn0 , v032
	.byte	W08
	.byte		N04   , Bn0 , v112
	.byte	W04
	.byte		        Bn0 , v032
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N08   , Ds3 , v048
	.byte	W08
	.byte		        Ds3 , v016
	.byte	W08
	.byte		N04   , Bn2 , v048
	.byte	W04
	.byte		        Bn2 , v016
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N08   , Bn0 , v120
	.byte	W08
	.byte		        Bn0 , v032
	.byte	W16
	.byte		PAN   , c_v-32
	.byte		N04   , Ds3 , v048
	.byte	W04
	.byte		N08   , Ds3 , v016
	.byte	W20
	.byte		PAN   , c_v+0
	.byte		N08   , Bn0 , v127
	.byte	W08
	.byte		        Bn0 , v032
	.byte	W16
	.byte		PAN   , c_v-32
	.byte		N08   , Ds3 , v048
	.byte	W08
	.byte		        Ds3 , v016
	.byte	W08
	.byte		N04   , Bn2 , v064
	.byte	W04
	.byte		        Bn2 , v032
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N08   , Bn0 , v120
	.byte	W08
	.byte		        Bn0 , v032
	.byte	W16
	.byte		PAN   , c_v-32
	.byte		N04   , Ds3 , v048
	.byte	W04
	.byte		N08   , Ds3 , v016
	.byte	W20
	.byte		PAN   , c_v+0
	.byte		N08   , Bn0 , v127
	.byte	W08
	.byte		        Bn0 , v032
	.byte	W08
	.byte		N04   , Bn0 , v112
	.byte	W04
	.byte		        Bn0 , v032
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N08   , Ds3 , v048
	.byte	W08
	.byte		        Ds3 , v016
	.byte	W08
	.byte		N04   , Bn2 , v064
	.byte	W04
	.byte		        Bn2 , v032
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N08   , Bn0 , v120
	.byte	W08
	.byte		        Bn0 , v032
	.byte	W16
	.byte		PAN   , c_v-32
	.byte		N04   , Ds3 , v048
	.byte	W04
	.byte		N08   , Ds3 , v016
	.byte	W20
	.byte		PAN   , c_v+0
	.byte		N08   , En1 , v127
	.byte	W08
	.byte		        En1 , v032
	.byte	W16
	.byte		PAN   , c_v-32
	.byte		N08   , Gs3 , v052
	.byte	W08
	.byte		        Gs3 , v016
	.byte	W08
	.byte		N04   , Bn2 , v048
	.byte	W04
	.byte		        Bn2 , v016
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N08   , En1 , v120
	.byte	W08
	.byte		        En1 , v032
	.byte	W16
	.byte		PAN   , c_v-32
	.byte		N04   , Gs3 , v048
	.byte	W04
	.byte		        Gs3 , v016
	.byte	W04
	.byte		        En3 , v048
	.byte	W04
	.byte		        En3 , v016
	.byte	W04
	.byte		        Gs3 , v048
	.byte	W04
	.byte		        Gs3 , v016
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N08   , Cs1 , v127
	.byte	W08
	.byte		        Cs1 , v032
	.byte	W08
	.byte		N04   , Cs1 , v108
	.byte	W04
	.byte		        Cs1 , v032
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N08   , En3 , v048
	.byte	W08
	.byte		        En3 , v016
	.byte	W08
	.byte		N04   , Bn2 , v048
	.byte	W04
	.byte		        Bn2 , v016
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N08   , Cs1 , v120
	.byte	W08
	.byte		        Cs1 , v032
	.byte	W16
	.byte		PAN   , c_v-32
	.byte		N04   , En3 , v048
	.byte	W04
	.byte		N08   , En3 , v016
	.byte	W20
mus_friendly_3_001:
	.byte		PAN   , c_v+0
	.byte		N08   , Fs1 , v127
	.byte	W08
	.byte		        Fs1 , v032
	.byte	W16
	.byte		PAN   , c_v-32
	.byte		N08   , Cs3 , v048
	.byte	W08
	.byte		        Cs3 , v016
	.byte	W08
	.byte		N04   , Cs3 , v048
	.byte	W04
	.byte		        Cs3 , v016
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N08   , Fs1 , v120
	.byte	W08
	.byte		        Fs1 , v032
	.byte	W16
	.byte		PAN   , c_v-32
	.byte		N04   , Cs3 , v048
	.byte	W04
	.byte		N08   , Cs3 , v016
	.byte	W20
	.byte	PEND
	.byte		PAN   , c_v+0
	.byte		N08   , Fs1 , v127
	.byte	W08
	.byte		        Fs1 , v032
	.byte	W08
	.byte		N04   , Fs1 , v100
	.byte	W04
	.byte		        Fs1 , v032
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , As3 , v080
	.byte	W04
	.byte		        As3 , v032
	.byte	W04
	.byte		        Fs3 , v072
	.byte	W04
	.byte		        Fs3 , v032
	.byte	W04
	.byte		        As3 , v080
	.byte	W04
	.byte		        As3 , v032
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N08   , Fs1 , v120
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N08   , As3 , v084
	.byte	W08
	.byte		        As3 , v032
	.byte	W08
	.byte		N04   , Bn3 , v084
	.byte	W04
	.byte		N08   , Bn3 , v032
	.byte	W12
	.byte		N04   , Cs4 , v084
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte	PATT
	 .word	mus_friendly_3_000
	.byte		PAN   , c_v+0
	.byte		N08   , Bn0 , v127
	.byte	W08
	.byte		        Bn0 , v032
	.byte	W08
	.byte		N04   , Bn0 , v116
	.byte	W04
	.byte		        Bn0 , v032
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N08   , Ds3 , v052
	.byte	W08
	.byte		        Ds3 , v016
	.byte	W08
	.byte		N04   , Bn2 , v048
	.byte	W04
	.byte		        Bn2 , v016
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N08   , Bn0 , v120
	.byte	W08
	.byte		        Bn0 , v032
	.byte	W16
	.byte		PAN   , c_v-32
	.byte		N04   , Ds3 , v048
	.byte	W04
	.byte		N08   , Ds3 , v016
	.byte	W20
	.byte	PATT
	 .word	mus_friendly_3_000
	.byte		PAN   , c_v+0
	.byte		N08   , Bn0 , v127
	.byte	W08
	.byte		        Bn0 , v032
	.byte	W08
	.byte		N04   , Bn0 , v116
	.byte	W04
	.byte		        Bn0 , v032
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N08   , Ds3 , v048
	.byte	W08
	.byte		        Ds3 , v016
	.byte	W08
	.byte		N04   , Bn2 , v048
	.byte	W04
	.byte		        Bn2 , v016
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N08   , Bn0 , v120
	.byte	W08
	.byte		        Bn0 , v032
	.byte	W16
	.byte		PAN   , c_v-32
	.byte		N04   , Ds3 , v048
	.byte	W04
	.byte		N08   , Ds3 , v016
	.byte	W20
	.byte		PAN   , c_v+0
	.byte		N08   , En1 , v127
	.byte	W08
	.byte		        En1 , v032
	.byte	W16
	.byte		PAN   , c_v-32
	.byte		N08   , Gs3 , v048
	.byte	W08
	.byte		        Gs3 , v016
	.byte	W08
	.byte		N04   , Bn2 , v048
	.byte	W04
	.byte		        Bn2 , v016
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N08   , En1 , v120
	.byte	W08
	.byte		        En1 , v032
	.byte	W16
	.byte		PAN   , c_v-32
	.byte		N04   , Gs3 , v048
	.byte	W04
	.byte		        Gs3 , v016
	.byte	W04
	.byte		        En3 , v048
	.byte	W04
	.byte		        En3 , v016
	.byte	W04
	.byte		        Gs3 , v048
	.byte	W04
	.byte		        Gs3 , v016
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N08   , Cs1 , v127
	.byte	W08
	.byte		        Cs1 , v032
	.byte	W08
	.byte		N04   , Cs1 , v120
	.byte	W04
	.byte		        Cs1 , v032
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N08   , En3 , v048
	.byte	W08
	.byte		        En3 , v016
	.byte	W08
	.byte		N04   , Bn2 , v048
	.byte	W04
	.byte		        Bn2 , v016
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N08   , Cs1 , v127
	.byte	W08
	.byte		        Cs1 , v032
	.byte	W16
	.byte		PAN   , c_v-32
	.byte		N04   , En3 , v048
	.byte	W04
	.byte		N08   , En3 , v016
	.byte	W20
	.byte	PATT
	 .word	mus_friendly_3_001
	.byte		PAN   , c_v+0
	.byte		N08   , Fs1 , v127
	.byte	W08
	.byte		        Fs1 , v032
	.byte	W08
	.byte		N04   , Fs1 , v096
	.byte	W04
	.byte		        Fs1 , v032
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , As3 , v080
	.byte	W04
	.byte		        As3 , v032
	.byte	W04
	.byte		        Fs3 , v072
	.byte	W04
	.byte		        Fs3 , v032
	.byte	W04
	.byte		        As3 , v076
	.byte	W04
	.byte		        As3 , v032
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N08   , Fs1 , v120
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N08   , As3 , v080
	.byte	W08
	.byte		        As3 , v032
	.byte	W08
	.byte		N04   , Bn3 , v080
	.byte	W04
	.byte		N08   , Bn3 , v032
	.byte	W12
	.byte		N04   , Cs4 , v080
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N08   , Ds1 , v127
	.byte	W08
	.byte		        Ds1 , v032
	.byte	W16
	.byte		        Ds1 , v120
	.byte	W08
	.byte		        Ds1 , v032
	.byte	W16
	.byte		N24   , As0 , v116
	.byte	W24
	.byte		N08   , As0 , v032
	.byte	W16
	.byte		        Ds1 , v124
	.byte	W08
	.byte		        Ds1 , v032
	.byte	W16
	.byte		        Ds1 , v112
	.byte	W08
	.byte		        Ds1 , v032
	.byte	W16
	.byte		        Ds1 , v112
	.byte	W08
	.byte		        Gn1 , v120
	.byte	W08
	.byte		        Gn1 , v032
	.byte	W08
	.byte		        Ds1 , v112
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		        Cs1 , v032
	.byte	W08
	.byte		        As0 , v112
	.byte	W08
	.byte		N16   , Gs1 , v127
	.byte	W16
	.byte		N08   , Bn1 , v112
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        Ds2 , v032
	.byte	W08
	.byte		N24   , Gn1 , v120
	.byte	W24
	.byte		N08   , Bn1 , v112
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        Ds2 , v032
	.byte	W16
	.byte		N16   , Fs1 , v127
	.byte	W16
	.byte		N08   , Gs1 , v112
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Fs1 , v032
	.byte	W08
	.byte		N32   , Fn1 , v112
	.byte	W32
	.byte		N08   , Ds1 , v120
	.byte	W08
	.byte		        Ds1 , v032
	.byte	W08
	.byte		        Fs1 , v112
	.byte	W08
	.byte		        Gn1 , v127
	.byte	W08
	.byte		        Gn1 , v032
	.byte	W16
	.byte		        Gn1 , v112
	.byte	W08
	.byte		        Gn1 , v032
	.byte	W16
	.byte		N16   , Ds1 , v112
	.byte	W16
	.byte		N08   , As0 , v120
	.byte	W08
	.byte		        Gn1 , v112
	.byte	W08
	.byte		        Gn1 , v032
	.byte	W08
	.byte		        Ds1 , v124
	.byte	W08
	.byte		        Ds1 , v032
	.byte	W16
	.byte		        As1 , v116
	.byte	W08
	.byte		        As1 , v032
	.byte	W16
	.byte		        As1 , v112
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        Ds2 , v032
	.byte	W08
	.byte		        As1 , v112
	.byte	W08
	.byte		        Gn1 , v120
	.byte	W08
	.byte		        Gn1 , v032
	.byte	W08
	.byte		        Ds1 , v112
	.byte	W08
	.byte		N16   , Gs1 , v127
	.byte	W16
	.byte		N08   , Bn1 , v112
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        Ds2 , v032
	.byte	W08
	.byte		N16   , Gn1 , v120
	.byte	W16
	.byte		N08   , Gn1 , v032
	.byte	W08
	.byte		        Bn1 , v112
	.byte	W08
	.byte		N24   , Ds2 
	.byte	W24
	.byte		N16   , Fs1 , v127
	.byte	W16
	.byte		N08   , Gs1 , v112
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Fs1 , v032
	.byte	W08
	.byte		N32   , Fn1 , v120
	.byte	W32
	.byte		N08   , Ds1 , v112
	.byte	W08
	.byte		        Ds1 , v032
	.byte	W08
	.byte		        Fn1 , v112
	.byte	W08
	.byte		        En1 , v127
	.byte	W08
	.byte		        En1 , v032
	.byte	W08
	.byte		N04   , Bn0 , v112
	.byte	W04
	.byte		        Bn0 , v032
	.byte	W04
	.byte		N08   , En1 , v112
	.byte	W08
	.byte		        En1 , v032
	.byte	W08
	.byte		N04   , Bn0 , v112
	.byte	W04
	.byte		        Bn0 , v032
	.byte	W04
	.byte		N08   , En1 , v120
	.byte	W08
	.byte		        En1 , v032
	.byte	W08
	.byte		N04   , Bn0 , v112
	.byte	W04
	.byte		        Bn0 , v032
	.byte	W04
	.byte		N08   , En1 , v112
	.byte	W08
	.byte		        En1 , v032
	.byte	W08
	.byte		N04   , Bn0 , v112
	.byte	W04
	.byte		        Bn0 , v032
	.byte	W04
	.byte		N08   , Fn1 , v127
	.byte	W08
	.byte		        Fn1 , v032
	.byte	W08
	.byte		N04   , Bn0 , v112
	.byte	W04
	.byte		        Bn0 , v032
	.byte	W04
	.byte		N08   , Fn1 , v112
	.byte	W08
	.byte		        Fn1 , v032
	.byte	W08
	.byte		N04   , Bn0 , v112
	.byte	W04
	.byte		        Bn0 , v032
	.byte	W04
	.byte		N08   , Fn1 , v120
	.byte	W08
	.byte		        Fn1 , v032
	.byte	W08
	.byte		N04   , Bn0 , v112
	.byte	W04
	.byte		        Bn0 , v032
	.byte	W04
	.byte		N08   , Fn1 , v112
	.byte	W08
	.byte		        Fn1 , v032
	.byte	W08
	.byte		N04   , Bn0 , v112
	.byte	W04
	.byte		        Bn0 , v032
	.byte	W04
	.byte		N08   , Fs1 , v127
	.byte	W08
	.byte		        Fs1 , v032
	.byte	W08
	.byte		N04   , Cs1 , v112
	.byte	W04
	.byte		        Cs1 , v032
	.byte	W04
	.byte		N08   , Fs1 , v112
	.byte	W08
	.byte		        Fs1 , v032
	.byte	W08
	.byte		N04   , Cs1 , v112
	.byte	W04
	.byte		        Cs1 , v032
	.byte	W04
	.byte		N08   , Fs1 , v120
	.byte	W08
	.byte		        Fs1 , v032
	.byte	W08
	.byte		N04   , Cs1 , v112
	.byte	W04
	.byte		        Cs1 , v032
	.byte	W04
	.byte		N08   , Fs1 , v112
	.byte	W08
	.byte		        Fs1 , v032
	.byte	W08
	.byte		N04   , Cs1 , v112
	.byte	W04
	.byte		        Cs1 , v032
	.byte	W04
	.byte		N08   , Fs1 , v127
	.byte	W08
	.byte		        Fs1 , v032
	.byte	W08
	.byte		N04   , Fs1 , v112
	.byte	W04
	.byte		        Fs1 , v032
	.byte	W04
	.byte		N08   , En1 , v112
	.byte	W08
	.byte		        En1 , v032
	.byte	W08
	.byte		N04   , Cs1 , v112
	.byte	W04
	.byte		        Cs1 , v032
	.byte	W04
	.byte		N08   , As0 , v120
	.byte	W08
	.byte		        As0 , v032
	.byte	W08
	.byte		N04   , Gs0 , v112
	.byte	W04
	.byte		        Gs0 , v032
	.byte	W04
	.byte		N08   , Fs0 , v112
	.byte	W08
	.byte		        Fs0 , v032
	.byte	W08
	.byte		        As0 , v112
	.byte	W08
	.byte	GOTO
	 .word	mus_friendly_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_friendly_4:
	.byte	KEYSH , mus_friendly_key+0
	.byte		VOICE , 46
	.byte		PAN   , c_v+0
	.byte		VOL   , 43*mus_friendly_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_friendly_4_B1:
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
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
	.byte	W96
	.byte		N04   , Bn2 , v112
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Fn5 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		PAN   , c_v+63
	.byte		BEND  , c_v+4
	.byte	W24
	.byte		N08   , En6 , v056
	.byte	W08
	.byte		        Cs6 
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte		        As5 
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte	GOTO
	 .word	mus_friendly_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_friendly_5:
	.byte	KEYSH , mus_friendly_key+0
	.byte		VOICE , 80
	.byte		PAN   , c_v-64
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 54*mus_friendly_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W40
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 12
	.byte	W56
	.byte	W96
mus_friendly_5_B1:
	.byte	W24
	.byte		N08   , Fs3 , v112
	.byte	W08
	.byte		        Fs3 , v032
	.byte	W08
	.byte		N04   , Ds3 , v112
	.byte	W04
	.byte		        Ds3 , v032
	.byte	W28
	.byte		        Fs3 , v112
	.byte	W04
	.byte		N08   , Fs3 , v032
	.byte	W20
mus_friendly_5_000:
	.byte	W24
	.byte		N08   , Gn3 , v112
	.byte	W08
	.byte		        Gn3 , v032
	.byte	W08
	.byte		N04   , Ds3 , v112
	.byte	W04
	.byte		        Ds3 , v032
	.byte	W28
	.byte		        Gn3 , v112
	.byte	W04
	.byte		        Gn3 , v032
	.byte	W20
	.byte	PEND
mus_friendly_5_001:
	.byte	W24
	.byte		N08   , Gs3 , v112
	.byte	W08
	.byte		        Gs3 , v032
	.byte	W08
	.byte		N04   , Ds3 , v112
	.byte	W04
	.byte		        Ds3 , v032
	.byte	W28
	.byte		        Gs3 , v112
	.byte	W04
	.byte		        Gs3 , v032
	.byte	W20
	.byte	PEND
mus_friendly_5_002:
	.byte	W24
	.byte		N08   , An3 , v112
	.byte	W08
	.byte		        An3 , v032
	.byte	W08
	.byte		N04   , Ds3 , v112
	.byte	W04
	.byte		        Ds3 , v032
	.byte	W28
	.byte		        An3 , v112
	.byte	W04
	.byte		        An3 , v032
	.byte	W20
	.byte	PEND
mus_friendly_5_003:
	.byte	W24
	.byte		N08   , Bn3 , v112
	.byte	W08
	.byte		        Bn3 , v032
	.byte	W08
	.byte		N04   , Gs3 , v112
	.byte	W04
	.byte		        Gs3 , v032
	.byte	W28
	.byte		        Bn3 , v112
	.byte	W04
	.byte		        Bn3 , v032
	.byte	W04
	.byte		        Gs3 , v112
	.byte	W04
	.byte		        Gs3 , v032
	.byte	W04
	.byte		        Bn3 , v112
	.byte	W04
	.byte		        Bn3 , v032
	.byte	W04
	.byte	PEND
	.byte	W24
	.byte		N08   , Gs3 , v112
	.byte	W08
	.byte		N04   , Gs3 , v032
	.byte	W08
	.byte		        En3 , v112
	.byte	W04
	.byte		        En3 , v032
	.byte	W28
	.byte		        Gs3 , v112
	.byte	W04
	.byte		        Gs3 , v032
	.byte	W20
	.byte	W24
	.byte		N08   , As3 , v112
	.byte	W08
	.byte		N04   , As3 , v032
	.byte	W08
	.byte		        Fs3 , v112
	.byte	W04
	.byte		        Fs3 , v032
	.byte	W28
	.byte		        As3 , v112
	.byte	W04
	.byte		        As3 , v032
	.byte	W20
	.byte		VOL   , 54*mus_friendly_mvl/mxv
	.byte	W24
	.byte		N04   , Cs4 , v112
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		        Bn3 , v112
	.byte	W04
	.byte		        Bn3 , v032
	.byte	W04
	.byte		        Cs4 , v112
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W12
	.byte		N08   , Ds4 , v112
	.byte	W08
	.byte		N04   , Ds4 , v032
	.byte	W08
	.byte		        En4 , v112
	.byte	W04
	.byte		        En4 , v032
	.byte	W12
	.byte		        Fs4 , v112
	.byte	W04
	.byte		        Fs4 , v032
	.byte	W04
	.byte		VOL   , 54*mus_friendly_mvl/mxv
	.byte	W24
	.byte		N08   , Fs3 , v112
	.byte	W08
	.byte		        Fs3 , v032
	.byte	W08
	.byte		N04   , Ds3 , v112
	.byte	W04
	.byte		        Ds3 , v032
	.byte	W28
	.byte		        Fs3 , v112
	.byte	W04
	.byte		N08   , Fs3 , v032
	.byte	W20
	.byte	PATT
	 .word	mus_friendly_5_000
	.byte	PATT
	 .word	mus_friendly_5_001
	.byte	PATT
	 .word	mus_friendly_5_002
	.byte	PATT
	 .word	mus_friendly_5_003
	.byte	W24
	.byte		N08   , Gs3 , v112
	.byte	W08
	.byte		        Gs3 , v032
	.byte	W08
	.byte		N04   , En3 , v112
	.byte	W04
	.byte		        En3 , v032
	.byte	W28
	.byte		        Gs3 , v112
	.byte	W04
	.byte		        Gs3 , v032
	.byte	W20
	.byte	W24
	.byte		N08   , As3 , v112
	.byte	W08
	.byte		        As3 , v032
	.byte	W08
	.byte		N04   , Fs3 , v112
	.byte	W04
	.byte		        Fs3 , v032
	.byte	W28
	.byte		        As3 , v112
	.byte	W04
	.byte		        As3 , v032
	.byte	W20
	.byte	W24
	.byte		        Cs4 , v112
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		        Bn3 , v112
	.byte	W04
	.byte		        Bn3 , v032
	.byte	W04
	.byte		        Cs4 , v112
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W12
	.byte		N08   , Ds4 , v112
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W08
	.byte		N04   , En4 , v112
	.byte	W04
	.byte		        En4 , v032
	.byte	W12
	.byte		        Fs4 , v112
	.byte	W04
	.byte		        Fs4 , v032
	.byte	W04
	.byte		N08   , As3 , v112
	.byte	W08
	.byte		        As3 , v032
	.byte	W16
	.byte		        As3 , v112
	.byte	W08
	.byte		        As3 , v032
	.byte	W16
	.byte		N16   , As3 , v112
	.byte	W16
	.byte		N08   , Fs3 
	.byte	W08
	.byte		N04   , As3 
	.byte	W04
	.byte		        As3 , v032
	.byte	W04
	.byte		        Gn3 , v112
	.byte	W04
	.byte		        Gn3 , v032
	.byte	W04
	.byte		N08   , Ds4 , v112
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W24
	.byte		        As3 , v112
	.byte	W08
	.byte		        As3 , v032
	.byte	W16
	.byte		        Gn3 , v112
	.byte	W08
	.byte		        Gn3 , v032
	.byte	W16
	.byte		        Ds3 , v112
	.byte	W08
	.byte		        Ds3 , v032
	.byte	W16
	.byte		        Gs3 , v112
	.byte	W08
	.byte		        Gs3 , v032
	.byte	W08
	.byte		        Gn3 , v112
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Gs3 , v032
	.byte	W08
	.byte		        As3 , v112
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Bn3 , v032
	.byte	W08
	.byte		        As3 , v112
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Bn3 , v032
	.byte	W08
	.byte		        Cs4 , v112
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W08
	.byte		        Dn4 , v112
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W08
	.byte		N24   , Gs4 , v112
	.byte	W08
	.byte		MOD   , 7
	.byte	W16
	.byte		        0
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        As3 , v032
	.byte	W16
	.byte		        As3 , v112
	.byte	W08
	.byte		        As3 , v032
	.byte	W16
	.byte		N16   , As3 , v112
	.byte	W16
	.byte		N08   , Fs3 
	.byte	W08
	.byte		N04   , As3 
	.byte	W04
	.byte		        As3 , v032
	.byte	W04
	.byte		        Fs3 , v112
	.byte	W04
	.byte		        Fs3 , v032
	.byte	W04
	.byte		N08   , Ds4 , v112
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W24
	.byte		        As3 , v112
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N04   , As3 
	.byte	W04
	.byte		        As3 , v032
	.byte	W04
	.byte		N08   , Bn3 , v112
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		N04   , Bn3 
	.byte	W04
	.byte		        Bn3 , v032
	.byte	W04
	.byte		N08   , Cs4 , v112
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N04   , Cs4 
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		N24   , Cs4 , v112
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W08
	.byte		        Bn3 , v112
	.byte	W08
	.byte		        Bn3 , v032
	.byte	W16
	.byte		        As3 , v112
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Bn3 , v032
	.byte	W08
	.byte		N32   , Cs4 , v112
	.byte	W08
	.byte	W08
	.byte		MOD   , 8
	.byte	W16
	.byte		        0
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W08
	.byte		N24   , Bn3 , v112
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N08   , En4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W08
	.byte		        Cs4 , v112
	.byte	W08
	.byte		BEND  , c_v+1
	.byte		N04   , Bn2 , v064
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Fn5 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		BEND  , c_v+0
	.byte	W24
	.byte		N08   , En6 , v056
	.byte	W08
	.byte		        Cs6 
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte		        As5 
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte	GOTO
	 .word	mus_friendly_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_friendly_6:
	.byte	KEYSH , mus_friendly_key+0
	.byte		VOICE , 83
	.byte		PAN   , c_v+63
	.byte		XCMD  , xIECV , 12
	.byte		        xIECL , 8
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 32*mus_friendly_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_friendly_6_B1:
mus_friendly_6_000:
	.byte	W48
	.byte		N08   , Ds5 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte	PEND
	.byte	W96
	.byte	PATT
	 .word	mus_friendly_6_000
	.byte	W96
	.byte	W48
	.byte		N08   , En5 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		N48   , Bn4 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N24   , As4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		N40   , Fs4 
	.byte	W24
	.byte		MOD   , 4
	.byte	W16
	.byte		        0
	.byte		N04   , Gs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		N48   , Gs4 
	.byte	W24
	.byte		MOD   , 4
	.byte	W24
	.byte		        0
	.byte		N08   , As4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        Fs5 
	.byte	W56
mus_friendly_6_001:
	.byte	W48
	.byte		N08   , Bn5 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Bn5 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte	PEND
	.byte	W96
	.byte	PATT
	 .word	mus_friendly_6_001
	.byte	W96
	.byte	W48
	.byte		N08   , En6 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Ds6 
	.byte	W08
	.byte		        Cs6 
	.byte	W08
	.byte		N48   , Gs5 
	.byte	W24
	.byte		MOD   , 4
	.byte	W24
	.byte		        0
	.byte		N24   , Bn5 , v108
	.byte	W24
	.byte		        Gs5 , v112
	.byte	W24
	.byte		N40   , As5 
	.byte	W24
	.byte		MOD   , 4
	.byte	W16
	.byte		        0
	.byte		N04   , Bn5 
	.byte	W04
	.byte		        As5 
	.byte	W04
	.byte		N48   , Gs5 
	.byte	W24
	.byte		MOD   , 4
	.byte	W24
	.byte		        0
	.byte		N08   , As5 
	.byte	W16
	.byte		        Bn5 
	.byte	W08
	.byte		        Cs6 
	.byte	W16
	.byte		        Ds6 
	.byte	W08
	.byte		        En6 
	.byte	W48
	.byte	W96
	.byte		N04   , Ds5 
	.byte	W08
	.byte		        Ds6 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		        Ds6 
	.byte	W16
	.byte		        Ds5 
	.byte	W08
	.byte		        Ds6 
	.byte	W16
	.byte		        Ds5 
	.byte	W08
	.byte		        Ds6 
	.byte	W16
	.byte		        Ds5 
	.byte	W08
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N08   
	.byte	W08
	.byte		N04   , Ds6 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		        Ds6 
	.byte	W16
	.byte		        Ds5 
	.byte	W08
	.byte		        Ds6 
	.byte	W16
	.byte		        Ds5 
	.byte	W08
	.byte		        Ds6 
	.byte	W16
	.byte		        Ds5 
	.byte	W08
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_friendly_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_friendly_7:
	.byte	KEYSH , mus_friendly_key+0
	.byte		VOICE , 1
	.byte		PAN   , c_v+63
	.byte		VOL   , 45*mus_friendly_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N12   , Ds6 , v120
	.byte	W09
	.byte		PAN   , c_v+62
	.byte	W03
	.byte		        c_v+60
	.byte		N03   , Bn5 , v108
	.byte	W02
	.byte		PAN   , c_v+55
	.byte	W01
	.byte		N03   , An5 
	.byte	W02
	.byte		PAN   , c_v+52
	.byte	W01
	.byte		N03   , Gn5 , v100
	.byte	W02
	.byte		PAN   , c_v+42
	.byte	W01
	.byte		N03   , Fn5 
	.byte	W03
	.byte		PAN   , c_v+35
	.byte		N03   , En5 , v096
	.byte	W02
	.byte		PAN   , c_v+32
	.byte	W01
	.byte		N03   , Dn5 
	.byte	W02
	.byte		PAN   , c_v+26
	.byte	W01
	.byte		N03   , Cn5 
	.byte	W02
	.byte		PAN   , c_v+21
	.byte	W01
	.byte		N03   , Bn4 
	.byte	W03
	.byte		PAN   , c_v+16
	.byte		N03   , An4 
	.byte	W02
	.byte		PAN   , c_v+12
	.byte	W01
	.byte		N03   , Gn4 
	.byte	W02
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N03   , Fn4 , v092
	.byte	W02
	.byte		PAN   , c_v-9
	.byte	W01
	.byte		N03   , En4 
	.byte	W03
	.byte		PAN   , c_v-11
	.byte		N03   , Dn4 
	.byte	W02
	.byte		PAN   , c_v-18
	.byte	W01
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Gn3 , v088
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        Bn2 
	.byte	W21
mus_friendly_7_B1:
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
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_friendly_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_friendly_8:
	.byte	KEYSH , mus_friendly_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 81*mus_friendly_mvl/mxv
	.byte		N04   , Cn1 , v112
	.byte		N04   , Fs1 
	.byte	W08
	.byte		        Fs1 , v060
	.byte	W08
	.byte		        Fs1 , v112
	.byte	W08
	.byte		        En1 
	.byte		N04   , Fs2 
	.byte	W16
	.byte		        Fs1 , v068
	.byte	W08
	.byte		        Cn1 , v112
	.byte		N04   , Fs1 
	.byte	W16
	.byte		        Fs1 , v064
	.byte	W08
	.byte		        En1 , v112
	.byte		N04   , Fs2 
	.byte	W08
	.byte		        Fs1 , v064
	.byte	W08
	.byte		        Cn1 , v112
	.byte		N04   , Fs1 
	.byte	W08
	.byte		        Cn1 
	.byte		N04   , Fs1 
	.byte	W08
	.byte		        Fs1 , v060
	.byte	W08
	.byte		        Cn1 , v112
	.byte		N04   , Fs1 
	.byte	W08
	.byte		        En1 
	.byte		N04   , Fs2 
	.byte	W16
	.byte		        Cn1 
	.byte		N04   , Fs1 , v068
	.byte	W08
	.byte		        Cn1 , v112
	.byte		N04   , Fs1 
	.byte	W16
	.byte		        En1 , v080
	.byte		N04   , Fs1 , v064
	.byte	W08
	.byte		        En1 , v112
	.byte		N04   , Fs2 
	.byte	W08
	.byte		        Fs1 , v064
	.byte	W08
	.byte		        Cn1 , v112
	.byte		N04   , Fs1 
	.byte	W08
	.byte		        Cn1 
	.byte		N04   , Fs1 
	.byte	W08
	.byte		        Fs1 , v060
	.byte	W08
	.byte		        Fs1 , v112
	.byte	W08
	.byte		        En1 
	.byte		N04   , Fs2 
	.byte	W16
	.byte		        Fs1 , v068
	.byte	W08
	.byte		        Cn1 , v112
	.byte		N04   , Fs1 
	.byte	W16
	.byte		        Fs1 , v064
	.byte	W08
	.byte		        En1 , v112
	.byte		N04   , Fs2 
	.byte	W08
	.byte		        Fs1 , v064
	.byte	W08
	.byte		        Cn1 , v112
	.byte		N04   , Fs1 
	.byte	W08
	.byte		        En1 
	.byte		N04   , Fs1 
	.byte	W08
	.byte		        Fs1 , v060
	.byte	W08
	.byte		        En1 , v112
	.byte		N04   , Fs1 
	.byte	W08
	.byte		        Cn1 
	.byte		N04   , Fs2 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        En1 
	.byte		N04   , Fs1 , v068
	.byte	W08
	.byte		        Cn1 
	.byte		N04   , Fs1 , v112
	.byte	W16
	.byte		        En1 
	.byte		N04   , Fs1 , v064
	.byte	W08
	.byte		        Cn1 , v112
	.byte		N04   , Fs2 
	.byte	W08
	.byte		        Cn1 
	.byte		N04   , Fs1 , v064
	.byte	W04
	.byte		        Cn1 , v080
	.byte	W04
	.byte		        En1 , v112
	.byte		N04   , Fs1 
	.byte	W08
mus_friendly_8_B1:
	.byte		VOL   , 73*mus_friendly_mvl/mxv
	.byte		N04   , Cn1 , v112
	.byte		N48   , An2 
	.byte	W24
	.byte		N04   , En1 
	.byte	W24
	.byte		        Cn1 
	.byte		N04   , Fs1 
	.byte	W16
	.byte		        Fs1 , v064
	.byte	W08
	.byte		        En1 , v112
	.byte		N04   , Fs2 
	.byte	W08
	.byte		        Fs1 , v064
	.byte	W08
	.byte		        Cn1 , v112
	.byte		N04   , Fs2 , v080
	.byte	W08
mus_friendly_8_000:
	.byte		N04   , Cn1 , v112
	.byte		N04   , Fs1 
	.byte	W08
	.byte		        Fs1 , v060
	.byte	W08
	.byte		        Cn1 , v112
	.byte		N04   , Fs1 
	.byte	W08
	.byte		        En1 
	.byte		N04   , Fs1 
	.byte	W16
	.byte		        Fs1 , v068
	.byte	W08
	.byte		        Cn1 , v112
	.byte		N04   , Fs1 
	.byte	W16
	.byte		        Fs1 , v064
	.byte	W08
	.byte		        En1 , v112
	.byte		N04   , Fs2 
	.byte	W08
	.byte		        Fs1 , v064
	.byte	W08
	.byte		        Cn1 , v112
	.byte		N04   , Fs1 
	.byte	W08
	.byte	PEND
mus_friendly_8_001:
	.byte		N04   , Cn1 , v112
	.byte		N04   , Fs1 
	.byte	W08
	.byte		        Fs1 , v060
	.byte	W08
	.byte		        Fs1 , v112
	.byte	W08
	.byte		        En1 
	.byte		N04   , Fs1 
	.byte	W16
	.byte		        Fs1 , v068
	.byte	W08
	.byte		        Cn1 , v112
	.byte		N04   , Fs1 
	.byte	W16
	.byte		        Fs1 , v064
	.byte	W08
	.byte		        En1 , v112
	.byte		N04   , Fs2 
	.byte	W08
	.byte		        Fs1 , v064
	.byte	W08
	.byte		        Cn1 , v112
	.byte		N04   , Fs2 , v080
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_friendly_8_000
	.byte	PATT
	 .word	mus_friendly_8_001
mus_friendly_8_002:
	.byte		N04   , Cn1 , v112
	.byte		N04   , Fs1 
	.byte	W08
	.byte		        Fs1 , v060
	.byte	W08
	.byte		        Cn1 , v112
	.byte		N04   , Fs1 
	.byte	W08
	.byte		        En1 
	.byte		N04   , Fs1 
	.byte	W16
	.byte		        Cn1 
	.byte		N04   , Fs1 , v068
	.byte	W08
	.byte		        Cn1 , v112
	.byte		N04   , Fs1 
	.byte	W16
	.byte		        Fs1 , v064
	.byte	W08
	.byte		        En1 , v112
	.byte		N04   , Fs2 
	.byte	W08
	.byte		        Fs1 , v064
	.byte	W08
	.byte		        Cn1 , v112
	.byte		N04   , Fs1 
	.byte	W08
	.byte	PEND
mus_friendly_8_003:
	.byte		N04   , Cn1 , v112
	.byte		N04   , Fs1 
	.byte	W08
	.byte		        Fs1 , v060
	.byte	W08
	.byte		        Fs1 , v112
	.byte	W08
	.byte		        En1 
	.byte		N48   , An2 
	.byte	W24
	.byte		N04   , Cn1 
	.byte	W24
	.byte		        En1 
	.byte		N48   , An2 
	.byte	W16
	.byte		N04   , Cn1 
	.byte	W08
	.byte	PEND
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En1 
	.byte		N48   , An2 
	.byte	W08
	.byte		N04   , En1 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        En1 
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Cn1 
	.byte		N48   , An2 
	.byte	W24
	.byte		N04   , En1 
	.byte	W24
	.byte		        Cn1 
	.byte		N04   , Fs1 
	.byte	W16
	.byte		        Fs1 , v064
	.byte	W08
	.byte		        En1 , v112
	.byte		N04   , Fs2 
	.byte	W08
	.byte		        Fs1 , v064
	.byte	W08
	.byte		        Cn1 , v112
	.byte		N04   , Fs2 , v080
	.byte	W08
	.byte	PATT
	 .word	mus_friendly_8_002
	.byte	PATT
	 .word	mus_friendly_8_001
	.byte	PATT
	 .word	mus_friendly_8_002
	.byte	PATT
	 .word	mus_friendly_8_001
	.byte	PATT
	 .word	mus_friendly_8_002
	.byte	PATT
	 .word	mus_friendly_8_003
	.byte		N04   , Cn1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En1 
	.byte		N48   , An2 
	.byte	W16
	.byte		N04   , Cn1 
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		N04   
	.byte		N04   , Fs2 
	.byte	W08
	.byte		        En1 
	.byte		N04   , Fs2 , v064
	.byte	W08
	.byte		        Cn1 , v112
	.byte		N04   , Fs1 
	.byte	W08
	.byte		        En1 
	.byte		N04   , Fs2 
	.byte	W16
	.byte		        Cn1 
	.byte		N04   , Fs2 
	.byte	W08
	.byte		        En1 
	.byte		N24   , As1 
	.byte	W16
	.byte		N04   , Cn1 
	.byte	W08
	.byte		        En1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Cn1 
	.byte		N24   , As1 
	.byte	W24
	.byte		N04   , Dn3 , v064
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		        En3 
	.byte	W08
	.byte		N48   , An2 , v112
	.byte		N04   , Dn3 , v064
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		        En3 
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W16
	.byte		        Fs2 , v064
	.byte	W08
	.byte		        Fs2 , v080
	.byte	W16
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Fs2 , v064
	.byte	W16
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Fs2 , v080
	.byte	W16
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Fs2 , v080
	.byte	W04
	.byte		        Fs2 , v072
	.byte	W04
	.byte		        Fs2 , v092
	.byte	W08
	.byte		        Fs2 , v108
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W16
	.byte		        Fs2 , v080
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W16
	.byte		        Fs2 , v080
	.byte	W08
	.byte		        En1 , v112
	.byte		N04   , Fs2 
	.byte	W16
	.byte		        Cn1 
	.byte		N04   , Fs2 
	.byte	W08
	.byte		        En1 
	.byte		N24   , As1 
	.byte	W16
	.byte		N04   , Cn1 
	.byte	W08
	.byte		        En1 
	.byte	W16
	.byte		        Cn1 
	.byte	W08
	.byte		        Fs2 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En1 
	.byte	W04
	.byte		        En1 , v080
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		        En1 , v072
	.byte	W08
	.byte		        En1 , v112
	.byte		N24   , As1 
	.byte	W16
	.byte		N04   , En1 
	.byte	W08
	.byte		N04   
	.byte		N48   , An2 
	.byte	W16
	.byte		N04   , En1 
	.byte	W08
	.byte		        Cn1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Fs2 , v064
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fs2 , v068
	.byte	W16
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Fs2 , v068
	.byte	W16
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Fs2 , v068
	.byte	W16
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Fs2 , v068
	.byte	W16
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Fs2 , v068
	.byte	W16
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Fs2 , v104
	.byte	W04
	.byte		        Fs2 , v072
	.byte	W04
	.byte		        Fs2 , v092
	.byte	W08
	.byte		        Fs2 , v096
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
mus_friendly_8_004:
	.byte		N04   , Fs2 , v068
	.byte	W16
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Fs2 , v068
	.byte	W16
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Fs2 , v068
	.byte	W16
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Fs2 , v068
	.byte	W16
	.byte		        Fs2 , v112
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_friendly_8_004
	.byte	PATT
	 .word	mus_friendly_8_004
	.byte		N04   , Cn1 , v112
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        En1 , v068
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Fs2 
	.byte	W04
	.byte		        Cn1 , v080
	.byte	W04
	.byte		        En1 , v112
	.byte	W08
	.byte	GOTO
	 .word	mus_friendly_8_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_friendly:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_friendly_pri	@ Priority
	.byte	mus_friendly_rev	@ Reverb.

	.word	mus_friendly_grp

	.word	mus_friendly_1
	.word	mus_friendly_2
	.word	mus_friendly_3
	.word	mus_friendly_4
	.word	mus_friendly_5
	.word	mus_friendly_6
	.word	mus_friendly_7
	.word	mus_friendly_8

	.end
