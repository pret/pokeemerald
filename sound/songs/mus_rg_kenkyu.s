	.include "MPlayDef.s"

	.equ	mus_rg_kenkyu_grp, voicegroup160
	.equ	mus_rg_kenkyu_pri, 0
	.equ	mus_rg_kenkyu_rev, reverb_set+50
	.equ	mus_rg_kenkyu_mvl, 127
	.equ	mus_rg_kenkyu_key, 0
	.equ	mus_rg_kenkyu_tbs, 1
	.equ	mus_rg_kenkyu_exg, 0
	.equ	mus_rg_kenkyu_cmp, 1

	.section .rodata
	.global	mus_rg_kenkyu
	.align	2

@********************** Track  1 **********************@

mus_rg_kenkyu_1:
	.byte	KEYSH , mus_rg_kenkyu_key+0
	.byte	TEMPO , 120*mus_rg_kenkyu_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 39*mus_rg_kenkyu_mvl/mxv
	.byte		PAN   , c_v-21
	.byte		N06   , An2 , v127
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
mus_rg_kenkyu_1_B1:
	.byte		N24   , Bn3 , v127
	.byte	W24
	.byte		N12   , An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W24
	.byte		N36   , Fs3 
	.byte	W36
	.byte		N03   , Dn3 , v120
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N24   , En3 
	.byte	W24
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W24
	.byte		N36   , Dn3 
	.byte	W36
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N24   , Fs3 , v127
	.byte	W24
	.byte		N36   , Gn3 
	.byte	W36
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N48   , Cn4 
	.byte	W48
	.byte		N36   , Bn3 
	.byte	W36
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N48   , Dn4 
	.byte	W48
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		N06   , Fs3 
	.byte	W24
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		N12   , An3 
	.byte	W12
	.byte		N06   , As3 , v120
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_kenkyu_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_kenkyu_2:
	.byte	KEYSH , mus_rg_kenkyu_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 75*mus_rg_kenkyu_mvl/mxv
	.byte		N06   , Fs3 , v127
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		MOD   , 0
	.byte		N06   , Fs4 
	.byte	W06
mus_rg_kenkyu_2_B1:
	.byte		N36   , Gn4 , v116
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 62*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        75*mus_rg_kenkyu_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N36   , Dn4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 62*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        75*mus_rg_kenkyu_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W24
	.byte		N48   , Dn4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 62*mus_rg_kenkyu_mvl/mxv
	.byte	W24
	.byte		        75*mus_rg_kenkyu_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   
	.byte	W24
	.byte		N36   , En4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 62*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        75*mus_rg_kenkyu_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N36   , Bn3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 62*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        75*mus_rg_kenkyu_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W24
	.byte		N48   , Bn3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 62*mus_rg_kenkyu_mvl/mxv
	.byte	W24
	.byte		        75*mus_rg_kenkyu_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   
	.byte	W24
	.byte		N36   , Cn4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 62*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        75*mus_rg_kenkyu_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N48   , En4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 62*mus_rg_kenkyu_mvl/mxv
	.byte	W24
	.byte		        75*mus_rg_kenkyu_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , Dn4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 62*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        75*mus_rg_kenkyu_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N48   , Gn4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 62*mus_rg_kenkyu_mvl/mxv
	.byte	W24
	.byte		        75*mus_rg_kenkyu_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Fs4 
	.byte	W12
	.byte		VOL   , 62*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        75*mus_rg_kenkyu_mvl/mxv
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N24   , En4 
	.byte	W12
	.byte		VOL   , 62*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        75*mus_rg_kenkyu_mvl/mxv
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N06   , En4 
	.byte	W12
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_kenkyu_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_kenkyu_3:
	.byte	KEYSH , mus_rg_kenkyu_key+0
	.byte		VOICE , 35
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+11
	.byte		VOL   , 73*mus_rg_kenkyu_mvl/mxv
	.byte		N06   , Gn1 , v120
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Gn2 , v127
	.byte	W06
	.byte		        Fs2 , v120
	.byte	W06
	.byte		        En2 , v127
	.byte	W06
	.byte		        Dn2 , v120
	.byte	W06
	.byte		        Cn2 , v127
	.byte	W06
	.byte		        Bn1 , v120
	.byte	W06
