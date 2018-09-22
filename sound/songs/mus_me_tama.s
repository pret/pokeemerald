	.include "MPlayDef.s"

	.equ	mus_me_tama_grp, voicegroup012
	.equ	mus_me_tama_pri, 5
	.equ	mus_me_tama_rev, reverb_set+50
	.equ	mus_me_tama_mvl, 127
	.equ	mus_me_tama_key, 0
	.equ	mus_me_tama_tbs, 1
	.equ	mus_me_tama_exg, 0
	.equ	mus_me_tama_cmp, 1

	.section .rodata
	.global	mus_me_tama
	.align	2

@********************** Track  1 **********************@

mus_me_tama_1:
	.byte	KEYSH , mus_me_tama_key+0
	.byte	W12
	.byte	TEMPO , 140*mus_me_tama_tbs/2
	.byte		VOICE , 48
	.byte		PAN   , c_v-10
	.byte		VOL   , 90*mus_me_tama_mvl/mxv
	.byte		N04   , Cn3 , v076
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Gn3 , v084
	.byte	W08
	.byte		        Bn3 , v076
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		TIE   , Gs4 , v080
	.byte	W96
	.byte	W24
	.byte		VOL   , 77*mus_me_tama_mvl/mxv
	.byte	W08
	.byte		        70*mus_me_tama_mvl/mxv
	.byte	W04
	.byte		        60*mus_me_tama_mvl/mxv
	.byte	W04
	.byte		        46*mus_me_tama_mvl/mxv
	.byte	W04
	.byte		EOT   
	.byte	W04
	.byte		VOL   , 90*mus_me_tama_mvl/mxv
	.byte		N04   , An3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        En5 
	.byte	W04
	.byte		N48   , Fn5 
	.byte	W48
	.byte		N16   , Cs5 
	.byte	W16
	.byte		        Ds5 
	.byte	W16
	.byte		        Fn5 
	.byte	W16
	.byte		N48   , Gs5 
	.byte	W48
	.byte		N16   , Fn5 
	.byte	W16
	.byte		        Ds5 
	.byte	W16
	.byte		        Cs5 
	.byte	W16
	.byte		N96   , Cn5 , v088
	.byte	W96
	.byte		N84   , Cn4 
	.byte	W44
	.byte		VOL   , 86*mus_me_tama_mvl/mxv
	.byte	W08
	.byte		        80*mus_me_tama_mvl/mxv
	.byte	W08
	.byte		        74*mus_me_tama_mvl/mxv
	.byte	W08
	.byte		        65*mus_me_tama_mvl/mxv
	.byte	W08
	.byte		        50*mus_me_tama_mvl/mxv
	.byte	W04
	.byte		        32*mus_me_tama_mvl/mxv
	.byte	W16
	.byte	FINE

@********************** Track  2 **********************@

mus_me_tama_2:
	.byte	KEYSH , mus_me_tama_key+0
	.byte	W12
	.byte		VOICE , 48
	.byte		VOL   , 90*mus_me_tama_mvl/mxv
	.byte		PAN   , c_v-10
	.byte	W04
	.byte		N04   , Dn3 , v076
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        An3 , v088
	.byte	W08
	.byte		        Cn4 , v076
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Gn4 
	.byte	W04
	.byte		VOICE , 60
	.byte		PAN   , c_v+10
	.byte		N96   , Cn4 , v088
	.byte	W96
	.byte		N08   , En4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N24   , En3 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		N96   , Fn4 
	.byte	W96
	.byte		N08   , Gs4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		        Cn4 
	.byte	W16
	.byte		        As3 
	.byte	W16
	.byte		        En3 , v076
	.byte	W16
	.byte		        Gn3 , v080
	.byte	W16
	.byte		        As3 
	.byte	W16
	.byte		        Cn4 , v084
	.byte	W16
	.byte		        En4 , v088
	.byte	W16
	.byte		        Gn4 , v092
	.byte	W16
	.byte		N84   , As4 , v100
	.byte	W44
	.byte		VOL   , 86*mus_me_tama_mvl/mxv
	.byte	W08
	.byte		        80*mus_me_tama_mvl/mxv
	.byte	W08
	.byte		        74*mus_me_tama_mvl/mxv
	.byte	W08
	.byte		        65*mus_me_tama_mvl/mxv
	.byte	W08
	.byte		        50*mus_me_tama_mvl/mxv
	.byte	W04
	.byte		        32*mus_me_tama_mvl/mxv
	.byte	W16
	.byte	FINE

@********************** Track  3 **********************@

