	.include "MPlayDef.s"

	.equ	bgm_frlg_mt_moon_grp, voicegroup_86A63F4
	.equ	bgm_frlg_mt_moon_pri, 0
	.equ	bgm_frlg_mt_moon_rev, reverb_set+50
	.equ	bgm_frlg_mt_moon_mvl, 127
	.equ	bgm_frlg_mt_moon_key, 0
	.equ	bgm_frlg_mt_moon_tbs, 1
	.equ	bgm_frlg_mt_moon_exg, 0
	.equ	bgm_frlg_mt_moon_cmp, 1

	.section .rodata
	.global	bgm_frlg_mt_moon
	.align	2

@********************** Track  1 **********************@

bgm_frlg_mt_moon_1:
	.byte	KEYSH , bgm_frlg_mt_moon_key+0
bgm_frlg_mt_moon_1_B1:
	.byte	TEMPO , 110*bgm_frlg_mt_moon_tbs/2
	.byte		VOICE , 1
	.byte		PAN   , c_v+16
	.byte		VOL   , 65*bgm_frlg_mt_moon_mvl/mxv
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
bgm_frlg_mt_moon_1_000:
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
	 .word	bgm_frlg_mt_moon_1_000
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
bgm_frlg_mt_moon_1_001:
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
	 .word	bgm_frlg_mt_moon_1_001
	.byte	PATT
	 .word	bgm_frlg_mt_moon_1_001
	.byte	PATT
	 .word	bgm_frlg_mt_moon_1_001
	.byte	PATT
	 .word	bgm_frlg_mt_moon_1_000
	.byte	PATT
	 .word	bgm_frlg_mt_moon_1_000
	.byte	PATT
	 .word	bgm_frlg_mt_moon_1_000
	.byte	PATT
	 .word	bgm_frlg_mt_moon_1_000
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
	.byte	TEMPO , 112*bgm_frlg_mt_moon_tbs/2
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
	.byte	TEMPO , 98*bgm_frlg_mt_moon_tbs/2
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
	.byte	TEMPO , 90*bgm_frlg_mt_moon_tbs/2
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
	.byte	TEMPO , 82*bgm_frlg_mt_moon_tbs/2
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
	.byte	TEMPO , 78*bgm_frlg_mt_moon_tbs/2
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
	.byte	TEMPO , 74*bgm_frlg_mt_moon_tbs/2
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
	.byte	TEMPO , 66*bgm_frlg_mt_moon_tbs/2
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
	.byte	TEMPO , 12*bgm_frlg_mt_moon_tbs/2
	.byte		        Cn2 
	.byte	W06
	.byte	TEMPO , 110*bgm_frlg_mt_moon_tbs/2
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
bgm_frlg_mt_moon_1_002:
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
	 .word	bgm_frlg_mt_moon_1_002
	.byte	PATT
	 .word	bgm_frlg_mt_moon_1_002
	.byte	PATT
	 .word	bgm_frlg_mt_moon_1_002
bgm_frlg_mt_moon_1_003:
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
	 .word	bgm_frlg_mt_moon_1_003
	.byte	PATT
	 .word	bgm_frlg_mt_moon_1_003
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
bgm_frlg_mt_moon_1_004:
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
	 .word	bgm_frlg_mt_moon_1_004
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
	 .word	bgm_frlg_mt_moon_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_frlg_mt_moon_2:
	.byte	KEYSH , bgm_frlg_mt_moon_key+0
bgm_frlg_mt_moon_2_B1:
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 73*bgm_frlg_mt_moon_mvl/mxv
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
bgm_frlg_mt_moon_2_000:
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
bgm_frlg_mt_moon_2_001:
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
	 .word	bgm_frlg_mt_moon_2_000
	.byte	PATT
	 .word	bgm_frlg_mt_moon_2_001
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
bgm_frlg_mt_moon_2_002:
	.byte		MOD   , 0
	.byte		N12   , Bn2 , v032
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte	PEND
bgm_frlg_mt_moon_2_003:
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
	 .word	bgm_frlg_mt_moon_2_002
	.byte	PATT
	 .word	bgm_frlg_mt_moon_2_003
	.byte	GOTO
	 .word	bgm_frlg_mt_moon_2_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  3 **********************@

