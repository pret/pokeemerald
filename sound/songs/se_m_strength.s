	.include "MPlayDef.s"

	.equ	se_m_strength_grp, voicegroup_rs_sfx_2
	.equ	se_m_strength_pri, 4
	.equ	se_m_strength_rev, reverb_set+50
	.equ	se_m_strength_mvl, 127
	.equ	se_m_strength_key, 0
	.equ	se_m_strength_tbs, 1
	.equ	se_m_strength_exg, 0
	.equ	se_m_strength_cmp, 1

	.section .rodata
	.global	se_m_strength
	.align	2

@********************** Track  1 **********************@

se_m_strength_1:
	.byte	KEYSH , se_m_strength_key+0
	.byte	TEMPO , 150*se_m_strength_tbs/2
	.byte		VOICE , 26
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_m_strength_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , Gn2 , v127
	.byte	W03
	.byte		PAN   , c_v+6
	.byte		N03   , Fs2 , v120
	.byte	W04
	.byte		PAN   , c_v-6
	.byte		N03   , Fn2 , v116
	.byte	W03
	.byte		PAN   , c_v+11
	.byte		N03   , En2 , v112
	.byte	W04
	.byte		PAN   , c_v-11
	.byte		N03   , Ds2 , v108
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N03   , Dn2 , v100
	.byte	W06
	.byte	FINE

@********************** Track  2 **********************@

se_m_strength_2:
	.byte	KEYSH , se_m_strength_key+0
	.byte		VOICE , 5
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_m_strength_mvl/mxv
	.byte		N02   , Fn2 , v072
	.byte	W02
	.byte		N01
	.byte	W01
	.byte		N02   , Gn2
	.byte	W03
	.byte		N01   , Gs2 , v060
	.byte	W01
	.byte		N02   , Cn3 , v040
	.byte	W03
	.byte		        Cn3 , v032
	.byte	W04
	.byte		N01   , Cn3 , v028
	.byte	W04
	.byte		        Cn3 , v020
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_m_strength:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_strength_pri	@ Priority
	.byte	se_m_strength_rev	@ Reverb.

	.word	se_m_strength_grp

	.word	se_m_strength_1
	.word	se_m_strength_2

	.end