mus_rg_kenkyu_3_B1:
	.byte		N12   , Gn1 , v127
	.byte	W12
	.byte		N03   , Dn2 
	.byte	W12
	.byte		N12   , Cs2 , v120
	.byte	W12
	.byte		N03   , Dn2 , v127
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N03   , Dn2 
	.byte	W12
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W12
	.byte		N12   , Dn2 , v120
	.byte	W12
	.byte		N03   , Fs2 , v127
	.byte	W12
	.byte		        Bn1 , v120
	.byte	W06
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W06
	.byte		N06   , Fs2 , v127
	.byte	W06
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		N03   , Bn1 
	.byte	W12
	.byte		N12   , As1 , v120
	.byte	W12
	.byte		N03   , Bn1 , v127
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N03   , Bn1 
	.byte	W12
	.byte		N12   , Fs1 
	.byte	W12
	.byte		N03   , Dn2 
	.byte	W12
	.byte		N12   , Bn1 , v120
	.byte	W12
	.byte		N03   , Dn2 , v127
	.byte	W12
	.byte		        Fs1 , v120
	.byte	W06
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N03   , Dn2 , v127
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , Dn2 , v120
	.byte	W06
	.byte		N06   , Bn1 
	.byte	W06
	.byte		N03   , Dn2 , v127
	.byte	W06
	.byte		N06   , Fs2 , v120
	.byte	W06
	.byte		N12   , Cn2 , v127
	.byte	W12
	.byte		N03   , En2 
	.byte	W24
	.byte		N03   
	.byte	W18
	.byte		        Cn2 , v120
	.byte	W06
	.byte		N06   , Gn1 , v127
	.byte	W06
	.byte		N03   , Gn2 , v120
	.byte	W06
	.byte		N12   , Cn2 , v127
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W12
	.byte		N12   , Dn2 
	.byte	W12
	.byte		N03   , Gn2 
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N06   , Dn2 , v120
	.byte	W06
	.byte		N03   , Bn1 , v127
	.byte	W06
	.byte		N06   , Gn1 , v120
	.byte	W06
	.byte		N03   , Bn1 , v127
	.byte	W06
	.byte		N06   , Gn2 , v120
	.byte	W06
	.byte		N12   , An1 , v127
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W12
	.byte		N12   , Fn2 , v120
	.byte	W12
	.byte		N03   , Fs2 , v127
	.byte	W12
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N03   , En2 
	.byte	W12
	.byte		N12   , Dn2 , v120
	.byte	W12
	.byte		N03   , An1 , v127
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W24
	.byte		N12   , Fs2 
	.byte	W12
	.byte		N03   , Dn2 , v120
	.byte	W12
	.byte		N12   , En2 , v127
	.byte	W12
	.byte		N03   , Cn2 , v120
	.byte	W12
	.byte		N12   , Dn2 , v127
	.byte	W12
	.byte		N03   , An1 , v120
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_kenkyu_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_kenkyu_4:
	.byte	KEYSH , mus_rg_kenkyu_key+0
	.byte		VOICE , 14
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 50*mus_rg_kenkyu_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W48
mus_rg_kenkyu_4_B1:
	.byte		PAN   , c_v-32
	.byte		VOL   , 50*mus_rg_kenkyu_mvl/mxv
	.byte		N24   , Gn4 , v096
	.byte	W12
	.byte		VOL   , 30*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		VOL   , 20*mus_rg_kenkyu_mvl/mxv
	.byte		N24   
	.byte	W12
	.byte		VOL   , 10*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        50*mus_rg_kenkyu_mvl/mxv
	.byte		N24   , Dn4 
	.byte	W12
	.byte		VOL   , 30*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		VOL   , 20*mus_rg_kenkyu_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		VOL   , 50*mus_rg_kenkyu_mvl/mxv
	.byte		N06   , Cs4 , v064
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		VOL   , 50*mus_rg_kenkyu_mvl/mxv
	.byte		N24   , En4 , v096
	.byte	W12
	.byte		VOL   , 30*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		VOL   , 20*mus_rg_kenkyu_mvl/mxv
	.byte		N24   
	.byte	W12
	.byte		VOL   , 10*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        50*mus_rg_kenkyu_mvl/mxv
	.byte		N24   , Dn4 
	.byte	W12
	.byte		VOL   , 30*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		VOL   , 20*mus_rg_kenkyu_mvl/mxv
	.byte		N24   
	.byte	W12
	.byte		VOL   , 10*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        50*mus_rg_kenkyu_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N24   , En4 
	.byte	W12
	.byte		VOL   , 30*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        20*mus_rg_kenkyu_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N24   
	.byte	W12
	.byte		VOL   , 10*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        50*mus_rg_kenkyu_mvl/mxv
	.byte		N24   , Bn3 
	.byte	W12
	.byte		VOL   , 30*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        20*mus_rg_kenkyu_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N12   
	.byte	W12
	.byte		VOL   , 50*mus_rg_kenkyu_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N06   , An3 , v064
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		VOL   , 50*mus_rg_kenkyu_mvl/mxv
	.byte		N24   , Cn4 , v096
	.byte	W12
	.byte		VOL   , 30*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        20*mus_rg_kenkyu_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N24   
	.byte	W12
	.byte		VOL   , 10*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        50*mus_rg_kenkyu_mvl/mxv
	.byte		N24   , Bn3 
	.byte	W12
	.byte		VOL   , 30*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        20*mus_rg_kenkyu_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N24   
	.byte	W12
	.byte		VOL   , 10*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        50*mus_rg_kenkyu_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N24   , Cn4 
	.byte	W12
	.byte		VOL   , 30*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        20*mus_rg_kenkyu_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N24   
	.byte	W12
	.byte		VOL   , 10*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        50*mus_rg_kenkyu_mvl/mxv
	.byte		N24   , En4 
	.byte	W12
	.byte		VOL   , 30*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        20*mus_rg_kenkyu_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N24   
	.byte	W12
	.byte		VOL   , 10*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        50*mus_rg_kenkyu_mvl/mxv
	.byte		N24   , Dn4 
	.byte	W12
	.byte		VOL   , 30*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        20*mus_rg_kenkyu_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N24   
	.byte	W12
	.byte		VOL   , 10*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        50*mus_rg_kenkyu_mvl/mxv
	.byte		N24   , Gn4 
	.byte	W12
	.byte		VOL   , 30*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        20*mus_rg_kenkyu_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N24   
	.byte	W12
	.byte		VOL   , 10*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        50*mus_rg_kenkyu_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N24   , Fs4 
	.byte	W12
	.byte		VOL   , 30*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        50*mus_rg_kenkyu_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N24   , Gn4 
	.byte	W12
	.byte		VOL   , 30*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        50*mus_rg_kenkyu_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N24   , En4 
	.byte	W12
	.byte		VOL   , 30*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        50*mus_rg_kenkyu_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N24   , Fs4 
	.byte	W12
	.byte		VOL   , 30*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		VOL   , 50*mus_rg_kenkyu_mvl/mxv
	.byte		N24   , Dn4 
	.byte	W12
	.byte		VOL   , 30*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        20*mus_rg_kenkyu_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N24   , Dn4 , v120
	.byte	W12
	.byte		VOL   , 10*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		        50*mus_rg_kenkyu_mvl/mxv
	.byte		N24   , Fs4 , v096
	.byte	W12
	.byte		VOL   , 30*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		VOL   , 20*mus_rg_kenkyu_mvl/mxv
	.byte		N24   , Fs4 , v120
	.byte	W12
	.byte		VOL   , 10*mus_rg_kenkyu_mvl/mxv
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_kenkyu_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_kenkyu_5:
	.byte	KEYSH , mus_rg_kenkyu_key+0
	.byte		VOICE , 81
	.byte		PAN   , c_v+0
	.byte		VOL   , 24*mus_rg_kenkyu_mvl/mxv
	.byte		N06   , Dn3 , v120
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
mus_rg_kenkyu_5_B1:
	.byte		PAN   , c_v-64
	.byte		N01   , Dn3 , v120
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Bn2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Cn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Cs3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Dn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , En3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Fs3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , En3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Dn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Bn2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Cn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Cs3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Dn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , En3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Fs3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Gn3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , As3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Bn3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Fs3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Gn3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Dn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , En3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Bn2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Cn3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Dn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Bn2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Cn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Cs3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Dn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , En3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Fs3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Gn3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , En3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Bn2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Cn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Dn3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , En3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Fs3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Gn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , An3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Gn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , En3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Fs3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Dn3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , En3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Fs3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , En3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Dn3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , En3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Fs3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , En3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Dn3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Bn2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Cn3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Bn2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , An2 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Gn2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , An2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Bn2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Cn3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Dn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Cs3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Cn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Bn2 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , En3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Gn2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , En3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Gn3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , En3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Cn3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , En3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Gn3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , En3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Gn3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , En3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Cn3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Gn2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , En2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Bn2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Cn3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Gn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Bn2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Fs3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Gn3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Dn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Bn2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Fs3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Gn3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Bn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , An3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Gn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Fs3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Gn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Dn3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , En3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Cn3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Dn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , En3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Fs3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , An3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Gn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Fs3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , En3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Dn3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Cn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Dn3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Fs3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , An3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , En3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Dn3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Cn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Bn2 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Dn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , An2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Cn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Dn3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Fs3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , An3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Fs3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Dn3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Cs3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Dn3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , An2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Fs2 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Dn2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Fs2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , An2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N01   , Cs3 
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_kenkyu_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_kenkyu_6:
	.byte	KEYSH , mus_rg_kenkyu_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 25*mus_rg_kenkyu_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N06   , Gn1 , v120
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Gn2 , v127
	.byte	W06
	.byte		        Fs2 , v120
	.byte	W06
	.byte		        En2 , v127
	.byte	W06
	.byte		        Dn2 , v120
	.byte	W06
	.byte		        Cn2 , v127
	.byte	W06
	.byte		        Bn1 , v120
	.byte	W06
