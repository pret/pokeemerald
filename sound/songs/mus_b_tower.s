	.include "MPlayDef.s"

	.equ	mus_b_tower_grp, voicegroup_867D918
	.equ	mus_b_tower_pri, 0
	.equ	mus_b_tower_rev, reverb_set+50
	.equ	mus_b_tower_mvl, 127
	.equ	mus_b_tower_key, 0
	.equ	mus_b_tower_tbs, 1
	.equ	mus_b_tower_exg, 0
	.equ	mus_b_tower_cmp, 1

	.section .rodata
	.global	mus_b_tower
	.align	2

@********************** Track  1 **********************@

mus_b_tower_1:
	.byte	KEYSH , mus_b_tower_key+0
	.byte	TEMPO , 128*mus_b_tower_tbs/2
	.byte		VOICE , 56
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte		N06   , Cn3 , v112
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Cn4 
	.byte	W12
mus_b_tower_1_B1:
	.byte		N68   , Fn4 , v112
	.byte	W32
	.byte	W01
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 77*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        73*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        66*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        56*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        34*mus_b_tower_mvl/mxv
	.byte	W09
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte		N03   , Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N68   , Fn3 
	.byte	W32
	.byte	W01
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 77*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        73*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        66*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        56*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        34*mus_b_tower_mvl/mxv
	.byte	W09
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte		N06   , Cn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N68   , Fn4 
	.byte	W32
	.byte	W01
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 77*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        73*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        66*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        56*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        34*mus_b_tower_mvl/mxv
	.byte	W09
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte		N03   , Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N96   , Cn4 
	.byte	W32
	.byte	W01
	.byte		MOD   , 7
	.byte	W24
	.byte	W03
	.byte		VOL   , 77*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        73*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        66*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        56*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        34*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        21*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte	W72
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte		N06   , Cn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , An3 
	.byte	W12
	.byte		N06   , As3 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N24   , Fn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W18
	.byte		N06   , As3 
	.byte	W06
	.byte		N66   , Fn3 
	.byte	W24
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 77*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        73*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        66*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        52*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        34*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte	W06
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte		N06   , As3 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N24   , Fn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W18
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N66   , Dn4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 77*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        73*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        66*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        52*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        34*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte	W06
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte		N06   , Ds4 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N42   , As3 
	.byte	W18
	.byte		VOL   , 76*mus_b_tower_mvl/mxv
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 69*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        58*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        39*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte	W06
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte		N06   , Cn4 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Gs3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , As3 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N42   , An3 
	.byte	W18
	.byte		VOL   , 76*mus_b_tower_mvl/mxv
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 69*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        58*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        39*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte	W06
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte		N32   , As3 
	.byte	W18
	.byte		MOD   , 7
	.byte	W18
	.byte		        0
	.byte		N03   , Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N24   , Fn4 
	.byte	W24
	.byte		N09   , Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N90   , Ds4 
	.byte	W36
	.byte		MOD   , 7
	.byte	W24
	.byte		VOL   , 77*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        73*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        66*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        56*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        34*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        21*mus_b_tower_mvl/mxv
	.byte		MOD   , 0
	.byte	W06
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte		N32   
	.byte	W18
	.byte		MOD   , 7
	.byte	W18
	.byte		        0
	.byte		N03   , Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N09   , Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		MOD   , 0
	.byte		N32   , Dn4 
	.byte	W15
	.byte		MOD   , 7
	.byte	W09
	.byte		        0
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N42   , Cn4 
	.byte	W18
	.byte		VOL   , 76*mus_b_tower_mvl/mxv
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 69*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        58*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        39*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte	W06
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte		N32   , Dn4 
	.byte	W18
	.byte		MOD   , 7
	.byte	W15
	.byte		        0
	.byte	W03
	.byte		N03   , As3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N24   , Fn4 
	.byte	W24
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		MOD   , 0
	.byte		N36   , Gn4 
	.byte	W15
	.byte		MOD   , 7
	.byte	W09
	.byte		        0
	.byte	W12
	.byte		N09   , Fn4 
	.byte	W12
	.byte		N42   , Ds4 
	.byte	W18
	.byte		VOL   , 76*mus_b_tower_mvl/mxv
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 69*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        58*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        39*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte	W06
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , Fs4 
	.byte	W15
	.byte		MOD   , 7
	.byte	W21
	.byte		        0
	.byte		N09   , Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N30   , Cn4 
	.byte	W15
	.byte		MOD   , 7
	.byte	W15
	.byte		        0
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W24
	.byte		N06   , Cn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Cn4 
	.byte	W12
	.byte	GOTO
	 .word	mus_b_tower_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_b_tower_2:
	.byte	KEYSH , mus_b_tower_key+0
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte	W24
mus_b_tower_2_B1:
	.byte		VOICE , 48
	.byte		PAN   , c_v+18
	.byte		N30   , As4 , v080
	.byte	W36
	.byte		N06   , As3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N18   , As4 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N12   , As4 
	.byte	W12
	.byte		N32   , An4 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N24   , As4 
	.byte	W24
	.byte		N12   , An4 
	.byte	W12
	.byte		N30   , As4 
	.byte	W36
	.byte		N06   , As3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N24   , As4 
	.byte	W24
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N12   , As4 
	.byte	W12
	.byte		N32   , An4 
	.byte	W36
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N96   , Fn3 
	.byte	W60
	.byte		VOL   , 77*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        73*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        66*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        56*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        34*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        21*mus_b_tower_mvl/mxv
	.byte	W06
	.byte	W96
	.byte	W36
	.byte		        80*mus_b_tower_mvl/mxv
	.byte		N06   , Cn4 , v076
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N24   , Fn4 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N48   , Dn4 
	.byte	W24
	.byte		VOL   , 74*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        62*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        48*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        23*mus_b_tower_mvl/mxv
	.byte	W03
	.byte		        13*mus_b_tower_mvl/mxv
	.byte	W48
	.byte	W03
	.byte	W36
	.byte		        80*mus_b_tower_mvl/mxv
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N24   , As4 
	.byte	W24
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N06   , Gn4 
	.byte	W12
	.byte		N30   
	.byte	W12
	.byte		VOL   , 74*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        62*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        48*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        23*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        80*mus_b_tower_mvl/mxv
	.byte		N24   , Gn2 , v068
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		N06   , As2 
	.byte	W12
	.byte		N24   , Cn3 
	.byte	W24
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		N06   , Gs3 
	.byte	W12
	.byte		N21   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N44   , Cn4 
	.byte	W18
	.byte		VOL   , 75*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        69*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        61*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        49*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        28*mus_b_tower_mvl/mxv
	.byte	W06
	.byte	W96
	.byte		VOICE , 1
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte		N32   , Gn4 , v064
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N24   , As4 
	.byte	W24
	.byte		N09   , Ds5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        As4 
	.byte	W24
	.byte		N03   , Ds5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		        As4 
	.byte	W24
	.byte		N03   , Ds5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   , Dn5 
	.byte	W12
	.byte		        As4 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N12   , Ds5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N36   , Fn4 
	.byte	W36
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N24   , As4 
	.byte	W24
	.byte		N12   , Cn5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		N36   , Ds5 
	.byte	W36
	.byte		N12   , Fn5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		N24   , Fn5 
	.byte	W24
	.byte		N12   , Ds5 
	.byte	W12
	.byte		N06   , Cs5 
	.byte	W12
	.byte		        As4 
	.byte	W24
	.byte		N03   , Cs5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , As4 
	.byte	W24
	.byte		N09   , Fs4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N30   , An4 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W48
	.byte	GOTO
	 .word	mus_b_tower_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_b_tower_3:
	.byte	KEYSH , mus_b_tower_key+0
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte	W24
mus_b_tower_3_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 60
	.byte	W36
	.byte		PAN   , c_v-20
	.byte		N03   , Fn2 , v076
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        An2 
	.byte	W24
	.byte		N09   , Fn2 
	.byte	W12
	.byte		N48   , As2 
	.byte	W24
	.byte		VOL   , 74*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        62*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        48*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        23*mus_b_tower_mvl/mxv
	.byte	W03
	.byte		        13*mus_b_tower_mvl/mxv
	.byte	W48
	.byte	W03
	.byte	W36
	.byte		        80*mus_b_tower_mvl/mxv
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As2 
	.byte	W12
	.byte		        Dn3 
	.byte	W24
	.byte		        As2 
	.byte	W12
	.byte		N42   , Ds3 
	.byte	W24
	.byte		VOL   , 74*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        62*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        48*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        23*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        80*mus_b_tower_mvl/mxv
	.byte	W48
	.byte	W48
	.byte		N24   , As2 , v064
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		N06   , Cn3 , v056
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Ds3 , v060
	.byte	W12
	.byte		        Gs2 , v064
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gs2 , v068
	.byte	W12
	.byte		        Ds3 , v072
	.byte	W12
	.byte		        Gs2 , v076
	.byte	W12
	.byte		        Fn3 , v064
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N44   , Cn3 
	.byte	W18
	.byte		VOL   , 75*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        69*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        61*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        49*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        28*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        80*mus_b_tower_mvl/mxv
	.byte		N06   , As2 , v076
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N44   
	.byte	W18
	.byte		VOL   , 75*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        69*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        61*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        49*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        28*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        80*mus_b_tower_mvl/mxv
	.byte		N06   , Ds2 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N44   
	.byte	W18
	.byte		VOL   , 75*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        69*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        61*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        49*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        28*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        80*mus_b_tower_mvl/mxv
	.byte		N24   
	.byte	W24
	.byte		        Fn2 
	.byte	W24
	.byte		        Fs2 
	.byte	W24
	.byte		        Gs2 
	.byte	W24
	.byte		N06   , As2 
	.byte	W12
	.byte		N21   
	.byte	W09
	.byte		VOL   , 71*mus_b_tower_mvl/mxv
	.byte	W03
	.byte		        54*mus_b_tower_mvl/mxv
	.byte	W03
	.byte		        44*mus_b_tower_mvl/mxv
	.byte	W09
	.byte		        80*mus_b_tower_mvl/mxv
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		N09   , As2 
	.byte	W12
	.byte		        Fn2 
	.byte	W24
	.byte		N03   , As2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N24   , Cn3 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N09   , Ds3 
	.byte	W12
	.byte		        As2 
	.byte	W24
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N36   , As3 
	.byte	W36
	.byte		N09   , Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N30   , Fn3 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W48
	.byte	GOTO
	 .word	mus_b_tower_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_b_tower_4:
	.byte	KEYSH , mus_b_tower_key+0
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte	W24
mus_b_tower_4_B1:
	.byte		VOICE , 80
	.byte		PAN   , c_v-48
	.byte		N66   , Dn4 , v052
	.byte	W32
	.byte	W01
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 77*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        73*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        66*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        56*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        34*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        21*mus_b_tower_mvl/mxv
	.byte		MOD   , 0
	.byte	W06
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte		N03   , As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N66   , Cn4 
	.byte	W32
	.byte	W01
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 77*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        73*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        66*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        56*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        34*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        21*mus_b_tower_mvl/mxv
	.byte		MOD   , 0
	.byte	W30
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte		N66   , Dn4 
	.byte	W32
	.byte	W01
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 77*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        73*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        66*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        56*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        34*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        21*mus_b_tower_mvl/mxv
	.byte		MOD   , 0
	.byte	W06
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte		N03   , As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N96   , An3 
	.byte	W32
	.byte	W01
	.byte		MOD   , 6
	.byte	W24
	.byte	W03
	.byte		VOL   , 77*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        73*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        66*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        56*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        34*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        21*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte	W96
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte		N06   , Fn3 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W24
	.byte		N09   
	.byte	W12
	.byte		N06   , Cn3 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		        Fn3 
	.byte	W24
	.byte		        Cn3 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W24
	.byte		N09   
	.byte	W12
	.byte		N06   , Ds3 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   , Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W24
	.byte		        Fn3 
	.byte	W12
	.byte		VOICE , 4
	.byte		PAN   , c_v+0
	.byte		N06   , Ds3 , v060
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		VOICE , 80
	.byte		PAN   , c_v-48
	.byte		N06   , Fn3 , v052
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N36   
	.byte	W36
	.byte		N12   , As2 
	.byte	W12
	.byte		N32   , Ds3 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N09   , As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fs3 
	.byte	W24
	.byte		N03   , As3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		        Fs3 
	.byte	W24
	.byte		N03   , As3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		        Fn3 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N09   , As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N09   , Ds4 
	.byte	W12
	.byte		        As3 
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N09   , Cs4 
	.byte	W12
	.byte		        Cs3 
	.byte	W24
	.byte		N03   , As3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   , Cs3 
	.byte	W24
	.byte		        As2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N30   , Cn3 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W48
	.byte	GOTO
	 .word	mus_b_tower_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_b_tower_5:
	.byte	KEYSH , mus_b_tower_key+0
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte	W24
mus_b_tower_5_B1:
	.byte		VOICE , 82
	.byte		PAN   , c_v+48
	.byte		N12   , As3 , v052
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W09
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 77*mus_b_tower_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 73*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        66*mus_b_tower_mvl/mxv
	.byte		N18   
	.byte	W06
	.byte		VOL   , 56*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        34*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        21*mus_b_tower_mvl/mxv
	.byte		MOD   , 0
	.byte	W06
	.byte		VOICE , 82
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte		N03   , Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W09
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 77*mus_b_tower_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 73*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        66*mus_b_tower_mvl/mxv
	.byte		N18   
	.byte	W06
	.byte		VOL   , 56*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        34*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        21*mus_b_tower_mvl/mxv
	.byte		MOD   , 0
	.byte	W30
	.byte		VOICE , 82
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte		N12   , As3 
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W09
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 77*mus_b_tower_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 73*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        66*mus_b_tower_mvl/mxv
	.byte		N18   
	.byte	W06
	.byte		VOL   , 56*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        34*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        21*mus_b_tower_mvl/mxv
	.byte		MOD   , 0
	.byte	W06
	.byte		VOICE , 82
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte		N03   , Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W09
	.byte		MOD   , 6
	.byte	W03
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOL   , 77*mus_b_tower_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 73*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        66*mus_b_tower_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 56*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        34*mus_b_tower_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 21*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte	W96
	.byte		VOICE , 82
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte		N06   , Dn3 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W24
	.byte		N09   
	.byte	W12
	.byte		N06   , As2 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   , An2 
	.byte	W12
	.byte		        Cn3 
	.byte	W24
	.byte		        An2 
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W24
	.byte		N09   
	.byte	W12
	.byte		N06   , Cn3 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   , Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W12
	.byte		VOICE , 5
	.byte	W06
	.byte		N06   , Ds3 , v040
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		VOICE , 82
	.byte		N06   , Dn3 , v052
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N36   
	.byte	W36
	.byte		N12   , Fn2 
	.byte	W12
	.byte		N32   , As2 
	.byte	W36
	.byte		N06   , Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N09   , Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W24
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		        Ds3 
	.byte	W24
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   , Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N09   , Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N24   , As3 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N09   , As3 
	.byte	W12
	.byte		        Gn3 
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N24   , An3 
	.byte	W24
	.byte		N12   , As3 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        As2 
	.byte	W24
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   , As2 
	.byte	W24
	.byte		        Fs2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N30   , An2 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W48
	.byte	GOTO
	 .word	mus_b_tower_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_b_tower_6:
	.byte	KEYSH , mus_b_tower_key+0
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte	W24
mus_b_tower_6_B1:
	.byte		VOICE , 81
	.byte		N06   , As1 , v080
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		VOICE , 83
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 81
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W24
	.byte		N09   
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		VOICE , 83
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 81
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W24
	.byte		N09   
	.byte	W12
