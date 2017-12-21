	.include "MPlayDef.s"

	.equ	bgm_frlg_silph_grp, voicegroup_86ACB38
	.equ	bgm_frlg_silph_pri, 0
	.equ	bgm_frlg_silph_rev, reverb_set+50
	.equ	bgm_frlg_silph_mvl, 127
	.equ	bgm_frlg_silph_key, 0
	.equ	bgm_frlg_silph_tbs, 1
	.equ	bgm_frlg_silph_exg, 0
	.equ	bgm_frlg_silph_cmp, 1

	.section .rodata
	.global	bgm_frlg_silph
	.align	2

@********************** Track  1 **********************@

bgm_frlg_silph_1:
	.byte	KEYSH , bgm_frlg_silph_key+0
	.byte	TEMPO , 114*bgm_frlg_silph_tbs/2
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 38*bgm_frlg_silph_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , En1 , v127
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		        Gs1 
	.byte	W03
	.byte		        As1 
	.byte	W03
	.byte		        Bn1 
	.byte	W03
	.byte		N42   , Cn2 
	.byte	W42
	.byte		N03   , Bn1 
	.byte	W03
	.byte		        As1 
	.byte	W03
	.byte		        Gs1 
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		N06   , En1 
	.byte	W12
	.byte		        Bn1 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
bgm_frlg_silph_1_B1:
	.byte		N06   , Gn1 , v127
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte	TEMPO , 114*bgm_frlg_silph_tbs/2
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		        Bn1 
	.byte	W12
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		        Bn1 
	.byte	W12
	.byte		BEND  , c_v+1
	.byte		N06   , Gn1 
	.byte	W36
	.byte		N03   , En1 
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		        Gs1 
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		N36   , Bn1 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N03   
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		        Gn1 
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		        En1 
	.byte	W36
	.byte		        Fn1 
	.byte	W03
	.byte		        Gs1 
	.byte	W03
	.byte		        As1 
	.byte	W03
	.byte		        Bn1 
	.byte	W03
	.byte		N36   , Cn2 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N03   
	.byte	W03
	.byte		        Bn1 
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		        Gn1 
	.byte	W03
	.byte		        Fn1 
	.byte	W36
	.byte		        Fs1 
	.byte	W03
	.byte		        Bn1 
	.byte	W03
	.byte		        Cn2 
	.byte	W03
	.byte		        Cs2 
	.byte	W03
	.byte		N36   , Dn2 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N03   
	.byte	W03
	.byte		        Cn2 
	.byte	W03
	.byte		        As1 
	.byte	W03
	.byte		        Gn1 
	.byte	W03
	.byte		        Fn1 
	.byte	W36
	.byte		N03   
	.byte	W03
	.byte		        Gs1 
	.byte	W03
	.byte		        As1 
	.byte	W03
	.byte		        Bn1 
	.byte	W03
	.byte		N36   , Cn2 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N03   
	.byte	W03
	.byte		        Bn1 
	.byte	W03
	.byte		        Gs1 
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		        En1 
	.byte	W24
	.byte		N48   , Bn1 
	.byte	W12
	.byte		MOD   , 8
	.byte	W36
	.byte		        0
	.byte		N24   , En2 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte	TEMPO , 176*bgm_frlg_silph_tbs/2
	.byte		VOL   , 47*bgm_frlg_silph_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Bn1 
	.byte	W36
	.byte		N06   
	.byte	W36
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W72
	.byte		        An1 
	.byte	W24
	.byte		        Bn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
bgm_frlg_silph_1_000:
	.byte		N06   , Bn1 , v127
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_silph_1_000
	.byte	PATT
	 .word	bgm_frlg_silph_1_000
	.byte	W12
	.byte		N06   , Cn2 , v127
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        Bn1 
	.byte	W12
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        As1 
	.byte	W12
	.byte	W12
	.byte		        An1 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		N06   
	.byte	W12
bgm_frlg_silph_1_001:
	.byte	W12
	.byte		N06   , Bn1 , v127
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W48
	.byte		        Cn2 
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_silph_1_001
	.byte	W12
	.byte		N06   , Bn2 , v127
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_silph_1_001
	.byte	W12
	.byte		N06   , En3 , v127
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N03   , Bn1 
	.byte	W03
	.byte		        As1 
	.byte	W03
	.byte		        Gs1 
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		N80   , En1 
	.byte	W09
	.byte		MOD   , 6
	.byte	W72
	.byte		        0
	.byte		N03   , Fn1 
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		        Gs1 
	.byte	W03
	.byte		        As1 
	.byte	W03
	.byte		        Bn1 
	.byte	W03
	.byte		N80   , Cn2 
	.byte	W09
	.byte		MOD   , 6
	.byte	W72
	.byte		        0
	.byte		N03   , Bn1 
	.byte	W03
	.byte		        As1 
	.byte	W03
	.byte		        Gs1 
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		N80   , En1 
	.byte	W09
	.byte		MOD   , 6
	.byte	W72
	.byte		        0
	.byte		N03   , Fn1 
	.byte	W03
	.byte		        Gn1 
	.byte	W03
	.byte		        As1 
	.byte	W03
	.byte		        Cn2 
	.byte	W03
	.byte		        Cs2 
	.byte	W03
	.byte		N80   , Dn2 
	.byte	W09
	.byte		MOD   , 6
	.byte	W72
	.byte		        0
	.byte	W24
	.byte	TEMPO , 154*bgm_frlg_silph_tbs/2
	.byte	W24
	.byte	TEMPO , 142*bgm_frlg_silph_tbs/2
	.byte	W24
	.byte	TEMPO , 118*bgm_frlg_silph_tbs/2
	.byte	W24
	.byte	TEMPO , 94*bgm_frlg_silph_tbs/2
	.byte	W24
	.byte	TEMPO , 78*bgm_frlg_silph_tbs/2
	.byte	W24
	.byte	TEMPO , 50*bgm_frlg_silph_tbs/2
	.byte	W48
	.byte	TEMPO , 48*bgm_frlg_silph_tbs/2
	.byte	W09
	.byte	TEMPO , 114*bgm_frlg_silph_tbs/2
	.byte	W03
	.byte		N06   , Bn1 , v060
	.byte	W12
	.byte		        Bn1 , v032
	.byte	W12
	.byte		        Bn1 , v072
	.byte	W12
	.byte		        Bn1 , v032
	.byte	W12
	.byte		        Bn1 , v084
	.byte	W12
	.byte		        Bn1 , v032
	.byte	W12
	.byte		N24   , Bn1 , v068
	.byte	W12
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		N06   , Bn1 , v084
	.byte	W24
	.byte		        Bn1 , v092
	.byte	W24
	.byte		        Bn1 , v096
	.byte	W24
	.byte		        Bn1 , v127
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_silph_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_frlg_silph_2:
	.byte	KEYSH , bgm_frlg_silph_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 38*bgm_frlg_silph_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		N03   , En3 , v127
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		N42   , Cn4 
	.byte	W42
	.byte		N03   , Bn3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		N06   , En3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N06   , Fs2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N06   , Gn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N06   , Gs2 
	.byte	W12
