	.include "MPlayDef.s"

	.equ	bgm_suikun_grp, voicegroup_pokemon_cry
	.equ	bgm_suikun_pri, 0
	.equ	bgm_suikun_rev, reverb_set+50
	.equ	bgm_suikun_mvl, 127
	.equ	bgm_suikun_key, 0
	.equ	bgm_suikun_tbs, 1
	.equ	bgm_suikun_exg, 0
	.equ	bgm_suikun_cmp, 1

	.section .rodata
	.global	bgm_suikun
	.align	2

@********************** Track  1 **********************@

bgm_suikun_1:
	.byte	KEYSH , bgm_suikun_key+0
	.byte	TEMPO , 186*bgm_suikun_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 80*bgm_suikun_mvl/mxv
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N12   , As3 
	.byte	W12
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   , En3 
	.byte	W12
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N24   , Cs3 
	.byte	W24
	.byte		N12   , As2 
	.byte	W12
	.byte		VOICE , 56
	.byte		N06   , An2 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
bgm_suikun_1_000:
	.byte		N06   , An2 , v112
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Fn4 
	.byte	W24
	.byte	PEND
bgm_suikun_1_001:
	.byte		N12   , En4 , v112
	.byte	W12
	.byte		N06   , An2 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_1_000
	.byte	PATT
	 .word	bgm_suikun_1_001
	.byte	PATT
	 .word	bgm_suikun_1_000
	.byte	PATT
	 .word	bgm_suikun_1_001
	.byte		N06   , An2 , v112
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		VOICE , 48
	.byte		N06   
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
bgm_suikun_1_B1:
	.byte		VOICE , 1
	.byte		N12   , An2 , v112
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N24   , En3 
	.byte	W24
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        En2 
	.byte	W12
bgm_suikun_1_002:
	.byte		N12   , Dn2 , v112
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		N24   , An2 
	.byte	W24
	.byte		N12   , En2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte	PEND
bgm_suikun_1_003:
	.byte		N12   , Dn3 , v112
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte	PEND
bgm_suikun_1_004:
	.byte		N12   , Dn3 , v112
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte	PEND
bgm_suikun_1_005:
	.byte		N12   , Cn3 , v112
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte	PEND
bgm_suikun_1_006:
	.byte		N12   , Cn3 , v112
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N12   , En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte	PEND
	.byte		        Gn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N36   , An3 
	.byte	W36
	.byte		N24   , Gn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		N12   , En3 
	.byte	W12
	.byte		N36   , Dn3 
	.byte	W36
	.byte		N12   , An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N24   , En3 
	.byte	W24
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte	PATT
	 .word	bgm_suikun_1_002
	.byte	PATT
	 .word	bgm_suikun_1_003
	.byte	PATT
	 .word	bgm_suikun_1_004
	.byte	PATT
	 .word	bgm_suikun_1_005
	.byte	PATT
	 .word	bgm_suikun_1_006
	.byte		N12   , Cn4 , v112
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N24   , An3 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N12   , An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
bgm_suikun_1_007:
	.byte		N12   , Bn2 , v112
	.byte	W12
	.byte		        Cn3 
	.byte	W24
	.byte		N24   , En3 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte	PEND
bgm_suikun_1_008:
	.byte		N12   , Bn2 , v112
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte	PEND
bgm_suikun_1_009:
	.byte		N12   , Cn3 , v112
	.byte	W12
	.byte		        Gn2 
	.byte	W24
	.byte		N60   , Gn3 
	.byte	W60
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_1_009
	.byte	PATT
	 .word	bgm_suikun_1_007
	.byte	PATT
	 .word	bgm_suikun_1_008
	.byte		N12   , Gn3 , v112
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		VOICE , 56
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N36   , Cn3 
	.byte	W36
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Fs1 
	.byte	W24
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Fs1 
	.byte	W24
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Fs1 
	.byte	W24
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
bgm_suikun_1_010:
	.byte		N12   , Bn3 , v112
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Fs1 
	.byte	W24
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Fs1 
	.byte	W24
	.byte	PEND
