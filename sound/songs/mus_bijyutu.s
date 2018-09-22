	.include "MPlayDef.s"

	.equ	mus_bijyutu_grp, voicegroup020
	.equ	mus_bijyutu_pri, 0
	.equ	mus_bijyutu_rev, reverb_set+50
	.equ	mus_bijyutu_mvl, 127
	.equ	mus_bijyutu_key, 0
	.equ	mus_bijyutu_tbs, 1
	.equ	mus_bijyutu_exg, 0
	.equ	mus_bijyutu_cmp, 1

	.section .rodata
	.global	mus_bijyutu
	.align	2

@********************** Track  1 **********************@

mus_bijyutu_1:
	.byte	KEYSH , mus_bijyutu_key+0
	.byte	TEMPO , 68*mus_bijyutu_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 41*mus_bijyutu_mvl/mxv
	.byte		N24   , Dn3 , v092
	.byte	W02
	.byte		VOL   , 45*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        50*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        55*mus_bijyutu_mvl/mxv
	.byte	W04
	.byte		        60*mus_bijyutu_mvl/mxv
	.byte	W02
	.byte		        66*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        74*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        78*mus_bijyutu_mvl/mxv
	.byte	W04
mus_bijyutu_1_B1:
	.byte		VOL   , 80*mus_bijyutu_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Gn3 , v092
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
mus_bijyutu_1_000:
	.byte		N03   , Fs3 , v084
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		N06   , Fs3 , v092
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte	PEND
mus_bijyutu_1_001:
	.byte		N12   , Gn3 , v092
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte	PEND
	.byte		N03   , Fs4 , v084
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		N06   , Fs4 , v092
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 , v084
	.byte	W12
	.byte		        Fs4 , v092
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	PATT
	 .word	mus_bijyutu_1_000
	.byte	PATT
	 .word	mus_bijyutu_1_001
	.byte		N03   , Fs4 , v084
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		N06   , Fs4 , v092
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 , v084
	.byte	W12
	.byte		        Fs4 , v092
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N09   , Cn5 , v080
	.byte	W12
	.byte		VOICE , 45
	.byte		N06   , Bn4 , v044
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Bn4 , v012
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Gn4 , v044
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Gn4 , v012
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Bn4 , v044
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Bn4 , v012
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Dn4 , v044
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Dn4 , v012
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Bn4 , v044
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Bn4 , v012
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Gn4 , v044
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Gn4 , v012
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Bn4 , v044
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Bn4 , v012
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Dn4 , v044
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Dn4 , v012
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Cn5 , v044
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Cn5 , v012
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Gn4 , v044
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Gn4 , v012
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Cn5 , v044
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Cn5 , v012
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En4 , v044
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , En4 , v012
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Cn5 , v044
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Cn5 , v012
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Gn4 , v044
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Gn4 , v012
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Cn5 , v044
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Cn5 , v012
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En4 , v044
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , En4 , v012
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Cs5 , v044
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Cs5 , v012
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Gn4 , v044
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Gn4 , v012
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Cs5 , v044
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Cs5 , v012
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En4 , v044
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , En4 , v012
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Cs5 , v044
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Cs5 , v012
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Gn4 , v044
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Gn4 , v012
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Cs5 , v044
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Cs5 , v012
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , En4 , v044
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , En4 , v012
	.byte	W06
	.byte		VOICE , 48
	.byte		PAN   , c_v+0
	.byte		N06   , Dn5 , v044
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N24   , An4 
	.byte	W24
	.byte		VOL   , 42*mus_bijyutu_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N44   , Gn2 , v092
	.byte	W06
	.byte		VOL   , 52*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        63*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte	W19
	.byte		        42*mus_bijyutu_mvl/mxv
	.byte		N44   , Dn2 
	.byte	W06
	.byte		VOL   , 52*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        63*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte	W19
	.byte		        42*mus_bijyutu_mvl/mxv
	.byte		N44   , Fs2 
	.byte	W06
	.byte		VOL   , 52*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        63*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte	W19
	.byte		        42*mus_bijyutu_mvl/mxv
	.byte		N44   , Cn2 
	.byte	W06
	.byte		VOL   , 52*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        63*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte	W19
	.byte		        42*mus_bijyutu_mvl/mxv
	.byte		N44   , En2 
	.byte	W06
	.byte		VOL   , 52*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        63*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte	W19
	.byte		        42*mus_bijyutu_mvl/mxv
	.byte		N48   , Bn1 
	.byte	W06
	.byte		VOL   , 52*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        63*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte	W19
	.byte		N48   , Dn2 
	.byte	W06
	.byte		VOL   , 71*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        65*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        50*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        60*mus_bijyutu_mvl/mxv
	.byte	W04
	.byte		        66*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        73*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte		        76*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte	W09
	.byte		PAN   , c_v+0
	.byte		N12   , Cn3 , v072
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
mus_bijyutu_1_002:
	.byte		N12   , Gn3 , v084
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	PEND
	.byte		N03   , Fs3 , v076
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		N06   , Fs3 , v084
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N03   , Fs4 , v076
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		N06   , Fs4 , v084
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 , v076
	.byte	W12
	.byte		        Fs4 , v084
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte	PATT
	 .word	mus_bijyutu_1_002
	.byte		N03   , Fs3 , v076
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		N06   , Fs3 , v084
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N44   , An3 
	.byte	W24
	.byte	W03
	.byte		VOL   , 74*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        63*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        44*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        25*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        15*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        6*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        55*mus_bijyutu_mvl/mxv
	.byte		N24   , Fs3 
	.byte	W03
	.byte		VOL   , 61*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        66*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        74*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte	W12
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N68   , Gn3 
	.byte	W18
	.byte		VOL   , 80*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        75*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        59*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        49*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        39*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        17*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        3*mus_bijyutu_mvl/mxv
	.byte	W13
	.byte		        41*mus_bijyutu_mvl/mxv
	.byte		N24   , Dn3 
	.byte	W02
	.byte		VOL   , 45*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        50*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        55*mus_bijyutu_mvl/mxv
	.byte	W04
	.byte		        60*mus_bijyutu_mvl/mxv
	.byte	W02
	.byte		        66*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        74*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        78*mus_bijyutu_mvl/mxv
	.byte	W04
	.byte	GOTO
	 .word	mus_bijyutu_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_bijyutu_2:
	.byte	KEYSH , mus_bijyutu_key+0
	.byte		LFOS  , 38
	.byte		XCMD  , xIECV , 9
	.byte		        xIECL , 8
	.byte		VOL   , 80*mus_bijyutu_mvl/mxv
	.byte	W24
