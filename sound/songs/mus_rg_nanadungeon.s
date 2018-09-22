	.include "MPlayDef.s"

	.equ	mus_rg_nanadungeon_grp, voicegroup147
	.equ	mus_rg_nanadungeon_pri, 0
	.equ	mus_rg_nanadungeon_rev, reverb_set+50
	.equ	mus_rg_nanadungeon_mvl, 127
	.equ	mus_rg_nanadungeon_key, 0
	.equ	mus_rg_nanadungeon_tbs, 1
	.equ	mus_rg_nanadungeon_exg, 0
	.equ	mus_rg_nanadungeon_cmp, 1

	.section .rodata
	.global	mus_rg_nanadungeon
	.align	2

@********************** Track  1 **********************@

mus_rg_nanadungeon_1:
	.byte	KEYSH , mus_rg_nanadungeon_key+0
mus_rg_nanadungeon_1_B1:
	.byte	TEMPO , 110*mus_rg_nanadungeon_tbs/2
	.byte		VOICE , 1
	.byte		PAN   , c_v+16
	.byte		VOL   , 65*mus_rg_nanadungeon_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N12   , Bn2 , v088
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
mus_rg_nanadungeon_1_000:
	.byte		N12   , Bn2 , v088
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_nanadungeon_1_000
	.byte		N12   , Bn2 , v088
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        En3 
	.byte	W12
mus_rg_nanadungeon_1_001:
	.byte		N12   , En3 , v088
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_nanadungeon_1_001
	.byte	PATT
	 .word	mus_rg_nanadungeon_1_001
	.byte	PATT
	 .word	mus_rg_nanadungeon_1_001
	.byte	PATT
	 .word	mus_rg_nanadungeon_1_000
	.byte	PATT
	 .word	mus_rg_nanadungeon_1_000
	.byte	PATT
	 .word	mus_rg_nanadungeon_1_000
	.byte	PATT
	 .word	mus_rg_nanadungeon_1_000
	.byte		N12   , Fn4 , v088
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte	TEMPO , 112*mus_rg_nanadungeon_tbs/2
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte	TEMPO , 98*mus_rg_nanadungeon_tbs/2
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte	TEMPO , 90*mus_rg_nanadungeon_tbs/2
	.byte		        An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte	TEMPO , 82*mus_rg_nanadungeon_tbs/2
	.byte		        Gs1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte	TEMPO , 78*mus_rg_nanadungeon_tbs/2
	.byte		        Gn1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte	TEMPO , 74*mus_rg_nanadungeon_tbs/2
	.byte		        Fs1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte	TEMPO , 66*mus_rg_nanadungeon_tbs/2
	.byte		        Fn1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte	TEMPO , 12*mus_rg_nanadungeon_tbs/2
	.byte		        Cn2 
	.byte	W06
	.byte	TEMPO , 110*mus_rg_nanadungeon_tbs/2
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N12   
	.byte	W12
mus_rg_nanadungeon_1_002:
	.byte		N12   , Ds3 , v088
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_nanadungeon_1_002
	.byte	PATT
	 .word	mus_rg_nanadungeon_1_002
	.byte	PATT
	 .word	mus_rg_nanadungeon_1_002
mus_rg_nanadungeon_1_003:
	.byte		N12   , An2 , v088
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_nanadungeon_1_003
	.byte	PATT
	 .word	mus_rg_nanadungeon_1_003
	.byte		N12   , Cs3 , v088
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
mus_rg_nanadungeon_1_004:
	.byte		N12   , Gs3 , v088
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_nanadungeon_1_004
	.byte		N12   , Gs3 , v088
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte	W96
	.byte	W48
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N36   , Cs3 
	.byte	W12
	.byte	W24
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N36   , Cs3 
	.byte	W36
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N36   , Cs3 
	.byte	W36
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N36   , Cs3 
	.byte	W36
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 , v064
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn2 , v080
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn2 , v096
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_nanadungeon_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_nanadungeon_2:
	.byte	KEYSH , mus_rg_nanadungeon_key+0
mus_rg_nanadungeon_2_B1:
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 73*mus_rg_nanadungeon_mvl/mxv
	.byte		N12   , Ds4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N12   , Ds4 , v016
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Cs4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N12   , Cs4 , v016
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Bn3 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Ds4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Ds4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N12   , Cs4 , v016
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Bn3 , v096
	.byte	W12
	.byte		        Cs4 
	.byte	W12
