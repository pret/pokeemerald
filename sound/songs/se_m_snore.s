	.include "MPlayDef.s"

	.equ	se_m_snore_grp, voicegroup128
	.equ	se_m_snore_pri, 4
	.equ	se_m_snore_rev, 0
	.equ	se_m_snore_mvl, 127
	.equ	se_m_snore_key, 0
	.equ	se_m_snore_tbs, 1
	.equ	se_m_snore_exg, 0
	.equ	se_m_snore_cmp, 1

	.section .rodata
	.global	se_m_snore
	.align	2

@********************** Track  1 **********************@

se_m_snore_1:
	.byte	KEYSH , se_m_snore_key+0
	.byte	TEMPO , 220*se_m_snore_tbs/2
	.byte		VOICE , 38
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 27*se_m_snore_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N10   , An1 , v127
	.byte	W01
	.byte		VOL   , 75*se_m_snore_mvl/mxv
	.byte	W01
	.byte		        120*se_m_snore_mvl/mxv
	.byte	W04
	.byte	W02
	.byte		        75*se_m_snore_mvl/mxv
	.byte	W01
	.byte		        28*se_m_snore_mvl/mxv
	.byte	W03
	.byte		VOICE , 36
	.byte		VOL   , 83*se_m_snore_mvl/mxv
	.byte		N18   , En2 , v112
	.byte	W02
	.byte		VOL   , 87*se_m_snore_mvl/mxv
	.byte	W02
	.byte		        91*se_m_snore_mvl/mxv
	.byte	W02
	.byte	W01
	.byte		        97*se_m_snore_mvl/mxv
	.byte	W02
	.byte		        102*se_m_snore_mvl/mxv
	.byte	W01
	.byte		        109*se_m_snore_mvl/mxv
	.byte	W02
	.byte		        113*se_m_snore_mvl/mxv
	.byte	W01
	.byte		        120*se_m_snore_mvl/mxv
	.byte	W05
	.byte	FINE

@********************** Track  2 **********************@

se_m_snore_2:
	.byte		VOL   , 120*se_m_snore_mvl/mxv
	.byte	KEYSH , se_m_snore_key+0
	.byte		VOICE , 27
	.byte		N01   , En2 , v052
	.byte	W02
	.byte		        Dn2
	.byte	W02
	.byte		        En2
	.byte	W02
	.byte	W01
	.byte		        Dn2
	.byte	W02
	.byte		        En2
	.byte	W03
	.byte	W01
	.byte		        En2 , v064
	.byte	W02
	.byte		        Gs2
	.byte	W03
	.byte		        Dn3
	.byte	W02
	.byte		        En2
	.byte	W02
	.byte		        Gs2
	.byte	W02
	.byte	W01
	.byte		        Dn3
	.byte	W05
	.byte	FINE

@******************************************************@
	.align	2

se_m_snore:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_snore_pri	@ Priority
	.byte	se_m_snore_rev	@ Reverb.

	.word	se_m_snore_grp

	.word	se_m_snore_1
	.word	se_m_snore_2

	.end