mus_bijyutu_2_B1:
	.byte		PAN   , c_v-48
	.byte		VOL   , 80*mus_bijyutu_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 83
	.byte		VOL   , 25*mus_bijyutu_mvl/mxv
	.byte		N96   , Dn3 , v048
	.byte	W06
	.byte		VOL   , 34*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        54*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        69*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        74*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte	W12
	.byte		        74*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        54*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        30*mus_bijyutu_mvl/mxv
	.byte	W06
mus_bijyutu_2_000:
	.byte		VOL   , 25*mus_bijyutu_mvl/mxv
	.byte		N96   , Cn3 , v048
	.byte	W06
	.byte		VOL   , 34*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        54*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        69*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        74*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte	W12
	.byte		        74*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        54*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        30*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte	PEND
	.byte		        25*mus_bijyutu_mvl/mxv
	.byte		N96   , Bn2 
	.byte	W06
	.byte		VOL   , 34*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        54*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        69*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        74*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte	W12
	.byte		        74*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        54*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        30*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        54*mus_bijyutu_mvl/mxv
	.byte		N48   , An2 
	.byte	W06
	.byte		VOL   , 62*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        69*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        74*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte	W18
	.byte		N48   , Cn3 , v056
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 80
	.byte		PAN   , c_v+0
	.byte		XCMD  , xIECV , 0
	.byte		        xIECL , 0
	.byte		N12   , Gn4 , v032
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N03   , Fs4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		N36   , Fs5 
	.byte	W12
	.byte		MOD   , 4
	.byte	W24
	.byte		        0
	.byte		N12   , En5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 83
	.byte		PAN   , c_v-48
	.byte		VOL   , 25*mus_bijyutu_mvl/mxv
	.byte		XCMD  , xIECV , 9
	.byte		        xIECL , 8
	.byte		N96   , Dn3 , v048
	.byte	W06
	.byte		VOL   , 34*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        54*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        69*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        74*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte	W12
	.byte		        74*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        54*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        30*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte	PATT
	 .word	mus_bijyutu_2_000
	.byte		VOL   , 54*mus_bijyutu_mvl/mxv
	.byte		N48   , Bn2 , v048
	.byte	W06
	.byte		VOL   , 62*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        69*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        74*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte	W18
	.byte		N48   , An2 
	.byte	W48
	.byte		N96   
	.byte	W12
	.byte		VOL   , 78*mus_bijyutu_mvl/mxv
	.byte	W12
	.byte		        76*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        68*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte		        66*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        62*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte		        58*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        52*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte		        47*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        38*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte		        31*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        21*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte		        11*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        1*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte	W96
	.byte	GOTO
	 .word	mus_bijyutu_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_bijyutu_3:
	.byte	KEYSH , mus_bijyutu_key+0
	.byte		XCMD  , xIECV , 9
	.byte		        xIECL , 8
	.byte		LFOS  , 38
	.byte		VOL   , 80*mus_bijyutu_mvl/mxv
	.byte	W24
