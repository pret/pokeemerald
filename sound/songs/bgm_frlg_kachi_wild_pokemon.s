	.include "MPlayDef.s"

	.equ	bgm_frlg_kachi_wild_pokemon_grp, voicegroup_86AE338
	.equ	bgm_frlg_kachi_wild_pokemon_pri, 0
	.equ	bgm_frlg_kachi_wild_pokemon_rev, reverb_set+50
	.equ	bgm_frlg_kachi_wild_pokemon_mvl, 127
	.equ	bgm_frlg_kachi_wild_pokemon_key, 0
	.equ	bgm_frlg_kachi_wild_pokemon_tbs, 1
	.equ	bgm_frlg_kachi_wild_pokemon_exg, 0
	.equ	bgm_frlg_kachi_wild_pokemon_cmp, 1

	.section .rodata
	.global	bgm_frlg_kachi_wild_pokemon
	.align	2

@********************** Track  1 **********************@

bgm_frlg_kachi_wild_pokemon_1:
	.byte	KEYSH , bgm_frlg_kachi_wild_pokemon_key+0
	.byte	TEMPO , 140*bgm_frlg_kachi_wild_pokemon_tbs/2
	.byte	W09
	.byte		VOICE , 73
	.byte		VOL   , 90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		BENDR , 3
	.byte		PAN   , c_v-8
	.byte		BEND  , c_v+0
	.byte		N06   , En4 , v112
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N68   , Bn4 
	.byte	W06
	.byte		VOL   , 77*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        59*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        51*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        42*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W12
	.byte		MOD   , 5
	.byte	W03
	.byte		VOL   , 50*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        55*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        63*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        71*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        79*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W15
bgm_frlg_kachi_wild_pokemon_1_B1:
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N06   , Bn4 , v112
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		        Cs5 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , Bn4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		        Cs5 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , Bn4 
	.byte	W24
	.byte		        Cn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
bgm_frlg_kachi_wild_pokemon_1_000:
	.byte		N06   , Cn5 , v112
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte	PEND
	.byte		        Dn5 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , Cn5 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte	PATT
	 .word	bgm_frlg_kachi_wild_pokemon_1_000
	.byte		N06   , Dn5 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , Cn5 
	.byte	W24
	.byte		        Bn3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte	GOTO
	 .word	bgm_frlg_kachi_wild_pokemon_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_frlg_kachi_wild_pokemon_2:
	.byte	KEYSH , bgm_frlg_kachi_wild_pokemon_key+0
	.byte	W09
	.byte		VOICE , 56
	.byte		VOL   , 90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		PAN   , c_v+10
	.byte		N06   , Gs3 , v080
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N68   , En4 , v100
	.byte	W06
	.byte		VOL   , 77*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        59*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        51*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        42*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W12
	.byte		MOD   , 5
	.byte	W03
	.byte		VOL   , 50*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        55*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        63*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        71*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        79*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W15
bgm_frlg_kachi_wild_pokemon_2_B1:
	.byte		VOICE , 56
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte	W12
	.byte		N06   , En3 , v092
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W36
	.byte		VOICE , 47
	.byte		PAN   , c_v+10
	.byte		N12   , An1 , v112
	.byte	W12
	.byte		        Bn1 
	.byte	W48
	.byte		VOICE , 56
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		N06   , En3 , v092
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		VOICE , 47
	.byte		PAN   , c_v+10
	.byte		N12   , An1 , v112
	.byte	W24
	.byte		        Bn1 
	.byte	W48