bgm_frlg_silph_2_B1:
	.byte		PAN   , c_v+63
	.byte		N06   , En2 , v127
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N06   , Fs2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N06   , Gn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N06   , Gs2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , En2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+1
	.byte		N24   , En4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		N18   , Fn4 
	.byte	W18
	.byte		N03   , Fs4 , v120
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		N24   , En4 , v127
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N30   , Ds4 
	.byte	W30
	.byte		N03   , Dn4 , v120
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		N24   , En4 , v127
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N36   , Gn4 
	.byte	W36
	.byte		N18   , Gs4 
	.byte	W18
	.byte		N03   , Fs4 , v120
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		N24   , Ds4 , v127
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		N48   , En4 
	.byte	W48
	.byte		        Bn4 
	.byte	W48
	.byte		N12   , En3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N36   , Gn3 
	.byte	W36
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W03
	.byte		        Fs3 , v120
	.byte	W03
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N12   , Dn3 , v127
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , En4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , En4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , En3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , En3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+1
	.byte		N12   , En5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		BEND  , c_v+0
	.byte		N12   , Ds5 , v032
	.byte	W12
	.byte		N06   , Gn2 , v064
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Gn2 , v032
	.byte	W12
	.byte		        Fs2 , v076
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Fs2 , v032
	.byte	W12
	.byte		        Gn2 , v092
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Gn2 , v032
	.byte	W12
	.byte		N24   , Gs2 , v068
	.byte	W12
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Gn2 , v084
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N06   , Fs2 , v092
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N06   , Gn2 , v096
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N06   , Gs2 , v127
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_silph_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_frlg_silph_3:
	.byte	KEYSH , bgm_frlg_silph_key+0
	.byte		VOICE , 92
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 38*bgm_frlg_silph_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W72
	.byte		BEND  , c_v+1
	.byte		N24   , En4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Fn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
bgm_frlg_silph_3_B1:
	.byte		MOD   , 0
	.byte		N24   , En4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Fn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Gs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 57*bgm_frlg_silph_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N06   , En4 , v072
	.byte	W12
	.byte		        Gn4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        Gs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Gn4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        Fs4 
	.byte	W12
	.byte	W12
	.byte		        Gn4 
	.byte	W24
	.byte		        Gs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	W12
	.byte		        Gn4 
	.byte	W24
	.byte		        Gs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Gs4 
	.byte	W24
	.byte		        Gn4 
	.byte	W12
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
bgm_frlg_silph_3_000:
	.byte		N06   , En3 , v072
	.byte	W36
	.byte		        Fn3 
	.byte	W36
	.byte		N06   
	.byte	W24
	.byte	PEND
	.byte		        En3 
	.byte	W72
	.byte		        Ds3 
	.byte	W24
	.byte	PATT
	 .word	bgm_frlg_silph_3_000
	.byte		N06   , En3 , v072
	.byte	W72
	.byte		        Ds3 
	.byte	W24
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fs3 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Gn3 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        En3 
	.byte	W12
	.byte	W12
	.byte		        Fn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Dn3 
	.byte	W12
	.byte		N48   , Dn3 , v076
	.byte	W09
	.byte		MOD   , 7
	.byte	W36
	.byte	W03
	.byte		        0
	.byte		N48   , Fn3 
	.byte	W09
	.byte		MOD   , 7
	.byte	W36
	.byte	W03
	.byte		        0
	.byte		N48   , Dn3 
	.byte	W09
	.byte		MOD   , 7
	.byte	W36
	.byte	W03
	.byte		        0
	.byte		N48   , Fs3 
	.byte	W09
	.byte		MOD   , 7
	.byte	W36
	.byte	W03
	.byte		        0
	.byte		N48   , Dn3 
	.byte	W09
	.byte		MOD   , 7
	.byte	W36
	.byte	W03
	.byte		        0
	.byte		N48   , Gn3 
	.byte	W09
	.byte		MOD   , 7
	.byte	W36
	.byte	W03
	.byte		        0
	.byte		N48   , Dn3 
	.byte	W09
	.byte		MOD   , 7
	.byte	W36
	.byte	W03
	.byte		        0
	.byte		N48   , An3 
	.byte	W09
	.byte		MOD   , 7
	.byte	W36
	.byte	W03