bgm_suikun_1_011:
	.byte		N12   , Bn3 , v112
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Fs1 
	.byte	W24
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N36   , Cn4 
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_1_010
	.byte	PATT
	 .word	bgm_suikun_1_011
bgm_suikun_1_012:
	.byte		N48   , Bn2 , v112
	.byte	W48
	.byte		        En2 
	.byte	W48
	.byte	PEND
	.byte		        Cn3 
	.byte	W48
	.byte		        An2 
	.byte	W48
	.byte	PATT
	 .word	bgm_suikun_1_012
	.byte		N60   , Fn2 , v112
	.byte	W60
	.byte		VOICE , 48
	.byte		N12   , Cn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N48   , Fs1 
	.byte	W48
	.byte		        Bn1 
	.byte	W48
	.byte		        Gn1 
	.byte	W48
	.byte		        Cn2 
	.byte	W48
	.byte		        Bn1 
	.byte	W48
	.byte		        En1 
	.byte	W48
	.byte		N96   , Fn1 
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
bgm_suikun_1_013:
	.byte	W24
	.byte		N12   , Dn3 , v112
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_1_013
	.byte	PATT
	 .word	bgm_suikun_1_013
	.byte	PATT
	 .word	bgm_suikun_1_013
bgm_suikun_1_014:
	.byte	W24
	.byte		N12   , Fn3 , v112
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_1_014
	.byte	PATT
	 .word	bgm_suikun_1_014
	.byte	PATT
	 .word	bgm_suikun_1_014
	.byte		N24   , En3 , v112
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
	.byte		VOICE , 1
	.byte		N12   , En5 
	.byte	W36
	.byte		        Fs5 
	.byte	W12
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        An5 
	.byte	W48
	.byte	W48
	.byte	GOTO
	 .word	bgm_suikun_1_B1
	.byte	W48
	.byte	FINE

@********************** Track  2 **********************@

bgm_suikun_2:
	.byte	KEYSH , bgm_suikun_key+0
	.byte		VOICE , 17
	.byte		VOL   , 80*bgm_suikun_mvl/mxv
	.byte		N06   , En6 , v088
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N12   , An5 
	.byte	W12
	.byte		N06   , En6 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N12   , An5 
	.byte	W12
	.byte		N06   , En6 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N12   , An5 
	.byte	W12
	.byte		N06   , En6 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N12   , An5 
	.byte	W12
	.byte		N06   , En6 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N12   , An5 
	.byte	W12
	.byte		N06   , En6 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N12   , An5 
	.byte	W12
	.byte		N06   , En6 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N12   , An5 
	.byte	W12
	.byte		N06   , En6 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N12   , An5 
	.byte	W12
	.byte		VOICE , 56
	.byte	W24
	.byte		N12   , En2 , v112
	.byte	W48
	.byte		N12   
	.byte	W24
bgm_suikun_2_000:
	.byte	W24
	.byte		N12   , En2 , v112
	.byte	W48
	.byte		        As5 
	.byte	W24
	.byte	PEND
	.byte		        An5 
	.byte	W24
	.byte		        En2 
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte	PATT
	 .word	bgm_suikun_2_000
bgm_suikun_2_001:
	.byte		N12   , An5 , v112
	.byte	W24
	.byte		        En4 
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	W24
	.byte		N12   
	.byte	W48
	.byte		        As5 
	.byte	W24
	.byte	PATT
	 .word	bgm_suikun_2_001
	.byte	W24
	.byte		N12   , En4 , v112
	.byte	W48
	.byte		N12   
	.byte	W24
bgm_suikun_2_B1:
bgm_suikun_2_002:
	.byte		VOICE , 48
	.byte		N48   , An3 , v112
	.byte	W48
	.byte		        Bn3 
	.byte	W48
	.byte	PEND
bgm_suikun_2_003:
	.byte		N48   , Dn3 , v112
	.byte	W48
	.byte		N96   , Dn4 
	.byte	W48
	.byte	PEND
