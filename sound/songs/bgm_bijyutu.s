	.include "MPlayDef.s"

	.equ	bgm_bijyutu_grp, voicegroup_8679DC0
	.equ	bgm_bijyutu_pri, 0
	.equ	bgm_bijyutu_rev, reverb_set+50
	.equ	bgm_bijyutu_mvl, 127
	.equ	bgm_bijyutu_key, 0
	.equ	bgm_bijyutu_tbs, 1
	.equ	bgm_bijyutu_exg, 0
	.equ	bgm_bijyutu_cmp, 1

	.section .rodata
	.global	bgm_bijyutu
	.align	2

@********************** Track  1 **********************@

bgm_bijyutu_1:
	.byte	KEYSH , bgm_bijyutu_key+0
	.byte	TEMPO , 68*bgm_bijyutu_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 41*bgm_bijyutu_mvl/mxv
	.byte		N24   , Dn3 , v092
	.byte	W02
	.byte		VOL   , 45*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        50*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        55*bgm_bijyutu_mvl/mxv
	.byte	W04
	.byte		        60*bgm_bijyutu_mvl/mxv
	.byte	W02
	.byte		        66*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        74*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        78*bgm_bijyutu_mvl/mxv
	.byte	W04
bgm_bijyutu_1_B1:
	.byte		VOL   , 80*bgm_bijyutu_mvl/mxv
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
bgm_bijyutu_1_000:
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
bgm_bijyutu_1_001:
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
	 .word	bgm_bijyutu_1_000
	.byte	PATT
	 .word	bgm_bijyutu_1_001
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
	.byte		VOL   , 42*bgm_bijyutu_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N44   , Gn2 , v092
	.byte	W06
	.byte		VOL   , 52*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        63*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte	W19
	.byte		        42*bgm_bijyutu_mvl/mxv
	.byte		N44   , Dn2 
	.byte	W06
	.byte		VOL   , 52*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        63*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte	W19
	.byte		        42*bgm_bijyutu_mvl/mxv
	.byte		N44   , Fs2 
	.byte	W06
	.byte		VOL   , 52*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        63*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte	W19
	.byte		        42*bgm_bijyutu_mvl/mxv
	.byte		N44   , Cn2 
	.byte	W06
	.byte		VOL   , 52*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        63*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte	W19
	.byte		        42*bgm_bijyutu_mvl/mxv
	.byte		N44   , En2 
	.byte	W06
	.byte		VOL   , 52*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        63*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte	W19
	.byte		        42*bgm_bijyutu_mvl/mxv
	.byte		N48   , Bn1 
	.byte	W06
	.byte		VOL   , 52*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        63*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte	W19
	.byte		N48   , Dn2 
	.byte	W06
	.byte		VOL   , 71*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        65*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        50*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        60*bgm_bijyutu_mvl/mxv
	.byte	W04
	.byte		        66*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        73*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte		        76*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*bgm_bijyutu_mvl/mxv
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
bgm_bijyutu_1_002:
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
	 .word	bgm_bijyutu_1_002
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
	.byte		VOL   , 74*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        63*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        44*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        25*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        15*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        6*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        55*bgm_bijyutu_mvl/mxv
	.byte		N24   , Fs3 
	.byte	W03
	.byte		VOL   , 61*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        66*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        74*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte	W12
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N68   , Gn3 
	.byte	W18
	.byte		VOL   , 80*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        75*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        59*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        49*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        39*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        17*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        3*bgm_bijyutu_mvl/mxv
	.byte	W13
	.byte		        41*bgm_bijyutu_mvl/mxv
	.byte		N24   , Dn3 
	.byte	W02
	.byte		VOL   , 45*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        50*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        55*bgm_bijyutu_mvl/mxv
	.byte	W04
	.byte		        60*bgm_bijyutu_mvl/mxv
	.byte	W02
	.byte		        66*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        74*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        78*bgm_bijyutu_mvl/mxv
	.byte	W04
	.byte	GOTO
	 .word	bgm_bijyutu_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_bijyutu_2:
	.byte	KEYSH , bgm_bijyutu_key+0
	.byte		LFOS  , 38
	.byte		XCMD  , xIECV , 9
	.byte		        xIECL , 8
	.byte		VOL   , 80*bgm_bijyutu_mvl/mxv
	.byte	W24
