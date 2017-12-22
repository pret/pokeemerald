	.include "MPlayDef.s"

	.equ	mus_tetsuji_grp, voicegroup_867D528
	.equ	mus_tetsuji_pri, 0
	.equ	mus_tetsuji_rev, reverb_set+50
	.equ	mus_tetsuji_mvl, 127
	.equ	mus_tetsuji_key, 0
	.equ	mus_tetsuji_tbs, 1
	.equ	mus_tetsuji_exg, 0
	.equ	mus_tetsuji_cmp, 1

	.section .rodata
	.global	mus_tetsuji
	.align	2

@********************** Track  1 **********************@

mus_tetsuji_1:
	.byte	KEYSH , mus_tetsuji_key+0
mus_tetsuji_1_B1:
	.byte	TEMPO , 108*mus_tetsuji_tbs/2
	.byte		VOICE , 48
	.byte		PAN   , c_v-16
	.byte		LFOS  , 44
	.byte		VOL   , 37*mus_tetsuji_mvl/mxv
	.byte	W48
	.byte		N03   , Bn3 , v112
	.byte	W03
	.byte		N32   , Cn4 
	.byte	W32
	.byte	W01
	.byte		N12   , As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N24   , Cn4 
	.byte	W36
	.byte	W24
	.byte		N12   , En4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        Cs4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N03   , En4 
	.byte	W03
	.byte		N21   , Fn4 
	.byte	W21
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N48   , As3 
	.byte	W48
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N48   , Dn4 
	.byte	W48
	.byte		N03   , En4 
	.byte	W03
	.byte		N09   , Fn4 
	.byte	W09
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N72   , Gn3 
	.byte	W48
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N36   , En3 
	.byte	W36
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte	GOTO
	 .word	mus_tetsuji_1_B1
	.byte	W48
	.byte	FINE

@********************** Track  2 **********************@

mus_tetsuji_2:
	.byte	KEYSH , mus_tetsuji_key+0
mus_tetsuji_2_B1:
	.byte		VOICE , 73
	.byte		LFOS  , 44
	.byte		MOD   , 0
	.byte		VOL   , 44*mus_tetsuji_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Gn4 , v112
	.byte	W12
	.byte		VOICE , 48
	.byte		VOL   , 37*mus_tetsuji_mvl/mxv
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N03   , Gs4 
	.byte	W03
	.byte		N32   , An4 
	.byte	W21
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N24   , An4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , An4 , v032
	.byte	W12
	.byte	W24
	.byte		        An4 , v112
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Dn5 , v032
	.byte	W12
	.byte		        En5 , v112
	.byte	W12
	.byte		        En5 , v032
	.byte	W12
	.byte		        Fn5 , v112
	.byte	W12
	.byte		        Fn5 , v032
	.byte	W12
	.byte		        An4 , v112
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N03   , Cs5 
	.byte	W03
	.byte		N21   , Dn5 
	.byte	W09
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N48   , Fn4 
	.byte	W36
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N06   , As4 
	.byte	W06
	.byte		        As4 , v032
	.byte	W06
	.byte		N12   , As4 , v112
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N48   , Fn4 
	.byte	W36
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N03   , Cs5 
	.byte	W03
	.byte		N09   , Dn5 
	.byte	W09
	.byte		N06   , An4 
	.byte	W06
	.byte		        An4 , v032
	.byte	W06
	.byte		N12   , An4 , v112
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N72   , Fn4 
	.byte	W48
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N36   , Gn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , An4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        As4 , v032
	.byte	W12
	.byte		VOICE , 73
	.byte		VOL   , 50*mus_tetsuji_mvl/mxv
	.byte		N12   , An4 , v112
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N48   , Cn5 
	.byte	W36
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W12
	.byte		N24   
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Dn4 , v032
	.byte	W12
	.byte		        Fn4 , v112
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N48   , Gn4 
	.byte	W36
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Gn4 , v032
	.byte	W12
	.byte		N03   , En4 , v112
	.byte	W03
	.byte		N09   , Fn4 
	.byte	W09
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N06   , En4 
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte		N24   , En4 , v112
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Gn4 , v032
	.byte	W12
	.byte		VOICE , 48
	.byte		VOL   , 41*mus_tetsuji_mvl/mxv
	.byte		N12   , An4 , v112
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N48   , Cn5 
	.byte	W36
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Cn5 , v032
	.byte	W12
	.byte		        An4 , v112
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Dn5 , v032
	.byte	W12
	.byte		        Fn5 , v112
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		N48   , Gn5 
	.byte	W36
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Gn5 , v032
	.byte	W12
	.byte		N03   , En5 , v112
	.byte	W03
	.byte		N09   , Fn5 
	.byte	W09
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		N06   , En5 
	.byte	W06
	.byte		        En5 , v032
	.byte	W06
	.byte		N24   , En5 , v112
	.byte	W24
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N24   , Gn5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		VOICE , 73
	.byte		MOD   , 0
	.byte		VOL   , 50*mus_tetsuji_mvl/mxv
	.byte		N12   , As4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte	GOTO
	 .word	mus_tetsuji_2_B1
	.byte	W48
	.byte	FINE