mus_bijyutu_3_B1:
	.byte		PAN   , c_v+48
	.byte		VOL   , 80*mus_bijyutu_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 84
	.byte		VOL   , 25*mus_bijyutu_mvl/mxv
	.byte		N12   , Bn2 , v048
	.byte	W06
	.byte		VOL   , 34*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		VOICE , 85
	.byte		VOL   , 46*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 54*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 69*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        74*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 77*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		VOL   , 74*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 68*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 54*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 30*mus_bijyutu_mvl/mxv
	.byte	W06
mus_bijyutu_3_000:
	.byte		VOICE , 84
	.byte		VOL   , 25*mus_bijyutu_mvl/mxv
	.byte		N12   , An2 , v048
	.byte	W06
	.byte		VOL   , 34*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		VOICE , 85
	.byte		VOL   , 46*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 54*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 69*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        74*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 77*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		VOL   , 74*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 68*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 54*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 30*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte	PEND
	.byte		VOICE , 84
	.byte		VOL   , 25*mus_bijyutu_mvl/mxv
	.byte		N12   , Gn2 
	.byte	W06
	.byte		VOL   , 34*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		VOICE , 85
	.byte		VOL   , 46*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 54*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 69*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        74*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 77*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		VOL   , 74*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 68*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 54*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 30*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		VOICE , 84
	.byte		VOL   , 54*mus_bijyutu_mvl/mxv
	.byte		N12   , Fs2 
	.byte	W06
	.byte		VOL   , 62*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		VOICE , 85
	.byte		VOL   , 69*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 74*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 80*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   , An2 , v056
	.byte	W12
	.byte		VOICE , 85
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 82
	.byte		PAN   , c_v+0
	.byte		XCMD  , xIECV , 0
	.byte		        xIECL , 0
	.byte	W03
	.byte		BEND  , c_v+6
	.byte		N12   , Gn4 , v020
	.byte	W12
	.byte		BEND  , c_v+4
	.byte		N12   , Dn4 
	.byte	W12
	.byte		BEND  , c_v+7
	.byte		N12   , An4 
	.byte	W12
	.byte		BEND  , c_v+4
	.byte		N12   , Dn4 
	.byte	W12
	.byte		BEND  , c_v+9
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		BEND  , c_v+6
	.byte		N12   , Gn4 
	.byte	W09
	.byte	W03
	.byte		BEND  , c_v+4
	.byte		N03   , Fs4 
	.byte	W03
	.byte		BEND  , c_v+6
	.byte		N03   , Gn4 
	.byte	W03
	.byte		BEND  , c_v+4
	.byte		N03   , Fs4 
	.byte	W03
	.byte		BEND  , c_v+6
	.byte		N03   , Gn4 
	.byte	W03
	.byte		BEND  , c_v+4
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		BEND  , c_v+6
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		BEND  , c_v+4
	.byte		N12   , Fs4 
	.byte	W09
	.byte	W03
	.byte		BEND  , c_v+6
	.byte		N12   , Gn4 
	.byte	W12
	.byte		BEND  , c_v+4
	.byte		N12   , Fs4 
	.byte	W12
	.byte		BEND  , c_v+6
	.byte		N12   , Gn4 
	.byte	W12
	.byte		BEND  , c_v+4
	.byte		N12   , En4 
	.byte	W12
	.byte		BEND  , c_v+9
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Gn5 
	.byte	W09
	.byte	W03
	.byte		        Fs5 
	.byte	W09
	.byte		MOD   , 4
	.byte	W03
	.byte		VOICE , 86
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W09
	.byte		MOD   , 0
	.byte	W03
	.byte		VOICE , 82
	.byte		N12   , En5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W09
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 84
	.byte		PAN   , c_v+49
	.byte		VOL   , 25*mus_bijyutu_mvl/mxv
	.byte		XCMD  , xIECV , 9
	.byte		        xIECL , 8
	.byte		BEND  , c_v+0
	.byte		N12   , Bn2 , v048
	.byte	W06
	.byte		VOL   , 34*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		VOICE , 85
	.byte		VOL   , 46*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 54*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 69*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        74*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 77*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		VOL   , 74*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 68*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 54*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 30*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte	PATT
	 .word	mus_bijyutu_3_000
	.byte		VOICE , 84
	.byte		VOL   , 54*mus_bijyutu_mvl/mxv
	.byte		N12   , Gn2 , v048
	.byte	W06
	.byte		VOL   , 62*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		VOICE , 85
	.byte		VOL   , 69*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 74*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 80*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		VOICE , 85
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   , Fs2 
	.byte	W12
	.byte		VOICE , 85
	.byte		VOL   , 78*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		VOL   , 76*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 68*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte		        66*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 62*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte		        58*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 52*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte		        47*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 38*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte		        31*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 21*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte		        11*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 1*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte	W96
	.byte	GOTO
	 .word	mus_bijyutu_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_bijyutu_4:
	.byte	KEYSH , mus_bijyutu_key+0
	.byte		VOICE , 0
	.byte	W24
