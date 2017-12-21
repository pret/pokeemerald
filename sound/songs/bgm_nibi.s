	.include "MPlayDef.s"

	.equ	bgm_nibi_grp, voicegroup_pokemon_cry
	.equ	bgm_nibi_pri, 0
	.equ	bgm_nibi_rev, reverb_set+50
	.equ	bgm_nibi_mvl, 127
	.equ	bgm_nibi_key, 0
	.equ	bgm_nibi_tbs, 1
	.equ	bgm_nibi_exg, 0
	.equ	bgm_nibi_cmp, 1

	.section .rodata
	.global	bgm_nibi
	.align	2

@********************** Track  1 **********************@

bgm_nibi_1:
	.byte	KEYSH , bgm_nibi_key+0
	.byte	TEMPO , 128*bgm_nibi_tbs/2
	.byte		VOICE , 1
	.byte		VOL   , 80*bgm_nibi_mvl/mxv
	.byte		N06   , En3 , v112
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N24   
	.byte	W36
	.byte		N12   , Cn4 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		N06   , En3 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N06   , Fn3 
	.byte	W12
	.byte	W24
	.byte		N48   
	.byte	W72
bgm_nibi_1_B1:
bgm_nibi_1_000:
	.byte		N06   , Gn3 , v112
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
bgm_nibi_1_001:
	.byte		N24   , As3 , v112
	.byte	W36
	.byte		N12   , Gn3 
	.byte	W24
	.byte		        As3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte	PEND
bgm_nibi_1_002:
	.byte		N06   , An3 , v112
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		        Cn4 
	.byte	W12
	.byte	PEND
bgm_nibi_1_003:
	.byte	W12
	.byte		N12   , An3 , v112
	.byte	W24
	.byte		N06   , Fn3 
	.byte	W12
	.byte		N24   
	.byte	W36
	.byte		N06   , An3 
	.byte	W12
	.byte	PEND
bgm_nibi_1_004:
	.byte		N06   , Cn4 , v112
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte		N24   , Fn3 
	.byte	W36
	.byte		N06   , Bn3 , v080
	.byte	W12
	.byte		        Dn4 , v088
	.byte	W12
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N06   , Bn3 
	.byte	W12
bgm_nibi_1_005:
	.byte		N06   , Gn3 , v112
	.byte	W24
	.byte		N12   , En3 
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N06   , Fn3 
	.byte	W12
	.byte	PEND
	.byte	W24
	.byte		N48   
	.byte	W72
	.byte	PATT
	 .word	bgm_nibi_1_000
	.byte	PATT
	 .word	bgm_nibi_1_001
	.byte	PATT
	 .word	bgm_nibi_1_002
	.byte	PATT
	 .word	bgm_nibi_1_003
	.byte	PATT
	 .word	bgm_nibi_1_004
	.byte		N24   , Fn3 , v112
	.byte	W36
	.byte		N06   , Bn3 , v072
	.byte	W12
	.byte		        Dn4 , v076
	.byte	W12
	.byte		N24   , Cn4 , v080
	.byte	W24
	.byte		N06   , Bn3 , v112
	.byte	W12
	.byte	PATT
	 .word	bgm_nibi_1_005
	.byte	W24
	.byte		N48   , Fn3 , v112
	.byte	W48
	.byte		N24   , As3 
	.byte	W24
bgm_nibi_1_006:
	.byte		N12   , An3 , v112
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte	PEND
	.byte	W12
	.byte		N12   , An3 
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N12   , An4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N06   , En3 
	.byte	W12
	.byte		        Gn3 
	.byte	W24
	.byte		N12   , En3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N24   , En5 
	.byte	W24
	.byte		        Ds5 
	.byte	W24
	.byte		N36   , Fn3 
	.byte	W36
	.byte		N48   , An3 
	.byte	W48
	.byte		N12   , Dn4 
	.byte	W12
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , An3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N06   , Cn3 
	.byte	W12
	.byte		        En3 
	.byte	W24
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N06   , En3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	W12
	.byte		N12   , En3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	PATT
	 .word	bgm_nibi_1_006
	.byte	W12
	.byte		N12   , An3 , v112
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N06   , En3 
	.byte	W12
	.byte		        Gn3 
	.byte	W24
	.byte		N12   , En3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        En3 
	.byte	W12
	.byte		N36   , Fn3 
	.byte	W36
	.byte		N06   , An3 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N12   , En4 
	.byte	W12
	.byte		N36   , Fn4 
	.byte	W12
	.byte	W24
	.byte		N12   , Dn4 
	.byte	W24
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W24
	.byte		N36   , En4 
	.byte	W12
	.byte	W24
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		N06   , Fn3 
	.byte	W24
	.byte		N48   
	.byte	W48
	.byte		N24   , Gs3 
	.byte	W24
	.byte	GOTO
	 .word	bgm_nibi_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_nibi_2:
	.byte	KEYSH , bgm_nibi_key+0
	.byte		VOICE , 1
	.byte		VOL   , 80*bgm_nibi_mvl/mxv
	.byte		N24   , Cn2 , v112
	.byte	W36
	.byte		N06   , Gn2 
	.byte	W12
	.byte		N24   
	.byte	W48
	.byte		        Cn2 
	.byte	W36
	.byte		N06   , Gn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   , Bn2 
	.byte	W24
	.byte		N06   , Gn2 
	.byte	W12