@********************** Track  3 **********************@

mus_tetsuji_3:
	.byte	KEYSH , mus_tetsuji_key+0
mus_tetsuji_3_B1:
	.byte		VOICE , 35
	.byte		PAN   , c_v+0
	.byte		LFOS  , 44
	.byte		VOL   , 99*mus_tetsuji_mvl/mxv
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        Cn1 , v028
	.byte	W06
	.byte		N12   , Cn2 , v112
	.byte	W12
	.byte		N06   , Cn3 , v088
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		N12   , As1 , v112
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W24
	.byte		N12   , Fn1 , v028
	.byte	W12
	.byte		N06   , Fn1 , v112
	.byte	W06
	.byte		        Fn1 , v028
	.byte	W06
	.byte		        Cn2 , v112
	.byte	W06
	.byte		        Cn2 , v028
	.byte	W06
	.byte		N18   , Fn1 , v112
	.byte	W18
	.byte		N06   , Fn1 , v028
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v028
	.byte	W06
	.byte		N24   , An1 , v112
	.byte	W24
	.byte		N12   , An1 , v028
	.byte	W12
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v028
	.byte	W06
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v028
	.byte	W06
	.byte		N18   , An1 , v112
	.byte	W18
	.byte		N06   , An1 , v028
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v028
	.byte	W06
	.byte		N24   , Dn1 , v112
	.byte	W24
	.byte		N12   , Dn1 , v028
	.byte	W12
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v028
	.byte	W06
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v028
	.byte	W06
	.byte		N18   , An1 , v112
	.byte	W24
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        Gn1 , v028
	.byte	W06
	.byte		N24   , Cn1 , v112
	.byte	W24
	.byte		N12   , Cn1 , v028
	.byte	W12
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v028
	.byte	W06
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v028
	.byte	W06
	.byte		N12   , Fn1 , v112
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W24
	.byte		N12   , Fn1 , v028
	.byte	W12
	.byte		N06   , As0 , v112
	.byte	W06
	.byte		        As0 , v028
	.byte	W06
	.byte		        As1 , v112
	.byte	W06
	.byte		        As1 , v028
	.byte	W06
	.byte		N18   , As1 , v112
	.byte	W18
	.byte		N06   , As1 , v028
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v028
	.byte	W06
	.byte		N24   , Gn1 , v112
	.byte	W24
	.byte		N12   , Gn1 , v028
	.byte	W12
	.byte		N06   , Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v028
	.byte	W06
	.byte		        Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v028
	.byte	W06
	.byte		N18   , Gn1 , v112
	.byte	W18
	.byte		N06   , Gn1 , v028
	.byte	W06
	.byte		        As1 , v112
	.byte	W06
	.byte		        As1 , v028
	.byte	W06
	.byte		N24   , Cn2 , v112
	.byte	W24
	.byte		N12   , Cn2 , v028
	.byte	W12
	.byte		N06   , Cn2 , v112
	.byte	W06
	.byte		        Cn2 , v028
	.byte	W06
	.byte		        Gn2 , v112
	.byte	W06
	.byte		        Gn2 , v028
	.byte	W06
	.byte		N12   , Cn2 , v112
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N24   , En1 
	.byte	W24
	.byte		N12   , En1 , v028
	.byte	W12
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		        En1 , v028
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Cn1 , v028
	.byte	W06
	.byte		N12   , Cn2 , v112
	.byte	W12
	.byte		N06   , Cn3 , v088
	.byte	W06
	.byte		        Cn3 , v028
	.byte	W06
	.byte		N12   , As1 , v112
	.byte	W12
	.byte		N24   , Cn2 
	.byte	W24
	.byte		N12   , Cn2 , v028
	.byte	W12
	.byte		N06   , Cn2 , v112
	.byte	W06
	.byte		        Cn2 , v028
	.byte	W06
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v028
	.byte	W06
	.byte		N18   , Cs2 , v112
	.byte	W18
	.byte		N06   , Cs2 , v028
	.byte	W06
	.byte		        As1 , v112
	.byte	W06
	.byte		        As1 , v028
	.byte	W06
	.byte		N24   , An1 , v112
	.byte	W24
	.byte		N12   , An1 , v028
	.byte	W12
	.byte		N06   , Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v028
	.byte	W06
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v028
	.byte	W06
	.byte		N18   , Fn1 , v112
	.byte	W18
	.byte		N06   , Fn1 , v028
	.byte	W06
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v028
	.byte	W06
	.byte		N24   , As1 , v112
	.byte	W24
	.byte		N12   , As1 , v028
	.byte	W12
	.byte		N06   , Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v028
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v028
	.byte	W06
	.byte		N18   , Gn1 , v112
	.byte	W18
	.byte		N06   , Gn1 , v028
	.byte	W06
	.byte		        Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v028
	.byte	W06
	.byte		N24   , Cn2 , v112
	.byte	W24
	.byte		N12   , Cn2 , v028
	.byte	W12
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v028
	.byte	W06
	.byte		        As1 , v112
	.byte	W06
	.byte		        As1 , v028
	.byte	W06
	.byte		N18   , As1 , v112
	.byte	W18
	.byte		N06   , As1 , v028
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v028
	.byte	W06
	.byte		N24   , An1 , v112
	.byte	W24
	.byte		N12   , An1 , v028
	.byte	W12
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v028
	.byte	W06
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v028
	.byte	W06
	.byte		N18   , An1 , v112
	.byte	W18
	.byte		N06   , An1 , v028
	.byte	W06
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v028
	.byte	W06
	.byte		N24   , Fn1 , v112
	.byte	W24
	.byte		N12   , Fn1 , v028
	.byte	W12
	.byte		N06   , Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v028
	.byte	W06
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v028
	.byte	W06
	.byte		N18   , Bn1 , v112
	.byte	W18
	.byte		N06   , Bn1 , v028
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v028
	.byte	W06
	.byte		N24   , As1 , v112
	.byte	W24
	.byte		N12   , As1 , v028
	.byte	W12
	.byte		N06   , Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v028
	.byte	W06
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v028
	.byte	W06
	.byte		N18   , Bn1 , v112
	.byte	W18
	.byte		N06   , Bn1 , v028
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v028
	.byte	W06
	.byte		N24   , Cn2 , v112
	.byte	W24
	.byte		N12   , Cn2 , v028
	.byte	W12
	.byte		N06   , Fn2 , v112
	.byte	W06
	.byte		        Fn2 , v028
	.byte	W06
	.byte		        Cn2 , v112
	.byte	W06
	.byte		        Cn2 , v028
	.byte	W06
	.byte		N18   , Cn2 , v112
	.byte	W18
	.byte		N06   , Cn2 , v028
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v028
	.byte	W06
	.byte	GOTO
	 .word	mus_tetsuji_3_B1
	.byte	W48
	.byte	FINE