bgm_frlg_silph_3_001:
	.byte		MOD   , 0
	.byte		N24   , En3 , v100
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Ds3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , En3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Fn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte	PEND
	.byte		        0
	.byte		N12   , En4 , v076
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_silph_3_001
	.byte		MOD   , 0
	.byte		N12   , En4 , v076
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N24   , En5 , v072
	.byte	W24
	.byte		        Ds5 
	.byte	W24
	.byte		        En5 
	.byte	W24
	.byte		        Fn5 
	.byte	W24
	.byte		        En5 
	.byte	W24
	.byte		        Ds5 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		        Ds5 
	.byte	W24
	.byte		        En5 
	.byte	W24
	.byte		        Fn5 
	.byte	W24
	.byte		        Fs5 
	.byte	W24
	.byte		        Gn5 
	.byte	W24
	.byte		        Gs5 
	.byte	W24
	.byte		        Ds5 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		        Ds5 
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOL   , 38*bgm_frlg_silph_mvl/mxv
	.byte		N24   , En4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte	GOTO
	 .word	bgm_frlg_silph_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_frlg_silph_4:
	.byte	KEYSH , bgm_frlg_silph_key+0
	.byte		VOICE , 35
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 76*bgm_frlg_silph_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N03   , En1 , v127
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		        Gs1 
	.byte	W03
	.byte		        As1 
	.byte	W03
	.byte		        Bn1 
	.byte	W03
	.byte		N42   , Cn2 
	.byte	W09
	.byte		MOD   , 8
	.byte	W32
	.byte	W01
	.byte		        0
	.byte		N03   , Bn1 
	.byte	W03
	.byte		        As1 
	.byte	W03
	.byte		        Gs1 
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		VOL   , 76*bgm_frlg_silph_mvl/mxv
	.byte		N06   , En1 , v120
	.byte	W12
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        En1 
	.byte	W42
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
bgm_frlg_silph_4_B1:
	.byte		N03   , En1 , v120
	.byte	W12
	.byte		N12   
	.byte	W48
	.byte		        As1 
	.byte	W12
	.byte		N06   , Fs1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		N03   , En1 
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Gs1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        En1 
	.byte	W36
	.byte		N03   , En1 , v127
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		        Gs1 
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		N36   , Bn1 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N03   
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		        Gn1 
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		        En1 
	.byte	W36
	.byte		        Fn1 
	.byte	W03
	.byte		        Gs1 
	.byte	W03
	.byte		        As1 
	.byte	W03
	.byte		        Bn1 
	.byte	W03
	.byte		N36   , Cn2 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N03   
	.byte	W03
	.byte		        Bn1 
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		        Gn1 
	.byte	W03
	.byte		        Fn1 
	.byte	W36
	.byte		        Fs1 
	.byte	W03
	.byte		        Bn1 
	.byte	W03
	.byte		        Cn2 
	.byte	W03
	.byte		        Cs2 
	.byte	W03
	.byte		N36   , Dn2 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N03   
	.byte	W03
	.byte		        Cn2 
	.byte	W03
	.byte		        As1 
	.byte	W03
	.byte		        Gn1 
	.byte	W03
	.byte		        Fn1 
	.byte	W36
	.byte		N03   
	.byte	W03
	.byte		        Gs1 
	.byte	W03
	.byte		        As1 
	.byte	W03
	.byte		        Bn1 
	.byte	W03
	.byte		N36   , Cn2 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N03   
	.byte	W03
	.byte		        Bn1 
	.byte	W03
	.byte		        Gs1 
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		        En1 
	.byte	W24
	.byte		VOICE , 35
	.byte		N48   , Bn1 
	.byte	W12
	.byte		MOD   , 8
	.byte	W36
	.byte		        0
	.byte		N24   , En2 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		VOICE , 62
	.byte		MOD   , 0
	.byte		PAN   , c_v-16
	.byte		VOL   , 58*bgm_frlg_silph_mvl/mxv
	.byte		N12   , Bn2 , v120
	.byte	W12
	.byte		N03   , En2 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N03   , En2 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N24   , Bn1 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N06   , Bn2 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+31
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N06   , En3 
	.byte	W06
	.byte		N03   , En3 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N12   , En3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Bn3 , v096
	.byte	W06
	.byte		N03   , Bn3 , v100
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N06   , En3 , v120
	.byte	W06
	.byte		N03   , En3 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N24   , Bn2 
	.byte	W24
	.byte		N06   , En3 , v120
	.byte	W06
	.byte		N03   , En3 , v108
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N24   , Bn2 
	.byte	W24
	.byte		N06   , Bn2 , v080
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   , Bn2 , v092
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N06   , En3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   , Bn2 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		VOL   , 38*bgm_frlg_silph_mvl/mxv
	.byte		PAN   , c_v+38
	.byte		BEND  , c_v+63
	.byte		N48   , En3 
	.byte	W03
	.byte		BEND  , c_v+59
	.byte	W02
	.byte		        c_v+56
	.byte	W03
	.byte		        c_v+49
	.byte	W03
	.byte		        c_v+45
	.byte	W01
	.byte		PAN   , c_v+32
	.byte	W02
	.byte		BEND  , c_v+42
	.byte	W03
	.byte		        c_v+36
	.byte	W03
	.byte		        c_v+32
	.byte	W03
	.byte		        c_v+27
	.byte	W01
	.byte		PAN   , c_v+23
	.byte	W02
	.byte		BEND  , c_v+24
	.byte	W03
	.byte		        c_v+20
	.byte	W03
	.byte		        c_v+16
	.byte	W03
	.byte		        c_v+14
	.byte	W01
	.byte		PAN   , c_v+16
	.byte	W02
	.byte		BEND  , c_v+10
	.byte	W03
	.byte		        c_v+7
	.byte	W03
	.byte		        c_v+4
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N48   
	.byte	W03
	.byte		BEND  , c_v-5
	.byte	W02
	.byte		        c_v-8
	.byte	W01
	.byte		PAN   , c_v-10
	.byte	W02
	.byte		BEND  , c_v-15
	.byte	W03
	.byte		        c_v-21
	.byte	W03
	.byte		        c_v-27
	.byte	W01
	.byte		PAN   , c_v-17
	.byte	W02
	.byte		BEND  , c_v-31
	.byte	W03
	.byte		        c_v-35
	.byte	W03
	.byte		        c_v-38
	.byte	W01
	.byte		PAN   , c_v-29
	.byte	W02
	.byte		BEND  , c_v-43
	.byte	W03
	.byte		        c_v-48
	.byte	W03
	.byte		        c_v-51
	.byte	W01
	.byte		PAN   , c_v-38
	.byte	W02
	.byte		BEND  , c_v-55
	.byte	W03
	.byte		        c_v-59
	.byte	W03
	.byte		        c_v-63
	.byte	W07
	.byte		PAN   , c_v-16
	.byte		VOL   , 58*bgm_frlg_silph_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N12   , Fn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Ds2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N06   , Cs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Dn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N12   , Ds2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N24   , An2 
	.byte	W24
	.byte		PAN   , c_v-16
	.byte		N06   , Fn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 31
	.byte		N12   , Dn3 , v096
	.byte	W12
	.byte		VOICE , 62
	.byte		PAN   , c_v+32
	.byte		N06   , Fn2 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N06   , Dn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N24   , An2 
	.byte	W24
	.byte		PAN   , c_v-16
	.byte		N06   , Fn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N36   , As2 
	.byte	W12
	.byte		BEND  , c_v-5
	.byte	W02
	.byte		        c_v-15
	.byte	W04
	.byte		        c_v-21
	.byte	W02
	.byte		        c_v-27
	.byte	W01
	.byte		        c_v-34
	.byte	W03
	.byte		        c_v-37
	.byte	W02
	.byte		        c_v-35
	.byte	W01
	.byte		        c_v-50
	.byte	W02
	.byte		        c_v-41
	.byte	W01
	.byte		        c_v-56
	.byte	W02
	.byte		        c_v-51
	.byte	W01
	.byte		        c_v-63
	.byte	W03
	.byte		PAN   , c_v-16
	.byte		BEND  , c_v+0
	.byte		N06   , Dn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N12   , Cs3 , v092
	.byte	W12
	.byte		VOICE , 62
	.byte		N06   , Dn2 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N48   , Dn3 
	.byte	W06
	.byte		BEND  , c_v-6
	.byte	W03
	.byte		        c_v-11
	.byte	W06
	.byte		        c_v-15
	.byte	W03
	.byte		        c_v-19
	.byte	W03
	.byte		        c_v-27
	.byte	W03
	.byte		        c_v-32
	.byte	W06
	.byte		        c_v-40
	.byte	W03
	.byte		        c_v-44
	.byte	W06
	.byte		        c_v-51
	.byte	W03
	.byte		        c_v-63
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		BEND  , c_v+0
	.byte		N03   , Cn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 31
	.byte		PAN   , c_v+32
	.byte		N12   , An2 
	.byte	W12
	.byte		VOICE , 62
	.byte		PAN   , c_v-17
	.byte		N03   , Cn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , An2 , v092
	.byte	W12
	.byte		VOICE , 62
	.byte		VOL   , 65*bgm_frlg_silph_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		BEND  , c_v-8
	.byte		N09   , En2 , v120
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		N06   
	.byte	W12
	.byte		N03   , Bn2 
	.byte	W12
	.byte		N09   , En2 , v127
	.byte	W12
	.byte		BEND  , c_v+5
	.byte		N03   , En2 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N03   , En2 , v127
	.byte	W06
	.byte		        En2 , v120
	.byte	W06
	.byte		VOICE , 31
	.byte		PAN   , c_v+40
	.byte		N24   , Bn2 , v076
	.byte	W24
	.byte		VOICE , 62
	.byte		PAN   , c_v-16
	.byte		VOL   , 58*bgm_frlg_silph_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , Bn2 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N06   , Bn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N06   , En3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N06   , En3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOL   , 64*bgm_frlg_silph_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		BEND  , c_v+0
	.byte		N03   , En2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En2 , v127
	.byte	W06
	.byte		        En2 , v120
	.byte	W06
	.byte		BEND  , c_v-8
	.byte		N03   
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		VOICE , 31
	.byte	W15
	.byte		N24   , En3 , v036
	.byte	W24
	.byte		VOICE , 62
	.byte		PAN   , c_v-16
	.byte		VOL   , 58*bgm_frlg_silph_mvl/mxv
	.byte		N06   , En3 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+42
	.byte		BEND  , c_v+63
	.byte		N48   , En2 
	.byte	W03
	.byte		BEND  , c_v+55
	.byte	W03
	.byte		PAN   , c_v+32
	.byte		BEND  , c_v+48
	.byte	W03
	.byte		        c_v+40
	.byte	W03
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v+32
	.byte	W03
	.byte		        c_v+23
	.byte	W03
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+15
	.byte	W03
	.byte		        c_v+6
	.byte	W03
	.byte		PAN   , c_v-8
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		        c_v-16
	.byte	W03
	.byte		PAN   , c_v-16
	.byte		BEND  , c_v-33
	.byte	W03
	.byte		        c_v-48
	.byte	W03
	.byte		PAN   , c_v-18
	.byte		BEND  , c_v-56
	.byte	W03
	.byte		        c_v-64
	.byte	W06
	.byte		VOL   , 67*bgm_frlg_silph_mvl/mxv
	.byte	W03
	.byte		BEND  , c_v+0
	.byte		N03   , Bn1 , v127
	.byte	W03
	.byte		PAN   , c_v-16
	.byte		N03   , As1 
	.byte	W03
	.byte		PAN   , c_v-7
	.byte		N03   , Gs1 
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		PAN   , c_v+32
	.byte		N03   , Fn1 
	.byte	W03
	.byte		N30   , En1 
	.byte	W09
	.byte		MOD   , 6
	.byte	W24
	.byte		N03   , En1 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , Fn1 , v127
	.byte	W03
	.byte		PAN   , c_v+15
	.byte		N03   , Fs1 
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N03   , Gs1 
	.byte	W03
	.byte		        As1 
	.byte	W03
	.byte		PAN   , c_v-32
	.byte		N03   , Bn1 
	.byte	W03
	.byte		PAN   , c_v-16
	.byte		N21   , Cn2 
	.byte	W09
	.byte		MOD   , 6
	.byte	W12
	.byte		N03   , Cn2 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , Bn1 , v127
	.byte	W03
	.byte		PAN   , c_v-16
	.byte		N03   , As1 
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N03   , Gs1 
	.byte	W03
	.byte		PAN   , c_v+32
	.byte		N03   , Fs1 
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		N09   , En1 
	.byte	W09
	.byte		MOD   , 6
	.byte		N03   , En1 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En1 , v116
	.byte	W06
	.byte		        En1 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En1 , v116
	.byte	W06
	.byte		        En1 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , Fn1 , v127
	.byte	W03
	.byte		PAN   , c_v+15
	.byte		N03   , Gn1 
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N03   , As1 
	.byte	W03
	.byte		        Cn2 
	.byte	W03
	.byte		PAN   , c_v-32
	.byte		N03   , Cs2 
	.byte	W03
	.byte		PAN   , c_v-16
	.byte		N30   , Dn2 
	.byte	W09
	.byte		MOD   , 6
	.byte	W24
	.byte		VOL   , 62*bgm_frlg_silph_mvl/mxv
	.byte		BEND  , c_v-2
	.byte		N03   , Dn2 , v120
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		VOL   , 57*bgm_frlg_silph_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		VOL   , 52*bgm_frlg_silph_mvl/mxv
	.byte		N03   
	.byte	W06
	.byte		VOL   , 46*bgm_frlg_silph_mvl/mxv
	.byte		BEND  , c_v-8
	.byte		N03   
	.byte	W06
	.byte		VOL   , 41*bgm_frlg_silph_mvl/mxv
	.byte		N03   
	.byte	W06
	.byte		VOL   , 35*bgm_frlg_silph_mvl/mxv
	.byte		BEND  , c_v-10
	.byte		N03   
	.byte	W06
	.byte		VOL   , 25*bgm_frlg_silph_mvl/mxv
	.byte		N03   
	.byte	W06
	.byte		VOICE , 31
	.byte		MOD   , 0
	.byte		VOL   , 58*bgm_frlg_silph_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		TIE   , En4 , v064
	.byte	W24
	.byte		PAN   , c_v-1
	.byte	W06
	.byte		        c_v+7
	.byte	W06
	.byte		        c_v+18
	.byte	W06
	.byte		        c_v+26
	.byte	W06
	.byte		        c_v+32
	.byte	W24
	.byte		        c_v+23
	.byte	W06
	.byte		        c_v+8
	.byte	W06
	.byte		        c_v-14
	.byte	W06
	.byte		        c_v-24
	.byte	W06
	.byte		VOL   , 55*bgm_frlg_silph_mvl/mxv
	.byte		PAN   , c_v-33
	.byte	W06
	.byte		VOL   , 50*bgm_frlg_silph_mvl/mxv
	.byte	W06
	.byte		        46*bgm_frlg_silph_mvl/mxv
	.byte	W06
	.byte		        42*bgm_frlg_silph_mvl/mxv
	.byte	W06
	.byte		        38*bgm_frlg_silph_mvl/mxv
	.byte	W06
	.byte		        34*bgm_frlg_silph_mvl/mxv
	.byte	W06
	.byte		        30*bgm_frlg_silph_mvl/mxv
	.byte	W06
	.byte		        27*bgm_frlg_silph_mvl/mxv
	.byte	W06
	.byte		        23*bgm_frlg_silph_mvl/mxv
	.byte		PAN   , c_v-22
	.byte	W06
	.byte		VOL   , 20*bgm_frlg_silph_mvl/mxv
	.byte	W06
	.byte		        16*bgm_frlg_silph_mvl/mxv
	.byte		PAN   , c_v-16
	.byte	W06
	.byte		VOL   , 12*bgm_frlg_silph_mvl/mxv
	.byte	W06
	.byte		        10*bgm_frlg_silph_mvl/mxv
	.byte		PAN   , c_v-1
	.byte	W06
	.byte		VOL   , 9*bgm_frlg_silph_mvl/mxv
	.byte		PAN   , c_v+4
	.byte	W06
	.byte		        c_v+15
	.byte	W12
	.byte		EOT   
	.byte		VOL   , 38*bgm_frlg_silph_mvl/mxv
	.byte		PAN   , c_v+21
	.byte		N36   , En4 , v016
	.byte	W06
	.byte		PAN   , c_v+26
	.byte	W03
	.byte		VOL   , 31*bgm_frlg_silph_mvl/mxv
	.byte	W03
	.byte		        29*bgm_frlg_silph_mvl/mxv
	.byte		PAN   , c_v+31
	.byte	W06
	.byte		VOL   , 22*bgm_frlg_silph_mvl/mxv
	.byte		PAN   , c_v+39
	.byte	W06
	.byte		VOL   , 19*bgm_frlg_silph_mvl/mxv
	.byte		PAN   , c_v+44
	.byte	W06
	.byte		VOL   , 13*bgm_frlg_silph_mvl/mxv
	.byte	W03
	.byte		        8*bgm_frlg_silph_mvl/mxv
	.byte	W06
	.byte		        5*bgm_frlg_silph_mvl/mxv
	.byte	W03
	.byte		        4*bgm_frlg_silph_mvl/mxv
	.byte	W06
	.byte		        0*bgm_frlg_silph_mvl/mxv
	.byte	W24
	.byte		        76*bgm_frlg_silph_mvl/mxv
	.byte	W24
	.byte		VOICE , 35
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v127
	.byte	W12
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        En1 
	.byte	W42
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_silph_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_frlg_silph_5:
	.byte	KEYSH , bgm_frlg_silph_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 38*bgm_frlg_silph_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_silph_mvl/mxv
	.byte	W68
	.byte	W01
	.byte		PAN   , c_v-32
	.byte		N24   , Bn3 , v120
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , As3 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Bn3 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Cn4 
	.byte	W24