bgm_suikun_2_004:
	.byte	W48
	.byte		VOICE , 1
	.byte		N12   , An5 , v112
	.byte	W36
	.byte		        Bn5 
	.byte	W12
	.byte	PEND
bgm_suikun_2_005:
	.byte	W24
	.byte		N12   , Dn5 , v112
	.byte	W24
	.byte		        Dn6 
	.byte	W48
	.byte	PEND
bgm_suikun_2_006:
	.byte		VOICE , 48
	.byte		N48   , Cn4 , v112
	.byte	W48
	.byte		        Dn4 
	.byte	W48
	.byte	PEND
bgm_suikun_2_007:
	.byte		N48   , Gn3 , v112
	.byte	W48
	.byte		        Fn4 
	.byte	W48
	.byte	PEND
	.byte		N96   , En4 
	.byte	W96
	.byte		VOICE , 1
	.byte		N24   , Gn2 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte	PATT
	 .word	bgm_suikun_2_002
	.byte	PATT
	 .word	bgm_suikun_2_003
	.byte	PATT
	 .word	bgm_suikun_2_004
	.byte	PATT
	 .word	bgm_suikun_2_005
	.byte	PATT
	 .word	bgm_suikun_2_006
	.byte	PATT
	 .word	bgm_suikun_2_007
	.byte		N96   , En4 , v112
	.byte	W96
	.byte		VOICE , 1
	.byte		N12   , Cn4 
	.byte	W48
	.byte		N48   , Gn4 
	.byte	W48
	.byte		VOICE , 48
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W24
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N12   , An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W24
	.byte		N60   , Cn4 
	.byte	W60
	.byte		VOICE , 1
	.byte		N12   , Gn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W24
	.byte		N60   , Cn6 
	.byte	W60
	.byte		VOICE , 48
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W24
	.byte		N24   , Bn4 
	.byte	W24
	.byte		N12   , An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N48   , Gn4 
	.byte	W48
	.byte		        Fs4 
	.byte	W48
	.byte		        En4 
	.byte	W48
	.byte		        Gn4 
	.byte	W48
	.byte		VOICE , 56
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N36   , Gn3 
	.byte	W36
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Bn1 
	.byte	W24
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Bn1 
	.byte	W24
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Bn1 
	.byte	W24
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N36   , Gn3 
	.byte	W36
bgm_suikun_2_008:
	.byte		N12   , Fs4 , v112
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Bn1 
	.byte	W24
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Bn1 
	.byte	W24
	.byte	PEND
bgm_suikun_2_009:
	.byte		N12   , Fs4 , v112
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Bn1 
	.byte	W24
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N36   , Gn4 
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_2_008
	.byte	PATT
	 .word	bgm_suikun_2_009
bgm_suikun_2_010:
	.byte		N48   , Fs3 , v112
	.byte	W48
	.byte		        Bn2 
	.byte	W48
	.byte	PEND
	.byte		        Gn3 
	.byte	W48
	.byte		        En3 
	.byte	W48
	.byte	PATT
	 .word	bgm_suikun_2_010
	.byte		N96   , Cn3 , v112
	.byte	W96
	.byte		VOICE , 48
	.byte		N48   , Bn1 
	.byte	W48
	.byte		        En2 
	.byte	W48
	.byte		        Cn2 
	.byte	W48
	.byte		        Fn2 
	.byte	W48
	.byte		        En2 
	.byte	W48
	.byte		        Bn1 
	.byte	W48
	.byte		N96   , Cn2 
	.byte	W96
	.byte		VOICE , 1
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N24   , Fn2 
	.byte	W24
	.byte		N12   , En2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
bgm_suikun_2_011:
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte	PEND
	.byte		        Bn1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N24   , Fn2 
	.byte	W24
	.byte		N12   , En2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte	PATT
	 .word	bgm_suikun_2_011
	.byte		N12   , Bn2 , v112
	.byte	W03
	.byte		VOICE , 48
	.byte	W09
	.byte		N12   , En3 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N12   , En3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