@********************** Track  4 **********************@

mus_tetsuji_4:
	.byte	KEYSH , mus_tetsuji_key+0
mus_tetsuji_4_B1:
	.byte		VOICE , 45
	.byte		LFOS  , 44
	.byte		PAN   , c_v+32
	.byte		VOL   , 62*mus_tetsuji_mvl/mxv
	.byte	W24
	.byte		N06   , As3 , v112
	.byte	W06
	.byte		N12   , As3 , v040
	.byte	W66
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W12
	.byte		VOICE , 0
	.byte		VOL   , 50*mus_tetsuji_mvl/mxv
	.byte	W84
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte	GOTO
	 .word	mus_tetsuji_4_B1
	.byte	W48
	.byte	FINE

@********************** Track  5 **********************@

mus_tetsuji_5:
	.byte	KEYSH , mus_tetsuji_key+0
mus_tetsuji_5_B1:
	.byte		VOICE , 1
	.byte		PAN   , c_v+0
	.byte		LFOS  , 44
	.byte		VOL   , 50*mus_tetsuji_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		N12   , An5 , v112
	.byte	W12
	.byte		        As5 
	.byte	W12
	.byte		N48   , Cn6 
	.byte	W48
	.byte		N12   , Cs6 
	.byte	W12
	.byte		        As5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		N06   , Fn5 
	.byte	W06
	.byte		        Fn5 , v036
	.byte	W06
	.byte		N24   , Fn5 , v112
	.byte	W24
	.byte		N12   , En5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Dn5 , v036
	.byte	W12
	.byte		        Fn5 , v112
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		N48   , Gn5 
	.byte	W48
	.byte		N12   , Gn5 , v036
	.byte	W12
	.byte		N03   , En5 , v112
	.byte	W03
	.byte		N09   , Fn5 
	.byte	W09
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		N06   , En5 
	.byte	W06
	.byte		        En5 , v036
	.byte	W06
	.byte		N24   , En5 , v112
	.byte	W24
	.byte		N12   , Fn5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		        Gn5 , v036
	.byte	W12
	.byte		        An5 , v112
	.byte	W12
	.byte		        As5 
	.byte	W12
	.byte		N48   , Cn6 
	.byte	W48
	.byte		N12   , Cn6 , v036
	.byte	W12
	.byte		        An5 , v112
	.byte	W12
	.byte		        Cs6 
	.byte	W12
	.byte		        En6 
	.byte	W12
	.byte		        Gn6 
	.byte	W12
	.byte		        Fn6 
	.byte	W12
	.byte		        En6 
	.byte	W12
	.byte		        Fn6 
	.byte	W12
	.byte		        Dn6 
	.byte	W12
	.byte		        Dn6 , v032
	.byte	W12
	.byte		        Fn6 , v112
	.byte	W12
	.byte		        An6 
	.byte	W12
	.byte		N48   , Gn6 
	.byte	W48
	.byte		N12   , Gn6 , v036
	.byte	W12
	.byte		N03   , En6 , v112
	.byte	W03
	.byte		N09   , Fn6 
	.byte	W09
	.byte		N12   , Dn6 
	.byte	W12
	.byte		        Fn6 
	.byte	W12
	.byte		N06   , En6 
	.byte	W06
	.byte		        En6 , v032
	.byte	W06
	.byte		N24   , En6 , v112
	.byte	W24
	.byte		N12   , Fn6 
	.byte	W12
	.byte		N24   , Gn6 
	.byte	W24
	.byte		N12   , As5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte	GOTO
	 .word	mus_tetsuji_5_B1
	.byte	W48
	.byte	FINE