bgm_frlg_silph_5_B1:
	.byte		PAN   , c_v-32
	.byte		N24   , Bn3 , v120
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , As3 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , An3 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , As3 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Bn3 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Cn4 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Cs4 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Dn4 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Ds4 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , As3 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , An3 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , As3 
	.byte	W24
	.byte		VOICE , 24
	.byte		PAN   , c_v-32
	.byte		VOL   , 53*bgm_frlg_silph_mvl/mxv
	.byte		N24   , Bn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+32
	.byte		N24   , As3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v-32
	.byte		N24   , Bn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+32
	.byte		N18   , Cn4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v-32
	.byte		N24   , Bn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+32
	.byte		N24   , As3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v-32
	.byte		N12   , An3 
	.byte	W12
	.byte		MOD   , 8
	.byte		N30   , As3 
	.byte	W12
	.byte		MOD   , 0
	.byte		PAN   , c_v+32
	.byte	W12
	.byte		MOD   , 8
	.byte	W06
	.byte		N03   , An3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v-32
	.byte		N24   , Bn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+32
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v-32
	.byte		N12   , Cs4 
	.byte	W12
	.byte		MOD   , 8
	.byte		N36   , Dn4 
	.byte	W12
	.byte		MOD   , 0
	.byte		PAN   , c_v+32
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v-32
	.byte		N18   , Ds4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v+32
	.byte		N24   , As3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v-32
	.byte		N24   , An3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+32
	.byte		N24   , As3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v-32
	.byte		N24   , Bn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N03   , En3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		PAN   , c_v-16
	.byte		N03   , Gn3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		PAN   , c_v+18
	.byte		N03   , Cs4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v+32
	.byte		N48   , En4 
	.byte	W15
	.byte		MOD   , 8
	.byte	W32
	.byte	W01
	.byte		        0
	.byte		PAN   , c_v-32
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , An4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N60   , Cn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W48
	.byte		        0
	.byte		N12   
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N60   , Cs4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W48
	.byte		        0
	.byte		N12   
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N60   , Dn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W48
	.byte		        0
	.byte		N12   
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
bgm_frlg_silph_5_000:
	.byte		N12   , Cn4 , v120
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_silph_5_000
	.byte		N12   , Cn4 , v120
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N03   , As3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		N06   , As3 
	.byte	W06
	.byte		N12   , An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