mus_rg_nanadungeon_2_000:
	.byte		MOD   , 0
	.byte		N12   , Ds4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Ds4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N12   , Cs4 , v016
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Bn3 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , As3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte	PEND
mus_rg_nanadungeon_2_001:
	.byte		MOD   , 0
	.byte		N12   , Bn3 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N12   , Bn3 , v016
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Cs4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N12   , Cs4 , v016
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Cs4 , v012
	.byte	W12
	.byte	PEND
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Gs4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N12   , Gs4 , v016
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Fs4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N12   , Fs4 , v016
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , En4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Fs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cn5 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Fs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N12   , Fs4 , v016
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , En4 , v096
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		MOD   , 0
	.byte		N12   , Gs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cn5 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Fs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N12   , Fs4 , v016
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , En4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Ds4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , En4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N12   , En4 , v016
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Fs4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N12   , Fs4 , v016
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , En4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N12   , En4 , v016
	.byte	W12
	.byte		VOICE , 24
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Ds4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N12   , Ds4 , v016
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Cs4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N12   , Cs4 , v016
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Bn3 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Ds4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Ds4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N12   , Cs4 , v016
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Bn3 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte	PATT
	 .word	mus_rg_nanadungeon_2_000
	.byte	PATT
	 .word	mus_rg_nanadungeon_2_001
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Gs4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N12   , Gs4 , v016
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Gs4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , An4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , As4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , As4 , v028
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , As4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Bn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		MOD   , 0
	.byte		N12   , En3 , v092
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , En3 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		MOD   , 0
	.byte		N12   , Bn2 , v092
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   , Bn2 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		MOD   , 0
	.byte		N12   , Ds3 , v092
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , Ds3 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		MOD   , 0
	.byte		N12   , As2 , v092
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   , As2 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		MOD   , 0
	.byte		N12   , Dn3 , v092
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , Dn3 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		MOD   , 0
	.byte		N12   , An2 , v092
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   , An2 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		MOD   , 0
	.byte		N12   , Cs3 , v092
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , Cs3 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		MOD   , 0
	.byte		N12   , Gs2 , v092
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   , Gs2 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		MOD   , 0
	.byte		N12   , Cn3 , v092
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , Cn3 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		MOD   , 0
	.byte		N12   , Gn2 , v092
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   , Gn2 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		MOD   , 0
	.byte		N12   , Bn2 , v092
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , Bn2 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		MOD   , 0
	.byte		N12   , Fs2 , v092
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   , Fs2 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		MOD   , 0
	.byte		N12   , As2 , v092
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , As2 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		MOD   , 0
	.byte		N12   , Fn2 , v092
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   , Fn2 , v016
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , An2 , v092
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , An2 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		MOD   , 0
	.byte		N12   , En2 , v092
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   , En2 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		VOICE , 1
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Bn4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , Bn4 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Bn4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , As4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , An4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-62
	.byte		MOD   , 0
	.byte		N12   , An4 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , An4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		VOICE , 24
	.byte		MOD   , 0
	.byte		N12   , Cs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , Cs4 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Bn3 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   , Bn3 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , As3 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Bn3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Ds4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Ds4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   , Cs4 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Bn3 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Ds4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Ds4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , Cs4 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Bn3 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Ds4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , Ds4 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Gn4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   , Gn4 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		VOICE , 1
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Gn3 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   , Gn3 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Fn3 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , Fn3 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , En3 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Fn3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , An3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , An3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gn3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , Gn3 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Fn3 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gn3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , An3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , An3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gn3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , Gn3 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , An3 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   , An3 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Cs4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , Cs4 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		VOICE , 24
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Gn4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , Gn4 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   , Gn4 , v020
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , Gn4 , v012
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   , Gn4 , v008
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Fn4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , Fn4 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   , Fn4 , v012
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , En4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Fn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , An4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cs5 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , An4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , Gn4 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , An4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cs5 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , An4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   , Gn4 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , An4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , An4 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Cs5 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   , Cs5 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		VOICE , 1
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Fs4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   , Fs4 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , Fs4 , v008
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , En4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , En4 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Ds4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , En4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cn5 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Fs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   , Fs4 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , En4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Fs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cn5 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Fs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , Fs4 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Gs4 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , Gs4 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Cn5 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , Cn5 , v016
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		VOICE , 24
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Ds3 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gn3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Ds3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cs3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   , Cs3 , v024
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		VOICE , 1
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Ds3 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gn3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Ds3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cs3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N12   , Cs3 , v024
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , En2 , v096
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gs2 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cn3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , En3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gs3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , En4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W03
	.byte		VOICE , 24
	.byte	W03
	.byte		MOD   , 0
	.byte		N12   , En4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		VOICE , 1
	.byte		MOD   , 0
	.byte		N12   , En4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		VOICE , 24
	.byte		MOD   , 0
	.byte		N12   , En4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		VOICE , 1
	.byte		MOD   , 0
	.byte		N12   , En4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		VOICE , 24
	.byte		MOD   , 0
	.byte		N12   , En4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Cn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Ds4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W03
	.byte		VOICE , 1
	.byte	W03
	.byte		MOD   , 0
	.byte		N12   , Bn2 , v032
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Ds3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gn3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Bn2 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Ds3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gn3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Bn2 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Ds3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Bn2 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Ds3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N12   , Gn3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
mus_rg_nanadungeon_2_002:
	.byte		MOD   , 0
	.byte		N12   , Bn2 , v032
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte	PEND
mus_rg_nanadungeon_2_003:
	.byte		MOD   , 0
	.byte		N12   , Ds3 , v032
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte	PEND
	.byte		        0
	.byte		N12   , Gn3 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte	PATT
	 .word	mus_rg_nanadungeon_2_002
	.byte	PATT
	 .word	mus_rg_nanadungeon_2_003
	.byte	GOTO
	 .word	mus_rg_nanadungeon_2_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_nanadungeon_3:
	.byte	KEYSH , mus_rg_nanadungeon_key+0