bgm_suikun_2_012:
	.byte		N12   , Bn2 , v112
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte	PEND
	.byte		        Bn2 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N12   , En3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte	PATT
	 .word	bgm_suikun_2_012
bgm_suikun_2_013:
	.byte		N12   , Dn3 , v112
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte	PEND
bgm_suikun_2_014:
	.byte		N12   , Dn3 , v112
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_2_013
	.byte	PATT
	 .word	bgm_suikun_2_014
bgm_suikun_2_015:
	.byte		N12   , Bn3 , v112
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N24   , Fn4 
	.byte	W24
	.byte		N12   , En4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte	PEND
bgm_suikun_2_016:
	.byte		N12   , Bn3 , v112
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_2_015
	.byte	PATT
	 .word	bgm_suikun_2_016
bgm_suikun_2_017:
	.byte		N12   , Dn4 , v112
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N24   , Gs4 
	.byte	W24
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte	PEND
bgm_suikun_2_018:
	.byte		N12   , Dn4 , v112
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_2_017
	.byte	PATT
	 .word	bgm_suikun_2_018
	.byte		N24   , An4 , v112
	.byte	W48
	.byte		VOICE , 1
	.byte		N12   , An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N24   , En3 
	.byte	W12
bgm_suikun_2_019:
	.byte	W12
	.byte		N12   , Bn2 , v112
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte	PEND
bgm_suikun_2_020:
	.byte		N12   , An2 , v112
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N24   , En3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_2_019
	.byte		N12   , An2 , v112
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W12
bgm_suikun_2_021:
	.byte	W12
	.byte		N12   , Dn3 , v112
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte	PEND
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W12
	.byte	PATT
	 .word	bgm_suikun_2_021
	.byte		N12   , Cn3 , v112
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N24   , En3 
	.byte	W12
	.byte	PATT
	 .word	bgm_suikun_2_019
	.byte	PATT
	 .word	bgm_suikun_2_020
	.byte	PATT
	 .word	bgm_suikun_2_019
	.byte		N12   , An2 , v112
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte	GOTO
	 .word	bgm_suikun_2_B1
	.byte	W48
	.byte	FINE

@********************** Track  3 **********************@

bgm_suikun_3:
	.byte	KEYSH , bgm_suikun_key+0
	.byte		VOICE , 36
	.byte		VOL   , 80*bgm_suikun_mvl/mxv
	.byte	W96
	.byte	W24
	.byte		N24   , An1 , v112
	.byte	W24
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
bgm_suikun_3_000:
	.byte		N12   , Dn1 , v112
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		N24   , An1 
	.byte	W24
	.byte		N12   , En1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte	PEND
bgm_suikun_3_001:
	.byte		N12   , Dn1 , v112
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_3_000
bgm_suikun_3_002:
	.byte		N12   , Dn1 , v112
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		N24   , An1 
	.byte	W24
	.byte		N12   , En1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_3_000
	.byte	PATT
	 .word	bgm_suikun_3_001
	.byte	PATT
	 .word	bgm_suikun_3_000
	.byte	PATT
	 .word	bgm_suikun_3_002
bgm_suikun_3_B1:
bgm_suikun_3_003:
	.byte		N12   , An0 , v112
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_3_003
bgm_suikun_3_004:
	.byte		N12   , An0 , v112
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte	PEND
bgm_suikun_3_005:
	.byte		N12   , An0 , v112
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte	PEND
bgm_suikun_3_006:
	.byte		N12   , Cn1 , v112
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_3_006
	.byte		N12   , Cn1 , v112
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N24   , Cn2 
	.byte	W24
	.byte		N12   , Gn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte	PATT
	 .word	bgm_suikun_3_003
	.byte	PATT
	 .word	bgm_suikun_3_003
	.byte	PATT
	 .word	bgm_suikun_3_004
	.byte	PATT
	 .word	bgm_suikun_3_005
	.byte	PATT
	 .word	bgm_suikun_3_006
	.byte		N12   , Cn1 , v112
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N24   , Cn2 
	.byte	W24
	.byte		N12   , Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