mus_rg_kenkyu_6_B1:
	.byte		N12   , Gn1 , v127
	.byte	W12
	.byte		N03   , Dn2 
	.byte	W12
	.byte		N12   , Cs2 , v120
	.byte	W12
	.byte		N03   , Dn2 , v127
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N03   , Dn2 
	.byte	W12
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W12
	.byte		N12   , Dn2 , v120
	.byte	W12
	.byte		N03   , Fs2 , v127
	.byte	W12
	.byte		        Bn1 , v120
	.byte	W06
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W06
	.byte		N06   , Fs2 , v127
	.byte	W06
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		N03   , Bn1 
	.byte	W12
	.byte		N12   , As1 , v120
	.byte	W12
	.byte		N03   , Bn1 , v127
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N03   , Bn1 
	.byte	W12
	.byte		N12   , Fs1 
	.byte	W12
	.byte		N03   , Dn2 
	.byte	W12
	.byte		N12   , Bn1 , v120
	.byte	W12
	.byte		N03   , Dn2 , v127
	.byte	W12
	.byte		        Fs1 , v120
	.byte	W06
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N03   , Dn2 , v127
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , Dn2 , v120
	.byte	W06
	.byte		N06   , Bn1 
	.byte	W06
	.byte		N03   , Dn2 , v127
	.byte	W06
	.byte		N06   , Fs2 , v120
	.byte	W06
	.byte		N12   , Cn2 , v127
	.byte	W12
	.byte		N03   , En2 
	.byte	W24
	.byte		N03   
	.byte	W18
	.byte		        Cn2 , v120
	.byte	W06
	.byte		N06   , Gn1 , v127
	.byte	W06
	.byte		N03   , Gn2 , v120
	.byte	W06
	.byte		N12   , Cn2 , v127
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W12
	.byte		N12   , Dn2 
	.byte	W12
	.byte		N03   , Gn2 
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N06   , Dn2 , v120
	.byte	W06
	.byte		N03   , Bn1 , v127
	.byte	W06
	.byte		N06   , Gn1 , v120
	.byte	W06
	.byte		N03   , Bn1 , v127
	.byte	W06
	.byte		N06   , Gn2 , v120
	.byte	W06
	.byte		N12   , An1 , v127
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W12
	.byte		N12   , Fn2 , v120
	.byte	W12
	.byte		N03   , Fs2 , v127
	.byte	W12
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N03   , En2 
	.byte	W12
	.byte		N12   , Dn2 , v120
	.byte	W12
	.byte		N03   , An1 , v127
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W24
	.byte		N12   , Fs2 
	.byte	W12
	.byte		N03   , Dn2 , v120
	.byte	W12
	.byte		N12   , En2 , v127
	.byte	W12
	.byte		N03   , Cn2 , v120
	.byte	W12
	.byte		N12   , Dn2 , v127
	.byte	W12
	.byte		N03   , An1 , v120
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_kenkyu_6_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_kenkyu:
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_kenkyu_pri	@ Priority
	.byte	mus_rg_kenkyu_rev	@ Reverb.

	.word	mus_rg_kenkyu_grp

	.word	mus_rg_kenkyu_1
	.word	mus_rg_kenkyu_2
	.word	mus_rg_kenkyu_3
	.word	mus_rg_kenkyu_4
	.word	mus_rg_kenkyu_5
	.word	mus_rg_kenkyu_6

	.end