mus_rg_nanadungeon_3_B1:
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-34
	.byte		VOL   , 65*mus_rg_nanadungeon_mvl/mxv
	.byte		BEND  , c_v+1
	.byte	W24
	.byte		N12   , Bn2 , v020
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
mus_rg_nanadungeon_3_000:
	.byte		N12   , Bn2 , v020
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_nanadungeon_3_000
	.byte	PATT
	 .word	mus_rg_nanadungeon_3_000
	.byte		N12   , Ds3 , v020
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
mus_rg_nanadungeon_3_001:
	.byte		N12   , En3 , v020
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_nanadungeon_3_001
	.byte	PATT
	 .word	mus_rg_nanadungeon_3_001
	.byte		N12   , En3 , v020
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_nanadungeon_3_000
	.byte	PATT
	 .word	mus_rg_nanadungeon_3_000
	.byte	PATT
	 .word	mus_rg_nanadungeon_3_000
	.byte		N12   , Bn2 , v020
	.byte	W12
	.byte		        Ds3 
	.byte	W84
	.byte	W96
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Gs1 
	.byte	W54
	.byte	W96
	.byte	W48
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
mus_rg_nanadungeon_3_002:
	.byte		N12   , Ds3 , v020
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_nanadungeon_3_002
	.byte	PATT
	 .word	mus_rg_nanadungeon_3_002
	.byte		N12   , Ds3 , v020
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
mus_rg_nanadungeon_3_003:
	.byte		N12   , An2 , v020
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_nanadungeon_3_003
	.byte		N12   , An2 , v020
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
mus_rg_nanadungeon_3_004:
	.byte		N12   , An3 , v020
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_nanadungeon_3_004
	.byte		N12   , Cs4 , v020
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
mus_rg_nanadungeon_3_005:
	.byte		N12   , En3 , v020
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_nanadungeon_3_005
	.byte		N12   , En3 , v020
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        En3 
	.byte	W84
	.byte	W72
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N36   , Cs3 
	.byte	W36
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N36   , Cs3 
	.byte	W12
	.byte	W24
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N36   , Cs3 
	.byte	W36
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N36   , Cs3 
	.byte	W36
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Bn2 , v016
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_nanadungeon_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_nanadungeon_4:
	.byte	KEYSH , mus_rg_nanadungeon_key+0