bgm_suikun_3_007:
	.byte		N12   , Bn0 , v112
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_3_007
	.byte		N12   , Cn1 , v112
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N24   , Gn1 
	.byte	W24
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
bgm_suikun_3_008:
	.byte		N12   , Dn1 , v112
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_3_008
	.byte		N12   , Cn1 , v112
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
bgm_suikun_3_009:
	.byte		N12   , Fs1 , v112
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte	PEND
bgm_suikun_3_010:
	.byte		N12   , Fs1 , v112
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N36   , Gn1 
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_3_009
	.byte	PATT
	 .word	bgm_suikun_3_010
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Bn0 
	.byte	W24
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Bn0 
	.byte	W24
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Bn0 
	.byte	W24
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N36   , Cn2 
	.byte	W36
	.byte		N12   , Fs2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Bn0 
	.byte	W24
	.byte		N12   , Fs2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Bn0 
	.byte	W24
	.byte		N12   , Fs2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Bn0 
	.byte	W24
	.byte		N12   , Fs2 
	.byte	W12
	.byte		N36   , Gn2 
	.byte	W36
bgm_suikun_3_011:
	.byte		N48   , Fs1 , v112
	.byte	W48
	.byte		        Bn0 
	.byte	W48
	.byte	PEND
	.byte		        Gn1 
	.byte	W48
	.byte		        En1 
	.byte	W48
	.byte	PATT
	 .word	bgm_suikun_3_011
	.byte		N60   , Cn1 , v112
	.byte	W60
	.byte		N12   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N48   , Bn0 
	.byte	W48
	.byte		        En1 
	.byte	W48
	.byte		        Cn1 
	.byte	W48
	.byte		        Fn1 
	.byte	W48
	.byte		        En1 
	.byte	W48
	.byte		        Bn0 
	.byte	W48
	.byte		N96   , Cn1 
	.byte	W96
bgm_suikun_3_012:
	.byte	W24
	.byte		N12   , Bn0 , v112
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_3_012
	.byte	PATT
	 .word	bgm_suikun_3_012
	.byte	PATT
	 .word	bgm_suikun_3_012
bgm_suikun_3_013:
	.byte		N12   , Bn0 , v112
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_3_013
	.byte	PATT
	 .word	bgm_suikun_3_013
	.byte		N12   , Bn0 , v112
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
bgm_suikun_3_014:
	.byte		N12   , Dn1 , v112
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_3_014
	.byte	PATT
	 .word	bgm_suikun_3_014
bgm_suikun_3_015:
	.byte		N12   , Dn1 , v112
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte	PEND
bgm_suikun_3_016:
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_3_016
	.byte	PATT
	 .word	bgm_suikun_3_013
	.byte	PATT
	 .word	bgm_suikun_3_013
bgm_suikun_3_017:
	.byte		N12   , Dn2 , v112
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_3_017
	.byte	PATT
	 .word	bgm_suikun_3_014
	.byte	PATT
	 .word	bgm_suikun_3_015
	.byte		N24   , An1 , v112
	.byte	W48
	.byte		N12   , An0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
bgm_suikun_3_018:
	.byte		N12   , An0 , v112
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_3_018
	.byte		N12   , An0 , v112
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
bgm_suikun_3_019:
	.byte		N12   , Gn1 , v112
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_3_019
	.byte	PATT
	 .word	bgm_suikun_3_019
	.byte		N12   , Gn1 , v112
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        An0 
	.byte	W12
bgm_suikun_3_020:
	.byte		N12   , En1 , v112
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_suikun_3_020
	.byte		N12   , En1 , v112
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		N24   , An1 
	.byte	W12
	.byte	W12
	.byte		N12   , En1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte	GOTO
	 .word	bgm_suikun_3_B1
	.byte	W48
	.byte	FINE

@******************************************************@
	.align	2

bgm_suikun:
	.byte	3	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_suikun_pri	@ Priority
	.byte	bgm_suikun_rev	@ Reverb.

	.word	bgm_suikun_grp

	.word	bgm_suikun_1
	.word	bgm_suikun_2
	.word	bgm_suikun_3

	.end
