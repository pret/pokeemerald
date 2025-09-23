	.include "MPlayDef.s"

	.equ	se_m_bonemerang_grp, voicegroup_rs_sfx_2
	.equ	se_m_bonemerang_pri, 4
	.equ	se_m_bonemerang_rev, reverb_set+50
	.equ	se_m_bonemerang_mvl, 127
	.equ	se_m_bonemerang_key, 0
	.equ	se_m_bonemerang_tbs, 1
	.equ	se_m_bonemerang_exg, 0
	.equ	se_m_bonemerang_cmp, 1

	.section .rodata
	.global	se_m_bonemerang
	.align	2

@********************** Track  1 **********************@

se_m_bonemerang_1:
	.byte	KEYSH , se_m_bonemerang_key+0
	.byte	TEMPO , 150*se_m_bonemerang_tbs/2
	.byte		VOICE , 24
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_m_bonemerang_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N01   , Cn5 , v127
	.byte	W01
	.byte		PAN   , c_v+10
	.byte		N01   , Cn6
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		N01   , Cn5
	.byte	W04
	.byte		N01
	.byte	W01
	.byte		PAN   , c_v-11
	.byte		N01   , Cn6
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		N01   , Cn5
	.byte	W04
	.byte	FINE

@******************************************************@
	.align	2

se_m_bonemerang:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_bonemerang_pri	@ Priority
	.byte	se_m_bonemerang_rev	@ Reverb.

	.word	se_m_bonemerang_grp

	.word	se_m_bonemerang_1

	.end