mus_rg_nanadungeon_4_B1:
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 45*mus_rg_nanadungeon_mvl/mxv
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
	.byte	W96
	.byte		VOL   , 90*mus_rg_nanadungeon_mvl/mxv
	.byte	W72
	.byte		PAN   , c_v-32
	.byte		N03   , Bn1 , v092
	.byte	W03
	.byte		        Cn2 
	.byte	W03
	.byte		        Cs2 
	.byte	W03
	.byte		        Dn2 
	.byte	W03
	.byte		        Ds2 
	.byte	W03
	.byte		        En2 
	.byte	W09
	.byte		PAN   , c_v+32
	.byte		N03   , Cn2 
	.byte	W03
	.byte		        Cs2 
	.byte	W03
	.byte		        Dn2 
	.byte	W03
	.byte		        Ds2 
	.byte	W03
	.byte		        En2 
	.byte	W03
	.byte		        Fn2 
	.byte	W80
	.byte	W01
	.byte		VOL   , 79*mus_rg_nanadungeon_mvl/mxv
	.byte	W48
	.byte		        79*mus_rg_nanadungeon_mvl/mxv
	.byte		PAN   , c_v+21
	.byte		N24   , En2 
	.byte	W12
	.byte		VOL   , 45*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        79*mus_rg_nanadungeon_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N24   , Bn1 , v080
	.byte	W12
	.byte		VOL   , 44*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        79*mus_rg_nanadungeon_mvl/mxv
	.byte		PAN   , c_v+22
	.byte		N24   , Ds2 , v092
	.byte	W12
	.byte		VOL   , 45*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        79*mus_rg_nanadungeon_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N24   , As1 , v080
	.byte	W12
	.byte		VOL   , 44*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        79*mus_rg_nanadungeon_mvl/mxv
	.byte		PAN   , c_v+22
	.byte		N24   , Dn2 , v092
	.byte	W12
	.byte		VOL   , 45*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        79*mus_rg_nanadungeon_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N24   , An1 , v080
	.byte	W12
	.byte		VOL   , 44*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        79*mus_rg_nanadungeon_mvl/mxv
	.byte		PAN   , c_v+23
	.byte		N24   , Cs2 , v092
	.byte	W12
	.byte		VOL   , 45*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        79*mus_rg_nanadungeon_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N24   , Gs1 , v080
	.byte	W12
	.byte		VOL   , 44*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        79*mus_rg_nanadungeon_mvl/mxv
	.byte		PAN   , c_v+22
	.byte		N24   , Cn2 , v092
	.byte	W12
	.byte		VOL   , 45*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        79*mus_rg_nanadungeon_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N24   , Gn1 , v080
	.byte	W12
	.byte		VOL   , 44*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        79*mus_rg_nanadungeon_mvl/mxv
	.byte		PAN   , c_v+21
	.byte		N24   , Bn1 , v092
	.byte	W12
	.byte		VOL   , 45*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        79*mus_rg_nanadungeon_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N24   , Fs1 , v080
	.byte	W12
	.byte		VOL   , 44*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        79*mus_rg_nanadungeon_mvl/mxv
	.byte		PAN   , c_v+22
	.byte		N24   , As1 , v092
	.byte	W12
	.byte		VOL   , 45*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        79*mus_rg_nanadungeon_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N24   , Fn1 , v080
	.byte	W12
	.byte		VOL   , 44*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        79*mus_rg_nanadungeon_mvl/mxv
	.byte		PAN   , c_v+22
	.byte		N24   , An1 , v092
	.byte	W12
	.byte		VOL   , 45*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        79*mus_rg_nanadungeon_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N48   , En1 , v080
	.byte	W12
	.byte		VOL   , 44*mus_rg_nanadungeon_mvl/mxv
	.byte	W06
	.byte		        29*mus_rg_nanadungeon_mvl/mxv
	.byte	W03
	.byte		        19*mus_rg_nanadungeon_mvl/mxv
	.byte	W03
	.byte		        10*mus_rg_nanadungeon_mvl/mxv
	.byte	W03
	.byte		        8*mus_rg_nanadungeon_mvl/mxv
	.byte	W03
	.byte		        5*mus_rg_nanadungeon_mvl/mxv
	.byte	W03
	.byte		        3*mus_rg_nanadungeon_mvl/mxv
	.byte	W03
	.byte		        1*mus_rg_nanadungeon_mvl/mxv
	.byte	W03
	.byte		        1*mus_rg_nanadungeon_mvl/mxv
	.byte	W09
	.byte		        0*mus_rg_nanadungeon_mvl/mxv
	.byte	W24
	.byte	W72
	.byte		PAN   , c_v+32
	.byte		VOL   , 90*mus_rg_nanadungeon_mvl/mxv
	.byte		N03   , Fn2 , v092
	.byte	W03
	.byte		        En2 
	.byte	W03
	.byte		        Ds2 
	.byte	W03
	.byte		        Dn2 
	.byte	W03
	.byte		        Cs2 
	.byte	W03
	.byte		        Cn2 
	.byte	W09
	.byte		PAN   , c_v-32
	.byte		N03   , En2 
	.byte	W03
	.byte		        Ds2 
	.byte	W03
	.byte		        Dn2 
	.byte	W03
	.byte		        Cs2 
	.byte	W03
	.byte		        Cn2 
	.byte	W03
	.byte		        Bn1 
	.byte	W09
	.byte		VOL   , 45*mus_rg_nanadungeon_mvl/mxv
	.byte	W72
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
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_nanadungeon_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_nanadungeon_5:
	.byte	KEYSH , mus_rg_nanadungeon_key+0
