	.include "MPlayDef.s"

	.equ	se_m_absorb_grp, voicegroup128
	.equ	se_m_absorb_pri, 4
	.equ	se_m_absorb_rev, 0
	.equ	se_m_absorb_mvl, 127
	.equ	se_m_absorb_key, 0
	.equ	se_m_absorb_tbs, 1
	.equ	se_m_absorb_exg, 0
	.equ	se_m_absorb_cmp, 1

	.section .rodata
	.global	se_m_absorb
	.align	2

@********************** Track  1 **********************@

se_m_absorb_1:
	.byte	KEYSH , se_m_absorb_key+0
	.byte	TEMPO , 150*se_m_absorb_tbs/2
	.byte		VOICE , 24
	.byte		VOL   , 110*se_m_absorb_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N01   , Cn6 , v127
	.byte	W01
	.byte		        Gn6 , v112
	.byte	W01
	.byte		VOICE , 38
	.byte		VOL   , 58*se_m_absorb_mvl/mxv
	.byte		N08   , Gn4
	.byte	W01
	.byte		VOL   , 68*se_m_absorb_mvl/mxv
	.byte		PAN   , c_v+8
	.byte		BEND  , c_v-20
	.byte	W01
	.byte		VOL   , 75*se_m_absorb_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		BEND  , c_v-48
	.byte	W02
	.byte		VOL   , 83*se_m_absorb_mvl/mxv
	.byte		PAN   , c_v+8
	.byte		BEND  , c_v-18
	.byte	W01
	.byte		VOL   , 90*se_m_absorb_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		BEND  , c_v+10
	.byte	W01
	.byte		VOL   , 101*se_m_absorb_mvl/mxv
	.byte		PAN   , c_v+9
	.byte		BEND  , c_v+39
	.byte	W01
	.byte		VOL   , 110*se_m_absorb_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		BEND  , c_v+63
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_m_absorb:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_absorb_pri	@ Priority
	.byte	se_m_absorb_rev	@ Reverb.

	.word	se_m_absorb_grp

	.word	se_m_absorb_1

	.end