mus_bijyutu_4_B1:
	.byte		PAN   , c_v-8
	.byte		VOL   , 80*mus_bijyutu_mvl/mxv
	.byte		N24   , Gn2 , v100
	.byte	W24
	.byte		N36   , Gn1 
	.byte	W36
	.byte		N24   , Dn2 
	.byte	W24
	.byte		N12   , Gn2 
	.byte	W12
mus_bijyutu_4_000:
	.byte		N24   , Fs2 , v100
	.byte	W24
	.byte		N36   , Fs1 
	.byte	W36
	.byte		N24   , Fs2 
	.byte	W24
	.byte		N12   , Cn2 
	.byte	W12
	.byte	PEND
mus_bijyutu_4_001:
	.byte		N24   , En2 , v100
	.byte	W24
	.byte		N36   , En1 
	.byte	W36
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte	PEND
mus_bijyutu_4_002:
	.byte		N24   , Dn3 , v100
	.byte	W24
	.byte		N36   , Dn1 
	.byte	W36
	.byte		N24   , Dn2 
	.byte	W24
	.byte		N12   , An2 
	.byte	W12
	.byte	PEND
mus_bijyutu_4_003:
	.byte		N24   , Gn2 , v100
	.byte	W24
	.byte		N36   , Gn1 
	.byte	W36
	.byte		N24   , Dn2 
	.byte	W24
	.byte		N12   , Gn2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_bijyutu_4_000
	.byte	PATT
	 .word	mus_bijyutu_4_001
	.byte		N24   , Dn2 , v100
	.byte	W24
	.byte		N36   , Dn1 
	.byte	W36
	.byte		N24   , Dn2 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N06   , En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W12
	.byte		        Cs4 
	.byte	W18
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N12   , An3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N06   , An2 , v084
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N12   , Gn3 , v100
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        Gn3 , v088
	.byte	W03
	.byte		        Fs3 , v100
	.byte	W03
	.byte		        Gn3 , v088
	.byte	W03
	.byte		N06   , Fs3 , v100
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N36   , Fs4 
	.byte	W36
	.byte		N12   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte	PATT
	 .word	mus_bijyutu_4_003
	.byte	PATT
	 .word	mus_bijyutu_4_000
	.byte	PATT
	 .word	mus_bijyutu_4_001
	.byte	PATT
	 .word	mus_bijyutu_4_002
	.byte	PATT
	 .word	mus_bijyutu_4_003
	.byte	PATT
	 .word	mus_bijyutu_4_000
	.byte		N24   , En2 , v100
	.byte	W24
	.byte		        En1 
	.byte	W24
	.byte		N12   , Dn2 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   , Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N44   
	.byte	W21
	.byte		VOL   , 67*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        57*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        45*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        39*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        21*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        1*mus_bijyutu_mvl/mxv
	.byte	W09
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte		N48   , Bn2 
	.byte	W48
	.byte		        Gn1 
	.byte	W48
	.byte	GOTO
	 .word	mus_bijyutu_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_bijyutu_5:
	.byte	KEYSH , mus_bijyutu_key+0
	.byte		VOICE , 0
	.byte	W24