bgm_frlg_silph_5_001:
	.byte		VOL   , 57*bgm_frlg_silph_mvl/mxv
	.byte		N24   , Bn2 , v120
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , As2 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Bn2 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Cn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte	PEND
	.byte		        0
	.byte		VOL   , 53*bgm_frlg_silph_mvl/mxv
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_silph_5_001
	.byte		MOD   , 0
	.byte		VOL   , 54*bgm_frlg_silph_mvl/mxv
	.byte		N12   , Bn3 , v120
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		VOICE , 48
	.byte		VOL   , 28*bgm_frlg_silph_mvl/mxv
	.byte		N24   , Bn3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        As3 , v032
	.byte	W12
	.byte		N06   , Bn1 , v072
	.byte	W12
	.byte		        Bn1 , v028
	.byte	W12
	.byte		        Bn1 , v084
	.byte	W12
	.byte		        Bn1 , v028
	.byte	W12
	.byte		        Bn1 , v108
	.byte	W12
	.byte		        Bn1 , v028
	.byte	W12
	.byte		N12   , Bn1 , v084
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N24   , Bn3 , v040
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , As3 , v056
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Bn3 , v064
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Cn4 , v084
	.byte	W24
	.byte	GOTO
	 .word	bgm_frlg_silph_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_frlg_silph_6:
	.byte	KEYSH , bgm_frlg_silph_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 38*bgm_frlg_silph_mvl/mxv
	.byte		PAN   , c_v-1
	.byte		N03   , En3 , v127
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		N42   , Cn4 
	.byte	W42
	.byte		N03   , Bn3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		VOL   , 41*bgm_frlg_silph_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+0
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Fn4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
bgm_frlg_silph_6_B1:
	.byte		MOD   , 0
	.byte		PAN   , c_v+0
	.byte		N24   , En4 , v127
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+0
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+0
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Fn4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+0
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+0
	.byte		N24   , Gs4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+0
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		VOICE , 24
	.byte		PAN   , c_v+0
	.byte		VOL   , 57*bgm_frlg_silph_mvl/mxv
	.byte		MOD   , 0
	.byte		PAN   , c_v+0
	.byte		N24   , En5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Ds5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+0
	.byte		N24   , En5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N18   , Fn5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W06
	.byte		N03   , Fs5 , v120
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v+0
	.byte		N24   , En5 , v127
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Ds5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+0
	.byte		N12   , Dn5 
	.byte	W12
	.byte		MOD   , 8
	.byte		N30   , Ds5 
	.byte	W12
	.byte		MOD   , 0
	.byte	W12
	.byte		        8
	.byte	W06
	.byte		N03   , Dn5 , v120
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v+0
	.byte		N24   , En5 , v127
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Fn5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+0
	.byte		N12   , Fs5 
	.byte	W12
	.byte		MOD   , 8
	.byte		N36   , Gn5 
	.byte	W12
	.byte		MOD   , 0
	.byte	W12
	.byte		        8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+0
	.byte		N18   , Gs5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W06
	.byte		N03   , Fs5 , v120
	.byte	W03
	.byte		        En5 
	.byte	W03
	.byte		MOD   , 0
	.byte		N24   , Ds5 , v127
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+0
	.byte		N24   , Dn5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Ds5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+0
	.byte		N48   , En5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W36
	.byte		        0
	.byte		N48   , Bn5 
	.byte	W15
	.byte		MOD   , 8
	.byte	W32
	.byte	W01
	.byte		VOICE , 17
	.byte		MOD   , 0
	.byte		VOL   , 76*bgm_frlg_silph_mvl/mxv
	.byte		N12   , En4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N60   , Fn4 
	.byte	W60
	.byte		N12   
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N60   , Fs4 
	.byte	W60
	.byte		N12   
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N60   , Gn4 
	.byte	W60
	.byte		N12   
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N03   , Ds4 
	.byte	W03
	.byte		        Fs4 , v120
	.byte	W03
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N12   , Dn4 , v127
	.byte	W12
	.byte		        Ds4 
	.byte	W12