mus_rg_nanadungeon_5_B1:
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-64
	.byte		VOL   , 34*mus_rg_nanadungeon_mvl/mxv
	.byte		BEND  , c_v-18
	.byte		TIE   , Gn3 , v040
	.byte	W03
	.byte		BEND  , c_v-10
	.byte	W03
	.byte		        c_v-6
	.byte	W03
	.byte		        c_v-2
	.byte	W03
	.byte		        c_v+0
	.byte	W36
	.byte		MOD   , 3
	.byte	W36
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte	W48
	.byte		MOD   , 3
	.byte	W36
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		        c_v+2
	.byte	W06
	.byte		        c_v+0
	.byte	W36
	.byte	W03
	.byte		MOD   , 3
	.byte	W12
	.byte		BEND  , c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W30
	.byte		MOD   , 0
	.byte	W48
	.byte		        3
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		        c_v+2
	.byte	W03
	.byte		        c_v+5
	.byte	W03
	.byte		        c_v+7
	.byte	W03
	.byte		        c_v+8
	.byte	W03
	.byte		        c_v+10
	.byte	W03
	.byte		        c_v+11
	.byte	W03
	.byte		        c_v+13
	.byte	W03
	.byte		        c_v+16
	.byte	W03
	.byte		        c_v+18
	.byte	W03
	.byte		        c_v+20
	.byte	W03
	.byte		        c_v+21
	.byte	W03
	.byte		        c_v+22
	.byte	W03
	.byte		        c_v+23
	.byte	W03
	.byte		        c_v+25
	.byte	W03
	.byte		        c_v+26
	.byte	W03
	.byte		MOD   , 0
	.byte		BEND  , c_v+26
	.byte	W48
	.byte		MOD   , 3
	.byte	W42
	.byte		BEND  , c_v+24
	.byte	W06
	.byte		MOD   , 0
	.byte		BEND  , c_v+26
	.byte	W42
	.byte		        c_v+28
	.byte	W06
	.byte		MOD   , 3
	.byte		BEND  , c_v+26
	.byte	W48
	.byte		MOD   , 0
	.byte	W48
	.byte		        3
	.byte	W36
	.byte		BEND  , c_v+24
	.byte	W06
	.byte		        c_v+26
	.byte	W06
	.byte		MOD   , 0
	.byte	W48
	.byte	W03
	.byte		BEND  , c_v+24
	.byte	W03
	.byte		        c_v+22
	.byte	W03
	.byte		        c_v+21
	.byte	W03
	.byte		        c_v+19
	.byte	W03
	.byte		        c_v+18
	.byte	W03
	.byte		        c_v+17
	.byte	W03
	.byte		        c_v+16
	.byte	W03
	.byte		        c_v+16
	.byte	W03
	.byte		        c_v+14
	.byte	W03
	.byte		        c_v+11
	.byte	W03
	.byte		        c_v+9
	.byte	W03
	.byte		        c_v+7
	.byte	W03
	.byte		        c_v+5
	.byte	W03
	.byte		        c_v+4
	.byte	W03
	.byte		        c_v+2
	.byte	W03
	.byte		        c_v-1
	.byte	W03
	.byte		        c_v+0
	.byte	W09
	.byte		MOD   , 4
	.byte	W48
	.byte		BEND  , c_v-4
	.byte	W06
	.byte		        c_v+0
	.byte	W30
	.byte	W36
	.byte	W03
	.byte		        c_v+4
	.byte	W09
	.byte		        c_v+0
	.byte	W48
	.byte	W32
	.byte	W01
	.byte		        c_v+2
	.byte	W06
	.byte		        c_v+0
	.byte	W56
	.byte	W01
	.byte	W36
	.byte		        c_v-4
	.byte	W12
	.byte		        c_v+0
	.byte	W48
	.byte		EOT   
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N03   , Fn4 , v032
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N03   
	.byte	W60
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOL   , 4*mus_rg_nanadungeon_mvl/mxv
	.byte	W48
	.byte		        4*mus_rg_nanadungeon_mvl/mxv
	.byte		BEND  , c_v-16
	.byte		TIE   , Ds3 , v052
	.byte	W03
	.byte		VOL   , 7*mus_rg_nanadungeon_mvl/mxv
	.byte	W03
	.byte		BEND  , c_v-15
	.byte	W03
	.byte		VOL   , 11*mus_rg_nanadungeon_mvl/mxv
	.byte	W03
	.byte		MOD   , 5
	.byte		VOL   , 15*mus_rg_nanadungeon_mvl/mxv
	.byte		BEND  , c_v-13
	.byte	W06
	.byte		VOL   , 17*mus_rg_nanadungeon_mvl/mxv
	.byte		BEND  , c_v-12
	.byte	W06
	.byte		VOL   , 21*mus_rg_nanadungeon_mvl/mxv
	.byte		BEND  , c_v-9
	.byte	W06
	.byte		VOL   , 24*mus_rg_nanadungeon_mvl/mxv
	.byte		BEND  , c_v-7
	.byte	W03
	.byte		VOL   , 28*mus_rg_nanadungeon_mvl/mxv
	.byte	W03
	.byte		BEND  , c_v-6
	.byte	W06
	.byte		VOL   , 31*mus_rg_nanadungeon_mvl/mxv
	.byte		BEND  , c_v-3
	.byte	W06
	.byte		VOL   , 34*mus_rg_nanadungeon_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		        c_v-2
	.byte	W06
	.byte		        c_v-2
	.byte	W06
	.byte		        c_v-3
	.byte	W06
	.byte		        c_v-5
	.byte	W06
	.byte		        c_v-5
	.byte	W12
	.byte		        c_v-7
	.byte	W06
	.byte		        c_v-8
	.byte	W03
	.byte		        c_v-9
	.byte	W03
	.byte		        c_v-11
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W30
	.byte		        c_v-9
	.byte	W06
	.byte		        c_v-6
	.byte	W06
	.byte		        c_v-4
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+3
	.byte	W06
	.byte		        c_v+6
	.byte	W06
	.byte		        c_v+8
	.byte	W06
	.byte		        c_v+10
	.byte	W24
	.byte		MOD   , 4
	.byte	W96
	.byte	W96
	.byte		        7
	.byte	W84
	.byte		BEND  , c_v+8
	.byte	W12
	.byte	W12
	.byte		        c_v+6
	.byte	W12
	.byte		MOD   , 0
	.byte		BEND  , c_v+5
	.byte	W12
	.byte		MOD   , 4
	.byte	W60
	.byte	W96
	.byte	W96
	.byte	W32
	.byte	W01
	.byte		VOL   , 27*mus_rg_nanadungeon_mvl/mxv
	.byte	W03
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        16*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        10*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        5*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		EOT   
	.byte		VOL   , 0*mus_rg_nanadungeon_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte	W92
	.byte	W01
	.byte		VOL   , 32*mus_rg_nanadungeon_mvl/mxv
	.byte	W03
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		BEND  , c_v+1
	.byte	W12
	.byte		N12   , Bn3 , v024
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_nanadungeon_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_nanadungeon_6:
	.byte	KEYSH , mus_rg_nanadungeon_key+0
