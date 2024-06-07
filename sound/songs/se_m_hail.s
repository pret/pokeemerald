	.include "MPlayDef.s"

	.equ	se_m_hail_grp, voicegroup128
	.equ	se_m_hail_pri, 4
	.equ	se_m_hail_rev, 0
	.equ	se_m_hail_mvl, 127
	.equ	se_m_hail_key, 0
	.equ	se_m_hail_tbs, 1
	.equ	se_m_hail_exg, 0
	.equ	se_m_hail_cmp, 1

	.section .rodata
	.global	se_m_hail
	.align	2

@********************** Track  1 **********************@

se_m_hail_1:
	.byte	KEYSH , se_m_hail_key+0
	.byte	TEMPO , 150*se_m_hail_tbs/2
	.byte		VOICE , 3
	.byte		VOL   , 100*se_m_hail_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N01   , Fn4 , v112
	.byte	W04
	.byte		PAN   , c_v+6
	.byte		N02   , Ds5 , v040
	.byte	W02
	.byte	W02
	.byte		PAN   , c_v-5
	.byte		N01   , Gn4 , v112
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		N01   , Ds5
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v+6
	.byte		N02   , Ds5 , v020
	.byte	W03
	.byte		PAN   , c_v-5
	.byte		N01   , Gn4 , v064
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		N01   , Ds5
	.byte	W03
	.byte		PAN   , c_v+11
	.byte		N02   , Ds5 , v020
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v-13
	.byte		N01   , Gn4 , v064
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		N01   , Ds5
	.byte	W04
	.byte	FINE

@********************** Track  2 **********************@

se_m_hail_2:
	.byte	KEYSH , se_m_hail_key+0
	.byte		VOICE , 4
	.byte		VOL   , 100*se_m_hail_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N01   , Dn4 , v040
	.byte	W04
	.byte		        Bn3
	.byte	W02
	.byte	W03
	.byte		        Dn4
	.byte	W03
	.byte	W01
	.byte		        Bn3 , v032
	.byte	W05
	.byte		        Dn4
	.byte	W03
	.byte		        Bn3 , v012
	.byte	W03
	.byte	W02
	.byte		        Dn4
	.byte	W04
	.byte	FINE

@******************************************************@
	.align	2

se_m_hail:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_hail_pri	@ Priority
	.byte	se_m_hail_rev	@ Reverb.

	.word	se_m_hail_grp

	.word	se_m_hail_1
	.word	se_m_hail_2

	.end