bgm_frlg_kachi_wild_pokemon_2_000:
	.byte		VOICE , 56
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		N06   , Fn3 , v092
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte		N06   
	.byte	W36
	.byte		VOICE , 47
	.byte		PAN   , c_v+10
	.byte		N12   , As1 , v112
	.byte	W12
	.byte		        Cn2 
	.byte	W48
	.byte	PATT
	 .word	bgm_frlg_kachi_wild_pokemon_2_000
	.byte		N06   , Fn3 , v092
	.byte	W24
	.byte		VOICE , 47
	.byte		PAN   , c_v+10
	.byte		N12   , As1 , v112
	.byte	W24
	.byte		        Cn2 
	.byte	W48
	.byte	GOTO
	 .word	bgm_frlg_kachi_wild_pokemon_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_frlg_kachi_wild_pokemon_3:
	.byte	KEYSH , bgm_frlg_kachi_wild_pokemon_key+0
	.byte	W09
	.byte		VOICE , 58
	.byte		VOL   , 90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W24
	.byte		N21   , En1 , v127
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N21   , Bn0 
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N21   , Gs0 
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
bgm_frlg_kachi_wild_pokemon_3_B1:
	.byte		VOL   , 90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N21   , En1 , v127
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N21   , Bn0 
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N21   , En1 
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N21   , Bn0 
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N48   , An1 
	.byte	W06
	.byte		VOL   , 75*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        65*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        60*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        65*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        72*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        77*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        86*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W09
	.byte		        70*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N48   , Bn1 
	.byte	W06
	.byte		VOL   , 73*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        75*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        78*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W09
	.byte		        86*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W09
	.byte		N21   , En1 
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N21   , Bn0 
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N21   , En1 
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N21   , Bn0 
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N24   , An1 
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W30
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N21   , En1 
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N21   , Cn1 
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N21   , Fn1 
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N21   , Cn1 
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N21   , Fn1 
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N21   , Cn1 
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N48   , As1 
	.byte	W06
	.byte		VOL   , 75*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        65*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        60*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        65*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        72*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        77*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        86*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W09
	.byte		        70*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N48   , Cn2 
	.byte	W06
	.byte		VOL   , 73*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        75*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        78*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W09
	.byte		        86*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W09
	.byte		N21   , Fn1 
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N21   , Cn1 
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N21   , Fn1 
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N21   , Cn1 
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N24   , As1 
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W30
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N24   , Fn1 
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N24   , Bn0 
	.byte	W12
	.byte		VOL   , 82*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        28*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte	GOTO
	 .word	bgm_frlg_kachi_wild_pokemon_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_frlg_kachi_wild_pokemon_4:
	.byte	KEYSH , bgm_frlg_kachi_wild_pokemon_key+0
	.byte	W09
	.byte		VOICE , 82
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		PAN   , c_v-48
	.byte		VOL   , 90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N06   , Bn2 , v052
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N72   , Gs3 
	.byte	W06
	.byte		VOL   , 77*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        59*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        51*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        42*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W15
	.byte		        50*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        55*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        63*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        71*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        79*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W15
bgm_frlg_kachi_wild_pokemon_4_B1:
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		N06   , Bn2 , v060
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cs3 
	.byte	W96
	.byte	W12
	.byte		        Bn2 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cs3 
	.byte	W96
bgm_frlg_kachi_wild_pokemon_4_000:
	.byte	W12
	.byte		N06   , Cn3 , v060
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte		        Dn3 
	.byte	W96
	.byte	PATT
	 .word	bgm_frlg_kachi_wild_pokemon_4_000
	.byte		N06   , Dn3 , v060
	.byte	W96
	.byte	GOTO
	 .word	bgm_frlg_kachi_wild_pokemon_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_frlg_kachi_wild_pokemon_5:
	.byte	KEYSH , bgm_frlg_kachi_wild_pokemon_key+0
	.byte	W09
	.byte		VOICE , 80
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		PAN   , c_v+48
	.byte		VOL   , 90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte		N06   , Gs2 , v052
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N72   , En3 
	.byte	W06
	.byte		VOL   , 77*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        68*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        59*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        51*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        42*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W15
	.byte		        50*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W06
	.byte		        55*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        63*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        71*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        79*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W03
	.byte		        90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W15
bgm_frlg_kachi_wild_pokemon_5_B1:
	.byte		VOICE , 83
	.byte		PAN   , c_v+48
	.byte		N03   , Bn5 , v032
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		        Cs6 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		        Bn5 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		        Cs6 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		        Bn5 
	.byte	W48