mus_me_tama_3:
	.byte	KEYSH , mus_me_tama_key+0
	.byte	W12
	.byte	W48
	.byte		VOICE , 85
	.byte		VOL   , 90*mus_me_tama_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N04   , An5 , v040
	.byte	W08
	.byte		PAN   , c_v-48
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v+48
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N04   , As5 
	.byte	W08
	.byte		PAN   , c_v-48
	.byte		N04   , An5 
	.byte	W08
	.byte		PAN   , c_v+48
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v-48
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v+48
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N04   , As5 
	.byte	W08
	.byte		PAN   , c_v-48
	.byte		N04   , An5 
	.byte	W08
	.byte		PAN   , c_v+48
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v-48
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v+48
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N04   , As5 
	.byte	W08
	.byte		PAN   , c_v-48
	.byte		N04   , An5 
	.byte	W08
	.byte		PAN   , c_v+48
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v-48
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v+48
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N04   , As5 
	.byte	W08
	.byte		PAN   , c_v-48
	.byte		N04   , An5 
	.byte	W08
	.byte		PAN   , c_v+48
	.byte		N04   
	.byte	W08
mus_me_tama_3_000:
	.byte		PAN   , c_v+0
	.byte		N04   , As5 , v040
	.byte	W08
	.byte		PAN   , c_v-48
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v+48
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N04   , Cn6 
	.byte	W08
	.byte		PAN   , c_v-48
	.byte		N04   , As5 
	.byte	W08
	.byte		PAN   , c_v+48
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v-48
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v+48
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N04   , Cn6 
	.byte	W08
	.byte		PAN   , c_v-48
	.byte		N04   , As5 
	.byte	W08
	.byte		PAN   , c_v+48
	.byte		N04   
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_me_tama_3_000
	.byte		VOICE , 83
	.byte		PAN   , c_v-48
	.byte		N16   , Gn3 , v060
	.byte	W16
	.byte		        As3 
	.byte	W16
	.byte		        Cn4 
	.byte	W16
	.byte		        En4 
	.byte	W16
	.byte		        Gn4 
	.byte	W16
	.byte		        As4 
	.byte	W16
	.byte		N84   , Cn5 
	.byte	W44
	.byte		VOL   , 86*mus_me_tama_mvl/mxv
	.byte	W08
	.byte		        80*mus_me_tama_mvl/mxv
	.byte	W08
	.byte		        74*mus_me_tama_mvl/mxv
	.byte	W08
	.byte		        65*mus_me_tama_mvl/mxv
	.byte	W08
	.byte		        50*mus_me_tama_mvl/mxv
	.byte	W04
	.byte		        32*mus_me_tama_mvl/mxv
	.byte	W16
	.byte	FINE

@********************** Track  4 **********************@

mus_me_tama_4:
	.byte	KEYSH , mus_me_tama_key+0
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 13
	.byte	W12
	.byte	W48
	.byte		VOICE , 82
	.byte		PAN   , c_v+0
	.byte		VOL   , 90*mus_me_tama_mvl/mxv
	.byte		N96   , En3 , v052
	.byte	W96
	.byte		N08   , Cn4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		N24   , Cn3 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		N96   , Cs4 
	.byte	W96
	.byte		N08   , Fn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		        Gs3 
	.byte	W16
	.byte		        Fs3 
	.byte	W16
	.byte		PAN   , c_v+48
	.byte		N16   , Cn3 , v060
	.byte	W16
	.byte		        En3 
	.byte	W16
	.byte		        Gn3 
	.byte	W16
	.byte		        As3 
	.byte	W16
	.byte		        Cn4 
	.byte	W16
	.byte		        En4 
	.byte	W16
	.byte		N84   , Gn4 
	.byte	W44
	.byte		VOL   , 86*mus_me_tama_mvl/mxv
	.byte	W08
	.byte		        80*mus_me_tama_mvl/mxv
	.byte	W08
	.byte		        74*mus_me_tama_mvl/mxv
	.byte	W08
	.byte		        65*mus_me_tama_mvl/mxv
	.byte	W08
	.byte		        50*mus_me_tama_mvl/mxv
	.byte	W04
	.byte		        32*mus_me_tama_mvl/mxv
	.byte	W16
	.byte	FINE

@********************** Track  5 **********************@