@********************** Track  6 **********************@

mus_tetsuji_6:
	.byte	KEYSH , mus_tetsuji_key+0
mus_tetsuji_6_B1:
	.byte		VOICE , 45
	.byte		LFOS  , 44
	.byte		PAN   , c_v-32
	.byte		VOL   , 72*mus_tetsuji_mvl/mxv
	.byte		N06   , Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v040
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v040
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v040
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v040
	.byte	W54
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W12
	.byte		VOICE , 48
	.byte	W84
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte	GOTO
	 .word	mus_tetsuji_6_B1
	.byte	W48
	.byte	FINE

@********************** Track  7 **********************@

mus_tetsuji_7:
	.byte	KEYSH , mus_tetsuji_key+0
mus_tetsuji_7_B1:
	.byte		VOICE , 4
	.byte		PAN   , c_v-63
	.byte		XCMD  , xIECV , 12
	.byte		        xIECV , 8
	.byte		LFOS  , 44
	.byte		VOL   , 58*mus_tetsuji_mvl/mxv
	.byte	W48
	.byte		N06   , Fn2 , v112
	.byte	W06
	.byte		        Fn2 , v032
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        Fn2 , v112
	.byte	W06
	.byte		        Fn2 , v032
	.byte	W06
	.byte		VOICE , 4
	.byte		N06   , Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W06
	.byte		        An2 , v112
	.byte	W06
	.byte		        An2 , v032
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		        Gn2 , v112
	.byte	W06
	.byte		        Gn2 , v032
	.byte	W06
	.byte		        Cs3 , v112
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Cs3 , v112
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        As2 , v112
	.byte	W06
	.byte		        As2 , v032
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		        As2 , v112
	.byte	W06
	.byte		        As2 , v032
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		        Gn2 , v112
	.byte	W06
	.byte		        Gn2 , v032
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		        Gn2 , v112
	.byte	W06
	.byte		        Gn2 , v032
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        An2 , v112
	.byte	W06
	.byte		        An2 , v032
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		        An2 , v112
	.byte	W06
	.byte		        An2 , v032
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v032
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
mus_tetsuji_7_000:
	.byte		N06   , Bn2 , v112
	.byte	W06
	.byte		        Bn2 , v032
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		        As2 , v112
	.byte	W06
	.byte		        As2 , v032
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte	PEND
	.byte		        Gn2 , v112
	.byte	W06
	.byte		        Gn2 , v032
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		        As3 , v112
	.byte	W06
	.byte		        As3 , v032
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        An2 , v112
	.byte	W06
	.byte		        An2 , v032
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		        An2 , v112
	.byte	W06
	.byte		        An2 , v032
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v032
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte	PATT
	 .word	mus_tetsuji_7_000
	.byte		N06   , Bn2 , v112
	.byte	W06
	.byte		        Bn2 , v032
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W06
	.byte	GOTO
	 .word	mus_tetsuji_7_B1
	.byte	W48
	.byte	FINE