bgm_frlg_mt_moon_3:
	.byte	KEYSH , bgm_frlg_mt_moon_key+0
bgm_frlg_mt_moon_3_B1:
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-34
	.byte		VOL   , 65*bgm_frlg_mt_moon_mvl/mxv
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
bgm_frlg_mt_moon_3_000:
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
	 .word	bgm_frlg_mt_moon_3_000
	.byte	PATT
	 .word	bgm_frlg_mt_moon_3_000
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
bgm_frlg_mt_moon_3_001:
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
	 .word	bgm_frlg_mt_moon_3_001
	.byte	PATT
	 .word	bgm_frlg_mt_moon_3_001
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
	 .word	bgm_frlg_mt_moon_3_000
	.byte	PATT
	 .word	bgm_frlg_mt_moon_3_000
	.byte	PATT
	 .word	bgm_frlg_mt_moon_3_000
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
bgm_frlg_mt_moon_3_002:
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
	 .word	bgm_frlg_mt_moon_3_002
	.byte	PATT
	 .word	bgm_frlg_mt_moon_3_002
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
bgm_frlg_mt_moon_3_003:
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
	 .word	bgm_frlg_mt_moon_3_003
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
bgm_frlg_mt_moon_3_004:
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
	 .word	bgm_frlg_mt_moon_3_004
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
bgm_frlg_mt_moon_3_005:
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
	 .word	bgm_frlg_mt_moon_3_005
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
	 .word	bgm_frlg_mt_moon_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_frlg_mt_moon_4:
	.byte	KEYSH , bgm_frlg_mt_moon_key+0
bgm_frlg_mt_moon_4_B1:
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 45*bgm_frlg_mt_moon_mvl/mxv
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
	.byte		VOL   , 90*bgm_frlg_mt_moon_mvl/mxv
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
	.byte		VOL   , 79*bgm_frlg_mt_moon_mvl/mxv
	.byte	W48
	.byte		        79*bgm_frlg_mt_moon_mvl/mxv
	.byte		PAN   , c_v+21
	.byte		N24   , En2 
	.byte	W12
	.byte		VOL   , 45*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_mt_moon_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N24   , Bn1 , v080
	.byte	W12
	.byte		VOL   , 44*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_mt_moon_mvl/mxv
	.byte		PAN   , c_v+22
	.byte		N24   , Ds2 , v092
	.byte	W12
	.byte		VOL   , 45*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_mt_moon_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N24   , As1 , v080
	.byte	W12
	.byte		VOL   , 44*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_mt_moon_mvl/mxv
	.byte		PAN   , c_v+22
	.byte		N24   , Dn2 , v092
	.byte	W12
	.byte		VOL   , 45*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_mt_moon_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N24   , An1 , v080
	.byte	W12
	.byte		VOL   , 44*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_mt_moon_mvl/mxv
	.byte		PAN   , c_v+23
	.byte		N24   , Cs2 , v092
	.byte	W12
	.byte		VOL   , 45*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_mt_moon_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N24   , Gs1 , v080
	.byte	W12
	.byte		VOL   , 44*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_mt_moon_mvl/mxv
	.byte		PAN   , c_v+22
	.byte		N24   , Cn2 , v092
	.byte	W12
	.byte		VOL   , 45*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_mt_moon_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N24   , Gn1 , v080
	.byte	W12
	.byte		VOL   , 44*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_mt_moon_mvl/mxv
	.byte		PAN   , c_v+21
	.byte		N24   , Bn1 , v092
	.byte	W12
	.byte		VOL   , 45*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_mt_moon_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N24   , Fs1 , v080
	.byte	W12
	.byte		VOL   , 44*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_mt_moon_mvl/mxv
	.byte		PAN   , c_v+22
	.byte		N24   , As1 , v092
	.byte	W12
	.byte		VOL   , 45*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_mt_moon_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N24   , Fn1 , v080
	.byte	W12
	.byte		VOL   , 44*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_mt_moon_mvl/mxv
	.byte		PAN   , c_v+22
	.byte		N24   , An1 , v092
	.byte	W12
	.byte		VOL   , 45*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_mt_moon_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N48   , En1 , v080
	.byte	W12
	.byte		VOL   , 44*bgm_frlg_mt_moon_mvl/mxv
	.byte	W06
	.byte		        29*bgm_frlg_mt_moon_mvl/mxv
	.byte	W03
	.byte		        19*bgm_frlg_mt_moon_mvl/mxv
	.byte	W03
	.byte		        10*bgm_frlg_mt_moon_mvl/mxv
	.byte	W03
	.byte		        8*bgm_frlg_mt_moon_mvl/mxv
	.byte	W03
	.byte		        5*bgm_frlg_mt_moon_mvl/mxv
	.byte	W03
	.byte		        3*bgm_frlg_mt_moon_mvl/mxv
	.byte	W03
	.byte		        1*bgm_frlg_mt_moon_mvl/mxv
	.byte	W03
	.byte		        1*bgm_frlg_mt_moon_mvl/mxv
	.byte	W09
	.byte		        0*bgm_frlg_mt_moon_mvl/mxv
	.byte	W24
	.byte	W72
	.byte		PAN   , c_v+32
	.byte		VOL   , 90*bgm_frlg_mt_moon_mvl/mxv
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
	.byte		VOL   , 45*bgm_frlg_mt_moon_mvl/mxv
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
	 .word	bgm_frlg_mt_moon_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_frlg_mt_moon_5:
	.byte	KEYSH , bgm_frlg_mt_moon_key+0