mus_rg_nanadungeon_6_B1:
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 34*mus_rg_nanadungeon_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		TIE   , Ds4 , v040
	.byte	W48
	.byte		MOD   , 3
	.byte	W36
	.byte		BEND  , c_v+1
	.byte	W12
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		        c_v-3
	.byte	W06
	.byte		        c_v+0
	.byte	W36
	.byte		MOD   , 3
	.byte	W48
	.byte		        0
	.byte	W36
	.byte		BEND  , c_v+2
	.byte	W12
	.byte		MOD   , 3
	.byte		BEND  , c_v+0
	.byte	W48
	.byte		MOD   , 0
	.byte	W36
	.byte		BEND  , c_v-3
	.byte	W12
	.byte		MOD   , 3
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		        c_v+2
	.byte	W03
	.byte		        c_v+5
	.byte	W03
	.byte		        c_v+7
	.byte	W03
	.byte		        c_v+8
	.byte	W03
	.byte		        c_v+10
	.byte	W03
	.byte		        c_v+11
	.byte	W03
	.byte		        c_v+13
	.byte	W03
	.byte		        c_v+16
	.byte	W03
	.byte		        c_v+18
	.byte	W03
	.byte		        c_v+20
	.byte	W03
	.byte		        c_v+21
	.byte	W03
	.byte		        c_v+22
	.byte	W03
	.byte		        c_v+23
	.byte	W03
	.byte		        c_v+25
	.byte	W03
	.byte		        c_v+26
	.byte	W03
	.byte		MOD   , 0
	.byte		BEND  , c_v+26
	.byte	W48
	.byte		MOD   , 3
	.byte	W36
	.byte		BEND  , c_v+23
	.byte	W06
	.byte		        c_v+26
	.byte	W06
	.byte		MOD   , 0
	.byte	W36
	.byte		BEND  , c_v+27
	.byte	W06
	.byte		        c_v+26
	.byte	W06
	.byte		MOD   , 3
	.byte	W48
	.byte		        0
	.byte	W48
	.byte		        3
	.byte	W36
	.byte		BEND  , c_v+23
	.byte	W12
	.byte		MOD   , 0
	.byte		BEND  , c_v+26
	.byte	W48
	.byte	W03
	.byte		        c_v+24
	.byte	W03
	.byte		        c_v+22
	.byte	W03
	.byte		        c_v+21
	.byte	W03
	.byte		        c_v+19
	.byte	W03
	.byte		        c_v+18
	.byte	W03
	.byte		        c_v+17
	.byte	W03
	.byte		        c_v+16
	.byte	W03
	.byte		        c_v+16
	.byte	W03
	.byte		        c_v+14
	.byte	W03
	.byte		        c_v+11
	.byte	W03
	.byte		        c_v+9
	.byte	W03
	.byte		        c_v+7
	.byte	W03
	.byte		        c_v+5
	.byte	W03
	.byte		        c_v+4
	.byte	W03
	.byte		        c_v+2
	.byte	W03
	.byte		        c_v-1
	.byte	W03
	.byte		        c_v+0
	.byte	W09
	.byte		MOD   , 4
	.byte	W21
	.byte		BEND  , c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W48
	.byte	W03
	.byte		        c_v-3
	.byte	W06
	.byte		        c_v+0
	.byte	W60
	.byte		        c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W30
	.byte	W60
	.byte		        c_v-6
	.byte	W06
	.byte		        c_v+0
	.byte	W30
	.byte	W12
	.byte		        c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte	W66
	.byte		        c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		EOT   
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N03   , Gs4 , v032
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		N03   
	.byte	W60
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOL   , 4*mus_rg_nanadungeon_mvl/mxv
	.byte	W48
	.byte		        4*mus_rg_nanadungeon_mvl/mxv
	.byte		BEND  , c_v-22
	.byte		TIE   , Cs4 , v052
	.byte	W03
	.byte		VOL   , 7*mus_rg_nanadungeon_mvl/mxv
	.byte	W03
	.byte		BEND  , c_v-18
	.byte	W03
	.byte		MOD   , 4
	.byte		VOL   , 11*mus_rg_nanadungeon_mvl/mxv
	.byte	W03
	.byte		        15*mus_rg_nanadungeon_mvl/mxv
	.byte		BEND  , c_v-13
	.byte	W06
	.byte		VOL   , 17*mus_rg_nanadungeon_mvl/mxv
	.byte		BEND  , c_v-10
	.byte	W06
	.byte		VOL   , 21*mus_rg_nanadungeon_mvl/mxv
	.byte		BEND  , c_v-8
	.byte	W06
	.byte		VOL   , 24*mus_rg_nanadungeon_mvl/mxv
	.byte		BEND  , c_v-5
	.byte	W03
	.byte		VOL   , 28*mus_rg_nanadungeon_mvl/mxv
	.byte	W03
	.byte		BEND  , c_v-3
	.byte	W06
	.byte		VOL   , 31*mus_rg_nanadungeon_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W06
	.byte		VOL   , 34*mus_rg_nanadungeon_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		        c_v-4
	.byte	W06
	.byte		        c_v-7
	.byte	W06
	.byte		        c_v-10
	.byte	W06
	.byte		        c_v-12
	.byte	W06
	.byte		        c_v-15
	.byte	W06
	.byte		        c_v-19
	.byte	W06
	.byte		        c_v-23
	.byte	W06
	.byte		        c_v-26
	.byte	W06
	.byte		        c_v-32
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W44
	.byte	W01
	.byte		        c_v-27
	.byte	W03
	.byte		        c_v-22
	.byte	W03
	.byte		        c_v-16
	.byte	W03
	.byte		        c_v-11
	.byte	W03
	.byte		        c_v-6
	.byte	W03
	.byte		        c_v-2
	.byte	W03
	.byte		        c_v+2
	.byte	W03
	.byte		        c_v+5
	.byte	W03
	.byte		        c_v+9
	.byte	W03
	.byte		        c_v+14
	.byte	W03
	.byte		        c_v+19
	.byte	W03
	.byte		        c_v+22
	.byte	W03
	.byte		        c_v+25
	.byte	W03
	.byte		        c_v+29
	.byte	W03
	.byte		        c_v+33
	.byte	W03
	.byte		        c_v+37
	.byte	W03
	.byte		        c_v+39
	.byte	W03
	.byte		MOD   , 4
	.byte		BEND  , c_v+42
	.byte	W96
	.byte	W96
	.byte		MOD   , 7
	.byte	W54
	.byte		BEND  , c_v+40
	.byte	W06
	.byte		        c_v+40
	.byte	W06
	.byte		        c_v+37
	.byte	W06
	.byte		        c_v+36
	.byte	W06
	.byte		        c_v+33
	.byte	W06
	.byte		        c_v+32
	.byte	W06
	.byte		        c_v+28
	.byte	W06
	.byte		MOD   , 0
	.byte		BEND  , c_v+26
	.byte	W24
	.byte		MOD   , 0
	.byte	W12
	.byte		        4
	.byte	W60
	.byte	W96
	.byte	W96
	.byte	W32
	.byte	W01
	.byte		VOL   , 27*mus_rg_nanadungeon_mvl/mxv
	.byte	W03
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        16*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        10*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        5*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		EOT   
	.byte		VOL   , 0*mus_rg_nanadungeon_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte	W96
	.byte		VOL   , 34*mus_rg_nanadungeon_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W60
	.byte		N12   , Bn2 , v032
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_nanadungeon_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_rg_nanadungeon_7:
	.byte	KEYSH , mus_rg_nanadungeon_key+0