@********************** Track  8 **********************@

mus_tetsuji_8:
	.byte	KEYSH , mus_tetsuji_key+0
mus_tetsuji_8_B1:
	.byte		VOICE , 5
	.byte		PAN   , c_v+63
	.byte		XCMD  , xIECV , 12
	.byte		        xIECV , 8
	.byte		LFOS  , 44
	.byte		VOL   , 50*mus_tetsuji_mvl/mxv
	.byte	W72
	.byte		N06   , Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		        Fn2 , v112
	.byte	W06
	.byte		        Fn2 , v032
	.byte	W06
	.byte	W12
	.byte		VOICE , 5
	.byte	W12
	.byte		N06   , Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W30
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W18
	.byte	W24
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		        Cs3 , v112
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W30
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W18
	.byte	W24
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v032
	.byte	W42
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W18
	.byte	W24
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W30
	.byte		        As3 , v112
	.byte	W06
	.byte		        As3 , v032
	.byte	W18
	.byte	W24
	.byte		        As3 , v112
	.byte	W06
	.byte		        As3 , v032
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W30
	.byte		        As3 , v112
	.byte	W06
	.byte		        As3 , v032
	.byte	W18
	.byte	W24
	.byte		        As3 , v112
	.byte	W06
	.byte		        As3 , v032
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W30
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W18
	.byte	W24
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W42
	.byte		        As3 , v112
	.byte	W06
	.byte		        As3 , v032
	.byte	W18
	.byte	W24
	.byte		        As3 , v112
	.byte	W06
	.byte		        As3 , v032
	.byte	W42
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W18
mus_tetsuji_8_000:
	.byte	W24
	.byte		N06   , An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W42
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W18
	.byte	PEND