mus_me_tama_5:
	.byte	KEYSH , mus_me_tama_key+0
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 13
	.byte	W12
	.byte	W48
	.byte		VOICE , 47
	.byte		PAN   , c_v+0
	.byte		VOL   , 90*mus_me_tama_mvl/mxv
	.byte		N04   , An1 , v112
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		PAN   , c_v+31
	.byte		N16   
	.byte	W16
	.byte		PAN   , c_v-33
	.byte		N12   
	.byte	W32
	.byte		PAN   , c_v+31
	.byte		N04   , En2 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N24   , An1 
	.byte	W24
	.byte		BEND  , c_v-5
	.byte		N08   , En2 
	.byte	W08
	.byte		N16   , An1 
	.byte	W16
	.byte		N08   , En2 
	.byte	W08
	.byte		N16   , An1 
	.byte	W16
	.byte		PAN   , c_v+32
	.byte		N08   , En2 
	.byte	W08
	.byte		PAN   , c_v-33
	.byte		N08   , An1 
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N04   , En2 
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		PAN   , c_v-33
	.byte		N08   , An1 
	.byte	W08
	.byte		PAN   , c_v-1
	.byte		N04   , En2 
	.byte	W04
	.byte		        En2 , v092
	.byte	W04
	.byte		        En2 , v100
	.byte	W04
	.byte		        En2 , v112
	.byte	W04
	.byte		        As1 
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		PAN   , c_v+31
	.byte		N16   
	.byte	W16
	.byte		PAN   , c_v-33
	.byte		N12   
	.byte	W32
	.byte		PAN   , c_v+31
	.byte		N04   , Fn2 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N24   , As1 
	.byte	W24
	.byte		N08   , Fn2 
	.byte	W08
	.byte		PAN   , c_v+31
	.byte		N16   , As1 
	.byte	W16
	.byte		PAN   , c_v-33
	.byte		N08   , Fn2 
	.byte	W08
	.byte		N16   , As1 
	.byte	W16
	.byte		N08   , Fn2 
	.byte	W08
	.byte		PAN   , c_v+31
	.byte		N08   , As1 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N04   , Fn2 
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N08   , As1 
	.byte	W08
	.byte		N04   , Fn2 
	.byte	W04
	.byte		        Fn2 , v092
	.byte	W04
	.byte		        Fn2 , v100
	.byte	W04
	.byte		        Fn2 , v112
	.byte	W04
	.byte		        Cn2 
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N16   
	.byte	W16
	.byte		N12   , En2 
	.byte	W16
	.byte		PAN   , c_v+32
	.byte		N04   , As1 
	.byte	W08
	.byte		PAN   , c_v-33
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N04   , Cn2 
	.byte	W04
	.byte		        Cn2 , v084
	.byte	W04
	.byte		        Cn2 , v088
	.byte	W04
	.byte		        Cn2 , v092
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        Cn2 , v096
	.byte	W04
	.byte		        Cn2 , v100
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        Cn2 , v104
	.byte	W04
	.byte		        Cn2 , v108
	.byte	W04
	.byte		N48   , Cn2 , v112
	.byte	W96
	.byte	FINE

@********************** Track  6 **********************@

mus_me_tama_6:
	.byte	KEYSH , mus_me_tama_key+0
	.byte	W12
	.byte	W48
	.byte		VOICE , 88
	.byte		VOL   , 90*mus_me_tama_mvl/mxv
	.byte		N68   , An1 , v072
	.byte	W72
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N96   
	.byte	W96
	.byte		N68   , As1 
	.byte	W72
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N96   
	.byte	W96
	.byte		        Cn2 
	.byte	W96
	.byte		N48   , Cn1 , v080
	.byte	W96
	.byte	FINE

@********************** Track  7 **********************@

mus_me_tama_7:
	.byte	KEYSH , mus_me_tama_key+0
	.byte	W12
	.byte	W48
	.byte		VOICE , 0
	.byte		VOL   , 90*mus_me_tama_mvl/mxv
	.byte		N88   , An2 , v092
	.byte	W88
	.byte		N08   
	.byte	W08
	.byte		N72   
	.byte	W72
	.byte		N24   
	.byte	W24
	.byte		N88   
	.byte	W88
	.byte		N08   
	.byte	W08
	.byte		N48   
	.byte	W48
	.byte		N32   
	.byte	W32
	.byte		N16   
	.byte	W16
	.byte		N56   
	.byte	W56
	.byte		VOL   , 28*mus_me_tama_mvl/mxv
	.byte		N40   , Cn3 , v064
	.byte	W04
	.byte		VOL   , 36*mus_me_tama_mvl/mxv
	.byte	W04
	.byte		        43*mus_me_tama_mvl/mxv
	.byte	W04
	.byte		        47*mus_me_tama_mvl/mxv
	.byte	W04
	.byte		        53*mus_me_tama_mvl/mxv
	.byte	W04
	.byte		        57*mus_me_tama_mvl/mxv
	.byte	W04
	.byte		        63*mus_me_tama_mvl/mxv
	.byte	W04
	.byte		        75*mus_me_tama_mvl/mxv
	.byte	W04
	.byte		        84*mus_me_tama_mvl/mxv
	.byte	W04
	.byte		        90*mus_me_tama_mvl/mxv
	.byte	W04
	.byte		N72   , An2 , v092
	.byte	W96
	.byte	FINE

@******************************************************@
	.align	2

mus_me_tama:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_me_tama_pri	@ Priority
	.byte	mus_me_tama_rev	@ Reverb.

	.word	mus_me_tama_grp

	.word	mus_me_tama_1
	.word	mus_me_tama_2
	.word	mus_me_tama_3
	.word	mus_me_tama_4
	.word	mus_me_tama_5
	.word	mus_me_tama_6
	.word	mus_me_tama_7

	.end