mus_rg_nanadungeon_7_B1:
	.byte		VOICE , 0
	.byte		VOL   , 44*mus_rg_nanadungeon_mvl/mxv
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
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		VOL   , 22*mus_rg_nanadungeon_mvl/mxv
	.byte		N96   , Cn3 , v052
	.byte	W12
	.byte		VOL   , 25*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        27*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        29*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        34*mus_rg_nanadungeon_mvl/mxv
	.byte	W09
	.byte		        38*mus_rg_nanadungeon_mvl/mxv
	.byte	W15
	.byte		        39*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        41*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        44*mus_rg_nanadungeon_mvl/mxv
	.byte		N48   , Gn2 , v076
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOL   , 25*mus_rg_nanadungeon_mvl/mxv
	.byte		N96   , Cn3 , v052
	.byte	W09
	.byte		VOL   , 26*mus_rg_nanadungeon_mvl/mxv
	.byte	W09
	.byte		        29*mus_rg_nanadungeon_mvl/mxv
	.byte	W06
	.byte		        34*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        35*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        39*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        42*mus_rg_nanadungeon_mvl/mxv
	.byte	W12
	.byte		        45*mus_rg_nanadungeon_mvl/mxv
	.byte	W24
	.byte		N48   , An2 , v076
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
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_nanadungeon_7_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_nanadungeon:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_nanadungeon_pri	@ Priority
	.byte	mus_rg_nanadungeon_rev	@ Reverb.

	.word	mus_rg_nanadungeon_grp

	.word	mus_rg_nanadungeon_1
	.word	mus_rg_nanadungeon_2
	.word	mus_rg_nanadungeon_3
	.word	mus_rg_nanadungeon_4
	.word	mus_rg_nanadungeon_5
	.word	mus_rg_nanadungeon_6
	.word	mus_rg_nanadungeon_7

	.end