bgm_frlg_mt_moon_5_B1:
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-64
	.byte		VOL   , 34*bgm_frlg_mt_moon_mvl/mxv
	.byte		BEND  , c_v-18
	.byte		N96   , Gn3 , v040
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
	.byte		N96   
	.byte	W48
	.byte		MOD   , 3
	.byte	W36
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N96   
	.byte	W03
	.byte		BEND  , c_v+2
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
	.byte		N96   
	.byte	W48
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
	.byte		N96   
	.byte	W48
	.byte		MOD   , 3
	.byte	W42
	.byte		BEND  , c_v+24
	.byte	W06
	.byte		MOD   , 0
	.byte		BEND  , c_v+26
	.byte		N96   
	.byte	W42
	.byte		BEND  , c_v+28
	.byte	W06
	.byte		MOD   , 3
	.byte		BEND  , c_v+26
	.byte	W48
	.byte		MOD   , 0
	.byte		N96   
	.byte	W48
	.byte		MOD   , 3
	.byte	W36
	.byte		BEND  , c_v+24
	.byte	W06
	.byte		        c_v+26
	.byte	W06
	.byte		MOD   , 0
	.byte		N96   
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
	.byte		N96   
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		MOD   , 4
	.byte	W48
	.byte		BEND  , c_v-4
	.byte	W06
	.byte		        c_v+0
	.byte	W30
	.byte		N96   
	.byte	W36
	.byte	W03
	.byte		BEND  , c_v+4
	.byte	W09
	.byte		        c_v+0
	.byte	W48
	.byte		N96   
	.byte	W32
	.byte	W01
	.byte		BEND  , c_v+2
	.byte	W06
	.byte		        c_v+0
	.byte	W56
	.byte	W01
	.byte		N96   
	.byte	W36
	.byte		BEND  , c_v-4
	.byte	W12
	.byte		        c_v+0
	.byte	W48
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
	.byte		VOL   , 4*bgm_frlg_mt_moon_mvl/mxv
	.byte	W48
	.byte		        4*bgm_frlg_mt_moon_mvl/mxv
	.byte		BEND  , c_v-16
	.byte		N48   , Ds3 , v052
	.byte	W03
	.byte		VOL   , 7*bgm_frlg_mt_moon_mvl/mxv
	.byte	W03
	.byte		BEND  , c_v-15
	.byte	W03
	.byte		VOL   , 11*bgm_frlg_mt_moon_mvl/mxv
	.byte	W03
	.byte		MOD   , 5
	.byte		VOL   , 15*bgm_frlg_mt_moon_mvl/mxv
	.byte		BEND  , c_v-13
	.byte	W06
	.byte		VOL   , 17*bgm_frlg_mt_moon_mvl/mxv
	.byte		BEND  , c_v-12
	.byte	W06
	.byte		VOL   , 21*bgm_frlg_mt_moon_mvl/mxv
	.byte		BEND  , c_v-9
	.byte	W06
	.byte		VOL   , 24*bgm_frlg_mt_moon_mvl/mxv
	.byte		BEND  , c_v-7
	.byte	W03
	.byte		VOL   , 28*bgm_frlg_mt_moon_mvl/mxv
	.byte	W03
	.byte		BEND  , c_v-6
	.byte	W06
	.byte		VOL   , 31*bgm_frlg_mt_moon_mvl/mxv
	.byte		BEND  , c_v-3
	.byte	W06
	.byte		VOL   , 34*bgm_frlg_mt_moon_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N96   , Ds3 , v040
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		N96   
	.byte	W48
	.byte		BEND  , c_v-2
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
	.byte		N96   
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		N96   
	.byte	W30
	.byte		BEND  , c_v-9
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
	.byte		N96   
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		MOD   , 7
	.byte		N96   
	.byte	W84
	.byte		BEND  , c_v+8
	.byte	W12
	.byte		N96   
	.byte	W12
	.byte		BEND  , c_v+6
	.byte	W12
	.byte		MOD   , 0
	.byte		BEND  , c_v+5
	.byte	W12
	.byte		MOD   , 4
	.byte	W60
	.byte		N96   
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		N96   
	.byte	W32
	.byte	W01
	.byte		VOL   , 27*bgm_frlg_mt_moon_mvl/mxv
	.byte	W03
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        16*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        10*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        5*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        0*bgm_frlg_mt_moon_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte	W92
	.byte	W01
	.byte		VOL   , 32*bgm_frlg_mt_moon_mvl/mxv
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
	 .word	bgm_frlg_mt_moon_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_frlg_mt_moon_6:
	.byte	KEYSH , bgm_frlg_mt_moon_key+0