bgm_frlg_silph_6_000:
	.byte		VOICE , 48
	.byte		PAN   , c_v+16
	.byte		VOL   , 50*bgm_frlg_silph_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N24   , En3 , v127
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v-21
	.byte		N24   , Ds3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+22
	.byte		N24   , En3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v-25
	.byte		N24   , Fn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte	PEND
	.byte		VOICE , 24
	.byte		MOD   , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 63*bgm_frlg_silph_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N12   , En5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_silph_6_000
	.byte		VOICE , 24
	.byte		MOD   , 0
	.byte		VOL   , 64*bgm_frlg_silph_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-1
	.byte		N12   , En5 , v127
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		N12   , Fn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		VOICE , 48
	.byte		VOL   , 41*bgm_frlg_silph_mvl/mxv
	.byte		N24   , En5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Ds5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , En5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Fn5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , En5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Ds5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Dn5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Ds5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , En5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Fn5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Fs5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Gn5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Gs5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Ds5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Dn5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Ds5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		VOICE , 24
	.byte		VOL   , 67*bgm_frlg_silph_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , En5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Ds5 , v032
	.byte	W12
	.byte		N06   , Gn2 , v068
	.byte	W12
	.byte		        Gn2 , v028
	.byte	W12
	.byte		        Fs2 , v084
	.byte	W12
	.byte		        Fs2 , v028
	.byte	W12
	.byte		        Gn2 , v104
	.byte	W12
	.byte		        Gn2 , v032
	.byte	W12
	.byte		N12   , Gs2 , v076
	.byte	W12
	.byte		VOICE , 48
	.byte		PAN   , c_v-32
	.byte		VOL   , 41*bgm_frlg_silph_mvl/mxv
	.byte		N24   , En4 , v040
	.byte	W24
	.byte		        Ds4 , v048
	.byte	W24
	.byte		        En4 , v064
	.byte	W24
	.byte		        Fn4 , v096
	.byte	W24
	.byte	GOTO
	 .word	bgm_frlg_silph_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_frlg_silph_7:
	.byte	KEYSH , bgm_frlg_silph_key+0
	.byte		VOICE , 0
	.byte		VOL   , 62*bgm_frlg_silph_mvl/mxv
	.byte		N03   , Dn2 , v120
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Gn1 
	.byte	W03
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte		N32   , An2 
	.byte	W32
	.byte	W01
	.byte		N24   , Cn3 
	.byte	W24