bgm_bijyutu_2_B1:
	.byte		PAN   , c_v-48
	.byte		VOL   , 80*bgm_bijyutu_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 83
	.byte		VOL   , 25*bgm_bijyutu_mvl/mxv
	.byte		N96   , Dn3 , v048
	.byte	W06
	.byte		VOL   , 34*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        54*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        69*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        74*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte	W12
	.byte		        74*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        54*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        30*bgm_bijyutu_mvl/mxv
	.byte	W06
bgm_bijyutu_2_000:
	.byte		VOL   , 25*bgm_bijyutu_mvl/mxv
	.byte		N96   , Cn3 , v048
	.byte	W06
	.byte		VOL   , 34*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        54*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        69*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        74*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte	W12
	.byte		        74*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        54*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        30*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte	PEND
	.byte		        25*bgm_bijyutu_mvl/mxv
	.byte		N96   , Bn2 
	.byte	W06
	.byte		VOL   , 34*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        54*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        69*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        74*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte	W12
	.byte		        74*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        54*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        30*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        54*bgm_bijyutu_mvl/mxv
	.byte		N48   , An2 
	.byte	W06
	.byte		VOL   , 62*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        69*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        74*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*bgm_bijyutu_mvl/mxv
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
	.byte		VOL   , 25*bgm_bijyutu_mvl/mxv
	.byte		XCMD  , xIECV , 9
	.byte		        xIECL , 8
	.byte		N96   , Dn3 , v048
	.byte	W06
	.byte		VOL   , 34*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        54*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        69*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        74*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte	W12
	.byte		        74*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        54*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        30*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte	PATT
	 .word	bgm_bijyutu_2_000
	.byte		VOL   , 54*bgm_bijyutu_mvl/mxv
	.byte		N48   , Bn2 , v048
	.byte	W06
	.byte		VOL   , 62*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        69*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        74*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte	W18
	.byte		N48   , An2 
	.byte	W48
	.byte		N96   
	.byte	W12
	.byte		VOL   , 78*bgm_bijyutu_mvl/mxv
	.byte	W12
	.byte		        76*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        68*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte		        66*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        62*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte		        58*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        52*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte		        47*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        38*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte		        31*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        21*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte		        11*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        1*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte	W96
	.byte	GOTO
	 .word	bgm_bijyutu_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_bijyutu_3:
	.byte	KEYSH , bgm_bijyutu_key+0
	.byte		XCMD  , xIECV , 9
	.byte		        xIECL , 8
	.byte		LFOS  , 38
	.byte		VOL   , 80*bgm_bijyutu_mvl/mxv
	.byte	W24
bgm_bijyutu_3_B1:
	.byte		PAN   , c_v+48
	.byte		VOL   , 80*bgm_bijyutu_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 84
	.byte		VOL   , 25*bgm_bijyutu_mvl/mxv
	.byte		N12   , Bn2 , v048
	.byte	W06
	.byte		VOL   , 34*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		VOICE , 85
	.byte		VOL   , 46*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 54*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 69*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        74*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 77*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		VOL   , 74*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 68*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 54*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 30*bgm_bijyutu_mvl/mxv
	.byte	W06