bgm_frlg_mt_moon_6_B1:
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 34*bgm_frlg_mt_moon_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N96   , Ds4 , v040
	.byte	W48
	.byte		MOD   , 3
	.byte	W36
	.byte		BEND  , c_v+1
	.byte	W12
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N96   
	.byte	W06
	.byte		BEND  , c_v-3
	.byte	W06
	.byte		        c_v+0
	.byte	W36
	.byte		MOD   , 3
	.byte	W48
	.byte		        0
	.byte		N96   
	.byte	W36
	.byte		BEND  , c_v+2
	.byte	W12
	.byte		MOD   , 3
	.byte		BEND  , c_v+0
	.byte	W48
	.byte		MOD   , 0
	.byte		N96   
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
	.byte		N96   
	.byte	W48
	.byte		MOD   , 3
	.byte	W36
	.byte		BEND  , c_v+23
	.byte	W06
	.byte		        c_v+26
	.byte	W06
	.byte		MOD   , 0
	.byte		N96   
	.byte	W36
	.byte		BEND  , c_v+27
	.byte	W06
	.byte		        c_v+26
	.byte	W06
	.byte		MOD   , 3
	.byte	W48
	.byte		        0
	.byte		N96   
	.byte	W48
	.byte		MOD   , 3
	.byte	W36
	.byte		BEND  , c_v+23
	.byte	W12
	.byte		MOD   , 0
	.byte		BEND  , c_v+26
	.byte		N96   
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
	.byte		N96   
	.byte	W03
	.byte		BEND  , c_v+0
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
	.byte		N96   
	.byte	W60
	.byte		BEND  , c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W30
	.byte		N96   
	.byte	W60
	.byte		BEND  , c_v-6
	.byte	W06
	.byte		        c_v+0
	.byte	W30
	.byte		N96   
	.byte	W12
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte	W66
	.byte		        c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte	W06
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
	.byte		VOL   , 4*bgm_frlg_mt_moon_mvl/mxv
	.byte	W48
	.byte		        4*bgm_frlg_mt_moon_mvl/mxv
	.byte		BEND  , c_v-22
	.byte		N48   , Cs4 , v052
	.byte	W03
	.byte		VOL   , 7*bgm_frlg_mt_moon_mvl/mxv
	.byte	W03
	.byte		BEND  , c_v-18
	.byte	W03
	.byte		MOD   , 4
	.byte		VOL   , 11*bgm_frlg_mt_moon_mvl/mxv
	.byte	W03
	.byte		        15*bgm_frlg_mt_moon_mvl/mxv
	.byte		BEND  , c_v-13
	.byte	W06
	.byte		VOL   , 17*bgm_frlg_mt_moon_mvl/mxv
	.byte		BEND  , c_v-10
	.byte	W06
	.byte		VOL   , 21*bgm_frlg_mt_moon_mvl/mxv
	.byte		BEND  , c_v-8
	.byte	W06
	.byte		VOL   , 24*bgm_frlg_mt_moon_mvl/mxv
	.byte		BEND  , c_v-5
	.byte	W03
	.byte		VOL   , 28*bgm_frlg_mt_moon_mvl/mxv
	.byte	W03
	.byte		BEND  , c_v-3
	.byte	W06
	.byte		VOL   , 31*bgm_frlg_mt_moon_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W06
	.byte		VOL   , 34*bgm_frlg_mt_moon_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N96   , Cs4 , v040
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		N96   
	.byte	W48
	.byte		BEND  , c_v-4
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
	.byte		N96   
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		N96   
	.byte	W44
	.byte	W01
	.byte		BEND  , c_v-27
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
	.byte		N96   
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		MOD   , 7
	.byte		N96   
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
	.byte		N96   
	.byte	W24
	.byte		MOD   , 0
	.byte	W12
	.byte		        4
	.byte	W60
	.byte		N96   
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		N96   
	.byte	W32
	.byte	W01
	.byte		VOL   , 27*bgm_frlg_mt_moon_mvl/mxv
	.byte	W03
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        16*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        10*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        5*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        0*bgm_frlg_mt_moon_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte	W96
	.byte		VOL   , 34*bgm_frlg_mt_moon_mvl/mxv
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
	 .word	bgm_frlg_mt_moon_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_frlg_mt_moon_7:
	.byte	KEYSH , bgm_frlg_mt_moon_key+0