bgm_frlg_silph_7_000:
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PEND
bgm_frlg_silph_7_B1:
	.byte		N06   , Cn1 , v120
	.byte	W12
	.byte		N12   , Fn1 
	.byte	W24
	.byte		N06   , Cn1 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N03   , En1 , v056
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Gn1 , v120
	.byte	W12
	.byte		        Fn1 
	.byte	W06
	.byte		N03   , En1 , v056
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v120
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 , v056
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v120
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N12   , Cn2 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        Dn1 , v060
	.byte	W12
	.byte		        Dn1 , v040
	.byte	W12
	.byte		N06   , Cn1 , v120
	.byte	W12
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N12   , Cn2 , v127
	.byte	W12
	.byte		        Fn1 , v120
	.byte	W12
	.byte		N24   , An2 
	.byte	W24
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N24   , En2 
	.byte	W24
	.byte		        Gn2 , v127
	.byte	W36
	.byte		N06   , Cn1 , v120
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N12   , Cs1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
bgm_frlg_silph_7_001:
	.byte		N06   , Cn1 , v120
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_silph_7_001
	.byte	PATT
	 .word	bgm_frlg_silph_7_001
	.byte	PATT
	 .word	bgm_frlg_silph_7_001
	.byte		N06   , Cn1 , v120
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 , v080
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W24
	.byte		        Cn1 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W24
	.byte		        Cs1 
	.byte	W24
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W24
	.byte		        Cs1 
	.byte	W24
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cs1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , Fn2 , v080
	.byte	W12
	.byte		        Fn2 , v112
	.byte	W12
	.byte		        Dn2 , v120
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Fn2 , v084
	.byte	W12
	.byte		        Fn2 , v112
	.byte	W12
	.byte		        Dn2 , v120
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N06   , Fn2 , v084
	.byte	W12
	.byte		        Fn2 , v116
	.byte	W12
	.byte		N03   , Dn2 , v120
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Cn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W06
	.byte		        Dn1 , v080
	.byte	W06
	.byte		        Dn1 , v108
	.byte	W06
	.byte		        Dn1 , v080
	.byte	W06