bgm_bijyutu_3_000:
	.byte		VOICE , 84
	.byte		VOL   , 25*bgm_bijyutu_mvl/mxv
	.byte		N12   , An2 , v048
	.byte	W06
	.byte		VOL   , 34*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		VOICE , 85
	.byte		VOL   , 46*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 54*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 69*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        74*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 77*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		VOL   , 74*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 68*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 54*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 30*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte	PEND
	.byte		VOICE , 84
	.byte		VOL   , 25*bgm_bijyutu_mvl/mxv
	.byte		N12   , Gn2 
	.byte	W06
	.byte		VOL   , 34*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		VOICE , 85
	.byte		VOL   , 46*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 54*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 69*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        74*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 77*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		VOL   , 74*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 68*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 54*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 30*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		VOICE , 84
	.byte		VOL   , 54*bgm_bijyutu_mvl/mxv
	.byte		N12   , Fs2 
	.byte	W06
	.byte		VOL   , 62*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		VOICE , 85
	.byte		VOL   , 69*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 74*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 80*bgm_bijyutu_mvl/mxv
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
	.byte		VOL   , 25*bgm_bijyutu_mvl/mxv
	.byte		XCMD  , xIECV , 9
	.byte		        xIECL , 8
	.byte		BEND  , c_v+0
	.byte		N12   , Bn2 , v048
	.byte	W06
	.byte		VOL   , 34*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		VOICE , 85
	.byte		VOL   , 46*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 54*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 69*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        74*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 77*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		VOL   , 74*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 68*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        62*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 54*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        46*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 30*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte	PATT
	 .word	bgm_bijyutu_3_000
	.byte		VOICE , 84
	.byte		VOL   , 54*bgm_bijyutu_mvl/mxv
	.byte		N12   , Gn2 , v048
	.byte	W06
	.byte		VOL   , 62*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		VOICE , 85
	.byte		VOL   , 69*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 74*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        77*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 80*bgm_bijyutu_mvl/mxv
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
	.byte		VOL   , 78*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		VOL   , 76*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 68*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte		        66*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 62*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte		        58*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 52*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte		        47*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 38*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte		        31*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 21*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte		        11*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 1*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte	W96
	.byte	GOTO
	 .word	bgm_bijyutu_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_bijyutu_4:
	.byte	KEYSH , bgm_bijyutu_key+0
	.byte		VOICE , 0
	.byte	W24
bgm_bijyutu_4_B1:
	.byte		PAN   , c_v-8
	.byte		VOL   , 80*bgm_bijyutu_mvl/mxv
	.byte		N24   , Gn2 , v100
	.byte	W24
	.byte		N36   , Gn1 
	.byte	W36
	.byte		N24   , Dn2 
	.byte	W24
	.byte		N12   , Gn2 
	.byte	W12
bgm_bijyutu_4_000:
	.byte		N24   , Fs2 , v100
	.byte	W24
	.byte		N36   , Fs1 
	.byte	W36
	.byte		N24   , Fs2 
	.byte	W24
	.byte		N12   , Cn2 
	.byte	W12
	.byte	PEND
bgm_bijyutu_4_001:
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
bgm_bijyutu_4_002:
	.byte		N24   , Dn3 , v100
	.byte	W24
	.byte		N36   , Dn1 
	.byte	W36
	.byte		N24   , Dn2 
	.byte	W24
	.byte		N12   , An2 
	.byte	W12
	.byte	PEND
bgm_bijyutu_4_003:
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
	 .word	bgm_bijyutu_4_000
	.byte	PATT
	 .word	bgm_bijyutu_4_001
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
	 .word	bgm_bijyutu_4_003
	.byte	PATT
	 .word	bgm_bijyutu_4_000
	.byte	PATT
	 .word	bgm_bijyutu_4_001
	.byte	PATT
	 .word	bgm_bijyutu_4_002
	.byte	PATT
	 .word	bgm_bijyutu_4_003
	.byte	PATT
	 .word	bgm_bijyutu_4_000
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
	.byte		VOL   , 67*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        57*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        45*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        39*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        21*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        1*bgm_bijyutu_mvl/mxv
	.byte	W09
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte		N48   , Bn2 
	.byte	W48
	.byte		        Gn1 
	.byte	W48
	.byte	GOTO
	 .word	bgm_bijyutu_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_bijyutu_5:
	.byte	KEYSH , bgm_bijyutu_key+0
	.byte		VOICE , 0
	.byte	W24
bgm_bijyutu_5_B1:
	.byte		PAN   , c_v+8
	.byte		VOL   , 80*bgm_bijyutu_mvl/mxv
	.byte		N48   , Bn2 , v100
	.byte	W60
	.byte		N12   , Gn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
bgm_bijyutu_5_000:
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
bgm_bijyutu_5_001:
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
bgm_bijyutu_5_002:
	.byte		N48   , An3 , v100
	.byte	W48
	.byte		N24   , Cn3 
	.byte	W24
	.byte		N12   , Fs2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte	PEND