bgm_frlg_kachi_wild_pokemon_5_000:
	.byte		N03   , Cn6 , v032
	.byte	W12
	.byte		        As5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        As5 
	.byte	W12
	.byte		        Cn6 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte	PEND
	.byte		        Dn6 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		        Cn6 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte	PATT
	 .word	bgm_frlg_kachi_wild_pokemon_5_000
	.byte		N03   , Dn6 , v032
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		        Cn6 
	.byte	W48
	.byte	GOTO
	 .word	bgm_frlg_kachi_wild_pokemon_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_frlg_kachi_wild_pokemon_6:
	.byte	KEYSH , bgm_frlg_kachi_wild_pokemon_key+0
	.byte	W09
	.byte		VOICE , 81
	.byte		VOL   , 90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W36
	.byte		N06   , Ds5 , v080
	.byte	W06
	.byte		        Ds5 , v032
	.byte	W06
	.byte		BEND  , c_v+2
	.byte		N06   , En5 , v080
	.byte	W12
	.byte		        En5 , v032
	.byte	W12
	.byte		        En5 , v080
	.byte	W12
	.byte		        En5 , v032
	.byte	W12
bgm_frlg_kachi_wild_pokemon_6_B1:
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte	W96
	.byte		N06   , An4 , v048
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte	W96
	.byte		        An4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , Gs4 
	.byte	W48
	.byte	W96
	.byte		        As4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , Gn4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte	W96
	.byte		        As4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , An4 
	.byte	W48
	.byte	GOTO
	 .word	bgm_frlg_kachi_wild_pokemon_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_frlg_kachi_wild_pokemon_7:
	.byte	KEYSH , bgm_frlg_kachi_wild_pokemon_key+0
	.byte	W09
	.byte		VOICE , 0
	.byte		VOL   , 90*bgm_frlg_kachi_wild_pokemon_mvl/mxv
	.byte	W24
	.byte		N03   , En1 , v112
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v092
	.byte	W06
	.byte		        En1 , v060
	.byte	W06
	.byte		        En1 , v064
	.byte	W06
	.byte		        En1 , v072
	.byte	W12
	.byte		        En1 , v084
	.byte	W06
	.byte		        En1 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
bgm_frlg_kachi_wild_pokemon_7_B1:
bgm_frlg_kachi_wild_pokemon_7_000:
	.byte		N06   , En1 , v076
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En1 , v064
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Fs2 , v064
	.byte	W12
	.byte		        En1 , v076
	.byte	W06
	.byte		        En1 , v064
	.byte	W06
	.byte		        En1 , v076
	.byte	W12
	.byte		        En1 , v084
	.byte	W06
	.byte		        En1 , v064
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Fs2 , v064
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        En1 , v076
	.byte	W06
	.byte		        En1 , v064
	.byte	W06
	.byte	PEND
bgm_frlg_kachi_wild_pokemon_7_001:
	.byte		N06   , En1 , v112
	.byte	W24
	.byte		        Fs2 , v064
	.byte	W24
	.byte		N12   , Bn2 , v092
	.byte	W24
	.byte		N06   , En1 , v112
	.byte		N03   , Fs2 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Fs2 , v040
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Fs2 , v052
	.byte	W06
	.byte		        En1 , v088
	.byte		N06   , Fs2 , v060
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_kachi_wild_pokemon_7_000
	.byte	PATT
	 .word	bgm_frlg_kachi_wild_pokemon_7_001
	.byte	PATT
	 .word	bgm_frlg_kachi_wild_pokemon_7_000
	.byte	PATT
	 .word	bgm_frlg_kachi_wild_pokemon_7_001
	.byte	PATT
	 .word	bgm_frlg_kachi_wild_pokemon_7_000
	.byte	PATT
	 .word	bgm_frlg_kachi_wild_pokemon_7_001
	.byte	GOTO
	 .word	bgm_frlg_kachi_wild_pokemon_7_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_frlg_kachi_wild_pokemon:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_frlg_kachi_wild_pokemon_pri	@ Priority
	.byte	bgm_frlg_kachi_wild_pokemon_rev	@ Reverb.

	.word	bgm_frlg_kachi_wild_pokemon_grp

	.word	bgm_frlg_kachi_wild_pokemon_1
	.word	bgm_frlg_kachi_wild_pokemon_2
	.word	bgm_frlg_kachi_wild_pokemon_3
	.word	bgm_frlg_kachi_wild_pokemon_4
	.word	bgm_frlg_kachi_wild_pokemon_5
	.word	bgm_frlg_kachi_wild_pokemon_6
	.word	bgm_frlg_kachi_wild_pokemon_7

	.end