mus_b_tower_6_000:
	.byte		N06   , As1 , v080
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		VOICE , 83
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 81
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W24
	.byte		N09   
	.byte	W12
	.byte	PEND
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		VOICE , 83
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 81
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N24   , Fn2 
	.byte	W24
	.byte		        Ds2 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte	PATT
	 .word	mus_b_tower_6_000
	.byte		N06   , Fn1 , v080
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		VOICE , 83
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 81
	.byte		N09   
	.byte	W12
	.byte		        Cn2 
	.byte	W24
	.byte		        Fn1 
	.byte	W12
	.byte	PATT
	 .word	mus_b_tower_6_000
	.byte		N06   , Gs1 , v080
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		VOICE , 83
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 81
	.byte		N09   , As1 
	.byte	W12
	.byte		        Fn2 
	.byte	W24
	.byte		        As1 
	.byte	W12
	.byte		N12   , Ds2 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N48   , Fn1 
	.byte	W48
	.byte		N09   , As1 
	.byte	W12
	.byte		        Fn2 
	.byte	W24
	.byte		VOICE , 83
	.byte		N03   , As1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 81
	.byte		N06   
	.byte	W12
	.byte		N12   , Fn2 
	.byte	W24
	.byte		N09   , As1 
	.byte	W12
mus_b_tower_6_001:
	.byte		N09   , Ds1 , v080
	.byte	W12
	.byte		        As1 
	.byte	W24
	.byte		VOICE , 83
	.byte		N03   , Ds1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 81
	.byte		N06   
	.byte	W12
	.byte		N12   , As1 
	.byte	W24
	.byte		N09   , Ds1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_b_tower_6_001
	.byte		N09   , As1 , v080
	.byte	W12
	.byte		        Fn2 
	.byte	W24
	.byte		VOICE , 83
	.byte		N03   , As1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 81
	.byte		N12   , Fn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N09   , As1 
	.byte	W12
	.byte		        Fn1 
	.byte	W24
	.byte		VOICE , 83
	.byte		N03   , As1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 81
	.byte		N12   
	.byte	W12
	.byte		N24   , Cn2 
	.byte	W24
	.byte		N12   , Dn2 
	.byte	W12
	.byte		N09   , Ds2 
	.byte	W12
	.byte		        As1 
	.byte	W24
	.byte		VOICE , 83
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 81
	.byte		N12   
	.byte	W12
	.byte		N24   , Fn2 
	.byte	W24
	.byte		N12   , Gn2 
	.byte	W12
	.byte		N09   , Fs2 
	.byte	W12
	.byte		        Fs1 
	.byte	W24
	.byte		VOICE , 83
	.byte		N03   , Cs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 81
	.byte		N09   , Fs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W24
	.byte		VOICE , 83
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   , Fn1 
	.byte	W12
	.byte		N12   , Fn2 
	.byte	W24
	.byte		VOICE , 83
	.byte		N03   , Fn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 81
	.byte		N12   
	.byte	W48
	.byte	GOTO
	 .word	mus_b_tower_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_b_tower_7:
	.byte	KEYSH , mus_b_tower_key+0
	.byte		PAN   , c_v-8
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte	W24
mus_b_tower_7_B1:
	.byte		VOICE , 47
	.byte		N24   , As1 , v127
	.byte	W72
	.byte		N24   
	.byte	W24