mus_tetsuji_8_001:
	.byte	W24
	.byte		N06   , An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W42
	.byte		        As3 , v112
	.byte	W06
	.byte		        As3 , v032
	.byte	W18
	.byte	PEND
	.byte	W24
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W42
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W18
	.byte	W24
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W42
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W18
	.byte	PATT
	 .word	mus_tetsuji_8_000
	.byte	PATT
	 .word	mus_tetsuji_8_001
	.byte	W24
	.byte		N06   , Bn3 , v112
	.byte	W06
	.byte		        Bn3 , v032
	.byte	W42
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W18
	.byte	W24
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W18
	.byte	GOTO
	 .word	mus_tetsuji_8_B1
	.byte	W48
	.byte	FINE

@********************** Track  9 **********************@

mus_tetsuji_9:
	.byte	KEYSH , mus_tetsuji_key+0
mus_tetsuji_9_B1:
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 40*mus_tetsuji_mvl/mxv
	.byte	W48
	.byte		N06   , Fs2 , v084
	.byte	W12
	.byte		        Fs2 , v064
	.byte	W12
	.byte		        Fs2 , v112
	.byte	W12
	.byte		        Fs2 , v068
	.byte	W12
mus_tetsuji_9_000:
	.byte		N06   , Fs2 , v084
	.byte	W12
	.byte		        Fs2 , v064
	.byte	W12
	.byte		        Fs2 , v112
	.byte	W12
	.byte		        Fs2 , v068
	.byte	W12
	.byte		        Fs2 , v084
	.byte	W12
	.byte		        Fs2 , v064
	.byte	W12
	.byte		        Fs2 , v112
	.byte	W12
	.byte		        Fs2 , v068
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_tetsuji_9_000
	.byte	PATT
	 .word	mus_tetsuji_9_000
	.byte	PATT
	 .word	mus_tetsuji_9_000
	.byte	PATT
	 .word	mus_tetsuji_9_000
	.byte	PATT
	 .word	mus_tetsuji_9_000
	.byte	PATT
	 .word	mus_tetsuji_9_000
	.byte	PATT
	 .word	mus_tetsuji_9_000
	.byte	PATT
	 .word	mus_tetsuji_9_000
	.byte	PATT
	 .word	mus_tetsuji_9_000
	.byte	PATT
	 .word	mus_tetsuji_9_000
	.byte	PATT
	 .word	mus_tetsuji_9_000
	.byte	PATT
	 .word	mus_tetsuji_9_000
	.byte	PATT
	 .word	mus_tetsuji_9_000
	.byte	PATT
	 .word	mus_tetsuji_9_000
	.byte		N06   , Fs2 , v084
	.byte	W12
	.byte		        Fs2 , v064
	.byte	W12
	.byte		        Fs2 , v112
	.byte	W12
	.byte		        Fs2 , v068
	.byte	W12
	.byte	GOTO
	 .word	mus_tetsuji_9_B1
	.byte	W48
	.byte	FINE

@******************************************************@
	.align	2

mus_tetsuji:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_tetsuji_pri	@ Priority
	.byte	mus_tetsuji_rev	@ Reverb.

	.word	mus_tetsuji_grp

	.word	mus_tetsuji_1
	.word	mus_tetsuji_2
	.word	mus_tetsuji_3
	.word	mus_tetsuji_4
	.word	mus_tetsuji_5
	.word	mus_tetsuji_6
	.word	mus_tetsuji_7
	.word	mus_tetsuji_8
	.word	mus_tetsuji_9

	.end