bgm_frlg_silph_7_002:
	.byte		N06   , Cn1 , v120
	.byte	W24
	.byte		        Fn2 
	.byte	W24
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fn2 
	.byte	W24
	.byte	PEND
bgm_frlg_silph_7_003:
	.byte		N06   , Cn1 , v120
	.byte	W24
	.byte		        Fn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_silph_7_002
	.byte	PATT
	 .word	bgm_frlg_silph_7_003
	.byte		N96   , Cs2 , v120
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_silph_7_000
	.byte	GOTO
	 .word	bgm_frlg_silph_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_frlg_silph_8:
	.byte	KEYSH , bgm_frlg_silph_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 38*bgm_frlg_silph_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W72
bgm_frlg_silph_8_000:
	.byte		N03   , Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W24
	.byte	PEND
bgm_frlg_silph_8_B1:
bgm_frlg_silph_8_001:
	.byte		N03   , Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_silph_8_000
	.byte	PATT
	 .word	bgm_frlg_silph_8_001
bgm_frlg_silph_8_002:
	.byte		N03   , Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W18
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_silph_8_002
	.byte	PATT
	 .word	bgm_frlg_silph_8_002
	.byte	PATT
	 .word	bgm_frlg_silph_8_002
	.byte	PATT
	 .word	bgm_frlg_silph_8_001
	.byte		N03   , Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W24
	.byte	PATT
	 .word	bgm_frlg_silph_8_001
	.byte		N03   , Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W18
	.byte	PATT
	 .word	bgm_frlg_silph_8_001
	.byte	PATT
	 .word	bgm_frlg_silph_8_001
	.byte	PATT
	 .word	bgm_frlg_silph_8_001
	.byte	PATT
	 .word	bgm_frlg_silph_8_001
bgm_frlg_silph_8_003:
	.byte		N03   , Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W18
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W18
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W18
	.byte	PEND
bgm_frlg_silph_8_004:
	.byte		N03   , Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
bgm_frlg_silph_8_005:
	.byte		N03   , Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_silph_8_005
	.byte	PATT
	 .word	bgm_frlg_silph_8_003
	.byte	PATT
	 .word	bgm_frlg_silph_8_004
	.byte	PATT
	 .word	bgm_frlg_silph_8_003
	.byte	PATT
	 .word	bgm_frlg_silph_8_004
	.byte	PATT
	 .word	bgm_frlg_silph_8_003
	.byte	PATT
	 .word	bgm_frlg_silph_8_004
	.byte	PATT
	 .word	bgm_frlg_silph_8_001
	.byte	PATT
	 .word	bgm_frlg_silph_8_001
	.byte	PATT
	 .word	bgm_frlg_silph_8_001
	.byte	PATT
	 .word	bgm_frlg_silph_8_001
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	bgm_frlg_silph_8_000
	.byte	GOTO
	 .word	bgm_frlg_silph_8_B1
	.byte	FINE

@********************** Track  9 **********************@

bgm_frlg_silph_9:
	.byte	KEYSH , bgm_frlg_silph_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 38*bgm_frlg_silph_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W72
	.byte	W84
	.byte		N12   , Gn5 , v120
	.byte	W12
bgm_frlg_silph_9_B1:
	.byte	W96
	.byte	W84
	.byte		N12   , Gn5 , v120
	.byte	W12
	.byte	W96
	.byte	W36
	.byte		N12   
	.byte	W60
	.byte	W36
	.byte		N12   
	.byte	W60
	.byte	W36
	.byte		N12   
	.byte	W60
	.byte	W36
	.byte		N12   
	.byte	W60
	.byte	W96
	.byte	W84
	.byte		N12   
	.byte	W12
	.byte	W96
	.byte	W84
	.byte		N12   
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_frlg_silph_9_000:
	.byte	W12
	.byte		N12   , Gn5 , v120
	.byte	W24
	.byte		N12   
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	W96
bgm_frlg_silph_9_001:
	.byte	W24
	.byte		N12   , Gn5 , v120
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_silph_9_001
	.byte	PATT
	 .word	bgm_frlg_silph_9_000
	.byte	W96
	.byte	PATT
	 .word	bgm_frlg_silph_9_000
	.byte	W96
	.byte	PATT
	 .word	bgm_frlg_silph_9_000
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		N12   , Gn5 , v120
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_silph_9_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_frlg_silph:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_frlg_silph_pri	@ Priority
	.byte	bgm_frlg_silph_rev	@ Reverb.

	.word	bgm_frlg_silph_grp

	.word	bgm_frlg_silph_1
	.word	bgm_frlg_silph_2
	.word	bgm_frlg_silph_3
	.word	bgm_frlg_silph_4
	.word	bgm_frlg_silph_5
	.word	bgm_frlg_silph_6
	.word	bgm_frlg_silph_7
	.word	bgm_frlg_silph_8
	.word	bgm_frlg_silph_9

	.end