mus_bijyutu_5_B1:
	.byte		PAN   , c_v+8
	.byte		VOL   , 80*mus_bijyutu_mvl/mxv
	.byte		N48   , Bn2 , v100
	.byte	W60
	.byte		N12   , Gn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
mus_bijyutu_5_000:
	.byte		N48   , An2 , v100
	.byte	W48
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte	PEND
mus_bijyutu_5_001:
	.byte		N48   , Gn2 , v100
	.byte	W48
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	PEND
mus_bijyutu_5_002:
	.byte		N48   , An3 , v100
	.byte	W48
	.byte		N24   , Cn3 
	.byte	W24
	.byte		N12   , Fs2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte	PEND
mus_bijyutu_5_003:
	.byte		N48   , Bn2 , v100
	.byte	W60
	.byte		N12   , Gn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_bijyutu_5_000
	.byte	PATT
	 .word	mus_bijyutu_5_001
	.byte		N48   , An3 , v100
	.byte	W48
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N12   , An2 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N24   , Gn2 
	.byte	W24
	.byte		N36   , Gn1 
	.byte	W36
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		N24   , Gn2 
	.byte	W24
	.byte		N36   , Gn1 
	.byte	W36
	.byte		N12   , Gn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N06   , En2 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   , Cs3 
	.byte	W12
	.byte		N06   , En2 
	.byte	W12
	.byte		N24   , Cs2 
	.byte	W24
	.byte		N36   , Fs3 
	.byte	W48
	.byte		N12   , An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W15
	.byte		N06   , Cn3 , v084
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W03
	.byte		N12   , Bn2 , v100
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N24   , An2 
	.byte	W24
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N36   , Gn2 
	.byte	W36
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N36   , Gn2 
	.byte	W36
	.byte		N12   , En2 
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte	PATT
	 .word	mus_bijyutu_5_003
	.byte	PATT
	 .word	mus_bijyutu_5_000
	.byte	PATT
	 .word	mus_bijyutu_5_001
	.byte	PATT
	 .word	mus_bijyutu_5_002
	.byte	PATT
	 .word	mus_bijyutu_5_003
	.byte	PATT
	 .word	mus_bijyutu_5_000
	.byte		N48   , Gn2 , v100
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte	W06
	.byte		N12   , Fs1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		N09   , Cn3 
	.byte	W09
	.byte		N42   , Dn3 
	.byte	W18
	.byte		VOL   , 67*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        57*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        45*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        39*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        21*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        1*mus_bijyutu_mvl/mxv
	.byte	W09
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte		N48   
	.byte	W48
	.byte		        Bn2 
	.byte	W48
	.byte	GOTO
	 .word	mus_bijyutu_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_bijyutu_6:
	.byte	KEYSH , mus_bijyutu_key+0
	.byte	W24