bgm_frlg_mt_moon_7_B1:
	.byte		VOICE , 0
	.byte		VOL   , 44*bgm_frlg_mt_moon_mvl/mxv
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
	.byte		VOL   , 22*bgm_frlg_mt_moon_mvl/mxv
	.byte		N96   , Cn3 , v052
	.byte	W12
	.byte		VOL   , 25*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        27*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        29*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        34*bgm_frlg_mt_moon_mvl/mxv
	.byte	W09
	.byte		        38*bgm_frlg_mt_moon_mvl/mxv
	.byte	W15
	.byte		        39*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        41*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        44*bgm_frlg_mt_moon_mvl/mxv
	.byte		N48   , Gn2 , v076
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOL   , 25*bgm_frlg_mt_moon_mvl/mxv
	.byte		N96   , Cn3 , v052
	.byte	W09
	.byte		VOL   , 26*bgm_frlg_mt_moon_mvl/mxv
	.byte	W09
	.byte		        29*bgm_frlg_mt_moon_mvl/mxv
	.byte	W06
	.byte		        34*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        35*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        39*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        42*bgm_frlg_mt_moon_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_mt_moon_mvl/mxv
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
	 .word	bgm_frlg_mt_moon_7_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_frlg_mt_moon:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_frlg_mt_moon_pri	@ Priority
	.byte	bgm_frlg_mt_moon_rev	@ Reverb.

	.word	bgm_frlg_mt_moon_grp

	.word	bgm_frlg_mt_moon_1
	.word	bgm_frlg_mt_moon_2
	.word	bgm_frlg_mt_moon_3
	.word	bgm_frlg_mt_moon_4
	.word	bgm_frlg_mt_moon_5
	.word	bgm_frlg_mt_moon_6
	.word	bgm_frlg_mt_moon_7

	.end