bgm_nibi_2_000:
	.byte		N24   , Cn2 , v112
	.byte	W36
	.byte		N06   , Gn2 
	.byte	W12
	.byte		N24   
	.byte	W36
	.byte		N06   , Dn2 
	.byte	W12
	.byte	PEND
	.byte	W24
	.byte		N48   
	.byte	W72
bgm_nibi_2_B1:
bgm_nibi_2_001:
	.byte		N24   , Cn2 , v112
	.byte	W36
	.byte		N06   , Gn2 
	.byte	W12
	.byte		N24   
	.byte	W48
	.byte	PEND
bgm_nibi_2_002:
	.byte		N24   , Cs2 , v112
	.byte	W36
	.byte		N06   , Gn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   , As2 
	.byte	W24
	.byte		N06   , Gn2 
	.byte	W12
	.byte	PEND
bgm_nibi_2_003:
	.byte		N24   , Dn2 , v112
	.byte	W36
	.byte		N06   , An2 
	.byte	W12
	.byte		N24   
	.byte	W48
	.byte	PEND
bgm_nibi_2_004:
	.byte		N24   , Dn2 , v112
	.byte	W36
	.byte		N06   , An2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   , Cn3 
	.byte	W24
	.byte		N06   , An2 
	.byte	W12
	.byte	PEND
bgm_nibi_2_005:
	.byte		N24   , Fn2 , v112
	.byte	W36
	.byte		N06   , Cn3 
	.byte	W12
	.byte		N24   
	.byte	W48
	.byte	PEND
bgm_nibi_2_006:
	.byte		N24   , Gn2 , v112
	.byte	W36
	.byte		N06   , Dn3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N06   , Dn3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_nibi_2_000
	.byte	W24
	.byte		N48   , Dn2 , v112
	.byte	W72
	.byte	PATT
	 .word	bgm_nibi_2_001
	.byte	PATT
	 .word	bgm_nibi_2_002
	.byte	PATT
	 .word	bgm_nibi_2_003
	.byte	PATT
	 .word	bgm_nibi_2_004
	.byte	PATT
	 .word	bgm_nibi_2_005
	.byte	PATT
	 .word	bgm_nibi_2_006
	.byte	PATT
	 .word	bgm_nibi_2_000
	.byte	W24
	.byte		N48   , Dn2 , v112
	.byte	W48
	.byte		N24   , En2 
	.byte	W24
bgm_nibi_2_007:
	.byte		N24   , Fn2 , v112
	.byte	W36
	.byte		N06   , Cn3 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   , Ds2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte	PEND
	.byte		N24   , Fn2 
	.byte	W36
	.byte		N06   , Cn3 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		N24   , Cn3 
	.byte	W24
	.byte		N12   , An2 
	.byte	W12
bgm_nibi_2_008:
	.byte		N24   , En2 , v112
	.byte	W36
	.byte		N06   , Bn2 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte	PEND
	.byte	W12
	.byte		        En2 
	.byte	W24
	.byte		N06   , Bn2 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		        As2 
	.byte	W24