mus_b_tower_7_000:
	.byte		N24   , Fn2 , v127
	.byte	W84
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte		N24   , As1 
	.byte	W72
	.byte		N24   
	.byte	W24
	.byte	PATT
	 .word	mus_b_tower_7_000
	.byte		N24   , Fn2 , v127
	.byte	W24
	.byte		        Ds2 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        As1 
	.byte	W96
	.byte	W36
	.byte		N06   , Fn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N24   , Cn2 
	.byte	W24
	.byte		N12   , Fn2 
	.byte	W12
	.byte		N24   , As1 
	.byte	W96
	.byte	W36
	.byte		N06   , Gs2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Fn2 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   , Ds2 
	.byte	W72
	.byte		N12   
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N06   , Dn2 , v116
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn2 , v127
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Dn2 , v116
	.byte	W06
	.byte		N24   , Cn2 , v127
	.byte	W72
	.byte		N12   , Ds2 , v120
	.byte	W12
	.byte		        Cn2 , v127
	.byte	W12
	.byte		N24   , As1 
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
	 .word	mus_b_tower_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_b_tower_8:
	.byte	KEYSH , mus_b_tower_key+0
	.byte		VOICE , 0
	.byte	W24
mus_b_tower_8_B1:
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte		N72   , Bn2 , v092
	.byte	W96
	.byte	W96
	.byte		N72   
	.byte	W96
	.byte	W96
	.byte		N36   
	.byte	W36
	.byte	W03
	.byte		N09   
	.byte	W09
	.byte		N48   
	.byte	W48
	.byte		N96   
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		VOL   , 40*mus_b_tower_mvl/mxv
	.byte		N48   , An2 , v064
	.byte	W09
	.byte		VOL   , 49*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        57*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        64*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        73*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        77*mus_b_tower_mvl/mxv
	.byte	W06
	.byte		        80*mus_b_tower_mvl/mxv
	.byte	W09
	.byte		N96   , Bn2 , v092
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_b_tower_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_b_tower_9:
	.byte	KEYSH , mus_b_tower_key+0
	.byte		VOICE , 0
	.byte		VOL   , 80*mus_b_tower_mvl/mxv
	.byte	W24