bgm_bijyutu_5_003:
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
	 .word	bgm_bijyutu_5_000
	.byte	PATT
	 .word	bgm_bijyutu_5_001
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
	 .word	bgm_bijyutu_5_003
	.byte	PATT
	 .word	bgm_bijyutu_5_000
	.byte	PATT
	 .word	bgm_bijyutu_5_001
	.byte	PATT
	 .word	bgm_bijyutu_5_002
	.byte	PATT
	 .word	bgm_bijyutu_5_003
	.byte	PATT
	 .word	bgm_bijyutu_5_000
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
	.byte		VOL   , 67*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        57*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        45*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        39*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        21*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        1*bgm_bijyutu_mvl/mxv
	.byte	W09
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte		N48   
	.byte	W48
	.byte		        Bn2 
	.byte	W48
	.byte	GOTO
	 .word	bgm_bijyutu_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_bijyutu_6:
	.byte	KEYSH , bgm_bijyutu_key+0
	.byte	W24
bgm_bijyutu_6_B1:
	.byte		VOL   , 80*bgm_bijyutu_mvl/mxv
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
	.byte		VOL   , 80*bgm_bijyutu_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		N44   , Gn1 , v112
	.byte	W24
	.byte		VOL   , 76*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        65*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte		        37*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        17*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte		N44   , Dn1 
	.byte	W24
	.byte		VOL   , 76*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        65*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte		        37*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        17*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte		N44   , Fs1 
	.byte	W24
	.byte		VOL   , 76*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        65*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte		        37*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        17*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte		N44   , Cn1 
	.byte	W24
	.byte		VOL   , 76*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        65*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte		        37*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        17*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte		N44   , En1 
	.byte	W24
	.byte		VOL   , 76*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        65*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte		        37*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        17*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte		N44   , Bn0 
	.byte	W24
	.byte		VOL   , 76*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        65*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte		        37*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        17*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte		N96   , Dn1 
	.byte	W52
	.byte	W01
	.byte		VOL   , 74*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        69*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        60*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        48*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        39*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        20*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        3*bgm_bijyutu_mvl/mxv
	.byte	W07
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		        56*bgm_bijyutu_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , Fs1 
	.byte	W06
	.byte		VOL   , 69*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte	W12
	.byte		N72   , Gn1 
	.byte	W06
	.byte		VOL   , 73*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        60*bgm_bijyutu_mvl/mxv
	.byte	W02
	.byte		        53*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        52*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        53*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        54*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        55*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        61*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        70*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte	W13
	.byte		        76*bgm_bijyutu_mvl/mxv
	.byte	W02
	.byte		        74*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        64*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        52*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        37*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        26*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        17*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        14*bgm_bijyutu_mvl/mxv
	.byte	W10
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		N72   , Fs1 
	.byte	W06
	.byte		VOL   , 73*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        60*bgm_bijyutu_mvl/mxv
	.byte	W02
	.byte		        53*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        52*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        53*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        54*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        55*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        61*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        70*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte	W13
	.byte		        76*bgm_bijyutu_mvl/mxv
	.byte	W02
	.byte		        74*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        64*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        52*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        37*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        26*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        17*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        14*bgm_bijyutu_mvl/mxv
	.byte	W10
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		N24   , En1 
	.byte	W12
	.byte		VOL   , 68*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        58*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        42*bgm_bijyutu_mvl/mxv
	.byte	W03
	.byte		        23*bgm_bijyutu_mvl/mxv
	.byte	W15
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N32   , An1 
	.byte	W18
	.byte		VOL   , 74*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        52*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        31*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        80*bgm_bijyutu_mvl/mxv
	.byte		N12   , En1 
	.byte	W12
	.byte		N96   , Dn1 
	.byte	W36
	.byte		VOL   , 80*bgm_bijyutu_mvl/mxv
	.byte	W05
	.byte		        75*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        68*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        63*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        57*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        45*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        32*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        10*bgm_bijyutu_mvl/mxv
	.byte	W06
	.byte		        7*bgm_bijyutu_mvl/mxv
	.byte	W13
	.byte	W96
	.byte	GOTO
	 .word	bgm_bijyutu_6_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_bijyutu:
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_bijyutu_pri	@ Priority
	.byte	bgm_bijyutu_rev	@ Reverb.

	.word	bgm_bijyutu_grp

	.word	bgm_bijyutu_1
	.word	bgm_bijyutu_2
	.word	bgm_bijyutu_3
	.word	bgm_bijyutu_4
	.word	bgm_bijyutu_5
	.word	bgm_bijyutu_6

	.end