bgm_nibi_2_009:
	.byte		N24   , Dn2 , v112
	.byte	W36
	.byte		N06   , An2 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   , Cn2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte	PEND
	.byte		N24   , Dn2 
	.byte	W36
	.byte		N06   , An2 
	.byte	W12
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N24   , Fn2 
	.byte	W24
	.byte		        Cn2 
	.byte	W36
	.byte		N06   , Gn2 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   , As1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		N06   , Gn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte	PATT
	 .word	bgm_nibi_2_007
	.byte		N24   , Fn2 , v112
	.byte	W36
	.byte		N06   , An2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		N24   , An2 
	.byte	W24
	.byte		N12   , Fn2 
	.byte	W12
	.byte	PATT
	 .word	bgm_nibi_2_008
	.byte	W12
	.byte		N12   , En2 , v112
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Cs2 
	.byte	W12
	.byte	PATT
	 .word	bgm_nibi_2_009
	.byte		N24   , Dn2 , v112
	.byte	W36
	.byte		N06   , Gs2 
	.byte	W12
	.byte		N24   
	.byte	W36
	.byte		N06   , Fn2 
	.byte	W12
	.byte		N24   , Cn2 
	.byte	W36
	.byte		N06   , Gn2 
	.byte	W12
	.byte		N24   
	.byte	W36
	.byte		N06   , Cn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W24
	.byte		N48   
	.byte	W48
	.byte		N24   , Gn1 
	.byte	W24
	.byte	GOTO
	 .word	bgm_nibi_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_nibi_3:
	.byte	KEYSH , bgm_nibi_key+0
	.byte		VOICE , 1
	.byte		VOL   , 80*bgm_nibi_mvl/mxv
	.byte		N06   , Gn3 , v112
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N24   
	.byte	W36
	.byte		N12   , En4 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		N06   , Gn3 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N06   , Cn4 
	.byte	W12
bgm_nibi_3_000:
	.byte	W24
	.byte		N48   , Cn4 , v112
	.byte	W48
	.byte		N12   , En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte	PEND
bgm_nibi_3_B1:
bgm_nibi_3_001:
	.byte		N12   , Gn4 , v112
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        En4 
	.byte	W48
	.byte	PEND
bgm_nibi_3_002:
	.byte	W12
	.byte		N12   , En4 , v112
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte	PEND
bgm_nibi_3_003:
	.byte		N12   , Fn4 , v112
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        An3 
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		        Fn4 
	.byte	W12
	.byte	PEND
bgm_nibi_3_004:
	.byte	W12
	.byte		N12   , Cn4 , v112
	.byte	W24
	.byte		N06   , An3 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte	PEND
bgm_nibi_3_005:
	.byte		N12   , Fn4 , v112
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Dn4 
	.byte	W48
	.byte	PEND
bgm_nibi_3_006:
	.byte	W12
	.byte		N12   , Dn4 , v112
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte	PEND
bgm_nibi_3_007:
	.byte		N12   , En4 , v112
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N06   , Cn4 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_nibi_3_000
	.byte	PATT
	 .word	bgm_nibi_3_001
	.byte	PATT
	 .word	bgm_nibi_3_002
	.byte	PATT
	 .word	bgm_nibi_3_003
	.byte	PATT
	 .word	bgm_nibi_3_004
	.byte	PATT
	 .word	bgm_nibi_3_005
	.byte	PATT
	 .word	bgm_nibi_3_006
	.byte	PATT
	 .word	bgm_nibi_3_007
	.byte	W24
	.byte		N48   , Cn4 , v112
	.byte	W48
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N72   , An4 
	.byte	W72
	.byte		N24   , Fn4 
	.byte	W24
	.byte		N48   , Cn5 
	.byte	W48
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N72   , Gn4 
	.byte	W72
	.byte		N24   , En4 
	.byte	W24
	.byte		N48   , Gn4 
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		N60   , Dn4 
	.byte	W60
	.byte		N12   
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , En4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N72   , En4 
	.byte	W72
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Gn4 
	.byte	W48
	.byte		N48   , As4 
	.byte	W48
	.byte		N72   , An4 
	.byte	W72
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Dn5 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		N60   , Gn4 
	.byte	W60
	.byte		N12   
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte	W12
	.byte		        An4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		N72   , Fn4 
	.byte	W12
	.byte	W60
	.byte		N12   
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N36   , Gs4 
	.byte	W12
	.byte	W24
	.byte		N12   , Gn4 
	.byte	W24
	.byte		        Fn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W24
	.byte		N84   , Gn4 
	.byte	W12
	.byte	W96
	.byte		N06   , Cn4 
	.byte	W24
	.byte		N48   
	.byte	W48
	.byte		N24   , Dn4 
	.byte	W24
	.byte	GOTO
	 .word	bgm_nibi_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_nibi_4:
	.byte	KEYSH , bgm_nibi_key+0
	.byte		VOICE , 0
	.byte		VOL   , 80*bgm_nibi_mvl/mxv
	.byte		N12   , Fs2 , v056
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        En1 , v084
	.byte	W12
	.byte		N24   , Fs2 , v056
	.byte	W24
	.byte		N12   , En1 , v084
	.byte	W12
	.byte		        Fs2 , v056
	.byte	W12
	.byte		        As1 , v084
	.byte	W12