mus_bijyutu_6_B1:
	.byte		VOL   , 80*mus_bijyutu_mvl/mxv
	.byte		PAN   , c_v+0
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
	.byte		VOICE , 0
	.byte		N12   , En3 , v096
	.byte	W48
	.byte		N12   
	.byte	W48
	.byte		PAN   , c_v+8
	.byte		N24   , Dn2 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        Bn1 
	.byte	W24
	.byte		        An1 
	.byte	W24
	.byte		VOICE , 58
	.byte		VOL   , 80*mus_bijyutu_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		N44   , Gn1 , v112
	.byte	W24
	.byte		VOL   , 76*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        65*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte		        37*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        17*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte		N44   , Dn1 
	.byte	W24
	.byte		VOL   , 76*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        65*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte		        37*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        17*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte		N44   , Fs1 
	.byte	W24
	.byte		VOL   , 76*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        65*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte		        37*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        17*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte		N44   , Cn1 
	.byte	W24
	.byte		VOL   , 76*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        65*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte		        37*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        17*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte		N44   , En1 
	.byte	W24
	.byte		VOL   , 76*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        65*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte		        37*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        17*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte		N44   , Bn0 
	.byte	W24
	.byte		VOL   , 76*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        65*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte		        37*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        17*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte		N96   , Dn1 
	.byte	W52
	.byte	W01
	.byte		VOL   , 74*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        69*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        60*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        48*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        39*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        20*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        3*mus_bijyutu_mvl/mxv
	.byte	W07
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		        56*mus_bijyutu_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , Fs1 
	.byte	W06
	.byte		VOL   , 69*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte	W12
	.byte		N72   , Gn1 
	.byte	W06
	.byte		VOL   , 73*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        60*mus_bijyutu_mvl/mxv
	.byte	W02
	.byte		        53*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        52*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        53*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        54*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        55*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        61*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        70*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte	W13
	.byte		        76*mus_bijyutu_mvl/mxv
	.byte	W02
	.byte		        74*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        64*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        52*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        37*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        26*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        17*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        14*mus_bijyutu_mvl/mxv
	.byte	W10
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		N72   , Fs1 
	.byte	W06
	.byte		VOL   , 73*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        60*mus_bijyutu_mvl/mxv
	.byte	W02
	.byte		        53*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        52*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        53*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        54*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        55*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        61*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        70*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte	W13
	.byte		        76*mus_bijyutu_mvl/mxv
	.byte	W02
	.byte		        74*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        64*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        52*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        37*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        26*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        17*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        14*mus_bijyutu_mvl/mxv
	.byte	W10
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		N24   , En1 
	.byte	W12
	.byte		VOL   , 68*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        58*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        42*mus_bijyutu_mvl/mxv
	.byte	W03
	.byte		        23*mus_bijyutu_mvl/mxv
	.byte	W15
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N32   , An1 
	.byte	W18
	.byte		VOL   , 74*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        52*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        31*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*mus_bijyutu_mvl/mxv
	.byte		N12   , En1 
	.byte	W12
	.byte		N96   , Dn1 
	.byte	W36
	.byte		VOL   , 80*mus_bijyutu_mvl/mxv
	.byte	W05
	.byte		        75*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        63*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        57*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        45*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        32*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        10*mus_bijyutu_mvl/mxv
	.byte	W06
	.byte		        7*mus_bijyutu_mvl/mxv
	.byte	W13
	.byte	W96
	.byte	GOTO
	 .word	mus_bijyutu_6_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_bijyutu:
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_bijyutu_pri	@ Priority
	.byte	mus_bijyutu_rev	@ Reverb.

	.word	mus_bijyutu_grp

	.word	mus_bijyutu_1
	.word	mus_bijyutu_2
	.word	mus_bijyutu_3
	.word	mus_bijyutu_4
	.word	mus_bijyutu_5
	.word	mus_bijyutu_6

	.end
