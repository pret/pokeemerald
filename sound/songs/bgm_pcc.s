	.include "MPlayDef.s"

	.equ	bgm_pcc_grp, voicegroup_pokemon_cry
	.equ	bgm_pcc_pri, 0
	.equ	bgm_pcc_rev, reverb_set+50
	.equ	bgm_pcc_mvl, 127
	.equ	bgm_pcc_key, 0
	.equ	bgm_pcc_tbs, 1
	.equ	bgm_pcc_exg, 0
	.equ	bgm_pcc_cmp, 1

	.section .rodata
	.global	bgm_pcc
	.align	2

@********************** Track  1 **********************@

bgm_pcc_1:
	.byte	KEYSH , bgm_pcc_key+0
	.byte	TEMPO , 120*bgm_pcc_tbs/2
	.byte		VOICE , 1
	.byte		VOL   , 80*bgm_pcc_mvl/mxv
	.byte		N12   , En3 , v076
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
bgm_pcc_1_B1:
bgm_pcc_1_000:
	.byte		N11   , En3 , v076
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N11   , Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	PEND
bgm_pcc_1_001:
	.byte		N11   , An3 , v076
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	PEND
	.byte		N11   
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N11   , An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	PATT
	 .word	bgm_pcc_1_000
	.byte	PATT
	 .word	bgm_pcc_1_001
	.byte		N11   , Gn3 , v076
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N23   , Bn3 
	.byte	W24
	.byte		N11   , An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N23   , Cn3 
	.byte	W24
	.byte		N11   , Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N12   , En3 
	.byte	W12
	.byte		N11   , Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N23   , Dn3 
	.byte	W24
	.byte		N11   , Bn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N44   , Gn3 
	.byte	W48
	.byte		N11   , Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N23   , An3 
	.byte	W24
	.byte		N11   , Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N23   , Bn3 
	.byte	W24
	.byte		N11   , An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N23   , Gn3 
	.byte	W24
	.byte		N11   , Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte	GOTO
	 .word	bgm_pcc_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_pcc_2:
	.byte	KEYSH , bgm_pcc_key+0
	.byte		VOICE , 32
	.byte		VOL   , 80*bgm_pcc_mvl/mxv
	.byte	W60
	.byte		N12   , Gn1 , v112
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
bgm_pcc_2_B1:
bgm_pcc_2_000:
	.byte		N11   , Cn2 , v112
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte	PEND
bgm_pcc_2_001:
	.byte		N11   , Dn2 , v112
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte	PEND
bgm_pcc_2_002:
	.byte		N11   , Dn2 , v112
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte	PEND
	.byte		        En2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte	PATT
	 .word	bgm_pcc_2_000
	.byte	PATT
	 .word	bgm_pcc_2_001
	.byte	PATT
	 .word	bgm_pcc_2_002
	.byte		N11   , Cn2 , v112
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
bgm_pcc_2_003:
	.byte		N11   , En2 , v112
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte	PEND
bgm_pcc_2_004:
	.byte		N11   , Fn2 , v112
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte	PEND
bgm_pcc_2_005:
	.byte		N11   , Dn2 , v112
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_pcc_2_003
	.byte	PATT
	 .word	bgm_pcc_2_003
	.byte	PATT
	 .word	bgm_pcc_2_004
	.byte	PATT
	 .word	bgm_pcc_2_005
	.byte		N11   , En2 , v112
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte	GOTO
	 .word	bgm_pcc_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_pcc_3:
	.byte	KEYSH , bgm_pcc_key+0
	.byte		VOICE , 48
	.byte		VOL   , 80*bgm_pcc_mvl/mxv
	.byte		N12   , Gn3 , v092
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W24
bgm_pcc_3_B1:
bgm_pcc_3_000:
	.byte		N11   , Cn4 , v092
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N23   , Gn4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N11   , En4 
	.byte	W12
	.byte	PEND
bgm_pcc_3_001:
	.byte		N11   , Dn4 , v092
	.byte	W12
	.byte		N32   , Bn3 
	.byte	W36
	.byte		VOICE , 1
	.byte		N11   , Gn5 , v100
	.byte	W12
	.byte		N12   , Dn5 
	.byte	W12
	.byte		N23   , Dn6 
	.byte	W24
	.byte	PEND
bgm_pcc_3_002:
	.byte		VOICE , 48
	.byte		N11   , Bn3 , v092
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N23   , En4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		N11   , Bn3 
	.byte	W12
	.byte	PEND
	.byte		        Cn4 
	.byte	W12
	.byte		N32   , En4 
	.byte	W36
	.byte		N11   , En3 
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N11   , Dn3 
	.byte	W12
	.byte		N12   , En3 
	.byte	W12
	.byte	PATT
	 .word	bgm_pcc_3_000
	.byte	PATT
	 .word	bgm_pcc_3_001
	.byte	PATT
	 .word	bgm_pcc_3_002
	.byte		N44   , Cn4 , v092
	.byte	W48
	.byte		N11   , Gn3 
	.byte	W12
	.byte		N12   , An3 
	.byte	W12
	.byte		N11   , Bn3 
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
bgm_pcc_3_003:
	.byte		N44   , En4 , v092
	.byte	W48
	.byte		        Gn4 
	.byte	W48
	.byte	PEND
	.byte		N11   , Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N44   , Dn4 
	.byte	W48
	.byte		        Bn3 
	.byte	W48
	.byte		        Dn4 
	.byte	W48
bgm_pcc_3_004:
	.byte		N11   , En4 , v092
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N44   , Cn4 
	.byte	W48
	.byte	PEND
	.byte	PATT
	 .word	bgm_pcc_3_003
	.byte		N11   , Fn4 , v092
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N44   , An4 
	.byte	W48
	.byte		N23   , Gn4 
	.byte	W24
	.byte		N11   , Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N44   , Fn4 
	.byte	W48
	.byte	PATT
	 .word	bgm_pcc_3_004
	.byte	GOTO
	 .word	bgm_pcc_3_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_pcc:
	.byte	3	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_pcc_pri	@ Priority
	.byte	bgm_pcc_rev	@ Reverb.

	.word	bgm_pcc_grp

	.word	bgm_pcc_1
	.word	bgm_pcc_2
	.word	bgm_pcc_3

	.end