bgm_nibi_4_000:
	.byte		N12   , Fs2 , v056
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , En1 , v084
	.byte	W24
	.byte		N12   , Fs2 , v056
	.byte	W12
	.byte		        En1 , v084
	.byte	W12
	.byte		        Fs2 , v056
	.byte	W12
	.byte		        As1 , v084
	.byte	W12
	.byte	PEND
bgm_nibi_4_001:
	.byte		N12   , Fs2 , v056
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        En1 , v084
	.byte	W12
	.byte		N24   , Fs2 , v056
	.byte	W24
	.byte		N12   , En1 , v084
	.byte	W12
	.byte		        Fs2 , v056
	.byte	W12
	.byte		        As1 , v084
	.byte	W12
	.byte	PEND
bgm_nibi_4_002:
	.byte		N12   , Fs2 , v056
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , As1 , v084
	.byte	W24
	.byte		N12   , En1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
bgm_nibi_4_B1:
	.byte	PATT
	 .word	bgm_nibi_4_001
	.byte	PATT
	 .word	bgm_nibi_4_000
	.byte	PATT
	 .word	bgm_nibi_4_001
	.byte	PATT
	 .word	bgm_nibi_4_000
	.byte	PATT
	 .word	bgm_nibi_4_001
	.byte	PATT
	 .word	bgm_nibi_4_000
	.byte	PATT
	 .word	bgm_nibi_4_001
	.byte	PATT
	 .word	bgm_nibi_4_002
	.byte	PATT
	 .word	bgm_nibi_4_001
	.byte	PATT
	 .word	bgm_nibi_4_000
	.byte		N12   , Fs2 , v056
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        En1 , v084
	.byte	W12
	.byte		        Fs2 , v056
	.byte	W24
	.byte		        En1 , v084
	.byte	W12
	.byte		        Fs2 , v056
	.byte	W12
	.byte		        As1 , v084
	.byte	W12
	.byte	PATT
	 .word	bgm_nibi_4_000
	.byte	PATT
	 .word	bgm_nibi_4_001
	.byte	PATT
	 .word	bgm_nibi_4_000
	.byte		N12   , Fs2 , v056
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        En1 , v084
	.byte	W12
	.byte		N18   , Fs2 , v056
	.byte	W24
	.byte		N12   , En1 , v084
	.byte	W12
	.byte		        Fs2 , v056
	.byte	W12
	.byte		        As1 , v084
	.byte	W12
	.byte	PATT
	 .word	bgm_nibi_4_002
bgm_nibi_4_003:
	.byte		N12   , Cn1 , v084
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N24   , En1 
	.byte	W24
	.byte	PEND
bgm_nibi_4_004:
	.byte		N12   , Cn1 , v084
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_nibi_4_003
bgm_nibi_4_005:
	.byte		N12   , Cn1 , v084
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        En1 , v072
	.byte	W12
	.byte		        En1 , v084
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_nibi_4_003
	.byte	PATT
	 .word	bgm_nibi_4_004
	.byte	PATT
	 .word	bgm_nibi_4_003
	.byte	PATT
	 .word	bgm_nibi_4_004
	.byte	PATT
	 .word	bgm_nibi_4_003
	.byte	PATT
	 .word	bgm_nibi_4_004
	.byte		N12   , Cn1 , v084
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        En1 
	.byte	W24
	.byte	PATT
	 .word	bgm_nibi_4_005
	.byte	PATT
	 .word	bgm_nibi_4_003
	.byte	PATT
	 .word	bgm_nibi_4_004
	.byte	PATT
	 .word	bgm_nibi_4_003
	.byte	PATT
	 .word	bgm_nibi_4_004
	.byte	GOTO
	 .word	bgm_nibi_4_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_nibi:
	.byte	4	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_nibi_pri	@ Priority
	.byte	bgm_nibi_rev	@ Reverb.

	.word	bgm_nibi_grp

	.word	bgm_nibi_1
	.word	bgm_nibi_2
	.word	bgm_nibi_3
	.word	bgm_nibi_4

	.end