mus_b_tower_9_B1:
mus_b_tower_9_000:
	.byte	W60
	.byte		N06   , En1 , v092
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v112
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_b_tower_9_000
	.byte	PATT
	 .word	mus_b_tower_9_000
	.byte	PATT
	 .word	mus_b_tower_9_000
	.byte		N06   , En1 , v112
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        En1 , v092
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 , v068
	.byte	W03
	.byte		        En1 , v072
	.byte	W03
	.byte		        En1 , v080
	.byte	W03
	.byte		        En1 , v084
	.byte	W03
	.byte		        En1 , v088
	.byte	W03
	.byte		        En1 , v092
	.byte	W03
	.byte		        En1 , v096
	.byte	W03
	.byte		        En1 , v100
	.byte	W03
	.byte		N24   , En1 , v112
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_b_tower_9_001:
	.byte		N06   , En1 , v092
	.byte	W06
	.byte		        En1 , v060
	.byte	W06
	.byte		        En1 , v048
	.byte	W06
	.byte		        En1 , v032
	.byte	W06
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v092
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v092
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
mus_b_tower_9_002:
	.byte		N06   , En1 , v092
	.byte	W06
	.byte		        En1 , v076
	.byte	W06
	.byte		        En1 , v092
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v092
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v060
	.byte	W06
	.byte		        En1 , v048
	.byte	W06
	.byte		        En1 , v032
	.byte	W06
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v092
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_b_tower_9_001
	.byte		N06   , En1 , v092
	.byte	W06
	.byte		        En1 , v076
	.byte	W06
	.byte		        En1 , v092
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v092
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v060
	.byte	W06
	.byte		        En1 , v048
	.byte	W06
	.byte		        En1 , v032
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		N03   , En1 , v072
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v092
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PATT
	 .word	mus_b_tower_9_001
	.byte	PATT
	 .word	mus_b_tower_9_002
	.byte	PATT
	 .word	mus_b_tower_9_001
	.byte		N06   , En1 , v092
	.byte	W06
	.byte		        En1 , v076
	.byte	W06
	.byte		        En1 , v092
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v092
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v112
	.byte	W48
	.byte	GOTO
	 .word	mus_b_tower_9_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_b_tower:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_b_tower_pri	@ Priority
	.byte	mus_b_tower_rev	@ Reverb.

	.word	mus_b_tower_grp

	.word	mus_b_tower_1
	.word	mus_b_tower_2
	.word	mus_b_tower_3
	.word	mus_b_tower_4
	.word	mus_b_tower_5
	.word	mus_b_tower_6
	.word	mus_b_tower_7
	.word	mus_b_tower_8
	.word	mus_b_tower_9

	.end
